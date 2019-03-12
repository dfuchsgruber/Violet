/*
 * incubator.h
 *
 *  Created on: Mar 6, 2019
 *      Author: dominik
 */

#ifndef INCLUDE_C_POKEPAD_INCUBATOR_H_
#define INCLUDE_C_POKEPAD_INCUBATOR_H_

#include "types.h"
#include "constants/species.h"
#include "pokemon/virtual.h"
#include "text.h"

typedef struct {
  u8 from_outdoor;
  u8 cursor_idx;
  u8 oam_egg_idx;
  u8 oam_egg_icons_idx[3];
  u8 oam_egg_progress_bars_idx[3][2]; // Two progress bars per egg
  u8 oam_selection[2];
  u8 context_menu_callback_idx;
  u8 imported_party_idx;
  u8 hide_current_egg_icon; // If set, the current egg icon is hidden
  void (*idle_callback)(); // The idle callback to set after showing components
} incubator_state_stru;

#define INCUBATOR_EGG_TAG POKEMON_EGG
#define INCUBATOR_SELECTION_TAG_LEFT 0x1496
#define INCUBATOR_SELECTION_TAG_RIGHT 0x1497
#define INCUBATOR_EGG_ICON_TAG 0x1498
#define INCUBATOR_EGG_PROGRESS_TAG 0x1499

/**
 * Returns the number of available slots for the incubator
 * @return the number of slots avaialable for the incubator
 */
int incubator_available_slots();

/**
 * Gets the egg progress of an egg.
 * @param egg the egg to get the progress of
 * @return the progress of the egg (value between 0 and 64, corresponding to 0% and 100%)
 */
int incubator_egg_get_progress(box_pokemon *egg);

/**
 * Removes an egg from the incubator.
 * @param slot the egg to remove
 * @param target an offset to place the pokemon at or null
 */
void incubator_remove_egg(int slot, box_pokemon *target);

/**
 * Callback function when an context menu item is printed. Does nothing.
 * @param tbox_idx the index of the textbox the context menu is in
 * @param idx the index of the item that is printed
 * @param y the tile position the text is printed to
 */
void incubator_context_menu_item_print_callback(u8 tbox_idx, int idx, u8 y);

/**
 * Big callback to handle the context menu of an egg.
 * @param self index of the callback itself
 */
void incubator_callback_context_menu_egg(u8 self);

/**
 * Big callback to simply countdown the shrinking of the egg icon to remove and then makes it
 * invisible.
 * @param self index of the callback itself
 */
void incubator_callback_wait_for_egg_icon_animation(u8 self);

/**
 * Idle callback for the incubator.
 */
void incubator_callback1_idle();

/**
 * Initializes ui components of the incubator.
 */
void incubator_initialize_ui();

/**
 * Continuation after one selected an egg to import into the incubator slot.
 */
void incubator_callback1_party_menu_continuation();

/**
 * Big callback to handle the context menu of an empty slot.
 * @param self index of the callback itself
 */
void incubator_callback_context_menu_empty(u8 self);

/**
 * Big callback to handle the text when a pokemon was imported from the party.
 * @param self index of the callback itself
 */
void incubator_callback_pokemon_imported(u8 self);

/**
 * Clears all slots in the incubator.
 */
void incubator_clear();

#define INCUBATOR_TBOX_CNT 6
#define INCUBATOR_TBOX_TITLE 0
#define INCUBATOR_TBOX_EGG 1
#define INCUBATOR_TBOX_TYPES 2
#define INCUBATOR_TBOX_CONTEXT_MENU_EGG 3
#define INCUBATOR_TBOX_CONTEXT_MENU_EMPTY 4
#define INCUBATOR_TBOX_MESSAGE 5
#define INCUBATOR_TBOX_START_TILE (1 + TBOX_CONTEXT_BORDER_NUM_TILES + TBOX_MESSAGE_NUM_TILES)

// How many pixels the temperature can span maximally
#define INCUBATOR_TEMPERATURE_PIXELS 98

tboxdata incubator_tboxes[INCUBATOR_TBOX_CNT + 1];

extern u16 gfx_incubator_ui_0Tiles[];
extern u16 gfx_incubator_ui_0Map[];
extern u16 gfx_incubator_ui_0Pal[];
extern u16 gfx_incubator_ui_boxTiles[];
extern u16 gfx_incubator_ui_boxMap[];
extern u16 gfx_incubator_ui_boxPal[];
extern u16 gfx_incubator_ui_box_greyPal[];
extern u16 gfx_incubator_ui_1Tiles[];
extern u16 gfx_incubator_ui_1Map[];
extern u16 gfx_incubator_ui_1Pal[];
extern u16 gfx_incubator_progress_barTiles[];
extern u16 gfx_incubator_progress_barPal[];
extern u16 gfx_incubator_ui_glassTiles[];
extern u16 gfx_incubator_ui_glassPal[];
extern u16 gfx_incubator_ui_glassMap[];
extern u16 gfx_incubator_selectionTiles[];
extern u16 gfx_incubator_selectionPal[];

#endif /* INCLUDE_C_POKEPAD_INCUBATOR_H_ */
