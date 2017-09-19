.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8c8f85
ow_script_0x8c8f85:
lock
faceplayer
loadpointer 0x0 str_0x8f18a8
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8f185a
loadpointer 0x0 str_0x8f1821
callstd MSG
release
end


.global ow_script_0x8f185a
ow_script_0x8f185a:
loadpointer 0x0 str_0x8f1865
callstd MSG
release
end
