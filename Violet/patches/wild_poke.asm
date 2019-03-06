.org 0x0806CB54
	ldr r0, =wildbattle_trainerschool_hook_trigger_script | 1
	bx r0
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

.org 0x0803DCB8
		mov r0, r5
		ldr r1, =pokemon_new_pid_with_nature | 1
		bl blxr1x0803DCB8
		mov r4, r0
		ldr r1, =0x0803DCD8 | 1
		blxr1x0803DCB8:
		bx r1
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
