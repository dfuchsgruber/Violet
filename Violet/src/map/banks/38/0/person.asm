.include "overworld_script.s"
.include "treasure_map.s"
.include "callstds.s"
.include "vars.s"
.include "ordinals.s"
.include "flags.s"
.include "specials.s"
.include "battle/battle_results.s"
.include "species.s"
.include "songs.s"

.global ow_script_sun_moon_tower_treasure_map
.global ow_script_sun_moon_tower_solrock

ow_script_sun_moon_tower_treasure_map:
    give_treasure_map treasure_map_idx=5 give_type=TREASURE_MAP_FIND
    hidesprite LASTTALKED
    release
    end

ow_script_sun_moon_tower_solrock:
    special 0x188
	compare LASTRESULT 2
	gotoif EQUAL end_solrock
	lock
	setwildbattle POKEMON_SONNFEL 40 0
	checksound
	cry POKEMON_SONNFEL 2
	loadpointer 0 str_solrock_growl
	callstd MSG_KEEPOPEN
	playsong MUS_CLOUDS_WILD_BATTLE 0
	closeonkeypress
	setflag FLAG_IN_BATTLE
	dowildbattle
	clearflag FLAG_IN_BATTLE
	special2 LASTRESULT SPECIAL_GET_BATTLE_RESULT
	compare LASTRESULT BATTLE_RESULT_WON
	gotoif EQUAL solrock_fainted
	compare LASTRESULT BATTLE_RESULT_RAN
	gotoif EQUAL solrock_fled
	compare LASTRESULT BATTLE_RESULT_PLAYER_TELEPORTED
	gotoif EQUAL solrock_fled
solrock_fainted:
	setflag FLAG_SUN_TOWER_SOLROCK
hide_solrock:
	fadescreen 1
	hidesprite LASTTALKED
	fadescreen 0
	releaseall
end_solrock:
	end

solrock_fled:
	fadescreen 1
	hidesprite LASTTALKED
	fadescreen 0
	loadpointer 0 str_solrock_fled
	callstd MSG_KEEPOPEN
	releaseall
	end

.ifdef LANG_GER
str_solrock_growl:
    .autostring 34 2 "Nrhgh! Nrgh! Nrgh!"
str_solrock_fled:
    .autostring 34 2 "Sonnfel ist geflohen!"
.elseif LANG_EN
str_solrock_growl:
    .autostring 34 2 "Nrhgh! Nrgh! Nrgh!"
str_solrock_fled:
    .autostring 34 2 "Solrock fled!"
.endif