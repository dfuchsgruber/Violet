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
.include "pathfinding.s"

.equ REFEREE_PERSON_IDX, 7
.equ REFEREE_X, 20
.equ REFEREE_Y, 37

.global str_inferior_gym_referee
.global levelscripts_inferior_gym

levelscripts_inferior_gym:
	.byte LEVELSCRIPT_TYPE_ON_FRAME_TABLE
.word lscr_referee
    .byte LEVELSCRIPT_TYPE_ON_TRANSITION
.word lscr_reset_trainerflags
	.byte 0

lscr_referee:
	.hword VAR_GYM_TIPPS, 3
	.word referee
	.hword 0x0

referee:
    lockall
    setvar 0x8004 REFEREE_PERSON_IDX
    special SPECIAL_SET_TARGET_NPC_TO_VAR
    npc_move_to_player REFEREE_PERSON_IDX
    faceplayer
    loadpointer 0 str_inferior_gym_referee
    callstd MSG
    npc_move_to REFEREE_PERSON_IDX REFEREE_X REFEREE_Y
    applymovement REFEREE_PERSON_IDX mov_fd
    waitmovement 0
    addvar VAR_GYM_TIPPS 1
    releaseall
    end

mov_fd:
    .byte LOOK_DOWN, STOP

lscr_reset_trainerflags:
    checkflag FRBADGE_4
    gotoif EQUAL dont_reset_trainerflags
    compare DIFFICULTY DIFFICULTY_NORMAL
    gotoif LESS dont_reset_trainerflags 
    settrainerflag 0xbf
    settrainerflag 0xc0
    settrainerflag 0xc1
    settrainerflag 0xc2
    settrainerflag 0xc3
dont_reset_trainerflags:
    end
    end

.ifdef LANG_GER
str_inferior_gym_referee:
    .autostring 34 2 "Wahnsinn, ist es hier drinnen heiß, nicht wahr?\pWenn du Igva besiegen möchtest, musst du ganz schön hitzeresistent sein.\pDa können deine Pokémon auch schonmal das Brennen anfangenDOTS"
.elseif LANG_EN
.endif
