#include <KNSoft/NDK/NDK.h>

#include "UnitTest.h"

#pragma comment (lib, "KNSoft.Syscall.lib")

/* Test case functions */

extern FN_TEST_PROC AllThunks;
extern FN_TEST_PROC MemPageAlloc;
extern FN_TEST_PROC NoImport;
extern FN_TEST_PROC NotFound;

static PFN_TEST_PROC TestList[] = {
    &AllThunks,
    &MemPageAlloc,
    &NoImport,
    &NotFound
};

/* Standard output */

static HANDLE StdOutput = NULL;

void
PrintEx(
    _In_reads_bytes_(TextSize) PCCH Text,
    _In_ ULONG TextSize)
{
    IO_STATUS_BLOCK IoStatusBlock;
    ScWriteFile(StdOutput, NULL, NULL, NULL, &IoStatusBlock, (PVOID)Text, TextSize, NULL, NULL);
}

int
_cdecl
mainCRTStartup(void)
{
    NTSTATUS Status;
    HRESULT hr;
    
    /* Initialize standard output handle */
    StdOutput = NtCurrentPeb()->ProcessParameters->StandardOutput;
    if ((NtCurrentPeb()->ProcessParameters->WindowFlags & STARTF_USEMONITOR) ||
        StdOutput == INVALID_HANDLE_VALUE || StdOutput == NULL)
    {
        return STATUS_INVALID_HANDLE;
    }

    /* Initialize syscall library */
    hr = Syscall_Init();
    if (FAILED(hr))
    {
        return hr;
    }

    /* Make sure we could output something to console */
    Status = Syscall_GetData(&ScWriteFile);
    if (NT_ERROR(Status))
    {
        return Status;
    }

    /* Run tests */
    for (ULONG i = 0; i < ARRAYSIZE(TestList); i++)
    {
        if (!TestList[i]())
        {
            return STATUS_ASSERTION_FAILURE;
        }
    }

    return STATUS_SUCCESS;
}
