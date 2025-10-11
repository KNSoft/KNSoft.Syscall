#pragma once

#include "Syscall.Thunks.h"

EXTERN_C_START

EXTERN_C PVOID Syscall_Win32uBase;
EXTERN_C NTSTATUS Syscall_Win32uStatus;

static
FORCEINLINE
NTSTATUS
Syscall_LoadWin32u(VOID)
{
    UNICODE_STRING Win32uName = RTL_CONSTANT_STRING(L"win32u.dll");

    Syscall_Win32uStatus = LdrLoadDll((PCWSTR)(LDR_PATH_IS_FLAGS | LDR_PATH_SEARCH_SYSTEM32),
                                      NULL,
                                      &Win32uName,
                                      &Syscall_Win32uBase);
    return Syscall_Win32uStatus;
}

HRESULT
NTAPI
Syscall_Init(VOID);

/* Return SSN or error status (>0xC0000000) */
static
FORCEINLINE
ULONG
Syscall_GetData(
    _In_ PVOID ScFunction)
{
    PULONG pData;

#if defined(_M_X64)
    pData = Add2Ptr(ScFunction, *(PINT)Add2Ptr(ScFunction, 2) + 6);
#elif defined(_M_IX86)
    pData = *(PULONG*)Add2Ptr(ScFunction, 1);
#else
#error
#endif

    return *pData;
}

EXTERN_C_END
