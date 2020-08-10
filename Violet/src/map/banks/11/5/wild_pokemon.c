#include "types.h"
#include "map/wild_pokemon.h"
#include "constants/wild_pokemon_densities.h"
#include "constants/species.h"


wild_pokemon_entry wild_pokemon_route_2_cave_water_entries[5] = {
	[WILD_POKEMON_DENSITY_WATER_0_60_PERCENT] = 
		{.level_min = 20, .level_max = 25, .species = POKEMON_KRABBY},
	[WILD_POKEMON_DENSITY_WATER_1_30_PERCENT] = 
		{.level_min = 20, .level_max = 25, .species = POKEMON_MARILL},
	[WILD_POKEMON_DENSITY_WATER_2_5_PERCENT] = 
		{.level_min = 25, .level_max = 30, .species = POKEMON_ZUBAT},
	[WILD_POKEMON_DENSITY_WATER_3_4_PERCENT] = 
		{.level_min = 30, .level_max = 35, .species = POKEMON_GOLBAT},
	[WILD_POKEMON_DENSITY_WATER_3_1_PERCENT] = 
		{.level_min = 30, .level_max = 35, .species = POKEMON_KINGLER},
};

wild_pokemon_habitat wild_pokemon_route_2_cave_water = {
	.frequency = 7, .data = wild_pokemon_route_2_cave_water_entries
};

wild_pokemon_entry wild_pokemon_route_2_cave_rod_entries[10] = {
	[WILD_POKEMON_DENSITY_OLD_ROD_0_70_PERCENT] = 
		{.level_min = 9, .level_max = 11, .species = POKEMON_KRABBY},
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
		{.level_min = 45, .level_max = 50, .species = POKEMON_KINGLER},
	[WILD_POKEMON_DENSITY_SUPER_ROD_4_1_PERCENT] = 
		{.level_min = 45, .level_max = 55, .species = POKEMON_KINGLER},
};

wild_pokemon_habitat wild_pokemon_route_2_cave_rod = {
	.frequency = 49, .data = wild_pokemon_route_2_cave_rod_entries
};
