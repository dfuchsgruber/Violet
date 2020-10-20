#include "types.h"
#include "map/wild_pokemon.h"
#include "constants/wild_pokemon_densities.h"
#include "constants/species.h"

wild_pokemon_entry wild_pokemon_route_12_east_grass_entries[12] = {
  [WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] =
    {.level_min = 34, .level_max = 38, .species = POKEMON_NEBULAK},
  [WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] =
    {.level_min = 34, .level_max = 36, .species = POKEMON_WINGULL},
  [WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] =
    {.level_min = 34, .level_max = 36, .species = POKEMON_ZWIRRLICHT},
  [WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] =
    {.level_min = 34, .level_max = 38, .species = POKEMON_SHUPPET},
  [WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] =
    {.level_min = 34, .level_max = 38, .species = POKEMON_NEBULAK},
  [WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] =
    {.level_min = 34, .level_max = 38, .species = POKEMON_WINGULL},
  [WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] =
    {.level_min = 34, .level_max = 38, .species = POKEMON_FIFFYEN},
  [WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] =
    {.level_min = 34, .level_max = 38, .species = POKEMON_FIFFYEN},
  [WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] =
    {.level_min = 37, .level_max = 39, .species = POKEMON_ALPOLLO},
  [WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] =
    {.level_min = 37, .level_max = 40, .species = POKEMON_MAGNAYEN},
  [WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] =
    {.level_min = 38, .level_max = 40, .species = POKEMON_SHUPPET},
  [WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] =
    {.level_min = 39, .level_max = 41, .species = POKEMON_PELIPPER},
};

wild_pokemon_habitat wild_pokemon_route_12_east_grass = {
  .frequency = 30, .data = wild_pokemon_route_12_east_grass_entries
};

wild_pokemon_entry wild_pokemon_route_12_east_other_entries[5] = {
  [WILD_POKEMON_DENSITY_OTHER_0_30_PERCENT] =
    {.level_min = 35, .level_max = 40, .species = POKEMON_FIFFYEN},
  [WILD_POKEMON_DENSITY_OTHER_1_25_PERCENT] =
    {.level_min = 35, .level_max = 41, .species = POKEMON_TRAUMATO},
  [WILD_POKEMON_DENSITY_OTHER_2_20_PERCENT] =
    {.level_min = 35, .level_max = 40, .species = POKEMON_KRAMURX},
  [WILD_POKEMON_DENSITY_OTHER_3_15_PERCENT] =
    {.level_min = 35, .level_max = 42, .species = POKEMON_KRAMURX},
  [WILD_POKEMON_DENSITY_OTHER_4_10_PERCENT] =
    {.level_min = 38, .level_max = 42, .species = POKEMON_KINGLER},
};

wild_pokemon_habitat wild_pokemon_route_12_east_other = {
  .frequency = 128, .data = wild_pokemon_route_12_east_other_entries
};

wild_pokemon_entry wild_pokemon_route_12_east_water_entries[5] = {
	[WILD_POKEMON_DENSITY_WATER_0_60_PERCENT] = 
		{.level_min = 37, .level_max = 41, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_WATER_1_30_PERCENT] = 
		{.level_min = 37, .level_max = 41, .species = POKEMON_NEBULAK},
	[WILD_POKEMON_DENSITY_WATER_2_5_PERCENT] = 
		{.level_min = 36, .level_max = 40, .species = POKEMON_QUABBEL},
	[WILD_POKEMON_DENSITY_WATER_3_4_PERCENT] = 
		{.level_min = 38, .level_max = 41, .species = POKEMON_WAILMER},
	[WILD_POKEMON_DENSITY_WATER_3_1_PERCENT] = 
		{.level_min = 39, .level_max = 42, .species = POKEMON_WAILMER},
};


wild_pokemon_habitat wild_pokemon_route_12_east_water = {
	.frequency = 4, .data = wild_pokemon_route_12_east_water_entries
};

wild_pokemon_entry wild_pokemon_route_12_east_rod_entries[10] = {
	[WILD_POKEMON_DENSITY_OLD_ROD_0_70_PERCENT] = 
		{.level_min = 34, .level_max = 38, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_OLD_ROD_1_30_PERCENT] = 
		{.level_min = 33, .level_max = 39, .species = POKEMON_QUABBEL},
	[WILD_POKEMON_DENSITY_GOOD_ROD_0_60_PERCENT] = 
		{.level_min = 34, .level_max = 39, .species = POKEMON_WAILMER},
	[WILD_POKEMON_DENSITY_GOOD_ROD_1_20_PERCENT] = 
		{.level_min = 34, .level_max = 38, .species = POKEMON_STERNDU},
	[WILD_POKEMON_DENSITY_GOOD_ROD_2_20_PERCENT] = 
		{.level_min = 34, .level_max = 39, .species = POKEMON_KANIVANHA},
	[WILD_POKEMON_DENSITY_SUPER_ROD_0_40_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_SUPER_ROD_1_40_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_KANIVANHA},
	[WILD_POKEMON_DENSITY_SUPER_ROD_2_15_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_TENTOXA},
	[WILD_POKEMON_DENSITY_SUPER_ROD_3_4_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_TOHAIDO},
	[WILD_POKEMON_DENSITY_SUPER_ROD_4_1_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_TOHAIDO},
};

wild_pokemon_habitat wild_pokemon_route_12_east_rod = {
	.frequency = 75, .data = wild_pokemon_route_12_east_rod_entries
};
