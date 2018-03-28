.include "vars.s"

.global lscr_0x8f5100

lscr_0x8f5100:
	.byte 0x3
.word ow_script_0x8112fd
	.byte 0x2
.word lscr_0x719b77
	.byte 0x0




.align 4
.global lscr_0x719b77

lscr_0x719b77:
	.hword STORY_PROGRESS, 0x14
	.word ow_script_0x8d3195
	.hword 0x0
