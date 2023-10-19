/*
 * data.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_POKEPAD_POKEDEX_DATA_H_
#define INCLUDE_C_POKEPAD_POKEDEX_DATA_H_

#include "types.h"
#include "stdbool.h"
#include "pokepad/pokedex/count.h"
#include "pokemon/count.h"

	typedef struct {
        u8 category[12];
        u16 height;
        u16 weight;
        u8 *page0;
        u8 *page1;
        u16 unused;
        u16 poke_scale;
        u16 poke_displace;
        u16 trainer_scale;
        u16 trainer_displace;
        u16 unused_2;
    } pokedex_entry;

    typedef struct {
            u16 dex_id;
            u16 species;
            u8 seen : 1;
            u8 caught : 1;
	} pokedex_list_element;


    pokedex_entry *pokedex_get_data(u16 dex_id);


    extern const u16 pokedex_order[POKEMON_CNT];
    extern const pokedex_entry pokedex_entries[POKEDEX_CNT + 1];

#endif /* INCLUDE_C_POKEPAD_POKEDEX_DATA_H_ */
