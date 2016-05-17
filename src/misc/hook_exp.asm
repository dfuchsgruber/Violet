.align 2
.thumb

.global hook_exp

.thumb_func
hook_exp:

lsl r0, #2
add r0, r3
ldrb r2, [r0, #0x9]
add r1, #0x2A
ldrb r0, [r1]
mul r0, r2
bl modify_exp
ldr r1, =0x08021B6D
bx r1

