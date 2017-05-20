@//insert via bx_r2 at 0x080162D0

.global hook_attack_init

.align 2
.thumb

.thumb_func
hook_attack_init:
    strb r0, [r1]
    bl attack_init_trigger_abilities
    add sp, #8
    pop {r3-r5}
    mov r8, r3
    mov r9, r4
    mov r10, r5
    pop {r4-r7}
    pop {r0}
    bx r0

