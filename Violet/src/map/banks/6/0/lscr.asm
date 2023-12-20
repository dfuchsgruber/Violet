.include "flags.s"
.include "levelscript_types.s"
.include "overworld_script.s"

.global lscr_0x16a286

lscr_0x16a286:
	.byte LEVELSCRIPT_TYPE_ON_TRANSITION
	.word on_transition
	.byte 0x0

on_transition:
	setflag FLAG_LESTERS_HOUSE
	end
