.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8e2b15
ow_script_0x8e2b15:
trainerbattlestd 0x0 0x32 0x0 str_0x8e2b2d str_0x8e2ba1
loadpointer 0x0 str_0x8e2ba1
callstd MSG_FACE
end
