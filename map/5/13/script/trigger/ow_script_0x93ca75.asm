.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x93cd29
ow_script_movs_0x93cd29:
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x93cd2c
ow_script_movs_0x93cd2c:
.byte FACE_DOWN
.byte STOP


.global ow_script_0x93ca75
ow_script_0x93ca75:
lockall
applymovement 0x7 ow_script_movs_0x93cd29
waitmovement 0x0
applymovement 0xff ow_script_movs_0x93cd2c
waitmovement 0x0
checkflag FRBADGE_3
gotoif EQUAL ow_script_0x93cadd
compare DIFFICULTY 0x2
callif LESS ow_script_0x93cbc4
compare DIFFICULTY 0x2
callif EQUAL ow_script_0x93cbd1
compare DIFFICULTY 0x2
callif HIGHER ow_script_0x93cbde
loadpointer 0x0 str_0x93cbff
callstd MSG_YES_NO
compare LASTRESULT 0x0
gotoif EQUAL ow_script_0x93cacf
goto ow_script_0x93d018


.global ow_script_0x93d018
ow_script_0x93d018:
setvar MERIANA_ARENA_TRAINERS 0x4
settrainerflag 0x80
settrainerflag 0x81
settrainerflag 0x82
settrainerflag 0x83
goto ow_script_0x93d02f


.global ow_script_movs_0x93d3b2
ow_script_movs_0x93d3b2:
.byte LOOK_RIGHT
.byte STOP


.global ow_script_movs_0x93cb81
ow_script_movs_0x93cb81:
.byte STEP_DOWN
.byte LOOK_UP
.byte STOP


.global ow_script_0x93d02f
ow_script_0x93d02f:
applymovement 0xff ow_script_movs_0x93d3b2
waitmovement 0x0
applymovement 0x7 ow_script_movs_0x93cb81
waitmovement 0x0
compare MERIANA_ARENA_TRAINERS 0x4
gotoif EQUAL ow_script_0x93d077
compare MERIANA_ARENA_TRAINERS 0x3
gotoif EQUAL ow_script_0x93d0a3
compare MERIANA_ARENA_TRAINERS 0x2
gotoif EQUAL ow_script_0x93d156
compare MERIANA_ARENA_TRAINERS 0x1
gotoif EQUAL ow_script_0x93d210
goto ow_script_0x93d576


.global ow_script_movs_0x949189
ow_script_movs_0x949189:
.byte JUMP_LEFT2
.byte STEP_LEFT_VERY_SLOW
.byte STOP


.global ow_script_0x93d576
ow_script_0x93d576:
clearflag PKMNMENU
showsprite 0xa
setflag PKMNMENU
applymovement 0xa ow_script_movs_0x949189
waitmovement 0x0
trainerbattlecont 0x1 0x1a0 0x0 str_0x948a7f str_0x948b5a ow_script_0x94b868


.global ow_script_0x94b868
ow_script_0x94b868:
loadpointer 0x0 str_0x94907f
callstd MSG_KEEPOPEN
fanfare 0x104
loadpointer 0x0 str_0x949053
callstd MSG_KEEPOPEN
waitfanfare
setflag FRBADGE_3
setflag MERIANA_CITY_ELISE_VISIBLE
loadpointer 0x0 str_0x948eb4
callstd MSG_KEEPOPEN
copyvarifnotzero 0x8000 ITEM_TM01
copyvarifnotzero 0x8001 1
callstd ITEM_OBTAIN
loadpointer 0x0 str_0x948d53
callstd MSG_KEEPOPEN
closeonkeypress
addvar STORY_PROGRESS 0x1
warpmuted 0x3 0x1 0x2 0x0 0x0
release
end


.global ow_script_movs_0x93d563
ow_script_movs_0x93d563:
.byte STEP_LEFT
.byte JUMP_LEFT2
.byte STOP


.global ow_script_0x93d210
ow_script_0x93d210:
setvar 0x8005 0x8
clearflag PKMNMENU
showsprite 0x8005
setflag PKMNMENU
applymovement 0x8005 ow_script_movs_0x93d563
waitmovement 0x0
trainerbattlecont 0x1 0x83 0x0 str_0x948a18 str_0x948c44 ow_script_0x93d358


.global ow_script_movs_0x93d567
ow_script_movs_0x93d567:
.byte STEP_RIGHT
.byte JUMP_RIGHT2
.byte STOP


.global ow_script_0x93d358
ow_script_0x93d358:
applymovement 0x8005 ow_script_movs_0x93d567
waitmovement 0x0
hidesprite 0x8005
applymovement 0x7 ow_script_movs_0x93cd29
waitmovement 0x0
applymovement 0xff ow_script_movs_0x93cd2c
waitmovement 0x0
subvar MERIANA_ARENA_TRAINERS 0x1
compare MERIANA_ARENA_TRAINERS 0x0
callif EQUAL ow_script_0x93d40f
compare MERIANA_ARENA_TRAINERS 0x0
callif HIGHER ow_script_0x93d4a1
compare MERIANA_ARENA_HEALS 0x0
callif EQUAL ow_script_0x93d40c
compare MERIANA_ARENA_HEALS 0x0
callif HIGHER ow_script_0x94903b
goto ow_script_0x93d02f


.global ow_script_0x94903b
ow_script_0x94903b:
loadpointer 0x0 str_0x93d3ca
callstd MSG_YES_NO
compare LASTRESULT 0x1
callif EQUAL ow_script_0x948d14
closeonkeypress
clearflag TRANS_DISABLE
return


.global ow_script_0x948d14
ow_script_0x948d14:
setflag TRANS_DISABLE
clearflag TRANS_PALETTE_FETCH
loadpointer 0x0 str_0x949015
callstd MSG_KEEPOPEN
special 0x9f
waitstate
lock
faceplayer
compare 0x8004 0x6
gotoif HIGHER_OR_EQUAL ow_script_0x948fc2
special 0x26
loadpointer 0x0 str_0x948f99
callstd MSG_KEEPOPEN
subvar MERIANA_ARENA_HEALS 0x1
return


.global ow_script_0x948fc2
ow_script_0x948fc2:
loadpointer 0x0 str_0x948fcc
callstd MSG_KEEPOPEN
return


.global ow_script_0x93d40c
ow_script_0x93d40c:
closeonkeypress
return


.global ow_script_0x93d4a1
ow_script_0x93d4a1:
loadpointer 0x0 str_0x93d4ab
callstd MSG_KEEPOPEN
return


.global ow_script_0x93d40f
ow_script_0x93d40f:
loadpointer 0x0 str_0x93d419
callstd MSG_KEEPOPEN
return


.global ow_script_0x93d156
ow_script_0x93d156:
setvar 0x8005 0x9
clearflag PKMNMENU
showsprite 0x8005
setflag PKMNMENU
applymovement 0x8005 ow_script_movs_0x93d563
waitmovement 0x0
trainerbattlecont 0x1 0x82 0x0 str_0x93d182 str_0x93d1dd ow_script_0x93d358


.global ow_script_0x93d0a3
ow_script_0x93d0a3:
setvar 0x8005 0x8
clearflag PKMNMENU
showsprite 0x8005
setflag PKMNMENU
applymovement 0x8005 ow_script_movs_0x93d563
waitmovement 0x0
trainerbattlecont 0x1 0x81 0x0 str_0x93d0cf str_0x93d123 ow_script_0x93d358


.global ow_script_0x93d077
ow_script_0x93d077:
setvar 0x8005 0x9
clearflag PKMNMENU
showsprite 0x8005
setflag PKMNMENU
applymovement 0x8005 ow_script_movs_0x93d563
waitmovement 0x0
trainerbattlecont 0x1 0x80 0x0 str_0x93d4e4 str_0x93d52c ow_script_0x93d358


.global ow_script_0x93cacf
ow_script_0x93cacf:
loadpointer 0x0 str_0x93cb85
callstd MSG
goto ow_script_0x93cd2e


.global ow_script_movs_0x93cb7d
ow_script_movs_0x93cb7d:
.byte JUMP_LEFT2
.byte STEP_LEFT
.byte STOP


.global ow_script_0x93cd2e
ow_script_0x93cd2e:
applymovement 0x7 ow_script_movs_0x93cb81
waitmovement 0x0
sound 0xa
applymovement 0xff ow_script_movs_0x93cb7d
waitmovement 0x0
releaseall
end


.global ow_script_0x93cbde
ow_script_0x93cbde:
bufferstring 0x0 str_0x93cbf8
setvar MERIANA_ARENA_HEALS 0x0
return


.global ow_script_0x93cbd1
ow_script_0x93cbd1:
bufferstring 0x0 str_0x93cbf2
setvar MERIANA_ARENA_HEALS 0x1
return


.global ow_script_0x93cbc4
ow_script_0x93cbc4:
bufferstring 0x0 str_0x93cbeb
setvar MERIANA_ARENA_HEALS 0x2
return


.global ow_script_0x93cadd
ow_script_0x93cadd:
loadpointer 0x0 str_0x93caeb
callstd MSG
goto ow_script_0x93cd2e
