.include "overworld_script.s"
.include "vars.s"
.include "ordinals.s"
.include "flags.s"
.include "callstds.s"
.include "movements.s"
.include "species.s"
.include "specials.s"
.include "battle_results.s"

.global ow_script_route_8_trigger_drampa
.global ow_script_route_8_drampa

ow_script_route_8_trigger_drampa:
	lockall
	checkflag RIVER_PUZZLE_DONE
	gotoif EQUAL show_drampa
	loadpointer 0 str_watched
	callstd MSG_KEEPOPEN
	releaseall
	end
show_drampa:
	loadpointer 0 str_watched
	callstd MSG_KEEPOPEN
	sound 0x15
	applymovement 255 mov_say_exclam
	waitmovement 0
	clearflag (SEN_LONG_VISIBLE | 0x8000)
	showsprite 1
	applymovement 1 mov_drampa_down
	waitmovement 0
	setvar SEN_LONG_TRIGGER 1
	releaseall
	end

mov_drampa_down:
	.byte STEP_DOWN_VERY_SLOW, STEP_DOWN_VERY_SLOW, STEP_DOWN_VERY_SLOW, STEP_DOWN_VERY_SLOW
	.byte STEP_DOWN_VERY_SLOW, STOP
mov_say_exclam:
	.byte SAY_EXCLAM, STOP

ow_script_route_8_drampa:
	special 0x188
	compare LASTRESULT 2
	gotoif EQUAL end_drampa
	lock
	setwildbattle POKEMON_SEN_LONG 40 0
	checksound
	cry POKEMON_SEN_LONG 2
	loadpointer 0 str_drampa_growl
	callstd MSG_KEEPOPEN
	playsong 0x156 0
	closeonkeypress
	setflag FLAG_IN_BATTLE
	dowildbattle
	clearflag FLAG_IN_BATTLE
	special2 LASTRESULT SPECIAL_GET_BATTLE_RESULT
	compare LASTRESULT BATTLE_RESULT_WON
	gotoif EQUAL drampa_fainted
	compare LASTRESULT BATTLE_RESULT_RAN
	gotoif EQUAL drampa_fled
	compare LASTRESULT BATTLE_RESULT_PLAYER_TELEPORTED
	gotoif EQUAL drampa_fled
	setflag SEN_LONG_CAUGHT
	end
drampa_fainted:
	setflag SEN_LONG_CAUGHT
hide_drampa:
	fadescreen 1
	hidesprite LASTTALKED
	fadescreen 0
	releaseall
end_drampa:
	end

drampa_fled:
	fadescreen 1
	hidesprite LASTTALKED
	fadescreen 0
	loadpointer 0 str_drampa_fled
	callstd MSG_KEEPOPEN
	releaseall
	end



.ifdef LANG_GER
str_watched:
	.autostring 34 2 "Es fühlt sich an, als würde man beobachtet werdenDOTS"
str_drampa_growl:
	.autostring 34 2 "Gryoo Ga Ga GaDOTS"
str_drampa_fled:
	.autostring 34 2 "Sen-Long flog davonDOTS"

.elseif LANG_EN
str_watched:
	.autostring 34 2 "It feels like you are being watchedDOTS"
str_drampa_growl:
	.autostring 34 2 "Gryoo Ga Ga GaDOTS"
str_drampa_fled:
	.autostring 34 2 "Drampa flew awayDOTS"

.endif
