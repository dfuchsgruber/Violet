#include "types.h"
#include "map/wild_pokemon.h"
#include "constants/wild_pokemon_densities.h"
#include "constants/species.h"

wild_pokemon_entry wild_pokemon_3_22_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 21, .level_max = 25, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 21, .level_max = 25, .species = POKEMON_MACHOLLO},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 21, .level_max = 25, .species = POKEMON_MEDITIE},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 21, .level_max = 25, .species = POKEMON_LOTURZEL},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 21, .level_max = 25, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 21, .level_max = 25, .species = POKEMON_MACHOLLO},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 21, .level_max = 25, .species = POKEMON_MEDITIE},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 22, .level_max = 25, .species = POKEMON_MEDITIE},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 22, .level_max = 25, .species = POKEMON_LOMBRERO},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 22, .level_max = 26, .species = POKEMON_LOMBRERO},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 25, .level_max = 28, .species = POKEMON_MASCHOCK},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 25, .level_max = 28, .species = POKEMON_MASCHOCK},
};

wild_pokemon_habitat wild_pokemon_3_22_grass = {
	.frequency = 21, .data = wild_pokemon_3_22_grass_entries
};

wild_pokemon_entry wild_pokemon_3_22_water_entries[5] = {
	[WILD_POKEMON_DENSITY_WATER_0_60_PERCENT] = 
		{.level_min = 5, .level_max = 10, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_WATER_1_30_PERCENT] = 
		{.level_min = 10, .level_max = 20, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_WATER_2_5_PERCENT] = 
		{.level_min = 20, .level_max = 30, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_WATER_3_4_PERCENT] = 
		{.level_min = 30, .level_max = 35, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_WATER_3_1_PERCENT] = 
		{.level_min = 30, .level_max = 35, .species = POKEMON_TENTACHA},
};

wild_pokemon_habitat wild_pokemon_3_22_water = {
	.frequency = 2, .data = wild_pokemon_3_22_water_entries
};

wild_pokemon_entry wild_pokemon_3_22_other_entries[5] = {
	[WILD_POKEMON_DENSITY_OTHER_0_30_PERCENT] = 
		{.level_min = 23, .level_max = 26, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_OTHER_1_25_PERCENT] = 
		{.level_min = 21, .level_max = 26, .species = POKEMON_FELINO},
	[WILD_POKEMON_DENSITY_OTHER_2_20_PERCENT] = 
		{.level_min = 23, .level_max = 25, .species = POKEMON_PANDIR},
	[WILD_POKEMON_DENSITY_OTHER_3_15_PERCENT] = 
		{.level_min = 23, .level_max = 25, .species = POKEMON_PANDIR},
	[WILD_POKEMON_DENSITY_OTHER_4_10_PERCENT] = 
		{.level_min = 28, .level_max = 28, .species = POKEMON_PANDIR},
};

wild_pokemon_habitat wild_pokemon_3_22_other = {
	.frequency = 159, .data = wild_pokemon_3_22_other_entries
};

wild_pokemon_entry wild_pokemon_3_22_rod_entries[10] = {
	[WILD_POKEMON_DENSITY_OLD_ROD_0_70_PERCENT] = 
		{.level_min = 5, .level_max = 5, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_OLD_ROD_1_30_PERCENT] = 
		{.level_min = 5, .level_max = 5, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_GOOD_ROD_0_60_PERCENT] = 
		{.level_min = 5, .level_max = 15, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_GOOD_ROD_1_20_PERCENT] = 
		{.level_min = 5, .level_max = 15, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_GOOD_ROD_2_20_PERCENT] = 
		{.level_min = 5, .level_max = 15, .species = POKEMON_KRABBY},
	[WILD_POKEMON_DENSITY_SUPER_ROD_0_40_PERCENT] = 
		{.level_min = 15, .level_max = 25, .species = POKEMON_KRABBY},
	[WILD_POKEMON_DENSITY_SUPER_ROD_1_40_PERCENT] = 
		{.level_min = 15, .level_max = 25, .species = POKEMON_KRABBY},
	[WILD_POKEMON_DENSITY_SUPER_ROD_2_15_PERCENT] = 
		{.level_min = 15, .level_max = 25, .species = POKEMON_KINGLER},
	[WILD_POKEMON_DENSITY_SUPER_ROD_3_4_PERCENT] = 
		{.level_min = 25, .level_max = 35, .species = POKEMON_GARADOS},
	[WILD_POKEMON_DENSITY_SUPER_ROD_4_1_PERCENT] = 
		{.level_min = 25, .level_max = 35, .species = POKEMON_GARADOS},
};

wild_pokemon_habitat wild_pokemon_3_22_rod = {
	.frequency = 20, .data = wild_pokemon_3_22_rod_entries
};
