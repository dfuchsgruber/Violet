.include "overworld_script.s"
.include "flags.s"
.include "levelscript_types.s"
.include "ordinals.s"

.global map_sonnaufeld_levelscripts

map_sonnaufeld_levelscripts:
    .byte LEVELSCRIPT_TYPE_ON_LOAD
    .word close_door
	.byte LEVELSCRIPT_TYPE_ON_TRANSITION
    .word worldmapflag_script
	.byte 0x0

worldmapflag_script:
	setworldmapflag WM_TANNS_LAB
    end

close_door:
    checkflag ROUTE_2_TANN_AND_VIOLET_GRUNTS
    gotoif EQUAL end_close_door
    setmaptile 0x17 0x7 0x3c7 1
end_close_door:
    end