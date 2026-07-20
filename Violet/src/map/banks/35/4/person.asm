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
	showsprite 2
	applymovement 0xFF mov_fd
	applymovement 1 mov_fd
	waitmovement 0
	playsong MUS_RIVALE_ERSCHEINT_GARY 0
	checksound
	pause 16
	loadpointer 0 str_0
	show_mugshot MUGSHOT_RIVAL MUGSHOT_LEFT
	applymovement 2 mov_1u
	waitmovement 0
	pause 20
	sound 0x15
	applymovement 2 mov_exclam
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
	applymovement 2 mov_1u
	waitmovement 0
	fadesong MUS_LAUBDORF
	pause 20
	npc_face_to_npc 0xFF 1
	loadpointer 0 str_5
	show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT emotion=MUGSHOT_HAPPY hide_mugshot=0 message_type=MSG_KEEPOPEN
	loadpointer 0 str_6
	update_mugshot_emotion MUGSHOT_NORMAL
	callstd MSG_KEEPOPEN
	hide_mugshot
	// goto jump_1
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
	applymovement 2 mov_exclam
	waitmovement 0
	checksound
	// goto jump_1
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
	npc_face_to_npc 0xFF 2
	waitmovement 0
	applymovement 2 mov_jump_in_place_2_times
	sound 10
	pause 16
	sound 10
	waitmovement 0
	checksound
	npc_face_to_npc 2 0xFF
	waitmovement 0
	loadpointer 0 str_22
	show_mugshot MUGSHOT_RIVAL MUGSHOT_LEFT emotion=MUGSHOT_HAPPY
	pause 24
	loadpointer 0 str_23
	show_mugshot MUGSHOT_RIVAL MUGSHOT_LEFT emotion=MUGSHOT_HAPPY
	playsong MUS_RIVALE_ERSCHEINT_GARY 0
	applymovement 2 mov_2d
	waitmovement 0
	pause 32
	applymovement 0xFF mov_fd
	applymovement 1 mov_fd
	waitmovement 0
	sound 9
	hidesprite 2
	checksound
	loadpointer 0 str_24
	show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT emotion=MUGSHOT_SHOCKED
	fadesong MUS_VERTANIA_CITY_AND_MARMORIA_CITY_AND_SAFFRONIA_CITY
	setvar 0x8004 1
	special SPECIAL_SET_TARGET_NPC_TO_VAR
	npc_face_to_npc 0xFF 1
	npc_face_to_npc 1 0xFF
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
	npc_move_to 1 4 7
	waitmovement 0
	applymovement 1 mov_fd
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
	.autostring 34 2 "PLAYER!\pDu warst als Erster hier?"
str_2:
	.autostring 34 2 "Dass so eine Schlafmütze wie du mich überholtDOTS"
str_3:
	.autostring 34 2 "RIVALDOTS\pKomm bitte einfach hierher, ja?"
str_4:
	.autostring 34 2 "Schon gut, Papa!"
str_5:
	.autostring 34 2 "Schön, dass ihr nun beide hier seid, PLAYER und RIVAL."
str_6:
	.autostring 34 2 "Ich werde euch nicht länger auf die Folter spannen.\pIch habe euch hergebeten, weil ich mich auf eine gefährliche Expedition begeben werde.\pVielleicht bin ich erst einmal eine ganze Weile unterwegs."
str_7:
	.autostring 34 2 "Eine Expedition?\pDas klingt ganz schön gefährlichDOTS"
str_8:
	.autostring 34 2 "Wie aufregend!"
str_9:
	.autostring 34 2 "Das ist eine Untertreibung!"
str_10:
	.autostring 34 2 "Ich bin schon seit einiger Zeit auf der Spur eines sagenumwobenen Relikts, das sich Alte Karte nennt.\pIm Grunde handelt es sich um einen Wegweiser, der einen direkt zur versunkenen Stadt Atlantea führen soll."
str_11:
	.autostring 34 2 "Die versunkene Stadt Atlantea?"
str_12:
	.autostring 34 2 "Aber gibt es die denn wirklich, Papa?\pIst das nicht bloß ein Märchen?"
str_13:
	.autostring 34 2 "Ganz ohne Zweifel sind viele der Erzählungen über diese Stadt mit der ein oder anderen Übertreibung ausgeschmücktDOTS"
str_14:
	.autostring 34 2 "Aber gleichzeitigDOTS\pGlaube ich fest daran, dass sie wirklich einmal existiert hat."
str_15:
	.autostring 34 2 "Von dieser Stadt könnten wir so viel über die Menschen lernen, die in Theto vor Jahrhunderten gelebt haben."
str_16:
	.autostring 34 2 "Eine versunkene Stadt zu erkundenDOTS\pDas hört sich nach einem tollen Abenteuer an!"
str_17:
	.autostring 34 2 "Und geführlich obendrein.\pEs ist mittlerweile recht riskant, in See zu stechenDOTS\pDie Blackbeard Piratenbande treibt auf dem Meer ihr UnwesenDOTS"
str_18:
	.autostring 34 2 "In Anbetracht der Gefahren, wollte ich mich von euch verabschieden, sollte ich nichtDOTS DOTS DOTS"
str_19:
	.autostring 34 2 "Alles klar, Papa!\pIch verstehe schon!"
str_20:
	.autostring 34 2 "Zu einem Abenteuer kann man nur ja sagen!"
str_21:
	.autostring 34 2 "Und wenn du herausfindest, wo diese versunkene Stadt liegtDOTS\pDann kann ich sie als Trainer erkunden!"
str_22:
	.autostring 34 2 "Da wird man ganz hibbelig!"
str_23:
	.autostring 34 2 "PLAYER!\pWir können hier nicht rumtrödeln!\pDa draußen warten neue Abenteuer auf uns!"
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
	.autostring 34 2 "Also melde dich doch bei ihr, bevor du dich wieder auf den Weg machst, ja?"
str_34:
	.autostring 34 2 "Mach's gut, PLAYER!\pBei unserem nächsten Treffen werde ich dir von der versunken Stadt Atlantea berichten!"

str_default_tann:
	.autostring 35 2 "Wie geht es dir, PLAYER?\pVerfolgst du immer noch deine Träume?\pLass dich auf deinem Weg von niemanden abhalten!"
str_0x843aba:
	.autostring 35 2 "Na siehst du?\pDu und deine Pokémon sehen schon wieder ganz fit aus!"
.elseif LANG_EN


.endif