.include "overworld_script.s"

.include "std.s"

.global ow_script_0x8fbbbb
ow_script_0x8fbbbb:
lockall
goto ow_script_0x8f6e67


.global ow_script_movs_0x8fbc24
ow_script_movs_0x8fbc24:
.byte SAY_EXCLAM
.byte STOP


.global ow_script_0x8f6e67
ow_script_0x8f6e67:
sound 0x15
applymovement 0x48 ow_script_movs_0x8fbc24
waitmovement 0x0
goto ow_script_0x8bf01f


.global ow_script_0x8bf01f
ow_script_0x8bf01f:
call ow_script_0x8bf7fb
loadpointer 0x0 str_0x8bf724
callstd MSG
special 0x7
setvar 0x8004 0x48
setvar LASTTALKED 0x48
special 0x19
waitmovement 0x0
faceplayer
call ow_script_0x8bf7fb
loadpointer 0x0 str_0x8bf610
callstd MSG_YES_NO
special 0x7
compare LASTRESULT 0x0
callif EQUAL ow_script_0x8bf0a0
goto ow_script_0x8bf0c1


.global ow_script_0x8bf0c1
ow_script_0x8bf0c1:
compare STARTER_SELECTED 0x0
gotoif EQUAL ow_script_0x8bf102
compare STARTER_SELECTED 0x1
gotoif EQUAL ow_script_0x8bf12d
call ow_script_0x8bf7fb
loadpointer 0x0 str_0x8bfe09
callstd MSG_KEEPOPEN
special 0x7
trainerbattlecont 0x1 0x2b 0x0 str_0x8bf5bc str_0x8bf5d1 ow_script_0x8bf158


.global ow_script_0x8bf158
ow_script_0x8bf158:
call ow_script_0x8bf7fb
loadpointer 0x0 str_0x8bf3f9
callstd MSG
special 0x7
additem ITEM_KARTE 0x1
fanfare 0x13e
loadpointer 0x0 str_0x8bf3dc
callstd MSG_KEEPOPEN
waitfanfare
closeonkeypress
call ow_script_0x8bf7fb
loadpointer 0x0 str_0x8bf2f0
callstd MSG
special 0x7
fadescreen 0x1
hidesprite 0x48
fadescreen 0x0
goto ow_script_0x8fb459


.global ow_script_0x8fb459
ow_script_0x8fb459:
addvar STORY_PROGRESS 0x1
releaseall
end


.global ow_script_0x8bf7fb
ow_script_0x8bf7fb:
setvar 0x8000 0x0
setvar 0x8001 0x8
setvar 0x8002 0xe
special 0x6
return


.global ow_script_0x8bf12d
ow_script_0x8bf12d:
call ow_script_0x8bf7fb
loadpointer 0x0 str_0x8bfe09
callstd MSG_KEEPOPEN
special 0x7
trainerbattlecont 0x1 0x2a 0x0 str_0x8bf5bc str_0x8bf5d1 ow_script_0x8bf158


.global ow_script_0x8bf102
ow_script_0x8bf102:
call ow_script_0x8bf7fb
loadpointer 0x0 str_0x8bfe09
callstd MSG_KEEPOPEN
special 0x7
trainerbattlecont 0x1 0x29 0x0 str_0x8bf5bc str_0x8bf5d1 ow_script_0x8bf158


.global ow_script_0x8bf0a0
ow_script_0x8bf0a0:
call ow_script_0x8bf7fb
loadpointer 0x0 str_0x8bf745
callstd MSG_YES_NO
special 0x7
compare LASTRESULT 0x0
callif EQUAL ow_script_0x8bf0a0
goto ow_script_0x8bf0c1
