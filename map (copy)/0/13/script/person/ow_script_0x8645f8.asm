.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8645f8
ow_script_0x8645f8:
setvar 0x8004 0x5
special 0x19
waitstate
end
