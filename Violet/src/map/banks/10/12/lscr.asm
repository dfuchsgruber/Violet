
.global lscr_0x16c558

lscr_0x16c558:
	.byte 0x3
.word ow_script_0x16c563
	.byte 0x5
.word ow_script_0x1bf89b
	.byte 0x0




.include "overworld_script.s"
.include "healingplaces.s"

.global ow_script_0x16c563
ow_script_0x16c563:
sethealingplace HEALINGPLACE_INFERIOR
end