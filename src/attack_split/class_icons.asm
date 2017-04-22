@insert at 0x81375E0 via bx_r0

.align 2
.global load_split_chart3
.thumb

.thumb_func
load_split_chart3:

@checking the data that is requested to draw



ldr r0, [r4]
ldr r1, =0x3214
add r0, r1
ldrb r0, [r0]
cmp r0, #3	@3 means that we are requesting a description draw, 
			@if we are not in 3 we do not draw the icon (e.g. 
			@for the "back"-button or for other stuff that is
			@drawn while not in attack descrption stuff)
bne end_func

@loading current index
ldr r0, =0x0203B16D
ldrb r2, [r0]

@loading tm state
ldr r4, =0x0203B140
ldr r4, [r4] @bank
ldr r0, =0x3208
add r0, r4
ldrb r0, [r0]
cmp r0, #2
beq is_tm

@is not tm so index = 4 means also no type
cmp r2, #4
beq end_func

is_tm:
cmp r2, #4
bhi end_func

@find our attack
ldr r1, =0x3258
add r1, r4

lsl r2, #1
add r1, r2
ldrh r0, [r1]

mov r1, #0xC
mul r0, r1
ldr r1, =attacks	@the attack table
add r0, r1
ldrb r1, [r0, #0xA]	@we got the category

loading:

@loading the tileset

lsl r1, #0x8	@0x100 bytes per icon
ldr r0, =gfx_attack_classesTiles
add r1, r0
mov r0, #0x1
str r0, [sp] @copy set
mov r0, #0x0
mov r2, #0x80
lsl r2, #1	@0x100 bytes as size
ldr r3, =0x4000
bl bg_copy_vram

@now we copy the tilemap (the lower and upper line of the icon seperate)
mov r0, #0x0
bl bg_get_tilemap
mov r3, r0
ldr r1, =0x1D4
add r1, r0
adr r0, upper_line
ldmia r0!, {r2}
stmia r1!, {r2}
ldmia r0!, {r2}
stmia r1!, {r2}

ldr r1, =0x214
add r1, r3
adr r0, lower_line
ldmia r0!, {r2}
stmia r1!, {r2}
ldmia r0!, {r2}
stmia r1!, {r2}

b end_func

category_none:
mov r1, #3
b loading

end_func:
pop {r4}
pop {r0}
bx r0

bg_copy_vram:
ldr r4, =0x080012A9
bx r4

bg_get_tilemap:
ldr r1, =0x08002019
bx r1


.align 4
upper_line:
.hword 0x6200
.hword 0x6201
.hword 0x6202
.hword 0x6203

.align 4
lower_line:
.hword 0x6204
.hword 0x6205
.hword 0x6206
.hword 0x6207
