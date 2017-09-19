.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8e6b58
ow_script_0x8e6b58:
trainerbattlestd 0x0 0x45 0x0 str_0x8efa78 str_0x8efb78
loadpointer 0x0 str_0x8efb78
callstd MSG_FACE
end
