#include "UnitTest.h"

static LOGICAL g_TestPassed = FALSE;

_Function_class_(FN_SYSCALL_FAIL_CALLBACK)
BOOL
__cdecl
NotFound_FailCallback(
    _In_ PVOID Thunk,
    _In_opt_ PCANSI_STRING Name,
    _In_ NTSTATUS Status)
{
    PDWORD p;

    if (Name == NULL)
    {
        g_TestPassed = FALSE;
    } else
    {
        p = (PDWORD)Name->Buffer;
        g_TestPassed = (Thunk == ScGetPlugPlayEvent &&
                        Name->Length == 16 &&
                        p[0] == ('PteG') && p[1] == ('Pgul') && p[2] == ('Eyal') && p[3] == ('tnev') &&
                        Status == STATUS_PROCEDURE_NOT_FOUND);
    }

    return TRUE;
}

/*
 * Test case: Syscall not found
 * NtGetPlugPlayEvent was removed since NT 6.2, should returns STATUS_PROCEDURE_NOT_FOUND
 */
_Function_class_(FN_TEST_PROC)
LOGICAL
NotFound(VOID)
{
    if (SharedUserData->NtMajorVersion > 6 ||
        SharedUserData->NtMajorVersion == 6 && SharedUserData->NtMinorVersion >= 2)
    {
        return g_TestPassed;
    }

    return TRUE;
}
