@insert at 0x1A0C4 via bx_r0.bin
.global ability_management_battle_enter

.align 2
.thumb

.equ hailalarm, 0x5F
.equ bsc_hailalarm, 0x88AC9C7


.thumb_func
ability_management_battle_enter:
ldrb r0, [r1]
cmp r0, #0x2D
beq sandstorm
cmp r0, #hailalarm
beq h_alarm
ldr r1, =0x0801A0CD
bx r1
end_event:
ldr r0, =0x0801BB2F
bx r0


h_alarm:
ldr r0, =0x2023F1C
ldrh r1, [r0]
mov r2, #0x80
and r1, r2
cmp r1, #0
bne end_event
strh r2, [r0]
ldr r0, =bsc_hailalarm
bl init_bsc
ldr r0, =0x02023FC4
mov r2, r10
strb r2, [r0, #0x17]
increment_r9:
ldr r0, =0x0801BADF
bx r0 


sandstorm:
ldr r0, =0x0801A231
bx r0

init_bsc:
ldr r1, =0x801BBA9
bx r1