#include "types.h"
#include "map/wild_pokemon.h"
#include "constants/wild_pokemon_densities.h"
#include "constants/species.h"

wild_pokemon_entry wild_pokemon_3_70_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 5, .level_max = 7, .species = POKEMON_KLEINSTEIN},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 5, .level_max = 7, .species = POKEMON_SANDAN},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 5, .level_max = 7, .species = POKEMON_KLEINSTEIN},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 5, .level_max = 7, .species = POKEMON_SANDAN},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 5, .level_max = 7, .species = POKEMON_ONIX},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 5, .level_max = 7, .species = POKEMON_ONIX},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 5, .level_max = 8, .species = POKEMON_KLEINSTEIN},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 5, .level_max = 8, .species = POKEMON_SANDAN},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 5, .level_max = 8, .species = POKEMON_KLEINSTEIN},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 6, .level_max = 8, .species = POKEMON_ONIX},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 6, .level_max = 8, .species = POKEMON_BRONZEL},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 7, .level_max = 8, .species = POKEMON_BRONZEL},
};

wild_pokemon_habitat wild_pokemon_3_70_grass = {
	.frequency = 9, .data = wild_pokemon_3_70_grass_entries
};

wild_pokemon_data wild_pokemon_3_70 = {
	.bank = 3, .map = 70,
	.grass = &wild_pokemon_3_70_grass,
	.water = NULL,
	.other = NULL,
	.rod = NULL,
};
