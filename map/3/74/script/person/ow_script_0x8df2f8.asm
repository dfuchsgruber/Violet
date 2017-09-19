.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8df2f8
ow_script_0x8df2f8:
trainerbattlestd 0x0 0x2e 0x0 str_0x8e1843 str_0x8e18b9
loadpointer 0x0 str_0x8e18b9
callstd MSG_FACE
end
