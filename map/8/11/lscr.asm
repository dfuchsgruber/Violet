.include "vars.s"

.global lscr_0x7194d8

lscr_0x7194d8:
	.byte 0x2
.word lscr_0x719852
	.byte 0x0


.align 4
.global lscr_0x719852

lscr_0x719852:
	.hword STORY_PROGRESS, 0x21
	.word ow_script_0x8c82da
	.hword 0x0
