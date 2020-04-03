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
	show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT
	call ow_script_healing_sequence
	playsong MUS_VERTANIA_CITY_AND_MARMORIA_CITY_AND_SAFFRONIA_CITY 0x0
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
	playsong MUS_RIVALE_ERSCHEINT_GARY 0
	checksound
	pause 16
	loadpointer 0 str_0
	show_mugshot MUGSHOT_RIVAL MUGSHOT_LEFT
	applymovement 4 mov_rival_to_prof
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
	setvar 0x8004 1
	setvar 0x8005 7
	setvar 0x8006 0xb
	special SPECIAL_NPC_MOVE_TO
	waitmovement 0
	applymovement 1 mov_fd
	waitmovement 0
	pause 16
	sound 9
	hidesprite 1
	checksound
	fadesong MUS_VERTANIA_CITY_AND_MARMORIA_CITY_AND_SAFFRONIA_CITY
	pause 64
	setvar 0x8004 2
	setvar 0x8005 7
	setvar 0x8006 5
	special SPECIAL_SET_TARGET_NPC_TO_VAR
	special SPECIAL_NPC_MOVE_TO
	waitmovement 0
	lock
	faceplayer
	loadpointer 0 str_8
	show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT
	copyvarifnotzero 0x8000 ITEM_ZUGANGSKARTE
	copyvarifnotzero 0x8001 1
	callstd ITEM_OBTAIN
	loadpointer 0 str_9
	show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT
	setvar 0x8004 2
	setvar 0x8005 7
	setvar 0x8006 0xb
	special SPECIAL_NPC_MOVE_TO
	waitmovement 0
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

mov_rival_to_prof:
	.byte STEP_UP, STEP_UP, STEP_UP, STEP_RIGHT, STEP_UP, STEP_UP, STOP
mov_rival_away:
	.byte STEP_DOWN, STEP_DOWN, STEP_DOWN, STEP_LEFT, STEP_DOWN, STEP_DOWN, STOP
mov_fu:
	.byte LOOK_UP, STOP
mov_fd:
	.byte LOOK_DOWN, STOP


.ifdef LANG_GER

str_expedition:
	.autostring 34 2 "PLAYER!\nWie schön dich zu sehen.\pIch wollte dir und RIVAL etwas mitteilenDOTS\pEr sollte jeden MomentDOTS"
str_0:
	.autostring 34 2 "Hallo Papa!\nDu wolltest mich sehen?"
str_1:
	.autostring 34 2 "PLAYER!\nDu bist ja auch schon da!\pSoll das etwa heißen, ich bin der Letzte?\pDas sieht mir so gar nicht ähnlich!\pAlso Papa, was gibt es?"
str_2:
	.autostring 34 2 "Schön, dass du es auch geschafft hast, RIVAL.\pIch habe große Neuigkeiten für euch.\pIch werde in Kürze auf eine Expedition gehen, die versunkene Stadt Atlantea zu entdecken.\pZiel dieser Unternehmung ist es, die Alte Karte zu bergen, welche der Legende nach den Weg nach Atlantea weist.\pDas bedeutet, dass ich für einige Zeit fort sein werde.\pWie mir aber zu Ohren gekommen ist, seid ihr beide inzwischen stattliche Trainer geworden.\pDas macht mich wirklich außerordentlich glücklich!\pIhr lebt euren Traum, und das selbe muss auch ich tun.\pMir ist bewusst, dass die Expedition auf, die ich mich begebe, nicht ungefährlich ist.\pUnd daher wollte ich euch beide noch ein letztes Mal sehen und mich verabschieden, nur für den Fall, dassDOTS DOTS DOTS"
str_3:
	.autostring 34 2 "Nun hör aber auf, so einen Unsinn zu reden, Papa!\pDeine Expedition wird ein Erfolg werden!\pIch werde mir von dir sicher kein Lebewohl anhören!"
str_4:
	.autostring 34 2 "RIVALDOTS"
str_5:
	.autostring 34 2 "Nichts da!\pDu kommst wieder zurück und damit basta!\pHast du mich verstanden?\pSo wird das gemacht, Papa und nicht anders!"
str_6:
	.autostring 34 2 "Ich meine es ernst, Papa!"
str_7:
	.autostring 34 2 "Ich sollte mit RIVAL sprechenDOTS\pEntschuldige bitte dieses ganze Drama, PLAYER.\pAber du weißt ja, wie sturköpfig RIVAL sein kannDOTS"
str_8:
	.autostring 34 2 "Der arme RIVAL macht sich wohl Sorgen um seinen VaterDOTS\pAuch, wenn er das scheinbar nicht wirklich ausdrücken kann.\pIch bin aber guter Dinge, dass die Expedition des Professors gut verlaufen wird!\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pSolltest du dich für die archäologische Forschung des Professors interessieren, solltest du unbedingt dem Museum in Orina City einen Besuch abstatten.\pUnd wenn du schon einmal dort bist, kann ich dir die Firma zeigen, für dich arbeite, die Laz. Corp.\pIch arbeite seit einiger Zeit an einem gänzlich virtuellen Pokémon.\pEinen Trainer wie dich, dürfte das sicherlich interessieren.\pIch werde dir eine Zugangskarte für mein Labor dort geben."
str_9:
	.autostring 34 2 "Du erreichst Orina City über Route 5, welche sich westlich von hier befindet.\pDu solltest mich auf jeden Fall in der Laz. Corp besuchen kommen, PLAYER!\pDas virtuelle Pokémon wird dich ganz sicher begeistern!"


str_0x843a47:
	.autostring 35 2 "Du und deine Pokémon sehen ja schrecklich erschöpft aus!\pSetz dich doch erst einmal eine Weile hin und ruh dich aus!"



str_0x843aba:
	.autostring 35 2 "Na siehst du?\pDu und deine Pokémon sehen schon wieder ganz fit aus!"


.elseif LANG_EN

.endif


ow_script_map_3_66_person_2:
loadpointer 0x0 str_0x8a679f
show_mugshot MUGSHOT_RIVAL MUGSHOT_RIGHT MSG_FACE
end


.ifdef LANG_GER

str_0x8a679f:
	.autostring 35 2 "Ich werde ganz sicher mehr Pokémon in meiner Pokédex-app registrieren, als du!"

.elseif LANG_EN

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
    loadpointer 0 str_expedition2
    show_mugshot MUGSHOT_ELISE MUGSHOT_RIGHT
    release
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
	.autostring 35 2 "Ohje, PLAYER!\nBeinahe hätte ich vergessen, dass auch ich für euch noch ein Geschenk habe.\pSeit einiger Zeit widme ich mich nämlich einem System, das helfen soll, Trainer von überall miteinander zu verbinden.\pDieses System heißt Wundertausch und das Ganze ist, um ehrlich zu sein, unglaublich aufregend!\pMan bietet eines seiner Pokémon zum Tausch an.\pDann wird es an einen Trainer irgendwo auf der Welt versandt und man erhält dessen verschicktes Pokémon.\pMan weiß nie, wen dein Pokémon erreicht!\pSpannend nicht?\pIch werde die Wundertausch-App auf deinem Poképad installieren."


str_0x8aa801:
    .autostring 35 2 "Elise hat die Wundertausch-App auf dem Pokepad installiert!"



str_0x8ab119:
	.autostring 35 2 "Eine Sache noch.\pJe öfter du den Wundertausch benutzt, desto höher steigt dein Level.\pMit einem hohen Wundertausch-Level kannst du mit anderen erfahrenen Trainern tauschen, sodass du häufiger seltene Pokémon mit besonderen Fähigkeiten erhältst.\pDadurch lohnt es sich für jeden, die App häufig zu benutzen und die Menschen der Welt zu verbinden.\pDas ist mein großer Traum.\pIch würde mich freuen, wenn du mir hilfst, ihn zu verwirklichen und den Wundertausch oft benutzt."


str_0x8a7951:
    .autostring 35 2 "Bald schon werden alle Trainer dieser Welt den Wundertausch benutzen!\pDavon bin ich fest überzeugt!"

str_expedition2:
    .autostring 34 2 "Professor Tann will dich sehen.\pEr begibt sich bald auf eine Expedition."

.elseif LANG_EN

.endif