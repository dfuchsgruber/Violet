.include "overworld_script.s"
.include "callstds.s"
.include "species.s"
.include "flags.s"
.include "vars.s"
.include "ordinals.s"
.include "specials.s"
.include "battle/battle_results.s"

.global ow_script_dungeon_forest_rotom_tv

ow_script_dungeon_forest_rotom_tv:
    lockall
    loadpointer 0 str_tv_not_working
    callstd MSG_KEEPOPEN
    checkflag FLAG_DUNGEON_GP
    gotoif EQUAL rotom_done
    loadpointer 0 str_investigate
    callstd MSG_YES_NO
    compare LASTRESULT 0
    gotoif EQUAL rotom_done
    closeonkeypress
    pause 24
    loadpointer 0 str_shake
    callstd MSG
    pause 32
    loadpointer 0 str_wait
    callstd MSG
    pause 24
	sound 0x15
    setvar 0x8004 POKEMON_ROTOM
	cry 0x8004 0
	callasm special_misc_encounter_overworld_new
	applymovement 0xFF mov_exclam
	waitmovement 0
	checksound
	waitcry
	setwildbattle POKEMON_ROTOM 35 0
	setflag FLAG_IN_BATTLE
	dowildbattle
	clearflag FLAG_IN_BATTLE
	special2 LASTRESULT SPECIAL_GET_BATTLE_RESULT
	compare LASTRESULT BATTLE_RESULT_RAN
	gotoif EQUAL rotom_done
	compare LASTRESULT BATTLE_RESULT_PLAYER_TELEPORTED
	gotoif EQUAL rotom_done
	setflag FLAG_DUNGEON_GP
rotom_done:
    releaseall
    end



.ifdef LANG_GER
str_tv_not_working:
    .autostring 34 2 "Der Fernseher scheint nicht mehr zu funktionieren."
str_investigate:
    .autostring 34 2 "Man könnte sich einbilden, dass er einen anstarrt.\pMöchtest du am Fernseher wackeln?"
str_shake:
    .autostring 34 2 "PLAYER wackelt am Fernseher."
str_wait:
    .autostring 34 2 ".TEXT_DELAY_LONG.TEXT_DELAY_LONG.TEXT_DELAY_LONG"
.elseif LANG_EN
.endif