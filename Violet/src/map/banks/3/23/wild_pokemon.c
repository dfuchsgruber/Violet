#include "types.h"
#include "map/wild_pokemon.h"
#include "constants/wild_pokemon_densities.h"
#include "constants/species.h"

wild_pokemon_entry wild_pokemon_3_23_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 30, .level_max = 33, .species = POKEMON_SCHWALBINI},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 30, .level_max = 33, .species = POKEMON_WABLU},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 30, .level_max = 33, .species = POKEMON_MEDITIE},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 30, .level_max = 33, .species = POKEMON_WABLU},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 30, .level_max = 33, .species = POKEMON_WABLU},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 31, .level_max = 33, .species = POKEMON_WAATY},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 31, .level_max = 34, .species = POKEMON_MEDITIE},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 31, .level_max = 34, .species = POKEMON_WABLU},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 31, .level_max = 34, .species = POKEMON_SPOINK},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 32, .level_max = 34, .species = POKEMON_SPOINK},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 31, .level_max = 34, .species = POKEMON_SPOINK},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 32, .level_max = 35, .species = POKEMON_GROINK},
};

wild_pokemon_habitat wild_pokemon_3_23_grass = {
	.frequency = 21, .data = wild_pokemon_3_23_grass_entries
};

wild_pokemon_entry wild_pokemon_3_23_other_entries[5] = {
	[WILD_POKEMON_DENSITY_OTHER_0_30_PERCENT] = 
		{.level_min = 25, .level_max = 28, .species = POKEMON_SNUBBULL},
	[WILD_POKEMON_DENSITY_OTHER_1_25_PERCENT] = 
		{.level_min = 26, .level_max = 28, .species = POKEMON_SPOINK},
	[WILD_POKEMON_DENSITY_OTHER_2_20_PERCENT] = 
		{.level_min = 28, .level_max = 32, .species = POKEMON_WABLU},
	[WILD_POKEMON_DENSITY_OTHER_3_15_PERCENT] = 
		{.level_min = 29, .level_max = 32, .species = POKEMON_SPOINK},
	[WILD_POKEMON_DENSITY_OTHER_4_10_PERCENT] = 
		{.level_min = 32, .level_max = 34, .species = POKEMON_AMPHAROS},
};

wild_pokemon_habitat wild_pokemon_3_23_other = {
	.frequency = 200, .data = wild_pokemon_3_23_other_entries
};

wild_pokemon_entry wild_pokemon_route_5_water_entries[5] = {
	[WILD_POKEMON_DENSITY_WATER_0_60_PERCENT] = 
		{.level_min = 5, .level_max = 10, .species = POKEMON_LOTURZEL},
	[WILD_POKEMON_DENSITY_WATER_1_30_PERCENT] = 
		{.level_min = 10, .level_max = 20, .species = POKEMON_LOTURZEL},
	[WILD_POKEMON_DENSITY_WATER_2_5_PERCENT] = 
		{.level_min = 20, .level_max = 30, .species = POKEMON_MARILL},
	[WILD_POKEMON_DENSITY_WATER_3_4_PERCENT] = 
		{.level_min = 30, .level_max = 35, .species = POKEMON_ENTON},
	[WILD_POKEMON_DENSITY_WATER_3_1_PERCENT] = 
		{.level_min = 30, .level_max = 35, .species = POKEMON_ENTORON},
};

wild_pokemon_habitat wild_pokemon_route_5_water = {
	.frequency = 2, .data = wild_pokemon_route_5_water_entries
};

wild_pokemon_entry wild_pokemon_route_5_rod_entries[10] = {
	[WILD_POKEMON_DENSITY_OLD_ROD_0_70_PERCENT] = 
		{.level_min = 5, .level_max = 5, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_OLD_ROD_1_30_PERCENT] = 
		{.level_min = 5, .level_max = 5, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_GOOD_ROD_0_60_PERCENT] = 
		{.level_min = 35, .level_max = 40, .species = POKEMON_FLEGMON},
	[WILD_POKEMON_DENSITY_GOOD_ROD_1_20_PERCENT] = 
		{.level_min = 35, .level_max = 40, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_GOOD_ROD_2_20_PERCENT] = 
		{.level_min = 35, .level_max = 40, .species = POKEMON_FLEGMON},
	[WILD_POKEMON_DENSITY_SUPER_ROD_0_40_PERCENT] = 
		{.level_min = 35, .level_max = 40, .species = POKEMON_FLEGMON},
	[WILD_POKEMON_DENSITY_SUPER_ROD_1_40_PERCENT] = 
		{.level_min = 35, .level_max = 40, .species = POKEMON_FLEGMON},
	[WILD_POKEMON_DENSITY_SUPER_ROD_2_15_PERCENT] = 
		{.level_min = 35, .level_max = 40, .species = POKEMON_FLEGMON},
	[WILD_POKEMON_DENSITY_SUPER_ROD_3_4_PERCENT] = 
		{.level_min = 25, .level_max = 35, .species = POKEMON_FLEGMON},
	[WILD_POKEMON_DENSITY_SUPER_ROD_4_1_PERCENT] = 
		{.level_min = 25, .level_max = 35, .species = POKEMON_GARADOS},
};

wild_pokemon_habitat wild_pokemon_route_5_rod = {
	.frequency = 20, .data = wild_pokemon_route_5_rod_entries
};
