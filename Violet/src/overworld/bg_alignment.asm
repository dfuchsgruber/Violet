@//*** Skips the bg alignment in the overworld

.include "flags.s"

.global bg_alignment

.align 4
.thumb

.thumb_func
bg_alignment:
push {r4, r5, lr}
ldr r0, =MAP_BGN_AUTO_ALIGN_OFF
bl _checkflag
cmp r0, #0
bne jump_end
ldr r1, =0x03000E90
mov r0, r1
add r0, #0x8
mov r2, #0
ldr r5, =0x0805A5FD
bx r5


jump_end:
pop {r4, r5}
pop {r0}
bx r0



_checkflag:
ldr r1, =checkflag
bx r1
