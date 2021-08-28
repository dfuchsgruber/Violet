.include "vars.s"
.include "overworld_script.s"
.include "flags.s"
.include "callstds.s"
.include "ordinals.s"
.include "attacks.s"

.equ DTYPE_OCEAN, 3


.global ow_script_dungeon_ocean_collapsing

ow_script_dungeon_ocean_collapsing:
	lockall
	fadesong 0
	loadpointer 0x0 str_dungeon_ocean_collapsing
	callstd MSG
    setvar DUNGEON_TYPE 0
	callasm dungeon2_exit
	waitstate
	end

.ifdef LANG_GER
str_dungeon_ocean_collapsing:
	.autostring 35 2 "Die Wellen scheinen stärker zu werden...\pEs ist wohl sicherer, zurückzukehren!"
.endif

.ifdef LANG_EN
str_dungeon_ocean_collapsing:
	.autostring 35 2 "The waves are getting bigger...\pBetter return now!"
.endif


.global ow_script_dungeon2_enter_ocean
.global ow_script_dungeon2_enter_ocean_field

ow_script_dungeon2_enter_ocean:
	@ Check levelscript state ??
	special 0x187
	compare LASTRESULT 0x2
	gotoif EQUAL ow_script_dungeon2_ocean_none

	loadpointer 0x0 str_dungeon_enter_ocean_0
	callstd MSG_KEEPOPEN

	@ Check if the player has secret power

	checkflag PLAYER_CAN_ENTER_DUNGEONS
	gotoif 0 ow_script_dungeon2_dont_enter_ocean

	checkattack ATTACK_GEHEIMPOWER
	compare LASTRESULT 0x6
	gotoif EQUAL ow_script_dungeon2_dont_enter_ocean
	setanimation 0x0 LASTRESULT
	bufferpartypokemon 0x0 LASTRESULT
	bufferattack 0x1 ATTACK_GEHEIMPOWER

	@ Ask if the dungeon is to be entered

	loadpointer 0x0 str_dungeon_enter_ocean_1
	callstd MSG_YES_NO
	compare LASTRESULT 0
	gotoif 1 ow_script_dungeon2_dont_enter_ocean

ow_script_dungeon2_enter_ocean_field:
	@ Display animation
	doanimation 0x2
	nop
	waitstate
    callasm dungeon2_seed_init
    setvar DUNGEON_STEPS 0
    callasm dungeon_map_entrance_set_flag
    callasm dungeon2_enter_ocean
    waitstate
    end

ow_script_dungeon2_dont_enter_ocean:
	closeonkeypress
ow_script_dungeon2_ocean_none:
	end

.ifdef LANG_GER
str_dungeon_enter_ocean_0:
	.autostring 35 2 "Die Felsen scheinen hier nicht sehr hoch aus dem Wasser zu ragen..."

str_dungeon_enter_ocean_1:
	.autostring 35 2 "Möchtest du Geheimpower nutzen, um die Felsen zu überwinden?"
.endif

.ifdef LANG_EN
str_dungeon_enter_ocean_0:
	.autostring 35 2 "The rocks do not sick out very high here..."

str_dungeon_enter_ocean_1:
	.autostring 35 2 "Do you want to use Secret Power to overcome the rocks?"
.endif


