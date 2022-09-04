
.include "overworld_script.s"
.include "vars.s"
.include "ordinals.s"
.include "flags.s"
.include "callstds.s"
.include "movements.s"
.include "species.s"
.include "specials.s"
.include "battle/battle_results.s"

.global ow_script_antike_ruinen_regirock

ow_script_antike_ruinen_regirock:
	special 0x188
	compare LASTRESULT 2
	gotoif EQUAL end_script
	lock
	setwildbattle POKEMON_REGIROCK 45 0
	checksound
	cry POKEMON_REGIROCK 2
	loadpointer 0 str_growl
	callstd MSG_KEEPOPEN
	closeonkeypress
	setflag FLAG_IN_BATTLE
	special SPECIAL_WILD_BATTLE_LEGENDARY_INITIALIZE
    waitstate
	clearflag FLAG_IN_BATTLE
	special2 LASTRESULT SPECIAL_GET_BATTLE_RESULT
	compare LASTRESULT BATTLE_RESULT_WON
	gotoif EQUAL fainted
	compare LASTRESULT BATTLE_RESULT_RAN
	gotoif EQUAL fainted
	compare LASTRESULT BATTLE_RESULT_PLAYER_TELEPORTED
	gotoif EQUAL fled
	setflag FLAG_REGIROCK
	end
fainted:
	setflag FLAG_REGIROCK
	fadescreen 1
	hidesprite LASTTALKED
	fadescreen 0
	releaseall
end_script:
	end

fled:
	fadescreen 1
	hidesprite LASTTALKED
	fadescreen 0
	loadpointer 0 str_fled
	callstd MSG_KEEPOPEN
	releaseall
	end

.ifdef LANG_GER
str_growl:
    .autostring 34 2 "Groyayaya!"
str_fled:
    .autostring 34 2 "Regirock ist verschwundenDOTS"

.elseif LANG_EN
str_growl:
    .autostring 34 2 "Groyayaya!"
str_fled:
    .autostring 34 2 "Regirock has vanishedDOTS"

.endif
