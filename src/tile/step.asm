@insert this at 0x6d684 via bx_r0.bin
@this code executes something everytime you step on a tile

.align 2
.thumb

.equ table, 0x9196280
@table looks like: [hword: BlockID] 00 00 [word: Function to call] ... [FF FF]

.global tile_step

.thumb_func
tile_step:

ldr r0, =0x50E2
bl vardecrypt
ldrh r1, [r0]
cmp r1, #250
bge skip_inc
add r1, #1
strh r1, [r0]
skip_inc:

bl do_fata_morgana


bl dungeon_crash
cmp r0, #0
bne ret_1


sub sp, #0x4
mov r0, sp
add r1, r0, #2
bl get_current_tile_position
mov r2, sp
ldrh r0, [r2]
lsl r0, #0x10
asr r0, #0x10
ldrh r1, [r2, #2]
lsl r1, #0x10
asr r1, #0x10
mov r2, #0x8
add sp, #4
bl get_tiles_attribute
mov r1, #0xFF
and r0, r1




@now has the block ID in r0
ldr r1, =table
ldr r3, =0xFFFF

scan_table:
ldrh r2, [r1]
cmp r2, r3
beq not_found
cmp r2, r0
beq found
add r1, #0x8
b scan_table
found:
ldr r0, [r1, #0x4]
bl call_via_r0
not_found:


ldr r0, =0x0919A461	@pokeradar poschange
bl call_via_r0


ldr r0, =0x081E7F95
mov r1, #0x8
bl spawn_big_cb

lsl r0, #0x18
lsr r0, r0, #0x18
mov r4, r0
lsl r1, r0, #2
add r1, r0
lsl r1, #3
ldr r0, =0x03004FE0
add r0, r1

mov r1, #0
mov r2, #0
loop:
lsl r3, r2, #1
add r3, r0
strh r1, [r3, #0x8]
add r2, #1
cmp r2, #0xF
bls loop


mov r1, r4
ldr r0, =0x02036DFC
ldr r0, [r0, #4]	@loading some maps dat

bl check_detector
mov r1, r0	@result of decetor_check_in_r4
mov r0, r4
mov r4, r1
bl remove_big_cb
ldr r0, =0x50f7
bl vardecrypt
ldrb r1, [r0]
cmp r1, #0
beq last_step_was_not
strb r4, [r0]
b end_main

last_step_was_not:
cmp r4, #0
beq end_main
mov r1, #1
strb r1, [r0]
ldr r0, =0x91D

bl checkflag
cmp r0, #0
beq end_main

@get the option
ldr r0, =0x03004F5C	@saveblock2 ptr
ldr r1, [r0]
ldrb r0, [r1, #0x13]	@detector settings
cmp r0, #0
beq entire_script
cmp r0, #1
bne end_main

@partial script, sound only
ldr r0, =0x88FB1A6
bl script_init
b ret_1

entire_script:
ldr r0, = 0x88F5B89
bl script_init
b ret_1
end_main:

bl safari_do_step
lsl r0, #0x18
lsr r0, #0x18
ldr r1, =0x0806d68d
bx r1



ret_1:
ldr r0, =0x00806D695
bx r0

script_init:
ldr r1, =0x08069AD5
bx r1

checkflag:
ldr r1, =0x0806E635
bx r1

safari_do_step:
ldr r0, =0x080A0ff9
call_via_r0:
bx r0


vardecrypt:
ldr r1, =0x0806E3B9
bx r1

spawn_big_cb:
ldr r2, =0x08077381
bx r2

check_detector:
ldr r2, =0x0813EEC5
bx r2

playsong:
ldr r1, =0x081E138D
bx r1

remove_big_cb:
ldr r1, =0x0807746D
bx r1



get_current_tile_position:
ldr r2, =0x0805C539
bx r2

get_tiles_attribute:
ldr r3, =0x08058f49
bx r3
