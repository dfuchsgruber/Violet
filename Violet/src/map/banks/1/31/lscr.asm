
.global lscr_0x160e15

lscr_0x160e15:
	.byte 0x3
.word ow_script_0x160e1b
	.byte 0x0


.include "overworld_script.s"
.include "flags.s"

.global ow_script_0x160e1b

ow_script_0x160e1b:
setworldmapflag WM_ASCHHAIN
end