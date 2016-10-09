overworld_table equ 0x08C80000

.org overworld_table + 4*1
    .word ow_mskate

.org overworld_table + 4*82
    .word ow_manus

.org overworld_table + 4*86
    .word ow_igva

.org overworld_table + 4*152
    .word ow_bbship

.org overworld_table + 4*153
    .word ow_mpirate

.org overworld_table + 4*154
    .word ow_shape_animal
    .word ow_shape_human
    .word ow_shape_tail
    .word ow_shape_snake
    .word ow_shape_winsect
    .word ow_shape_winged
    .word ow_shape_insect
    .word ow_shape_head
    .word ow_shape_arms
    .word ow_shape_legs
    .word ow_shape_tentacles
    .word ow_shape_fish
    .word ow_shape_ball
    .word ow_shape_multi

.org overworld_table + 4 * 168
    .word ow_mistral

.org overworld_table + 4 * 169
    .word ow_altaria


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