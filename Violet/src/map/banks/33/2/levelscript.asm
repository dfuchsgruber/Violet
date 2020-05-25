
.include "vars.s"
.include "levelscript_types.s"
.include "overworld_script.s"
.include "flags.s"
.include "person_behaviours.s"
.include "ordinals.s"

.global map_blackbeard_ship_storage_levelscripts
.global ow_script_blackbeard_ship_storage_open_treasure_room
.align 4

map_blackbeard_ship_storage_levelscripts:
    .byte LEVELSCRIPT_TYPE_ON_TRANSITION
    .word transition_script
    .byte LEVELSCRIPT_TYPE_ON_LOAD
    .word setmaptile_script
	.byte 0x0

setmaptile_script:
    checkflag FLAG_BBSHIP_CAPTAIN_ROOM_UNLOCKED
    callif EQUAL ow_script_blackbeard_ship_storage_open_treasure_room
    end

ow_script_blackbeard_ship_storage_open_treasure_room:
    setmaptile 0x25 0x20 0x2ca 1
    return

transition_script:
    checkflag FLAG_BBSHIP_LUCKY_IN_CELL
    gotoif NOT_EQUAL roadblock
    // The npc only starts moving, once lucky is out of his cell
    movesprite2 0x2 0x1c 0x20
    spritebehave 0x2 BEHAVIOUR_WALK_LEFT_AND_RIGHT
roadblock:
    end