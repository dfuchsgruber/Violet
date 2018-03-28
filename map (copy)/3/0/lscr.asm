.include "std.s"

.global lscr_0x71a510

lscr_0x71a510:
	.byte 0x3
.word ow_script_0x8012d1
	.byte 0x2
.word lscr_0x71a51b
	.byte 0x0




.align 4
.global lscr_0x71a51b

lscr_0x71a51b:
	.hword STORY_PROGRESS, 0x2
	.word ow_script_0x85e7c8
	.hword 0x0
