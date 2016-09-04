.global var_ext

.align 2
.thumb

.thumb_func
var_ext:
    ldr r0, =0x3FFF
    cmp r4, r0
    bhi valid_var
    mov r0, #0
    b end_func
valid_var:
    ldr r0, =0x5000
    cmp r4, r0
    blt std_var
    ldr r0, =0x5100
    cmp r4, r0
    bge std_var
    mov r0, r4
    bl var_access_ext
end_func:
    pop {r4-r6}
    pop {r1}
    bx r1

std_var:
    ldr r0, =0x806E3D1
    bx r0
