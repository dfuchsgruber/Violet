/*
 * scanner.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_POKEPAD_POKEDEX_SCANNER_H_
#define INCLUDE_C_POKEPAD_POKEDEX_SCANNER_H_

#include "types.h"
#include "map/wild_pokemon.h"
#include "constants/wild_pokemon_densities.h"
#include "pokemon/roamer.h"
#include "pokemon/sprites.h"
#include "bg.h"
#include "map/wild_pokemon.h"

        #define POKEDEX_SCANNER_MAX_NUM_DISPLAYED 7
        // x, y are relative to the list tbox
        #define POKEDEX_SCANNER_LIST_X 2
        #define POKEDEX_SCANNER_LIST_Y 8
        #define POKEDEX_SCANNER_LIST_LINE_WIDTH 18

        enum {
                POKEDEX_SCANNER_HABITAT_GRASS = 0,
                POKEDEX_SCANNER_HABITAT_WATER,
                POKEDEX_SCANNER_HABITAT_OTHER,
                POKEDEX_SCANNER_HABITAT_ROD,
                POKEDEX_SCANNER_NUM_HABITATS,
        };

        enum {
                POKEDEX_SCANNER_GFX_TAG_ICON_GRASS = 0xE310,
                POKEDEX_SCANNER_GFX_TAG_ICON_WATER,
                POKEDEX_SCANNER_GFX_TAG_ICON_OTHER,
                POKEDEX_SCANNER_GFX_TAG_ICON_ROD,
                POKEDEX_SCANNER_GFX_TAG_ICON_POKEMON,
                POKEDEX_SCANNER_GFX_TAG_CURSOR,
                POKEDEX_SCANNER_GFX_TAG_ICON_CAUGHT,
                POKEDEX_SCANNER_GFX_TAG_ICONS_BASE,
        };

        enum {
                POKEDEX_SCANNER_SETUP_STATE_DATA_SETUP = 0,
                POKEDEX_SCANNER_SETUP_STATE_RESET,
                POKEDEX_SCANNER_SETUP_STATE_SETUP_BGS,
                POKEDEX_SCANNER_SETUP_STATE_SETUP_TBOXES,
                POKEDEX_SCANNER_SETUP_STATE_LOAD_GFX,
                POKEDEX_SCANNER_SETUP_STATE_SETUP_OAM,
                POKEDEX_SCANNER_SETUP_STATE_SETUP_ICON_OAM,
                POKEDEX_SCANNER_SETUP_STATE_UPDATE_LIST,
                POKEDEX_SCANNER_SETUP_SCROLL_INDICATORS,
                POKEDEX_SCANNER_SETUP_SHOW,
        };

        enum {
                POKEDEX_SCANNER_TBOX_TITLE = 0,
                POKEDEX_SCANNER_TBOX_LIST,
                POKEDEX_SCANNER_TBOX_STATS,
                POKEDEX_SCANNER_TBOX_NUM_TBOXES
        };

        enum {
                POKEDEX_SCANNER_DELIMITER_ROD = 0,
                POKEDEX_SCANNER_DELIMITER_GOOD_ROD,
                POKEDEX_SCANNER_DELIMITER_SUPER_ROD,
                POKEDEX_SCANNER_NUM_DELIMITERS,
        };

        #define POKEDEX_SCANNER_MAX_NUM_ENTIRES_ROD (WILD_POKEMON_NUM_ENTRIES_ROD + WILD_POKEMON_NUM_ENTRIES_GOOD_ROD + \
                        WILD_POKEMON_NUM_ENTRIES_SUPER_ROD + POKEDEX_SCANNER_NUM_DELIMITERS)

        typedef struct {
                u16 species;
                u8 percentage;
                u8 is_delimiter : 1;
        } pokedex_scanner_entry_t;

        #define POKEDEX_SCANNER_NUM_BGS 2

        typedef struct {
                size_t num_entries[POKEDEX_SCANNER_NUM_HABITATS];
                pokedex_scanner_entry_t entries_grass[WILD_POKEMON_NUM_ENTRIES_GRASS + NUM_ROAMERS];
                pokedex_scanner_entry_t entries_water[WILD_POKEMON_NUM_ENTRIES_WATER + NUM_ROAMERS];
                pokedex_scanner_entry_t entries_other[WILD_POKEMON_NUM_ENTRIES_OTHER];
                pokedex_scanner_entry_t entries_rods[POKEDEX_SCANNER_MAX_NUM_ENTIRES_ROD];
        } pokedex_scanner_data_t;

        typedef struct {
                u16 list[WILD_POKEMON_NUM_ENTRIES_GRASS + WILD_POKEMON_NUM_ENTRIES_WATER + WILD_POKEMON_NUM_ENTRIES_OTHER + WILD_POKEMON_NUM_ENTRIES_ROD + WILD_POKEMON_NUM_ENTRIES_GOOD_ROD + \
                        WILD_POKEMON_NUM_ENTRIES_SUPER_ROD + NUM_ROAMERS];
                size_t size;
        } pokedex_scanner_unique_species_list_t;

	typedef struct {
                u8 initialization_state;
                pokedex_scanner_data_t data;
                bg_tile (*bg_maps[2])[32];
                u8 oams[POKEDEX_SCANNER_MAX_NUM_DISPLAYED];
                u8 oams_icons_caught[POKEDEX_SCANNER_MAX_NUM_DISPLAYED];
                u8 oam_idxs_icon[POKEDEX_SCANNER_NUM_HABITATS];
                u8 oam_idx_icon_pokemon;
                u8 pal_idx_icon_pokemon;
                u16 base_tile_pokemon;
                u8 icon_pals[POKEMON_NUM_ICON_PALS + 1];
                u16 cursor_positions[POKEDEX_SCANNER_NUM_HABITATS];
                u8 first_idx_displayed, last_idx_displayed;
                u8 scroll_indicator_cb_idx;
                u8 fading_timer;
                u8 habitat;
                u8 oam_idx_habitat_cursor;
        } pokedex_scanner_state_t;
        
        /**
         * Builds a list of unique species from the given data.
         * @param dst The destination list.
         * @param state The data to build the list from.
        */
        void pokedex_scanner_build_unique_species(pokedex_scanner_unique_species_list_t *dst, 
                pokedex_scanner_data_t *state);

        /**
         * Builds the scanner data from the given wild pokemon data.
         * @param dst The destination data.
         * @param wild_pokemon The wild pokemon data to build the scanner data from.
        */
        void pokedex_feature_scanner_build_all_entries(pokedex_scanner_data_t *dst, 
                const wild_pokemon_data *wild_pokemon);

        /**
         * Prints icons of the available pokemon on opening the START menu
         **/
        void start_menu_print_scanner();

        extern EWRAM pokedex_scanner_state_t *pokedex_scanner_state;

        /**
         * Callback to initialize the pokedex scanner UI.
         */
        void pokedex_callback_initialize_feature_scanner();


#endif /* INCLUDE_C_POKEPAD_POKEDEX_SCANNER_H_ */
