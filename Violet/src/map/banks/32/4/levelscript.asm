.include "overworld_script.s"
.include "levelscript_types.s"
.include "vars.s"

.global map_dark_tower_top_levelscripts

map_dark_tower_top_levelscripts:
    .byte LEVELSCRIPT_TYPE_ON_LOAD
    .word setmaptile_script
    .byte 0

setmaptile_script:
    compare VAR_DARK_TOWER_TRIGGER_LEFT 0x64
    callif 1 move_left
    compare VAR_DARK_TOWER_TRIGGER_RIGHT 0x64
    callif 1 move_right
    end

move_left:
    setmaptile 0x9 0x6 0x281 0
    return
move_right:
    setmaptile 0x9 0x7 0x281 0
    return
    
