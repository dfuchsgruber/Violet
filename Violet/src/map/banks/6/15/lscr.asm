
.global lscr_0x71bffc

lscr_0x71bffc:
	.byte 0x1
.word ow_script_0x8dc2d5
	.byte 0x0


.include "ordinals.s"
.include "overworld_script.s"
.include "flags.s"

.global ow_script_0x8dc443
.global ow_script_0x8dc2d5

ow_script_0x8dc2d5:
checkflag AKTANIA_GEODUDE_FOUGHT
gotoif EQUAL ow_script_0x8dc443
end


ow_script_0x8dc443:
setmaptile 0x7 0x7 0x2fc 0x0
end