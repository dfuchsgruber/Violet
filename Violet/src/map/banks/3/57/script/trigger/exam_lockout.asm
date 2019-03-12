.include "callstds.s"
.include "movements.s"
.include "overworld_script.s"
.include "vars.s"
.include "ordinals.s"

.global ow_script_trainerschool_lock_grass
ow_script_trainerschool_lock_grass:
	lockall
	call lockout
	applymovement 0xFF mov_down
	waitmovement 0
	releaseall
	end

.global ow_script_trainerschool_lock_exit
ow_script_trainerschool_lock_exit:
	lockall
	call lockout
	applymovement 0xFF mov_up
	waitmovement 0x0
	releaseall
	end

lockout:
	compare TRAINERSCHOOL_PROGRESS 3
	callif EQUAL faun_not_arrived
	compare TRAINERSCHOOL_PROGRESS 4
	callif EQUAL receive_pkmn
	compare TRAINERSCHOOL_PROGRESS 5
	callif EQUAL receive_pokeballs
	compare TRAINERSCHOOL_PROGRESS 6
	callif EQUAL fight_wild_pokemon
	compare TRAINERSCHOOL_PROGRESS 7 @// Go to battle field
	callif EQUAL receive_pkmn
	compare TRAINERSCHOOL_PROGRESS 8 @// Take results from faun
	callif EQUAL receive_pkmn
	compare TRAINERSCHOOL_PROGRESS 9 @// Good-bye from npcs
	callif EQUAL goodbye
	return


goodbye:
	call ow_script_0x8a1cc9
	loadpointer 0 str_trainerschool_say_goodbye
	callstd MSG
	special 0x7
	return

faun_not_arrived:
	call ow_script_0x8a1cc9
	loadpointer 0 str
	callstd MSG
	special 0x7
	return

receive_pkmn:
	call ow_script_0x89c5ee
	loadpointer 0 str_receive_pkmn
	callstd MSG
	special 0x7
	return

receive_pokeballs:
	call ow_script_0x89c5ee
	loadpointer 0 str_receive_pkmn
	callstd MSG
	special 0x7
	return

fight_wild_pokemon:
	call ow_script_0x89c5ee
	loadpointer 0 str_fight_wild_pokemon
	callstd MSG
	special 0x7
	return

mov_up:
	.byte STEP_UP, STOP

mov_down:
	.byte STEP_DOWN, STOP

.ifdef LANG_GER
str:
    .autostring 35 2 "Ich sollte mich nicht zu weit von hier entfernen, Faun wird jeden Moment kommenDOTS"

str_receive_pkmn:
	.autostring 35 2 "Wo willst du denn hin, PLAYER! Komm gefälligst hierher!"

str_fight_wild_pokemon:
	.autostring 35 2 "Was ist los, PLAYER?\nFürchtest du dich etwa vor den wilden Pokémon?\pMach' keinen Unsinn und komm her!"

str_trainerschool_say_goodbye:
	.autostring 35 2 "Ich sollte mich von meinen Mitschülern verabschieden."

.elseif LANG_EN

.endif
