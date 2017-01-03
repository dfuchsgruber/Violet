
evolution_table equ 0x9195500

//evolutions
.org 0x08045878
	ldr r1, =get_pokemons_basis_stage | 1
	bx r1
	.pool
	
.org 0x08042E98
	ldr r0, =evolutions_evee | 1
	bx r0
	.pool

.org (evolution_table + ((0x10-1) * 4)) //evolution method 0xF, map
	.word evolution_m_map
	.pool

.org (evolution_table + ((0x11-1) * 4)) //evolution method holding item
	.word evolution_m_hitem
	.pool
	
.org (evolution_table + ((0x12-1) * 4)) //evolution method knowing move
	.word evolution_m_know_move
	.pool

.org (evolution_table + ((0x14-1) * 4)) //evolution method link & item hold
	.word 0x08043010
	.pool
	
.org (evolution_table + ((0x15-1) * 4)) //evolution method funkelstein&male
	.word 0x08043010
	.pool
	
.org 0x08043084
	ldr r0, =evolution_m_litem | 1
	bx r0
	.pool
	
.org 0x080419E4
	.word evolution_stone_remove_item
	.pool