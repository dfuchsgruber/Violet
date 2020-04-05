.include "overworld_script.s"
.include "levelscript_types.s"
.include "vars.s"
.include "flags.s"

.global map_ceometria_clouds_levelscripts

map_ceometria_clouds_levelscripts:
    .byte LEVELSCRIPT_TYPE_ON_LOAD 
    .word levelscript_on_load
	.byte LEVELSCRIPT_TYPE_ON_WARP_INTO_MAP_TABLE
	.word levelscript_player_set_on_cloud
    .byte 0

levelscript_on_load:
    checkflag FLAG_DARK_TOWER_UNLOCKED
    callif 1 ow_script_ceometria_clouds_dark_tower_set_unlocked_door_tiles
    end