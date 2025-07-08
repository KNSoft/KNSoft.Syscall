INCLUDE Syscall.inc

.CODE

ASSUME fs:NOTHING

; STATUS_PROCEDURE_NOT_FOUND
$PUBLIC_LABEL Syscall_Proc_Not_Found
    ALIGN 16
    mov eax, 0C000007Ah ; STATUS_PROCEDURE_NOT_FOUND
    db 0C2h, 000h, 000h ; ret 0
    mov eax, 0C000007Ah
    ret 4 * 1
    mov eax, 0C000007Ah
    ret 4 * 2
    mov eax, 0C000007Ah
    ret 4 * 3
    mov eax, 0C000007Ah
    ret 4 * 4
    mov eax, 0C000007Ah
    ret 4 * 5
    mov eax, 0C000007Ah
    ret 4 * 6
    mov eax, 0C000007Ah
    ret 4 * 7
    mov eax, 0C000007Ah
    ret 4 * 8
    mov eax, 0C000007Ah
    ret 4 * 9
    mov eax, 0C000007Ah
    ret 4 * 10
    mov eax, 0C000007Ah
    ret 4 * 11
    mov eax, 0C000007Ah
    ret 4 * 12
    mov eax, 0C000007Ah
    ret 4 * 13
    mov eax, 0C000007Ah
    ret 4 * 14
    mov eax, 0C000007Ah
    ret 4 * 15
    mov eax, 0C000007Ah
    ret 4 * 16
    mov eax, 0C000007Ah
    ret 4 * 17

; STATUS_NOT_SUPPORTED
$PUBLIC_LABEL Syscall_Proc_Not_Supported
    ALIGN 16
    mov eax, 0C00000BBh ; STATUS_NOT_SUPPORTED
    db 0C2h, 000h, 000h ; ret 0
    mov eax, 0C00000BBh
    ret 4 * 1
    mov eax, 0C00000BBh
    ret 4 * 2
    mov eax, 0C00000BBh
    ret 4 * 3
    mov eax, 0C00000BBh
    ret 4 * 4
    mov eax, 0C00000BBh
    ret 4 * 5
    mov eax, 0C00000BBh
    ret 4 * 6
    mov eax, 0C00000BBh
    ret 4 * 7
    mov eax, 0C00000BBh
    ret 4 * 8
    mov eax, 0C00000BBh
    ret 4 * 9
    mov eax, 0C00000BBh
    ret 4 * 10
    mov eax, 0C00000BBh
    ret 4 * 11
    mov eax, 0C00000BBh
    ret 4 * 12
    mov eax, 0C00000BBh
    ret 4 * 13
    mov eax, 0C00000BBh
    ret 4 * 14
    mov eax, 0C00000BBh
    ret 4 * 15
    mov eax, 0C00000BBh
    ret 4 * 16
    mov eax, 0C00000BBh
    ret 4 * 17

$PUBLIC_LABEL Syscall_Proc_X86
    ALIGN 16
    mov edx, esp
    sysenter
    retn

$PUBLIC_LABEL Syscall_Proc_LE_Win7_WowTransition_X86
    ALIGN 16
    xor ecx, ecx
    lea edx, [esp + 8]
    call dword ptr fs:[0C0h]
    retn

END
