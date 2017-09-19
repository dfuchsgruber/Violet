.include "overworld_script.s"

.include "std.s"

.global ow_script_0x914bf0
ow_script_0x914bf0:
trainerbattlestd 0x0 0x70 0x0 str_0x92d16d str_0x92dd6f
loadpointer 0x0 str_0x92dd6f
callstd MSG_FACE
end
