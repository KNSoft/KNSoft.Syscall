#pragma once

#include "Syscall.Thunks.h"

EXTERN_C_START

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
#endif

    return *pData;
}

EXTERN_C_END
