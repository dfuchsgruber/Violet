.align 2
.thumb

.global hook_update_timezone

.thumb_func
hook_update_timezone:

ldr r0, =0x0805676D
str r0, [r1, #8]
bl update_timezone
pop {r0}
bx r0

