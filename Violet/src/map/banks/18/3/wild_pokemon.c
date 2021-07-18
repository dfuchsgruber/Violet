#include "types.h"
#include "map/wild_pokemon.h"
#include "constants/wild_pokemon_densities.h"
#include "constants/species.h"

wild_pokemon_entry wild_pokemon_18_3_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 32, .level_max = 34, .species = POKEMON_VULPIX},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 32, .level_max = 34, .species = POKEMON_SCHNECKMAG},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 33, .level_max = 34, .species = POKEMON_MAGBY},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 33, .level_max = 35, .species = POKEMON_CAMAUB},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 33, .level_max = 35, .species = POKEMON_VULPIX},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 33, .level_max = 35, .species = POKEMON_SCHNECKMAG},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 34, .level_max = 35, .species = POKEMON_CAMAUB},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 34, .level_max = 35, .species = POKEMON_MAGBY},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 34, .level_max = 36, .species = POKEMON_VULPIX},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 35, .level_max = 36, .species = POKEMON_SCHNECKMAG},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 35, .level_max = 37, .species = POKEMON_CAMAUB},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 37, .level_max = 37, .species = POKEMON_MAGMAR},
};

wild_pokemon_habitat wild_pokemon_18_3_grass = {
	.frequency = 24, .data = wild_pokemon_18_3_grass_entries
};

wild_pokemon_entry wild_pokemon_18_3_other_entries[5] = {
	[WILD_POKEMON_DENSITY_OTHER_0_30_PERCENT] = 
		{.level_min = 35, .level_max = 37, .species = POKEMON_FUKANO},
	[WILD_POKEMON_DENSITY_OTHER_1_25_PERCENT] = 
		{.level_min = 35, .level_max = 37, .species = POKEMON_HUNDUSTER},
	[WILD_POKEMON_DENSITY_OTHER_2_20_PERCENT] = 
		{.level_min = 36, .level_max = 38, .species = POKEMON_FUKANO},
	[WILD_POKEMON_DENSITY_OTHER_3_15_PERCENT] = 
		{.level_min = 36, .level_max = 38, .species = POKEMON_HUNDUSTER},
	[WILD_POKEMON_DENSITY_OTHER_4_10_PERCENT] = 
		{.level_min = 38, .level_max = 38, .species = POKEMON_PANZAERON},
};

wild_pokemon_habitat wild_pokemon_18_3_other = {
	.frequency = 79, .data = wild_pokemon_18_3_other_entries
};
