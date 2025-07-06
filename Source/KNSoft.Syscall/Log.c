#include "Syscall.inl"

static
_Function_class_(FN_Syscall_Log)
VOID
__cdecl
Syscall_Log_Default(
    _In_ ULONG Level,
    _In_z_ _Printf_format_string_ PCSTR Format,
    ...)
{
    va_list ArgList;

    va_start(ArgList, Format);
    vDbgPrintEx(DPFLTR_DEFAULT_ID, Level, Format, ArgList);
    va_end(ArgList);
}

PFN_Syscall_Log Syscall_Log = Syscall_Log_Default;
