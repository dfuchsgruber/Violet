/*
 * state.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_POKEPAD_POKEDEX_STATE_H_
#define INCLUDE_C_POKEPAD_POKEDEX_STATE_H_

#include "pokepad/pokedex/data.h"
#include "pokepad/pokedex/habitat.h"
#include "pokepad/pokedex/scanner.h"

   typedef struct {
        bool from_outdoor;
        bool in_list;
        u8 current_group;
        u8 group_fading_index;
        bool group_fading_mode;
        u8 sorting;
        u16 current_species;
        u16 current_list_index;
        u8 current_comparator;
        bool cursor_anchor;
        //for list
        u8 list_mode; //0 = none, 1 = down, 2 = up, 3=right, 4=left
        bool list_fast_mode;
        u8 list_countdown;
        //for sortings
        u8 oam_sort_cursor;
        u8 sort_cursor_pos;
        bool resorting;
        bool reverse_req;
        pokedex_list_element *list;
        //for entry
        u16 tile_pokepic;
        u16 tile_form;
        u8 pal_pokepic;
        u8 pal_form;
        u8 oam_pokepic;
        u8 oam_form;
        bool entry_fade;
        bool entry_skip_cry;
        //for habitats
        pokedex_habitat_pair *habitats;
        int habitat_size;
        u8 oam_habitat_cursor;
        u8 oam_habitat_head;
        u8 habitat_cursor_x;
        u8 habitat_cursor_y;
        u8 habitat_oams_rarity[4]; // 3 for rod is not used
        bool habitat_cursor_is_moving;
        u8 habitat_fading_mode;
        u8 habitat_fading_index;
        u8 habitat_fading_countdown;
        u8 habitat_oams_rod[3];
        u8 current_worldmap;
        u8 current_feature;
        bool habitat_found;
        bool from_battle;
        pokedex_scanner_state *scanner_state;
    } pokedex_memory;


#endif /* INCLUDE_C_POKEPAD_POKEDEX_STATE_H_ */
