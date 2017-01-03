.align 2
.thumb

.global hook_price_money

.thumb_func

hook_price_money:
mov r0, r4
bl modify_price_money
mov r4, r0

@return point
mov r1, r8
ldr r0, [r1]
mov r1, #0x29
lsl r1, #0x4
ldr r2, =0x08025975
bx r2
