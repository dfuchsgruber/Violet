#include "types.h"
#include "map/wild_pokemon.h"
#include "constants/wild_pokemon_densities.h"
#include "constants/species.h"

wild_pokemon_entry wild_pokemon_1_59_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 22, .level_max = 25, .species = POKEMON_SPOINK},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 22, .level_max = 25, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 22, .level_max = 25, .species = POKEMON_SPOINK},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 22, .level_max = 25, .species = POKEMON_FLABEBE},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 22, .level_max = 25, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 22, .level_max = 25, .species = POKEMON_SPOINK},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 22, .level_max = 25, .species = POKEMON_FLABEBE},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 22, .level_max = 25, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 23, .level_max = 26, .species = POKEMON_SPOINK},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 23, .level_max = 26, .species = POKEMON_FLABEBE},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 23, .level_max = 26, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 28, .level_max = 32, .species = POKEMON_PELIPPER},
};

wild_pokemon_habitat wild_pokemon_1_59_grass = {
	.frequency = 7, .data = wild_pokemon_1_59_grass_entries
};

wild_pokemon_entry wild_pokemon_1_59_water_entries[5] = {
	[WILD_POKEMON_DENSITY_WATER_0_60_PERCENT] = 
		{.level_min = 32, .level_max = 32, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_WATER_1_30_PERCENT] = 
		{.level_min = 32, .level_max = 34, .species = POKEMON_QUABBEL},
	[WILD_POKEMON_DENSITY_WATER_2_5_PERCENT] = 
		{.level_min = 32, .level_max = 34, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_WATER_3_4_PERCENT] = 
		{.level_min = 33, .level_max = 35, .species = POKEMON_KRABBY},
	[WILD_POKEMON_DENSITY_WATER_3_1_PERCENT] = 
		{.level_min = 34, .level_max = 35, .species = POKEMON_WAILMER},
};

wild_pokemon_habitat wild_pokemon_1_59_water = {
	.frequency = 0, .data = wild_pokemon_1_59_water_entries
};

wild_pokemon_entry wild_pokemon_1_59_rod_entries[10] = {
	[WILD_POKEMON_DENSITY_OLD_ROD_0_70_PERCENT] = 
		{.level_min = 23, .level_max = 25, .species = POKEMON_QUABBEL},
	[WILD_POKEMON_DENSITY_OLD_ROD_1_30_PERCENT] = 
		{.level_min = 23, .level_max = 25, .species = POKEMON_QUABBEL},
	[WILD_POKEMON_DENSITY_GOOD_ROD_0_60_PERCENT] = 
		{.level_min = 23, .level_max = 25, .species = POKEMON_REMORAID},
	[WILD_POKEMON_DENSITY_GOOD_ROD_1_20_PERCENT] = 
		{.level_min = 23, .level_max = 25, .species = POKEMON_REMORAID},
	[WILD_POKEMON_DENSITY_GOOD_ROD_2_20_PERCENT] = 
		{.level_min = 23, .level_max = 25, .species = POKEMON_KARPADOR},
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

wild_pokemon_habitat wild_pokemon_1_59_rod = {
	.frequency = 25, .data = wild_pokemon_1_59_rod_entries
};
