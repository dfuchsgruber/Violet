.include "overworld_script.s"

.include "std.s"

.global ow_script_0x81fcc0
ow_script_0x81fcc0:
trainerbattlestd 0x0 0x65 0x0 str_0x90ff68 str_0x91ff1b
loadpointer 0x0 str_0x91ff1b
callstd MSG_FACE
end
