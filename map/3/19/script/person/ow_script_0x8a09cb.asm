.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8a09cb
ow_script_0x8a09cb:
trainerbattlestd 0x0 0x3 0x0 str_0x8a09e3 str_0x8a0a35
loadpointer 0x0 str_0x8a0a35
callstd MSG_FACE
end
