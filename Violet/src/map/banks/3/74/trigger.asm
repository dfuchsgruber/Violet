.include "ordinals.s"
.include "vars.s"
.include "movements.s"
.include "songs.s"
.include "callstds.s"
.include "mugshot.s"
.include "flags.s"
.include "overworld_script.s"
.include "items.s"
.include "pathfinding.s"

.global ow_script_0x8e33a7
.global ow_script_0x8e63a6
.global ow_script_0x8fb3fe
.global ow_script_map_3_74_trigger_0
.global ow_script_0x8e33bb
.global ow_script_0x8e63b7

ow_script_movs_0x8e63b5:
.byte STEP_RIGHT
.byte STOP


ow_script_movs_0x8e63a3:
.byte LOOK_LEFT
.byte STOP


ow_script_movs_0x8e639b:
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STEP_RIGHT
.byte STOP

mov_fl:
	.byte LOOK_LEFT, STOP
mov_fr:
	.byte LOOK_RIGHT, STOP

ow_script_map_3_74_trigger_0:
	lockall
	clearflag PKMNMENU
	showsprite 0x11
	setflag PKMNMENU
	playsong MUS_RIVALE_ERSCHEINT_GARY 0x0
	npc_move_to_player 0x11
	applymovement 0xFF mov_fr
	applymovement 0x11 mov_fl
	waitmovement 0
	checkflag FLAG_FELSIGE_OEDNIS_RIVAL_SKIP_DIALOG
	gotoif EQUAL skipped_dialog
	setflag FLAG_FELSIGE_OEDNIS_RIVAL_SKIP_DIALOG
	loadpointer 0 str_0
	show_mugshot MUGSHOT_RIVAL alignment=MUGSHOT_RIGHT hide_mugshot=0 message_type=MSG_KEEPOPEN
	update_mugshot_emotion MUGSHOT_RUMINATIVE
	loadpointer 0 str_1
	callstd MSG_KEEPOPEN
	update_mugshot_emotion MUGSHOT_HAPPY
	loadpointer 0 str_2
	callstd MSG_KEEPOPEN
	loadpointer 0 str_3
	callstd MSG_KEEPOPEN
	update_mugshot_emotion MUGSHOT_ANGRY
	loadpointer 0 str_4
	callstd MSG_KEEPOPEN
	update_mugshot_emotion MUGSHOT_HAPPY
	loadpointer 0 str_5
	update_mugshot_emotion MUGSHOT_NORMAL
	compare STARTER_SELECTED 0
	gotoif EQUAL plant_starter
	compare STARTER_SELECTED 1
	gotoif EQUAL fire_starter
water_starter:
	trainerbattlecont 1 0xbb 0 str_6 str_after later
plant_starter:
	trainerbattlecont 1 0xb9 0 str_6 str_after later
fire_starter:
	trainerbattlecont 1 0xba 0 str_6 str_after later

skipped_dialog:
	compare STARTER_SELECTED 0
	gotoif EQUAL plant_starter_skipped
	compare STARTER_SELECTED 1
	gotoif EQUAL fire_starter_skipped
water_starter_skipped:
	trainerbattlecont 1 0xbb 0 str_10 str_after later
plant_starter_skipped:
	trainerbattlecont 1 0xb9 0 str_10 str_after later
fire_starter_skipped:
	trainerbattlecont 1 0xba 0 str_10 str_after later

later:
	loadpointer 0 str_7 
	show_mugshot MUGSHOT_RIVAL alignment=MUGSHOT_RIGHT message_type=MSG_KEEPOPEN emotion=MUGSHOT_SHOCKED hide_mugshot=0
	loadpointer 0 str_8
	update_mugshot_emotion MUGSHOT_NORMAL
	callstd MSG_KEEPOPEN
	update_mugshot_emotion MUGSHOT_HAPPY
	loadpointer 0 str_9
	callstd MSG_KEEPOPEN
	hide_mugshot
	closeonkeypress
	npc_move_to 0x11 0x11 0x10
	hidesprite 0x11
	addvar STORY_PROGRESS 1
	releaseall
	end









.ifdef LANG_GER
str_0:
	.autostring 34 2 "PLAYER!\pWas für ein Zufall!\pEben läuft mir Felix über den Weg und jetzt treffe ich dich.\pWas sagt man dazu!\pFindest du es nicht verrückt, dass Felix sich der Polizei angeschlossen hat?"
str_1:
	.autostring 34 2 "WobeiDOTS\pEr hatte schon immer irgendwie das Bedürfnis, anderen zu helfenDOTS"
str_2:
	.autostring 34 2 "Vielleicht ist es doch gar nicht so verrückt, wie ich dachte!"
str_3:
	.autostring 34 2 "Aber er hat mir gesagt, dass er hier einen Kommandanten von Team Violet stellen will."
str_4:
	.autostring 34 2 "Ich hab' mit diesen Leuten noch eine Rechnung offen, seit sie meinen Papa auf Route 2 so angegangen sind."
str_5:
	.autostring 34 2 "Das heißt, dass wir beide diesem Kommandanten ordentlich zeigen, wo es lang geht, oder?"
str_6:
	.autostring 34 2 "Aber vermutlich bist du so schwach, dass du mir nur im Weg stehstDOTS\pLass uns einmal sehen, wie gut du geworden bist!"
str_after:
	.autostring 34 2 "Urgh\nDas war ein Ausrutscher!"
str_7:
	.autostring 34 2 "Wie konnte das denn passieren?"
str_8:
	.autostring 34 2 "Da hast du mich wohl ganz kalt erwischt!\pAber normalerweise wäre mir das nicht passiert!\pDOTS DOTS DOTS\nDOTS DOTS DOTS"
str_9:
	.autostring 34 2 "Aber du bist auf jeden Fall stark genug, um den Team Violet Leuten eins auf die Mütze zu geben!\pLass uns keine Zeit verlieren, und diesen elenden Kommandanten finden!\pIch werde ihn ganz sicher vor dir besiegt haben!"
str_10:
	.autostring 34 2 "Na, da bist du ja wieder, PLAYER!\pInzwischen hoffentlich etwas besser vorbereitet, ja?"
.elseif LANG_EN

.endif