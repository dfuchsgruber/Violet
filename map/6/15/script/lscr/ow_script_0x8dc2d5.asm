.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8dc2d5
ow_script_0x8dc2d5:
checkflag 0x1e3
gotoif EQUAL ow_script_0x8dc443
end


.global ow_script_0x8dc443
ow_script_0x8dc443:
setmaptile 0x7 0x7 0x2fc 0x0
end
