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

.global str_silvania_gym_referee
.global levelscripts_silvania_gym
.global ow_script_silvania_gym_remove_red_trees
.global ow_script_silvania_gym_remove_purple_trees
.global ow_script_silvania_gym_remove_golden_trees

ow_script_silvania_gym_remove_red_trees:
    setmaptile 0xc 0x1f 0x28b 0
    setmaptile 0x2 0xb 0x280 0
    setmaptile 0x2 0xa 0x280 0
    setmaptile 0x6 0xb 0x280 0
    setmaptile 0x6 0xa 0x280 0
    return

ow_script_silvania_gym_remove_purple_trees:
    setmaptile 0x1e 0x7 0x28b 0
    setmaptile 0x3 0xa 0x28c 0
    setmaptile 0x3 0x9 0x280 0
    setmaptile 0x5 0xa 0x28c 0
    setmaptile 0x5 0x9 0x280 0
    return

ow_script_silvania_gym_remove_golden_trees:
    setmaptile 0x8 0x10 0x28b 0
    setmaptile 0x4 0x9 0x280 0
    setmaptile 0x4 0x8 0x280 0
    return

levelscripts_silvania_gym:
    .byte LEVELSCRIPT_TYPE_ON_LOAD
.word lscr_setmaptile
	.byte LEVELSCRIPT_TYPE_ON_FRAME_TABLE
.word lscr_referee
    .byte LEVELSCRIPT_TYPE_ON_TRANSITION
.word lscr_reset_trainerflags_and_vars
	.byte 0

lscr_setmaptile:
    checkflag FRBADGE_2
    gotoif NOT_EQUAL gym_not_solved
    call ow_script_silvania_gym_remove_red_trees
    call ow_script_silvania_gym_remove_purple_trees
    call ow_script_silvania_gym_remove_golden_trees
    setvar VAR_TMP_SILVANIA_GYM_RED_TRIGGER 1
    setvar VAR_TMP_SILVANIA_GYM_PURPLE_TRIGGER 1
    setvar VAR_TMP_SILVANIA_GYM_GOLDEN_TRIGGER 1
gym_not_solved:
    end

lscr_referee:
	.hword VAR_GYM_TIPPS, 0x1
	.word referee
	.hword 0x0

referee:
    lockall
    setvar 0x8004 2
    npc_move_to_player 2
    special SPECIAL_SET_TARGET_NPC_TO_VAR
    faceplayer
    loadpointer 0 str_silvania_gym_referee
    callstd MSG
    npc_move_to 2 0x7 0x1c
    applymovement 2 mov_fd
    waitmovement 0
    addvar VAR_GYM_TIPPS 1
    releaseall
    end

mov_fd:
    .byte LOOK_DOWN, STOP

lscr_reset_trainerflags_and_vars:
    checkflag FRBADGE_2
    gotoif EQUAL dont_reset_trainerflags
    compare DIFFICULTY DIFFICULTY_NORMAL
    gotoif LESS dont_reset_trainerflags 
    settrainerflag 0x3f
    settrainerflag 0x3e
    settrainerflag 0x3d
    settrainerflag 0x3a
dont_reset_trainerflags:
    end



.ifdef LANG_GER
str_silvania_gym_referee:
    .autostring 34 2 "Du musst wohl PLAYER sein, nicht?\pRosalie war schon ganz aufgeregt, gegen dich anzutreten.\pAber zuerst musst du dich durch das Heckenlabyrinth kämpfen.\pIch werde dir einen kleinen Tipp geben.\pDie Schalter am Boden öffnen dir Durchgänge in den Hecken.\pMal sehen, ob du es bis zu Rosalie schaffst!"
.elseif LANG_EN
.endif
