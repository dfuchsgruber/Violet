#include "types.h"
#include "map/wild_pokemon.h"
#include "constants/wild_pokemon_densities.h"
#include "constants/species.h"

wild_pokemon_entry wild_pokemon_15_0_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 9, .level_max = 12, .species = POKEMON_VOLTILAMM},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 8, .level_max = 11, .species = POKEMON_KNOFENSA},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 9, .level_max = 13, .species = POKEMON_MYRAPLA},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 9, .level_max = 13, .species = POKEMON_MAEHIKEL},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 7, .level_max = 14, .species = POKEMON_VOLTILAMM},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 9, .level_max = 13, .species = POKEMON_KNOFENSA},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 8, .level_max = 11, .species = POKEMON_MYRAPLA},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 8, .level_max = 11, .species = POKEMON_MAEHIKEL},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 8, .level_max = 11, .species = POKEMON_VOLTILAMM},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 8, .level_max = 11, .species = POKEMON_VOLTILAMM},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 8, .level_max = 11, .species = POKEMON_KNOFENSA},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 15, .level_max = 15, .species = POKEMON_WAATY},
};

wild_pokemon_habitat wild_pokemon_15_0_grass = {
	.frequency = 16, .data = wild_pokemon_15_0_grass_entries
};

wild_pokemon_entry wild_pokemon_15_0_water_entries[5] = {
	[WILD_POKEMON_DENSITY_WATER_0_60_PERCENT] = 
		{.level_min = 26, .level_max = 30, .species = POKEMON_LOTURZEL},
	[WILD_POKEMON_DENSITY_WATER_1_30_PERCENT] = 
		{.level_min = 28, .level_max = 33, .species = POKEMON_LOMBRERO},
	[WILD_POKEMON_DENSITY_WATER_2_5_PERCENT] = 
		{.level_min = 28, .level_max = 30, .species = POKEMON_MARILL},
	[WILD_POKEMON_DENSITY_WATER_3_4_PERCENT] = 
		{.level_min = 30, .level_max = 35, .species = POKEMON_AZUMARILL},
	[WILD_POKEMON_DENSITY_WATER_3_1_PERCENT] = 
		{.level_min = 27, .level_max = 35, .species = POKEMON_AZUMARILL},
};

wild_pokemon_habitat wild_pokemon_15_0_water = {
	.frequency = 11, .data = wild_pokemon_15_0_water_entries
};

wild_pokemon_entry wild_pokemon_15_0_other_entries[5] = {
	[WILD_POKEMON_DENSITY_OTHER_0_30_PERCENT] = 
		{.level_min = 10, .level_max = 14, .species = POKEMON_MOGELBAUM},
	[WILD_POKEMON_DENSITY_OTHER_1_25_PERCENT] = 
		{.level_min = 10, .level_max = 14, .species = POKEMON_CLAVION},
	[WILD_POKEMON_DENSITY_OTHER_2_20_PERCENT] = 
		{.level_min = 10, .level_max = 14, .species = POKEMON_MAEHIKEL},
	[WILD_POKEMON_DENSITY_OTHER_3_15_PERCENT] = 
		{.level_min = 12, .level_max = 14, .species = POKEMON_MOGELBAUM},
	[WILD_POKEMON_DENSITY_OTHER_4_10_PERCENT] = 
		{.level_min = 14, .level_max = 16, .species = POKEMON_MILTANK},
};

wild_pokemon_habitat wild_pokemon_15_0_other = {
	.frequency = 130, .data = wild_pokemon_15_0_other_entries
};

wild_pokemon_entry wild_pokemon_15_0_rod_entries[10] = {
	[WILD_POKEMON_DENSITY_OLD_ROD_0_70_PERCENT] = 
		{.level_min = 9, .level_max = 13, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_OLD_ROD_1_30_PERCENT] = 
		{.level_min = 11, .level_max = 14, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_GOOD_ROD_0_60_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_GOOD_ROD_1_20_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_GOOD_ROD_2_20_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_0_40_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_1_40_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_2_15_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_3_4_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_GARADOS},
	[WILD_POKEMON_DENSITY_SUPER_ROD_4_1_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_GARADOS},
};

wild_pokemon_habitat wild_pokemon_15_0_rod = {
	.frequency = 75, .data = wild_pokemon_15_0_rod_entries
};
