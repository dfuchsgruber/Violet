.include "std.s"

.global lscr_0x81a5d6

lscr_0x81a5d6:
	.byte 0x2
.word lscr_0x8f4fcd
	.byte 0x0


.align 4
.global lscr_0x8f4fcd

lscr_0x8f4fcd:
	.hword STORY_PROGRESS, 0x12
	.word ow_script_0x8cad90
	.hword 0x0
