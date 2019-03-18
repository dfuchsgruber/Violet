#include "types.h"
#include "map/wild_pokemon.h"
#include "constants/wild_pokemon_densities.h"
#include "constants/species.h"

wild_pokemon_entry wild_pokemon_15_4_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 10, .level_max = 13, .species = POKEMON_SCHWALBINI},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 10, .level_max = 13, .species = POKEMON_WABLU},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 10, .level_max = 13, .species = POKEMON_SCHWALBINI},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 10, .level_max = 13, .species = POKEMON_STARAVIA},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 10, .level_max = 13, .species = POKEMON_SCHWALBINI},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 10, .level_max = 13, .species = POKEMON_SCHWALBINI},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 10, .level_max = 13, .species = POKEMON_DARTIRI},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 10, .level_max = 13, .species = POKEMON_STARALILI},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 10, .level_max = 13, .species = POKEMON_DARTIRI},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 10, .level_max = 13, .species = POKEMON_WABLU},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 10, .level_max = 13, .species = POKEMON_DARTIRI},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 14, .level_max = 17, .species = POKEMON_STARAVIA},
};

wild_pokemon_habitat wild_pokemon_15_4_grass = {
	.frequency = 6, .data = wild_pokemon_15_4_grass_entries
};

wild_pokemon_data wild_pokemon_15_4 = {
	.bank = 15, .map = 4,
	.grass = &wild_pokemon_15_4_grass,
	.water = NULL,
	.other = NULL,
	.rod = NULL,
};
