
.global lscr_0x718de8

lscr_0x718de8:
	.byte 0x1
.word ow_script_0x88b2c5
	.byte 0x3
.word ow_script_0x811515
	.byte 0x0




.include "overworld_script.s"
.include "ordinals.s"
.include "flags.s"

.global ow_script_0x88b2c5
.global ow_script_0x811515
.global ow_script_0x8f6fce

ow_script_0x811515:
setworldmapflag WM_AKTANIA
end


ow_script_0x88b2c5:
end