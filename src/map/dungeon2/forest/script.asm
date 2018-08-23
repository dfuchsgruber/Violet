.include "vars.s"
.include "overworld_script.s"
.include "flags.s"
.include "callstds.s"

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
	.autostring 36 2 "Irgendetwas scheint im Unterholz zu lauern...\pEs ist vermutlich besser, den Ort zu verlassen!"
.endif

.ifdef LANG_EN
str_dungeon_forest_collapsing:
	.autostring 36 2 "Something seems to lurk in the underwood...\pBetter leave this place!"
.endif

.global ow_script_test
ow_script_test:
setflag PLAYER_CAN_ENTER_DUNGEONS
goto ow_script_dungeon2_enter_ocean
end


.global ow_script_dungeon2_enter_forest

ow_script_dungeon2_enter_forest:
	loadpointer 0x0 str_dungeon_enter_forest_0
	callstd MSG_KEEPOPEN
	checkflag PLAYER_CAN_ENTER_DUNGEONS
	gotoif 0 ow_script_dungeon2_dont_enter_forest
	loadpointer 0x0 str_dungeon_enter_forest_1
	callstd MSG_YES_NO
	compare LASTRESULT 0
	gotoif 1 ow_script_dungeon2_dont_enter_forest
    callasm dungeon2_seed_init
    setvar DUNGEON_TYPE DTYPE_FOREST
    setvar DUNGEON_STEPS 0
    callasm dungeon_map_entrance_set_flag
    callasm dungeon2_enter_forest
    waitstate
    end

ow_script_dungeon2_dont_enter_forest:
	closeonkeypress
	end

.ifdef LANG_GER
str_dungeon_enter_forest_0:
	.autostring 36 2 "Das Unterholz scheint hier nicht all zu dicht zu sein..."

str_dungeon_enter_forest_1:
	.autostring 36 2 "Möchtest du das Laz.Gear benutzen, um das Unterholz zu erkunden?"
.endif

.ifdef LANG_EN
str_dungeon_enter_forest_0:
	.autostring 36 2 "The underwood seems to be light arround here..."

str_dungeon_enter_forest_1:
	.autostring 36 2 "Do you want to use the Laz.Gear in order to enter the underwood?"
.endif
