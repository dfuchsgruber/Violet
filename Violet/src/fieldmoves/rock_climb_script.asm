.include "overworld_script.s"
.include "vars.s"
.include "ordinals.s"
.include "movements.s"
.include "flags.s"
.include "attacks.s"
.include "callstds.s"

.global ow_script_rock_climb
.global ow_script_execute_rock_climb
ow_script_rock_climb:
special 0x187
compare LASTRESULT 2
gotoif EQUAL end_script
loadpointer 0 str_enter
callstd MSG_KEEPOPEN
checkflag FRBADGE_8
gotoif 0 dont_rock_climb
checkattack ATTACK_KRAXLER
compare LASTRESULT 0x6
gotoif EQUAL dont_rock_climb

setanimation 0x0 LASTRESULT
bufferpartypokemon 0x0 LASTRESULT
bufferattack 0x1 ATTACK_KRAXLER

loadpointer 0 str_use_rock_climb
callstd MSG_YES_NO
compare LASTRESULT 0
gotoif EQUAL dont_rock_climb

loadpointer 0 str_uses_rock_climb
callstd MSG

doanimation 0x2
nop
waitstate

goto step_head


ow_script_execute_rock_climb:
setanimation 0x0 LASTRESULT
bufferpartypokemon 0x0 LASTRESULT
bufferattack 0x1 ATTACK_KRAXLER
doanimation 0x2
nop
waitstate
step_head:
special2 LASTRESULT 0x9
compare LASTRESULT 0
gotoif EQUAL last_step
@ Execute another step of rock climb
call step
goto step_head
last_step:
call step
end_script:
end

dont_rock_climb:
closeonkeypress
end

step:
special2 0x8004 0x11f @//get player facing
compare 0x8004 1
callif EQUAL move_down
compare 0x8004 2
callif EQUAL move_up
compare 0x8004 3
callif EQUAL move_left
compare 0x8004 4
callif EQUAL move_right
return

move_down:
applymovement 0xFF mov_down
waitmovement 0
return

move_up:
applymovement 0xFF mov_up
waitmovement 0
return

move_left:
applymovement 0xFF mov_left
waitmovement 0
return

move_right:
applymovement 0xFF mov_right
waitmovement 0
return

mov_down:
	.byte STEP_DOWN_FAST, STOP
mov_up:
	.byte STEP_UP_FAST, STOP
mov_right:
	.byte STEP_RIGHT_FAST, STOP
mov_left:
	.byte STEP_LEFT_FAST, STOP

.ifdef LANG_GER

str_enter:
	.autostring 35 2 "Die Felswand sieht so aus, als könne ein Pokémon sie erklimmen DOTS"

str_use_rock_climb:
	.autostring 35 2 "Möchtest du Kraxler einsetzten, um die Felswand zu erklimmen?"

str_uses_rock_climb:
	.autostring 35 2 "BUFFER_1 setzt BUFFER_2 ein!"

.elseif LANG_EN

str_enter:
	.autostring 35 2 "The rock face looks like a Pokémon could climb it DOTS"

str_use_rock_climb:
	.autostring 35 2 "Do you want to use Rock Climb to climb the face rock?"

str_uses_rock_climb:
	.autostring 35 2 "BUFFER_1 uses BUFFER_2!"

.endif
