#include "types.h"
#include "map/wild_pokemon.h"
#include "constants/wild_pokemon_densities.h"
#include "constants/species.h"

wild_pokemon_entry wild_pokemon_tafelberg_south_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 21, .level_max = 23, .species = POKEMON_DIGDA},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 21, .level_max = 23, .species = POKEMON_MENKI},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 21, .level_max = 22, .species = POKEMON_MACHOLLO},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 22, .level_max = 23, .species = POKEMON_KLEINSTEIN},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 21, .level_max = 23, .species = POKEMON_MEDITIE},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 22, .level_max = 24, .species = POKEMON_MACHOLLO},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 21, .level_max = 25, .species = POKEMON_MENKI},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 20, .level_max = 25, .species = POKEMON_KLEINSTEIN},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 24, .level_max = 24, .species = POKEMON_MEDITIE},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 24, .level_max = 24, .species = POKEMON_KLEINSTEIN},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 28, .level_max = 28, .species = POKEMON_MASCHOCK},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 28, .level_max = 28, .species = POKEMON_MASCHOCK},
};

wild_pokemon_habitat wild_pokemon_tafelberg_south_grass = {
	.frequency = 3, .data = wild_pokemon_tafelberg_south_grass_entries
};


wild_pokemon_entry wild_pokemon_tafelberg_south_other_entries[5] = {
	[WILD_POKEMON_DENSITY_OTHER_0_30_PERCENT] = 
		{.level_min = 24, .level_max = 26, .species = POKEMON_LEDYBA},
	[WILD_POKEMON_DENSITY_OTHER_1_25_PERCENT] = 
		{.level_min = 25, .level_max = 26, .species = POKEMON_MAEHIKEL},
	[WILD_POKEMON_DENSITY_OTHER_2_20_PERCENT] = 
		{.level_min = 25, .level_max = 26, .species = POKEMON_SANDAN},
	[WILD_POKEMON_DENSITY_OTHER_3_15_PERCENT] = 
		{.level_min = 25, .level_max = 25, .species = POKEMON_FLOETTE},
	[WILD_POKEMON_DENSITY_OTHER_4_10_PERCENT] = 
		{.level_min = 28, .level_max = 28, .species = POKEMON_FLOETTE},
};

wild_pokemon_habitat wild_pokemon_tafelberg_south_other = {
	.frequency = 180, .data = wild_pokemon_tafelberg_south_other_entries
};


wild_pokemon_entry wild_pokemon_tafelberg_south_water_entries[5] = {
	[WILD_POKEMON_DENSITY_WATER_0_60_PERCENT] = 
		{.level_min = 35, .level_max = 35, .species = POKEMON_FLEGMON},
	[WILD_POKEMON_DENSITY_WATER_1_30_PERCENT] = 
		{.level_min = 35, .level_max = 35, .species = POKEMON_KRABBY},
	[WILD_POKEMON_DENSITY_WATER_2_5_PERCENT] = 
		{.level_min = 35, .level_max = 35, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_WATER_3_4_PERCENT] = 
		{.level_min = 35, .level_max = 35, .species = POKEMON_FLEGMON},
	[WILD_POKEMON_DENSITY_WATER_3_1_PERCENT] = 
		{.level_min = 37, .level_max = 38, .species = POKEMON_KINGLER},
};

wild_pokemon_habitat wild_pokemon_tafelberg_south_water = {
	.frequency = 15, .data = wild_pokemon_tafelberg_south_water_entries
};

wild_pokemon_entry wild_pokemon_tafelberg_south_rod_entries[10] = {
	[WILD_POKEMON_DENSITY_OLD_ROD_0_70_PERCENT] = 
		{.level_min = 20, .level_max = 20, .species = POKEMON_SCHMERBE},
	[WILD_POKEMON_DENSITY_OLD_ROD_1_30_PERCENT] = 
		{.level_min = 20, .level_max = 20, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_GOOD_ROD_0_60_PERCENT] = 
		{.level_min = 40, .level_max = 40, .species = POKEMON_KRABBY},
	[WILD_POKEMON_DENSITY_GOOD_ROD_1_20_PERCENT] = 
		{.level_min = 40, .level_max = 40, .species = POKEMON_SCHMERBE},
	[WILD_POKEMON_DENSITY_GOOD_ROD_2_20_PERCENT] = 
		{.level_min = 40, .level_max = 40, .species = POKEMON_FLEGMON},
	[WILD_POKEMON_DENSITY_SUPER_ROD_0_40_PERCENT] = 
		{.level_min = 40, .level_max = 40, .species = POKEMON_FLEGMON},
	[WILD_POKEMON_DENSITY_SUPER_ROD_1_40_PERCENT] = 
		{.level_min = 40, .level_max = 40, .species = POKEMON_KRABBY},
	[WILD_POKEMON_DENSITY_SUPER_ROD_2_15_PERCENT] = 
		{.level_min = 50, .level_max = 50, .species = POKEMON_KINGLER},
	[WILD_POKEMON_DENSITY_SUPER_ROD_3_4_PERCENT] = 
		{.level_min = 50, .level_max = 50, .species = POKEMON_GARADOS},
	[WILD_POKEMON_DENSITY_SUPER_ROD_4_1_PERCENT] = 
		{.level_min = 50, .level_max = 50, .species = POKEMON_WELSAR},
};

wild_pokemon_habitat wild_pokemon_tafelberg_south_rod = {
	.frequency = 6, .data = wild_pokemon_tafelberg_south_rod_entries
};
