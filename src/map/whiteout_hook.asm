.global whiteout_hook

.align 2
.thumb

.thumb_func

whiteout_hook:
push {lr}
sub sp, #4
ldr r0, =0x50DF @var timezone
bl _vardecrypt
mov r1, #0
strh r1, [r0]
bl whiteout
ldr r1, =0x03003040 + 0x438 @superstate 
ldr r0, =0x080566D0 | 1
bx r0

_vardecrypt:
    ldr r1, =vardecrypt
    bx r1
