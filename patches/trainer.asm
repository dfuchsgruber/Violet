//trainer
.org 0x0803D9B8
	ldr r0, =hook_build_trainer_poke | 1
	bx r0
	.pool

.org 0x0802596C
	ldr r0, =hook_price_money | 1
	bx r0
	.pool
	
	
.org 0x080C6F38
	ldr r0, =hook_trainer_items | 1
	bx r0
	.pool
