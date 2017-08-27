.include "overworld_script.s"

.include "std.s"

.global ow_script_0x87acde
ow_script_0x87acde:
loadpointer 0x0 str_0x87f589
callstd MSG
setflag 0x901
end
