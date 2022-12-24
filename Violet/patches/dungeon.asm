//dynamic maps
.org 0x08055258
	ldr r2, =get_mapheader | 1
	bx r2
	.pool

	
.org 0x08055190
	ldr r0, =get_mapfooter | 1
	bx r0
	.pool
	
.org 0x08058a20
	ldr r1, =map_initialize_blocks | 1
	bx r1
	.pool
