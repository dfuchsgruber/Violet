.global hook_protecting_attacks_reset

.align 2
.thumb

.thumb_func

hook_protecting_attacks_reset: 
@8026F18 via r1
    bl attack_is_protecting_move
    cmp r0, #0
    bne skip_reset
    mov r0, r8
    ldrb r3, [r0]
    ldr r0, =0x08026F24 | 1
    bx r0

skip_reset:
    ldr r0, =0x08026F30 | 1
    bx r0
    

