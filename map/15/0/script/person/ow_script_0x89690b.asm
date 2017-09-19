.include "overworld_script.s"

.include "std.s"

.global ow_script_0x89690b
ow_script_0x89690b:
trainerbattlestd 0x0 0x1a 0x0 str_0x89837f str_0x89989f
loadpointer 0x0 str_0x89989f
callstd MSG_FACE
end
