
.global lscr_0x726f30

lscr_0x726f30:
	.byte 0x3
.word ow_script_wm_orina_city
	.byte 0x0


.include "overworld_script.s"
.include "flags.s"



ow_script_wm_orina_city:
setworldmapflag WM_ORINA_CITY
end