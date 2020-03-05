.global hook_attack_negating_abilities

.align 2
.thumb

.thumb_func
hook_attack_negating_abilities:
    mov r1, r8
    ldrb r0, [r1]
    mov r1, r4
    bl attack_negating_abilities
    cmp r0, #0
    beq no_trigger
    ldr r1, =0x2023D74
    str r0, [r1]
    ldr r2, =0x801A5F6 | 1
    bx r2


    no_trigger:
    ldr r0, =0x0801BB2E | 1
    bx r0
