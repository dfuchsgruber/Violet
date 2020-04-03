.include "vars.s"
.include "movements.s"
.include "specials.s"
.include "callstds.s"
.include "songs.s"
.include "mugshot.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "flags.s"
.include "items.s"

.global ow_script_0x89c06b
.global ow_script_map_3_57_trigger_1
.global ow_script_map_3_57_trigger_0
.global ow_script_0x8f6dec
.global ow_script_trainerschool_lock_grass
.global ow_script_trainerschool_battle_test
.global ow_script_trainerschool_lock_exit

ow_script_trainerschool_battle_test:
lockall
applymovement 4 mov_face_down
applymovement 3 mov_face_up
applymovement 5 mov_face_up
applymovement 7 mov_face_up
applymovement 0xFF mov_face_up
waitmovement 0
loadpointer 0 str_announce_battle
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
applymovement 3 mov_face_right
applymovement 7 mov_face_right
applymovement 0xFF mov_face_left
applymovement 5 mov_face_left
waitmovement 0
pause 32
draw_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT
loadpointer 0 str_rival_challange
callstd MSG_KEEPOPEN
compare STARTER_SELECTED 0
gotoif EQUAL plant_chosen
compare STARTER_SELECTED 1
gotoif EQUAL fire_chosen
compare STARTER_SELECTED 2
gotoif EQUAL water_chosen
end

plant_chosen:
trainerbattlelosable 0x9 0xb3 0x0 str_won str_lost
goto after_battle

fire_chosen:
trainerbattlelosable 0x9 0xb4 0x0 str_won str_lost
goto after_battle

water_chosen:
trainerbattlelosable 0x9 0xb5 0x0 str_won str_lost
goto after_battle

after_battle:
compare LASTRESULT 0xFF
gotoif EQUAL lost_battle
won_battle:
loadpointer 0 str_after_battle_won
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT
may_felix_battle:
clearflag BLACKOUT_BYPASS
special 0x113
applymovement 0x7f mov_cam_to_may_felix
waitmovement 0x0
loadpointer 0 str_may_lost
show_mugshot MUGSHOT_MAY MUGSHOT_RIGHT
loadpointer 0 str_felix_won
show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT
applymovement 0x7F mov_cam_back
waitmovement 0
special 0x114
@ Battles are over
loadpointer 0 str_announce_end
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
applymovement 7 mov_face_up
applymovement 0xFF mov_player_row
applymovement 5 mov_may_row
applymovement 3 mov_rival_row
waitmovement 0
@ Award felix
loadpointer 0 str_final_call_felix
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
applymovement 7 mov_felix_to_faun
waitmovement 0
loadpointer 0 str_award_felix
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
fanfare 0x13E
waitfanfare
loadpointer 0 str_felix_awarded
show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT
applymovement 7 mov_felix_back
waitmovement 0
loadpointer 0 str_final_call_player
show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
addvar TRAINERSCHOOL_PROGRESS 1
releaseall
end

lost_battle:
special SPECIAL_HEAL
loadpointer 0 str_after_battle_lost
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT
goto may_felix_battle

mov_felix_back:
	.byte STEP_RIGHT, STEP_DOWN, LOOK_UP, STOP

mov_felix_to_faun:
	.byte STEP_UP, STEP_LEFT, LOOK_UP, STOP

mov_player_row:
	.byte STEP_RIGHT, STEP_RIGHT, LOOK_UP, STOP

mov_may_row:
	.byte STEP_LEFT, STEP_LEFT, STEP_LEFT, LOOK_UP, STOP

mov_rival_row:
	.byte STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, LOOK_UP, STOP

mov_cam_back:
	.byte STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_LEFT, STEP_LEFT, STOP

mov_cam_to_may_felix:
	.byte STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STEP_RIGHT, STOP

mov_face_down:
	.byte LOOK_DOWN, STOP

mov_face_up:
	.byte LOOK_UP, STOP

mov_face_left:
	.byte LOOK_LEFT, STOP

mov_face_right:
	.byte LOOK_RIGHT, STOP

	.ifdef LANG_GER

str_announce_battle:
	.autostring 35 2 "Nun denn, ihr Bälger!\pZeit für den wahren Härtetest. Ihr tretet nun in einem Kampf gegeneinander an.\pWenn ihr diese Prüfung bestehen wollt, gebt alles!"

str_rival_challange:
	.autostring 35 2 "PLAYER! Das ist der Tag, von dem wir geträumt haben!\pWir beide gegenüber in einem Pokémon-Kampf.\pIch werde dir eine Lektion erteilen!"

str_won:
	.autostring 35 2 "Moment! Das kann nicht sein! Du hast geschummelt, ich will nochmal!"

str_lost:
	.autostring 35 2 "Tja, ich bin dir immer einen Schritt voraus!"

str_after_battle_won:
	.autostring 35 2 "Das war ein einfacher Ausrutscher! Nichts weiter!\pIch bin der bessere Trainer von uns beiden, PLAYER. Das wissen wir wohl beide!"

str_after_battle_lost:
	.autostring 35 2 "Dass ich der bessere Trainer von uns beiden bin, wissen wir wohl beide, PLAYER.\pAber du hast dich gut geschlagen."

str_may_lost:
	.autostring 35 2 "I-Ich habe verlorenDOTS\pIch bin eine Schande für diese SchuleDOTS"

str_felix_won:
	.autostring 35 2 "Rede doch keinen Unsinn, Maike!\pDu hast gut gekämpft! Du brauchst nur etwas mehr Vertrauen in dich und deine Pokémon!"

str_announce_end:
	.autostring 35 2 "Ausgezeichnet! Damit sind wir auch schon am Ende der Prüfung angelangt.\pReiht euch wieder auf, dann teile ich euch eure Ergebnisse mit!"

str_final_call_felix:
	.autostring 35 2 "Felix, du bist wieder als Erster an der Reihe.\pKomm zu mir, Junge!"

str_award_felix:
	.autostring 35 2 "Im schriftlichen Test konntest du sieben Fragen richtig beantwortenDOTS\pAusgezeichnet!\pEin Pokémon zu fangen hat dir keine Probleme bereitet und deinen Kampf hast du gewonnen.\pGlückwunsch, du hast es geschafft, Bursche!\pAb heute darfst du dich einen Trainer nennen!"

str_felix_awarded:
	.autostring 35 2 "Hihi! Danke, Opi - ähm, Herr Faun!\pDu warst wirklich ein großartiger Lehrer!"

str_final_call_player:
	.autostring 35 2 "Machen wir mit dir weiter, PLAYER!\pAngetreten!"

.elseif LANG_EN

.endif

ow_script_trainerschool_lock_grass:
	lockall
	call lockout
	applymovement 0xFF mov_down
	waitmovement 0
	releaseall
	end

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
	loadpointer 0 str_trainerschool_say_goodbye
	show_mugshot MUGSHOT_PLAYER
	return

faun_not_arrived:
	loadpointer 0 str
	show_mugshot MUGSHOT_PLAYER
	return

receive_pkmn:
	loadpointer 0 str_receive_pkmn
	show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
	return

receive_pokeballs:
	loadpointer 0 str_receive_pkmn
	show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
	return

fight_wild_pokemon:
	loadpointer 0 str_fight_wild_pokemon
	show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT
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


ow_script_movs_0x899c63:
.byte FACE_DOWN
.byte SAY_EXCLAM
.byte STOP


ow_script_movs_0x899c67:
.byte LOOK_UP
.byte STOP


ow_script_map_3_57_trigger_0:
playsong MUS_RIVALE_ERSCHEINT_GARY 0x0
sound 0x15
applymovement 0x1 ow_script_movs_0x899c63
applymovement 0xff ow_script_movs_0x899c67
waitmovement 0x0
goto ow_script_0x89c06b


ow_script_movs_0x89bfe7:
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STEP_UP_FAST
.byte STOP


ow_script_0x89c06b:
loadpointer 0x0 str_0x89bfed
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT
applymovement 0x1 ow_script_movs_0x89bfe7
waitmovement 0x0
sound 0x9
hidesprite 0x1
checksound
fadesong MUS_TRAINERSCHOOL
setflag TRAINERSCHOOL_RIVAL
setvar STORY_PROGRESS 0x5
end


.ifdef LANG_GER

str_0x89bfed:
    .string "Na los! Die Schule hat längst\nangefangen. Faun wird uns Feuer\lunterm Hintern machen, wenn wir\luns nicht bald blicken lassen."


.elseif LANG_EN

.endif


ow_script_map_3_57_trigger_1:
lockall
playsong MUS_RIVALE_ERSCHEINT_GARY 0x0
pause 0x2c
goto ow_script_0x8f6dec


ow_script_movs_0x89c14d:
.byte LOOK_RIGHT
.byte SAY_EXCLAM
.byte STOP


ow_script_movs_0x89c14a:
.byte LOOK_LEFT
.byte STOP


ow_script_0x8f6dec:
sound 0x15
applymovement 0x1 ow_script_movs_0x89c14d
applymovement 0xff ow_script_movs_0x89c14a
waitmovement 0x0
goto ow_script_0x89c06b