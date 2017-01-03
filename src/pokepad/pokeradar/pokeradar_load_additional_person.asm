@insert via bx_r0 at 0x550B4

.global pokeradar_load_additional_person

.align 2
.thumb

.equ flag, 0x917

pokeradar_load_additional_person:
@when reaching this point we need to add our new overworld to this list though
mov r0, r10
ldr r1, [r0]
mov r3, r8
mov r0, #0x18
mul r0, r3
add r1, r0
mov r4, #0x8E
lsl r4, #4
add r1, r4
mov r5, r1
adr r0, overworld
ldmia r0!, {r2}
stmia r1!, {r2}
ldmia r0!, {r2}
stmia r1!, {r2}
ldmia r0!, {r2}
stmia r1!, {r2}
ldmia r0!, {r2}
stmia r1!, {r2}
ldmia r0!, {r2}
stmia r1!, {r2}
ldmia r0!, {r2}
stmia r1!, {r2}

definite_end:
ldr r0, =flag
bl setflag
pop {r3-r5}
mov r8, r3
mov r9, r4
mov r10, r5
pop {r4-r7}
pop {r0}
bx r0

setflag:
ldr r1, =0x0806E5E5
bx r1

@this is the additional overworld we load
.align 2
overworld:
.byte 254	@id of the additional npc
.byte 155	@picture
.byte 0x0
.byte 0x0	@unkowns
.hword 0x0	@x
.hword 0x0	@y
.byte 0x0	@level
.byte 0x2	@movement type = herumgehen
.byte 0x0	@movement
.byte 0x0	@unkown
.byte 0x1	@is_trainer? YES
.byte 0x0	@unkown
.hword 0x3	@how wide can npc see?
.word script_pokeradar_battle	@script to test
.hword flag
.hword 0
