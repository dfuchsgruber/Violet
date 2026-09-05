.include "overworld_script.s"
.include "levelscript_types.s"

.global lscr_clouds_mine

lscr_clouds_mine:
    .byte LEVELSCRIPT_TYPE_ON_LOAD
    .word on_load
    .byte 0x0

on_load:
    call ow_script_route_5_clouds_cave_switch
    end