@insert at 0x1A0C4 via bx_r0.bin
.global ability_management_battle_enter

.align 2
.thumb

.thumb_func
ability_management_battle_enter:
mov r1, r8
ldrb r0, [r1]
mov r1, r10
bl abilities_battle_enter
cmp r0, #0
beq no_trigger
ldr r0, =0x0801BADF
bx r0 


no_trigger:
mov r1, r8
ldrb r0, [r1]
cmp r0, #0x2D
beq sandstorm
ldr r1, =0x0801A0CD
bx r1




sandstorm:
ldr r0, =0x0801A231
bx r0
