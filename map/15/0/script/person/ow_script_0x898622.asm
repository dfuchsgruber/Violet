.include "overworld_script.s"

.include "std.s"

.global ow_script_0x898622
ow_script_0x898622:
trainerbattlestd 0x0 0x24 0x0 str_0x899a49 str_0x899ac7
loadpointer 0x0 str_0x899ac7
callstd MSG_FACE
end
