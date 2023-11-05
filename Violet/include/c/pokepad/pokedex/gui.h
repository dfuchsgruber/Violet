/*
 * gui.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_POKEPAD_POKEDEX_GUI_H_
#define INCLUDE_C_POKEPAD_POKEDEX_GUI_H_

#include "text.h"

#define POKEDEX_LIST_WIDTH_NUMBER 4
#define POKEDEX_LIST_WIDTH_CAUGHT_ICON 3
#define POKEDEX_LIST_WIDTH_NAME 9
#define POKEDEX_LIST_WIDTH_TYPE 10

#define POKEDEX_LIST_MAX_NUM_VISIBLE 10

// Bounds of the list window
#define POKEDEX_LIST_X0 68
#define POKEDEX_LIST_Y0 18
#define POKEDEX_LIST_X1 240
#define POKEDEX_LIST_Y1 160
#define POKEDEX_LIST_DELTA_Y 8

enum {
    POKEDEX_TBOX_STATS = 0,
    POKEDEX_TBOX_TITLE,
    POKEDEX_TBOX_LIST_NUMBER,
    POKEDEX_TBOX_LIST_CAUGHT_ICON,
    POKEDEX_TBOX_LIST_NAME,
    POKEDEX_TBOX_LIST_TYPE,
    POKEDEX_TBOX_HEADER,
    POKEDEX_TBOX_CONTEXT_MENU_SORT,
    NUM_POKEDEX_TBOXES,
};

enum {
    POKEDEX_SORTING_STATE_CLOSING,
    POKEDEX_SORTING_STATE_SORTING,
    POKEDEX_SORTING_STATE_OPENING,
};

typedef struct {
    u8 state;
    u8 y0, y1;
    void (*continuation)(u8) __attribute__ ((aligned (4)));
} pokedex_sorting_state_t;


enum {
    POKEDEX_CURSOR_GFX_TAG = 0xA013,
    POKEDEX_UI_POKEMON_TAG,
};

extern const tbox_font_colormap pokedex_fontcolmap;

// Main GUI
/**
 * Initializes the pokedex ui and state components
 */
void pokedex_init_components();

/**
 * Callback to trigger the resort animation of the pokedex
 * @param self the callback to overwrite
 * @param continuation which callback to continue with after resorting
*/
void pokedex_resort_list(u8 self, void (*continuation)(u8));

/**
 * Callback1 that initializes the pokedex gui. `pokedex_state` should already be allocated at this point.
 * Also, the screen is expected to be already faded to (or currently fading) black.
 */
void pokedex_callback_initialize();

/**
 * Initializes the pokedex either from the pokepad or the LR overworld shortcut
 * @param from_outdoor if the pokedex is launched from the overworld
 */
void pokedex_initialize(bool from_outdoor);

/**
 * Shows the ui components of the pokedex
 */
void pokedex_show_components();

/**
 * Builds the list entries for the pokedex
 */
void pokedex_build_list();

/**
 * Sorts the entries of the pokedex state's list.
 * @param comparator according to which comparator
 * @param l from which left index
 * @param r to which right index
*/
void pokedex_quicksort_list(u8 comparator, int l, int r);

/**
 * Callback during the selection of a group
 */
void pokedex_callback_group_selection();

/**
 * Updates the `first_idx` and `last_idx` fields of the `pokedex_state`.
*/
void pokedex_list_update_bounds();

/**
 * Creates a new scroll indicator pair for the list
*/
void pokedex_list_scroll_indicators_new();

/**
 * Updates the list entries of the pokedex
 */
void pokedex_update_list(bool scrolling_down);

/**
 * Callback during the list feature of the pokedex
 */
void pokedex_callback_list();

/**
 * Enter a list mode of the pokedex callback (normal or fast scrolling)
 */
void pokedex_callback_list_enter_mode(u8 mode);

/**
 * Callback to proceed a list mode of the pokedex
 */
bool pokedex_callback_list_mode_proceed();

/**
 * Handles inputs for the pokedex gui.
 * @param self self-reference
*/
void pokedex_context_menu_sort_handle_inputs(u8 self);

/**
 * Unused: Parallel quicksort (using callbacks): Brings no improvement however
 * @param self the own callback id
 */
void pokedex_big_callback_quicksort_parallel(u8 self);

/**
 * Reverses the order of list entries
 * @param from the first entry
 * @param the last entry
 */
void pokedex_quicksort_revert(int from, int to);

/**
 * Initializes the entry of a pokemon
 */
void pokedex_callback_init_entry();

/**
 * Loads all strings for a pokedex entry
 */
void pokedex_entry_load_strings();

/**
 * Loads the pokemon picture for an entry
 */
void pokedex_entry_load_pokepic();

/**
 * Idle callback1 for the pokedex entry
 */
void pokedex_callback_entry_idle();

/**
 * Returns from the entry to the main gui of the pokedex
 */
void pokedex_callback_entry_back();

// Habitat GUI
/**
 * Initializes the habitat gui of the pokedex
 */
void pokedex_init_habitat();

/**
 * Loads the habitats for a species by changing palettes of the tilemap
 * @param unpacked_map the decompressed tilemap to adjust
 */
void pokedex_habitats_load_for_species(u16 *unpacked_map);

/**
 * Loads the currently selected namespace
 */
void pokedex_habitats_load_namespace();

/**
 * Updates the habitats for a pokemon based on the currently selected pokemon
 */
void pokedex_habitats_update();

/**
 * Idle callback for the pokemon habitat feature
 */
void pokedex_habitat_callback_idle();

/**
 * Callback to move the cursor (which is only moving aligned to 8 pixels)
 * @param self the own callback id
 */
void pokedex_habitat_big_callback_cursor_movement(u8 self);

/**
 * Draws a number on a textbox
 * @param box_id the box id
 * @param n the number to draw
 * @param species the species
 * @param n2 ???
 * @param y_pixel the y displacement
 */
bool pokedex_tbox_draw_num(u8 box_id, u8 n, u16 species, u8 n2, u16 y_pixel);

#endif /* INCLUDE_C_POKEPAD_POKEDEX_GUI_H_ */
