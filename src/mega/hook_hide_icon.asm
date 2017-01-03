@insert at 0x2E9A8 via bx_r0.bin

@this code is responsible for hiding the mega-evo icon

.align 2
.thumb


.global mega_trigger_callback
.global mega_hook_hide_icon

mega_hook_hide_icon:
push {r4-r7, lr}
mov r7, r8
push {r7}
sub sp, #4


ldr r0, =0x04000130
ldrh r0, [r0]	@keypad input direct read for l & r
neg r0, r0	@active keys are 1 now
lsr r0, #0x8	@bit 8 and 9 are l and r
mov r1, #3
and r1, r0

cmp r1, #3
bne not_lr_pressed



@set trigger
ldr r0, =0x02023BC4
ldrb r0, [r0]
mov r1, #0x58
mul r0, r1
ldr r1, =0x02023BE4
add r0, r1
add r0, #0x3B
mov r4, r0

@check trigger
ldrb r1, [r0]
cmp r1, #0
bne not_lr_pressed


sub r0, #0x3B
bl _can_mega_evolve
ldr r1, =0xFFFF
cmp r1, r0
beq not_lr_pressed


@check if we have a regent evoution
mov r0, r4
sub r0, #0x3B
bl _get_mega_if_can_mega_evolve
cmp r0, #0
beq not_lr_pressed
ldrh r1, [r0, #6]	@regent ?
cmp r1, #0
bne regent



bl _can_player_trigger_mega
cmp r0, #0
beq not_lr_pressed

regent:

mov r0, r4

mov r1, #0x1
strb r1, [r0]

@play sound for trigger
mov r0, #184
bl sound

@spawn callback
ldr r0,  =mega_trigger_callback
mov r1, #0
bl spawn_big_cb

mov r1, #0x28
mul r0, r1
ldr r1, =0x3004FE0
add r0, r1
str r4, [r0, #0x8]

ldr r1, =0x02023BC4
ldrb r1, [r1]
strb r1, [r0, #0x10]
b not_b_pressed

not_lr_pressed:
ldr r0, =0x03003040
ldrh r1, [r0, #0x2E]	@proceted keys
mov r2, #3	@a and b are filtered
and r1, r2
cmp r1, #0
beq end_func


@a or b was pressed, if we pressed b we untrigger
mov r2, #2
and r2, r1
cmp r2, #0
beq not_b_pressed

ldr r0, =0x02023BC4
ldrb r0, [r0]
mov r1, #0x58
mul r0, r1
ldr r1, =0x02023BE4
add r0, r1
add r0, #0x3B
mov r1, #0x0
strb r1, [r0]


not_b_pressed:

@we hide the object if present
ldr r2, =0x020370D0
ldrh r1, [r2]
ldr r3, =0xFFFF
cmp r3, r1
beq end_func

strh r3, [r2]

mov r0, #0x44
mul r1, r0
ldr r0, =0x0202063C
add r1, r0
add r1, #0x2E
mov r0, #0x2
strh r0, [r1]

end_func:
ldr r0, =0x0802E9B1
bx r0


_can_mega_evolve:
ldr r1, =can_mega_evolve
bx r1

sound:
ldr r1, =0x8072231
bx r1

spawn_big_cb:
ldr r2, =0x08077381
bx r2

remove_big_callback:
ldr r1, =0x0807746D
bx r1

_can_player_trigger_mega:
ldr r0, =can_player_trigger_mega
bx r0

_get_mega_if_can_mega_evolve:
ldr r1, =get_mega_if_can_mega_evolve
bx r1

.align 4
.thumb


.thumb_func
mega_trigger_callback:
push {r4-r6, lr}
mov r5, r0
mov r1, #0x28
mul r0, r1
ldr r1, =0x3004FE0
add r0, r1
ldr r3, [r0, #0x8]	@dependent trigger
mov r6, r0

@finding the pal_id
ldrb r0, [r0, #0x10] @pokeindex
ldr r1, =0x02023D44
add r0, r1
ldrb r1, [r0]	@oam_index
mov r0, #0x44
mul r1, r0
ldr r0, =0x0202063C
add r1, r0
ldrh r0, [r1, #0x4]	@oamattribute2
lsr r0, #12
lsl r0, #4	@16 colors per palette
mov r1, #1
lsl r1, #8
add r0, r1	@color to affect



ldrb r1, [r3]
cmp r1, #0
bne	do_blend

@resetting to normal
mov r1, #16
mov r2, #0
mov r3, #0
bl color_blend

@despawning the callback
mov r0, r5
bl remove_big_callback
b end_funcc

do_blend:
ldrb r2, [r6, #0x11]
cmp r2, #0
beq count_up
@count_down:

ldrb r1, [r6, #0x12]
cmp r1, #0
beq switch_to_count_up
sub r1, #1
strb r1, [r6, #0x12]
b blend

switch_to_count_up:
strb r1, [r6, #0x11]
b blend

count_up:
ldrb r1, [r6, #0x12]
cmp r1, #16
bge switch_to_count_down
add r1, #1
strb r1, [r6, #0x12]
b blend

switch_to_count_down:
mov r2, #0x1
strb r2, [r6, #0x11]
b blend

blend:	@we need the intensitiy in r1 jetzt

ldrb r2, [r6, #0x10]
mov r3, #0x58
mul r2, r3
ldr r3, =0x02023BE4
add r3, r2
ldrh r2, [r3]	@species

ldr r3, =0x194	@kyogre
cmp r2, r3
bne check_g
ldr r3, =0x6C86
b do_blendx

check_g:
add r3, #1
cmp r2, r3
bne check_r
ldr r3, =0x61F
b do_blendx

check_r:
add r3, #1
cmp r2, r3
bne nmegacol
ldr r3, =0x372a
b do_blendx

nmegacol:
ldr r3, =0x7FFF

do_blendx:	
mov r2, r1
mov r1, #16
bl color_blend

end_funcc:
pop {r4-r6, pc}




.align 2
.thumb

color_blend:
ldr r4, =0x08045179
bx r4








