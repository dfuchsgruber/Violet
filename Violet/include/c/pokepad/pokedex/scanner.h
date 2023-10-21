/*
 * scanner.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_POKEPAD_POKEDEX_SCANNER_H_
#define INCLUDE_C_POKEPAD_POKEDEX_SCANNER_H_

#include "map/wild_pokemon.h"

	typedef struct {
        int num_entries_grass, num_entries_water, num_entries_other,
                num_entries_rod, num_entries_good_rod, num_entries_super_rod;
        u16 entries_grass[13][2]; // Potenial 13st slot for a roamer
        u16 entries_water[5][2];
        u16 entries_other[5][2];
        u16 entries_rod[2][2];
        u16 entries_good_rod[3][2];
        u16 entries_super_rod[5][2];
        u8 oams[13];
        u8 icon_pals[4];
        u8 fading_timer;
        u8 selected_area;
    } pokedex_scanner_state_t;

        extern EWRAM pokedex_scanner_state_t *pokedex_scanner_state;

        /**
         * Callback to initialize the pokedex scanner UI.
         */
        void pokedex_callback_init_feature_scanner();


#endif /* INCLUDE_C_POKEPAD_POKEDEX_SCANNER_H_ */
