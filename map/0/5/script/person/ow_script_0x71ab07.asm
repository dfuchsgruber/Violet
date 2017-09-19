.include "overworld_script.s"

.include "std.s"

.global ow_script_0x71ab07
ow_script_0x71ab07:
trainerbattlestd 0x0 0x4f 0x0 str_0x71ab1f str_0x8fb233
loadpointer 0x0 str_0x71ab61
callstd MSG_FACE
end
