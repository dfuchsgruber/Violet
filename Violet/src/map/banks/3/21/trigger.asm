.include "ordinals.s"
.include "vars.s"
.include "movements.s"
.include "callstds.s"
.include "mugshot.s"
.include "flags.s"
.include "overworld_script.s"
.include "items.s"
.include "pathfinding.s"

.global ow_script_felsige_oednis_may_trigger

ow_script_felsige_oednis_may_trigger:
	lockall
	applymovement 0xFF mov_fd
	waitmovement 0
	sound 0x15
	setvar 0x8004 1
	setvar LASTTALKED 1 
	special SPECIAL_SET_TARGET_NPC_TO_VAR
	applymovement 1 mov_fu
	waitmovement 0
	applymovement 1 mov_exclam
	waitmovement 0
	checksound
	npc_move_to_player 1
	applymovement 1 mov_fu
	waitmovement 0
	loadpointer 0 str_0
	show_mugshot MUGSHOT_MAY MUGSHOT_LEFT hide_mugshot=0 message_type=MSG_KEEPOPEN
	update_mugshot_emotion MUGSHOT_HAPPY
	loadpointer 0 str_1
	callstd MSG_KEEPOPEN
	update_mugshot_emotion MUGSHOT_HAPPY
	loadpointer 0 str_2
	callstd MSG_KEEPOPEN
	update_mugshot_emotion MUGSHOT_SAD
	loadpointer 0 str_3
	callstd MSG_KEEPOPEN
	update_mugshot_emotion MUGSHOT_SERIOUS
	loadpointer 0 str_4
	callstd MSG_KEEPOPEN
	update_mugshot_emotion MUGSHOT_SAD
	loadpointer 0 str_5
	callstd MSG_KEEPOPEN
	update_mugshot_emotion MUGSHOT_SERIOUS
	loadpointer 0 str_6
	callstd MSG_KEEPOPEN
	update_mugshot_emotion MUGSHOT_SAD
	compare STARTER_SELECTED 0x0
	gotoif EQUAL plant_starter
	compare STARTER_SELECTED 0x1
	gotoif EQUAL fire_starter
water_starter:
	trainerbattlecont 0x1 0x5e 0x0 str_before str_after later
plant_starter:
	trainerbattlecont 0x1 0x5c 0x0 str_before str_after later
fire_starter:
	trainerbattlecont 0x1 0x5d 0x0 str_before str_after later
later:
	loadpointer 0 str_7
	show_mugshot MUGSHOT_MAY MUGSHOT_LEFT hide_mugshot=0 message_type=MSG_KEEPOPEN emotion=MUGSHOT_SAD
	update_mugshot_emotion MUGSHOT_ANGRY
	loadpointer 0 str_8
	callstd MSG_KEEPOPEN
	update_mugshot_emotion MUGSHOT_NORMAL
	loadpointer 0 str_9
	callstd MSG_KEEPOPEN
	update_mugshot_emotion MUGSHOT_SAD
	loadpointer 0 str_10
	callstd MSG_KEEPOPEN
	update_mugshot_emotion MUGSHOT_NORMAL
	loadpointer 0 str_11
	callstd MSG_KEEPOPEN
	update_mugshot_emotion MUGSHOT_SAD
	loadpointer 0 str_12
	callstd MSG_KEEPOPEN
	update_mugshot_emotion MUGSHOT_HAPPY
	loadpointer 0 str_13
	callstd MSG_KEEPOPEN
	hide_mugshot
	copyvarifnotzero 0x8000 ITEM_VM05
	copyvarifnotzero 0x8001 1
	callstd ITEM_OBTAIN
	loadpointer 0 str_14
	show_mugshot MUGSHOT_MAY MUGSHOT_LEFT hide_mugshot=0 message_type=MSG_KEEPOPEN emotion=MUGSHOT_NORMAL
	update_mugshot_emotion MUGSHOT_SAD
	loadpointer 0 str_15
	callstd MSG_KEEPOPEN
	closeonkeypress
	hide_mugshot
	pause 16
	applymovement 1 mov_1d
	waitmovement 0
	pause 32
	applymovement 1 mov_fu
	waitmovement 0
	pause 16
	loadpointer 0 str_16
	show_mugshot MUGSHOT_MAY MUGSHOT_LEFT hide_mugshot=0 message_type=MSG_KEEPOPEN emotion=MUGSHOT_NORMAL
	update_mugshot_emotion MUGSHOT_SERIOUS
	loadpointer 0 str_17
	callstd MSG_KEEPOPEN
	update_mugshot_emotion MUGSHOT_SAD
	loadpointer 0 str_18
	callstd MSG_KEEPOPEN
	update_mugshot_emotion MUGSHOT_HAPPY
	loadpointer 0 str_19
	callstd MSG_KEEPOPEN
	update_mugshot_emotion MUGSHOT_NORMAL
	loadpointer 0 str_20
	callstd MSG_KEEPOPEN
	closeonkeypress
	hide_mugshot
	applymovement 1 mov_5d
	waitmovement 0
	hidesprite 1
	addvar STORY_PROGRESS 0x1
	setworldmapflag WM_DESERT_VILLAGE
	releaseall
	end

.ifdef LANG_GER
str_0:
	.autostring 34 2 "Hallo, PLAYER!"
str_1:
	.autostring 34 2 "Du hast es wohl auch aus dieser finsteren Höhle herausgeschafft?\pIch will dir deine Laune ja nicht verderbenDOTS"
str_2:
	.autostring 34 2 "Aber diese Wüste ist auch nicht gerade besserDOTS"
str_3:
	.autostring 34 2 "Oh, übrigens, PLAYERDOTS"
str_4:
	.autostring 34 2 "Ich habe sehr viel trainiert!\pIch bin jetzt viel stärker geworden!"
str_5:
	.autostring 34 2 "IchDOTS\nDOTS DOTS DOTS\pI-Ich glaube ich kann dich besiegen, PLAYER!"
str_6:
	.autostring 34 2 "Ich will gegen dich kämpfen!\pIch will dir beweisen, dass ich als Trainer zu etwas tauge!"
str_before:
	.autostring 34 2 "W-was sagst du, PLAYER?"
str_after:
	.autostring 34 2 "I-Ich habe verlorenDOTS\pNach dem ganzen Training habe ich trotzdem wieder verlorenDOTS"
str_7:
	.autostring 34 2 "Ich fasse es nichtDOTS\pIch habe so viel Zeit und Mühe in mein Training gesteckt.\pIch habe alles gegebenDOTS"
str_8:
	.autostring 34 2 "Und trotzdem habe ich wieder verloren!"
str_9:
	.autostring 34 2 ".TEXT_DELAY_LONG.TEXT_DELAY_LONG.TEXT_DELAY_LONG\pEntschuldige bitte, PLAYER.\pIch bin nur einfach frustriert, denke ich."
str_10:
	.autostring 34 2 "Aber so ist das nun einmal!\pManche Trainer sind eben stärker als andere.\pUnd du bist mir wohl immer einen Schritt voraus."
str_11:
	.autostring 34 2 "Und außerdem habe ich noch etwas für dich, PLAYER."
str_12:
	.autostring 34 2 "Eigentlich wollte ich dir das als Trostpreis überreichenDOTS"
str_13:
	.autostring 34 2 "Aber sieh es jetzt einfach als Preis für deinen Sieg, ja?"
str_14:
	.autostring 34 2 "Mit der VM Blitz kommst du kinderleicht durch dunkle Höhlen.\pJe stärker das Pokémon ist, das die Attacke benutzt, desto heller wird es!"
str_15:
	.autostring 34 2 "In deinen Händen ist diese VM sowieso viel besser aufgehoben als in meinen, was?\pDOTS DOTS DOTS\nDOTS DOTS DOTS"
str_16:
	.autostring 34 2 "Es war schön, dich einmal wieder zu sehen, PLAYER!\pEhrlich!\nObwohl du mich besiegt hast.\pI-IchDOTS\nDOTS DOTS DOTS"
str_17:
	.autostring 34 2 "Ich werde umso härter an mir arbeiten, dich beim nächsten Mal schlagen zu können!"
str_18:
	.autostring 34 2 "DOTS DOTS DOTS\pUnd wenn ich das nicht schaffeDOTS\p.TEXT_DELAY_LONG.TEXT_DELAY_LONG.TEXT_DELAY_LONG"
str_19:
	.autostring 34 2 "Ach!\nIch werde schon zurecht kommen, oder?"
str_20:
	.autostring 34 2 "Pass auf dich auf, PLAYER!"
.elseif LANG_EN
.endif
