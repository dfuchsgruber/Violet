overworld_pals equ 0x083A501C

.org 0x0805F2C8
    ldr r1, =overworld_get | 1
    bx r1
    .pool

.org overworld_pals + 8 * 8
    .word gfx_ow_pal_hiroPal

.org overworld_pals + 9 * 8
    .word gfx_ow_pal_hiro_mirrorPal


////////////////////////////////////////////////////////////////////////////////

.org 0x8064540
    .word npc_anims

.org 0x8064584
    .word npc_anims

.org 0x80645B4
    .word npc_anims

.org 0x0805BBD0
    ldr r1, = npc_player_walk_tile_accessable_hook | 1
    bx r1
    .pool

.org 0x0805B9E4
    ldr r1, = npc_player_init_move_hook | 1
    bx r1
    .pool


.org 0x80BD3F4
    ldr r1, = npc_player_init_bike_hook | 1
    bx r1
    .pool

//Fix for weird overworld of rival in intro...
.org 0x083E18C0
    .word gfx_ow_rival_allTiles

.org 0x083E18C8
    .word gfx_ow_rival_allPal
