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

.global ow_script_map_3_66_person_0
.global ow_script_map_3_66_person_2
.global ow_script_0x8a5ccb
.global ow_script_0x8a7343
.global ow_script_map_3_66_person_1

ow_script_map_3_66_person_0:
	lockall
	faceplayer
	checkflag FRBADGE_3
	gotoif EQUAL check_expedition1
expedition_announced:
	loadpointer 0x0 str_0x843a47
	show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT emotion=MUGSHOT_SHOCKED
	call ow_script_healing_sequence
	// playsong MUS_VERTANIA_CITY_AND_MARMORIA_CITY_AND_SAFFRONIA_CITY 0x0
	loadpointer 0x0 str_0x843aba
	show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT MSG_FACE
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

/* 
	applymovement 4 mov_fu
	waitmovement 0
	loadpointer 0 str_1
	show_mugshot MUGSHOT_RIVAL MUGSHOT_LEFT
	applymovement 1 mov_fd
	waitmovement 0
	loadpointer 0 str_2
	show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT
	loadpointer 0 str_3
	show_mugshot MUGSHOT_RIVAL MUGSHOT_LEFT
	pause 16
	loadpointer 0 str_4
	show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT
	loadpointer 0 str_5
	show_mugshot MUGSHOT_RIVAL MUGSHOT_LEFT
	applymovement 4 mov_rival_away
	waitmovement 0
	pause 32
	applymovement 4 mov_fu
	waitmovement 0
	loadpointer 0 str_6
	show_mugshot MUGSHOT_RIVAL MUGSHOT_LEFT
	applymovement 4 mov_fd
	waitmovement 0
	pause 32
	hidesprite 4
	sound 9
	checksound
	pause 32
	faceplayer
	loadpointer 0 str_7
	show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT
	npc_move_to 1 0x7 0xB
	applymovement 1 mov_fd
	waitmovement 0
	pause 16
	sound 9
	hidesprite 1
	checksound
	fadesong MUS_VERTANIA_CITY_AND_MARMORIA_CITY_AND_SAFFRONIA_CITY
	pause 64
	setvar 0x8004 2
	special SPECIAL_SET_TARGET_NPC_TO_VAR
	npc_move_to 2 0x7 0x5
	lock
	faceplayer
	loadpointer 0 str_8
	show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT
	copyvarifnotzero 0x8000 ITEM_ZUGANGSKARTE
	copyvarifnotzero 0x8001 1
	callstd ITEM_OBTAIN
	loadpointer 0 str_9
	show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT
	npc_move_to 2 0x7 0xB
	applymovement 2 mov_fd
	waitmovement 0
	pause 16
	sound 9
	hidesprite 2
	checksound
	setflag ROUTE_5_VIOLET_GRUNTS
	clearflag MERIANA_CITY_ELISE_VISIBLE // makes her disappear
	releaseall
	end
*/

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
	.autostring 34 2 "Ihr wisst vermutlich schon, warum ich euch herbestellt habe, oder?\pIch werde mich auf eine gefährliche Expedition begeben.\pVielleicht bin ich erst einmal eine ganze Weile unterwegs."
str_7:
	.autostring 34 2 "Eine Expedition?\pDas klingt ganz schön gefährlichDOTS"
str_8:
	.autostring 34 2 "Aber auch super aufregend!\pWohin geht diese Expedition denn, Papa?"
str_9:
	.autostring 34 2 "Freut mich, dass du frägst, RIVAL."
str_10:
	.autostring 34 2 "Ich bin schon seit einiger Zeit auf der Spur eines sagenumwobenen Relikts, das man oft einfach als Alte Karte bezeichnet.\pIm Grunde handelt es sich dabei um einen Wegweiser, der einen direkt zur versunkenen Stadt Atlantea führen soll."
str_11:
	.autostring 34 2 "Die versunkene Stadt Atlantea?"
str_12:
	.autostring 34 2 "Aber gibt es die denn wirklich, Papa?\pIch dachte immer, das wäre bloß eine Geschichte."
str_13:
	.autostring 34 2 "Das weiß niemand so genau, RIVAL.\pSicherlich ist die Legende der versunkenen Stadt Atlantea auch einfach ein Seefahrermärchen.\pUnd viele der Erzählungen davon sind vermutlich mit einigen Übertreibungen ausgeschmückt."
str_14:
	.autostring 34 2 "Aber gleichzeitigDOTS\pGibt es auch viele Hinweise darauf, dass es eine solche Stadt tatsächlich einmal gegeben haben könnte."
str_15:
	.autostring 34 2 "Und wie aufregend es wäre, wenn jemand diese Stadt entdecken würde!\pWir könnten so viel über die Menschen lernen, die in Theto vor Jahrhunderten gelebt haben."
str_16:
	.autostring 34 2 "So eine versunkene Stadt zu erkundenDOTS\pDas hört sich nach einem aufregenden Abenteuer an!"
str_17:
	.autostring 34 2 "Aber das bedeutet auch, dass ihr mich erst einmal eine Weile nicht sehen werdet.\pVielleicht bin ich für Wochen oder sogar Monate unterwegs."
str_18:
	.autostring 34 2 "Und ich kann natürlich nicht einfach gehen, ohne mich von euch zu verabschieden, oder?"
str_19:
	.autostring 34 2 "Alles klar, Papa!\pIch verstehe schon!\nDu gehst jetzt auch auf ein Abenteuer."
str_20:
	.autostring 34 2 "Das liegt wohl bei uns in der Familie!"
str_21:
	.autostring 34 2 "Und außerdem ist das perfekt.\pDu findest diese versunkene Stadt und dann werde ich der Trainer sein, der sie erkundet."
str_22:
	.autostring 34 2 "Ich bin ja sowas von aufgeregt!"
str_23:
	.autostring 34 2 "Also, worauf warten wir noch, PLAYER?\pDa draußen warten Abenteuer auf uns!"
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
	.autostring 34 2 "Kannst du am besten auch gleich noch auf RIVAL aufpassen."
str_30:
	.autostring 34 2 "Und bevor ich es vergesseDOTS"
str_31:
	.autostring 34 2 "Meine Assistentin Elise wollte dich und RIVAL noch sprechen.\pEs klang so, als hätte sie etwas für euch."
str_32:
	.autostring 34 2 "Aber RIVAL ist wohl schon längst über alle BergeDOTS"
str_33:
	.autostring 34 2 "Also sei doch so lieb und sprich mit ihr, bevor du dich wieder auf den Weg machst, ja?"
str_34:
	.autostring 34 2 "Bis dann, PLAYER!\pVielleicht sehen wir uns beim nächsten Mal ja in der versunkenen Stadt Atlantea wieder.\pHalt die Ohren steif!"

str_0x843a47:
	.autostring 35 2 "Du und deine Pokémon sehen ja schrecklich erschöpft aus!\pSetz dich doch noch einmal eine Weile hin und ruh dich aus!"
str_0x843aba:
	.autostring 35 2 "Na siehst du?\pDu und deine Pokémon sehen schon wieder ganz fit aus!"


.elseif LANG_EN

str_0x843a47:
	.autostring 34 2 "You and your Pokémon look terribly exhausted!\pTake a set and get some rest, what do you think?"
str_0x843aba:
	.autostring 34 2 "See?\pYou and your Pokémon are look quite fit again!"

.endif


ow_script_map_3_66_person_2:
loadpointer 0x0 str_0x8a679f
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT MSG_FACE emotion=MUGSHOT_HAPPY
end


.ifdef LANG_GER

str_0x8a679f:
	.autostring 35 2 "Ich werde ganz sicher mehr Pokémon in meiner Pokédex-App registrieren als du!"
.elseif LANG_EN

str_0x8a679f:
	.autostring 35 2 "Ich will definitely register way more Pokémon in my Pokédex-App than you!"
.endif

ow_script_map_3_66_person_1:
	lock
	faceplayer
	checkflag FRBADGE_3
	gotoif EQUAL check_expedition
	checkflag WONDERTRADE
	gotoif EQUAL ow_script_0x8a5ccb
	call ow_script_0x8a7343
	release
	end

check_expedition:
    checkflag ROUTE_5_VIOLET_GRUNTS
    gotoif EQUAL ow_script_0x8a7343
	checkflag FLAG_PROFESSOR_TANN_GONE
	gotoif EQUAL elise_give_access_card
    loadpointer 0 str_expedition2
    show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT
    release
    end

elise_give_access_card:
	loadpointer 0 str_elise_0
	show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT hide_mugshot=0 message_type=MSG_KEEPOPEN
	loadpointer 0 str_elise_1
	update_mugshot_emotion MUGSHOT_ANNOYED
	callstd MSG_KEEPOPEN
	loadpointer 0 str_elise_2
	update_mugshot_emotion MUGSHOT_HAPPY
	callstd MSG_KEEPOPEN
	closeonkeypress
	hide_mugshot
	copyvarifnotzero 0x8000 ITEM_ZUGANGSKARTE
	copyvarifnotzero 0x8001 1
	callstd ITEM_OBTAIN
	loadpointer 0 str_elise_3
	show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT hide_mugshot=0 message_type=MSG_KEEPOPEN
	loadpointer 0 str_elise_4
	update_mugshot_emotion MUGSHOT_HAPPY
	callstd MSG_KEEPOPEN
	loadpointer 0 str_elise_5
	update_mugshot_emotion MUGSHOT_NORMAL
	callstd MSG_KEEPOPEN
	loadpointer 0 str_elise_6
	update_mugshot_emotion MUGSHOT_RUMINATIVE
	callstd MSG_KEEPOPEN
	loadpointer 0 str_elise_7
	update_mugshot_emotion MUGSHOT_NORMAL
	callstd MSG_KEEPOPEN
	closeonkeypress
	hide_mugshot
	npc_move_to 2 0x7 0xa
	applymovement 2 mov_1d
	waitmovement 0
	pause 16
	sound 9
	hidesprite 2
	checksound
	setflag ROUTE_5_VIOLET_GRUNTS
	clearflag MERIANA_CITY_ELISE_VISIBLE // makes her disappear
	releaseall
	end

ow_script_0x8a7343:
	loadpointer 0x0 str_0x8aac71
	show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT
	fanfare 0x13e
	loadpointer 0x0 str_0x8aa801
	callstd MSG_KEEPOPEN
	closeonkeypress
	waitfanfare
	setflag WONDERTRADE
	loadpointer 0x0 str_0x8ab119
	show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT MSG_FACE
	setvar STORY_PROGRESS 0x10
	return


ow_script_0x8a5ccb:
	loadpointer 0x0 str_0x8a7951
	show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT
	release
	end


.ifdef LANG_GER

str_0x8aac71:
	.autostring 34 2 "Ach, PLAYER!\pIch hätte beinahe vergessen, dass auch ich für euch ein Geschenk habe.\pVor einiger Zeit habe ich ein System entwickelt, dass es Trainern erleichtert, Pokémon miteinander zu tauschen.\pIch habe das ganze Wundertausch genannt und um ehrlich zu sein, ich finde, dass es eine meiner besseren Ideen ist.\pMan bietet eines seiner Pokémon zum Tausch an.\pDann wird es einem zufälligen Trainer irgendwo auf der Welt zugesandt und man im Gegenzug eines seiner Pokémon.\pDas Aufregende dabei ist, dass man nie genau weiß, welches Pokémon man erhält.\pWenn du dieses System nutzt, wird es dir sicherlich noch viel leichter fallen, Daten für den Pokédex zu sammeln.\pIch werde jetzt die Wundertausch-App auf deinem Poképad installieren!"
	str_0x8aa801:
    .autostring 35 2 "Elise hat die Wundertausch-App auf dem Pokepad installiert!"
str_0x8ab119:
	.autostring 35 2 "Eine Sache noch.\pJe öfter du den Wundertausch benutzt, desto höher steigt dein Level.\pMit einem hohen Wundertausch-Level kannst du mit anderen erfahrenen Trainern tauschen, sodass du häufiger seltene Pokémon mit besonderen Fähigkeiten erhältst.\pBesonders ambitionierte Trainer sollten meine App also sehr häufig benutzen!"
str_0x8a7951:
    .autostring 35 2 "Hallo PLAYER!\pWie geht es dir?\pSammelst du auch fleißig Daten für den Pokédex?"
str_expedition2:
    .autostring 34 2 "Professor Tann will dich sehen.\pEr begibt sich bald auf eine Expedition."
str_elise_0:
	.autostring 34 2 "PLAYER!\pSchön, dich zu sehen."
str_elise_1:
	.autostring 34 2 "Sieht wohl so aus, als wären RIVAL und der Professor schon weg.\pDas sieht ihnen ähnlichDOTS"
str_elise_2:
	.autostring 34 2 "Dann bekommst eben nur du das Geschenk, das ich eigentlich dir und RIVAL geben wollte."
str_elise_3:
	.autostring 34 2 "Mit dieser Karte gelangst du in das Gebäude der Laz. Corp., der Firma, für die ich arbeite.\pMeine Forschung hier ist fast abgeschlossenDOTS"
str_elise_4:
	.autostring 34 2 "Und um ehrlich zu sein, ist uns in der Laz. Corp. ein Durchbruch gelungen."
str_elise_5:
	.autostring 34 2 "Aber ich will die Überraschung nicht vorweg nehmen.\pKomm einfach in das Hauptgebäude der Laz. Corp. in Orina City.\pDort werde ich mit meiner Überraschung auf dich warten, ja?"
str_elise_6:
	.autostring 34 2 "Orina City liegt westlich von Route 2, also nicht weit von hier."
str_elise_7:
	.autostring 34 2 "Und lass dir nicht zu viel Zeit, PLAYER, ja?\pImmerhin wird es sich lohnen, das verspreche ich dir."
.elseif LANG_EN


str_0x8aac71:
	.autostring 34 2 "Oh PLAYER, I almost forgot!\pI also have a present for you!\pSome while ago I developed a system that enables trainers from arround the world to trade Pokémon with one another.\pI called the system Wondertrade and to be quite honest, I think it's one of my better ideas.\pYou offer one of your Pokémon for trading.\pThen it will be sent to a random trainer somewhere else and in return you get one of their Pokémon.\pThe most exciting part about it all is that you can never quite know what kind of Pokémon you will be given.\pIf you make use of this system, it will get a lot easier to collect data for the Pokédex.\pI will just install the Wondertrade-App on your Poképad!"
	str_0x8aa801:
    .autostring 35 2 "Elise installed the Wondertrade-App on the Poképad."
str_0x8ab119:
	.autostring 34 2 "Just one thing.\pThe more you use the Wondertrade, the higher your level will go.\pWith a high Wondertrade-Level you will be more likely to trade with other experienced trainers and receive more rare and skilled Pokémon.\pIsn't that a great incentive for more ambitious trainers to use the Wondertrade-System very frequently?"
str_0x8a7951:
    .autostring 35 2 "Hello PLAYER!\pHow are you?\pAre you collecting data for the Pokédex?"
str_expedition2:
    .autostring 34 2 "Professor Fig want's to see you.\pHe will be going on an expedition soon!"

.endif