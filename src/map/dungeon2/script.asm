.include "std.s"
.include "overworld_script.s"


.global ow_script_dungeon2_enter_forest

ow_script_dungeon2_enter_forest:
    callasm dungeon2_init_map_interface_forest
    setvar DUNGEON_TYPE DTYPE_FOREST
    setvar DUNGEON_STEPS 0
    warp 3 3 255 0 0
    waitstate
    end

.global ow_script_dungeon2_enter_cave

ow_script_dungeon2_enter_cave:
    @//TODO 
    callasm dungeon2_init_map_interface_forest
    setvar DUNGEON_TYPE DTYPE_FOREST
    setvar DUNGEON_STEPS 0
    warp 3 3 255 0 0
    waitstate
    end
