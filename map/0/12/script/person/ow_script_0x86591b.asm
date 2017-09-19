.include "overworld_script.s"

.include "std.s"

.global ow_script_0x86591b
ow_script_0x86591b:
setvar 0x8004 0xa
special 0x19
waitstate
end
