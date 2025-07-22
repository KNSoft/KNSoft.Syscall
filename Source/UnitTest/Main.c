#include <KNSoft/NDK/NDK.h>

#include "UnitTest.h"

#pragma comment (lib, "KNSoft.Syscall.lib")

extern FN_TEST_PROC MemPageAlloc;
extern FN_TEST_PROC NoImport;
extern FN_TEST_PROC NotFound;

static PFN_TEST_PROC TestList[] = {
    MemPageAlloc,
    NoImport,
    NotFound
};

extern FN_SYSCALL_FAIL_CALLBACK NotFound_FailCallback;

static PFN_SYSCALL_FAIL_CALLBACK FailCallbackList[] = { NotFound_FailCallback };

static
_Function_class_(FN_SYSCALL_FAIL_CALLBACK)
BOOL
__cdecl
FailCallbackCenter(
    _In_ PVOID Thunk,
    _In_opt_ PCANSI_STRING Name,
    _In_ NTSTATUS Status)
{
    for (ULONG i = 0; i < ARRAYSIZE(FailCallbackList); i++)
    {
        if (!FailCallbackList[i](Thunk, Name, Status))
        {
            return FALSE;
        }
    }
    return TRUE;
}

int
_cdecl
mainCRTStartup(void)
{
    HRESULT hr = Syscall_Init(FailCallbackCenter);
    if (FAILED(hr))
    {
        return hr;
    }

    for (ULONG i = 0; i < ARRAYSIZE(TestList); i++)
    {
        if (!TestList[i]())
        {
            return 1;
        }
    }

    return 0;
}
