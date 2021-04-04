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

levelscripts_meriana_city_gym2:
    .byte LEVELSCRIPT_TYPE_ON_LOAD
    .word set_rotating_walls
    .byte 0

set_rotating_walls:
    callasm bluetenbach_gym_set_rotating_doors_blocks
    end
