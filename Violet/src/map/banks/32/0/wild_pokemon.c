#include "types.h"
#include "map/wild_pokemon.h"
#include "constants/wild_pokemon_densities.h"
#include "constants/species.h"

static wild_pokemon_entry wild_pokemon_dark_tower_grass[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 34, .level_max = 36, .species = POKEMON_KRAMURX},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 34, .level_max = 36, .species = POKEMON_TRAUNFUGIL},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 34, .level_max = 36, .species = POKEMON_ZWIRRLICHT},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 34, .level_max = 36, .species = POKEMON_SHUPPET},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 34, .level_max = 37, .species = POKEMON_NEBULAK},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 34, .level_max = 37, .species = POKEMON_TRAUNFUGIL},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 35, .level_max = 37, .species = POKEMON_ZWIRRLICHT},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 35, .level_max = 37, .species = POKEMON_NEBULAK},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 36, .level_max = 37, .species = POKEMON_ALPOLLO},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 36, .level_max = 37, .species = POKEMON_KRAMURX},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 38, .level_max = 38, .species = POKEMON_BANETTE},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 38, .level_max = 38, .species = POKEMON_BANETTE},
};

wild_pokemon_habitat wild_pokemon_dark_tower = {
	.frequency = 2, .data = wild_pokemon_dark_tower_grass
};