//tile
.org 0x0806d684
	ldr r0, =tile_step | 1
	bx r0
	.pool

.org 0x806D154
	ldr r0, =hook_get_behavior_script | 1
	bx r0
	.pool

.org 0x08059AE4
	ldr r0, =hook_tile_init | 1
	bx r0
	.pool
	