.global string_get_width_control_code_skip

.align 4
.thumb

string_get_width_control_code_skip:
    add r4, #1
    ldrb r0, [r4]
    add r5, r0
    ldr r0, = 0x0800607c | 1
    bx r0