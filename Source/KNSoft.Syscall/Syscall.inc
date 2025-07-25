INCLUDE KNSoft\NDK\Assembly\Header.inc
INCLUDE KNSoft\NDK\Assembly\NDK.inc

$STACKFRAME FALSE

EXTERN $SYMBOLNAME(Syscall_FastSystemCall):SIZE_T

$SYSCALL_THUNKDATA TEXTEQU <>
$SYSCALL_THUNK TEXTEQU <>

IFDEF _M_X64

$SYSCALL_FUNC MACRO Name:REQ, ArgCount
    $PUBLIC_LABEL Name, PROC
    mov eax, dword ptr $SYSCALL_THUNK
    jmp [Syscall_FastSystemCall]
ENDM

ELSEIFDEF _M_IX86

$SYSCALL_FUNC MACRO Name:REQ, ArgCount:REQ
    $PUBLIC_LABEL $SYMBOLNAME(Name, ArgCount * 4), PROC
    mov eax, dword ptr $SYSCALL_THUNK
    call [$SYMBOLNAME(Syscall_FastSystemCall)]
    ret ArgCount * 4
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
    $SYSCALL_THUNKDATA CATSTR <Syscall_ThunkData_>, <Name>
    $SYSCALL_THUNK CATSTR <Syscall_Thunk_>, <Name>

ScCode SEGMENT PARA READ EXECUTE ALIAS(".ScCode")
    $SYSCALL_FUNC Name, ArgCount
ScCode ENDS

ScData SEGMENT DWORD READ WRITE ALIAS(".ScData")
    $SYSCALL_THUNKDATA db ((BlobSize AND 0111111b) SHL 1) OR (NtUser AND 01b)
    db @SubStr(<%BlobArray>, 1, @SizeStr(<%BlobArray>) - 2)
ScData ENDS

ScThunk SEGMENT ALIGN(SIZEOF SIZE_T) READ WRITE ALIAS(".ScThunk$THK")
    $SYSCALL_THUNK SIZE_T offset $SYSCALL_THUNKDATA
ScThunk ENDS

ENDM
