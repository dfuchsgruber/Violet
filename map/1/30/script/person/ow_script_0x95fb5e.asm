.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95fb5e
ow_script_0x95fb5e:
trainerbattlestd 0x0 0x9c 0x0 str_0x95ff17 str_0x95ff6e
loadpointer 0x0 str_0x95ff6e
callstd MSG_FACE
end
