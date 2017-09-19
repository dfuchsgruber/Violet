.include "overworld_script.s"

.include "std.s"

.global ow_script_0x818b83
ow_script_0x818b83:
trainerbattlestd 0x0 0x18 0x0 str_0x818b9b str_0x818bd9
loadpointer 0x0 str_0x818bd9
callstd MSG_FACE
end
