

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

// Overwrite gfx for the shallow water overworld effect
.org 0x083A534C + 0xC
	.word shallow_water_graphics


//hidden items
.org 0x080CC604
    ldr r2, =singpost_get_flag | 1
    bx r2
    .pool

.org 0x0806D120
    ldr r0, =hook_singpost_hidden_flag | 1
    bx r0
    .pool

.org 0x08083064
    .word script_repel_wore_off


.org 0x08097C9C
    .word cut_table

.org 0x805b298
	.word door_animations

.org 0x805b2cc
	.word door_animations

.org 0x805b300
	.word door_animations

.org 0x805b340
	.word door_animations

.org 0x805b37c
	.word door_animations


.org 0x083A52F0
    .word high_grass_graphics

.org 0x083A520C
    .word gfx_high_grassPal

//PC
.org 0x0806CE3C
    .word owscript_pc_turn_on

.org 0x083B95C8
    .word owscript_pc_turn_on


.org 0x0806CE40
    .word owscript_pc_turn_on2

.org 0x0806D178
    .word owscript_pc_turn_on2

.org 0x083CD334
    .word str_pc_take, str_pc_take_desc
    .word str_pc_deposit, str_pc_deposit_desc
    .word str_pc_move, str_pc_move_desc
    .word str_pc_move_items, str_pc_move_items_desc
    .word str_pc_adieu, str_pc_adieu

// Disable FRD's random spawning hidden items
.org 0x0815D60C
	bx lr
.org 0x0815D4D8
	bx lr

.org 0x0806D4AC
	ldr r3, =tile_trigger_water_scripts | 1
	bx r3
	.pool

