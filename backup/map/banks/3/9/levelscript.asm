.include "overworld_script.s"
.include "vars.s"
.include "flags.s"
.include "ordinals.s"

.global map_3_9_laubdorf_levelscripts
map_3_9_laubdorf_levelscripts:
    .byte 3
    .word lscr_setworldmapflag
    .byte 0

lscr_setworldmapflag:
    setworldmapflag WM_LAUBDORF
    checkflag FLAG_DAYCARE_EGG_SPAWNED
    gotoif NOT_EQUAL end_lscr
    movesprite2 0x3 0x22 0x24
    end_lscr:
    end
