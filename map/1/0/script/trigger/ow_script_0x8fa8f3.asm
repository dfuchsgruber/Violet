.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x8037d4
ow_script_movs_0x8037d4:
.byte LOOK_RIGHT
.byte STOP


.global ow_script_movs_0x8f4d2c
ow_script_movs_0x8f4d2c:
.byte STEP_RIGHT
.byte STOP


.global ow_script_movs_0x8f4b78
ow_script_movs_0x8f4b78:
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x8f4ab5
ow_script_movs_0x8f4ab5:
.byte LOOK_LEFT
.byte STOP


.global ow_script_0x8fa8f3
ow_script_0x8fa8f3:
lockall
applymovement 0xff ow_script_movs_0x8037d4
waitmovement 0x0
settrainerflag 0x4a
settrainerflag 0x4b
settrainerflag 0x4c
lockall
playsong MUS_ROCKET_HQ_AND_AZURIA_HOHLE_AND_TOP_4_BRUNO 0x0
special 0x113
applymovement 0x7f ow_script_movs_0x8f4d2c
waitmovement 0x0
special 0x114
call ow_script_0x8f4d18
loadpointer 0x0 str_0x8f4c85
callstd MSG
special 0x7
call ow_script_0x8f4d04
loadpointer 0x0 str_0x8f4c4b
callstd MSG
special 0x7
call ow_script_0x8f4d18
loadpointer 0x0 str_0x8f4b7b
callstd MSG
special 0x7
applymovement 0x1e ow_script_movs_0x8f4b78
waitmovement 0x0
pause 0x38
call ow_script_0x8f4d04
loadpointer 0x0 str_0x8f4aee
callstd MSG
special 0x7
call ow_script_0x8f4d18
loadpointer 0x0 str_0x8f4ab8
callstd MSG
special 0x7
applymovement 0x1e ow_script_movs_0x8f4ab5
waitmovement 0x0
call ow_script_0x8f4d04
loadpointer 0x0 str_0x8f49f3
callstd MSG
special 0x7
call ow_script_0x8f4d18
loadpointer 0x0 str_0x8f49c5
callstd MSG
special 0x7
call ow_script_0x8f4d04
loadpointer 0x0 str_0x8f48ca
callstd MSG
special 0x7
call ow_script_0x8f4d18
loadpointer 0x0 str_0x8f4823
callstd MSG
special 0x7
call ow_script_0x8f4d04
loadpointer 0x0 str_0x8f4755
callstd MSG
special 0x7
call ow_script_0x8f4d18
goto ow_script_0x8fbc5c


.global ow_script_0x8fbc5c
ow_script_0x8fbc5c:
loadpointer 0x0 str_0x8f46fc
callstd MSG
special 0x7
goto ow_script_0x8f5143


.global ow_script_movs_0x8f5a91
ow_script_movs_0x8f5a91:
.byte STEP_RIGHT
.byte STOP


.global ow_script_movs_0x8f5a8d
ow_script_movs_0x8f5a8d:
.byte LOOK_LEFT
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x8f505f
ow_script_movs_0x8f505f:
.byte LOOK_RIGHT
.byte STOP


.global ow_script_movs_0x8f5140
ow_script_movs_0x8f5140:
.byte LOOK_LEFT
.byte STOP


.global ow_script_movs_0x8f52c0
ow_script_movs_0x8f52c0:
.byte STEP_DOWN
.byte LOOK_LEFT
.byte STOP


.global ow_script_movs_0x8f52c4
ow_script_movs_0x8f52c4:
.byte STEP_LEFT
.byte STEP_DOWN
.byte STEP_LEFT
.byte STOP


.global ow_script_0x8f5143
ow_script_0x8f5143:
getplayerpos 0x8000 0x8001
compare 0x8001 0x12
callif EQUAL ow_script_0x8f5a94
compare 0x8001 0x14
callif EQUAL ow_script_0x8f5aa3
applymovement 0xff ow_script_movs_0x8f5a91
waitmovement 0x0
sound 0x15
applymovement 0x1e ow_script_movs_0x8f5a8d
applymovement 0x1f ow_script_movs_0x8f5a8d
applymovement 0x20 ow_script_movs_0x8f5a8d
applymovement 0x5 ow_script_movs_0x8f5a8d
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8f5a63
callstd MSG
waitmovement 0x0
special 0x7
call ow_script_0x8f4d04
loadpointer 0x0 str_0x8f59e8
callstd MSG
special 0x7
applymovement 0x5 ow_script_movs_0x8f505f
waitmovement 0x0
call ow_script_0x8f4d18
loadpointer 0x0 str_0x8f59cf
callstd MSG
applymovement 0x5 ow_script_movs_0x8f5140
loadpointer 0x0 str_0x8f56b8
callstd MSG
special 0x7
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8f5628
callstd MSG
special 0x7
call ow_script_0x8f4d18
loadpointer 0x0 str_0x8f5514
callstd MSG
special 0x7
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8f5425
callstd MSG
special 0x7
call ow_script_0x8f4d18
loadpointer 0x0 str_0x8f52c9
callstd MSG
special 0x7
applymovement 0x20 ow_script_movs_0x8f52c0
applymovement 0x1f ow_script_movs_0x8f52c4
waitmovement 0x0
trainerbattlecont 0x1 0x4a 0x0 str_0x8f523b str_0x8f527b ow_script_0x8f5cdf


.global ow_script_0x8f5cdf
ow_script_0x8f5cdf:
playsong MUS_ROCKET_HQ_AND_AZURIA_HOHLE_AND_TOP_4_BRUNO 0x0
loadpointer 0x0 str_0x8f5f96
callstd MSG
trainerbattlecont 0x1 0x4b 0x0 str_0x8f5f21 str_0x8f5f57 ow_script_0x8fa888


.global ow_script_movs_0x8f5eb0
ow_script_movs_0x8f5eb0:
.byte STEP_UP
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x8f5eb4
ow_script_movs_0x8f5eb4:
.byte LOOK_UP
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x8f5eac
ow_script_movs_0x8f5eac:
.byte STEP_DOWN
.byte STEP_LEFT
.byte STOP


.global ow_script_0x8fa888
ow_script_0x8fa888:
playsong MUS_ROCKET_HQ_AND_AZURIA_HOHLE_AND_TOP_4_BRUNO 0x0
loadpointer 0x0 str_0x8f5edb
callstd MSG
call ow_script_0x8f4d18
loadpointer 0x0 str_0x8f5eb8
callstd MSG
special 0x7
applymovement 0x20 ow_script_movs_0x8f5eb0
applymovement 0x1f ow_script_movs_0x8f5eb4
waitmovement 0x0
applymovement 0x5 ow_script_movs_0x8f5eac
waitmovement 0x0
pause 0x20
call ow_script_0x8f4d18
loadpointer 0x0 str_0x8f5d92
callstd MSG
setflag TRANS_DISABLE
clearflag TRANS_PALETTE_FETCH
special 0x3b
playsong MUS_KAMPF_GEGEN_ARENALEITER_HOENN 0x0
trainerbattlecont 0x1 0x4c 0x0 str_0x8f5d92 str_0x8f5d31 ow_script_0x8fab2c


.global ow_script_movs_0x8f6d19
ow_script_movs_0x8f6d19:
.byte LOOK_RIGHT
.byte STOP


.global ow_script_movs_0x8f6d16
ow_script_movs_0x8f6d16:
.byte LOOK_UP_DELAYED
.byte LOOK_DOWN_DELAYED
.byte STOP


.global ow_script_movs_0x8f6cf5
ow_script_movs_0x8f6cf5:
.byte STEP_DOWN
.byte STEP_LEFT
.byte STEP_LEFT
.byte STOP


.global ow_script_movs_0x8f6c01
ow_script_movs_0x8f6c01:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT_FAST
.byte STOP


.global ow_script_movs_0x8f6bfe
ow_script_movs_0x8f6bfe:
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x8f6be5
ow_script_movs_0x8f6be5:
.byte STEP_UP_FAST
.byte LOOK_LEFT
.byte STOP


.global ow_script_movs_0x8f6a5d
ow_script_movs_0x8f6a5d:
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x8f6ae2
ow_script_movs_0x8f6ae2:
.byte FACE_DOWN
.byte STOP


.global ow_script_movs_0x8f68a4
ow_script_movs_0x8f68a4:
.byte LOOK_RIGHT
.byte SAY_QUESTION
.byte STOP


.global ow_script_0x8fab2c
ow_script_0x8fab2c:
applymovement 0xff ow_script_movs_0x8f6d19
waitmovement 0x0
clearflag TRANS_DISABLE
call ow_script_0x8f4d18
loadpointer 0x0 str_0x8fa9e7
callstd MSG
special 0x7
applymovement 0x5 ow_script_movs_0x8f6d16
waitmovement 0x0
call ow_script_0x8f4d18
loadpointer 0x0 str_0x8f6cfb
callstd MSG
special 0x7
fadescreen 0x1
hidesprite 0x5
hidesprite 0x1f
hidesprite 0x20
hidesprite 0xd
hidesprite 0x9
hidesprite 0x6
fadescreen 0x0
applymovement 0x1e ow_script_movs_0x8f6cf5
waitmovement 0x0
call ow_script_0x8f4d04
loadpointer 0x0 str_0x8f6c09
callstd MSG
special 0x7
clearflag PKMNMENU
showsprite 0x24
applymovement 0x24 ow_script_movs_0x8f6c01
waitmovement 0x0
sound 0x15
applymovement 0x24 ow_script_movs_0x8f6bfe
waitmovement 0x0
call ow_script_0x8a7f80
loadpointer 0x0 str_0x8f6be9
callstd MSG
special 0x7
applymovement 0x1e ow_script_movs_0x8f6be5
waitmovement 0x0
applymovement 0xff ow_script_movs_0x8f6a5d
waitmovement 0x0
call ow_script_0x8f4d04
loadpointer 0x0 str_0x8f6bb4
callstd MSG
special 0x7
call ow_script_0x8a7f80
loadpointer 0x0 str_0x8f6b22
callstd MSG
special 0x7
call ow_script_0x8f4d04
loadpointer 0x0 str_0x8f6ae5
callstd MSG
applymovement 0x1e ow_script_movs_0x8f6ae2
waitmovement 0x0
loadpointer 0x0 str_0x8f6a60
callstd MSG
special 0x7
applymovement 0x24 ow_script_movs_0x8f6ae2
waitmovement 0x0
call ow_script_0x8a7f80
loadpointer 0x0 str_0x8f68d7
callstd MSG
special 0x7
call ow_script_0x8f4d04
loadpointer 0x0 str_0x8f68a8
callstd MSG_KEEPOPEN
sound 0x15
applymovement 0x24 ow_script_movs_0x8f68a4
applymovement 0xff ow_script_movs_0x8f68a4
waitmovement 0x0
loadpointer 0x0 str_0x8f6749
callstd MSG
special 0x7
call ow_script_0x8a7f80
loadpointer 0x0 str_0x8f6725
callstd MSG
special 0x7
call ow_script_0x8f4d04
loadpointer 0x0 str_0x8f6626
callstd MSG_KEEPOPEN
special 0x7
fadescreen 0x1
hidesprite 0x1e
fadescreen 0x0
applymovement 0x24 ow_script_movs_0x8f6ae2
applymovement 0xff ow_script_movs_0x8f6a5d
waitmovement 0x0
call ow_script_0x8a7f80
loadpointer 0x0 str_0x8f65b0
callstd MSG
special 0x7
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x8f64bc
callstd MSG
special 0x7
call ow_script_0x8a7f80
loadpointer 0x0 str_0x8f6465
callstd MSG
special 0x7
fadescreen 0x1
hidesprite 0x24
fadescreen 0x0
addvar STORY_PROGRESS 0x1
releaseall
end


.global ow_script_0x8f4d04
ow_script_0x8f4d04:
setvar 0x8000 0x0
setvar 0x8001 0x18
setvar 0x8002 0xe
special 0x6
return


.global ow_script_0x8f4d18
ow_script_0x8f4d18:
setvar 0x8000 0x1
setvar 0x8001 0x0
setvar 0x8002 0xe
special 0x6
return


.global ow_script_movs_0x8f5aaf
ow_script_movs_0x8f5aaf:
.byte STEP_UP
.byte STOP


.global ow_script_0x8f5aa3
ow_script_0x8f5aa3:
applymovement 0xff ow_script_movs_0x8f5aaf
waitmovement 0x0
return


.global ow_script_movs_0x8f5aa0
ow_script_movs_0x8f5aa0:
.byte STEP_DOWN
.byte STOP


.global ow_script_0x8f5a94
ow_script_0x8f5a94:
applymovement 0xff ow_script_movs_0x8f5aa0
waitmovement 0x0
return
