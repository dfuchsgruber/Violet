.align 2
.thumb

.global hook_main_initialize


.thumb_func
hook_main_initialize:

bl fmem_init

@//return to the rom boot
ldr r0, =0x03003034
strb r4, [r0]
ldr r7, =0x03003040
mov r1, #0
ldr r2, =0x08000421
bx r2
