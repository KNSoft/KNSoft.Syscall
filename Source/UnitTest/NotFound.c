#include "UnitTest.h"

/*
 * Test case: Syscall not found
 * NtGetPlugPlayEvent was removed since NT 6.2, should returns STATUS_PROCEDURE_NOT_FOUND
 */
_Function_class_(FN_TEST_PROC)
LOGICAL
NotFound(VOID)
{
    if ((SharedUserData->NtMajorVersion > 6 ||
         SharedUserData->NtMajorVersion == 6 && SharedUserData->NtMinorVersion >= 2))
    {
        if (Syscall_GetData(&ScGetPlugPlayEvent) != STATUS_PROCEDURE_NOT_FOUND)
        {
            return FALSE;
        }
    }

    return TRUE;
}
