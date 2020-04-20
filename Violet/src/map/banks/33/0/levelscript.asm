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

.global map_blackbeard_ship_cells_levelscripts
.global ow_script_blackbeard_ship_cells_open_player_cell
.global ow_script_blackbeard_ship_cells_open_lucky_cell

.align 4

map_blackbeard_ship_cells_levelscripts:
	.byte LEVELSCRIPT_TYPE_ON_FRAME_TABLE
	.word lscr_frame_table
    .byte LEVELSCRIPT_TYPE_ON_LOAD
    .word setmaptile_script
	.byte 0x0

lscr_frame_table:
	.hword STORY_PROGRESS, 0x3e
	.word ow_script_frame_table
    .hword VAR_BBSHIP_THROWN_INTO_CELL, 2
    .word ow_script_throw_into_cell
    .hword 0

ow_script_frame_table:
    lockall
    pause 64
    loadpointer 0 str_0
    show_mugshot MUGSHOT_PLAYER alignment=MUGSHOT_RIGHT message_type=MSG mask_name=0
    playsong MUS_BBSHIP 0
    addvar STORY_PROGRESS 1
    setvar SONG_OVERRIDE 0
    releaseall
    end

setmaptile_script:
    checkflag FLAG_BBSHIP_CELL_UNLOCKED
    gotoif NOT_EQUAL dont_open_player_cell
    compare VAR_BBSHIP_THROWN_INTO_CELL 1 // The door needs to be re-opened
    call ow_script_blackbeard_ship_cells_open_player_cell
dont_open_player_cell:
    checkflag FLAG_BBSHIP_LUCKYS_CELL_UNLOCKED
    callif EQUAL ow_script_blackbeard_ship_cells_open_lucky_cell
    end

ow_script_blackbeard_ship_cells_open_player_cell:
    setmaptile 0x3 0x8 0x2c3 0
    setmaptile 0x4 0x8 0x2c4 0
    return

ow_script_blackbeard_ship_cells_open_lucky_cell:
    setmaptile 0xb 0x8 0x2c3 0
    setmaptile 0xc 0x8 0x2c4 0
    return

ow_script_throw_into_cell:
    lockall
    pause 16
    loadpointer 0 str_1
    callstd MSG
    applymovement 4 mov_2d
    waitmovement 0
    pause 16
    sound 9
    hidesprite 4
    checksound
    pause 64
    // Close the cell
    setmaptile 0x3 0x8 0x2c6 0
    setmaptile 0x4 0x8 0x2c7 0
    special SPECIAL_MAP_UPDATE_BLOCKS
    sound 22
    checksound
    pause 32
    setvar VAR_BBSHIP_THROWN_INTO_CELL 1 // The door needs to be re-opened again
    releaseall
    end

mov_2d:
    .byte STEP_DOWN, STEP_DOWN, STOP

.ifdef LANG_GER
str_0:
    .autostring 34 2 "ArghDOTS\nMein Kopf dröhntDOTS\pDOTS DOTS DOTS\nDOTS DOTS DOTS\pWo bin ich hier?\pDas letzte woran ich mich erinnern kann, ist, dass Lucius mich vom Turm gestoßen hatDOTS"
str_1:
    .autostring 34 2 "So, du kleiner Ausreißer!\pDu bleibst gefälligst in deiner Zelle, ja?\pJemand hat wohl vergessen, sie ordentlich abzuschließen.\pSo viel Glück hast nicht nochmal, Kindchen!"

.elseif LANG_EN

.endif
