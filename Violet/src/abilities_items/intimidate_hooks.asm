@insert as pointer in the switch table @0x0801a088
.global battle_ability_case_intimidate2_hook

.align 2
.thumb

.thumb_func
battle_ability_case_intimidate2_hook:
    bl battle_abilities_intimidate2
    mov r1, r9
    add r1, r0
    lsl r0, r1, #0x18
    lsr r1, r0, #0x18
    mov r9, r1
    ldr r0, =0x0801bb2e | 1
    bx r0

@insert as pointer in the switch table @0x0801a084
.global battle_ability_case_intimidate1_hook

.align 2
.thumb

.thumb_func
battle_ability_case_intimidate1_hook:
    bl battle_abilities_intimidate1
    mov r1, r9
    add r1, r0
    lsl r0, r1, #0x18
    lsr r1, r0, #0x18
    mov r9, r1
    ldr r0, =0x0801bb2e | 1
    bx r0
