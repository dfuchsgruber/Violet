@insert at 0x032A94 via bx r0.bin

.align 2
.thumb

.global mega_trigger_reset

mega_trigger_reset:
push {lr}
ldr r0, =0x02023BC4
ldrb r1, [r0]
mov r0, #0x58
mul r1, r0
ldr r0, =0x02023BE4
add r0, r1
add r0, #0x3B
mov r1, #0x0
strb r1, [r0]
bl sub_08001970
lsl r0, #0x18
lsr r1, r0, #0x18
ldr r0, =0x08032A9F
bx r0



sub_08001970:
ldr r0, =0x08001971
bx r0
