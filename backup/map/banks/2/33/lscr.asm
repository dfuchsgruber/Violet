.include "vars.s"
.include "map_connections.s"


.global lscr_0x71cbcc

lscr_0x71cbcc:
	.byte 0x2
.word lscr_0x7193ce
	.byte 0x4
.word lscr_0x71cb9f
	.byte 0x0


.align 4
.global lscr_0x7193ce

lscr_0x7193ce:
	.hword STORY_PROGRESS, 0x35
	.word ow_script_0x9730ba
	.hword 0x0


.align 4
.global lscr_0x71cb9f

lscr_0x71cb9f:
	.hword STORY_PROGRESS, 0x35
	.word ow_script_0x811aa5
	.hword 0xffff
