
.include "ordinals.s"
.include "vars.s"
.include "overworld_script.s"
.include "levelscript_types.s"
.include "healingplaces.s"

.global map_desert_tent_levelscripts

map_desert_tent_levelscripts:
	.byte LEVELSCRIPT_TYPE_ON_TRANSITION
    .word script_set_healingplace
	.byte 0x0

script_set_healingplace:
	sethealingplace HEALINGPLACE_DESERT
    end
