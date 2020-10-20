.include "vars.s"
.include "flags.s"
.include "levelscript_types.s"
.include "overworld_script.s"

.global map_meriana_city_levelscripts

map_meriana_city_levelscripts:
	.byte LEVELSCRIPT_TYPE_ON_TRANSITION
.word worldmapflag_script
	.byte 0x0


worldmapflag_script:
setworldmapflag WM_MERIANA_CITY
end
