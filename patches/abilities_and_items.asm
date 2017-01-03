
//abilities and items
.org 0x0801A378
	ldr r0, =end_of_turn_ab | 1
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

.org 0x0801A584
        ldr r0, =hook_attack_negating_abilities | 1
        bx r0
        .pool
