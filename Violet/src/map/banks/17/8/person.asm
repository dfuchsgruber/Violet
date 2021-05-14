.include "overworld_script.s"
.include "vars.s"
.include "ordinals.s"
.include "flags.s"
.include "callstds.s"
.include "movements.s"
.include "species.s"
.include "specials.s"
.include "battle/battle_results.s"
.include "items.s"

.global ow_script_route_5_cave_ariados

ow_script_route_5_cave_ariados:
    lock
    faceplayer
	setwildbattle POKEMON_ARIADOS 39 0
	checksound
    cry POKEMON_ARIADOS 2
	loadpointer 0 str_growl
	callstd MSG_KEEPOPEN
	playsong 0x156 0
	closeonkeypress
	setflag FLAG_IN_BATTLE
	dowildbattle
	clearflag FLAG_IN_BATTLE
	special2 LASTRESULT SPECIAL_GET_BATTLE_RESULT
	compare LASTRESULT BATTLE_RESULT_RAN
	gotoif EQUAL end_script
	compare LASTRESULT BATTLE_RESULT_PLAYER_TELEPORTED
	gotoif EQUAL end_script
	fadescreen 1
	hidesprite LASTTALKED
	fadescreen 0
    pause 40
    loadpointer 0 str_0
    callstd MSG
    setvar 0x8000 ITEM_WOLKENGARN
    setvar 0x8001 1
    callstd ITEM_OBTAIN
end_script:
    releaseall
	end

.ifdef LANG_GER
str_growl:
    .autostring 34 2 "Ieeeeeek!"
str_0:
    .autostring 34 2 "Was ist das?\pDa scheint etwas auf dem Boden zu liegen.\pDOTSTEXT_DELAY_LONG DOTSTEXT_DELAY_LONG DOTSTEXT_DELAY_LONG"
.elseif LANG_EN
.endif
