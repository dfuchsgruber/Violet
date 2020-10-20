.include "overworld_script.s"
.include "healingplaces.s"

.global map_12_0_laubdorf_pokecenter_levelscripts

map_12_0_laubdorf_pokecenter_levelscripts:
	.byte 0x3
.word healing_place
	.byte 0x5
.word ow_script_init_union_room
	.byte 0x0

healing_place:
    sethealingplace HEALINGPLACE_LAUBDORF
    end