#pragma once

#include <KNSoft/NDK/NDK.h>

#include "../KNSoft.Syscall/Syscall.h"

typedef
_Function_class_(FN_TEST_PROC)
_Success_(return != FALSE)
LOGICAL
FN_TEST_PROC(VOID);
typedef FN_TEST_PROC* PFN_TEST_PROC;

void
PrintEx(
    _In_reads_bytes_(TextSize) PCCH Text,
    _In_ ULONG TextSize);

#define Print(Text) PrintEx(Text, sizeof(Text))
