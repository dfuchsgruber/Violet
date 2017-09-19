.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x89d801
ow_script_movs_0x89d801:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


.global ow_script_movs_0x89d7ee
ow_script_movs_0x89d7ee:
.byte LOOK_LEFT
.byte STOP


.global ow_script_0x89d6f0
ow_script_0x89d6f0:
lockall
applymovement 0x1 ow_script_movs_0x89d801
waitmovement 0x0
getplayerpos 0x8000 0x8005
compare 0x8005 0x21
callif EQUAL ow_script_0x89d7f1
applymovement 0xff ow_script_movs_0x89d7ee
waitmovement 0x0
call ow_script_0x89ba6e
loadpointer 0x0 str_0x89d77c
callstd MSG
special 0x7
goto ow_script_0x8f6e05


.global ow_script_0x8f6e05
ow_script_0x8f6e05:
compare 0x8005 0x21
callif EQUAL ow_script_0x89d759
compare 0x8005 0x22
callif EQUAL ow_script_0x89d765
goto ow_script_0x89d8a8


.global ow_script_movs_0x89d808
ow_script_movs_0x89d808:
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STOP


.global ow_script_0x89d8a8
ow_script_0x89d8a8:
applymovement 0x1 ow_script_movs_0x89d808
waitmovement 0x0
hidesprite 0x1
setflag TRAINERSCHOOL_RIVAL_INSIDE
clearflag AMONIA_RIVAL_INSIDE_PLAYER_HOUSE
setvar STORY_PROGRESS 0x7
end


.global ow_script_movs_0x89d777
ow_script_movs_0x89d777:
.byte STEP_UP_FAST
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STOP


.global ow_script_0x89d765
ow_script_0x89d765:
applymovement 0x1 ow_script_movs_0x89d777
waitmovement 0x0
return


.global ow_script_movs_0x89d771
ow_script_movs_0x89d771:
.byte STEP_DOWN_FAST
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STEP_UP_FAST
.byte STOP


.global ow_script_0x89d759
ow_script_0x89d759:
applymovement 0x1 ow_script_movs_0x89d771
waitmovement 0x0
return


.global ow_script_movs_0x89d7fd
ow_script_movs_0x89d7fd:
.byte STEP_UP
.byte LOOK_RIGHT
.byte STOP


.global ow_script_0x89d7f1
ow_script_0x89d7f1:
applymovement 0x1 ow_script_movs_0x89d7fd
waitmovement 0x0
return
