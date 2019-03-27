.org 0x080C04BC
    .word gfx_worldmapPal

.org 0x080C2EC0
    .word gfx_worldmapPal

.org 0x080C052C
    .word gfx_worldmapMap

.org 0x080C0500
    .word gfx_worldmapTiles

//patch to abort overwriting of unneccessary pal entries (grit can not deal with those)
.org 0x80C0486
    //copy transparent backdrop color at color 0xCF (BEWEGEN cursor)
    ldr r0, =gfx_worldmapPal
    mov r1, #0xCF
    mov r2, #2
    ldr r3, =0x80C04B6 | 1
    bx r3
    .pool

//worldmap as 256 color img
.org 0x83F12A8
    .word 0x29E0 //bg setup config with colmode = 1
    .word 0x30F9 //bg setup config with charbase at 0x06008000 (=2)


.org 0x080C434C
    .word worldmap0_position_data

.org 0x080C3EF4
    .word worldmap0_namespace_position_assoc

.org 0x080C43C4
    .word gfx_hiroine_headTiles

.org 0x80C43F4
    .word gfx_hiro_headTiles

.org 0x080C44B8
    .word gfx_hiroine_headPal

.org 0x080C44D4
    .word gfx_hiro_headPal

.org 0x080BFE20
    ldr r2, =map_get_flightposition | 1
    bx r2
    .pool

.org 0x080BFE80
    ldr r1, =flightposition_by_id | 1
    bx r1
    .pool

// Associate all maps with the Kanto map (default wm)
.org 0x080C0234
	ldr r0, =0x080C02A8 | 1
	bx r0
	.pool

.org 0x080C3CE0
	ldr r0, =worldmap_locate_player | 1
	bx r0
	.pool

// Always locate player via the locate routine
.org 0x080C3F00
	ldr r0, =0x080C42EA | 1
	bx r0
	.pool

.org 0x080c3794
    ldr r1, =worldmap_lower_layer_check | 1
    bx r1
    .pool

.org 0x080c3a30
    ldr r1, =worldmap_upper_layer_check | 1
    bx r1
    .pool

.org 0x080c5460
    .word flight_position_associations
    
