.include "overworld_script.s"

.include "std.s"

.global ow_script_0x955382
ow_script_0x955382:
loadpointer 0x0 str_0x955818
callstd MSG_KEEPOPEN
goto ow_script_0x9554da


.global ow_script_0x9554da
ow_script_0x9554da:
loadpointer 0x0 str_0x955852
callstd MSG_KEEPOPEN
setvar DYN_MULTICHOICE_ITEM_CNT 0x4
loadpointer 0x0 choice
multichoice 0x0 0x0 0x0 0x0
setvar DYN_MULTICHOICE_ITEM_CNT 0x0
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x9555b3
compare LASTRESULT 0x1
gotoif EQUAL ow_script_0x9555c9
compare LASTRESULT 0x2
gotoif EQUAL ow_script_0x9555df
compare LASTRESULT 0x3
gotoif EQUAL ow_script_0x955527
closeonkeypress
releaseall
end

.align 4
choice:
    .word str_orina_city_bounties_0, 0
    .word str_orina_city_bounties_1, 0
    .word str_orina_city_bounties_2, 0
    .word str_orina_city_bounties_3, 0


.global ow_script_0x955527
ow_script_0x955527:
call ow_script_0x8e63f4
loadpointer 0x0 str_0x95553d
callstd MSG
special 0x7
goto ow_script_0x9554da


.global ow_script_0x9555df
ow_script_0x9555df:
call ow_script_0x955687
loadpointer 0x0 str_0x9555f5
callstd MSG
special 0x7
goto ow_script_0x9554da


.global ow_script_0x955687
ow_script_0x955687:
setvar 0x8000 0x1
setvar 0x8001 0x1a
setvar 0x8002 0xe
special 0x6
return


.global ow_script_0x9555c9
ow_script_0x9555c9:
call ow_script_0x936c1c
loadpointer 0x0 str_0x95569b
callstd MSG
special 0x7
goto ow_script_0x9554da


.global ow_script_0x9555b3
ow_script_0x9555b3:
call ow_script_0x8f4d18
loadpointer 0x0 str_0x955726
callstd MSG
special 0x7
goto ow_script_0x9554da
