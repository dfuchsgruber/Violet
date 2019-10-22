.include "overworld_script.s"
.include "healingplaces.s"

.global map_13_0_ceometria_pokestop_levelscripts

map_13_0_ceometria_pokestop_levelscripts:
	.byte 0x3
.word healing_place
	.byte 0x5
.word ow_script_0x1bf89b
	.byte 0x0

healing_place:
    sethealingplace HEALINGPLACE_CEOMETRIA
    end