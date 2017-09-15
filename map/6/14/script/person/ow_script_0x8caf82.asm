.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8caf82
ow_script_0x8caf82:
lock
faceplayer
loadpointer 0x0 str_0x8ceca3
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x8cafa0
goto ow_script_0x8cee08


.global ow_script_0x8cee08
ow_script_0x8cee08:
loadpointer 0x0 str_0x8ceaf8
callstd MSG_KEEPOPEN
goto ow_script_0x8cafa0


.global ow_script_0x8cafa0
ow_script_0x8cafa0:
loadpointer 0x0 str_0x8ced19
callstd MSG_FACE
end
