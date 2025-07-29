.include "vars.s"
.include "callstds.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "time_types.s"


.global ow_script_pokemon_spotter
.global ow_script_pokemon_spotter_wife

ow_script_pokemon_spotter:
	lock
	faceplayer
	callasm route_2_house_get_special_encounter_species
	bufferpokemon 0, 0x8004
	loadpointer 0 str_spotter
	callstd MSG_KEEPOPEN
	release
	end

ow_script_pokemon_spotter_wife:
	loadpointer 0 str_spotter_wife
	callstd MSG_FACE
	end

.ifdef LANG_GER
str_spotter:
	.autostring 34 2 "Mein Garten zieht Pokémon regelrecht an.\pEs gibt nichts schöneres, als sie von hier drinnen aus zu beobachten.\pErst heute morgen habe ich dort zum Beispiel ein BUFFER_1 gesehen.\pDu glaubst mir nicht?\pSieh doch selbst nach!"
str_spotter_wife:
	.autostring 34 2 "Mein Mann prahlt gerne damit, welche seltenen Pokémon sich in seinen Garten verirren.\pDabei weiß er nicht, dass sie eigentlich meinetwegen kommen.\pJeden Morgen, lange bevor er wach ist, stelle ich ein wenig Futter auf.\pDas lockt allerhand Pokémon hervor.\pDOTS DOTS DOTS\pDas muss aber unser Geheimnis blieben, ja?\pIch will ja nicht, dass mein Mann die Freude am Pokémon-Beobachten verliert."
.elseif LANG_EN
str_spotter:
	.autostring 34 2 "My garden attracts Pokémon like a magnet.\pThere is nothing more beautiful than watching them from here.\pJust this morning I saw a BUFFER_1 out there.\pYou don't believe me?\pGo and see for yourself!"
str_spotter_wife:
	.autostring 34 2 "My husband likes to boast about the rare Pokémon that wander into his garden.\pBut he doesn't know they actually come because of me.\pEvery morning, long before he's awake, I put out a little food.\pThat attracts all kinds of Pokémon.\pDOTS DOTS DOTS\pBut that's our secret, okay?\pI wouldn't want my husband to lose his joy for Pokémon watching."
.endif


@ .global ow_script_clock_master

@ ow_script_clock_master:
@ lock
@ faceplayer
@ compare TIME_TYPE TIME_TYPE_RTC
@ callif EQUAL buffer_rtc
@ compare TIME_TYPE TIME_TYPE_INGAME_CLOCK
@ callif EQUAL buffer_ingame_clock
@ loadpointer 0 str_clock_master
@ setvar 0x8000 1
@ special 0xE
@ loadpointer 0 str_intro
@ callstd MSG_KEEPOPEN
@ @// check if rtc works
@ special2 LASTRESULT 0x8
@ compare LASTRESULT 0
@ callif EQUAL broken
@ compare TIME_TYPE 0
@ gotoif EQUAL rtc
@ compare TIME_TYPE 1
@ gotoif EQUAL ingame_clock
@ special 0xF
@ release
@ end

@ ingame_clock:
@ @// If the ingame clock is broken, 999:99 hours are exceeded. This can be fixed here.
@ special2 LASTRESULT 0x8
@ compare LASTRESULT 0x0
@ callif EQUAL reset_ingame_clock
@ setvar 0x8008 TIME_TYPE_RTC @// 0x8008 contains the type that will be set after change
@ goto ask_change


@ reset_ingame_clock:
@ loadpointer 0 str_reset_ingame_clock
@ callstd MSG_YES_NO
@ compare LASTRESULT 1
@ gotoif EQUAL do_reset_ingame_clock
@ return

@ do_reset_ingame_clock:
@ closeonkeypress
@ special 0xF
@ callasm time_reset_ingame_clock
@ pause 0x64
@ loadpointer 0 str_clock_master
@ setvar 0x8000 1
@ special 0xE
@ loadpointer 0 str_ingame_clock_resetted
@ callstd MSG
@ special 0xF
@ release
@ end


@ rtc:
@ setvar 0x8008 TIME_TYPE_INGAME_CLOCK @// 0x8008 contains the type that will be set after change
@ ask_change:
@ loadpointer 0 str_change
@ callstd MSG_YES_NO
@ compare LASTRESULT 1
@ gotoif EQUAL change_type
@ no_change:
@ loadpointer 0 str_end
@ callstd MSG
@ special 0xF
@ release
@ end

@ change_type:
@ // Ask if you are sure
@ loadpointer 0 str_sure
@ callstd MSG_YES_NO
@ compare LASTRESULT 0
@ gotoif EQUAL no_change
@ copyvar TIME_TYPE 0x8008
@ callasm time_reset_events
@ special 0xF
@ closeonkeypress
@ pause 64
@ loadpointer 0 str_clock_master
@ setvar 0x8000 1
@ special 0xE
@ loadpointer 0 str_done
@ callstd MSG
@ special 0xF
@ release
@ end

@ broken:
@ loadpointer 0 str_broken
@ callstd MSG_KEEPOPEN
@ return


@ buffer_ingame_clock:
@ bufferstring 0 str_ingame_clock
@ bufferstring 1 str_rtc
@ return

@ buffer_rtc:
@ bufferstring 0 str_rtc
@ bufferstring 1 str_ingame_clock
@ return


@ .ifdef LANG_GER

@ str_clock_master:
@ 	.string "Uhrenmacher"

@ str_intro:
@ 	.autostring 35 2 "Ich bin der Uhrenmacher und kann die Uhren in deinem Spiel beeinflussen.\pDie interne Spielzeit wird entweder durch die RTC in deinem Gameboy beeinflusst, oder aber direkt aus der Spielzeit abgelesen.\pDerzeit nutzt du die BUFFER_1."

@ str_rtc:
@ 	.string "RTC"

@ str_ingame_clock:
@ 	.string "Spielzeit-Uhr"

@ str_broken:
@ 	.autostring 35 2 "Allerdings sieht es aus, als würde die BUFFER_1 nicht mehr voranschreiten DOTS"

@ str_change:
@ 	.autostring 35 2 "Möchtest du stattdessen die BUFFER_2 benutzen?"

@ str_end:
@ 	.autostring 35 2 "Wenn du Probleme mit der Uhr in deinem Spiel hast, komm einfach zu wieder zu mir."

@ str_sure:
@ 	.autostring 35 2 "Allerdings werden alle zeitbasierten Events bei einem Wechsel der Uhr zurückgesetzt.\pBist du damit einverstanden?"

@ str_done:
@ 	.autostring 35 2 "Alles klar!\pDie interne Spielzeit greift nun auf die BUFFER_2 zurück!\pDOTS DOTS DOTS\pKomm jederzeit wieder zu mir, falls du etwas an deiner internen Uhr ändern möchtest."

@ str_reset_ingame_clock:
@ 	.autostring 35 2 "Der Grund dafür ist, dass du die maximale Spielzeit bereits erreicht hast.\pSoll ich deine Spielzeit wieder zurücksetzten?"

@ str_ingame_clock_resetted:
@ 	.autostring 35 2 "Na bitte!\pDeine Spielzeit wurde wieder zurückgesetzt.\pDeine interne Uhr sollte nun wieder voranschreiten."

@ .elseif LANG_EN

@ .endif