/*
 * scanner.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_POKEPAD_POKEDEX_SCANNER_H_
#define INCLUDE_C_POKEPAD_POKEDEX_SCANNER_H_

	typedef struct {
        int num_entries_grass, num_entries_water, num_entries_other,
                num_entries_rod, num_entries_good_rod, num_entries_super_rod;
        u16 entries_grass[12][2];
        u16 entries_water[5][2];
        u16 entries_other[5][2];
        u16 entries_rod[2][2];
        u16 entries_good_rod[3][2];
        u16 entries_super_rod[5][2];
        u8 oams[13];
        u8 icon_pals[4];
        u8 fading_timer;
        u8 selected_area;
    } pokedex_scanner_state;

    /* ====================== Feature Scanner ================================*/
        /**
        * Transforms the wild_entry list into a pair of unique key, values with the
        * keys being the species and value the total probabilty for encounters.
        * @param wild_entries The wild_entry list to read from
        * @param dst Destination of the key, value list
        * @param capacity The number of elements in wild_entry list
        * @param pdf The associated pdf
        * @return The number of unique key, value pairs in dst
        */
        int _pokedex_feature_scanner_build_entries(wild_pokemon_entry *wild_entries,
               u16 dst[][2], int capacity, u8 pdf[]);

        /**
         * Uses bubble sort to sort the entries in descending order based on their values
         * @param entries A list of key, value pairs. O(n^2) does not matter since
         * n <= 12
         * @param size The size of the list
         */
        void _pokedex_feature_scanner_sort_entries(u16 entries[][2], int size);

        /**
         * Util function for _pokedex_feature_scanner_sort_entries. Swaps i and j.
         * @param entries The entry list.
         * @param i Index of first element to swap.
         * @param j Index of second element to swap
         */
        void _pokedex_feature_scanner_sort_entries_swap(u16 entries[][2], int i, int j);

        /**
         * Builds the wild pokemon entries for the current map.
         * @param state The scanner state where the entries will be stored
         * @return
         */
        int pokedex_feature_scanner_build_entries(pokedex_scanner_state *state);

        /**
         * Helper method to initialize the components of the scanner UI.
         * @param state
         */
        void _pokedex_callback_init_feature_scanner(pokedex_scanner_state *state);

        /**
         * Callback to initialize the pokedex scanner UI.
         */
        void pokedex_callback_init_feature_scanner();

        /**
         * Callback to handle the pokedex scanner UI.
         */
        void pokedex_callback_feature_scanner_idle();

        /**
         * Function that fades the "cursor" for the currently active area.
         * @param state
         */
        void pokedex_callback_feature_scanner_selection_fade(pokedex_scanner_state *state);

        /**
         * Clears the boxes and icons for the entry display and sets the callback
         * to pokedex_calllback_feature_scanner_load so in the next frame the
         * fitting entries are loaded.
         */
        void pokedex_callback_feature_scanner_clear();

        /**
         * Draws the texts and icons for the current entry set. Afterwards the
         * idle callback will be set.
         */
        void pokedex_callback_feature_scanner_load();

        /**
         * Returns to the pokedex main UI and frees all compontents allocated
         * by the scanner.
         */
        void pokedex_callback_feature_scanner_return();

#endif /* INCLUDE_C_POKEPAD_POKEDEX_SCANNER_H_ */
