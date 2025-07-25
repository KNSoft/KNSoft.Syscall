#pragma once

#include "Syscall.h"

EXTERN_C_START

#pragma pack(push, 1)

typedef struct _SYSCALL_THUNK_DATA
{
    struct
    {
        BYTE NtUser : 1;    // 0: ntdll, 1: win32u
        BYTE BlobSize : 6;  // Size of Blob in bytes - 1, 0-63
        BYTE NotUsed : 1;   // Reserved
    };
    _Field_size_bytes_(BlobSize + 1) BYTE Blob[];
} SYSCALL_THUNK_DATA, *PSYSCALL_THUNK_DATA;
_STATIC_ASSERT(UFIELD_OFFSET(SYSCALL_THUNK_DATA, Blob) == 1);

typedef union _SYSCALL_THUNK
{
    PSYSCALL_THUNK_DATA Data;
    ULONG SSN;
} SYSCALL_THUNK, *PSYSCALL_THUNK;

#pragma pack(pop)

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
    _In_ LOGICAL NtUser,
    _In_ PCSTR Name)
{
    if (!NtUser)
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
    _In_ LOGICAL NtUser,
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
        if (Syscall_GetName(NtUser, Add2Ptr(SyscallDll->DllBase, SyscallDll->NameRVAs[i - 1])) != 0)
        {
            SyscallDll->SearchBegin = i;
            return;
        }
    }
    SyscallDll->SearchBegin = SyscallDll->ExportTable->NumberOfNames;
}

EXTERN_C_END
