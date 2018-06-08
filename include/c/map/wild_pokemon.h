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

/**
 * Starts an already initialized wildbattle
 */
void wildbattle_start();

/**
 * Tries to initialize a wildbattle by a habitat
 * @param habitat the habitat
 * @param type 0 for grass-like habitats, 1 for water-like habitats
 * @param p2 TODO
 * @return whether the initialization, i.e. the generation of a pokemon was successful
 */
int wildbattle_initialize_by_habitat(wild_pokemon_habitat *habitat, int type, int p2);

/**
 * Gets the current wild_pokemon_data header or NULL if no data is availible
 */
wild_pokemon_data *map_wildbattle_get_header();

u16 map_wild_pokemon_get_current_table_id(); //returns 0xFFFF if none matches

/**
 * Returns the wild pokemon data of the current map
 * @return pointer to the wild pokemon data
 */
wild_pokemon_data *map_wild_pokemon_get_current();

/**
 * Checks if a wild pokemon appears by a frequency between [0;255]
 * @param frequency the frequency for pokemon to appear in [0;255]
 * @param type the type of check (0 seems to be the regular value)
 * @return whether a pokemon would appear
 */
int wildbattle_does_pokemon_appear_by_frequency(u8 frequency, u8 type);

/**
 * Increases the chance for a wildbattle after a potential tile did not trigger a wildbattle
 * @param frequency the base frequency for a wildbattle
 */
void wildbattle_increase_chance(u8 frequency);


#endif /* INCLUDE_C_MAP_WILD_POKEMON_H_ */
