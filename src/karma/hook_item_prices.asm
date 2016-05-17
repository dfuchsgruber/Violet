.align 2
.thumb

.global hook_item_prices

.thumb_func

hook_item_prices:
lsl r0, #0x10
lsr r0, #0x10	@typecasting for u16
mov r1, #0x2C
mul r0, r1
add r4, r0
ldrh r0, [r4, #0x10]	@price is loaded
bl modify_item_prices
pop {r4}
pop {r1}
bx r1
