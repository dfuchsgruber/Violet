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
.include "healingplaces.s"

.global map_blackbeard_ship_deck_levelscripts
.global ow_script_blackbeard_ship_deck_open_captain_cabin

.align 4

map_blackbeard_ship_cells_levelscripts:
	// .byte LEVELSCRIPT_TYPE_ON_FRAME_TABLE
	// .word lscr_frame_table
    .byte LEVELSCRIPT_TYPE_ON_LOAD
    .word setmaptile_script
	.byte 0x0

setmaptile_script:
    checkflag FLAG_BBSHIP_CAPTAIN_ROOM_UNLOCKED
    callif EQUAL ow_script_blackbeard_ship_deck_open_captain_cabin
    end

ow_script_blackbeard_ship_deck_open_captain_cabin:
    setmaptile 0x48 0x28 0x2ca 1
    return
