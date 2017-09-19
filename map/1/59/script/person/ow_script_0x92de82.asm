.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x92e99c
ow_script_movs_0x92e99c:
.byte LOOK_UP
.byte STOP


.global ow_script_0x92de82
ow_script_0x92de82:
lock
faceplayer
loadpointer 0x0 str_0x92ea1b
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x92e99f
playsong MUS_DARK_QUEEN 0x0
applymovement 0x800f ow_script_movs_0x92e99c
waitmovement 0x0
setvar 0x8004 0x1
special 0x19
waitstate
loadpointer 0x0 str_0x92e752
callstd MSG
setvar 0x8004 0x2
special 0x19
waitstate
goto ow_script_0x92eaa9


.global ow_script_0x92eaa9
ow_script_0x92eaa9:
fadesong MUS_ROUTE_24_25
compare KARMA_VALUE 0xff81
gotoif EQUAL ow_script_0x92ded4
loadpointer 0x0 str_0x92e6f1
callstd MSG_FACE
end


.global ow_script_0x92ded4
ow_script_0x92ded4:
faceplayer
loadpointer 0x0 str_0x92df22
callstd MSG
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x92def0
callstd MSG
special 0x7
release
end


.global ow_script_0x92e99f
ow_script_0x92e99f:
loadpointer 0x0 str_0x92e9aa
callstd MSG
release
end
