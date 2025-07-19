#pragma once

#include <KNSoft/NDK/NDK.h>

#include "../KNSoft.Syscall/Syscall.h"

typedef
_Function_class_(FN_TEST_PROC)
_Success_(return != FALSE)
LOGICAL
FN_TEST_PROC(VOID);
