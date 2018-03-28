.include "vars.s"

.global lscr_0x719224

lscr_0x719224:
	.byte 0x2
.word lscr_0x71922a
	.byte 0x0


.align 4
.global lscr_0x71922a

lscr_0x71922a:
	.hword STORY_PROGRESS, 0x7
	.word ow_script_0x89d8c1
	.hword 0x0
