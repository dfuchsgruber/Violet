.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8fb42c
ow_script_0x8fb42c:
trainerbattlestd 0x0 0x6e 0x0 str_0x9281cc str_0x928233
loadpointer 0x0 str_0x928233
callstd MSG_FACE
end
