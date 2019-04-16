.include "levelscript_types.s"

.global lscr_route_2_east_clouds

lscr_route_2_east_clouds:
	.byte LEVELSCRIPT_TYPE_ON_WARP_INTO_MAP_TABLE
	.word levelscript_player_set_on_cloud
	.byte 0x0
