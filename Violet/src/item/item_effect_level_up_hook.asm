@ // Hooking here is not the cleanest approach, but by far easier than recoding the item effect routine, as its a piece of ***

.global item_effect_level_up_apply_hook
.global item_effect_level_up_unapplicable_hook

.align 4
.thumb
.thumb_func
item_effect_level_up_apply_hook:
    mov r0, r8 @ pokemon *target
    ldr r1, [sp, #8] @ u16 item
    bl item_effect_level_up_apply
    cmp r0, #0
    bne _return_apply_hook
    str r0, [sp, #0x1C] @ bool result
_return_apply_hook:
    ldr r1, =0x08041782 | 1
    bx r1

.align 4
.thumb
.thumb_func
item_effect_level_up_unapplicable_hook:
    mov r0, r8 @ pokemon *target
    ldr r1, [sp, #0] @ u16 item
    bl item_effect_level_up_unapplicable
    cmp r0, #0
    bne _return_check_hook
    str r0, [sp, #0x10] @ bool result
_return_check_hook:
    ldr r1, =0x08042656 | 1
    bx r1

