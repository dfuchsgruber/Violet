.include "std.s"

.global lscr_0x71df44

lscr_0x71df44:
	.byte 0x4
.word lscr_0x71deee
	.byte 0x0


.align 4
.global lscr_0x71deee

lscr_0x71deee:
	.hword MERIANA_ARENA_TRIGGER, 0x0
	.word ow_script_0x80ed2e
	.hword 0x0
