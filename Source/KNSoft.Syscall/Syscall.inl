#pragma once

#include "Syscall.h"

EXTERN_C_START

typedef DECLSPEC_ALIGN(4) struct _SYSCALL_THUNK_DATA_HEADER
{
    struct
    {
        USHORT NtUser : 1;      // 0: ntdll, 1: win32u
        USHORT BlobSize : 6;    // Size of Blob in bytes - 1, 0-63
        USHORT ArgCount : 5;    // Number of arguments, 0-31
        USHORT NotUsed : 4;     // Reserved
    };
    PVOID Proc;
} SYSCALL_THUNK_DATA_HEADER, *PSYSCALL_THUNK_DATA_HEADER;

typedef union _SYSCALL_THUNK_DATA
{
    struct
    {
        SYSCALL_THUNK_DATA_HEADER Header;
        _Field_size_bytes_(BlobSize + 1) BYTE Blob[];
    };
    ULONG SSN;
} SYSCALL_THUNK_DATA, *PSYSCALL_THUNK_DATA;

LOGICAL
Syscall_InitArch(VOID);

_Success_(return != FALSE)
BOOL
Syscall_GetSSNFromFunction(
    _In_ PVOID Function,
    _Out_ PULONG SSN);

typedef DECLSPEC_ALIGN(4) struct _SYSCALL_DLL
{
    _In_ PVOID DllBase;
    _Out_ PIMAGE_EXPORT_DIRECTORY ExportTable;
    _Out_ PDWORD FuncRVAs;
    _Out_ PWORD NameOrdinals;
    _Out_ PDWORD NameRVAs;
    _Out_ DWORD SearchBegin;
} SYSCALL_DLL, *PSYSCALL_DLL;

ULONG
FORCEINLINE
Syscall_GetName(
    _In_ LOGICAL IsNtUser,
    _In_ PCSTR Name)
{
    if (!IsNtUser)
    {
        if (*(PWORD)Name == 'wZ')
        {
            return 2;
        }
    } else
    {
        if (*(PWORD)Name == 'tN' && *(PDWORD)(Name + 2) == 'resU')
        {
            return 6;
        }
    }
    return 0;
}

VOID
FORCEINLINE
Syscall_InitDll(
    _In_ LOGICAL IsNtUser,
    _Inout_ PSYSCALL_DLL SyscallDll)
{
    DWORD i;
    PVOID DllBase = SyscallDll->DllBase;
    PIMAGE_NT_HEADERS NtHeader = Add2Ptr(DllBase, ((PIMAGE_DOS_HEADER)DllBase)->e_lfanew);

    SyscallDll->ExportTable = Add2Ptr(DllBase, NtHeader->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress);
    SyscallDll->NameOrdinals = Add2Ptr(DllBase, SyscallDll->ExportTable->AddressOfNameOrdinals);
    SyscallDll->FuncRVAs = Add2Ptr(DllBase, SyscallDll->ExportTable->AddressOfFunctions);
    SyscallDll->NameRVAs = Add2Ptr(DllBase, SyscallDll->ExportTable->AddressOfNames);

    for (i = SyscallDll->ExportTable->NumberOfNames; i > 0; i--)
    {
        if (Syscall_GetName(IsNtUser, Add2Ptr(SyscallDll->DllBase, SyscallDll->NameRVAs[i - 1])) != 0)
        {
            SyscallDll->SearchBegin = i;
            return;
        }
    }

    SyscallDll->SearchBegin = SyscallDll->ExportTable->NumberOfNames;
    return;
}

EXTERN_C_END
