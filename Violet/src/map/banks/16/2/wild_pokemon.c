#include "types.h"
#include "map/wild_pokemon.h"
#include "constants/wild_pokemon_densities.h"
#include "constants/species.h"

wild_pokemon_entry wild_pokemon_route_4_south_cave_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 24, .level_max = 24, .species = POKEMON_MARILL},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 24, .level_max = 25, .species = POKEMON_KRABBY},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 24, .level_max = 25, .species = POKEMON_ZUBAT},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 24, .level_max = 26, .species = POKEMON_MACHOLLO},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 25, .level_max = 27, .species = POKEMON_MEDITIE},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 25, .level_max = 27, .species = POKEMON_ZUBAT},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 25, .level_max = 27, .species = POKEMON_MENKI},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 25, .level_max = 27, .species = POKEMON_KRABBY},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 26, .level_max = 28, .species = POKEMON_ZUBAT},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 26, .level_max = 29, .species = POKEMON_MARILL},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 27, .level_max = 30, .species = POKEMON_GOLBAT},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 29, .level_max = 31, .species = POKEMON_MASCHOCK},
};

wild_pokemon_habitat wild_pokemon_route_4_south_cave_grass = {
	.frequency = 1, .data = wild_pokemon_route_4_south_cave_grass_entries
};