.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8fb58c
ow_script_0x8fb58c:
trainerbattlestd 0x0 0x54 0x0 str_0x8fe86e str_0x8feac9
loadpointer 0x0 str_0x8feac9
callstd MSG_FACE
end
