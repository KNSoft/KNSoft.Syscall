#pragma once

#include "Syscall.Thunks.h"

EXTERN_C_START

typedef
_Function_class_(FN_SYSCALL_FAIL_CALLBACK)
BOOL
__cdecl
FN_SYSCALL_FAIL_CALLBACK(
    _In_ PVOID Thunk,
    _In_opt_ PCANSI_STRING Name,
    _In_ NTSTATUS Status);
typedef FN_SYSCALL_FAIL_CALLBACK* PFN_SYSCALL_FAIL_CALLBACK;

HRESULT
NTAPI
Syscall_Init(
    _In_opt_ PFN_SYSCALL_FAIL_CALLBACK Callback);

EXTERN_C PVOID* Syscall_FastSystemCall;

EXTERN_C_END
