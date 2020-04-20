.include "vars.s"
.include "levelscript_types.s"
.include "overworld_script.s"
.include "callstds.s"
.include "mugshot.s"
.include "vars.s"
.include "flags.s"
.include "movements.s"
.include "specials.s"
.include "songs.s"
.include "ordinals.s"
.include "movements.s"

.global map_blackbeard_ship_cells_floor_levelscripts
.global ow_script_blackbeard_ship_cells_floor_unlock_lucky_cell

.align 4

map_blackbeard_ship_cells_floor_levelscripts:
    .byte LEVELSCRIPT_TYPE_ON_LOAD
    .word setmaptile_script
	.byte 0x0


setmaptile_script:
    checkflag FLAG_BBSHIP_LUCKYS_CELL_UNLOCKED
    callif EQUAL ow_script_blackbeard_ship_cells_floor_unlock_lucky_cell
    end


ow_script_blackbeard_ship_cells_floor_unlock_lucky_cell:
    setmaptile 0x9 0x2 0x2ca 1
    return