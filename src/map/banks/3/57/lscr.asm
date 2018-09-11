.include "vars.s"

.global lscr_0x719224

lscr_0x719224:
	.byte 0x4
	.word lscr_movesprites
	.byte 0x0



.align 4

lscr_movesprites:
	.hword STORY_PROGRESS, 7
	.word ow_script_trainerschool_movesprites
	.hword 0x0
