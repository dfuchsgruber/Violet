#include "types.h"
#include "map/wild_pokemon.h"
#include "constants/wild_pokemon_densities.h"
#include "constants/species.h"

wild_pokemon_entry wild_pokemon_route_4_cloud_cave_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 34, .level_max = 36, .species = POKEMON_KLEINSTEIN},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 34, .level_max = 36, .species = POKEMON_ZUBAT},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 34, .level_max = 36, .species = POKEMON_ONIX},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 34, .level_max = 36, .species = POKEMON_GEOROK},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 34, .level_max = 36, .species = POKEMON_ZUBAT},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 34, .level_max = 36, .species = POKEMON_ONIX},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 34, .level_max = 36, .species = POKEMON_GEOROK},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 34, .level_max = 37, .species = POKEMON_GOLBAT},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 35, .level_max = 37, .species = POKEMON_GOLBAT},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 35, .level_max = 27, .species = POKEMON_NASGNET},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 35, .level_max = 37, .species = POKEMON_NASGNET},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 35, .level_max = 37, .species = POKEMON_NASGNET},
};

wild_pokemon_habitat wild_pokemon_route_4_cloud_cave_grass = {
	.frequency = 2, .data = wild_pokemon_route_4_cloud_cave_grass_entries
};