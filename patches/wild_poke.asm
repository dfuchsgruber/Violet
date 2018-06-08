
//wild poke
.org 0x0803DA0C
	ldr r1, =wild_poke_less_shinies | 1
	bx r1
	.pool


.org 0x08082898
        ldr r0, =map_wild_pokemon_get_current_table_id | 1
        bx r0
        .pool

.org 0x080831B0
		ldr r1, =map_wildbattle_init_seed | 1
		bx r1
		.pool

.org 0x08082C20
		ldr r2, =map_wildbattle_init | 1
		bx r2
		.pool

.org 0x8082cb0
	.word wild_pokemon

.org 0x8082d7c
	.word wild_pokemon

.org 0x8082e0c
	.word wild_pokemon

.org 0x8082e7c
	.word wild_pokemon

.org 0x8082ecc
	.word wild_pokemon

.org 0x8082f08
	.word wild_pokemon

.org 0x8082f48
	.word wild_pokemon

.org 0x8082f88
	.word wild_pokemon

.org 0x8083010
	.word wild_pokemon

.org 0x80831ec
	.word wild_pokemon

.org 0x8083210
	.word wild_pokemon

.org 0x813cb14
	.word wild_pokemon

.org 0x813cbcc
	.word wild_pokemon
