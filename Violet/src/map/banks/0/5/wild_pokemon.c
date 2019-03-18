#include "types.h"
#include "map/wild_pokemon.h"
#include "constants/wild_pokemon_densities.h"
#include "constants/species.h"

wild_pokemon_entry wild_pokemon_0_5_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 15, .level_max = 18, .species = POKEMON_KLEINSTEIN},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 15, .level_max = 18, .species = POKEMON_ZUBAT},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 15, .level_max = 18, .species = POKEMON_MACHOLLO},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 15, .level_max = 18, .species = POKEMON_SANDAN},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 15, .level_max = 18, .species = POKEMON_KLEINSTEIN},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 15, .level_max = 18, .species = POKEMON_MACHOLLO},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 15, .level_max = 18, .species = POKEMON_ZUBAT},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 16, .level_max = 19, .species = POKEMON_SANDAN},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 16, .level_max = 19, .species = POKEMON_KLEINSTEIN},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 16, .level_max = 19, .species = POKEMON_ZUBAT},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 17, .level_max = 20, .species = POKEMON_MACHOLLO},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 22, .level_max = 22, .species = POKEMON_SANDAN},
};

wild_pokemon_habitat wild_pokemon_0_5_grass = {
	.frequency = 2, .data = wild_pokemon_0_5_grass_entries
};

wild_pokemon_data wild_pokemon_0_5 = {
	.bank = 0, .map = 5,
	.grass = &wild_pokemon_0_5_grass,
	.water = NULL,
	.other = NULL,
	.rod = NULL,
};
