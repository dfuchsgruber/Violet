.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x888a24
ow_script_movs_0x888a24:
.byte SAY_EXCLAM
.byte STOP


.global ow_script_movs_0x888a27
ow_script_movs_0x888a27:
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x888a2a
ow_script_movs_0x888a2a:
.byte STEP_UP
.byte STEP_UP
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x888a2f
ow_script_movs_0x888a2f:
.byte STEP_RIGHT
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x888a36
ow_script_movs_0x888a36:
.byte LOOK_RIGHT
.byte STOP


.global ow_script_movs_0x888a33
ow_script_movs_0x888a33:
.byte LOOK_LEFT
.byte STOP


.global ow_script_movs_0x888a40
ow_script_movs_0x888a40:
.byte STEP_LEFT
.byte STOP


.global ow_script_movs_0x888a39
ow_script_movs_0x888a39:
.byte STEP_LEFT
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x888a10
ow_script_movs_0x888a10:
.byte STEP_DOWN
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x888a16
ow_script_movs_0x888a16:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_UP
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x888a1d
ow_script_movs_0x888a1d:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x888a08
ow_script_movs_0x888a08:
.byte STEP_RIGHT
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x888a0c
ow_script_movs_0x888a0c:
.byte STEP_RIGHT
.byte LOOK_UP
.byte STOP


.global ow_script_movs_0x8889e6
ow_script_movs_0x8889e6:
.byte STEP_RIGHT
.byte STEP_DOWN
.byte STOP


.global ow_script_movs_0x888a04
ow_script_movs_0x888a04:
.byte STEP_DOWN
.byte STEP_RIGHT
.byte STOP


.global ow_script_movs_0x888a43
ow_script_movs_0x888a43:
.byte STEP_IN_PLACE_RIGHT
.byte STOP


.global ow_script_movs_0x8889fe
ow_script_movs_0x8889fe:
.byte STEP_DOWN
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x8889ea
ow_script_movs_0x8889ea:
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_DOWN
.byte STEP_DOWN
.byte STEP_DOWN
.byte STOP


.global ow_script_movs_0x8889f4
ow_script_movs_0x8889f4:
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_LEFT
.byte STEP_DOWN
.byte STEP_DOWN
.byte STOP


.global ow_script_movs_0x888a3d
ow_script_movs_0x888a3d:
.byte STEP_DOWN
.byte STOP


.global ow_script_0x88832c
ow_script_0x88832c:
sound 0x15
applymovement 0x7 ow_script_movs_0x888a24
waitmovement 0x0
loadpointer 0x0 str_0x8884e2
callstd MSG
applymovement 0x7 ow_script_movs_0x888a27
waitmovement 0x0
loadpointer 0x0 str_0x8884fb
callstd MSG
playsong MUS_KOMMT_MIT_SPIELER_WIRD_HERUMGEFUHRT 0x0
applymovement 0x7 ow_script_movs_0x888a2a
applymovement 0xff ow_script_movs_0x888a2a
waitmovement 0x0
applymovement 0xff ow_script_movs_0x888a2f
waitmovement 0x0
applymovement 0x7 ow_script_movs_0x888a36
applymovement 0xff ow_script_movs_0x888a33
waitmovement 0x0
loadpointer 0x0 str_0x888541
callstd MSG
applymovement 0x7 ow_script_movs_0x888a40
waitmovement 0x0
applymovement 0x7 ow_script_movs_0x888a36
waitmovement 0x0
applymovement 0xff ow_script_movs_0x888a39
waitmovement 0x0
savincrementkey 0xf
loadpointer 0x0 str_0x1a81da
callstd MSG_KEEPOPEN
closeonkeypress
call ow_script_0x8884c3
pause 0x5
special 0x169
pause 0x5
preparemsg str_0x1a8237
waitmsg
applymovement 0x1 ow_script_movs_0x1a951d
waitmovement 0x0
loadpointer 0x0 str_0x1a8219
callstd MSG_KEEPOPEN
applymovement 0xff ow_script_movs_0x888a33
waitmovement 0x0
loadpointer 0x0 str_0x88861b
callstd MSG
applymovement 0x7 ow_script_movs_0x888a10
waitmovement 0x0
applymovement 0x7 ow_script_movs_0x888a16
applymovement 0xff ow_script_movs_0x888a1d
waitmovement 0x0
loadpointer 0x0 str_0x888649
callstd MSG
applymovement 0x7 ow_script_movs_0x888a08
applymovement 0xff ow_script_movs_0x888a0c
waitmovement 0x0
loadpointer 0x0 str_0x8886c2
callstd MSG
applymovement 0x7 ow_script_movs_0x8889e6
waitmovement 0x0
applymovement 0x7 ow_script_movs_0x888a04
applymovement 0xff ow_script_movs_0x888a04
waitmovement 0x0
loadpointer 0x0 str_0x888787
callstd MSG
applymovement 0x7 ow_script_movs_0x888a43
waitmovement 0x0
pause 0x20
sound 0x41
checksound
pause 0x10
applymovement 0x7 ow_script_movs_0x888a33
waitmovement 0x0
additem ITEM_TRANK 0x1
fanfare 0x13e
loadpointer 0x0 str_0x8889cd
callstd MSG_KEEPOPEN
waitfanfare
closeonkeypress
loadpointer 0x0 str_0x88887f
callstd MSG
applymovement 0x7 ow_script_movs_0x8889fe
waitmovement 0x0
applymovement 0x7 ow_script_movs_0x8889ea
applymovement 0xff ow_script_movs_0x8889f4
waitmovement 0x0
sound 0x9
hidesprite 0x7
setflag PKMNMENU
clearflag AMONIA_RIVAL_INSIDE_PLAYER_HOUSE
applymovement 0xff ow_script_movs_0x888a3d
waitmovement 0x0
setvar STORY_PROGRESS 0xa
warp 0x3 0x1 0x3 0x0 0x0
end


.global ow_script_0x8884c3
ow_script_0x8884c3:
applymovement 0x1 ow_script_movs_0x1aa419
waitmovement 0x0
doanimation 0x19
nop
checkanimation 0x19
applymovement 0x1 ow_script_movs_0x1aa41f
waitmovement 0x0
special 0x0
return