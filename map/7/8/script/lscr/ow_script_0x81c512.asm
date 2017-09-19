.include "overworld_script.s"

.include "std.s"

.global ow_script_0x81c512
ow_script_0x81c512:
checkflag SILVANIA_FOREST_FLASHBACK_DONE
gotoif EQUAL ow_script_0x81c51d
end


.global ow_script_0x81c51d
ow_script_0x81c51d:
spriteface 0xff 0x2
spriteface 0x1 0x0
spriteface 0x2 0x0
end
