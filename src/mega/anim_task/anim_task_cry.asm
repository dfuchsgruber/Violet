.align 2
.thumb


.global anim_task_cry

.thumb_func
anim_task_cry:
push {r4, lr}
mov r4, r0
ldr r0, =cb_mega_anim
bl search_if_func_is_already_a_cb
cmp r0, #0xFF
bne skip_0
mov r0, #0
skip_0:

mov r1, #0x28
mul r0, r1
ldr r1, =0x03004FE0
add r0, r1
ldrh r1, [r0, #0xA]

mov r0, #0x58
mul r1, r0
ldr r0, =0x02023BE4
add r1, r0
ldrh r0, [r1]	@species

mov r1, #0xFF
bl cry

mov r0, r4
bl end_anim_cb

pop {r4, pc}


cry:
ldr r2, =0x8071E89
bx r2


end_anim_cb:
ldr r1, =0x080726C5
bx r1


search_if_func_is_already_a_cb:
ldr r1, =0x80775ED
bx r1
