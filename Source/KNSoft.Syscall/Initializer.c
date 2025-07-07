#include "Syscall.inl"

EXTERN_C PVOID Syscall_Proc_Not_Found;
EXTERN_C PVOID Syscall_Proc_Not_Supported;

#pragma section(".ScThunk$AAA", long, read, write)
#pragma section(".ScThunk$ZZZ", long, read, write)
// #pragma comment(linker, "/merge:.ScThunk=.data")

static __declspec(allocate(".ScThunk$AAA")) PSYSCALL_THUNK_DATA Syscall_Thunk_First[] = { NULL };
static __declspec(allocate(".ScThunk$ZZZ")) PSYSCALL_THUNK_DATA Syscall_Thunk_Last[] = { NULL };

static const UNICODE_STRING g_usWin32u = RTL_CONSTANT_STRING(L"win32u.dll");
static SYSCALL_DLL Ntdll = { 0 }, Win32u = { 0 };
static NTSTATUS Win32uStatus = STATUS_SUCCESS;

static
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
NTSTATUS
Syscall_InitThunk(
    _Inout_ PSYSCALL_THUNK_DATA* Thunk)
{
    PSYSCALL_DLL SyscallDll;
    PCSTR Symbol;
    CHAR DecodedName[128 + 1];
    ULONG iCch, SSN;
    BYTE Ch, ByteRemain;
    PSYSCALL_THUNK_DATA ThunkData = *Thunk;

    /* Initialize Syscall Dlls lazily */
    if (!ThunkData->Header.NtUser)
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
            if (!NT_SUCCESS(Win32uStatus))
            {
                goto _Not_Found;
            }
            /* FIXME: Load from system directory only */
            /* TODO: Use NtOpenSection instead */
            Win32uStatus = LdrLoadDll(NULL, NULL, (PUNICODE_STRING)&g_usWin32u, &Win32u.DllBase);
            if (!NT_SUCCESS(Win32uStatus))
            {
                goto _Not_Found;
            }
            Syscall_InitDll(TRUE, &Win32u);
        }
        SyscallDll = &Win32u;
    }

    /* Decode thunk data */
    iCch = 0;
    ByteRemain = 0;
    for (UINT i = 0; i <= ThunkData->Header.BlobSize; i++)
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
        DecodedName[iCch++] = Ch;
        if (i % 3 == 2 && ByteRemain != 0)
        {
            Ch = ByteRemain;
            ByteRemain = 0;
            goto _Write_Char;
        }
    }
    DecodedName[iCch] = ANSI_NULL;

    /* Lookup export table */
    for (DWORD i = SyscallDll->SearchBegin; i > 0; i--)
    {
        Symbol = Add2Ptr(SyscallDll->DllBase, SyscallDll->NameRVAs[i - 1]);
        iCch = Syscall_GetName(ThunkData->Header.NtUser, Symbol);
        if (iCch == 0)
        {
            break;
        } else if (strcmp(Symbol + iCch, DecodedName) != 0)
        {
            continue;
        }

        /* Get SSN */
        if (!Syscall_GetSSNFromFunction(Add2Ptr(SyscallDll->DllBase,
                                                SyscallDll->FuncRVAs[SyscallDll->NameOrdinals[i - 1]]),
                                        &SSN))
        {
            *Thunk = (PSYSCALL_THUNK_DATA)&Syscall_Proc_Not_Supported;
            Syscall_Log(DPFLTR_ERROR_LEVEL, "[KNSoft.Syscall] Error: Initialize %hs failed\n", Symbol);
            return STATUS_NOT_SUPPORTED;
        }

        *Thunk = (PSYSCALL_THUNK_DATA)ThunkData->Header.Proc;
        ThunkData->SSN = SSN;
        return STATUS_SUCCESS;
    }

_Not_Found:
    *Thunk = (PSYSCALL_THUNK_DATA)&Syscall_Proc_Not_Found;
    Syscall_Log(DPFLTR_ERROR_LEVEL, "[KNSoft.Syscall] Error: Symbol %hs not found\n", DecodedName);
    return STATUS_PROCEDURE_NOT_FOUND;
}

static HRESULT g_hrInitState = E_FAIL;
static BOOL g_bInitialized = FALSE;

HRESULT
NTAPI
Syscall_Init(VOID)
{
    if (g_bInitialized)
    {
        return g_hrInitState;
    }

    if (Syscall_InitArch())
    {
        g_hrInitState = S_OK;
        for (PSYSCALL_THUNK_DATA* Thunk = Syscall_Thunk_First + 1; Thunk != Syscall_Thunk_Last; Thunk++)
        {
            if (*Thunk != NULL)
            {
                if (!NT_SUCCESS(Syscall_InitThunk(Thunk)))
                {
                    g_hrInitState = S_FALSE;
                }
            }
        }
    } else
    {
        g_hrInitState = E_NOTIMPL;
    }

    g_bInitialized = TRUE;
    return g_hrInitState;
}
