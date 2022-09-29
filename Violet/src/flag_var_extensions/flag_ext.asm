.global flag_ext

.align 2
.thumb

.thumb_func
flag_ext:
    ldr r0, =0x900
    cmp r4, r0
    blt std_flag
    ldr r0, =0x4000
    cmp r4, r0
    bge std_flag
    mov r0, r4
    bl flag_access_ext
    pop {r4-r6}
    pop {r1}
    bx r1

std_flag:
    ldr r0, =0x3005DD8
    ldrb r0, [r0]
    ldr r1, =0x806E53F
    bx r1
