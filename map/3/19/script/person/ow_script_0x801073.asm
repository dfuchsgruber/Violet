.include "overworld_script.s"

.include "std.s"

.global ow_script_0x801073
ow_script_0x801073:
lock
faceplayer
loadpointer 0x0 str_0x804215
callstd MSG
release
end
