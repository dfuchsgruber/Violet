.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8000a5
ow_script_0x8000a5:
lock
faceplayer
loadpointer 0x0 str_0x8000b2
callstd MSG
release
end
