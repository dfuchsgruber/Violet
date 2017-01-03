.global hook_whiteout

.align 2
.thumb

.thumb_func
hook_whiteout:
push {lr}
sub sp, #4
bl whiteout
mov r0, #0x87
lsl r0, #3
ldr r1, = 0x03003040
ldr r2, =0x080566CE | 1
bx r2
