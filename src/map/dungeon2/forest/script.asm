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
	.autostring 40 2 "Irgendetwas scheint im Unterholz zu lauern...\pEs ist vermutlich besser, den Ort zu verlassen!"
.endif

.ifdef LANG_EN
str_dungeon_forest_collapsing:
	.autostring 40 2 "Something seems to lurk in the underwood...\pBetter leave this place!"
.endif


.global ow_script_dungeon2_enter_forest

ow_script_dungeon2_enter_forest:
    callasm dungeon2_seed_init
    setvar DUNGEON_TYPE DTYPE_FOREST
    setvar DUNGEON_STEPS 0
    callasm dungeon2_enter_forest
    waitstate
    end
