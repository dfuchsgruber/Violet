.include "overworld_script.s"

.include "std.s"

.global ow_script_0x948f71
ow_script_0x948f71:
trainerbattlestd 0x0 0x8b 0x0 str_0x94c37e str_0x949d71
loadpointer 0x0 str_0x949d71
callstd MSG_FACE
end
