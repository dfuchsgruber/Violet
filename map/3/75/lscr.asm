.include "std.s"

.global lscr_0x726a18

lscr_0x726a18:
	.byte 0x4
.word lscr_0x726a1e
	.byte 0x0


.align 4
.global lscr_0x726a1e

lscr_0x726a1e:
	.hword MERIANA_ARENA_TRIGGER, 0x0
	.word ow_script_0x94566b
	.hword 0x0
