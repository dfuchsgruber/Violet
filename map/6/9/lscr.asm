.include "vars.s"

.global lscr_0x8f511d

lscr_0x8f511d:
	.byte 0x4
.word lscr_0x8f5134
	.byte 0x2
.word lscr_0x8f5129
	.byte 0x0


.align 4
.global lscr_0x8f5134

lscr_0x8f5134:
	.hword STORY_PROGRESS, 0x13
	.word ow_script_0x8f5b84
	.hword 0x0


.align 4
.global lscr_0x8f5129

lscr_0x8f5129:
	.hword STORY_PROGRESS, 0x13
	.word ow_script_0x89472b
	.hword 0x0
