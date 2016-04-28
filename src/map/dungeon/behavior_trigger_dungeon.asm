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

cmp r4, #0xB0
beq trigger_dungeon_entry

ldr r0, =0x0806D15F
bx r0


trigger_dungeon_entry:
adr r0, script_d_entry
pop {r4-r5}
pop {r1}
bx r1

script_d_entry:






