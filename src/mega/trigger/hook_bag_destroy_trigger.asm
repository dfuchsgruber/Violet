.align 2
.thumb

.global hook_bag_destroy_trigger
.thumb_func
hook_bag_destroy_trigger:
push {lr}
bl destroy_trigger_cbs
ldr r0, =0x02023BC4
ldrb r1, [r0]
lsl r0, r1, #2
ldr r1, =0x03004F30
add r0, r1
ldr r1, =0x08032BED
str r1, [r0]
pop {pc}
