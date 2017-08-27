.include "std.s"

.global lscr_0x71a500

lscr_0x71a500:
	.byte 0x4
.word lscr_0x168c29
	.byte 0x3
.word ow_script_0x84002b
	.byte 0x2
.word lscr_0x720a14
	.byte 0x0


.align 4
.global lscr_0x168c29

lscr_0x168c29:
	.hword 0x4056, 0x0
	.word ow_script_0x168c33
	.hword 0x0




.align 4
.global lscr_0x720a14

lscr_0x720a14:
	.hword STORY_PROGRESS, 0x0
	.word ow_script_0x892f40
	.hword 0x0
