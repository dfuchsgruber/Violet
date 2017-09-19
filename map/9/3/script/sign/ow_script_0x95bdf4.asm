.include "overworld_script.s"

.include "std.s"

.global ow_script_0x95bdf4
ow_script_0x95bdf4:
checkflag ORINA_CITY_BANK_MEMBER
gotoif EQUAL ow_script_0x95b72c
loadpointer 0x0 str_0x95bcb7
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x95bc3d
loadpointer 0x0 str_0x95bc47
callstd MSG
pause 0x28
fanfare 0x13e
loadpointer 0x0 str_0x95bc02
callstd MSG_KEEPOPEN
waitfanfare
loadpointer 0x0 str_0x95bb96
callstd MSG_KEEPOPEN
setflag ORINA_CITY_BANK_MEMBER
goto ow_script_0x95b72c


.global ow_script_0x95b72c
ow_script_0x95b72c:
loadpointer 0x0 str_0x95b769
callstd MSG_KEEPOPEN
setvar DYN_MULTICHOICE_ITEM_CNT 0x3
loadpointer 0x0 str_0x95b8e2
multichoice 0x0 0x0 0x0 0x0
setvar DYN_MULTICHOICE_ITEM_CNT 0x0
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x95b911
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x95b7ec
loadpointer 0x0 str_0x95b7b9
callstd MSG
end


.global ow_script_0x95b7ec
ow_script_0x95b7ec:
loadpointer 0x0 str_0x95b7fa
callstd MSG_KEEPOPEN
goto ow_script_0x95b911


.global ow_script_0x95b911
ow_script_0x95b911:
buffernumber 0x0 0x50d4
loadpointer 0x0 str_0x95bb6b
callstd MSG_KEEPOPEN
setvar DYN_MULTICHOICE_ITEM_CNT 0x2
loadpointer 0x0 str_0x95bb4f
multichoice 0x0 0x0 0x0 0x0
setvar DYN_MULTICHOICE_ITEM_CNT 0x0
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x95b947
loadpointer 0x0 str_0x95b7b9
callstd MSG
end


.global ow_script_0x95b947
ow_script_0x95b947:
loadpointer 0x0 str_0x95bb13
callstd MSG_KEEPOPEN
setvar DYN_MULTICHOICE_ITEM_CNT 0x4
loadpointer 0x0 str_0x95badc
multichoice 0x0 0x0 0x0 0x0
setvar DYN_MULTICHOICE_ITEM_CNT 0x0
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x95b98b
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x95b9b0
compare LASTRESULT 0x2
gotoif EQUAL ow_script_0x95b9d5
goto ow_script_0x95b911


.global ow_script_0x95b9d5
ow_script_0x95b9d5:
compare BANK_CREDIT 0x0
gotoif HIGHER ow_script_0x95ba8d
showmoney 0x0 0x0 0x0
setvar 0x8004 0xc350
addvar BANK_CREDIT 0xea60
givemoney 0xc350 0x0
goto ow_script_0x95b9fa


.global ow_script_0x95b9fa
ow_script_0x95b9fa:
buffernumber 0x1 0x8004
loadpointer 0x0 str_0x95ba20
callstd MSG_KEEPOPEN
sound 0x41
updatemoney 0x0 0x0 0x0
checksound
buffernumber 0x0 0x50d4
loadpointer 0x0 str_0x95ba63
callstd MSG_KEEPOPEN
goto ow_script_0x95b911


.global ow_script_0x95ba8d
ow_script_0x95ba8d:
loadpointer 0x0 str_0x95ba9b
callstd MSG_KEEPOPEN
goto ow_script_0x95b947


.global ow_script_0x95b9b0
ow_script_0x95b9b0:
compare BANK_CREDIT 0xbb80
gotoif HIGHER ow_script_0x95ba8d
showmoney 0x0 0x0 0x0
setvar 0x8004 0x2710
addvar BANK_CREDIT 0x2ee0
givemoney 0x2710 0x0
goto ow_script_0x95b9fa


.global ow_script_0x95b98b
ow_script_0x95b98b:
compare BANK_CREDIT 0xe5b0
gotoif HIGHER ow_script_0x95ba8d
showmoney 0x0 0x0 0x0
setvar 0x8004 0x3e8
addvar BANK_CREDIT 0x4b0
givemoney 0x3e8 0x0
goto ow_script_0x95b9fa


.global ow_script_0x95bc3d
ow_script_0x95bc3d:
loadpointer 0x0 str_0x95bd3c
callstd MSG
end
