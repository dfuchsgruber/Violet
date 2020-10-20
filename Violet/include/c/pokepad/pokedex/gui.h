/*
 * gui.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_POKEPAD_POKEDEX_GUI_H_
#define INCLUDE_C_POKEPAD_POKEDEX_GUI_H_

#include "text.h"

#define POKEDEX_TBOX_SEEN 0
#define POKEDEX_TBOX_CAUGHT 1
#define POKEDEX_TBOX_LIST_NAME 2
#define POKEDEX_TBOX_LIST_TYPES 3
#define POKEDEX_TBOX_LIST_CAPTURE 4
#define POKEDEX_TBOX_LIST_NR 5
#define POKEDEX_TBOX_FEATURE_0 6
#define POKEDEX_TBOX_FEATURE_1 7
#define POKEDEX_TBOX_FEATURE_2 8

#define POKEDEX_SCANNER_ICON_BASE_TAG 0xDDE0

tbox_font_colormap pokedex_fontcolmap;

// Main GUI
/**
 * Initializes the pokedex ui and state components
 */
void pokedex_init_components();

/**
 * Initializes the pokedex (callback)
 */
void pokedex_callback_init();

/**
 * Initializes the pokedex either from the pokepad or the LR overworld shortcut
 * @param from_outdoor if the pokedex is launched from the overworld
 */
void pokedex_init(bool from_outdoor);

/**
 * Shows the ui components of the pokedex
 */
void pokedex_show_components();

/**
 * Builds the list entries for the pokedex
 */
void pokedex_build_list();

/**
 * Sorts the list entries of the pokedex
 * @param comparator: 0 by number, 1 by name, 2 by size, 3 by weight
 * @param l the lower bound for quicksort
 * @param r the upper bound for quicksort
 */
void pokedex_quicksort_list(u8 comparator, int l, int r); //0 := nr, 1 := name, 2 := size, 3 := weight

/**
 * Compares two list entries by a comparator
 * @param comparator: 0 by number, 1 by name, 2 by size, 3 by weight
 * @param a first entry
 * @param b second entry
 * @return the difference a - b using the comparison method
 */
int pokedex_quicksort_list_compare(u8 comparator, int a, int b);

/**
 * Swaps two list entries
 * @param a the first entry
 * @param b the second entry
 */
void pokedex_quicksort_list_swap(int a, int b);

/**
 * Sets the group window currently active (by using the win feature)
 */
void pokedex_group_window_set();

/**
 * Callback during the selection of a group
 */
void pokedex_callback_group_selection();

/**
 * Returns from the pokedex to the previous state
 */
void pokedex_callback_return();

/**
 * Frees all pokedex components allocated on the heap
 */
void pokedex_free_maps();

/**
 * Gets the first pokedex entry number that was seen
 * @return the first entry number seen
 */
int pokedex_get_first_seen();

/**
 * Gets the last pokedex entry number that was seen
 * @return the last entry number seen
 */
int pokedex_get_last_seen();

/**
 * Updates the list entries of the pokedex
 */
void pokedex_update_list();

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
 * Loactes the cursor of the pokedex list after resorting
 */
void pokedex_sort_locate_cursor();

/**
 * Callback during the sort feature
 */
void pokedex_callback_sort();

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
 * Updates the entry of a pokemon according to the currently selected pokedex entry
 */
void pokedex_entry_update();

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
