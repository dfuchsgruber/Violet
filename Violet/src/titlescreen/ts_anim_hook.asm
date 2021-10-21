.global ts_anim_hook
.global ts_cry_hook

.align 2
.thumb

.thumb_func
ts_anim_hook:
    mov r0, r5
    bl ts_animation_step
    pop {r4-r5}
    pop {r0}
    bx r0

.thumb_func
ts_cry_hook:
    ldr r0, =0x19a
    mov r1, #0
    bl c_cry
    ldrb r0, [r4, #0xC]
    ldr r1, =0x807915C | 1
    bx r1

c_cry:
    ldr r2, =0x8071D54 | 1
    bx r2
