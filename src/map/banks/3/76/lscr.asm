.include "vars.s"

.global lscr_0x71dfbc

lscr_0x71dfbc:
	.byte 0x4
.word lscr_0x71dfb2
	.byte 0x0


.align 4
.global lscr_0x71dfb2

lscr_0x71dfb2:
	.hword MERIANA_ARENA_TRIGGER, 0x0
	.word ow_script_0x80ed2e
	.hword 0x0
