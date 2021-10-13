.global hook_battle_abilities_attack_type

.align 2
.thumb

.thumb_func
hook_battle_abilities_attack_type:
push {r3} //there, unfortunatly, is no other way to save the register
mov r0, r1
bl attack_type_by_ability
pop {r3}
mov r8, r0
ldr r0, =0x0801E80C | 1
bx r0


@insert at 0x1A0C4 via bx_r0.bin
.global hook_battle_abilities_battle_enter

.align 2
.thumb

.thumb_func
hook_battle_abilities_battle_enter:
mov r1, r8
ldrb r0, [r1]
mov r1, r10
bl abilities_battle_enter
cmp r0, #0
beq no_trigger
ldr r0, =0x0801BADF
bx r0 


no_trigger:
mov r1, r8
ldrb r0, [r1]
cmp r0, #0x2D
beq sandstorm
ldr r1, =0x0801A0CD
bx r1

sandstorm:
ldr r0, =0x0801A231
bx r0

@0801E2C0
.global hook_battle_abilities_pp_reduce

.align 2
.thumb

.thumb_func
hook_battle_abilities_pp_reduce:
    mov r0, r6
    bl pp_reduce
    ldr r0, =0x0801E2E6 | 1
    bx r0

.global hook_battle_abilities_stat_changes

.align 2
.thumb

.thumb_func

hook_battle_abilities_stat_changes:
@we get: r7 a_ang, r8 a_sang, r6 fast_ac_a, sp+4 fast_ac_d, sp+0x14 d_def, sp+0x18, d_sdef

    mov r8, r3
    ldr r0, [sp, #0x4]
    ldrh r0, [r0, #0xa]
    str r0, [sp, #0x18]

    mov r0, r8
    bl attacker_modify_satk
    mov r8, r0

    mov r0, r7
    bl attacker_modify_atk
    mov r7, r0

    ldr r0, [sp, #0x14]
    bl defender_modify_def
    str r0, [sp, #0x14]

    ldr r0, [sp, #0x18]
    bl defender_modify_sdef
    str r0, [sp, #0x18]

    @stats modified
    ldr r0, =0x0803EC80 | 1
    bx r0

.align 2
.thumb

.global hook_battle_abilities_turn_end

hook_battle_abilities_turn_end:
ldr r0, =0x02023D6B
mov r1, r10
strb r1, [r0]
mov r2, r8
ldrb r5, [r2]	@ability
mov r0, r5
mov r1, r4
bl battle_abilities_turn_end
cmp r0, #0
beq end_event
end_withbsc:
ldr r0, =0x801BADF
bx r0
end_event:
ldr r4, =0x0801BB2E | 1
bx r4

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

.global hook_battle_abilities_attack_negating

.align 2
.thumb

.thumb_func
hook_battle_abilities_attack_negating:
    mov r1, r8
    ldrb r0, [r1]
    mov r1, r4
    bl attack_negating_abilities
    cmp r0, #0
    beq no_trigger2
    ldr r1, =0x2023D74
    str r0, [r1]
    ldr r2, =0x801A5F6 | 1
    bx r2


    no_trigger2:
    ldr r0, =0x0801BB2E | 1
    bx r0
