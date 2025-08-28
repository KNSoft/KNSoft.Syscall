#include "Syscall.inl"

#pragma section(".ScThunk$AAA", long, read, write)
#pragma section(".ScThunk$ZZZ", long, read, write)

static __declspec(allocate(".ScThunk$AAA")) SYSCALL_THUNK Syscall_Thunk_First[] = { NULL };
static __declspec(allocate(".ScThunk$ZZZ")) SYSCALL_THUNK Syscall_Thunk_Last[] = { NULL };

PVOID Syscall_Win32uBase = NULL;
NTSTATUS Syscall_Win32uStatus = STATUS_UNSUCCESSFUL;
static SYSCALL_DLL Ntdll = { 0 }, Win32u = { 0 };

static
FORCEINLINE
CHAR
Syscall_DecodeThunkChar(
    _In_ CHAR Ch)
{
    if (Ch >= 1 && Ch <= 26)
    {
        return Ch - 1 + 'a';
    } else if (Ch >= 27 && Ch <= 52)
    {
        return Ch - 27 + 'A';
    } else if (Ch >= 53 && Ch <= 62)
    {
        return Ch - 53 + '0';
    } else
    {
        return ANSI_NULL;
    }
}

static
FORCEINLINE
LOGICAL
Syscall_CompareThunkName(
    _In_ PCSTR ThunkName,
    _In_reads_(DecodedNameLength) PCHAR DecodedName,
    _In_ ULONG DecodedNameLength)
{
    for (ULONG i = 0; i < DecodedNameLength; i++)
    {
        if (ThunkName[i] != DecodedName[i] || ThunkName[i] == ANSI_NULL)
        {
            return FALSE;
        }
    }

    return ThunkName[DecodedNameLength] == ANSI_NULL;
}

static
FORCEINLINE
NTSTATUS
Syscall_InitThunk(
    _Inout_ PSYSCALL_THUNK Thunk)
{
    NTSTATUS Status;
    PSYSCALL_DLL SyscallDll;
    PCSTR Symbol;
    CHAR DecodedName[128 + 1];
    ULONG Cch = 0, uTemp;
    BYTE Ch, ByteRemain;
    PSYSCALL_THUNK_DATA ThunkData = Thunk->Data;

    /* Initialize Syscall Dlls lazily */
    if (!ThunkData->NtUser)
    {
        if (Ntdll.DllBase == NULL)
        {
            Ntdll.DllBase = NtGetNtdllBase();
            Syscall_InitDll(FALSE, &Ntdll);
        }
        SyscallDll = &Ntdll;
    } else
    {
        if (Win32u.DllBase == NULL)
        {
            if (!NT_SUCCESS(Syscall_Win32uStatus))
            {
                Status = Syscall_Win32uStatus;
                goto _Fail;
            }
            Win32u.DllBase = Syscall_Win32uBase;
        }
        SyscallDll = &Win32u;
    }

    /* Decode thunk data */
    ByteRemain = 0;
    for (ULONG i = 0; i <= ThunkData->BlobSize; i++)
    {
        if (i % 3 == 0)
        {
            Ch = ThunkData->Blob[i] >> 2;
            ByteRemain = (ThunkData->Blob[i] & 0b11) << 4;
        } else if (i % 3 == 1)
        {
            Ch = ByteRemain | ((ThunkData->Blob[i] & 0b11110000) >> 4);
            ByteRemain = (ThunkData->Blob[i] & 0b1111) << 2;
        } else if (i % 3 == 2)
        {
            Ch = ByteRemain | ((ThunkData->Blob[i] & 0b11000000) >> 6);
            ByteRemain = ThunkData->Blob[i] & 0b111111;
        }
_Write_Char:
        Ch = Syscall_DecodeThunkChar(Ch);
        if (Ch == ANSI_NULL)
        {
            break;
        }
        DecodedName[Cch++] = Ch;
        if (i % 3 == 2 && ByteRemain != 0)
        {
            Ch = ByteRemain;
            ByteRemain = 0;
            goto _Write_Char;
        }
    }

    /* Lookup export table */
    for (ULONG i = SyscallDll->SearchBegin; i > 0; i--)
    {
        Symbol = Add2Ptr(SyscallDll->DllBase, SyscallDll->NameRVAs[i - 1]);
        uTemp = Syscall_GetName(ThunkData->NtUser, Symbol);
        if (uTemp == 0)
        {
            break;
        } else if (
            /* Name has 5 characters at least, encoded data at least 4 bytes */
            *(PULONG)(Symbol + uTemp) != *(PULONG)DecodedName ||
            !Syscall_CompareThunkName(Symbol + uTemp + sizeof(ULONG), DecodedName + sizeof(ULONG), Cch - sizeof(ULONG)))
        {
            continue;
        }

        /* Get SSN */
        if (!Syscall_GetSSNFromFunction(Add2Ptr(SyscallDll->DllBase,
                                                SyscallDll->FuncRVAs[SyscallDll->NameOrdinals[i - 1]]),
                                        &uTemp))
        {
            Status = STATUS_NOT_SUPPORTED;
            goto _Fail;
        }

        if (NT_ERROR(uTemp))
        {
            Status = STATUS_ASSERTION_FAILURE;
            goto _Fail;
        }
        Thunk->SSN = uTemp;
        return STATUS_SUCCESS;
    }
    Status = STATUS_PROCEDURE_NOT_FOUND;

_Fail:
    Thunk->SSN = Status;
    return Status;
}

static HRESULT g_hrInitState = E_FAIL;
static BOOL g_bInitialized = FALSE;

HRESULT
NTAPI
Syscall_Init(VOID)
{
    NTSTATUS Status;

    if (g_bInitialized)
    {
        return g_hrInitState;
    }

    if (Syscall_InitArch())
    {
        g_hrInitState = S_OK;
        for (PSYSCALL_THUNK Thunk = Syscall_Thunk_First + 1; Thunk != Syscall_Thunk_Last; Thunk++)
        {
            if (Thunk->Data != NULL)
            {
                Status = Syscall_InitThunk(Thunk);
                if (!NT_SUCCESS(Status))
                {
                    if (Status == STATUS_REQUEST_ABORTED)
                    {
                        g_hrInitState = E_ABORT;
                        break;
                    }
                    g_hrInitState = S_FALSE;
                }
            }
        }
    } else
    {
        /* Unimplemented, welcome to send PR or report issue */
        g_hrInitState = E_NOTIMPL;
    }

    g_bInitialized = TRUE;
    return g_hrInitState;
}
