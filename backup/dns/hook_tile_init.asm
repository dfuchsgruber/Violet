.align 2
.thumb

.global hook_tile_init
.global mapchange_tileset_pal_load_hook

.thumb_func
hook_tile_init:
mov r0, r4
bl tileset_load_pal_as_ts1
mov r0, r4
bl tile_init
pop {r4}
pop {r0}
bx r0

tileset_load_pal_as_ts1:
ldr r1, =0x08059AA1
bx r1

.thumb_func
mapchange_tileset_pal_load_hook:
ldr r0, [r4]
bl map_change_load_ts1_pal
mov r4, #7
ldr r0, =0x80558F4 | 1
bx r0


