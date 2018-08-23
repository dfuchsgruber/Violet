.include "vars.s"
.include "overworld_script.s"
.include "flags.s"
.include "callstds.s"
.include "ordinals.s"

.equ DTYPE_CAVE, 2


.global ow_script_dungeon_cave_collapsing

ow_script_dungeon_cave_collapsing:
	lockall
	fadesong 0
	loadpointer 0x0 str_dungeon_cave_collapsing
	callstd MSG
    setvar DUNGEON_TYPE 0
	callasm dungeon2_exit
	waitstate
	end

.ifdef LANG_GER
str_dungeon_cave_collapsing:
	.autostring 36 2 "Die Höhle scheint nicht stabil zu sein...\pSchnell zum Ausgang, bevor sie einstürtzt!"
.endif

.ifdef LANG_EN
str_dungeon_cave_collapsing:
	.autostring 36 2 "The cave does not seem to be stable...\pBetter find the exit before it collapses!"
.endif


.global ow_script_dungeon2_enter_cave

ow_script_dungeon2_enter_cave:
	loadpointer 0x0 str_dungeon_enter_cave_0
	callstd MSG_KEEPOPEN
	checkflag PLAYER_CAN_ENTER_DUNGEONS
	gotoif 0 ow_script_dungeon2_dont_enter_cave
	loadpointer 0x0 str_dungeon_enter_cave_1
	callstd MSG_YES_NO
	compare LASTRESULT 0
	gotoif 1 ow_script_dungeon2_dont_enter_cave
    callasm dungeon2_seed_init
    setvar DUNGEON_TYPE DTYPE_CAVE
    setvar DUNGEON_STEPS 0
    callasm dungeon_map_entrance_set_flag
    callasm dungeon2_enter_cave
    waitstate
    end

ow_script_dungeon2_dont_enter_cave:
	closeonkeypress
	end

.ifdef LANG_GER
str_dungeon_enter_cave_0:
	.autostring 36 2 "Eine Höhle scheint sich hinter dieser Felswand zu verbergen..."

str_dungeon_enter_cave_1:
	.autostring 36 2 "Möchtest du das Laz.Gear benutzen, um die Höhle zu betreten?"
.endif

.ifdef LANG_EN
str_dungeon_enter_cave_0:
	.autostring 36 2 "There seems to be some kind of cave behind this rock face..."

str_dungeon_enter_cave_1:
	.autostring 36 2 "Do you want to use the Laz.Gear in order to enter the cave?"
.endif


