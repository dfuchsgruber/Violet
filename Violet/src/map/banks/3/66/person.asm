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
    gotoif EQUAL ow_script_0x8a5ccb
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
    .autostring 35 2 "Hallo PLAYER!\pWie geht es dir?\pSammelst du Daten für den Pokédex?\pVergiss nicht, die Wundertausch-App zu benutzen, um verschiedene Pokémon zu registrieren."
str_expedition2:
    .autostring 34 2 "Professor Tann will dich sehen."
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
	.autostring 34 2 "Aber ich will die Überraschung nicht vorweg nehmen.\pKomm einfach in das Hauptgebäude der Laz. Corp. in Orina City.\pDort werde ich auf dich warten, ja?"
str_elise_6:
	.autostring 34 2 "Orina City liegt westlich von Route 2, also nicht weit von hier."
str_elise_7:
	.autostring 34 2 "Und lass dir nicht zu viel Zeit, PLAYER, ja?\pImmerhin wird es sich lohnen, das verspreche ich dir."
.elseif LANG_EN

.endif