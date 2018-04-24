.include "vars.s"

.global lscr_0x81c4d9

lscr_0x81c4d9:
	.byte 0x4
.word lscr_0x83074b
	.byte 0x2
.word lscr_0x81c541
	.byte 0x0


.align 4
.global lscr_0x83074b

lscr_0x83074b:
	.hword STORY_PROGRESS, 0x1a
	.word ow_script_0x81c512
	.hword 0x0


.align 4
.global lscr_0x81c541

lscr_0x81c541:
	.hword STORY_PROGRESS, 0x1a
	.word ow_script_0x81c406
	.hword 0x0
