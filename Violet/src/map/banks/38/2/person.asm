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

.global ow_script_moon_tower_treasure_map
.global ow_script_moon_tower_lunatone

ow_script_moon_tower_treasure_map:
    give_treasure_map treasure_map_idx=6 give_type=TREASURE_MAP_FIND
    hidesprite LASTTALKED
    release
    end

ow_script_moon_tower_lunatone:
    special 0x188
	compare LASTRESULT 2
	gotoif EQUAL end_lunatone
	lock
	setwildbattle POKEMON_LUNASTEIN 40 0
	checksound
	cry POKEMON_LUNASTEIN 2
	loadpointer 0 str_lunatone_growl
	callstd MSG_KEEPOPEN
	playsong MUS_CLOUDS_WILD_BATTLE 0
	closeonkeypress
	setflag FLAG_IN_BATTLE
	dowildbattle
	clearflag FLAG_IN_BATTLE
	special2 LASTRESULT SPECIAL_GET_BATTLE_RESULT
	compare LASTRESULT BATTLE_RESULT_WON
	gotoif EQUAL lunatone_fainted
	compare LASTRESULT BATTLE_RESULT_RAN
	gotoif EQUAL lunatone_fled
	compare LASTRESULT BATTLE_RESULT_PLAYER_TELEPORTED
	gotoif EQUAL lunatone_fled
lunatone_fainted:
	setflag FLAG_MOON_TOWER_LUNATONE
hide_lunatone:
	fadescreen 1
	hidesprite LASTTALKED
	fadescreen 0
	releaseall
end_lunatone:
	end

lunatone_fled:
	fadescreen 1
	hidesprite LASTTALKED
	fadescreen 0
	loadpointer 0 str_lunatone_fled
	callstd MSG_KEEPOPEN
	releaseall
	end

.ifdef LANG_GER
str_lunatone_growl:
    .autostring 34 2 "Urghgyaa!"
str_lunatone_fled:
    .autostring 34 2 "Lunastein ist geflohen!"
.elseif LANG_EN
str_lunatone_growl:
    .autostring 34 2 "Urghgyaa"
str_lunatone_fled:
    .autostring 34 2 "Lunatone fled!"
.endif
