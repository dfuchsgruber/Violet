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

.global str_silvania_gym_referee
.global levelscripts_silvania_gym

levelscripts_silvania_gym:
	.byte LEVELSCRIPT_TYPE_ON_FRAME_TABLE
.word lscr_referee
    .byte LEVELSCRIPT_TYPE_ON_TRANSITION
.word lscr_reset_trainerflags_and_vars
	.byte 0

lscr_referee:
	.hword VAR_GYM_TIPPS, 0x1
	.word referee
	.hword 0x0

referee:
    lockall
    setvar 0x8004 2
    special SPECIAL_SET_TARGET_NPC_TO_VAR
    special SPECIAL_NPC_MOVE_TO_PLAYER
    waitmovement 0
    faceplayer
    loadpointer 0 str_silvania_gym_referee
    callstd MSG
    setvar 0x8004 2
    setvar 0x8005 0x4
    setvar 0x8006 0x10
    special SPECIAL_NPC_MOVE_TO
    waitmovement 0
    applymovement 2 mov_fd
    waitmovement 0
    addvar VAR_GYM_TIPPS 1
    releaseall
    end

mov_fd:
    .byte LOOK_DOWN, STOP

lscr_reset_trainerflags_and_vars:
    setvar VAR_SIVLANIA_GYM_SWITCH 0
    setvar VAR_SILVANIA_GYM_GOLDEN_SWITCH 0
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
    .autostring 34 2 "Nanu!\nDu willst schon wieder einen Arenaleiter herausfordern?\pSei gewarnt, Mia mag zwar wie ein Engel wirken, verwandelt sich aber auf dem Kampffeld in ein Teufelchen!\pIhre Pflanzen-Pokémon sind widerspenstig und nicht kleinzukriegen.\pUnd in dieser Arena wächst und gedeit praktisch alles.\pNur ein schneller und effektiver Angriff kann dir hier zum Sieg verhelfen!"
.elseif LANG_EN
.endif
