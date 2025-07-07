INCLUDE Syscall.inc

.CODE

$PUBLIC_LABEL Syscall_Proc_Not_Found
    ALIGN 16
    mov eax, 0C000007Ah ; STATUS_PROCEDURE_NOT_FOUND
    ret

$PUBLIC_LABEL Syscall_Proc_Not_Supported
    ALIGN 16
    mov eax, 0C00000BBh ; STATUS_NOT_SUPPORTED
    ret

$PUBLIC_LABEL Syscall_Proc_GE_Win11_X64
    ALIGN 16
    mov r10, rcx
    syscall
    ret

$PUBLIC_LABEL Syscall_Proc_Int2E_GE_Win11_X64
    ALIGN 16
    mov r10, rcx
    int 02Eh
    ret

END