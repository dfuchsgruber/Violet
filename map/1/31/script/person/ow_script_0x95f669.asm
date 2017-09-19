.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95f669
ow_script_0x95f669:
trainerbattlestd 0x0 0x9a 0x0 str_0x95f681 str_0x95f6f4
loadpointer 0x0 str_0x95f6f4
callstd MSG_FACE
end
