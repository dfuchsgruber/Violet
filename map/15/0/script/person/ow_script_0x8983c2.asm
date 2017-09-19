.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8983c2
ow_script_0x8983c2:
trainerbattlestd 0x0 0x22 0x0 str_0x8999f3 str_0x899a36
loadpointer 0x0 str_0x899a36
callstd MSG_FACE
end
