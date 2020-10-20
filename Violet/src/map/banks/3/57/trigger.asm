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
trainerbattlelosable 0x9 0xb3 0x1 str_won str_lost
goto after_battle

fire_chosen:
trainerbattlelosable 0x9 0xb4 0x1 str_won str_lost
goto after_battle

water_chosen:
trainerbattlelosable 0x9 0xb5 0x1 str_won str_lost
goto after_battle

after_battle:
compare LASTRESULT 1
gotoif EQUAL lost_battle
won_battle:
loadpointer 0 str_after_battle_won
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT emotion=MUGSHOT_SCARED
may_felix_battle:
clearflag FLAG_SCRIPTED_WILD_BATTLES_LOSABLE
special 0x113
applymovement 0x7f mov_cam_to_may_felix
waitmovement 0x0
loadpointer 0 str_may_lost
show_mugshot MUGSHOT_MAY MUGSHOT_RIGHT emotion=MUGSHOT_SAD
loadpointer 0 str_felix_won
show_mugshot MUGSHOT_FELIX MUGSHOT_RIGHT message_type=MSG_KEEPOPEN emotion=MUGSHOT_ANGRY hide_mugshot=0
update_mugshot_emotion MUGSHOT_NORMAL
loadpointer 0 str_felix_won2
callstd MSG_KEEPOPEN
closeonkeypress
hide_mugshot
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
	.autostring 34 2 "Also dann, ihr Gören!\pEs geht ans Eingemachte!\pIhr tretet jetzt im Kampf gegeneinander an.\pWenn ihr diese Prüfung bestehen wollt, gebt ihr besser alles!"
str_rival_challange:
	.autostring 35 2 "Man PLAYER!\nWie lange ich auf diesen Moment gewartet habe!\pKeine leeren Sticheleien mehr!\pJetzt sehen wir, wer der Bessere ist!"
str_won:
	.autostring 35 2 "Moment!\nDas kann nicht sein!\pDu hast geschummelt, ich will nochmal!"
str_lost:
	.autostring 35 2 "Bist du davon überrascht?"
str_after_battle_won:
	.autostring 35 2 "Anfängerglück!\pIch war nicht ganz bei der Sache.\pAber ich gönne dir den Sieg natürlich.\pImmerhin wird es dein einziger gegen mich sein!"
str_after_battle_lost:
	.autostring 35 2 "Hah!\nHab ich dir nicht gesagt, dass ich der bessere Trainer bin?\pMach dir nichts draus, gegen mich zu verlieren ist keine Schande!"
str_may_lost:
	.autostring 35 2 "Ich wusste esDOTS\pIch tauge einfach nicht zum TrainerDOTS"
str_felix_won:
	.autostring 35 2 "Willst du nach einer Niederlage etwa schon aufgeben?"
str_felix_won2:
	.autostring 35 2 "Das würde Opi gar nicht gefallen!\pDu hast dich doch nicht schlecht geschlagen, Maike!"
str_announce_end:
	.autostring 35 2 "Sehr gut.\pDas war's auch schon!\pEin Kinderspiel, was?\pIch werde euch die Ergebnisse mitteilen!"
str_final_call_felix:
	.autostring 35 2 "Felix, du bist wieder als Erster an der Reihe.\pKomm zu mir, Junge!"
str_award_felix:
	.autostring 35 2 "Der schriftliche Test war keine Meisterleistung, aber du hast deinen Kampf gewonnen.\pDas sollte reichen, was?\pLass dir das aber nicht zu Kopf steigen!"
str_felix_awarded:
	.autostring 35 2 "Hihi!\nDanke, Opi!\pÄhm, ich meine natürlich Herr Faun!"
str_final_call_player:
	.autostring 35 2 "Machen wir mit dir weiter, PLAYER!\pAngetreten!"

.elseif LANG_EN

str_announce_battle:
	.autostring 34 2 "Well you brats!\pNow we get down to buisness!\pYou will battle each other!\pIf you plan to pass this exam I suggest you give it all!"
str_rival_challange:
	.autostring 35 2 "Hey, PLAYER!\pCan you imagine how long I have waited for this moment?\pNo empty banter anymore!\pNow we will find out who really is the better trainer!"
str_won:
	.autostring 35 2 "Wait a second!\nThat can't be!\pYou cheated!\nLet's repeat the fightDOTS"
str_lost:
	.autostring 35 2 "Are you really suprised?"
str_after_battle_won:
	.autostring 34 2 "Beginners luck!\pI just didn't focus that much.\pBut I will give you that victory, since it will be your only one against me!"
str_after_battle_lost:
	.autostring 35 2 "Hah!\nDidn't I tell you I'd win?\pDon't take it too seriously, losing against me is nothing be ashamed of!"
str_may_lost:
	.autostring 35 2 "Ich knew itDOTS\pI am just not good enough to be a trainerDOTS"
str_felix_won:
	.autostring 35 2 "Do you really want to give up after a single defeat?"
str_felix_won2:
	.autostring 35 2 "Grandpa surely wouldn't like that!\pYou didn't do bad at all, May!"
str_announce_end:
	.autostring 35 2 "Very well.\nThat's it!\pPiece of cake, right?\pI will give you the results now."
str_final_call_felix:
	.autostring 35 2 "Felix, you're first again.\pCome here, boy."
str_award_felix:
	.autostring 35 2 "Well, the written test wasn't that great, but you won your battle.\pI suppose that is sufficient.\pBut don't let that get to your head!"
str_felix_awarded:
	.autostring 35 2 "Hihi!\nThanks, grandpa!\pOh, I mean Mr. Faun, of course!"
str_final_call_player:
	.autostring 35 2 "Let's continue with you, PLAYER!"
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
	show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT emotion=MUGSHOT_ANGRY
	return

receive_pokeballs:
	loadpointer 0 str_receive_pkmn
	show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT emotion=MUGSHOT_ANGRY
	return

fight_wild_pokemon:
	loadpointer 0 str_fight_wild_pokemon
	show_mugshot MUGSHOT_FAUN MUGSHOT_LEFT emotion=MUGSHOT_ANGRY
	return

mov_up:
	.byte STEP_UP, STOP

mov_down:
	.byte STEP_DOWN, STOP

.ifdef LANG_GER
str:
    .autostring 35 2 "Ich sollte nicht zuweit weggehen, Faun wird jeden Moment hier seinDOTS"

str_receive_pkmn:
	.autostring 35 2 "Wo willst du denn hin, PLAYER!\pKomm gefälligst hierher!"

str_fight_wild_pokemon:
	.autostring 35 2 "Was ist los, PLAYER?\nFürchtest du dich etwa vor den wilden Pokémon?\pMach' keinen Unsinn und komm her!"

str_trainerschool_say_goodbye:
	.autostring 35 2 "Ich sollte mich von meinen Mitschülern verabschieden."

.elseif LANG_EN
str:
    .autostring 35 2 "I shouldn't go too far away, Faun will be here any momentDOTS"

str_receive_pkmn:
	.autostring 35 2 "Where are you going, PLAYER?\pGet yourself right here!"

str_fight_wild_pokemon:
	.autostring 35 2 "What's the deal, PLAYER?\pAfraid of the wild Pokémon?\pStop this nonsense and come here!"

str_trainerschool_say_goodbye:
	.autostring 35 2 "I should say goodbye to my classmates."

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
	.autostring 34 2 "Na los!\nWas dauert da denn so lange?\pDie Prüfung hat bestimmt schon angefangen!\pFaun wird uns Feuer unterm Hintern machen, wenn wir uns nicht bald blicken lassen!"
.elseif LANG_EN
str_0x89bfed:
	.autostring 34 2 "Come on!\nWhat's taking you so long?\pThe exam most likely has already started and Faun won't like us coming late at all!"
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