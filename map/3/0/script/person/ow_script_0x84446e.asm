.include "overworld_script.s"

.include "std.s"

.global ow_script_0x84446e
ow_script_0x84446e:
loadpointer 0x0 str_0x416097
callstd MSG
setvar 0x8006 0x1
end
