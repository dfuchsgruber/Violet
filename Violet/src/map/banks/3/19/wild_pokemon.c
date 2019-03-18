#include "types.h"
#include "map/wild_pokemon.h"
#include "constants/wild_pokemon_densities.h"
#include "constants/species.h"

wild_pokemon_entry wild_pokemon_3_19_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 3, .level_max = 3, .species = POKEMON_FIFFYEN},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 3, .level_max = 3, .species = POKEMON_DARTIRI},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 3, .level_max = 3, .species = POKEMON_FIFFYEN},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 3, .level_max = 3, .species = POKEMON_ZIGZACHS},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 2, .level_max = 2, .species = POKEMON_STARALILI},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 2, .level_max = 2, .species = POKEMON_STARALILI},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 3, .level_max = 3, .species = POKEMON_STARALILI},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 3, .level_max = 3, .species = POKEMON_FIFFYEN},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 3, .level_max = 3, .species = POKEMON_STARALILI},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 4, .level_max = 4, .species = POKEMON_STARALILI},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 5, .level_max = 5, .species = POKEMON_STARALILI},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 4, .level_max = 4, .species = POKEMON_STARALILI},
};

wild_pokemon_habitat wild_pokemon_3_19_grass = {
	.frequency = 39, .data = wild_pokemon_3_19_grass_entries
};

wild_pokemon_entry wild_pokemon_3_19_other_entries[5] = {
	[WILD_POKEMON_DENSITY_OTHER_0_30_PERCENT] = 
		{.level_min = 8, .level_max = 10, .species = POKEMON_FUKANO},
	[WILD_POKEMON_DENSITY_OTHER_1_25_PERCENT] = 
		{.level_min = 7, .level_max = 11, .species = POKEMON_NIDORANW},
	[WILD_POKEMON_DENSITY_OTHER_2_20_PERCENT] = 
		{.level_min = 8, .level_max = 11, .species = POKEMON_NIDORANM},
	[WILD_POKEMON_DENSITY_OTHER_3_15_PERCENT] = 
		{.level_min = 7, .level_max = 11, .species = POKEMON_SNUBBULL},
	[WILD_POKEMON_DENSITY_OTHER_4_10_PERCENT] = 
		{.level_min = 8, .level_max = 12, .species = POKEMON_SNUBBULL},
};

wild_pokemon_habitat wild_pokemon_3_19_other = {
	.frequency = 0, .data = wild_pokemon_3_19_other_entries
};

wild_pokemon_data wild_pokemon_3_19 = {
	.bank = 3, .map = 19,
	.grass = &wild_pokemon_3_19_grass,
	.water = NULL,
	.other = &wild_pokemon_3_19_other,
	.rod = NULL,
};
