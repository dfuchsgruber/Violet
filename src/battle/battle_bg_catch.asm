.global battle_bg_catch

.align 4
.thumb

.thumb_func
battle_bg_catch:
    mov r0, #0x19	@catch bg
    ldr r1, =0x0203c5c6
    strb r0, [r1]
    ldr r0, =0x802DA60 | 1
    bx r0
