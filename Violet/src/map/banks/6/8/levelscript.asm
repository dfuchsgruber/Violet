.include "items.s"
.include "callstds.s"
.include "flags.s"
.include "movements.s"
.include "overworld_script.s"
.include "mugshot.s"
.include "specials.s"
.include "vars.s"
.include "levelscript_types.s"
.include "difficulties.s"
.include "ordinals.s"
.include "person_behaviours.s"

.global levelscripts_bruchfels_gym_room_1

levelscripts_bruchfels_gym_room_1:
    .byte LEVELSCRIPT_TYPE_ON_LOAD
    .word lscr_setmaptile
    .byte LEVELSCRIPT_TYPE_ON_TRANSITION
    .word lscr_move_boulders
	.byte 0

lscr_setmaptile:
    checkflag FLAG_BRUCHFELS_GYM_PUZZLE_ROOM_1_SOLVED
    callif EQUAL ow_script_bruchfels_gym_puzzle_room_1_open_door
    end

lscr_move_boulders:
    checkflag FLAG_BRUCHFELS_GYM_PUZZLE_ROOM_1_SOLVED
    gotoif NOT_EQUAL dont_move_boulders
    movesprite2 1 0x1 0x5
    spritebehave 1 BEHAVIOUR_FACE_LEFT
    movesprite2 3 0x5 0x5
    spritebehave 3 BEHAVIOUR_FACE_UP
    movesprite2 2 2 9
    spritebehave 2 BEHAVIOUR_FACE_LEFT
dont_move_boulders:
    end
