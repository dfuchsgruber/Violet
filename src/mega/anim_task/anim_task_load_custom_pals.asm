.align 2
.thumb

.global anim_task_load_custom_pals

.thumb_func
anim_task_load_custom_pals:
push {r4, lr}
mov r4, r0

@find the pal by tag
ldr r0, =0x27E3
bl pal_get_id_by_tag
cmp r0, #0xFF
beq skip_load0
add r0, #16
lsl r1, r0, #4
ldr r0, =0x93daf00
mov r2, #32
bl load_uncomp_pal_into_ram

skip_load0:

@find the pal by tag
ldr r0, =0x27E4
bl pal_get_id_by_tag
cmp r0, #0xFF
beq skip_load1
add r0, #16
lsl r1, r0, #4
ldr r0, =0x93daf00
mov r2, #32
bl load_uncomp_pal_into_ram

skip_load1:
mov r0, r4
bl end_anim_cb
pop {r4, pc}


end_anim_cb:
ldr r1, =0x080726C5
bx r1


load_uncomp_pal_into_ram:
ldr r3, =0x08070351
bx r3

pal_get_id_by_tag:
ldr r1, =0x08008969
bx r1
