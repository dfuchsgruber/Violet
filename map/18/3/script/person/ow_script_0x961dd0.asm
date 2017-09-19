.include "overworld_script.s"

.include "std.s"

.global ow_script_0x961dd0
ow_script_0x961dd0:
trainerbattlestd 0x0 0xa2 0x0 str_0x96364e str_0x96368c
loadpointer 0x0 str_0x96368c
callstd MSG_FACE
end
