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

.equ DTYPE_FOREST, 1

.global ow_script_dungeon_forest_collapsing

ow_script_dungeon_forest_collapsing:
	lockall
	fadesong 0
	loadpointer 0x0 str_dungeon_forest_collapsing
	callstd MSG
    setvar DUNGEON_TYPE 0
	callasm dungeon2_exit
	waitstate
	end

.ifdef LANG_GER
str_dungeon_forest_collapsing:
	.autostring 35 2 "Irgendetwas scheint im Unterholz zu lauern...\pEs ist vermutlich besser, den Ort zu verlassen!"
.endif

.ifdef LANG_EN
str_dungeon_forest_collapsing:
	.autostring 35 2 "Something seems to lurk in the underwood...\pBetter leave this place!"
.endif

.global ow_script_test

ow_script_test:
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


.global ow_script_dungeon2_enter_forest
.global ow_script_dungeon2_enter_forest_field

ow_script_dungeon2_enter_forest:
	@ Check levelscript state ??
	special 0x187
	compare LASTRESULT 0x2
	gotoif EQUAL ow_script_dungeon2_forest_none

	loadpointer 0x0 str_dungeon_enter_forest_0
	callstd MSG_KEEPOPEN

	@ Check if the player has secret power

	checkflag PLAYER_CAN_ENTER_DUNGEONS
	gotoif 0 ow_script_dungeon2_dont_enter_forest

	checkattack ATTACK_GEHEIMPOWER
	compare LASTRESULT 0x6
	gotoif EQUAL ow_script_dungeon2_dont_enter_forest
	setanimation 0x0 LASTRESULT
	bufferpartypokemon 0x0 LASTRESULT
	bufferattack 0x1 ATTACK_GEHEIMPOWER

	@ Ask if the dungeon is to be entered

	loadpointer 0x0 str_dungeon_enter_forest_1
	callstd MSG_YES_NO
	compare LASTRESULT 0
	gotoif 1 ow_script_dungeon2_dont_enter_forest

ow_script_dungeon2_enter_forest_field:
	@ Display animation
	doanimation 0x2
	nop
	waitstate
    callasm dungeon2_seed_init
    setvar DUNGEON_TYPE DTYPE_FOREST
    setvar DUNGEON_STEPS 0
    callasm dungeon_map_entrance_set_flag
    callasm dungeon2_enter_forest
    waitstate
    end

ow_script_dungeon2_dont_enter_forest:
	closeonkeypress
ow_script_dungeon2_forest_none:
	end

.ifdef LANG_GER
str_dungeon_enter_forest_0:
	.autostring 35 2 "Das Unterholz scheint hier nicht allzu dicht zu sein..."

str_dungeon_enter_forest_1:
	.autostring 35 2 "Möchtest du Geheimpower nutzen, um das Dickicht zu zerschneiden?"
.endif

.ifdef LANG_EN
str_dungeon_enter_forest_0:
	.autostring 35 2 "The underwood seems to be light arround here..."

str_dungeon_enter_forest_1:
	.autostring 35 2 "Do you want to use Secret Power to cut the thicket?"
.endif
