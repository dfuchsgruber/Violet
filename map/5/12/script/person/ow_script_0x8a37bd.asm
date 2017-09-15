.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8a37bd
ow_script_0x8a37bd:
lock
faceplayer
loadpointer 0x0 str_0x8a4832
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8a3829
loadpointer 0x0 str_0x8a4537
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8a3829
loadpointer 0x0 str_0x8a382c
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8a3829
loadpointer 0x0 str_0x8a3f1e
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8a3829
loadpointer 0x0 str_0x8a4108
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8a3829
loadpointer 0x0 str_0x8a4349
callstd MSG_FACE
release
end


.global ow_script_0x8a3829
ow_script_0x8a3829:
release
end
