.include "std.s"

.global lscr_0x719248

lscr_0x719248:
	.byte 0x2
.word lscr_0x719056
	.byte 0x3
.word ow_script_0x83ff26
	.byte 0x0


.align 4
.global lscr_0x719056

lscr_0x719056:
	.hword STORY_PROGRESS, 0x1
	.word ow_script_0x89bb77
	.hword 0x0


