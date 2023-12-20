.include "overworld_script.s"
.include "levelscript_types.s"
.include "vars.s"
.include "specials.s"
.include "ordinals.s"
.include "flags.s"

.global map_forest_cemetery_teahs_house_levelscript

map_forest_cemetery_teahs_house_levelscript:
	.byte LEVELSCRIPT_TYPE_ON_TRANSITION
    .word on_transition
    .byte 0

on_transition:
    // Get the hour (0x4)
    setflag FLAG_TEAHS_HOUSE
    setvar 0x8004 4
    special2 LASTRESULT SPECIAL_TIME_GET
    compare LASTRESULT 1
    gotoif LESS_OR_EQUAL dont_hide
    compare LASTRESULT 23
    gotoif HIGHER_OR_EQUAL dont_hide
    spriteinvisible 1 20 0
dont_hide:
    end
