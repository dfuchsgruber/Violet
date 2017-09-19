.include "std.s"

.global lscr_0x71d854

lscr_0x71d854:
	.byte 0x2
.word lscr_0x71d836
	.byte 0x0


.align 4
.global lscr_0x71d836

lscr_0x71d836:
	.hword 0x32, 0x4051
	.word ow_script_0x858dec
	.hword 0x0
