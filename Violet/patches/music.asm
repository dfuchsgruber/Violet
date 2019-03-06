	.org 0x81e13b4
		.word song_table

	.org 0x81e13e8
		.word song_table

	.org 0x81e1434
		.word song_table

	.org 0x81e1488
		.word song_table

	.org 0x81e14bc
		.word song_table

.org 0x0812F888
	ldr r0, =hook_music_oak_intro | 1
	bx r0
	.pool
    
