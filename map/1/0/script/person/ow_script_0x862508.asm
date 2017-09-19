.include "overworld_script.s"

.include "std.s"

.global ow_script_0x862508
ow_script_0x862508:
trainerbattlestd 0x0 0x43 0x0 str_0x8ef778 str_0x8ef878
loadpointer 0x0 str_0x8ef878
callstd MSG_FACE
end
