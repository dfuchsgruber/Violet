.include "overworld_script.s"
@0806D154 via r0

.align 2
.thumb

.global hook_get_behavior_script

.thumb_func
hook_get_behavior_script:

push {r4-r5, lr}
lsl r1, #0x18
lsr r4, r1, #0x18
lsl r2, #0x18
lsr r5, r2, #0x18
ldr r0, =0x020370D4
strh r5, [r0]

cmp r4, #0xB2
beq trigger_tv

cmp r4, #0xB3
beq trigger_trash

cmp r4, #0xB8
beq trigger_cloud

cmp r4, #0xB9
beq trigger_cloud_back

cmp r4, #0xBC
beq trigger_any_behavior

ldr r0, =0x924
bl _checkflag
cmp r0, #0
beq ret

cmp r4, #0xB1
beq trigger_dungeon_entry


ret:
ldr r0, =0x0806D15F
bx r0

trigger_trash:
mov r0, r5
bl generate_trash_item
ldr r0, =0x089279D4
b ret_s

trigger_tv:
cmp r5, #2
bne ret
ldr r0, =script_tv
b ret_s

trigger_any_behavior:
bl singpost_behavior_xBC
b ret_s


trigger_cloud:
mov r0, #0
exec_trigger_cloud:
bl cloud_trigger
b ret_s

trigger_cloud_back:
mov r0, #1
b exec_trigger_cloud


trigger_dungeon_entry:
ldr r0, =script_d_entry
ret_s:
pop {r4-r5}
pop {r1}
bx r1

_checkflag:
ldr r1, =checkflag
bx r1



script_d_entry:
.byte 0xF 
.byte 0 
.word 0x88102A3 @loadpointer 0 @text
.byte 0x9 
.byte 0x5 @callstd 5
.byte 0x21 
.hword 0x800D 
.hword 0	@compare LASTRESULT 0
.byte 0x6 
.byte 01
.word sden	@if 0x1 goto @sden

.byte 0xF 
.byte 0 
.word 0x88102E5 @loadpointer 0 @text
.byte 0x9 
.byte 0x6 @callstd 6

 setvar 0x50E1 0
.byte 0x23 
.word dungeon_store_current_pos @callasm store...
.byte 0x29 
.hword 0x922

.byte 0x39 
.byte 3
.byte 3
.byte 0 
.hword 0 
.hword 0
.byte 0x27
.byte 2

sden:
.byte 0x68	@closeonkeypress
.byte 0x2


script_tv:
.byte 0x23
.word load_tv_text	@callasm load tv text
.byte 0x9
.byte 0x3	@callstd 3
.byte 2




