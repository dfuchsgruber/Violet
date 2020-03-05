
.global reset_mapchanges_hook


.align 2
.thumb

.thumb_func
reset_mapchanges_hook:
ldr r0, =0x03004F58
ldr r1, [r0]
ldrb r0, [r1, #4]
ldrb r1, [r1, #5]
bl dungeon_get_type
bl dungeon2_compute
skip:
add sp, #4
pop {r4-r6}
pop {r0}
bx r0
