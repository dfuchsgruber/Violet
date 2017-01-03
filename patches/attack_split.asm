//attack split
.org 0x0803EE04
	ldr r1, = physical_special_item_load| 1
	bx r1
	.pool