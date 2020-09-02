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

.equ REFEREE_PERSON_IDX, 2
.equ REFEREE_X, 5
.equ REFEREE_Y, 11

.global str_ceometria_gym_referee
.global levelscripts_ceometria_gym

levelscripts_ceometria_gym:
	.byte LEVELSCRIPT_TYPE_ON_FRAME_TABLE
.word lscr_referee
    .byte LEVELSCRIPT_TYPE_ON_TRANSITION
.word lscr_reset_trainerflags
	.byte 0

lscr_referee:
	.hword VAR_GYM_TIPPS, 4
	.word referee
	.hword 0x0

referee:
    lockall
    setvar 0x8004 REFEREE_PERSON_IDX
    special SPECIAL_SET_TARGET_NPC_TO_VAR
    npc_move_to_player REFEREE_PERSON_IDX
    faceplayer
    loadpointer 0 str_ceometria_gym_referee
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
    callasm ceometria_gym_initialize
    checkflag FRBADGE_5
    gotoif EQUAL dont_reset_trainerflags
    compare DIFFICULTY DIFFICULTY_NORMAL
    gotoif LESS dont_reset_trainerflags 
dont_reset_trainerflags:
    end

.ifdef LANG_GER
str_ceometria_gym_referee:
    .autostring 34 2 "Ich halte nicht viel von soetwas, aber alle Herausforderer dieser Arena schwören darauf, dass die Räume verhext sind.\pVielleicht können dir andere Trainer einen Hinweis darauf geben, welcher Weg der richtige ist?\pIn einer so düsteren und unheimlichen Umgebung zu kämpfen, ist weder für Trainer noch Pokémon leicht.\pDa können einem schonmal vor Angst die Knie schlotternDOTS"
.elseif LANG_EN
.endif