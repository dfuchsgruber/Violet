.include "overworld_script.s"
.include "levelscript_types.s"
.include "vars.s"
.include "specials.s"
.include "ordinals.s"

.global map_forest_cemetery_teahs_house_levelscript

map_forest_cemetery_teahs_house_levelscript:
	.byte LEVELSCRIPT_TYPE_ON_TRANSITION
    .word lscr_hide_boy
    .byte 0

lscr_hide_boy:
    // Get the hour (0x4)
    setvar 0x8004 4
    special2 LASTRESULT SPECIAL_TIME_GET
    compare LASTRESULT 1
    gotoif LESS_OR_EQUAL dont_hide
    compare LASTRESULT 23
    gotoif HIGHER_OR_EQUAL dont_hide
    spriteinvisible 1 20 0
dont_hide:
    end
