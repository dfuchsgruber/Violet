.include "overworld_script.s"

.include "std.s"

.global ow_script_0x958d68
ow_script_0x958d68:
checkflag ORINA_CITY_MISTRALS_GRUNTS
gotoif EQUAL ow_script_0x958a9b
special2 0x800d 0x1aa
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x958ca6
showmoney 0x0 0x0 0x0
loadpointer 0x0 str_0x958c0b
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x958bfa
checkmoney 0x96 0x0
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x958ba3
closeonkeypress
sound 0x41
paymoney 0x96 0x0
updatemoney 0x0 0x0 0x0
checksound
loadpointer 0x0 str_0x958b7e
callstd MSG_KEEPOPEN
hidemoney 0x0 0x0
goto ow_script_0x958d28


.global ow_script_movs_0x958d35
ow_script_movs_0x958d35:
.byte STEP_UP
.byte STOP


.global ow_script_0x958d28
ow_script_0x958d28:
closeonkeypress
applymovement 0xff ow_script_movs_0x958d35
waitmovement 0x0
end


.global ow_script_0x958ba3
ow_script_0x958ba3:
hidemoney 0x0 0x0
loadpointer 0x0 str_0x958bb4
callstd MSG_KEEPOPEN
goto ow_script_0x958d18


.global ow_script_movs_0x958d25
ow_script_movs_0x958d25:
.byte STEP_DOWN
.byte STOP


.global ow_script_0x958d18
ow_script_0x958d18:
closeonkeypress
applymovement 0xff ow_script_movs_0x958d25
waitmovement 0x0
end


.global ow_script_0x958bfa
ow_script_0x958bfa:
hidemoney 0x0 0x0
loadpointer 0x0 str_0x958cc7
callstd MSG_KEEPOPEN
goto ow_script_0x958d18


.global ow_script_0x958ca6
ow_script_0x958ca6:
loadpointer 0x0 str_0x958d38
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x958d28
loadpointer 0x0 str_0x958cc7
callstd MSG_KEEPOPEN
goto ow_script_0x958d18


.global ow_script_0x958a9b
ow_script_0x958a9b:
special2 0x800d 0x1aa
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x958b36
loadpointer 0x0 str_0x958ab9
callstd MSG_KEEPOPEN
goto ow_script_0x958d28


.global ow_script_0x958b36
ow_script_0x958b36:
loadpointer 0x0 str_0x958b44
callstd MSG_KEEPOPEN
goto ow_script_0x958d18
