/*
 * wild_pokemon.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_MAP_WILD_POKEMON_H_
#define INCLUDE_C_MAP_WILD_POKEMON_H_

#include "constants/wild_pokemon_densities.h"

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
    const wild_pokemon_entry *data;
} wild_pokemon_habitat;

typedef struct {
    u8 bank;
    u8 map;
    u8 field_2;
    u8 field_3;
    const wild_pokemon_habitat *grass;
    const wild_pokemon_habitat *water;
    const wild_pokemon_habitat *other;
    const wild_pokemon_habitat *rod;

} wild_pokemon_data;

#define NUM_UNOWN_LETTERS_PER_MAP 4

typedef struct {
    u8 bank;
    u8 map_idx;
    u8 letters[NUM_UNOWN_LETTERS_PER_MAP + 1];
} wild_pokemon_unown_t;

extern EWRAM wild_pokemon_data dynamic_wild_pokemon;
extern EWRAM wild_pokemon_habitat dynamic_wild_pokemon_habitat_grass;
extern EWRAM wild_pokemon_habitat dynamic_wild_pokemon_habitat_water;
extern EWRAM wild_pokemon_habitat dynamic_wild_pokemon_habitat_radar;
extern EWRAM wild_pokemon_habitat dynamic_wild_pokemon_habitat_rod;
extern EWRAM wild_pokemon_entry dynamic_wild_pokemon_entries_grass[WILD_POKEMON_NUM_ENTRIES_GRASS];
extern EWRAM wild_pokemon_entry dynamic_wild_pokemon_entries_water[WILD_POKEMON_NUM_ENTRIES_WATER];
extern EWRAM wild_pokemon_entry dynamic_wild_pokemon_entries_rod[WILD_POKEMON_NUM_ENTRIES_ROD + WILD_POKEMON_NUM_ENTRIES_GOOD_ROD + WILD_POKEMON_NUM_ENTRIES_SUPER_ROD];
extern EWRAM wild_pokemon_entry dynamic_wild_pokemon_entries_radar[WILD_POKEMON_NUM_ENTRIES_OTHER];

/**
 * Returns a pointer to the NUM_UNOWN_LETTERS_PER_MAP letters that currently can appear on the current map.
 * @return pointer to NUM_UNOWN_LETTERS_PER_MAP chars representing the letters or NULL
 **/
const u8 *wild_pokemon_get_current_unown_letters();

/**
 * Returns a pointer to the NUM_UNOWN_LETTERS_PER_MAP letters that currently can appear on the map specified by
 * a bank in variable 0x8005 and a map_idx in variable 0x8006.
 * @return pointer to NUM_UNOWN_LETTERS_PER_MAP chars representing the letters or NULL
 **/
const u8 *wild_pokemon_get_unown_letters_of_header(u8 bank, u8 map_idx);

#define UNOWN_LETTER(char) (char - 'A')
#define UNOWN_LETTER_EXCLAMATION_MARK 26
#define UNOWN_LETTER_QUESTION_MARK 27

extern u8 wild_pokemon_disabled;

extern const wild_pokemon_data wild_pokemon[];

/**
 * Starts an already initialized wildbattle
 */
void wildbattle_start();

/**
 * Tries to initialize a wildbattle by a habitat
 * @param habitat the habitat
 * @param type 0 for grass-like habitats, 1 for water-like habitats
 * @param consider_repel if repel should be considered when generating a battle
 * @return whether the initialization, i.e. the generation of a pokemon was successful
 */
bool wildbattle_initialize_by_habitat(const wild_pokemon_habitat *habitat, int type,
		bool consider_repel);

/**
 * Initializes the opponent's party with a wild pokemon
 * @param species the species to spawn
 * @param level level of the wild pokemon
 * @param icognito_letter the icognito letter to spawn (probably tho)
 */
void wild_pokemon_new(u16 species, u8 level, int icognoito_letter);
/**
 * Gets the current wild_pokemon_data header or NULL if no data is availible
 */
const wild_pokemon_data *map_wildbattle_get_header();

u16 map_wild_pokemon_get_current_table_id(); //returns 0xFFFF if none matches

/**
 * Returns the wild pokemon data of the current map
 * @return pointer to the wild pokemon data
 */
const wild_pokemon_data *map_wild_pokemon_get_current();

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

/**
 * Samples an index from a pdf for wild pokemon data
 * @param pdf array of probabilities of an index to occur (have to sum up to 100)
 * @paran size total size of the pdf
 * @return random index according to pdf
 */
int wildbattle_sample_from_pdf(const u8 *pdf, int size);

/**
 * Checks if the wild pokemon is prevented by repel
 * @param level the level of the wild pokemon to generate
 * @return if the battle is allowed by repel
 */
bool wildbattle_is_allowed_by_repel(u8 level);

/**
 * Samples the level of a wild pokemon
 * @param entry the pokemon to sample
 * @return the level
 */
u8 wildbattle_sample_level(const wild_pokemon_entry *entry);

/**
 * Samples an index in the rod table to be encountered.
 * @param rod_type which rod is used (0 := rod, 1 := good rod, 2 := super rod)
 * @return the index in the table
 **/
int wildbattle_sample_from_rod_pdf (u8 rod_type);

/**
 * Initializes the wild battle encounter with the secondary starter (used for the trainer school)
 * @return if the pokemon will be encountered
 */
bool trainerschool_wildbattle_initialize_secondary_starter();

/*
 * Probability density functions for each type of encounter
 * in percent. (Encounters are actually hardwired with these values)
 */

extern const u8 wild_pokemon_grass_pdf[WILD_POKEMON_NUM_ENTRIES_GRASS];

extern const u8 wild_pokemon_water_pdf[WILD_POKEMON_NUM_ENTRIES_WATER];

extern const u8 wild_pokemon_rod_pdf[WILD_POKEMON_NUM_ENTRIES_ROD];

extern const u8 wild_pokemon_good_rod_pdf[WILD_POKEMON_NUM_ENTRIES_GOOD_ROD];

extern const u8 wild_pokemon_super_rod_pdf[WILD_POKEMON_NUM_ENTRIES_SUPER_ROD];

extern const u8 wild_pokemon_other_pdf[WILD_POKEMON_NUM_ENTRIES_OTHER];

#endif /* INCLUDE_C_MAP_WILD_POKEMON_H_ */
