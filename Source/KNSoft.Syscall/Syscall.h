#pragma once

#include "Syscall.Thunks.h"

EXTERN_C_START

typedef
_Function_class_(FN_Syscall_Log)
VOID
__cdecl
FN_Syscall_Log(
    _In_ ULONG Level, // DPFLTR_*
    _In_z_ _Printf_format_string_ PCSTR Format,
    ...);
typedef FN_Syscall_Log* PFN_Syscall_Log;

EXTERN_C PFN_Syscall_Log Syscall_Log;

HRESULT
NTAPI
Syscall_Init(VOID);

EXTERN_C_END
