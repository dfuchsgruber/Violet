.global hook_kings_shield
.global hook_protect_attack_succeeds
.global hook_protect_attack_succeeds2
.global hook_kings_shield_drop

.align 2
.thumb

.thumb_func
hook_kings_shield:
    bl bsc_command_setprotect_apply_kings_shield
    mov r1, r8
    ldrb r0, [r1]
    lsl r1, r0, #3
    sub r1, r0
    lsl r1, #2
    ldr r0, =0x08026FC0 | 1
    bx r0

.align 2
.thumb

.thumb_func
hook_protect_attack_succeeds:
    bl protect_attack_succeeds
    cmp r0, #0
    bne success
    ldr r0, =0x0801D9E2 | 1
    bx r0
success:
    ldr r0, =0x0801DA78 | 1
    bx r0

.align 2
.thumb

.thumb_func
hook_protect_attack_succeeds2:
    bl protect_attack_succeeds
    cmp r0, #0
    bne success2
    ldr r0, =0x0801DBC6 | 1
    bx r0
success2:
    ldr r0, =0x0801DBE0 | 1
    bx r0

.align 2
.thumb

.thumb_func
hook_kings_shield_drop:
    bl bsc_push_kings_shield_drop
    pop {r4-r7}
    pop {r0}
    bx r0



