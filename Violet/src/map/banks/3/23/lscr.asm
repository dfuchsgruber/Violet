.include "vars.s"

.global lscr_0x71df9c

lscr_0x71df9c:
	.byte 0x2
.word lscr_0x71dfa2
	.byte 0x0


.align 4
.global lscr_0x71dfa2

lscr_0x71dfa2:
	.hword STORY_PROGRESS, 0x2a
	.word ow_script_0x949d92
	.hword 0x0
