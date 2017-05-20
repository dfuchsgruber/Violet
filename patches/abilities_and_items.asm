
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

.org 0x08023504
        ldr r0, =hook_attack_done | 1
        bx r0
        .pool

.org 0x0801E800
        ldr r0, =hook_attack_type | 1
        bx r0
        .pool



//scarf
.org 0x8014DC0
	ldr r2, =scarf_poke1_hook | 1
	bx r2
	.pool

.org 0x8014EA4
	ldr r2, =scarf_poke2_hook | 1
	bx r2
	.pool
	
.org 0x0803EE4C
	ldr r0, =choice_band_on_0 | 1
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
        ldr r1, =write_ability_into_dbuf_by_battler_slot | 1
        bl blxr1
        b lhiddenab0done
blxr1:
        bx r1
        .pool
        lsl r0, #0
lhiddenab0done:

.org 0x80130CC
        ldr r1, =write_ability_into_dbuf_by_battler_slot | 1
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
    ldr r1, =write_ability_into_dbuf | 1
    bl blxr1
    b bhiddenabdone
    lsl r0, #0
    .pool

bhiddenabdone:

.org 0x08040C7C
    ldr r1, =get_pokemons_ability | 1
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
