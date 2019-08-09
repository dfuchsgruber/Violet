.include "overworld_script.s"
.include "levelscript_types.s"
.include "vars.s"
.include "movements.s"
.include "specials.s"

.global lscr_ceometria_gym_punishment_room

lscr_ceometria_gym_punishment_room:
    .byte LEVELSCRIPT_TYPE_ON_WARP_INTO_MAP_TABLE
    .word player_face_up
    .byte LEVELSCRIPT_TYPE_ON_TRANSITION
    .word initialize_npc
    .byte LEVELSCRIPT_TYPE_ON_FRAME_TABLE
    .word punishment
    .byte 0

player_face_up:
	.hword AKTANIA_FLASHBACK_LSCR_PLAYER_INVISIBLE, 0x0
	.word ow_script_player_face_up
	.hword 0x0

ow_script_player_face_up:
    spriteface 0xff 0x2
    end

initialize_npc:
    callasm ceometria_gym_punishment_room_create_npc
    end

punishment:
    .hword CEOMETRIA_GYM_PUNISHMENT_ROOM_TRIGGER, 0
    .word ow_script_punishment
    .hword 0

ow_script_punishment:
    lockall
    checkflag 0x5FB
    gotoif 1 ow_script_ceometria_gym_punishment_room_npc_move_away
    applymovement 1 mov_down
    waitmovement 0
    special SPECIAL_CEOMETRIA_GYM_PUNISHMENT_ROOM_GET_SCRIPT
    jumpram

mov_down:
    .byte STEP_DOWN, STEP_DOWN, STEP_DOWN, STOP
