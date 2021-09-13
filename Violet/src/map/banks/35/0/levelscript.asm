.include "vars.s"
.include "levelscript_types.s"
.include "healingplaces.s"
.include "overworld_script.s"

.global map_sonnaufeld_pokestop_levelscripts

map_sonnaufeld_pokestop_levelscripts:
	.byte LEVELSCRIPT_TYPE_ON_TRANSITION
.word healing_place
	.byte LEVELSCRIPT_TYPE_ON_RESUME
.word ow_script_init_union_room
	.byte 0x0

healing_place:
	sethealingplace HEALINGPLACE_TANNS_LAB
    end
