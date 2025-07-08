#include "UnitTest.h"

TEST_FUNC(Test)
{
    NTSTATUS Status;
    HRESULT hr;
    PBYTE Base = NULL;
    SIZE_T Size = PAGE_SIZE;

    hr = Syscall_Init();
    TEST_OK(SUCCEEDED(hr));
    if (FAILED(hr))
    {
        return;
    }

    /*
     * Test case: Syscall not found
     * NtGetPlugPlayEvent was removed since NT 6.2, should returns STATUS_PROCEDURE_NOT_FOUND
     */
    if (SharedUserData->NtMajorVersion > 6 ||
        SharedUserData->NtMajorVersion == 6 && SharedUserData->NtMinorVersion >= 2)
    {
#pragma warning(disable: __WARNING_INVALID_PARAM_VALUE_1)
        Status = ScGetPlugPlayEvent(NULL, NULL, NULL, 0);
#pragma warning(default: __WARNING_INVALID_PARAM_VALUE_1)
        TEST_OK(Status == STATUS_PROCEDURE_NOT_FOUND);
    } else
    {
        TEST_SKIP("NT version < 6.2, NtGetPlugPlayEvent exists\n");
    }

    /*
     * Test case: Memory page allocation
     */
    Status = ScAllocateVirtualMemory(NtCurrentProcess(), &Base, 0, &Size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    TEST_OK(NT_SUCCESS(Status));
    if (NT_SUCCESS(Status))
    {
        *Base = 0xFF;
        Status = ScFreeVirtualMemory(NtCurrentProcess(), &Base, &Size, MEM_RELEASE);
        TEST_OK(NT_SUCCESS(Status));
    }
}
