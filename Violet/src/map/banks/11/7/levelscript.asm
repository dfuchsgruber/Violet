.include "vars.s"
.include "callstds.s"
.include "mugshot.s"
.include "ordinals.s"
.include "overworld_script.s"
.include "flags.s"
.include "person_behaviours.s"
.include "levelscript_types.s"

.global map_route_2_clouds_cave_eg_levelscripts

map_route_2_clouds_cave_eg_levelscripts:
	.byte LEVELSCRIPT_TYPE_ON_TRANSITION
.word ow_script_move_hiker
	.byte 0x0

ow_script_move_hiker:
    checkflag FLAG_ROUTE_2_CLOUDS_ICE_CAVE_ENTRANCE
    callif EQUAL move_hiker
    end

move_hiker:
    movesprite2 0x6 0xd 0x6
    spritebehave 0x6 BEHAVIOUR_FACE_RIGHT
    return
