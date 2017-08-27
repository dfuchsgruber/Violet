.include "overworld_script.s"

.include "std.s"

.global ow_script_0x80067e
ow_script_0x80067e:
loadpointer 0x0 str_0x800688
callstd MSG_SIGN
end
