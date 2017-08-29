.include "overworld_script.s"

.include "std.s"

.global ow_script_0x834f46
ow_script_0x834f46:
checkflag FRBADGE_3
gotoif EQUAL ow_script_0x834fb5
end


.global ow_script_0x834fb5
ow_script_0x834fb5:
setvar 0x4046 0x1
setflag 0x260
return
