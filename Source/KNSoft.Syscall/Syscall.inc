INCLUDE KNSoft\NDK\Assembly\Header.inc
INCLUDE KNSoft\NDK\Assembly\NDK.inc

$STACKFRAME FALSE

EXTERN $SYMBOLNAME(Syscall_FastSystemCall):SIZE_T

$SYSCALL_FUNCNAME TEXTEQU <>
$SYSCALL_THUNKNAME TEXTEQU <>

IFDEF _M_X64

$SYSCALL_FUNC MACRO Name:REQ, ArgCount

    $SYSCALL_FUNCNAME CATSTR <Syscall_>, <Name>

    $SYSCALL_FUNCNAME LABEL PROC
    ALIGN 16
    mov eax, dword ptr $SYSCALL_THUNKNAME
    jmp [Syscall_FastSystemCall]

ENDM

ELSEIFDEF _M_IX86

$SYSCALL_FUNC MACRO Name:REQ, ArgCount:REQ

    LOCAL ArgSize
    ArgSize = ArgCount * 4
    $SYSCALL_FUNCNAME CATSTR <Syscall_>, $SYMBOLNAME(Name, ArgSize)

    $SYSCALL_FUNCNAME LABEL PROC
    ALIGN 16
    mov eax, dword ptr $SYSCALL_THUNKNAME
    call [$SYMBOLNAME(Syscall_FastSystemCall)]
    ret ArgSize

ENDM

ENDIF

$SYSCALL MACRO Name:REQ, NtUser:REQ, ArgCount:REQ, Blob:VARARG

    LOCAL BlobSize, BlobArray
    BlobSize = -1
    BlobArray TEXTEQU <>
    FOR p, <Blob>
        BlobArray CATSTR BlobArray, <p, >
        BlobSize = BlobSize + 1
    ENDM
    $SYSCALL_THUNKNAME CATSTR <Syscall_ThunkData_>, <Name>

ScCode SEGMENT PARA READ EXECUTE ALIAS(".ScCode")
    $SYSCALL_FUNC Name, ArgCount
ScCode ENDS

ScData SEGMENT DWORD READ WRITE ALIAS(".ScData")
    ALIGN 4
    $SYSCALL_THUNKNAME dw ((ArgCount AND 011111b) SHL 7) OR ((BlobSize AND 0111111b) SHL 1) OR (NtUser AND 01b)
    SIZE_T offset $SYSCALL_FUNCNAME
    db @SubStr(<%BlobArray>, 1, @SizeStr(<%BlobArray>) - 2)
ScData ENDS

ScThunk SEGMENT ALIGN(SIZEOF SIZE_T) READ WRITE ALIAS(".ScThunk$THK")
    PUBLIC $SYMBOLNAME(Name)
    $SYMBOLNAME(Name) SIZE_T offset $SYSCALL_THUNKNAME
ScThunk ENDS

ENDM
