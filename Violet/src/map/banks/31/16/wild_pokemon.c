#include "types.h"
#include "map/wild_pokemon.h"
#include "constants/wild_pokemon_densities.h"
#include "constants/species.h"

wild_pokemon_entry wild_pokemon_ardeal_dungeon_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 33, .level_max = 36, .species = POKEMON_ZUBAT},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 33, .level_max = 36, .species = POKEMON_BRONZEL},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 33, .level_max = 36, .species = POKEMON_LICHTEL},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 33, .level_max = 36, .species = POKEMON_ZUBAT},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 34, .level_max = 37, .species = POKEMON_BRONZEL},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 34, .level_max = 37, .species = POKEMON_LICHTEL},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 35, .level_max = 37, .species = POKEMON_ZUBAT},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 35, .level_max = 37, .species = POKEMON_GOLBAT},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 35, .level_max = 38, .species = POKEMON_LATERNECTO},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 35, .level_max = 38, .species = POKEMON_GOLBAT},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 36, .level_max = 38, .species = POKEMON_ZOBIRIS},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 36, .level_max = 39, .species = POKEMON_BRONZONG},
};

wild_pokemon_habitat wild_pokemon_ardeal_dungeon_grass = {
	.frequency = 2, .data = wild_pokemon_ardeal_dungeon_grass_entries
};
