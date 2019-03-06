@insert at 0x79D20 via bx_r1.bin

.align 2
.thumb

.global mega_reset


.thumb_func
mega_reset:
push {r4, lr}
lsl r0, #0x18
lsr r4, r0, #0x18
bl mega_reset_do
ldr r2, =0x02037F34
ldr r1, =0x08079D29
bx r1

