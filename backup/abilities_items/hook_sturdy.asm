.global hook_sturdy

.align 2
.thumb

.thumb_func

hook_sturdy:
bl trigger_sturdy
ldr r0, =0x2023D50 @no dmg
ldr r0, [r0]
ldr r1, =0x2710
cmp r0, r1
bgt skip
lsl r0, #0x10
lsr r1, r0, #0x10
skip:
ldr r0, =0x0801F5BB
bx r0
