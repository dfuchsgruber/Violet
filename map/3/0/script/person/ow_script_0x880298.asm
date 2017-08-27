.include "overworld_script.s"

.include "std.s"

.global ow_script_0x880298
ow_script_0x880298:
buffernumber 0x0 0x5000
loadpointer 0x0 str_0x8acc27
callstd MSG
setvar 0x5100 0x1
end
