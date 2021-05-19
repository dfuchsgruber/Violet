#include "types.h"
#include "map/wild_pokemon.h"
#include "constants/wild_pokemon_densities.h"
#include "constants/species.h"

wild_pokemon_entry wild_pokemon_3_41_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 5, .level_max = 7, .species = POKEMON_FRIZELBLIZ},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 5, .level_max = 7, .species = POKEMON_TRASLA},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 5, .level_max = 7, .species = POKEMON_WAUMPEL},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 5, .level_max = 7, .species = POKEMON_ABRA},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 5, .level_max = 7, .species = POKEMON_KOKUNA},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 5, .level_max = 7, .species = POKEMON_HORNLIU},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 5, .level_max = 7, .species = POKEMON_MENKI},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 5, .level_max = 7, .species = POKEMON_ABRA},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 5, .level_max = 7, .species = POKEMON_MENKI},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 5, .level_max = 7, .species = POKEMON_MENKI},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 5, .level_max = 7, .species = POKEMON_MENKI},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 10, .level_max = 10, .species = POKEMON_BIBOR},
};

wild_pokemon_habitat wild_pokemon_3_41_grass = {
	.frequency = 16, .data = wild_pokemon_3_41_grass_entries
};

wild_pokemon_entry wild_pokemon_3_41_water_entries[5] = {
	[WILD_POKEMON_DENSITY_WATER_0_60_PERCENT] = 
		{.level_min = 20, .level_max = 25, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_WATER_1_30_PERCENT] = 
		{.level_min = 20, .level_max = 25, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_WATER_2_5_PERCENT] = 
		{.level_min = 25, .level_max = 30, .species = POKEMON_MARILL},
	[WILD_POKEMON_DENSITY_WATER_3_4_PERCENT] = 
		{.level_min = 30, .level_max = 35, .species = POKEMON_MARILL},
	[WILD_POKEMON_DENSITY_WATER_3_1_PERCENT] = 
		{.level_min = 30, .level_max = 35, .species = POKEMON_AZUMARILL},
};

wild_pokemon_habitat wild_pokemon_3_41_water = {
	.frequency = 7, .data = wild_pokemon_3_41_water_entries
};

wild_pokemon_entry wild_pokemon_3_41_other_entries[5] = {
	[WILD_POKEMON_DENSITY_OTHER_0_30_PERCENT] = 
		{.level_min = 9, .level_max = 12, .species = POKEMON_VOLTOBAL},
	[WILD_POKEMON_DENSITY_OTHER_1_25_PERCENT] = 
		{.level_min = 9, .level_max = 12, .species = POKEMON_ZIGZACHS},
	[WILD_POKEMON_DENSITY_OTHER_2_20_PERCENT] = 
		{.level_min = 10, .level_max = 14, .species = POKEMON_SAMURZEL},
	[WILD_POKEMON_DENSITY_OTHER_3_15_PERCENT] = 
		{.level_min = 10, .level_max = 14, .species = POKEMON_SAMURZEL},
	[WILD_POKEMON_DENSITY_OTHER_4_10_PERCENT] = 
		{.level_min = 10, .level_max = 15, .species = POKEMON_SAMURZEL},
};

wild_pokemon_habitat wild_pokemon_3_41_other = {
	.frequency = 151, .data = wild_pokemon_3_41_other_entries
};

wild_pokemon_entry wild_pokemon_3_41_rod_entries[10] = {
	[WILD_POKEMON_DENSITY_OLD_ROD_0_70_PERCENT] = 
		{.level_min = 9, .level_max = 11, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_OLD_ROD_1_30_PERCENT] = 
		{.level_min = 9, .level_max = 11, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_GOOD_ROD_0_60_PERCENT] = 
		{.level_min = 25, .level_max = 35, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_GOOD_ROD_1_20_PERCENT] = 
		{.level_min = 25, .level_max = 35, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_GOOD_ROD_2_20_PERCENT] = 
		{.level_min = 25, .level_max = 35, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_0_40_PERCENT] = 
		{.level_min = 25, .level_max = 35, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_1_40_PERCENT] = 
		{.level_min = 45, .level_max = 50, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_SUPER_ROD_2_15_PERCENT] = 
		{.level_min = 45, .level_max = 50, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_3_4_PERCENT] = 
		{.level_min = 45, .level_max = 50, .species = POKEMON_TENTOXA},
	[WILD_POKEMON_DENSITY_SUPER_ROD_4_1_PERCENT] = 
		{.level_min = 45, .level_max = 55, .species = POKEMON_GARADOS},
};

wild_pokemon_habitat wild_pokemon_3_41_rod = {
	.frequency = 49, .data = wild_pokemon_3_41_rod_entries
};
