.include "callstds.s"
.include "flags.s"
.include "songs.s"
.include "overworld_script.s"
.include "mugshot.s"
.include "songs.s"
.include "movements.s"
.include "specials.s"
.include "ordinals.s"
.include "items.s"

.global ow_script_0x8951c4
ow_script_0x8951c4:
	lockall
	faceplayer
	checkflag FRBADGE_3
	gotoif EQUAL check_expedition
expedition_announced:
	loadpointer 0x0 str_0x843a47
	show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT
	call ow_script_healing_sequence
	playsong MUS_VERTANIA_CITY_AND_MARMORIA_CITY_AND_SAFFRONIA_CITY 0x0
	loadpointer 0x0 str_0x843aba
	show_mugshot MUGSHOT_TANN MUGSHOT_RIGHT MSG_FACE
	releaseall
	end


check_expedition:
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

.global str_0x843a47

str_0x843a47:
	.autostring 35 2 "Du und deine Pokémon sehen ja schrecklich erschöpft aus!\pSetz dich doch erst einmal eine Weile hin und ruh dich aus!"
        
        
.global str_0x843aba

str_0x843aba:
	.autostring 35 2 "Na siehst du?\pDu und deine Pokémon sehen schon wieder ganz fit aus!"
        
        
.elseif LANG_EN

.endif
