.align 2
.thumb

.global hook_trainer_items

.thumb_func
hook_trainer_items:

ldr r1, [r7]
ldr r0, [r1, #0x18]
add r0, #0x24
bl load_trainer_items

bl func_80C6F58
pop {r4-r7}
pop {r0}
bx r0

func_80C6F58:
ldr r0, =0x80C6F59
bx r0
