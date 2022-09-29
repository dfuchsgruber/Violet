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

.org 0x08071b28
	ldr r1, = fanfare_by_fanfare_idx | 1
	bx r1
	.pool

.org 0x08071bac
	ldr r1, = fanfare_stop_by_fanfare_idx | 1
	bx r1
	.pool

.org 0x08071bc4
	ldr r1, = fanfare | 1
	bx r1
	.pool
    
