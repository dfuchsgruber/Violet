//tile
.org 0x0806d684
	ldr r0, =tile_step | 1
	bx r0
	.pool

.org 0x806D154
	ldr r0, =hook_get_behavior_script | 1
	bx r0
	.pool

.org 0x08059AE4
	ldr r0, =hook_tile_init | 1
	bx r0
	.pool
	
.org 0x0806CA94
        ldr r0, =pokepad_outdoor_trigger | 1
        bx r0
        .pool

.org 0x080680D0
        ldr r1, =tile_is_reflective | 1
        bx r1
        .pool


.org 0x080DB58C
        ldr r1, =tile_high_grass_init_hook | 1
        bx r1
        .pool

.org 0x80DB838
        ldr r1, =tile_tall_grass_init_hook | 1
        bx r1
        .pool


.org 0x08059F34
        ldr r1, =tile_is_high_grass_hook | 1
        bx r1
        .pool


.org 0x08059F44
        tile_is_any_grass_wrap:
        ldr r1, =tile_is_any_grass_hook | 1
        bx r1
        .pool
        b tile_is_any_grass_wrap


//prevents the help context from start menu to be ereased by decetor state
.org 0x0806F064
        mov r0, #0
        mov r0, #0


//overwrite gfx for therme graphic covers
.org 0x083A5D14
    .word gfx_grass_thermeTiles

.org 0x08398EA8
    .word 0x7B313F52

.org 0x08046294
    ldr r1, =pokemon_hatch_decrement_hook | 1
    bx r1
    .pool