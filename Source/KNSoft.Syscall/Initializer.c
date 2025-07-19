#include "Syscall.inl"

#if defined(_M_X64)
#define SYSCALL_PROC_STUB(Proc, ArgCount) ((PVOID)Proc)
#elif defined(_M_IX86)
#define SYSCALL_PROC_STUB(Proc, ArgCount) Add2Ptr(Proc, ArgCount * 8);
#endif

#define SYSCALL_WIN32U_STRING L"win32u.dll"

EXTERN_C PVOID Syscall_Proc_Not_Found;
EXTERN_C PVOID Syscall_Proc_Not_Supported;

#pragma section(".ScThunk$AAA", long, read, write)
#pragma section(".ScThunk$ZZZ", long, read, write)

static __declspec(allocate(".ScThunk$AAA")) PSYSCALL_THUNK_DATA Syscall_Thunk_First[] = { NULL };
static __declspec(allocate(".ScThunk$ZZZ")) PSYSCALL_THUNK_DATA Syscall_Thunk_Last[] = { NULL };

static const UNICODE_STRING g_usWin32u = RTL_CONSTANT_STRING(SYSCALL_WIN32U_STRING);
static SYSCALL_DLL Ntdll = { 0 }, Win32u = { 0 };
static NTSTATUS Win32uStatus = STATUS_SUCCESS;

static
FORCEINLINE
PVOID
Syscall_GetWin32uBase(VOID)
{
    PLDR_DATA_TABLE_ENTRY pHead, pNode;
    PWCHAR pChar;

    /* Skip the first entry (ntdll.dll) */
    pHead = CONTAINING_RECORD(NtCurrentPeb()->Ldr->InLoadOrderModuleList.Flink, LDR_DATA_TABLE_ENTRY, InLoadOrderLinks);
    pNode = pHead;
    do
    {
        pNode = CONTAINING_RECORD(pNode->InLoadOrderLinks.Flink, LDR_DATA_TABLE_ENTRY, InLoadOrderLinks);
        if (pNode->BaseDllName.Length != g_usWin32u.Length)
        {
            continue;
        }
        pChar = pNode->BaseDllName.Buffer;
        if ((pChar[0] != L'w' && pChar[0] != L'W') ||
            (pChar[1] != L'i' && pChar[1] != L'I') ||
            (pChar[2] != L'n' && pChar[2] != L'N') ||
            pChar[3] != L'3' ||
            pChar[4] != L'2' ||
            (pChar[5] != L'u' && pChar[5] != L'U') ||
            pChar[6] != L'.' ||
            (pChar[7] != L'd' && pChar[7] != L'D') ||
            (pChar[8] != L'l' && pChar[8] != L'L') ||
            (pChar[9] != L'l' && pChar[9] != L'L'))
        {
            continue;
        }
        return pNode->DllBase;
    } while (pNode != pHead);

    return NULL;
}

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
    _Inout_ PSYSCALL_THUNK_DATA* Thunk)
{
    PSYSCALL_DLL SyscallDll;
    PCSTR Symbol;
    CHAR DecodedName[128 + 1];
    ULONG Cch, uTemp;
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
            /* TODO: Use NtCreateSection instead? */
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
    Cch = 0;
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
        DecodedName[Cch++] = Ch;
        if (i % 3 == 2 && ByteRemain != 0)
        {
            Ch = ByteRemain;
            ByteRemain = 0;
            goto _Write_Char;
        }
    }

    /* Lookup export table */
    for (DWORD i = SyscallDll->SearchBegin; i > 0; i--)
    {
        Symbol = Add2Ptr(SyscallDll->DllBase, SyscallDll->NameRVAs[i - 1]);
        uTemp = Syscall_GetName(ThunkData->Header.NtUser, Symbol);
        if (uTemp == 0)
        {
            break;
        } else if (
            /* Name has 5 characters at least */
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
            *Thunk = (PSYSCALL_THUNK_DATA)SYSCALL_PROC_STUB(&Syscall_Proc_Not_Supported, ThunkData->Header.ArgCount);
            Syscall_Log(DPFLTR_ERROR_LEVEL, "[KNSoft.Syscall] Error: Initialize %hs failed\n", Symbol);
            return STATUS_NOT_SUPPORTED;
        }

        *Thunk = (PSYSCALL_THUNK_DATA)ThunkData->Header.Proc;
        ThunkData->SSN = uTemp;
        return STATUS_SUCCESS;
    }

_Not_Found:
    *Thunk = (PSYSCALL_THUNK_DATA)SYSCALL_PROC_STUB(&Syscall_Proc_Not_Found, ThunkData->Header.ArgCount);
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
            if (*Thunk != NULL && !NT_SUCCESS(Syscall_InitThunk(Thunk)))
            {
                /* Not all thunks initialized successfully */
                g_hrInitState = S_FALSE;
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
