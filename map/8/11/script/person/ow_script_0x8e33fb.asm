.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8e33fb
ow_script_0x8e33fb:
trainerbattlestd 0x0 0x72 0x0 str_0x931a72 str_0x92df3b
loadpointer 0x0 str_0x92df3b
callstd MSG_FACE
end
