.align 2
.thumb

.global hook_tile_init

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

