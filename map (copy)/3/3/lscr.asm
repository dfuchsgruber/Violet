.include "std.s"

.global lscr_0x719378

lscr_0x719378:
	.byte 0x3
.word ow_script_0x84c480
	.byte 0x2
.word lscr_0x719cab
	.byte 0x1
.word ow_script_0x81c52a
	.byte 0x0




.align 4
.global lscr_0x719cab

lscr_0x719cab:
	.hword STORY_PROGRESS, 0x17
	.word ow_script_0x81c55e
	.hword 0x0


