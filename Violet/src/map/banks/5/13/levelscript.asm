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

.equ REFEREE_PERSON_IDX, 11
.equ REFEREE_X, 0xB
.equ REFEREE_Y, 0xB

.global str_meriana_city_gym_referee
.global levelscripts_meriana_city_gym

levelscripts_meriana_city_gym:
	.byte LEVELSCRIPT_TYPE_ON_FRAME_TABLE
.word lscr_referee
    .byte LEVELSCRIPT_TYPE_ON_TRANSITION
.word lscr_reset_trainerflags
	.byte 0

lscr_referee:
	.hword VAR_GYM_TIPPS, 2
	.word referee
	.hword 0x0

referee:
    lockall
    setvar 0x8004 REFEREE_PERSON_IDX
    special SPECIAL_SET_TARGET_NPC_TO_VAR
    npc_move_to_player REFEREE_PERSON_IDX
    faceplayer
    loadpointer 0 str_meriana_city_gym_referee
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
    end

.ifdef LANG_GER
str_meriana_city_gym_referee:
    .autostring 34 2 "Schon ein Weilchen her, seit ich dir zuletzt gesehen habe!\pIch hatte schon befürchtet, du hättest aufgegeben!\pFreut mich, dich hier zu treffen!\pManus ist ein harter Brocken.\pSeine Kampf-Pokémon teilen ordentlich aus, können aber auch einstecken.\pDurchhaltevermögen ist hier gefragt!\pUnd die ganzen Zuschauer, die Manus' Pokémon anfeuern, machen dir die Sache nicht unbedingt leichterDOTS"
.elseif LANG_EN
.endif
