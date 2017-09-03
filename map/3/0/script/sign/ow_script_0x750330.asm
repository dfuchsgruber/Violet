.include "overworld_script.s"

.include "std.s"

.global ow_script_0x750330
ow_script_0x750330:
checkflag 0x21c
gotoif LESS ow_script_0x772eb2
checkflag 0x21d
gotoif EQUAL ow_script_0x75176f
fanfare 0x13e
loadpointer 0x0 str_0x7503dd
callstd MSG
waitfanfare
setflag 0x21d
end


.global ow_script_0x75176f
ow_script_0x75176f:
loadpointer 0x0 str_0x772e4a
callstd MSG
end


.global ow_script_0x772eb2
ow_script_0x772eb2:
loadpointer 0x0 str_0x772ebc
callstd MSG
end
