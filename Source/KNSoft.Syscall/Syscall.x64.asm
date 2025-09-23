INCLUDE Syscall.inc

.CODE

$PUBLIC_LABEL Syscall_Proc_Fast
    ALIGN 16
    mov r10, rcx
    syscall
    ret

$PUBLIC_LABEL Syscall_Proc_Int2E
    ALIGN 16
    mov r10, rcx
    int 02Eh
    ret

END
