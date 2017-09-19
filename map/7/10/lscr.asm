.include "std.s"

.global lscr_0x726eac

lscr_0x726eac:
	.byte 0x2
.word lscr_0x71fe1a
	.byte 0x4
.word lscr_0x71fe2f
	.byte 0x0


.align 4
.global lscr_0x71fe1a

lscr_0x71fe1a:
	.hword MERIANA_ARENA_TRIGGER, 0x0
	.word ow_script_0x83103c
	.hword 0x0


.align 4
.global lscr_0x71fe2f

lscr_0x71fe2f:
	.hword MERIANA_ARENA_TRIGGER, 0x0
	.word ow_script_0x801080
	.hword 0xffff
