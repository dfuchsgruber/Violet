.include "std.s"
.include "overworld_script.s"


.global ow_script_dungeon2_enter

ow_script_dungeon2_enter:
    callasm dungeon2_init_map_interface
    setflag MAP_LOAD_DYNAMIC
    setvar DUNGEON_STEPS 0
    warp 3 3 255 0 0
    waitstate
    end
