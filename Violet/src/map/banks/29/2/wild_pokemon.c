#include "types.h"
#include "map/wild_pokemon.h"
#include "constants/wild_pokemon_densities.h"
#include "constants/species.h"

wild_pokemon_entry wild_pokemon_route_7_castle_grass_entries[12] = {
  [WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] =
    {.level_min = 32, .level_max = 36, .species = POKEMON_TRASLA},
  [WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] =
    {.level_min = 33, .level_max = 35, .species = POKEMON_BRONZEL},
  [WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] =
    {.level_min = 33, .level_max = 35, .species = POKEMON_SAMURZEL},
  [WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] =
    {.level_min = 33, .level_max = 36, .species = POKEMON_ENTON},
  [WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] =
    {.level_min = 34, .level_max = 37, .species = POKEMON_KIRLIA},
  [WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] =
    {.level_min = 34, .level_max = 36, .species = POKEMON_KNOFENSA},
  [WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] =
    {.level_min = 34, .level_max = 35, .species = POKEMON_BLANAS},
  [WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] =
    {.level_min = 34, .level_max = 36, .species = POKEMON_KNOFENSA},
  [WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] =
    {.level_min = 35, .level_max = 36, .species = POKEMON_ULTRIGARIA},
  [WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] =
    {.level_min = 35, .level_max = 37, .species = POKEMON_KIRLIA},
  [WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] =
    {.level_min = 37, .level_max = 38, .species = POKEMON_ENTORON},
  [WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] =
    {.level_min = 37, .level_max = 38, .species = POKEMON_BLANAS},
};

wild_pokemon_habitat wild_pokemon_route_7_castle_grass = {
  .frequency = 30, .data = wild_pokemon_route_7_castle_grass_entries
};

wild_pokemon_entry wild_pokemon_route_7_castle_other_entries[5] = {
  [WILD_POKEMON_DENSITY_OTHER_0_30_PERCENT] =
    {.level_min = 35, .level_max = 40, .species = POKEMON_GRANBULL},
  [WILD_POKEMON_DENSITY_OTHER_1_25_PERCENT] =
    {.level_min = 35, .level_max = 41, .species = POKEMON_ENTORON},
  [WILD_POKEMON_DENSITY_OTHER_2_20_PERCENT] =
    {.level_min = 35, .level_max = 40, .species = POKEMON_TENGULIST},
  [WILD_POKEMON_DENSITY_OTHER_3_15_PERCENT] =
    {.level_min = 35, .level_max = 42, .species = POKEMON_GUARDEVOIR},
  [WILD_POKEMON_DENSITY_OTHER_4_10_PERCENT] =
    {.level_min = 38, .level_max = 42, .species = POKEMON_SARZENIA},
};

wild_pokemon_habitat wild_pokemon_route_7_castle_other = {
  .frequency = 128, .data = wild_pokemon_route_7_castle_other_entries
};


wild_pokemon_entry wild_pokemon_route_7_castle_water_entries[5] = {
	[WILD_POKEMON_DENSITY_WATER_0_60_PERCENT] = 
		{.level_min = 34, .level_max = 37, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_WATER_1_30_PERCENT] = 
		{.level_min = 34, .level_max = 37, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_WATER_2_5_PERCENT] = 
		{.level_min = 34, .level_max = 38, .species = POKEMON_QUABBEL},
	[WILD_POKEMON_DENSITY_WATER_3_4_PERCENT] = 
		{.level_min = 35, .level_max = 38, .species = POKEMON_WAILMER},
	[WILD_POKEMON_DENSITY_WATER_3_1_PERCENT] = 
		{.level_min = 36, .level_max = 39, .species = POKEMON_TENTOXA},
};


wild_pokemon_habitat wild_pokemon_route_7_castle_water = {
	.frequency = 4, .data = wild_pokemon_route_7_castle_water_entries
};

wild_pokemon_entry wild_pokemon_route_7_castle_rod_entries[10] = {
	[WILD_POKEMON_DENSITY_OLD_ROD_0_70_PERCENT] = 
		{.level_min = 34, .level_max = 38, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_OLD_ROD_1_30_PERCENT] = 
		{.level_min = 33, .level_max = 39, .species = POKEMON_QUABBEL},
	[WILD_POKEMON_DENSITY_GOOD_ROD_0_60_PERCENT] = 
		{.level_min = 34, .level_max = 39, .species = POKEMON_WAILMER},
	[WILD_POKEMON_DENSITY_GOOD_ROD_1_20_PERCENT] = 
		{.level_min = 34, .level_max = 38, .species = POKEMON_STERNDU},
	[WILD_POKEMON_DENSITY_GOOD_ROD_2_20_PERCENT] = 
		{.level_min = 34, .level_max = 39, .species = POKEMON_KRABBY},
	[WILD_POKEMON_DENSITY_SUPER_ROD_0_40_PERCENT] = 
		{.level_min = 53, .level_max = 55, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_SUPER_ROD_1_40_PERCENT] = 
		{.level_min = 54, .level_max = 56, .species = POKEMON_QUABBEL},
	[WILD_POKEMON_DENSITY_SUPER_ROD_2_15_PERCENT] = 
		{.level_min = 51, .level_max = 56, .species = POKEMON_TENTOXA},
	[WILD_POKEMON_DENSITY_SUPER_ROD_3_4_PERCENT] = 
		{.level_min = 51, .level_max = 57, .species = POKEMON_KINGLER},
	[WILD_POKEMON_DENSITY_SUPER_ROD_4_1_PERCENT] = 
		{.level_min = 55, .level_max = 59, .species = POKEMON_KINGLER},
};

wild_pokemon_habitat wild_pokemon_route_7_castle_rod = {
	.frequency = 75, .data = wild_pokemon_route_7_castle_rod_entries
};
