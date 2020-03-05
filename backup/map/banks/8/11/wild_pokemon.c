#include "types.h"
#include "map/wild_pokemon.h"
#include "constants/wild_pokemon_densities.h"
#include "constants/species.h"

wild_pokemon_entry wild_pokemon_8_11_water_entries[5] = {
	[WILD_POKEMON_DENSITY_WATER_0_60_PERCENT] = 
		{.level_min = 26, .level_max = 32, .species = POKEMON_QUABBEL},
	[WILD_POKEMON_DENSITY_WATER_1_30_PERCENT] = 
		{.level_min = 26, .level_max = 30, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_WATER_2_5_PERCENT] = 
		{.level_min = 26, .level_max = 29, .species = POKEMON_KRABBY},
	[WILD_POKEMON_DENSITY_WATER_3_4_PERCENT] = 
		{.level_min = 27, .level_max = 33, .species = POKEMON_KRABBY},
	[WILD_POKEMON_DENSITY_WATER_3_1_PERCENT] = 
		{.level_min = 30, .level_max = 34, .species = POKEMON_KRABBY},
};

wild_pokemon_habitat wild_pokemon_8_11_water = {
	.frequency = 13, .data = wild_pokemon_8_11_water_entries
};

wild_pokemon_entry wild_pokemon_8_11_rod_entries[10] = {
	[WILD_POKEMON_DENSITY_OLD_ROD_0_70_PERCENT] = 
		{.level_min = 21, .level_max = 24, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_OLD_ROD_1_30_PERCENT] = 
		{.level_min = 21, .level_max = 24, .species = POKEMON_QUABBEL},
	[WILD_POKEMON_DENSITY_GOOD_ROD_0_60_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_KRABBY},
	[WILD_POKEMON_DENSITY_GOOD_ROD_1_20_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_GOOD_ROD_2_20_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_KRABBY},
	[WILD_POKEMON_DENSITY_SUPER_ROD_0_40_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_QUABBEL},
	[WILD_POKEMON_DENSITY_SUPER_ROD_1_40_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_KRABBY},
	[WILD_POKEMON_DENSITY_SUPER_ROD_2_15_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_QUABBEL},
	[WILD_POKEMON_DENSITY_SUPER_ROD_3_4_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_KINGLER},
	[WILD_POKEMON_DENSITY_SUPER_ROD_4_1_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_GARADOS},
};

wild_pokemon_habitat wild_pokemon_8_11_rod = {
	.frequency = 75, .data = wild_pokemon_8_11_rod_entries
};
