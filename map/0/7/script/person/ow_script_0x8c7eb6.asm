.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8c7eb6
ow_script_0x8c7eb6:
trainerbattlestd 0x0 0x6b 0x0 str_0x8c7ece str_0x8c7efc
loadpointer 0x0 str_0x8c7efc
callstd MSG_FACE
end
