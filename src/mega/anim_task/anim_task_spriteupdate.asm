.global anim_task_sprite_update

.align 2
.thumb

.thumb_func
anim_task_sprite_update:
push {r4-r7, lr}
mov r6, r0

ldr r0, =cb_mega_anim
bl search_if_func_is_already_a_cb
cmp r0, #0xFF
bne skip_0
mov r0, #0
skip_0:
mov r1, #0x28
mul r0, r1
ldr r1, =0x03004FE0
add r0, r1
ldrh r5, [r0, #0xA]

@we first update our sprite

mov r1, #0x28
mul r1, r6
ldr r7, =0x03004FE0
add r7, r1
ldrh r1, [r7, #0x8]
cmp r1, #1
beq return_old_pos

mov r1, #1
strh r1, [r7, #8]

mov r0, r5
mov r1, r5
mov r2, #0
bl load_graphic_for_wandler


@move oam away
ldr r0, =0x02023D44
add r0, r5
ldrb r1, [r0]	@oam_id
mov r0, #0x44
mul r1, r0
ldr r0, =0x0202063C
add r0, r1

ldrh r1, [r0, #0x20]
strh r1, [r7, #0xA]




mov r1, #0
sub r1, #32	@-32
strh r1, [r0, #0x20] 	@move offscreen

ldrh r1, [r0, #0x4]
lsr r0, r1, #12
add r0, #16
lsl r0, #4
mov r1, #16
mov r2, #16
ldr r3, =0x7FFF
bl color_blend

pop {r4-r7, pc}



return_old_pos:

@now we need to make the palette white by using color blend
@first we get the oam
ldr r0, =0x02023D44
add r0, r5
ldrb r1, [r0]	@oam_id
mov r0, #0x44
mul r1, r0
ldr r0, =0x0202063C
add r0, r1

ldrh r1, [r7, #0xA]
strh r1, [r0, #0x20]


@now we remove our own task
mov r0, r6
bl end_anim_cb

pop {r4-r7, pc}


end_anim_cb:
ldr r1, =0x080726C5
bx r1

color_blend:
ldr r4, =0x08045179
bx r4

load_graphic_for_wandler:
ldr r3, =0x08034AF5
bx r3

search_if_func_is_already_a_cb:
ldr r1, =0x80775ED
bx r1
