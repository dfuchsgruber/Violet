.include "vars.s"
.include "levelscript_types.s"
.include "healingplaces.s"
.include "overworld_script.s"

.global map_meriana_city_pokestop_levelscripts

map_meriana_city_pokestop_levelscripts:
	.byte LEVELSCRIPT_TYPE_ON_TRANSITION
.word ow_script_0x16a237
	.byte 0x5
.word ow_script_0x1bf89b
	.byte 0x0

.global ow_script_0x16a237
.global ow_script_0x1bf89b

ow_script_0x16a237:
sethealingplace HEALINGPLACE_MERIANA_CITY
end


ow_script_0x1bf89b:
special 0x182
end
