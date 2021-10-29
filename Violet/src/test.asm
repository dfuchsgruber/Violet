.include "vars.s"
.include "overworld_script.s"
.include "flags.s"
.include "callstds.s"
.include "items.s"
.include "attacks.s"
.include "ordinals.s"
.include "species.s"
.include "roamers.s"
.include "specials.s"
.include "movements.s"
.include "trainer_backsprites.s"
.include "battle/battle_handicaps.s"
.include "battle/battle_bgs.s"
.include "map_weathers.s"
.include "overworld/overworld_effects.s"

.global ow_script_test
.global ow_script_trainer1
.global ow_script_trainer2


ow_script_trainer1:
	trainerbattlestd 0x0 0x15f 0 str_beforea str_aftera
	end
ow_script_trainer2:
	trainerbattlestd 0x0 0x160 0 str_beforeb str_afterb
	end

str_beforea:
	.string "Before A"
str_aftera:
	.string "After A"
str_beforeb:
	.string "Before B"
str_afterb:
	.string "After B"

ow_script_test:
	setflag PLAYER_ABLE_TO_MEGA_EVOLVE
	givepokemon POKEMON_ZOBIRIS 20 ITEM_ZOBIRISNIT 0 0 0
	end
	additem ITEM_LOTUS_BALL 1
	setvar 0x8004 20
	special SPECIAL_CUTSCENE_SHOW
	waitstate
	end

	setvar 0x8004 0x45
	setvar 0x8005 0x1c
	special SPECIAL_OVERWORLD_EFFECT_LIGHTNING
	sound 111
	checkanimation OVERWORLD_EFFECT_LIGHTNING
	end

	additem ITEM_ROTES_ZAHNRAD 1
	additem ITEM_BLAUES_ZAHNRAD 1
	additem ITEM_GELBES_ZAHNRAD 1
	additem ITEM_GRUENES_ZAHNRAD 1
	end

	setworldmapflag WM_DESERT_VILLAGE
	end
	
	clearflag FLAG_DUNGEON_BASE
	additem ITEM_ABRA_PUPPE 5
	end

	clearflag ORINA_CITY_RECEIVED_PORYGON
	end

	// setflag PLAYER_ABLE_TO_MEGA_EVOLVE
	givepokemon POKEMON_ARIADOS 20 ITEM_ARIADOSNIT 0 0 0
	end
	

	callasm bluetenbach_gym_rotate_walls
	special SPECIAL_MAP_UPDATE_BLOCKS
	end

	settrainerflag 0x2e
	trainerbattlestd 0x0 0x2e 0 str_beforeb str_afterb
	end

	setflag FLAG_BRUCHFELS_GYM_PUZZLE_ROOM_0_SOLVED
	setflag FLAG_BRUCHFELS_GYM_PUZZLE_ROOM_1_SOLVED
	setflag FLAG_SILVANIA_CUT_TREE
	setflag FLAG_SILVANIA_CUT_TREE_2
	setflag FLAG_SILVANIA_FOREST_BURNING
	setflag FLAG_SILVANIA_FOREST_SEQUENCE_1_NPCS
	setflag FLAG_SILVANIA_FOREST_HYDRO_PUMP_0
	setflag FLAG_SILVANIA_FOREST_HYDRO_PUMP_1
	end


	callasm print_flags
	callasm print_vars
	end

	clearflag (KASKADA_IGVA | 0x8000)
	end
	givepokemon POKEMON_DARTIRI 26 0 0 0 0
	additem ITEM_SONDERBONBON 99 
	end
	
	setvar STORY_PROGRESS 31
	end

	setflag PLAYER_ABLE_TO_MEGA_EVOLVE
	givepokemon POKEMON_MASKEREGEN 20 ITEM_MASKEREGENIT 0 0 0
	end

	callasm berry_trees_initialize_all
	end
	clearflag PLAYER_ABLE_TO_MEGA_EVOLVE
	end
	setflag PLAYER_ABLE_TO_MEGA_EVOLVE
	givepokemon POKEMON_SANDAMER 20 ITEM_SANDAMERNIT 0 0 0
	end
	fadescreen 1
	setvar 0x8004 0xe
	setvar 0x8005 0x9
	special SPECIAL_OVERWORLD_VIEWPORT_SET_POSITION
	fadescreen 0
	pause 64
	special SPECIAL_OVERWORLD_VIEWPORT_UNLOCK
	applymovement 0x7F movs
	waitmovement 0
	special SPECIAL_OVERWORLD_VIEWPORT_LOCK
	fadescreen 1
	special SPECIAL_OVERWORLD_VIEWPORT_SET_TO_PLAYER_POSITION
	callasm ow_script_fadescreen_palette_backup
	fadescreen 0
	end

movs:
    .byte STEP_UP, STEP_UP, STOP 
	end

	givepokemon POKEMON_MOLUNK 50 ITEM_ALTARIANIT 0 0 0
	givepokemon POKEMON_AMFIRA 50 ITEM_ALTARIANIT 0 0 0
	givepokemon POKEMON_PICHU 50 ITEM_ALTARIANIT 0 0 0
	givepokemon POKEMON_ROTOM 50 ITEM_ALTARIANIT 0 0 0
	givepokemon POKEMON_ROTOM_HEAT 50 ITEM_ALTARIANIT 0 0 0
	givepokemon POKEMON_ROTOM_WASH 50 ITEM_ALTARIANIT 0 0 0
	givepokemon POKEMON_ROTOM_FORST 50 ITEM_ALTARIANIT 0 0 0
	givepokemon POKEMON_ROTOM_GRASS 50 ITEM_ALTARIANIT 0 0 0
	givepokemon POKEMON_ROTOM_WIND 50 ITEM_ALTARIANIT 0 0 0
	end
	settrainerflag 4
	trainerbattlecont 0x1 0x4 0x3 str_beforea str_aftera cont
cont:
	sound 15
	checksound
	end


	setweather MAP_WEATHER_BURNING_TREES
	doweather
	end
	setvar STORY_PROGRESS 0x1c
	end
	settrainerflag 0x29
	settrainerflag 0x2a
	settrainerflag 0x2b
	setvar STORY_PROGRESS 16
	clearflag ROUTE_3_MAY
	end


	setflag FLAG_SILVANIA_FOREST_ENTRANCE
	setflag FLAG_SILVANIA_CUT_TREE
	clearflag FRBADGE_5
	end


	callasm composter_initialize
	waitstate
	loadpointer 0 str_beforea
	callstd MSG
	end
	setflag FRBADGE_5
	additem ITEM_VM04 1
	end
	clearflag FLAG_BRUCHFELS_GYM_PUZZLE_ROOM_1_SOLVED
	end
	setflag PLAYER_ABLE_TO_MEGA_EVOLVE
	givepokemon POKEMON_ALTARIA 50 ITEM_ALTARIANIT 0 0 0
	trainerbattlestd 0x0 0x300 0 str_beforea str_aftera
	end
	clearflag FLAG_BRUCHFELS_GYM_PUZZLE_ROOM_0_SOLVED
	end
	additem ITEM_SONDERBONBON 1
	additem ITEM_GOLDBONBON 99
	additem ITEM_BITTERKRAUT 1
	additem ITEM_QUARZSTAUB 1
	additem ITEM_ENERGIEQUARZ 1
	end
	trainerbattlestd 0x0 0x300 0 str_beforea str_aftera
	end
	clearflag PLAYER_ABLE_TO_MEGA_EVOLVE
	additem ITEM_APFEL 1
	additem ITEM_GOLDAPFEL 1
	additem ITEM_MININUGGET 1
	end

	setflag PLAYER_ABLE_TO_MEGA_EVOLVE
	givepokemon POKEMON_RASAFF 20 ITEM_RASAFFNIT 0 0 0
	end

	setflag FRBADGE_4
	additem ITEM_VM03 1
	end
	additem ITEM_VM02 1
	givepokemon POKEMON_STARALILI 5 0 0 0 0
	end

	additem ITEM_TSITRUBEERE 99
	additem ITEM_TSITRUBEERE 99
	additem ITEM_TSITRUBEERE 99
	additem ITEM_TSITRUBEERE 99
	additem ITEM_TSITRUBEERE 99
	additem ITEM_TSITRUBEERE 99
	callasm pokemon_get_evolution_item_line_test
	end
	setvar 0x8000 ITEM_NULLSAFT
	setvar 0x8001 5
	callstd ITEM_FIND
	end
	additem ITEM_BODENJUWEL 3
	end
	callasm crafting_ui_initialize
	waitstate
	end

	callasm berry_trees_initialize_all
	additem ITEM_WUNDERSTAUB 5
	end
	// setflag PLAYER_ABLE_TO_MEGA_EVOLVE
	// setvar BATTLE_BG_OVERRIDE BATTLE_BG_BBSHIP_OUTSIDE + 1
	// givepokemon POKEMON_OCTILLERY 80 ITEM_OCTILLERYNIT 0 0 0
	//trainerbattlestd 0x0 0x199 0 str_beforea str_aftera
	// end
	warp 33 4 0 0 0
	waitstate
	end
	setflag 0x820
	setflag 0x821
	setflag 0x822
	setflag 0x823
	setflag 0x824
	end

	// setvar BATTLE_SONG_OVERRIDE MUS_LUCIUS_BATTLE
    trainerbattlelosable 0x9 0x15e 0x5 str_beforea str_beforeb
	end

	setvar 0x8004 19
	special SPECIAL_CUTSCENE_SHOW
	waitstate
	end

callasm trainerschool_exam_init

loadpointer 0 str_beforea
callstd MSG
end
/** 
clearflag AMONIA_RIVAL_INSIDE_PLAYER_HOUSE
showsprite 2
goto ow_script_0x88abb8


loadpointer 0 str_a
setvar 0x8000 0
special 0xE
settrainerflag 4
trainerbattlecont 0x1 0x4 0x3 str_0x8a158f str_0x8a15bf ow_script_0x8a1433


setvar 0x8004 18
special 0x19
waitstate
end

clearflag MAP_BGN_AUTO_ALIGN_OFF
waitstate //both waitstates are resolved in animation 12
pause 0x20
fadescreen 1
setvar 0x8004 13
special 0x19
waitstate //now disable the bg aligment again
setflag MAP_BGN_AUTO_ALIGN_OFF
waitstate
clearflag MAP_BGN_AUTO_ALIGN_OFF
pause 0x80
loadpointer 0x0 str_0x8cf12f
callstd MSG_KEEPOPEN
closeonkeypress
end



setflag TRANS_DISABLE
clearflag TRANS_PALETTE_FETCH
special SPECIAL_SELECT_HALF_PARTY
waitstate
clearflag TRANS_DISABLE
compare LASTRESULT 0
gotoif EQUAL cont
goto ow_script_0x971404
//setvar 0x8004 BATTLE_HANDICAP_EXTREME_HEAT
//setvar 0x8004 BATTLE_HANDICAP_FLOATING_ROCKS
//setvar 0x8004 BATTLE_HANDICAP_GRASSY_FIELD
//setvar 0x8004 BATTLE_HANDICAP_TERRIFYING_ATMOSPHERE
//setvar 0x8004 BATTLE_HANDICAP_ARENA_ENCOURAGEMENT
setvar 0x8004 BATTLE_HANDICAP_GROUDON_BATTLE
special SPECIAL_BATTLE_HANDICAP_SET
trainerbattlecont 0x1 0x170 0x0 str_a str_0x96f156 cont


additem ITEM_SONDERBONBON 55
additem ITEM_DUBIOSDISC 1
end


setflag TRANS_DISABLE
clearflag TRANS_PALETTE_FETCH
special SPECIAL_SELECT_HALF_PARTY
waitstate
clearflag TRANS_DISABLE
compare LASTRESULT 0
gotoif EQUAL cont
setvar VAR_ALLY 0x161
special SPECIAL_ALLY_BATTLE_SAVE_AND_SETUP_PARTY
trainerbattleallytwotrainers 0x15f 0x160 0x161 0 TRAINER_BACKSPRITE_RIVAL 1 str_beforea str_aftera str_afterb cont
cont:
loadpointer 0 str_a
callstd MSG
end

trainerbattlecont 0x1 0x160 0x0 str_a str_0x96f156 cont
setflag PLAYER_ABLE_TO_MEGA_EVOLVE
givepokemon POKEMON_TROPIUS 80 ITEM_TROPIUSNIT 0 0 0
end

str_a:
	.string "KEY_L KEY_R"

special SPECIAL_OVERWORLD_VIEWPORT_UNLOCK
callasm test_overworld_viewport_set_position
pause 120
applymovement 0x7F movs
waitmovement 0
end

applymovement 0x7F movs
waitmovement 0
special SPECIAL_OVERWORLD_VIEWPORT_LOCK
end

movs:
    .byte STEP_UP, STEP_UP, STOP 


callasm special_initialize_pc_for_selection
waitstate 
end


special 60
waitstate
end


givepokemon POKEMON_ICOGNITO 12 0 0 0 0
end

lock
setvar 0x8004 2
special2 0x800D SPECIAL_PLAYER_PARTY_SPELLS_UNOWN_MESSAGE
special SPECIAL_UNOWN_MESSAGE_PRINT
waitstate
special SPECIAL_UNOWN_MESSAGE_REMOVE
release
end


sound 0xd1
setanimation 0x0 0x47
setanimation 0x1 0x1d
setanimation 0x2 0x0
doanimation 0x36
checkanimation 0x36
setvar 0x8004 0x6
setflag TRANS_DISABLE
special 0x19
waitstate
settrainerflag 0xaa
trainerbattlecont 0x1 0xaa 0x0 str_0x96f0ee str_0x96f156 ow_script_0x96fbaa
end


warp 3 17 255 0x1e 0x15
waitstate
end

braille braille1
waitkeypress
waitmsg
closeonkeypress
end

braille1:
.autostring 34 2 "BRAILLE_HBRAILLE_CBRAILLE_KBRAILLE_,"


setvar 0x8000 ITEM_KUESTENSALZ
loop:
	additem 0x8000 10
	addvar 0x8000 1
	compare 0x8000 ITEM_ENIGMABEERE
	gotoif 0 loop
end


additem ITEM_SONDERBONBON 99
additem ITEM_GOLDBONBON 99
additem ITEM_SUESSBONBON 99
end
warp 11 2 255 0x1a 0
waitstate
end

setvar 0x8004 ROAMER_LAVADOS
special SPECIAL_ROAMER_RESET_AND_INITIALIZE
setflag POKEDEX_FEATURE_0
end

clearflag FLAG_FOREST_CEMETERY_DONE
setvar STORY_PROGRESS 0x37
end

setflag TRANS_DISABLE
callasm river_puzzle_initialize
end

setflag TRANS_DISABLE
callasm incubator_initialize
waitstate
end
settrainerflag 0xb7
trainerbattlecont 0x1 0xb7 0x0 str_0x83114c str_0x8311a8 ow_script_0x83108d
setvar 0x8004 6
special 0x19
waitstate
cont_end:
end

givepokemon POKEMON_LEDYBA 12 0 0 0 0
additem ITEM_LICHTLEHM 1
end
givepokemon POKEMON_KECLEON_PURPLE 35 0 0 0 0
end
setflag PLAYER_CAN_ENTER_DUNGEONS
setflag FRBADGE_5
setflag FRBADGE_6
setflag FRBADGE_7
additem ITEM_VM03 1
additem ITEM_TM43 1
additem ITEM_VM08 1
setflag FRBADGE_8
callasm debug_vars
callasm debug_flags
@ goto ow_script_dungeon2_enter_ocean
end
*/