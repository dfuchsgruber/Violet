.include "vars.s"
.include "overworld_script.s"
.include "flags.s"
.include "callstds.s"

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
	.autostring 40 2 "Die Höhle scheint nicht stabil zu sein...\pSchnell zum Ausgang, bevor sie einstürtzt!"
.endif

.ifdef LANG_EN
str_dungeon_cave_collapsing:
	.autostring 40 2 "The cave does not seem to be stable...\pBetter find the exit before it collapses!"
.endif


.global ow_script_dungeon2_enter_cave

ow_script_dungeon2_enter_cave:
    callasm dungeon2_seed_init
    setvar DUNGEON_TYPE DTYPE_CAVE
    setvar DUNGEON_STEPS 0
    callasm dungeon2_enter_cave
    waitstate
    end
