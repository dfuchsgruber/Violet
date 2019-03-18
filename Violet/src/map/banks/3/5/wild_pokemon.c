#include "types.h"
#include "map/wild_pokemon.h"
#include "constants/wild_pokemon_densities.h"
#include "constants/species.h"

wild_pokemon_entry wild_pokemon_3_5_water_entries[5] = {
	[WILD_POKEMON_DENSITY_WATER_0_60_PERCENT] = 
		{.level_min = 5, .level_max = 10, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_WATER_1_30_PERCENT] = 
		{.level_min = 10, .level_max = 20, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_WATER_2_5_PERCENT] = 
		{.level_min = 20, .level_max = 30, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_WATER_3_4_PERCENT] = 
		{.level_min = 30, .level_max = 35, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_WATER_3_1_PERCENT] = 
		{.level_min = 35, .level_max = 40, .species = POKEMON_TENTACHA},
};

wild_pokemon_habitat wild_pokemon_3_5_water = {
	.frequency = 1, .data = wild_pokemon_3_5_water_entries
};

wild_pokemon_entry wild_pokemon_3_5_rod_entries[10] = {
	[WILD_POKEMON_DENSITY_OLD_ROD_0_70_PERCENT] = 
		{.level_min = 5, .level_max = 5, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_OLD_ROD_1_30_PERCENT] = 
		{.level_min = 5, .level_max = 5, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_GOOD_ROD_0_60_PERCENT] = 
		{.level_min = 5, .level_max = 15, .species = POKEMON_SEEPER},
	[WILD_POKEMON_DENSITY_GOOD_ROD_1_20_PERCENT] = 
		{.level_min = 5, .level_max = 15, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_GOOD_ROD_2_20_PERCENT] = 
		{.level_min = 5, .level_max = 15, .species = POKEMON_KRABBY},
	[WILD_POKEMON_DENSITY_SUPER_ROD_0_40_PERCENT] = 
		{.level_min = 15, .level_max = 25, .species = POKEMON_SEEPER},
	[WILD_POKEMON_DENSITY_SUPER_ROD_1_40_PERCENT] = 
		{.level_min = 15, .level_max = 25, .species = POKEMON_MUSCHAS},
	[WILD_POKEMON_DENSITY_SUPER_ROD_2_15_PERCENT] = 
		{.level_min = 15, .level_max = 25, .species = POKEMON_GARADOS},
	[WILD_POKEMON_DENSITY_SUPER_ROD_3_4_PERCENT] = 
		{.level_min = 25, .level_max = 35, .species = POKEMON_SEEPER},
	[WILD_POKEMON_DENSITY_SUPER_ROD_4_1_PERCENT] = 
		{.level_min = 25, .level_max = 35, .species = POKEMON_ENTON},
};

wild_pokemon_habitat wild_pokemon_3_5_rod = {
	.frequency = 10, .data = wild_pokemon_3_5_rod_entries
};

wild_pokemon_data wild_pokemon_3_5 = {
	.bank = 3, .map = 5,
	.grass = NULL,
	.water = &wild_pokemon_3_5_water,
	.other = NULL,
	.rod = &wild_pokemon_3_5_rod,
};
