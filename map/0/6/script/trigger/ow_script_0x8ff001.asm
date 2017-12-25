.include "overworld_script.s"

.include "std.s"

.global ow_script_movs_0x8ff26e
ow_script_movs_0x8ff26e:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


.global ow_script_movs_0x8ff96a
ow_script_movs_0x8ff96a:
.byte LOOK_LEFT
.byte STOP


.global ow_script_movs_0x8ff0da
ow_script_movs_0x8ff0da:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


.global ow_script_0x8ff001
ow_script_0x8ff001:
lockall
clearflag PKMNMENU
showsprite 0x12
getplayerpos 0x8004 0x8005
compare 0x8005 0x5
callif EQUAL ow_script_0x8ff96d
applymovement 0x12 ow_script_movs_0x8ff26e
waitmovement 0x0
applymovement 0xff ow_script_movs_0x8ff96a
waitmovement 0x0
call ow_script_0x89e1fc
loadpointer 0x0 str_0x8ff6f3
callstd MSG
special 0x7
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x9454f8
callstd MSG
special 0x7
call ow_script_0x89e1fc
loadpointer 0x0 str_0x94591f
callstd MSG_KEEPOPEN
special 0x7
setvar DYN_MULTICHOICE_ITEM_CNT 0x2
loadpointer 0x0 choice
multichoice 0x0 0x0 0x0 0x1
setvar DYN_MULTICHOICE_ITEM_CNT 0x0
copyvar 0x8004 LASTRESULT
compare 0x8004 0x0
callif EQUAL ow_script_0x8ff277
compare 0x8004 0x1
callif EQUAL ow_script_0x8ff296
loadpointer 0x0 str_0x945a65
callstd MSG
special 0x7
pause 0x28
call ow_script_0x89e1fc
loadpointer 0x0 str_0x945bc8
callstd MSG
special 0x7
compare 0x8005 0x5
callif EQUAL ow_script_0x8ff0e5
compare 0x8005 0x4
callif EQUAL ow_script_0x8ff0f1
applymovement 0x12 ow_script_movs_0x8ff0da
waitmovement 0x0
hidesprite 0x12
addvar STORY_PROGRESS 0x1
addvar DIFFICULTY_LEVEL_RANGE 0x2
releaseall
end

.align 4
choice:
    .word str_felsige_oednis_choice_0, 0
    .word str_felsige_oednis_choice_1, 0


.global ow_script_movs_0x8ff979
ow_script_movs_0x8ff979:
.byte STEP_DOWN
.byte STOP


.global ow_script_0x8ff0f1
ow_script_0x8ff0f1:
applymovement 0x12 ow_script_movs_0x8ff979
waitmovement 0x0
return


.global ow_script_movs_0x8ff0fd
ow_script_movs_0x8ff0fd:
.byte STEP_UP
.byte STOP


.global ow_script_0x8ff0e5
ow_script_0x8ff0e5:
applymovement 0x12 ow_script_movs_0x8ff0fd
waitmovement 0x0
return


.global ow_script_0x8ff296
ow_script_0x8ff296:
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x945da0
callstd MSG
special 0x7
call ow_script_0x89e1fc
loadpointer 0x0 str_0x945daa
callstd MSG_KEEPOPEN
return


.global ow_script_0x8ff277
ow_script_0x8ff277:
call ow_script_0x8a1cc9
loadpointer 0x0 str_0x945c7d
callstd MSG
special 0x7
call ow_script_0x89e1fc
loadpointer 0x0 str_0x945d2b
callstd MSG_KEEPOPEN
return


.global ow_script_0x8ff96d
ow_script_0x8ff96d:
applymovement 0x12 ow_script_movs_0x8ff979
waitmovement 0x0
return
