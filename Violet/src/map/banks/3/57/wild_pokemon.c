#include "types.h"
#include "map/wild_pokemon.h"
#include "constants/wild_pokemon_densities.h"
#include "constants/species.h"

wild_pokemon_entry wild_pokemon_3_57_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 2, .level_max = 3, .species = POKEMON_FLABEBE},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 2, .level_max = 3, .species = POKEMON_FIFFYEN},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 2, .level_max = 3, .species = POKEMON_ZIGZACHS},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 3, .level_max = 3, .species = POKEMON_FLABEBE},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 3, .level_max = 3, .species = POKEMON_FIFFYEN},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 3, .level_max = 3, .species = POKEMON_ZIGZACHS},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 3, .level_max = 3, .species = POKEMON_FLABEBE},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 3, .level_max = 3, .species = POKEMON_FIFFYEN},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 3, .level_max = 3, .species = POKEMON_ZIGZACHS},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 3, .level_max = 4, .species = POKEMON_FLABEBE},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 3, .level_max = 4, .species = POKEMON_FIFFYEN},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 3, .level_max = 4, .species = POKEMON_ZIGZACHS},
};

wild_pokemon_habitat wild_pokemon_3_57_grass = {
	.frequency = 21, .data = wild_pokemon_3_57_grass_entries
};

wild_pokemon_entry wild_pokemon_3_57_water_entries[5] = {
	[WILD_POKEMON_DENSITY_WATER_0_60_PERCENT] = 
		{.level_min = 5, .level_max = 35, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_WATER_1_30_PERCENT] = 
		{.level_min = 5, .level_max = 15, .species = POKEMON_QUABBEL},
	[WILD_POKEMON_DENSITY_WATER_2_5_PERCENT] = 
		{.level_min = 35, .level_max = 40, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_WATER_3_4_PERCENT] = 
		{.level_min = 35, .level_max = 40, .species = POKEMON_TENTOXA},
	[WILD_POKEMON_DENSITY_WATER_3_1_PERCENT] = 
		{.level_min = 35, .level_max = 40, .species = POKEMON_TENTOXA},
};

wild_pokemon_habitat wild_pokemon_3_57_water = {
	.frequency = 6, .data = wild_pokemon_3_57_water_entries
};

wild_pokemon_entry wild_pokemon_3_57_other_entries[5] = {
	[WILD_POKEMON_DENSITY_OTHER_0_30_PERCENT] = 
		{.level_min = 9, .level_max = 11, .species = POKEMON_ABRA},
	[WILD_POKEMON_DENSITY_OTHER_1_25_PERCENT] = 
		{.level_min = 7, .level_max = 11, .species = POKEMON_HORNLIU},
	[WILD_POKEMON_DENSITY_OTHER_2_20_PERCENT] = 
		{.level_min = 8, .level_max = 11, .species = POKEMON_ABRA},
	[WILD_POKEMON_DENSITY_OTHER_3_15_PERCENT] = 
		{.level_min = 8, .level_max = 11, .species = POKEMON_WATTZAPF},
	[WILD_POKEMON_DENSITY_OTHER_4_10_PERCENT] = 
		{.level_min = 9, .level_max = 12, .species = POKEMON_WATTZAPF},
};

wild_pokemon_habitat wild_pokemon_3_57_other = {
	.frequency = 0, .data = wild_pokemon_3_57_other_entries
};

wild_pokemon_entry wild_pokemon_3_57_rod_entries[10] = {
	[WILD_POKEMON_DENSITY_OLD_ROD_0_70_PERCENT] = 
		{.level_min = 5, .level_max = 5, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_OLD_ROD_1_30_PERCENT] = 
		{.level_min = 5, .level_max = 5, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_GOOD_ROD_0_60_PERCENT] = 
		{.level_min = 5, .level_max = 15, .species = POKEMON_SEEPER},
	[WILD_POKEMON_DENSITY_GOOD_ROD_1_20_PERCENT] = 
		{.level_min = 5, .level_max = 15, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_GOOD_ROD_2_20_PERCENT] = 
		{.level_min = 5, .level_max = 15, .species = POKEMON_SEEPER},
	[WILD_POKEMON_DENSITY_SUPER_ROD_0_40_PERCENT] = 
		{.level_min = 15, .level_max = 25, .species = POKEMON_SEEPER},
	[WILD_POKEMON_DENSITY_SUPER_ROD_1_40_PERCENT] = 
		{.level_min = 15, .level_max = 25, .species = POKEMON_SEEPER},
	[WILD_POKEMON_DENSITY_SUPER_ROD_2_15_PERCENT] = 
		{.level_min = 15, .level_max = 25, .species = POKEMON_GARADOS},
	[WILD_POKEMON_DENSITY_SUPER_ROD_3_4_PERCENT] = 
		{.level_min = 25, .level_max = 35, .species = POKEMON_SEEMON},
	[WILD_POKEMON_DENSITY_SUPER_ROD_4_1_PERCENT] = 
		{.level_min = 35, .level_max = 40, .species = POKEMON_SEEPER},
};

wild_pokemon_habitat wild_pokemon_3_57_rod = {
	.frequency = 20, .data = wild_pokemon_3_57_rod_entries
};

wild_pokemon_data wild_pokemon_3_57 = {
	.bank = 3, .map = 57,
	.grass = &wild_pokemon_3_57_grass,
	.water = &wild_pokemon_3_57_water,
	.other = &wild_pokemon_3_57_other,
	.rod = &wild_pokemon_3_57_rod,
};
