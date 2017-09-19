.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8974dd
ow_script_0x8974dd:
trainerbattlestd 0x0 0x1b 0x0 str_0x8998d3 str_0x899949
loadpointer 0x0 str_0x899949
callstd MSG_FACE
end
