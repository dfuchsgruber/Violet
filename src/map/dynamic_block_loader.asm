@// at via r0 080589FC

.align 2
.thumb

.global dynamic_block_loader


.thumb_func
dynamic_block_loader:
@ --------------------------------- this code is garbage, since the timing is wrong

ldr r0, =0x03004F58
ldr r1, [r0]
ldrb r0, [r1, #4]
ldrb r1, [r1, #5]
bl is_dungeon_map
cmp r0, #0
beq not_dyn

@bl compute_dungeon_blocks
not_dyn:
bl launch_mapscript2
pop {r0}
bx r0


launch_mapscript2:
ldr r0, =0x8069C29
bx r0


.global reset_mapchanges_hook
.thumb_func
reset_mapchanges_hook:
ldr r0, =0x03004F58
ldr r1, [r0]
ldrb r0, [r1, #4]
ldrb r1, [r1, #5]
bl is_dungeon_map
cmp r0, #0
beq skip
@bl dungeon_compute_blocks
bl dungeon2_compute
skip:
add sp, #4
pop {r4-r6}
pop {r0}
bx r0
