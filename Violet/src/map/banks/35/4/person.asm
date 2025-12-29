.include "ordinals.s"
.include "vars.s"
.include "movements.s"
.include "specials.s"
.include "callstds.s"
.include "songs.s"
.include "mugshot.s"
.include "overworld_script.s"
.include "flags.s"
.include "items.s"
.include "pathfinding.s"

.global ow_script_prof_tann_study

ow_script_prof_tann_study:
	lockall
	faceplayer
	checkflag FRBADGE_3
	gotoif EQUAL check_expedition1
expedition_announced:
	loadpointer 0x0 str_default_tann
	show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT
	releaseall
	end
check_expedition1:
	checkflag ROUTE_5_VIOLET_GRUNTS
	gotoif EQUAL expedition_announced
announce_expedition:
	loadpointer 0 str_expedition
	show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT
	sound 9
	clearflag PKMNMENU
	showsprite 4
	applymovement 0xFF mov_fd
	applymovement 1 mov_fd
	waitmovement 0
	playsong MUS_RIVALE_ERSCHEINT_GARY 0
	checksound
	pause 16
	loadpointer 0 str_0
	show_mugshot MUGSHOT_RIVAL MUGSHOT_LEFT
	applymovement 4 mov_3u
	waitmovement 0
	pause 20
	sound 0x15
	applymovement 4 mov_exclam
	waitmovement 0
	checksound
	loadpointer 0 str_1
	show_mugshot MUGSHOT_RIVAL MUGSHOT_LEFT emotion=MUGSHOT_SHOCKED hide_mugshot=0 message_type=MSG_KEEPOPEN
	update_mugshot_emotion MUGSHOT_ANNOYED
	loadpointer 0 str_2
	callstd MSG_KEEPOPEN
	hide_mugshot
	closeonkeypress
	loadpointer 0 str_3
	show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT
	loadpointer 0 str_4
	show_mugshot MUGSHOT_RIVAL MUGSHOT_LEFT emotion=MUGSHOT_ANNOYED
	// Move rival either in front of prof or right next to them
	getplayerpos 0x8004 0x8005
	compare 0x8004 7
	gotoif EQUAL move_rival_right
move_rival_in_front:
	npc_move_to 4 0x7 0x6
	applymovement 4 mov_fu
	waitmovement 0
	goto after_rival_there
move_rival_right:
	npc_move_to 4 0x8 0x6
	applymovement 4 mov_fu
	waitmovement 0
after_rival_there:
	fadesong MUS_VERTANIA_CITY_AND_MARMORIA_CITY_AND_SAFFRONIA_CITY
	pause 20
	setvar 0x8004 0xFF
	setvar 0x8005 1
	special SPECIAL_NPC_FACE_TO_NPC
	waitmovement 0
	loadpointer 0 str_5
	show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT emotion=MUGSHOT_HAPPY hide_mugshot=0 message_type=MSG_KEEPOPEN
	loadpointer 0 str_6
	update_mugshot_emotion MUGSHOT_NORMAL
	callstd MSG_KEEPOPEN
	hide_mugshot
	loadpointer 0 str_7
	show_mugshot MUGSHOT_RIVAL MUGSHOT_LEFT emotion=MUGSHOT_SHOCKED hide_mugshot=0 message_type=MSG_KEEPOPEN
	loadpointer 0 str_8
	update_mugshot_emotion MUGSHOT_HAPPY
	callstd MSG_KEEPOPEN
	hide_mugshot
	loadpointer 0 str_9
	show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT emotion=MUGSHOT_HAPPY hide_mugshot=0 message_type=MSG_KEEPOPEN
	loadpointer 0 str_10
	update_mugshot_emotion MUGSHOT_NORMAL
	callstd MSG_KEEPOPEN
	hide_mugshot
	closeonkeypress
	pause 16
	sound 0x15
	applymovement 4 mov_exclam
	waitmovement 0
	checksound
	loadpointer 0 str_11
	show_mugshot MUGSHOT_RIVAL MUGSHOT_LEFT emotion=MUGSHOT_SHOCKED hide_mugshot=0 message_type=MSG_KEEPOPEN
	loadpointer 0 str_12
	update_mugshot_emotion MUGSHOT_RUMINATIVE
	callstd MSG_KEEPOPEN
	hide_mugshot
	loadpointer 0 str_13
	show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT emotion=MUGSHOT_NORMAL hide_mugshot=0 message_type=MSG_KEEPOPEN
	loadpointer 0 str_14
	update_mugshot_emotion MUGSHOT_RUMINATIVE
	callstd MSG_KEEPOPEN
	loadpointer 0 str_15
	update_mugshot_emotion MUGSHOT_HAPPY
	callstd MSG_KEEPOPEN
	hide_mugshot
	loadpointer 0 str_16
	show_mugshot MUGSHOT_RIVAL MUGSHOT_LEFT emotion=MUGSHOT_HAPPY
	loadpointer 0 str_17
	show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT emotion=MUGSHOT_NORMAL hide_mugshot=0 message_type=MSG_KEEPOPEN
	loadpointer 0 str_18
	update_mugshot_emotion MUGSHOT_HAPPY
	callstd MSG_KEEPOPEN
	hide_mugshot
	loadpointer 0 str_19
	show_mugshot MUGSHOT_RIVAL MUGSHOT_LEFT hide_mugshot=0 message_type=MSG_KEEPOPEN
	loadpointer 0 str_20
	update_mugshot_emotion MUGSHOT_RUMINATIVE
	callstd MSG_KEEPOPEN
	loadpointer 0 str_21
	update_mugshot_emotion MUGSHOT_HAPPY
	callstd MSG_KEEPOPEN
	hide_mugshot
	closeonkeypress
	pause 12
	setvar 0x8004 0xFF
	setvar 0x8005 4
	special SPECIAL_NPC_FACE_TO_NPC
	waitmovement 0
	applymovement 4 mov_jump_in_place_2_times
	sound 10
	pause 16
	sound 10
	waitmovement 0
	checksound
	setvar 0x8004 4
	setvar 0x8005 0xFF
	special SPECIAL_NPC_FACE_TO_NPC
	waitmovement 0
	loadpointer 0 str_22
	show_mugshot MUGSHOT_RIVAL MUGSHOT_LEFT emotion=MUGSHOT_HAPPY
	pause 24
	loadpointer 0 str_23
	show_mugshot MUGSHOT_RIVAL MUGSHOT_LEFT emotion=MUGSHOT_HAPPY
	playsong MUS_RIVALE_ERSCHEINT_GARY 0
	getplayerpos 0x8004 0x8005
	compare 0x8004 7
	gotoif EQUAL move_rival_away_right
move_rival_away_in_front:
	applymovement 4 mov_rival_away_in_front
	goto rival_moved_away
move_rival_away_right:
	applymovement 4 mov_rival_away_right
	goto rival_moved_away
rival_moved_away:
	pause 32
	applymovement 0xFF mov_fd
	applymovement 1 mov_fd
	waitmovement 4
	sound 9
	hidesprite 4
	checksound
	loadpointer 0 str_24
	show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT emotion=MUGSHOT_SHOCKED
	fadesong MUS_VERTANIA_CITY_AND_MARMORIA_CITY_AND_SAFFRONIA_CITY
	setvar 0x8004 1
	special SPECIAL_SET_TARGET_NPC_TO_VAR
	setvar 0x8004 0xFF
	setvar 0x8005 1
	special SPECIAL_NPC_FACE_TO_NPC
	waitmovement 0
	setvar 0x8004 1
	setvar 0x8005 0xFF
	special SPECIAL_NPC_FACE_TO_NPC
	waitmovement 0
	loadpointer 0 str_25
	show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT emotion=MUGSHOT_ANNOYED hide_mugshot=0 message_type=MSG_KEEPOPEN
	loadpointer 0 str_26
	update_mugshot_emotion MUGSHOT_NORMAL
	callstd MSG_KEEPOPEN
	loadpointer 0 str_27
	update_mugshot_emotion MUGSHOT_HAPPY
	callstd MSG_KEEPOPEN
	loadpointer 0 str_28
	update_mugshot_emotion MUGSHOT_RUMINATIVE
	callstd MSG_KEEPOPEN
	loadpointer 0 str_29
	update_mugshot_emotion MUGSHOT_HAPPY
	callstd MSG_KEEPOPEN
	loadpointer 0 str_30
	update_mugshot_emotion MUGSHOT_RUMINATIVE
	callstd MSG_KEEPOPEN
	loadpointer 0 str_31
	update_mugshot_emotion MUGSHOT_NORMAL
	callstd MSG_KEEPOPEN
	loadpointer 0 str_32
	update_mugshot_emotion MUGSHOT_ANNOYED
	callstd MSG_KEEPOPEN
	loadpointer 0 str_33
	update_mugshot_emotion MUGSHOT_NORMAL
	callstd MSG_KEEPOPEN
	loadpointer 0 str_34
	update_mugshot_emotion MUGSHOT_HAPPY
	callstd MSG_KEEPOPEN
	closeonkeypress
	hide_mugshot
	npc_move_to 1 0x7 0x7
	applymovement 0xFF mov_fd
	applymovement 1 mov_4d
	waitmovement 0
	pause 16
	sound 9
	hidesprite 1
	checksound
	releaseall
	end


mov_jump_in_place_2_times:
	.byte JUMP_IN_PLACE_FACE_UP, JUMP_IN_PLACE_FACE_UP, STOP
mov_rival_away_in_front:
	.byte STEP_DOWN_FAST, STEP_DOWN_FAST, STEP_DOWN_FAST, STEP_DOWN_FAST, STEP_DOWN_FAST, STEP_DOWN_FAST, STOP
mov_rival_away_right:
	.byte STEP_DOWN_FAST, STEP_DOWN_FAST, STEP_LEFT_FAST, STEP_DOWN_FAST, STEP_DOWN_FAST, STEP_DOWN_FAST, STEP_DOWN_FAST, STOP


.ifdef LANG_GER

str_expedition:
	.autostring 34 2 "PLAYER!\nDa bist du ja!\pRIVAL sollte auch jeden Moment-"
str_0:
	.autostring 34 2 "So Papa!\nDa bin ich!"
str_1:
	.autostring 34 2 "PLAYER!\pSoll das etwa heißen, dass du schon vor mir hier warst?"
str_2:
	.autostring 34 2 "Dass eine Schlafmütze mich überholt haben sollDOTS"
str_3:
	.autostring 34 2 "RIVALDOTS\pKomm bitte einfach hierher, ja?"
str_4:
	.autostring 34 2 "Schon gut, Papa!"
str_5:
	.autostring 34 2 "Schön, dass ihr nun beide hier seid, PLAYER und RIVAL."
str_6:
	.autostring 34 2 "Ich will euch auch gar nicht länger auf die Folter spannen und euch sagen, warum ihr hier seid.\pIch werde mich auf eine gefährliche Expedition begeben.\pVielleicht bin ich erst einmal eine ganze Weile unterwegs."
str_7:
	.autostring 34 2 "Eine Expedition?\pDas klingt ganz schön gefährlichDOTS"
str_8:
	.autostring 34 2 "Aber auch super aufregend!"
str_9:
	.autostring 34 2 "Das ist eine Untertreibung!"
str_10:
	.autostring 34 2 "Ich bin schon seit einiger Zeit auf der Spur eines sagenumwobenen Relikts names Alte Karte.\pIm Grunde handelt es sich dabei um einen Wegweiser, der einen direkt zur versunkenen Stadt Atlantea führen soll."
str_11:
	.autostring 34 2 "Die versunkene Stadt Atlantea?"
str_12:
	.autostring 34 2 "Aber gibt es die denn wirklich, Papa?\pIch dachte immer, das wäre bloß ein Märchen."
str_13:
	.autostring 34 2 "Ganz ohne Zweifel sind viele der Erzählungen über diese Stadt mit der ein oder anderen Übertreibung ausgeschmücktDOTS"
str_14:
	.autostring 34 2 "Aber gleichzeitigDOTS\pGibt es auch viele Hinweise darauf, dass es eine solche Stadt tatsächlich einmal gegeben hat."
str_15:
	.autostring 34 2 "Und ist es nicht aufregend, nach dieser Stadt zu suchen?\pWir könnten so viel über die Menschen lernen, die in Theto vor Jahrhunderten gelebt haben."
str_16:
	.autostring 34 2 "Eine versunkene Stadt zu erkundenDOTS\pDas hört sich nach einem tollen Abenteuer an!"
str_17:
	.autostring 34 2 "Aber es bedeutet auch, dass ich mich einigen Gefahren aussetzen muss.\pIn letzter Zeit ist es immer gefährlicher geworden, in See zu stechenDOTS\pDie Blackbeard Piratenbande treibt auf dem Meer ihr UnwesenDOTS\pUnd ich weiß nicht, wie lange mich diese Expedition beschäftigen wird."
str_18:
	.autostring 34 2 "Und ich kann natürlich nicht einfach gehen, ohne mich von euch zu verabschieden, oder?"
str_19:
	.autostring 34 2 "Alles klar, Papa!\pIch verstehe schon!"
str_20:
	.autostring 34 2 "Das Abenteuer liegt bei uns in der Familie!"
str_21:
	.autostring 34 2 "Und außerdem ist das perfekt.\pWenn du herausfindest, wo diese versunkene Stadt liegtDOTS\pDann kann ich sie als erster Trainer erkunden!"
str_22:
	.autostring 34 2 "Da wird man ganz hibbelig!"
str_23:
	.autostring 34 2 "PLAYER!\pWir haben keine Zeit, hier herumzutrödeln.\pDa draußen warten unzählige Abenteuer auf uns!"
str_24:
	.autostring 34 2 "J-Jetzt warte doch 'mal, RIVAL!"
str_25:
	.autostring 34 2 "Das ist mal wieder typischDOTS"
str_26:
	.autostring 34 2 "Aber zumindest von dir kann ich mich ordentlich verabschieden, PLAYER."
str_27:
	.autostring 34 2 "Pass auf dich auf, ja?"
str_28:
	.autostring 34 2 "Und wenn wir schon dabei sindDOTS"
str_29:
	.autostring 34 2 "Pass bitte auch auf RIVAL auf, ja?\pDu siehst ja, dass sein Hitzkopf manchmal etwas mit ihm durchgehtDOTS"
str_30:
	.autostring 34 2 "Und bevor ich es vergesseDOTS"
str_31:
	.autostring 34 2 "Meine Assistentin Elise wollte euch beide auch noch sprechen.\pEs klang so, als hätte sie etwas für euch."
str_32:
	.autostring 34 2 "Aber RIVAL ist wohl schon längst über alle BergeDOTS"
str_33:
	.autostring 34 2 "Also sei doch so lieb und sprich wenigstens du mit ihr, bevor du dich wieder auf den Weg machst, ja?"
str_34:
	.autostring 34 2 "Bis dann, PLAYER!\pVielleicht kann ich dir bei unserem nächsten Treffen die sagenumwobene versunkene Stadt Atlantea zeigen!\pHalt die Ohren steif!"

str_default_tann:
	.autostring 35 2 "Wie geht es dir, PLAYER?\pVerfolgst du immer noch deine Träume?\pLass dich auf deinem Weg von niemanden abhalten!"
str_0x843aba:
	.autostring 35 2 "Na siehst du?\pDu und deine Pokémon sehen schon wieder ganz fit aus!"
.elseif LANG_EN


.endif