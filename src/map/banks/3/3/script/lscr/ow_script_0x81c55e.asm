.include "movements.s"
.include "callstds.s"
.include "vars.s"
.include "overworld_script.s"


.global ow_script_movs_0x8e6a33
ow_script_movs_0x8e6a33:
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
.byte STEP_RIGHT_FAST
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


.global ow_script_movs_0x81c5a4
ow_script_movs_0x81c5a4:
.byte STEP_UP
.byte STOP


.global ow_script_movs_0x87e927
ow_script_movs_0x87e927:
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_DOWN_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STEP_LEFT_FAST
.byte STOP


.global ow_script_0x81c55e
ow_script_0x81c55e:
lockall
special 0x113
applymovement 0x7f ow_script_movs_0x8e6a33
waitmovement 0x0
loadpointer 0 str_violet
setvar 0x8000 0
special 0xE
loadpointer 0x0 str_r1
callstd MSG
special 0xF
loadpointer 0 str_violet
setvar 0x8000 1
special 0xE
loadpointer 0x0 str_r2
callstd MSG
special 0xF

applymovement 0x1 ow_script_movs_0x81c5a4
applymovement 0x2 ow_script_movs_0x81c5a4
waitmovement 0x0
sound 0x9
hidesprite 0x1
hidesprite 0x2
checksound
applymovement 0x7f ow_script_movs_0x87e927
waitmovement 0x0
special 0x114
addvar STORY_PROGRESS 0x1
releaseall
end


.ifdef LANG_GER

str_violet:
	.string "Team Violet Rüpel"

str_r1:
	.autostring 36 2 "Beeilen wir uns besser, Rin wartet schon auf uns DOTS"

str_r2:
	.autostring 36 2 "Ja und sie wird schnell launisch, wenn man sie warten lässt DOTS"

        
.elseif LANG_EN

.endif
