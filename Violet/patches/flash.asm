//misc
.org 0x080C9D84
	.word ow_script_flash
	.pool
	
//flash radius in caves will be kept
.org 0x08055CFC
	pop {r0}
	bx r0 
	.pool