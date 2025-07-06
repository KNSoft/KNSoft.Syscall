#include "../KNSoft.Syscall/Syscall.h"

#pragma comment (lib, "KNSoft.Syscall.lib")

int
_cdecl
wmain(
    _In_ int argc,
    _In_reads_(argc) _Pre_z_ wchar_t** argv)
{
    NTSTATUS Status;
    HRESULT hr;
    PBYTE Base = NULL;
    SIZE_T Size = PAGE_SIZE;

    hr = Syscall_Init();
    if (FAILED(hr))
    {
        return hr;
    }

    // Status = ScGetPlugPlayEvent(NULL, NULL, NULL, 0);

    Status = ScAllocateVirtualMemory(NtCurrentProcess(), &Base, 0, &Size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    if (!NT_SUCCESS(Status))
    {
        return Status;
    }
    *Base = 0xFF;
    Status = ScFreeVirtualMemory(NtCurrentProcess(), &Base, &Size, MEM_RELEASE);
    if (!NT_SUCCESS(Status))
    {
        return Status;
    }

    ScTerminateProcess(NtCurrentProcess(), STATUS_SUCCESS);
    return STATUS_ASSERTION_FAILURE;
}
