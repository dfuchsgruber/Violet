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

.global levelscripts_meriana_city_gym2
.global str_bluetenbach_gym_referee

levelscripts_meriana_city_gym2:
    .byte LEVELSCRIPT_TYPE_ON_LOAD
    .word set_rotating_walls
    .byte LEVELSCRIPT_TYPE_ON_FRAME_TABLE
    .word lscr_referee
    .byte 0

set_rotating_walls:
    callasm bluetenbach_gym_set_rotating_doors_blocks
    end


lscr_referee:
	.hword VAR_GYM_TIPPS, 0x2
	.word referee
	.hword 0x0

referee:
    lockall
    setvar 0x8004 9
    npc_move_to_player 9
    special SPECIAL_SET_TARGET_NPC_TO_VAR
    faceplayer
    loadpointer 0 str_bluetenbach_gym_referee
    callstd MSG
    npc_move_to 9 0xa 0x12
    applymovement 9 mov_fd
    waitmovement 0
    addvar VAR_GYM_TIPPS 1
    releaseall
    end



.ifdef LANG_GER
str_bluetenbach_gym_referee:
    .autostring 34 2 "Ah, du bist PLAYER, nicht?\pManuel hat mir von einem ungewöhnlichen Herausforderer erzählt.\pIn dieser Arena geht es um Kraft im Körper aber auch im Geist.\pIch möchte nicht zu viel verratenDOTS\pAber die Wände hier bewegen sich, wenn du den Gong schlägst.\pOben im Turm erwartet dich dann Manuel.\pMal sehen, ob du es bis dorthin schaffst."
.elseif LANG_EN
.endif

