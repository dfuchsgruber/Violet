#include "types.h"
#include "map/wild_pokemon.h"
#include "constants/wild_pokemon_densities.h"
#include "constants/species.h"

wild_pokemon_entry wild_pokemon_3_7_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 4, .level_max = 7, .species = POKEMON_KNOFENSA},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 4, .level_max = 7, .species = POKEMON_NIDORANW},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 4, .level_max = 7, .species = POKEMON_FLABEBE},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 4, .level_max = 7, .species = POKEMON_NIDORANM},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 4, .level_max = 7, .species = POKEMON_ENECO},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 4, .level_max = 7, .species = POKEMON_NIDORANW},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 5, .level_max = 7, .species = POKEMON_NIDORANM},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 5, .level_max = 7, .species = POKEMON_NIDORANM},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 6, .level_max = 7, .species = POKEMON_ENECO},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 6, .level_max = 7, .species = POKEMON_KNOFENSA},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 8, .level_max = 8, .species = POKEMON_NIDORANW},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 8, .level_max = 8, .species = POKEMON_NIDORANM},
};

wild_pokemon_habitat wild_pokemon_3_7_grass = {
	.frequency = 24, .data = wild_pokemon_3_7_grass_entries
};

wild_pokemon_entry wild_pokemon_3_7_other_entries[5] = {
	[WILD_POKEMON_DENSITY_OTHER_0_30_PERCENT] = 
		{.level_min = 7, .level_max = 9, .species = POKEMON_TANNZA},
	[WILD_POKEMON_DENSITY_OTHER_1_25_PERCENT] = 
		{.level_min = 7, .level_max = 9, .species = POKEMON_SAMURZEL},
	[WILD_POKEMON_DENSITY_OTHER_2_20_PERCENT] = 
		{.level_min = 7, .level_max = 9, .species = POKEMON_BUMMELZ},
	[WILD_POKEMON_DENSITY_OTHER_3_15_PERCENT] = 
		{.level_min = 7, .level_max = 9, .species = POKEMON_TANNZA},
	[WILD_POKEMON_DENSITY_OTHER_4_10_PERCENT] = 
		{.level_min = 10, .level_max = 11, .species = POKEMON_SAMURZEL},
};

wild_pokemon_habitat wild_pokemon_3_7_other = {
	.frequency = 130, .data = wild_pokemon_3_7_other_entries
};
