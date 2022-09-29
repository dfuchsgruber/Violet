//attack split
.org 0x0803EE04
	ldr r1, = physical_special_item_load | 1
	bx r1
	.pool

.org 0x081375E0
        ldr r0, =load_split_chart3 | 1
        bx r0
        .pool

