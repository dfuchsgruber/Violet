.include "vars.s"
.include "overworld_script.s"
.include "flags.s"
.include "callstds.s"

.equ DTYPE_FOREST, 1
.equ DTYPE_CAVE, 2

.global ow_script_dungeon_item

ow_script_dungeon_item:
	copyvarifnotzero 0x8004 LASTTALKED
	callasm dungeon_special_item_by_overworld_idx
	copyvarifnotzero 0x8000 0x8005
	copyvarifnotzero 0x8001 1
	callstd ITEM_FIND
	end


.global ow_script_dungeon_encounter

ow_script_dungeon_encounter:
	lock
	faceplayer
	cry DUNGEON_OVERWORLD_SPECIES 0
	waitcry
	callasm dungeon2_set_encounter
	dowildbattle
	fadescreen 1
	hidesprite LASTTALKED
	fadescreen 0
	release
	end

.global ow_script_dungeon2_enter_forest

ow_script_dungeon2_enter_forest:
    callasm dungeon2_seed_init
    setvar DUNGEON_TYPE DTYPE_FOREST 
    setvar DUNGEON_STEPS 0
    callasm dungeon2_enter_forest
    waitstate
    end

.global ow_script_dungeon2_enter_cave

ow_script_dungeon2_enter_cave:
    @//TODO 
    // callasm dungeon2_init_map_interface_forest
    setvar DUNGEON_TYPE DTYPE_FOREST
    setvar DUNGEON_STEPS 0
    warp 3 3 255 0 0
    waitstate
    end
