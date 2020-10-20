.include "vars.s"
.include "movements.s"
.include "callstds.s"
.include "mugshot.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "flags.s"

.global ow_script_0x89d765
.global ow_script_0x89d7f1
.global ow_script_0x89d759
.global ow_script_0x89d8a8
.global ow_script_0x8f6e05
.global ow_script_trainerschool_lock_right
.global ow_script_trainerschool_lock_down
.global ow_script_trainerschool_lock_up
.global ow_script_trainerschool_rival_goes_outside
.global ow_script_trainerschool_lock_classroom
.global ow_script_trainerschool_lock_classroom2

ow_script_trainerschool_lock_right:
lockall
loadpointer 0 str
show_mugshot MUGSHOT_PLAYER
applymovement 0xFF mov_left
waitmovement 0
releaseall
end

ow_script_trainerschool_lock_up:
lockall
loadpointer 0 str
show_mugshot MUGSHOT_PLAYER
applymovement 0xFF mov_down
waitmovement 0
releaseall
end

ow_script_trainerschool_lock_classroom:
lockall
call faun_shout
applymovement 0xFF mov_left
waitmovement 0x0
releaseall
end

ow_script_trainerschool_lock_classroom2:
lockall
special 0x113
applymovement 0x7F mov_up
waitmovement 0x0
call faun_shout
applymovement 0x7F mov_down
waitmovement 0x0
special 0x114
applymovement 0xFF mov_left
waitmovement 0x0
releaseall
end

faun_shout:
sound 0x15
applymovement 0x9 mov_shout
applymovement 0xFF mov_look_left
waitmovement 0x0
loadpointer 0x0 lock_classroom_str
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT emotion=MUGSHOT_ANGRY
return

ow_script_trainerschool_lock_down:
lockall
compare STORY_PROGRESS 7
gotoif LESS written_test_not_done
loadpointer 0 str2
show_mugshot MUGSHOT_PLAYER
applymovement 0xFF mov_up
waitmovement 0
releaseall
end

written_test_not_done:
loadpointer 0 str
show_mugshot MUGSHOT_PLAYER
applymovement 0xFF mov_up
waitmovement 0
releaseall
end

mov_left:
	.byte STEP_LEFT, STOP
mov_down:
	.byte STEP_DOWN, STOP
mov_up:
	.byte STEP_UP, STOP
mov_look_left:
	.byte LOOK_LEFT
	.byte STOP
mov_shout:
	.byte LOOK_RIGHT
	.byte SAY_EXCLAM
	.byte STOP

.ifdef LANG_GER
str:
    .autostring 35 2 "Ich sollte besser schnell in unser Klassenzimmer."
str2:
	.autostring 35 2 "Ich gehe besser auf den HofDOTS\pDer Feldtest fängt sicher gleich an."
lock_classroom_str:
	.autostring 34 2 "PLAYER!\nDu willst dich doch nicht etwa drücken?\pSetz' dich gefälligst hin!"
.elseif LANG_EN
str:
    .autostring 35 2 "I should hurry up and go to the classroom."
str2:
	.autostring 35 2 "I better go to the schoolyard.\pThe field exam will start at any moment."
lock_classroom_str:
	.autostring 34 2 "PLAYER!\nYou're not trying to weasel out, are ya?\pUnbelievable!\nTake a seat before I come and get you!"
.endif


ow_script_movs_0x89d801:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP


ow_script_movs_0x89d7ee:
.byte LOOK_LEFT
.byte STOP


ow_script_trainerschool_rival_goes_outside:
lockall
applymovement 0x1 ow_script_movs_0x89d801
waitmovement 0x0
getplayerpos 0x8000 0x8005
compare 0x8005 0x21
callif EQUAL ow_script_0x89d7f1
applymovement 0xff ow_script_movs_0x89d7ee
waitmovement 0x0
checkgender
compare LASTRESULT 0x0
callif EQUAL hurry_m
callif NOT_EQUAL hurry_f
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT
goto ow_script_0x8f6e05

hurry_m:
    loadpointer 0x0 str_hurry_m
    return

hurry_f:
    loadpointer 0x0 str_hurry_f
    return


ow_script_0x8f6e05:
compare 0x8005 0x21
callif EQUAL ow_script_0x89d759
compare 0x8005 0x22
callif EQUAL ow_script_0x89d765
goto ow_script_0x89d8a8


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


ow_script_0x89d8a8:
applymovement 0x1 ow_script_movs_0x89d808
waitmovement 0x0
hidesprite 0x1
setflag TRAINERSCHOOL_RIVAL_OUTSIDE @// Make him visible
addvar TRAINERSCHOOL_PROGRESS 1
end


ow_script_movs_0x89d777:
.byte STEP_UP_FAST
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STOP


ow_script_0x89d765:
applymovement 0x1 ow_script_movs_0x89d777
waitmovement 0x0
return


ow_script_movs_0x89d771:
.byte STEP_DOWN_FAST
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STEP_UP_FAST
.byte STOP


ow_script_0x89d759:
applymovement 0x1 ow_script_movs_0x89d771
waitmovement 0x0
return


ow_script_movs_0x89d7fd:
.byte STEP_UP
.byte LOOK_RIGHT
.byte STOP


ow_script_0x89d7f1:
applymovement 0x1 ow_script_movs_0x89d7fd
waitmovement 0x0
return


.ifdef LANG_GER

str_hurry_m:
	.autostring 34 2 "Immer noch nicht drauen?\pHeut hast du es wirklich mit dem Trödeln, PLAYER!"
str_hurry_f:
	.autostring 34 2 "Immer noch nicht drauen?\pHeut hast du es wirklich mit dem Trödeln, PLAYER!"

.elseif LANG_EN

str_hurry_m:
	.autostring 34 2 "Still in here?\pYou really are taking your time today, PLAYER!"
str_hurry_f:
	.autostring 34 2 "Still in here?\pYou really are taking your time today, PLAYER!"

.endif