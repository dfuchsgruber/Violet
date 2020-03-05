.include "vars.s"
.include "levelscript_types.s"

.global lscr_0x71dfbc

lscr_0x71dfbc:
	.byte LEVELSCRIPT_TYPE_ON_WARP_INTO_MAP_TABLE
	.word levelscript_player_set_on_cloud
	.byte 0x0


.align 4
.global levelscript_player_set_on_cloud

levelscript_player_set_on_cloud:
	.hword MERIANA_ARENA_TRIGGER, 0x0
	.word ow_script_set_player_on_cloud
	.hword 0x0
