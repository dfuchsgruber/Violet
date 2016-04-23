.align 2
.thumb

.global rom_boot_clear_map_generated.asm


.thumb_func
rom_boot_clear_map_generated:

ldr r0, =0x0203CEC4
ldrb r1, [r0]
lsr r1, #1
lsl r1, #1
strb r1, [r0]	@no map was generated so far

@//return to the rom boot
ldr r0, =0x03003034
strb r4, [r0]
ldr r7, =0x03003040
mov r1, #0
ldr r2, =0x08000421
bx r2

