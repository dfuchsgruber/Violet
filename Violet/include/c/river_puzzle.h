/*
 * river_puzzle.h
 *
 *  Created on: Mar 14, 2019
 *      Author: dominik
 */

#ifndef INCLUDE_C_RIVER_PUZZLE_H_
#define INCLUDE_C_RIVER_PUZZLE_H_

#include "types.h"
#include "map/footer.h"
#include "text.h"
#include "save.h"

#define RIVER_PUZZLE_WEST 0
#define RIVER_PUZZLE_EAST 1
#define RIVER_PUZZLE_BOAT_WEST 2
#define RIVER_PUZZLE_BOAT_EAST 3

typedef struct {
  u8 boat_oam;
  u8 pokemon_oams[6];
  u8 cursor_oam;
  u8 boat[2]; // Which indices are in the boat
  u8 pokemon[6]; // Which indices
  u8 cursor_side; // The side where the cursor is
  u8 cursor; // Where the cursor is at
  u8 callback_idx_list;
} river_puzzle_state_t;

#define RIVER_PUZZLE_STATE ((river_puzzle_state_t*) fmem.gp_state)

/**
 * Callback to handle the state of the river puzzle.
 * @param self self-reference to the callback structures
 */
void river_puzzle_callback_idle(u8 self);

extern const u16 gfx_river_puzzle_uiTiles[];
extern const u16 gfx_river_puzzle_uiMap[];
extern const u16 gfx_river_puzzle_uiPal[];
extern const u16 gfx_river_puzzle_boatTiles[];
extern const u16 gfx_river_puzzle_boatPal[];
extern const u32 gfx_river_puzzle_wigglytuff_lineTiles[];
extern const u16 gfx_river_puzzle_wigglytuff_linePal[];
extern const u32 gfx_river_puzzle_electrivire_lineTiles[];
extern const u16 gfx_river_puzzle_electrivire_linePal[];
extern const u32 gfx_river_puzzle_magmortar_lineTiles[];
extern const u16 gfx_river_puzzle_magmortar_linePal[];
extern const u32 gfx_river_puzzle_cursorTiles[];
extern const u16 gfx_river_puzzle_cursorPal[];
extern const u8 str_river_puzzle_help[];
extern const u8 str_river_puzzle_confirm_exit[];
extern const u8 str_river_puzzle_invalid_configuration[];

#define RIVER_PUZZLE_BABY_POKEMON 1
#define RIVER_PUZZLE_LINE(x) ((x) << 1)
#define RIVER_PUZZLE_WIGGLYTUFF_LINE 0
#define RIVER_PUZZLE_ELECTRIVIRE_LINE 1
#define RIVER_PUZZLE_MAGMORTAR_LINE 2
#define RIVER_PUZZLE_WIGGLYTUFF (RIVER_PUZZLE_LINE(RIVER_PUZZLE_WIGGLYTUFF_LINE))
#define RIVER_PUZZLE_IGGLYTUFF (RIVER_PUZZLE_LINE(RIVER_PUZZLE_WIGGLYTUFF_LINE) | RIVER_PUZZLE_BABY_POKEMON)
#define RIVER_PUZZLE_ELECTRIVIRE (RIVER_PUZZLE_LINE(RIVER_PUZZLE_ELECTRIVIRE_LINE))
#define RIVER_PUZZLE_ELEKID (RIVER_PUZZLE_LINE(RIVER_PUZZLE_ELECTRIVIRE_LINE) | RIVER_PUZZLE_BABY_POKEMON)
#define RIVER_PUZZLE_MAGMORTAR (RIVER_PUZZLE_LINE(RIVER_PUZZLE_MAGMORTAR_LINE))
#define RIVER_PUZZLE_MAGBY (RIVER_PUZZLE_LINE(RIVER_PUZZLE_MAGMORTAR_LINE) | RIVER_PUZZLE_BABY_POKEMON)

#define RIVER_PUZZLE_CURSOR_TAG 0x679F
#define RIVER_PUZZLE_BOAT_TAG 0x67A0
#define RIVER_PUZZLE_POKEMON_TAG 0x67A1

extern map_footer_t map_footer_22_river_puzzle;

#define RIVER_PUZZLE_UI_NUM_TILES 64
#define RIVER_PUZZLE_TBOX_START_TILE (TBOX_CONTEXT_BORDER_NUM_TILES + TBOX_MESSAGE_NUM_TILES + RIVER_PUZZLE_UI_NUM_TILES)
#define RIVER_PUZZLE_TBOX_CNT 4
#define RIVER_PUZZLE_TBOX_TITLE 0
#define RIVER_PUZZLE_TBOX_CONTEXT 1
#define RIVER_PUZZLE_TBOX_MESSAGE 2
#define RIVER_PUZZLE_TBOX_LIST 3
tboxdata river_puzzle_tboxes[RIVER_PUZZLE_TBOX_CNT + 1];


#endif /* INCLUDE_C_RIVER_PUZZLE_H_ */
