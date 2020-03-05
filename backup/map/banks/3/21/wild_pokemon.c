#include "types.h"
#include "map/wild_pokemon.h"
#include "constants/wild_pokemon_densities.h"
#include "constants/species.h"

wild_pokemon_entry wild_pokemon_3_21_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 17, .level_max = 19, .species = POKEMON_KNACKLION},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 17, .level_max = 19, .species = POKEMON_PUPPANCE},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 17, .level_max = 19, .species = POKEMON_SANDAN},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 17, .level_max = 19, .species = POKEMON_DIGDA},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 17, .level_max = 19, .species = POKEMON_KNACKLION},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 17, .level_max = 19, .species = POKEMON_DIGDA},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 17, .level_max = 19, .species = POKEMON_SANDAN},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 17, .level_max = 19, .species = POKEMON_PUPPANCE},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 17, .level_max = 19, .species = POKEMON_DIGDA},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 17, .level_max = 19, .species = POKEMON_DIGDA},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 17, .level_max = 19, .species = POKEMON_SANDAN},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 19, .level_max = 22, .species = POKEMON_SANDAN},
};

wild_pokemon_habitat wild_pokemon_3_21_grass = {
	.frequency = 17, .data = wild_pokemon_3_21_grass_entries
};

wild_pokemon_entry wild_pokemon_3_21_other_entries[5] = {
	[WILD_POKEMON_DENSITY_OTHER_0_30_PERCENT] = 
		{.level_min = 16, .level_max = 19, .species = POKEMON_TUSKA},
	[WILD_POKEMON_DENSITY_OTHER_1_25_PERCENT] = 
		{.level_min = 16, .level_max = 20, .species = POKEMON_TUSKA},
	[WILD_POKEMON_DENSITY_OTHER_2_20_PERCENT] = 
		{.level_min = 16, .level_max = 21, .species = POKEMON_TUSKA},
	[WILD_POKEMON_DENSITY_OTHER_3_15_PERCENT] = 
		{.level_min = 18, .level_max = 22, .species = POKEMON_SANDAMER},
	[WILD_POKEMON_DENSITY_OTHER_4_10_PERCENT] = 
		{.level_min = 25, .level_max = 25, .species = POKEMON_SANDAMER},
};

wild_pokemon_habitat wild_pokemon_3_21_other = {
	.frequency = 154, .data = wild_pokemon_3_21_other_entries
};
