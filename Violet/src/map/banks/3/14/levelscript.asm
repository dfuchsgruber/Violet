.include "overworld_script.s"
.include "vars.s"
.include "flags.s"
.include "ordinals.s"
.include "specials.s"
.include "levelscript_types.s"

.global map_3_14_ceometria_levelscripts
map_3_14_ceometria_levelscripts:
    .byte LEVELSCRIPT_TYPE_ON_TRANSITION
    .word lscr_on_transition
    .byte 0

lscr_on_transition:
    end
