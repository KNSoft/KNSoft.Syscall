#include "UnitTest.h"

static LOGICAL g_TestPassed = FALSE;

_Function_class_(FN_SYSCALL_FAIL_CALLBACK)
BOOL
__cdecl
NotFound_FailCallback(
    _In_ PANSI_STRING Name,
    _In_ NTSTATUS Status)
{
    PDWORD p = (PDWORD)Name->Buffer;
    g_TestPassed = (Name->Length == 16 &&
                    p[0] == ('PteG') && p[1] == ('Pgul') && p[2] == ('Eyal') && p[3] == ('tnev') &&
                    Status == STATUS_PROCEDURE_NOT_FOUND);

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
    if (&ScGetPlugPlayEvent &&
        (SharedUserData->NtMajorVersion > 6 ||
         SharedUserData->NtMajorVersion == 6 && SharedUserData->NtMinorVersion >= 2))
    {
        return g_TestPassed;
    }

    return TRUE;
}
