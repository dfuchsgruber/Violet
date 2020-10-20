.include "overworld_script.s"
.include "levelscript_types.s"
.include "vars.s"

.global map_dark_tower_floor_1_levelscripts

map_dark_tower_floor_1_levelscripts:
    .byte LEVELSCRIPT_TYPE_ON_TRANSITION
    .word on_transition
    .byte 0

on_transition:
    compare VAR_DARK_TOWER_TRIGGER_LEFT 0x64
    callif 1 move_left
    compare VAR_DARK_TOWER_TRIGGER_RIGHT 0x64
    callif 1 move_right
    end

move_left:
    movesprite2 1 0x8 0x3
    return
move_right:
    movesprite2 2 0xa 0x3
    return
    
