#include "types.h"
#include "map/wild_pokemon.h"
#include "constants/wild_pokemon_densities.h"
#include "constants/species.h"

wild_pokemon_entry wild_pokemon_3_3_water_entries[5] = {
	[WILD_POKEMON_DENSITY_WATER_0_60_PERCENT] = 
		{.level_min = 30, .level_max = 30, .species = POKEMON_SEEPER},
	[WILD_POKEMON_DENSITY_WATER_1_30_PERCENT] = 
		{.level_min = 30, .level_max = 30, .species = POKEMON_SEEPER},
	[WILD_POKEMON_DENSITY_WATER_2_5_PERCENT] = 
		{.level_min = 30, .level_max = 30, .species = POKEMON_SEEPER},
	[WILD_POKEMON_DENSITY_WATER_3_4_PERCENT] = 
		{.level_min = 30, .level_max = 35, .species = POKEMON_SEEMON},
	[WILD_POKEMON_DENSITY_WATER_3_1_PERCENT] = 
		{.level_min = 35, .level_max = 38, .species = POKEMON_SEEDRAKING},
};

wild_pokemon_habitat wild_pokemon_3_3_water = {
	.frequency = 17, .data = wild_pokemon_3_3_water_entries
};

wild_pokemon_entry wild_pokemon_3_3_rod_entries[10] = {
	[WILD_POKEMON_DENSITY_OLD_ROD_0_70_PERCENT] = 
		{.level_min = 13, .level_max = 16, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_OLD_ROD_1_30_PERCENT] = 
		{.level_min = 13, .level_max = 16, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_GOOD_ROD_0_60_PERCENT] = 
		{.level_min = 5, .level_max = 15, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_GOOD_ROD_1_20_PERCENT] = 
		{.level_min = 5, .level_max = 15, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_GOOD_ROD_2_20_PERCENT] = 
		{.level_min = 5, .level_max = 15, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_0_40_PERCENT] = 
		{.level_min = 15, .level_max = 25, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_1_40_PERCENT] = 
		{.level_min = 15, .level_max = 25, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_2_15_PERCENT] = 
		{.level_min = 15, .level_max = 25, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_3_4_PERCENT] = 
		{.level_min = 25, .level_max = 35, .species = POKEMON_GARADOS},
	[WILD_POKEMON_DENSITY_SUPER_ROD_4_1_PERCENT] = 
		{.level_min = 25, .level_max = 35, .species = POKEMON_GARADOS},
};

wild_pokemon_habitat wild_pokemon_3_3_rod = {
	.frequency = 10, .data = wild_pokemon_3_3_rod_entries
};

wild_pokemon_data wild_pokemon_3_3 = {
	.bank = 3, .map = 3,
	.grass = NULL,
	.water = &wild_pokemon_3_3_water,
	.other = NULL,
	.rod = &wild_pokemon_3_3_rod,
};
