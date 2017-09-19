.include "std.s"

.global lscr_0x84020c

lscr_0x84020c:
	.byte 0x2
.word lscr_0x840218
	.byte 0x4
.word lscr_0x84e9b8
	.byte 0x0


.align 4
.global lscr_0x840218

lscr_0x840218:
	.hword STORY_PROGRESS, 0x36
	.word ow_script_0x94772b
	.hword 0x0


.align 4
.global lscr_0x84e9b8

lscr_0x84e9b8:
	.hword STORY_PROGRESS, 0x36
	.word ow_script_0x812c75
	.hword 0x0
