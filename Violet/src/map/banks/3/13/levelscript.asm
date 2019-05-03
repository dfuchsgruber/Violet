.include "overworld_script.s"
.include "vars.s"
.include "flags.s"
.include "ordinals.s"

.global map_3_13_ceometria_levelscripts
map_3_13_ceometria_levelscripts:
    .byte 3
    .word lscr_setworldmapflag
    .byte 0

lscr_setworldmapflag:
    setworldmapflag WM_CEOMETRIA
    end
