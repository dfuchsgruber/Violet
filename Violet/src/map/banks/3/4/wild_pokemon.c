#include "types.h"
#include "map/wild_pokemon.h"
#include "constants/wild_pokemon_densities.h"
#include "constants/species.h"

wild_pokemon_entry wild_pokemon_3_4_water_entries[5] = {
	[WILD_POKEMON_DENSITY_WATER_0_60_PERCENT] = 
		{.level_min = 30, .level_max = 30, .species = POKEMON_MARILL},
	[WILD_POKEMON_DENSITY_WATER_1_30_PERCENT] = 
		{.level_min = 30, .level_max = 30, .species = POKEMON_KANIVANHA},
	[WILD_POKEMON_DENSITY_WATER_2_5_PERCENT] = 
		{.level_min = 30, .level_max = 30, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_WATER_3_4_PERCENT] = 
		{.level_min = 35, .level_max = 35, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_WATER_3_1_PERCENT] = 
		{.level_min = 35, .level_max = 40, .species = POKEMON_TENTACHA},
};

wild_pokemon_habitat wild_pokemon_3_4_water = {
	.frequency = 13, .data = wild_pokemon_3_4_water_entries
};

wild_pokemon_data wild_pokemon_3_4 = {
	.bank = 3, .map = 4,
	.grass = NULL,
	.water = &wild_pokemon_3_4_water,
	.other = NULL,
	.rod = NULL,
};
