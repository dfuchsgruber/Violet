
// tm hack
.org 0x08132752
	mov r0, #1
	.pool
	
.org 0x0809BD20
	ldr r1, =tm_sale | 1
	bx r1
	.pool
	
.org 0x0809BE44
	ldr r0, =tm_count_arrows | 1
	bx r0
	.pool
	