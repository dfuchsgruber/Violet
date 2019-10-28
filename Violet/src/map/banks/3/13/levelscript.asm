.include "overworld_script.s"
.include "vars.s"
.include "flags.s"
.include "ordinals.s"
.include "levelscript_types.s"

.global map_3_13_ceometria_levelscripts
map_3_13_ceometria_levelscripts:
    .byte 3
    .word lscr_setworldmapflag
    .byte LEVELSCRIPT_TYPE_ON_LOAD
    .word close_gym
    .byte 0

lscr_setworldmapflag:
    setworldmapflag WM_CEOMETRIA
    end

close_gym:
    checkflag FLAG_FOREST_CEMETERY_DONE
    gotoif EQUAL gym_open

    setmaptile 0xB 0x24 0x3B0 0 level=0x1
    setmaptile 0xC 0x24 0x3B1 0 level=0x1
    setmaptile 0xD 0x24 0x3B2 0 level=0x1
    setmaptile 0xE 0x24 0x3B3 0 level=0x1
    setmaptile 0xF 0x24 0x3A3 0 level=0x1

    setmaptile 0xB 0x25 0x3B8 0 level=0x1
    setmaptile 0xC 0x25 0x3B9 0 level=0x1
    setmaptile 0xD 0x25 0x3BA 0 level=0x1
    setmaptile 0xE 0x25 0x3BB 0 level=0x1
    setmaptile 0xF 0x25 0x3AA 0 level=0x1

gym_open:
    end