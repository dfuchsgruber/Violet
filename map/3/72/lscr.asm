.include "vars.s"

.global lscr_0x719018

lscr_0x719018:
	.byte 0x2
.word lscr_0x71a186
	.byte 0x0


.align 4
.global lscr_0x71a186

lscr_0x71a186:
	.hword STORY_PROGRESS, 0x5
	.word ow_script_0x89c150
	.hword 0x0
