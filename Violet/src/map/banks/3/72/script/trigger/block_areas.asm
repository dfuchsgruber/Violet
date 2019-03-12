.include "callstds.s"
.include "movements.s"
.include "overworld_script.s"
.include "vars.s"
.include "ordinals.s"

.global ow_script_trainerschool_lock_right
ow_script_trainerschool_lock_right:
lockall
call ow_script_0x8a1cc9
loadpointer 0 str
callstd MSG
special 0x7
applymovement 0xFF mov_left
waitmovement 0
releaseall
end

.global ow_script_trainerschool_lock_up
ow_script_trainerschool_lock_up:
lockall
call ow_script_0x8a1cc9
loadpointer 0 str
callstd MSG
special 0x7
applymovement 0xFF mov_down
waitmovement 0
releaseall
end

.global ow_script_trainerschool_lock_classroom
ow_script_trainerschool_lock_classroom:
lockall
call faun_shout
applymovement 0xFF mov_left
waitmovement 0x0
releaseall
end

.global ow_script_trainerschool_lock_classroom2
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
call ow_script_0x89c5ee
loadpointer 0x0 lock_classroom_str
callstd MSG
special 0x7
return

.global ow_script_trainerschool_lock_down
ow_script_trainerschool_lock_down:
lockall
compare STORY_PROGRESS 7
gotoif LESS written_test_not_done
call ow_script_0x8a1cc9
loadpointer 0 str2
callstd MSG
special 0x7
applymovement 0xFF mov_up
waitmovement 0
releaseall
end

written_test_not_done:
call ow_script_0x8a1cc9
loadpointer 0 str
callstd MSG
special 0x7
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
    .autostring 35 2 "Ich sollte unverzüglich ins Klassenzimmer.\pFaun wird ohnehin schon rasend seinDOTS"

str2:
	.autostring 35 2 "Ich gehe besser auf den HofDOTS"

lock_classroom_str:
	.autostring 34 2 "PLAYER!\nDu willst dich doch nicht etwa drücken?\pSetz' dich gefälligst hin!"
        
.elseif LANG_EN

.endif
