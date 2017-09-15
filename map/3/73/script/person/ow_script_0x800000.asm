.include "overworld_script.s"

.include "std.s"

.global ow_script_0x800000
ow_script_0x800000:
lock
faceplayer
loadpointer 0x0 str_0x8b4962
callstd MSG
release
end
