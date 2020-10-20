
.global lscr_0x726f28

lscr_0x726f28:
	.byte 0x3
.word ow_script_0x84c062
	.byte 0x0


.include "overworld_script.s"
.include "flags.s"

.global ow_script_0x84c062

ow_script_0x84c062:
setworldmapflag WM_KASKADA
end