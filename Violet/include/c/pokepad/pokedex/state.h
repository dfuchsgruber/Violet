/*
 * state.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_POKEPAD_POKEDEX_STATE_H_
#define INCLUDE_C_POKEPAD_POKEDEX_STATE_H_

#include "types.h"
#include "pokepad/pokedex/data.h"
#include "pokepad/pokedex/habitat.h"
#include "pokepad/pokedex/scanner.h"
#include "bg.h"

    enum {
        POKEDEX_SETUP_STATE_FREE_PREVIOUS_STATE = 0,
        POKEDEX_SETUP_STATE_DATA_SETUP,
        POKEDEX_SETUP_STATE_RESET,
        POKEDEX_SETUP_STATE_SETUP_BGS,
        POKEDEX_SETUP_STATE_SETUP_TBOXES,
        POKEDEX_SETUP_STATE_LOAD_GFX,
        POKEDEX_SETUP_STATE_SETUP_OAM,
        POKEDEX_SETUP_STATE_UPDATE_LIST,
        POKEDEX_SETUP_SHOW,
    };

    enum {
        POKEDEX_GROUP_LIST = 0,
        POKEDEX_GROUP_FEATURES,
        POKEDEX_GROUP_SORTING,
    };

   typedef struct {

        bg_tile (*bg_maps[4])[32];

        u8 from_outdoor : 1;
        u8 in_list : 1;
        u8 group_fading_mode : 1;
        u8 cursor_anchor : 1;
        u8 list_fast_mode : 1;
        u8 initialization_state;
        u8 current_group;
        u8 group_fading_index;
        u8 sorting;
        u16 current_species;
        u16 current_list_index;
        u8 current_comparator;
        //for list
        u8 list_mode; //0 = none, 1 = down, 2 = up, 3=right, 4=left
        
        u8 list_countdown;
        //for sortings
        u8 oam_sort_cursor;
        u8 sort_cursor_pos;
        u8 resorting : 1;
        u8 reverse_req : 1;
        pokedex_list_element *list;
        //for entry
        u16 tile_pokepic;
        u16 tile_form;
        u8 pal_pokepic;
        u8 pal_form;
        u8 oam_pokepic;
        u8 oam_form;
        u8 entry_fade : 1;
        u8 entry_skip_cry : 1;
        //for habitats
        pokedex_habitat_pair *habitats;
        int habitat_size;
        u8 oam_habitat_cursor;
        u8 oam_habitat_head;
        u8 habitat_cursor_x;
        u8 habitat_cursor_y;
        u8 habitat_oams_rarity[6][3]; // encounter_types x map_types
        u8 habitat_cursor_is_moving : 1;
        u8 habitat_found : 1;
        u8 from_battle : 1;
        u8 habitat_fading_mode;
        u8 habitat_fading_index;
        u8 habitat_fading_countdown;
        u8 current_worldmap;
        u8 current_feature;
        pokedex_scanner_state *scanner_state;
    } pokedex_state_t;

    extern EWRAM pokedex_state_t *pokedex_state;


#endif /* INCLUDE_C_POKEPAD_POKEDEX_STATE_H_ */
