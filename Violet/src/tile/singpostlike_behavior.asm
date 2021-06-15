.include "overworld_script.s"
.include "flags.s"
.include "constants/block_behaviour.s"
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

cmp r4, #0xB1
beq trigger_dungeon_entry

cmp r4, #0xBD
beq trigger_rock_climb

cmp r4, #MB_CRAFTING_CAULDRON
beq trigger_crafting_cauldron

ret:
ldr r0, =0x0806D15F
bx r0

trigger_trash:
    ldr r0, =ow_script_trash
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
ldr r0, =ow_script_dungeon_enter
b ret_s

trigger_crafting_cauldron:
    ldr r0, =ow_script_crafting_cauldron
    b ret_s

trigger_rock_climb:
ldr r0, =ow_script_rock_climb
ret_s:
pop {r4-r5}
pop {r1}
bx r1


_checkflag:
ldr r1, =checkflag
bx r1


script_tv:
.byte 0x23
.word load_tv_text	@callasm load tv text
.byte 0x9
.byte 0x3	@callstd 3
.byte 2




