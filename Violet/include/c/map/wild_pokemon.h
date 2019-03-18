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
 * @param icognito_letter the icognito letter to spawn (probably tho)
 * @return whether the initialization, i.e. the generation of a pokemon was successful
 */
bool wildbattle_initialize_by_habitat(wild_pokemon_habitat *habitat, int type,
		int icognoito_letter);

/**
 * Initializes the opponent's party with a wild pokemon
 * @param species the species to spawn
 * @param level level of the wild pokemon
 * @param icognito_letter the icognito letter to spawn (probably tho)
 */
void wildbattle_initialize_pokemon(u16 species, u8 level, int icognoito_letter);
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

/**
 * Samples an index from a pdf for wild pokemon data
 * @param pdf array of probabilities of an index to occur (have to sum up to 100)
 * @paran size total size of the pdf
 * @return random index according to pdf
 */
int wildbattle_sample_from_pdf(u8 *pdf, int size);

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
u8 wildbattle_sample_level(wild_pokemon_entry *entry);

/**
 * Initializes the wild battle encounter with the secondary starter (used for the trainer school)
 * @return if the pokemon will be encountered
 */
bool trainerschool_wildbattle_initialize_secondary_starter();

/*
 * Probability density functions for each type of encounter
 * in percent. (Encounters are actually hardwired with these values)
 */

u8 wild_pokemon_grass_pdf[12];

u8 wild_pokemon_water_pdf[5];

u8 wild_pokemon_rod_pdf[2];

u8 wild_pokemon_good_rod_pdf[3];

u8 wild_pokemon_super_rod_pdf[5];

u8 wild_pokemon_other_pdf[5];

wild_pokemon_habitat wild_pokemon_3_0_water;
wild_pokemon_habitat wild_pokemon_3_0_rod;
wild_pokemon_habitat wild_pokemon_3_1_water;
wild_pokemon_habitat wild_pokemon_3_1_rod;
wild_pokemon_habitat wild_pokemon_3_2_water;
wild_pokemon_habitat wild_pokemon_3_2_rod;
wild_pokemon_habitat wild_pokemon_3_19_grass;
wild_pokemon_habitat wild_pokemon_3_19_other;
wild_pokemon_habitat wild_pokemon_3_76_grass;
wild_pokemon_habitat wild_pokemon_3_57_grass;
wild_pokemon_habitat wild_pokemon_3_57_water;
wild_pokemon_habitat wild_pokemon_3_57_other;
wild_pokemon_habitat wild_pokemon_3_57_rod;
wild_pokemon_habitat wild_pokemon_3_41_grass;
wild_pokemon_habitat wild_pokemon_3_41_water;
wild_pokemon_habitat wild_pokemon_3_41_other;
wild_pokemon_habitat wild_pokemon_3_41_rod;
wild_pokemon_habitat wild_pokemon_3_70_grass;
wild_pokemon_habitat wild_pokemon_15_0_grass;
wild_pokemon_habitat wild_pokemon_15_0_water;
wild_pokemon_habitat wild_pokemon_15_0_other;
wild_pokemon_habitat wild_pokemon_15_0_rod;
wild_pokemon_habitat wild_pokemon_15_4_grass;
wild_pokemon_habitat wild_pokemon_3_3_water;
wild_pokemon_habitat wild_pokemon_3_3_rod;
wild_pokemon_habitat wild_pokemon_1_0_grass;
wild_pokemon_habitat wild_pokemon_1_0_water;
wild_pokemon_habitat wild_pokemon_1_0_other;
wild_pokemon_habitat wild_pokemon_1_0_rod;
wild_pokemon_habitat wild_pokemon_0_5_grass;
wild_pokemon_habitat wild_pokemon_0_6_grass;
wild_pokemon_habitat wild_pokemon_0_7_grass;
wild_pokemon_habitat wild_pokemon_0_7_water;
wild_pokemon_habitat wild_pokemon_0_7_rod;
wild_pokemon_habitat wild_pokemon_3_21_grass;
wild_pokemon_habitat wild_pokemon_3_21_other;
wild_pokemon_habitat wild_pokemon_3_67_grass;
wild_pokemon_habitat wild_pokemon_3_67_water;
wild_pokemon_habitat wild_pokemon_3_67_rod;
wild_pokemon_habitat wild_pokemon_3_74_grass;
wild_pokemon_habitat wild_pokemon_3_74_other;
wild_pokemon_habitat wild_pokemon_3_4_water;
wild_pokemon_habitat wild_pokemon_8_11_water;
wild_pokemon_habitat wild_pokemon_8_11_rod;
wild_pokemon_habitat wild_pokemon_1_59_grass;
wild_pokemon_habitat wild_pokemon_1_59_water;
wild_pokemon_habitat wild_pokemon_1_59_rod;
wild_pokemon_habitat wild_pokemon_3_22_grass;
wild_pokemon_habitat wild_pokemon_3_22_water;
wild_pokemon_habitat wild_pokemon_3_22_other;
wild_pokemon_habitat wild_pokemon_3_22_rod;
wild_pokemon_habitat wild_pokemon_16_3_grass;
wild_pokemon_habitat wild_pokemon_16_3_rod;
wild_pokemon_habitat wild_pokemon_3_23_grass;
wild_pokemon_habitat wild_pokemon_3_23_other;
wild_pokemon_habitat wild_pokemon_17_2_grass;
wild_pokemon_habitat wild_pokemon_3_5_water;
wild_pokemon_habitat wild_pokemon_3_5_rod;
wild_pokemon_habitat wild_pokemon_3_24_water;
wild_pokemon_habitat wild_pokemon_3_24_rod;
wild_pokemon_habitat wild_pokemon_18_2_grass;
wild_pokemon_habitat wild_pokemon_18_3_grass;
wild_pokemon_habitat wild_pokemon_18_3_other;
wild_pokemon_habitat wild_pokemon_1_30_grass;
wild_pokemon_habitat wild_pokemon_1_30_other;
wild_pokemon_habitat wild_pokemon_3_6_water;
wild_pokemon_habitat wild_pokemon_3_6_rod;
wild_pokemon_habitat wild_pokemon_0_12_grass;
wild_pokemon_habitat wild_pokemon_1_81_grass;
wild_pokemon_habitat wild_pokemon_1_82_grass;
wild_pokemon_habitat wild_pokemon_1_82_other;
wild_pokemon_habitat wild_pokemon_1_126_grass;
wild_pokemon_habitat wild_pokemon_3_7_grass;
wild_pokemon_habitat wild_pokemon_3_7_other;
wild_pokemon_habitat wild_pokemon_11_2_route_2_east_clouds_grass;
wild_pokemon_habitat wild_pokemon_3_8_grass;
wild_pokemon_habitat wild_pokemon_3_8_water;
wild_pokemon_habitat wild_pokemon_3_8_rod;
wild_pokemon_habitat wild_pokemon_3_8_other;


#endif /* INCLUDE_C_MAP_WILD_POKEMON_H_ */
