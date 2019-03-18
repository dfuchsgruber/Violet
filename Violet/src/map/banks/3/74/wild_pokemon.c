#include "types.h"
#include "map/wild_pokemon.h"
#include "constants/wild_pokemon_densities.h"
#include "constants/species.h"

wild_pokemon_entry wild_pokemon_3_74_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 13, .level_max = 16, .species = POKEMON_PONITA},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 13, .level_max = 16, .species = POKEMON_MAEHIKEL},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 13, .level_max = 16, .species = POKEMON_MYRAPLA},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 13, .level_max = 16, .species = POKEMON_RIHORN},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 14, .level_max = 16, .species = POKEMON_PONITA},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 14, .level_max = 16, .species = POKEMON_MAEHIKEL},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 14, .level_max = 16, .species = POKEMON_PONITA},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 14, .level_max = 16, .species = POKEMON_RIHORN},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 15, .level_max = 17, .species = POKEMON_MAEHIKEL},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 15, .level_max = 17, .species = POKEMON_TAUROS},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 15, .level_max = 17, .species = POKEMON_TAUROS},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 18, .level_max = 18, .species = POKEMON_TAUROS},
};

wild_pokemon_habitat wild_pokemon_3_74_grass = {
	.frequency = 23, .data = wild_pokemon_3_74_grass_entries
};

wild_pokemon_entry wild_pokemon_3_74_other_entries[5] = {
	[WILD_POKEMON_DENSITY_OTHER_0_30_PERCENT] = 
		{.level_min = 13, .level_max = 17, .species = POKEMON_PONITA},
	[WILD_POKEMON_DENSITY_OTHER_1_25_PERCENT] = 
		{.level_min = 13, .level_max = 17, .species = POKEMON_KNACKLION},
	[WILD_POKEMON_DENSITY_OTHER_2_20_PERCENT] = 
		{.level_min = 13, .level_max = 17, .species = POKEMON_SKORGLA},
	[WILD_POKEMON_DENSITY_OTHER_3_15_PERCENT] = 
		{.level_min = 14, .level_max = 17, .species = POKEMON_SKORGLA},
	[WILD_POKEMON_DENSITY_OTHER_4_10_PERCENT] = 
		{.level_min = 16, .level_max = 18, .species = POKEMON_SKORGLA},
};

wild_pokemon_habitat wild_pokemon_3_74_other = {
	.frequency = 134, .data = wild_pokemon_3_74_other_entries
};

wild_pokemon_data wild_pokemon_3_74 = {
	.bank = 3, .map = 74,
	.grass = &wild_pokemon_3_74_grass,
	.water = NULL,
	.other = &wild_pokemon_3_74_other,
	.rod = NULL,
};
