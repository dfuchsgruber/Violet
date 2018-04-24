.include "vars.s"

.global lscr_0x89f109

lscr_0x89f109:
	.byte 0x4
.word lscr_0x8f46eb
	.byte 0x2
.word lscr_0x8f4e6f
	.byte 0x0


.align 4
.global lscr_0x8f46eb

lscr_0x8f46eb:
	.hword AKTANIA_FLASHBACK_LSCR_PLAYER_INVISIBLE, 0x0
	.word ow_script_0x814a4c
	.hword 0x0


.align 4
.global lscr_0x8f4e6f

lscr_0x8f4e6f:
	.hword STORY_PROGRESS, 0x15
	.word ow_script_0x8d7960
	.hword 0x0
