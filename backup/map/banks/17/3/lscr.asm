.include "vars.s"

.global lscr_0x71df84

lscr_0x71df84:
	.byte 0x4
.word lscr_0x71df07
	.byte 0x2
.word lscr_0x71df8f
	.byte 0x0


.align 4
.global lscr_0x71df07

lscr_0x71df07:
	.hword MERIANA_ARENA_TRIGGER, 0x0
	.word ow_script_0x814a4c
	.hword 0x0


.align 4
.global lscr_0x71df8f

lscr_0x71df8f:
	.hword STORY_PROGRESS, 0x29
	.word ow_script_0x94c408
	.hword 0x0
