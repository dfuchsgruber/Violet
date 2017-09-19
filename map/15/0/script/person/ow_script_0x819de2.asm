.include "overworld_script.s"

.include "std.s"

.global ow_script_0x819de2
ow_script_0x819de2:
trainerbattlestd 0x0 0x36 0x0 str_0x819dfa str_0x819e42
loadpointer 0x0 str_0x819e42
callstd MSG_FACE
end
