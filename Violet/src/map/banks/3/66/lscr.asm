
.include "overworld_script.s"
.include "vars.s"
.include "flags.s"
.include "ordinals.s"
.include "levelscript_types.s"

.global lscr_0x718dc8

lscr_0x718dc8:
	.byte 0x2
	.word lscr_0x71a5df
	.byte 0x0


.align 4
.global lscr_0x71a5df

lscr_0x71a5df:
	.hword STORY_PROGRESS, 0xe
	.word ow_script_0x8a7586
	.hword 0x0
