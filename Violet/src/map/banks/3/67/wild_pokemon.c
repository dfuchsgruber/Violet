#include "types.h"
#include "map/wild_pokemon.h"
#include "constants/wild_pokemon_densities.h"
#include "constants/species.h"

wild_pokemon_entry wild_pokemon_3_67_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 19, .level_max = 21, .species = POKEMON_DIGDA},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 19, .level_max = 22, .species = POKEMON_ZUBAT},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 19, .level_max = 23, .species = POKEMON_MACHOLLO},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 19, .level_max = 23, .species = POKEMON_DIGDA},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 19, .level_max = 23, .species = POKEMON_ZUBAT},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 19, .level_max = 23, .species = POKEMON_MACHOLLO},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 19, .level_max = 23, .species = POKEMON_DIGDA},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 19, .level_max = 23, .species = POKEMON_ZUBAT},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 19, .level_max = 23, .species = POKEMON_MACHOLLO},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 19, .level_max = 23, .species = POKEMON_DIGDA},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 20, .level_max = 24, .species = POKEMON_ZUBAT},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 24, .level_max = 26, .species = POKEMON_MACHOLLO},
};

wild_pokemon_habitat wild_pokemon_3_67_grass = {
	.frequency = 3, .data = wild_pokemon_3_67_grass_entries
};

wild_pokemon_entry wild_pokemon_3_67_water_entries[5] = {
	[WILD_POKEMON_DENSITY_WATER_0_60_PERCENT] = 
		{.level_min = 35, .level_max = 35, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_WATER_1_30_PERCENT] = 
		{.level_min = 35, .level_max = 35, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_WATER_2_5_PERCENT] = 
		{.level_min = 35, .level_max = 35, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_WATER_3_4_PERCENT] = 
		{.level_min = 35, .level_max = 35, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_WATER_3_1_PERCENT] = 
		{.level_min = 37, .level_max = 37, .species = POKEMON_TENTOXA},
};

wild_pokemon_habitat wild_pokemon_3_67_water = {
	.frequency = 15, .data = wild_pokemon_3_67_water_entries
};

wild_pokemon_entry wild_pokemon_3_67_rod_entries[10] = {
	[WILD_POKEMON_DENSITY_OLD_ROD_0_70_PERCENT] = 
		{.level_min = 20, .level_max = 20, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_OLD_ROD_1_30_PERCENT] = 
		{.level_min = 20, .level_max = 20, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_GOOD_ROD_0_60_PERCENT] = 
		{.level_min = 40, .level_max = 40, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_GOOD_ROD_1_20_PERCENT] = 
		{.level_min = 40, .level_max = 40, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_GOOD_ROD_2_20_PERCENT] = 
		{.level_min = 40, .level_max = 40, .species = POKEMON_TENTOXA},
	[WILD_POKEMON_DENSITY_SUPER_ROD_0_40_PERCENT] = 
		{.level_min = 40, .level_max = 40, .species = POKEMON_TENTOXA},
	[WILD_POKEMON_DENSITY_SUPER_ROD_1_40_PERCENT] = 
		{.level_min = 40, .level_max = 40, .species = POKEMON_TENTOXA},
	[WILD_POKEMON_DENSITY_SUPER_ROD_2_15_PERCENT] = 
		{.level_min = 50, .level_max = 50, .species = POKEMON_TENTOXA},
	[WILD_POKEMON_DENSITY_SUPER_ROD_3_4_PERCENT] = 
		{.level_min = 50, .level_max = 50, .species = POKEMON_TENTOXA},
	[WILD_POKEMON_DENSITY_SUPER_ROD_4_1_PERCENT] = 
		{.level_min = 50, .level_max = 50, .species = POKEMON_TENTOXA},
};

wild_pokemon_habitat wild_pokemon_3_67_rod = {
	.frequency = 6, .data = wild_pokemon_3_67_rod_entries
};

wild_pokemon_data wild_pokemon_3_67 = {
	.bank = 3, .map = 67,
	.grass = &wild_pokemon_3_67_grass,
	.water = &wild_pokemon_3_67_water,
	.other = NULL,
	.rod = &wild_pokemon_3_67_rod,
};
