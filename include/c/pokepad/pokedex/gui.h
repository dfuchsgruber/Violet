/*
 * gui.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_POKEPAD_POKEDEX_GUI_H_
#define INCLUDE_C_POKEPAD_POKEDEX_GUI_H_

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

u8 pokedex_fontcolmap[4];

// Main GUI

void pokedex_init_components();
void pokedex_callback_init();
void pokedex_init(bool from_outdoor);
void pokedex_show_components();
void pokedex_build_list();
void pokedex_quicksort_list(u8 comparator, int l, int r); //0 := nr, 1 := name, 2 := size, 3 := weight
int pokedex_quicksort_list_compare(u8 comparator, int a, int b);
void pokedex_quicksort_list_swap(int a, int b);
void pokedex_group_window_set();
void pokedex_callback_group_selection();
void pokedex_callback_return();
void pokedex_free_maps();
int pokedex_get_first_seen();
int pokedex_get_last_seen();
void pokedex_update_list();
void pokedex_callback_list();
void pokedex_callback_list_enter_mode(u8 mode);
bool pokedex_callback_list_mode_proceed();
void pokedex_sort_locate_cursor();
void pokedex_callback_sort();
void pokedex_big_callback_quicksort_parallel(u8 self);
void pokedex_quicksort_revert(int from, int to);
void pokedex_callback_init_entry();
void pokedex_entry_load_strings();
void pokedex_entry_load_pokepic();
void pokedex_entry_update();
void pokedex_callback_entry_idle();
void pokedex_callback_entry_back();

// Habitat GUI
void pokedex_init_habitat();
void pokedex_habitats_load_for_species(u16 *unpacked_map);
void pokedex_habitats_load_namespace();
void pokedex_habitats_update();
void pokedex_habitat_callback_idle();
void pokedex_habitat_big_callback_cursor_movement(u8 self);



#endif /* INCLUDE_C_POKEPAD_POKEDEX_GUI_H_ */
