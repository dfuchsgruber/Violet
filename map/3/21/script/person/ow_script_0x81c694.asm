.include "overworld_script.s"

.include "std.s"

.global ow_script_0x81c694
ow_script_0x81c694:
trainerbattlestd 0x0 0x67 0x0 str_0x81fb0d str_0x81fb69
loadpointer 0x0 str_0x81fb69
callstd MSG_FACE
end
