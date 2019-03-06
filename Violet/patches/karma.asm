
.org 0x08021b60
	ldr r2, =hook_exp | 1
	bx r2
	.pool

.org 0x0809a9f0
	ldr r1, =hook_item_prices | 1
	bx r1
	.pool