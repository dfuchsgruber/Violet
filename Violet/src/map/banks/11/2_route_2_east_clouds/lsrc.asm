.include "vars.s"

.global lscr_route_2_east_clouds

lscr_route_2_east_clouds:
	.byte 0x4
.word type_4
	.byte 0x0


type_4:
	.hword MERIANA_ARENA_TRIGGER, 0x0
	.word ow_script_0x80ed2e
	.hword 0x0
