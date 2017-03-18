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

NUM_CHAN equ 12

.org 0x081e1361
        .byte 0xC0 + NUM_CHAN


    