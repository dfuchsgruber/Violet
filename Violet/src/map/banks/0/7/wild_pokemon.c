#include "types.h"
#include "map/wild_pokemon.h"
#include "constants/wild_pokemon_densities.h"
#include "constants/species.h"

wild_pokemon_entry wild_pokemon_0_7_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 20, .level_max = 22, .species = POKEMON_MARILL},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 18, .level_max = 22, .species = POKEMON_KRABBY},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 18, .level_max = 22, .species = POKEMON_ZUBAT},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 18, .level_max = 22, .species = POKEMON_FLEGMON},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 18, .level_max = 22, .species = POKEMON_KRABBY},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 18, .level_max = 18, .species = POKEMON_ZUBAT},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 22, .level_max = 22, .species = POKEMON_FLEGMON},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 22, .level_max = 17, .species = POKEMON_KRABBY},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 17, .level_max = 17, .species = POKEMON_ZUBAT},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 18, .level_max = 18, .species = POKEMON_MARILL},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 19, .level_max = 21, .species = POKEMON_KRABBY},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 26, .level_max = 26, .species = POKEMON_AZUMARILL},
};

wild_pokemon_habitat wild_pokemon_0_7_grass = {
	.frequency = 1, .data = wild_pokemon_0_7_grass_entries
};

wild_pokemon_entry wild_pokemon_0_7_water_entries[5] = {
	[WILD_POKEMON_DENSITY_WATER_0_60_PERCENT] = 
		{.level_min = 25, .level_max = 32, .species = POKEMON_KRABBY},
	[WILD_POKEMON_DENSITY_WATER_1_30_PERCENT] = 
		{.level_min = 25, .level_max = 32, .species = POKEMON_KREBSCORPS},
	[WILD_POKEMON_DENSITY_WATER_2_5_PERCENT] = 
		{.level_min = 27, .level_max = 33, .species = POKEMON_KRABBY},
	[WILD_POKEMON_DENSITY_WATER_3_4_PERCENT] = 
		{.level_min = 25, .level_max = 34, .species = POKEMON_KINGLER},
	[WILD_POKEMON_DENSITY_WATER_3_1_PERCENT] = 
		{.level_min = 30, .level_max = 35, .species = POKEMON_KINGLER},
};

wild_pokemon_habitat wild_pokemon_0_7_water = {
	.frequency = 10, .data = wild_pokemon_0_7_water_entries
};

wild_pokemon_entry wild_pokemon_0_7_rod_entries[10] = {
	[WILD_POKEMON_DENSITY_OLD_ROD_0_70_PERCENT] = 
		{.level_min = 20, .level_max = 22, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_OLD_ROD_1_30_PERCENT] = 
		{.level_min = 20, .level_max = 22, .species = POKEMON_KRABBY},
	[WILD_POKEMON_DENSITY_GOOD_ROD_0_60_PERCENT] = 
		{.level_min = 20, .level_max = 22, .species = POKEMON_FLEGMON},
	[WILD_POKEMON_DENSITY_GOOD_ROD_1_20_PERCENT] = 
		{.level_min = 20, .level_max = 22, .species = POKEMON_KRABBY},
	[WILD_POKEMON_DENSITY_GOOD_ROD_2_20_PERCENT] = 
		{.level_min = 20, .level_max = 22, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_0_40_PERCENT] = 
		{.level_min = 20, .level_max = 22, .species = POKEMON_KRABBY},
	[WILD_POKEMON_DENSITY_SUPER_ROD_1_40_PERCENT] = 
		{.level_min = 20, .level_max = 24, .species = POKEMON_FLEGMON},
	[WILD_POKEMON_DENSITY_SUPER_ROD_2_15_PERCENT] = 
		{.level_min = 20, .level_max = 24, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_3_4_PERCENT] = 
		{.level_min = 20, .level_max = 24, .species = POKEMON_KINGLER},
	[WILD_POKEMON_DENSITY_SUPER_ROD_4_1_PERCENT] = 
		{.level_min = 25, .level_max = 25, .species = POKEMON_KINGLER},
};

wild_pokemon_habitat wild_pokemon_0_7_rod = {
	.frequency = 30, .data = wild_pokemon_0_7_rod_entries
};
