/*
 * wild_pokemon.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_MAP_WILD_POKEMON_H_
#define INCLUDE_C_MAP_WILD_POKEMON_H_


typedef struct wild_pokemon_entry {
    u8 level_min;
    u8 level_max;
    u16 species;
} wild_pokemon_entry;

typedef struct wild_pokemon_habitat {
    u8 frequency;
    u8 field_1;
    u8 field_2;
    u8 field_3;
    wild_pokemon_entry *data;
} wild_pokemon_habitat;

typedef struct {
    u8 bank;
    u8 map;
    u8 field_2;
    u8 field_3;
    wild_pokemon_habitat *grass;
    wild_pokemon_habitat *water;
    wild_pokemon_habitat *other;
    wild_pokemon_habitat *rod;

} wild_pokemon_data;

extern wild_pokemon_data wild_pokemon[];

u16 map_wild_pokemon_get_current_table_id(); //returns 0xFFFF if none matches


#endif /* INCLUDE_C_MAP_WILD_POKEMON_H_ */
