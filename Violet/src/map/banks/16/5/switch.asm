.include "overworld_script.s"
.include "specials.s"
.include "flags.s"
.include "ordinals.s"

.global ow_script_route_5_clouds_cave_switch

.macro set_switch_1 x:req y:req
    setmaptile \x, \y, 0x3BD, 0
    setmaptile \x + 1, \y, 0x3BE 0
    setmaptile \x + 2, \y, 0x59 0
    setmaptile \x, \y + 1, 0x3C5 0
    setmaptile \x + 1, \y + 1, 0x3C6 1
    setmaptile \x + 2, \y + 1, 0x3C7 0
.endm


.macro set_switch_2 x:req y:req
    setmaptile \x, \y, 0x3F3 0
    setmaptile \x + 1, \y, 0x3F4 0
    setmaptile \x + 2, \y, 0x3F5 0
    setmaptile \x, \y + 1, 0x3FB 0
    setmaptile \x + 1, \y + 1, 0x3FC 1
    setmaptile \x + 2, \y + 1, 0x3FD 0
.endm

.macro show_north x:req y:req
    setmaptile \x, \y, 0x2e3 1
    setmaptile \x + 1, \y, 0x2e4 0
    setmaptile \x + 2, \y, 0x2e5 1
    setmaptile \x, \y + 1, 0x2e3 1
    setmaptile \x + 1, \y + 1, 0x2e4 0
    setmaptile \x + 2, \y + 1, 0x2e5 1
.endm

.macro hide_north x:req y:req
    setmaptile \x, \y, 0x3d8 1
    setmaptile \x + 1, \y, 0x3d3 1
    setmaptile \x + 2, \y, 0x3d9 1
    setmaptile \x, \y + 1, 0x3e0 1
    setmaptile \x + 1, \y + 1, 0x3da 1
    setmaptile \x + 2, \y + 1, 0x3e1 1
.endm

.macro show_horizontal x:req y:req
    setmaptile \x, \y, 0x336 1
    setmaptile \x, \y + 1, 0x33e 0
    setmaptile \x, \y + 2, 0x346 1
    setmaptile \x + 1, \y, 0x336 1
    setmaptile \x + 1, \y + 1, 0x33e 0
    setmaptile \x + 1, \y + 2, 0x346 1
.endm

.macro hide_horizontal x:req y:req
    setmaptile \x, \y, 0x2A9 1
    setmaptile \x, \y + 1, 0x3BB 1
    setmaptile \x, \y + 2, 0x3C3 1
    setmaptile \x + 1, \y, 0x2A9 1
    setmaptile \x + 1, \y + 1, 0x3BC 1
    setmaptile \x + 1, \y + 2, 0x3C4 1
.endm

.macro show_north_2 x:req y:req
    setmaptile \x, \y, 0x2DE, 1
    setmaptile \x + 1, \y, 0x2DF, 0
    setmaptile \x + 2, \y, 0x2E6, 1
    setmaptile \x, \y + 1, 0x2F4, 1
    setmaptile \x + 1, \y + 1, 0x2F5, 0
    setmaptile \x + 2, \y + 1, 0x2F6, 1
.endm

.macro hide_north_2 x:req y:req
    setmaptile \x, \y, 0x3C9, 1
    setmaptile \x + 1, \y, 0x3CA, 1
    setmaptile \x + 2, \y, 0x3CB, 1
    setmaptile \x, \y + 1, 0x3E2, 1
    setmaptile \x + 1, \y + 1, 0x3DB, 1
    setmaptile \x + 2, \y + 1, 0x3E3, 1
.endm

switch_toggle_1:
    set_switch_1 16 39
    set_switch_1 25 23
    show_north 19 32
    show_north 55 17
    hide_horizontal 47 37
    hide_horizontal 64 25
    show_horizontal 28 37
    hide_north_2 41 14
    return


switch_toggle_2:
    set_switch_2 16 39
    set_switch_2 25 23
    hide_north 19 32
    hide_north 55 17
    show_horizontal 47 37
    show_horizontal 64 25
    hide_horizontal 28 37
    show_north_2 41 14
    return


ow_script_route_5_clouds_cave_switch:
    checkflag FLAG_ROUTE_5_CLOUDS_CAVE_SWITCH
    callif NOT_EQUAL switch_toggle_1
    checkflag FLAG_ROUTE_5_CLOUDS_CAVE_SWITCH
    callif EQUAL switch_toggle_2
    return
