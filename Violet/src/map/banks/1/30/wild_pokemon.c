#include "types.h"
#include "map/wild_pokemon.h"
#include "constants/wild_pokemon_densities.h"
#include "constants/species.h"

wild_pokemon_entry wild_pokemon_1_30_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 27, .level_max = 30, .species = POKEMON_DARTIGNIS},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 27, .level_max = 30, .species = POKEMON_KLEINSTEIN},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 27, .level_max = 30, .species = POKEMON_SCHNECKMAG},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 27, .level_max = 30, .species = POKEMON_DARTIGNIS},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 27, .level_max = 30, .species = POKEMON_KLEINSTEIN},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 27, .level_max = 30, .species = POKEMON_SCHNECKMAG},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 28, .level_max = 31, .species = POKEMON_DARTIGNIS},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 28, .level_max = 31, .species = POKEMON_GEOROK},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 29, .level_max = 32, .species = POKEMON_SCHNECKMAG},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 30, .level_max = 32, .species = POKEMON_DARTIGNIS},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 30, .level_max = 33, .species = POKEMON_GEOROK},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 33, .level_max = 35, .species = POKEMON_MAGCARGO},
};

wild_pokemon_habitat wild_pokemon_1_30_grass = {
	.frequency = 9, .data = wild_pokemon_1_30_grass_entries
};

wild_pokemon_entry wild_pokemon_1_30_other_entries[5] = {
	[WILD_POKEMON_DENSITY_OTHER_0_30_PERCENT] = 
		{.level_min = 29, .level_max = 32, .species = POKEMON_VULPIX},
	[WILD_POKEMON_DENSITY_OTHER_1_25_PERCENT] = 
		{.level_min = 29, .level_max = 32, .species = POKEMON_DARTIGNIS},
	[WILD_POKEMON_DENSITY_OTHER_2_20_PERCENT] = 
		{.level_min = 29, .level_max = 33, .species = POKEMON_CAMAUB},
	[WILD_POKEMON_DENSITY_OTHER_3_15_PERCENT] = 
		{.level_min = 30, .level_max = 34, .species = POKEMON_VULPIX},
	[WILD_POKEMON_DENSITY_OTHER_4_10_PERCENT] = 
		{.level_min = 32, .level_max = 37, .species = POKEMON_MAGMAR},
};

wild_pokemon_habitat wild_pokemon_1_30_other = {
	.frequency = 145, .data = wild_pokemon_1_30_other_entries
};
