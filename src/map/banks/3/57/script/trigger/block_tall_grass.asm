.include "callstds.s"
.include "movements.s"
.include "overworld_script.s"
.include "vars.s"
.include "ordinals.s"

.global ow_script_trainerschool_lock_grass
ow_script_trainerschool_lock_grass:
lockall
compare TRAINERSCHOOL_PROGRESS 3
gotoif EQUAL faun_not_arrived
compare TRAINERSCHOOL_PROGRESS 4
gotoif EQUAL receive_pkmn
compare TRAINERSCHOOL_PROGRESS 5
gotoif EQUAL receive_pokeballs
compare TRAINERSCHOOL_PROGRESS 7 @// Go to battle field
gotoif EQUAL receive_pkmn
compare TRAINERSCHOOL_PROGRESS 8 @// Take results from faun
gotoif EQUAL receive_pkmn
compare TRAINERSCHOOL_PROGRESS 9 @// Good-bye from npcs
gotoif EQUAL goodbye
end

.global ow_script_trainerschool_lock_exit
ow_script_trainerschool_lock_exit:
call ow_script_0x8a1cc9
loadpointer 0 str_trainerschool_say_goodbye
callstd MSG
special 0x7
applymovement 0xFF mov_up
waitmovement 0
releaseall
end

goodbye:
call ow_script_0x8a1cc9
loadpointer 0 str_trainerschool_say_goodbye
callstd MSG
special 0x7
goto move_player_down

faun_not_arrived:
call ow_script_0x8a1cc9
loadpointer 0 str
callstd MSG
special 0x7
move_player_down:
applymovement 0xFF mov_down
waitmovement 0
releaseall
end

receive_pkmn:
call ow_script_0x89c5ee
loadpointer 0 str_receive_pkmn
callstd MSG
special 0x7
goto move_player_down

receive_pokeballs:
call ow_script_0x89c5ee
loadpointer 0 str_receive_pkmn
callstd MSG
special 0x7
goto move_player_down

mov_up:
	.byte STEP_UP, STOP

mov_down:
	.byte STEP_DOWN, STOP

.ifdef LANG_GER
str:
    .autostring 36 2 "Ich sollte mich nicht zu weit von der Gruppe entfernen, Faun wird jeden Moment kommenDOTS"

str_receive_pkmn:
	.autostring 36 2 "Wo willst du denn hin, PLAYER! Komm gefälligst hierher!"

str_trainerschool_say_goodbye:
	.autostring 36 2 "Ich sollte mich von meinen Mitschülern verabschieden."

.elseif LANG_EN

.endif
