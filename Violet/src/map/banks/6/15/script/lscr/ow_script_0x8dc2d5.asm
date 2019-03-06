.include "flags.s"
.include "ordinals.s"
.include "overworld_script.s"


.global ow_script_0x8dc2d5
ow_script_0x8dc2d5:
checkflag AKTANIA_GEODUDE_FOUGHT
gotoif EQUAL ow_script_0x8dc443
end


.global ow_script_0x8dc443
ow_script_0x8dc443:
setmaptile 0x7 0x7 0x2fc 0x0
end
