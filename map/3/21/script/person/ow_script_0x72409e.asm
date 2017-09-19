.include "overworld_script.s"

.include "std.s"

.global ow_script_0x72409e
ow_script_0x72409e:
trainerbattlestd 0x0 0x66 0x0 str_0x72458c str_0x7245ea
loadpointer 0x0 str_0x7245ea
callstd MSG_FACE
end
