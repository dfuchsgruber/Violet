
.include "vars.s"
.include "levelscript_types.s"
.include "overworld_script.s"
.include "flags.s"
.include "person_behaviours.s"
.include "ordinals.s"

.global map_blackbeard_ship_storage_levelscripts
.align 4

map_blackbeard_ship_storage_levelscripts:
    .byte LEVELSCRIPT_TYPE_ON_TRANSITION
    .word transition_script
	.byte 0x0

transition_script:
    checkflag FLAG_BBSHIP_LUCKY_IN_CELL
    gotoif NOT_EQUAL roadblock
    // The npc only starts moving, once lucky is out of his cell
    movesprite2 0x2 0x1c 0x20
    spritebehave 0x2 BEHAVIOUR_LAUFE_HIN_UND_HER
roadblock:
    end