
//abilities and items
.org 0x0801A378
	ldr r0, =hook_turn_end | 1
	bx r0
	.pool

.org 0x0801A0C4
        ldr r0, =ability_management_battle_enter | 1
        bx r0
        .pool


.org 0x0801A584
        ldr r0, =hook_attack_negating_abilities | 1
        bx r0
        .pool

//.org 0x0801a83c
//        ldr r0, =hook_battle_abilities_attack_done | 1
//        bx r0
//        .pool

// Move end battle script command x49
.org 0x08023b7a
        // The original command would have incremented the bsc offset by 3, instead we go to state 18
        mov r0, #18
        strb r0, [r1, #0x14]
        b 0x08023b82


.org 0x0801E800
        ldr r0, =hook_attack_type | 1
        bx r0
        .pool

.org 0x0801F5AC
        ldr r0, =hook_sturdy | 1
        bx r0
        .pool



//abilities
.org 0x80001c0
	.word ability_names

.org 0x80d823c
	.word ability_names

.org 0x80d8840
	.word ability_names

.org 0x813683c
	.word ability_names


.org 0x80001c4
	.word ability_descriptions

.org 0x8136844
	.word ability_descriptions

.org 0x8023F56
//load hidden ability
        ldr r1, =battler_load_ability_as_defender_by_slot | 1
        bl blxr1
        b lhiddenab0done
blxr1:
        bx r1
        .pool
        lsl r0, #0
lhiddenab0done:

.org 0x80130CC
        ldr r1, =battler_load_ability_as_defender_by_slot | 1
        bl blxr1
        b lhiddenab1done
        .pool
        lsl r0, #0
        lsl r0, #0
lhiddenab1done:

.org 0x08136792
//Bericht
    ldr r0, [r6]
    add r0, r8
    ldr r1, =battler_load_ability_as_defender | 1
    bl blxr1
    b bhiddenabdone
    lsl r0, #0
    .pool

bhiddenabdone:

.org 0x08040C7C
    ldr r1, =pokemon_get_ability | 1
    bx r1
    .pool


.org 0x080162D0
    ldr r2, =hook_attack_init | 1
    bx r2
    .pool

.org 0x0801E2B8
    ldr r0, =hook_pp_reduce | 1
    bx r0
    .pool

.org 0x0801a084
    .word battle_ability_case_intimidate1_hook
.org 0x0801a088
    .word battle_ability_case_intimidate2_hook
