.include "overworld_script.s"
.include "callstds.s"
.include "flags.s"
.include "specials.s"

.global ow_script_blackbeard_ship_cells_floor_lucky_door

ow_script_blackbeard_ship_cells_floor_lucky_door:
    lockall
    pause 16
    sound 46
    call ow_script_blackbeard_ship_cells_floor_unlock_lucky_cell
    special SPECIAL_MAP_UPDATE_BLOCKS
    setflag FLAG_BBSHIP_LUCKYS_CELL_UNLOCKED
    checksound
    loadpointer 0 str_0
    callstd MSG
    releaseall
    end

.ifdef LANG_GER
str_0:
    .autostring 34 2 "PLAYER benutzt den Zellenschlüssel, um die Zelle von Lucky zu öffnen."
.elseif LANG_EN
.endif