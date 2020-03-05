.include "overworld_script.s"
.include "levelscript_types.s"
.include "vars.s"

.global map_14_0_route_9_clouds_levelscripts

map_14_0_route_9_clouds_levelscripts:
	.byte LEVELSCRIPT_TYPE_ON_WARP_INTO_MAP_TABLE
    .word levelscript_player_set_on_cloud
	.byte 0x0

