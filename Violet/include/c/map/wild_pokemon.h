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

#define NUM_UNOWN_LETTERS_PER_MAP 4

typedef struct {
    u8 bank;
    u8 map_idx;
    u8 letters[NUM_UNOWN_LETTERS_PER_MAP + 1];
} wild_pokemon_unown_t;

/**
 * Returns a pointer to the NUM_UNOWN_LETTERS_PER_MAP letters that currently can appear on the current map.
 * @return pointer to NUM_UNOWN_LETTERS_PER_MAP chars representing the letters or NULL
 **/
u8 *wild_pokemon_get_current_unown_letters();

/**
 * Returns a pointer to the NUM_UNOWN_LETTERS_PER_MAP letters that currently can appear on the map specified by
 * a bank in variable 0x8005 and a map_idx in variable 0x8006.
 * @return pointer to NUM_UNOWN_LETTERS_PER_MAP chars representing the letters or NULL
 **/
u8 *wild_pokemon_get_unown_letters_of_header(u8 bank, u8 map_idx);

#define UNOWN_LETTER(char) (char - 'A')

u8 wild_pokemon_disabled;

extern wild_pokemon_data wild_pokemon[];

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
bool wildbattle_initialize_by_habitat(wild_pokemon_habitat *habitat, int type,
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


#define WILD_POKEMON_NUM_ENTRIES_GRASS 12
#define WILD_POKEMON_NUM_ENTRIES_WATER 5
#define WILD_POKEMON_NUM_ENTRIES_ROD 2
#define WILD_POKEMON_NUM_ENTRIES_GOOD_ROD 3
#define WILD_POKEMON_NUM_ENTRIES_SUPER_ROD 5
#define WILD_POKEMON_NUM_ENTRIES_OTHER 5

/*
 * Probability density functions for each type of encounter
 * in percent. (Encounters are actually hardwired with these values)
 */

u8 wild_pokemon_grass_pdf[WILD_POKEMON_NUM_ENTRIES_GRASS];

u8 wild_pokemon_water_pdf[WILD_POKEMON_NUM_ENTRIES_WATER];

u8 wild_pokemon_rod_pdf[WILD_POKEMON_NUM_ENTRIES_ROD];

u8 wild_pokemon_good_rod_pdf[WILD_POKEMON_NUM_ENTRIES_GOOD_ROD];

u8 wild_pokemon_super_rod_pdf[WILD_POKEMON_NUM_ENTRIES_SUPER_ROD];

u8 wild_pokemon_other_pdf[WILD_POKEMON_NUM_ENTRIES_OTHER];

wild_pokemon_habitat wild_pokemon_unown_ruins_grass;
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
wild_pokemon_habitat wild_pokemon_tafelberg_grass;
wild_pokemon_habitat wild_pokemon_tafelberg_water;
wild_pokemon_habitat wild_pokemon_tafelberg_rod;
wild_pokemon_habitat wild_pokemon_tafelberg_other;
wild_pokemon_habitat wild_pokemon_3_22_grass;
wild_pokemon_habitat wild_pokemon_3_22_water;
wild_pokemon_habitat wild_pokemon_3_22_other;
wild_pokemon_habitat wild_pokemon_3_22_rod;
wild_pokemon_habitat wild_pokemon_16_3_grass;
wild_pokemon_habitat wild_pokemon_16_3_rod;
wild_pokemon_habitat wild_pokemon_3_23_grass;
wild_pokemon_habitat wild_pokemon_3_23_other;
wild_pokemon_habitat wild_pokemon_route_5_clouds_grass;
wild_pokemon_habitat wild_pokemon_route_5_clouds_water;
wild_pokemon_habitat wild_pokemon_route_5_clouds_rod;
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
wild_pokemon_habitat wild_pokemon_route_2_clouds_grass;
wild_pokemon_habitat wild_pokemon_route_2_clouds_water;
wild_pokemon_habitat wild_pokemon_route_2_clouds_rod;
wild_pokemon_habitat wild_pokemon_3_8_grass;
wild_pokemon_habitat wild_pokemon_3_8_water;
wild_pokemon_habitat wild_pokemon_3_8_rod;
wild_pokemon_habitat wild_pokemon_3_8_other;
wild_pokemon_habitat wild_pokemon_laubdorf_water;
wild_pokemon_habitat wild_pokemon_laubdorf_rod;
wild_pokemon_habitat wild_pokemon_route_9_water;
wild_pokemon_habitat wild_pokemon_route_9_rod;
wild_pokemon_habitat wild_pokemon_route_10_water;
wild_pokemon_habitat wild_pokemon_route_10_rod;
wild_pokemon_habitat wild_pokemon_route_10_clouds_grass;
wild_pokemon_habitat wild_pokemon_route_11_water;
wild_pokemon_habitat wild_pokemon_route_11_rod;
wild_pokemon_habitat wild_pokemon_forest_cemetery_grass;
wild_pokemon_habitat wild_pokemon_forest_cemetery_other;
wild_pokemon_habitat wild_pokemon_route_12_east_water;
wild_pokemon_habitat wild_pokemon_route_12_east_rod;
wild_pokemon_habitat wild_pokemon_route_12_east_grass;
wild_pokemon_habitat wild_pokemon_route_12_east_other;
wild_pokemon_habitat wild_pokemon_orina_city_clouds_grass;
wild_pokemon_habitat wild_pokemon_orina_city_clouds_water;
wild_pokemon_habitat wild_pokemon_orina_city_clouds_rod;
wild_pokemon_habitat wild_pokemon_route_6_clouds_grass;
wild_pokemon_habitat wild_pokemon_route_6_clouds_water;
wild_pokemon_habitat wild_pokemon_route_6_clouds_rod;
wild_pokemon_habitat wild_pokemon_meriana_city_clouds_grass;
wild_pokemon_habitat wild_pokemon_route_4_clouds_grass;
wild_pokemon_habitat wild_pokemon_kaskada_clouds_grass;
wild_pokemon_habitat wild_pokemon_felsige_oednis_clouds_grass;
wild_pokemon_habitat wild_pokemon_silvania_clouds_grass;
wild_pokemon_habitat wild_pokemon_route_3_clouds_grass;
wild_pokemon_habitat wild_pokemon_silvania_wald_clouds_grass;
wild_pokemon_habitat wild_pokemon_route_8_clouds_grass;
wild_pokemon_habitat wild_pokemon_route_9_clouds_grass;
wild_pokemon_habitat wild_pokemon_route_10_clouds_grass;
wild_pokemon_habitat wild_pokemon_route_11_clouds_grass;
wild_pokemon_habitat wild_pokemon_ceometria_clouds_grass;
wild_pokemon_habitat wild_pokemon_route_12_clouds_grass;
wild_pokemon_habitat wild_pokemon_route_12_west_grass;
wild_pokemon_habitat wild_pokemon_route_12_west_other;
wild_pokemon_habitat wild_pokemon_route_12_west_water;
wild_pokemon_habitat wild_pokemon_route_12_west_rod;
wild_pokemon_habitat wild_pokemon_route_7_north_grass;
wild_pokemon_habitat wild_pokemon_route_7_north_other;
wild_pokemon_habitat wild_pokemon_route_7_castle_grass;
wild_pokemon_habitat wild_pokemon_route_7_castle_other;
wild_pokemon_habitat wild_pokemon_route_7_castle_water;
wild_pokemon_habitat wild_pokemon_route_7_castle_rod;
wild_pokemon_habitat wild_pokemon_route_7_grass;
wild_pokemon_habitat wild_pokemon_route_7_other;
wild_pokemon_habitat wild_pokemon_ardeal_dungeon_grass;
wild_pokemon_habitat wild_pokemon_dark_tower;
wild_pokemon_habitat wild_pokemon_route_2_cave_water;
wild_pokemon_habitat wild_pokemon_route_2_cave_rod;
wild_pokemon_habitat wild_pokemon_tafelberg_south_grass;
wild_pokemon_habitat wild_pokemon_tafelberg_south_other;
wild_pokemon_habitat wild_pokemon_tafelberg_south_water;
wild_pokemon_habitat wild_pokemon_tafelberg_south_rod;
wild_pokemon_habitat wild_pokemon_route_5_rod;
wild_pokemon_habitat wild_pokemon_route_5_water;
wild_pokemon_habitat wild_pokemon_route_5_cave_grass;
wild_pokemon_habitat wild_pokemon_route_4_cloud_cave_grass;

#endif /* INCLUDE_C_MAP_WILD_POKEMON_H_ */
