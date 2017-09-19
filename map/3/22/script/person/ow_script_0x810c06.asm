.include "overworld_script.s"

.include "std.s"

.global ow_script_0x810c06
ow_script_0x810c06:
trainerbattlestd 0x0 0x74 0x0 str_0x935b6f str_0x932010
loadpointer 0x0 str_0x932010
callstd MSG_FACE
end
