.include "overworld_script.s"

.include "std.s"

.global ow_script_0x935dcf
ow_script_0x935dcf:
trainerbattlestd 0x0 0x7c 0x0 str_0x9382bb str_0x938319
loadpointer 0x0 str_0x938319
callstd MSG_FACE
end
