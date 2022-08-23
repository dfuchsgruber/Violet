#ifndef H_DATA_WILD_POKEMON
#define H_DATA_WILD_POKEMON

#include "types.h"
#include "constants/species.h"
#include "constants/wild_pokemon_densities.h"
#include "map/wild_pokemon.h"

static wild_pokemon_entry wild_pokemon_0_12_grass_entries[12] = {
    [WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 26, .level_max = 30, .species = POKEMON_CAMAUB},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 26, .level_max = 30, .species = POKEMON_SCHNECKMAG},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 26, .level_max = 30, .species = POKEMON_KLEINSTEIN},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 27, .level_max = 31, .species = POKEMON_CAMAUB},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 27, .level_max = 31, .species = POKEMON_SCHNECKMAG},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 27, .level_max = 31, .species = POKEMON_KLEINSTEIN},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 27, .level_max = 32, .species = POKEMON_CAMAUB},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 28, .level_max = 32, .species = POKEMON_SCHNECKMAG},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 29, .level_max = 33, .species = POKEMON_GEOROK},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 29, .level_max = 33, .species = POKEMON_CAMAUB},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 30, .level_max = 33, .species = POKEMON_SCHNECKMAG},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 33, .level_max = 34, .species = POKEMON_GEOROK},
};

static wild_pokemon_habitat wild_pokemon_0_12_grass = {
	.frequency = 28, .data = wild_pokemon_0_12_grass_entries
};

static wild_pokemon_entry wild_pokemon_0_5_grass_entries[12] = {
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

static wild_pokemon_habitat wild_pokemon_0_5_grass = {
	.frequency = 2, .data = wild_pokemon_0_5_grass_entries
};

static wild_pokemon_entry wild_pokemon_0_6_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 16, .level_max = 19, .species = POKEMON_ZUBAT},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 16, .level_max = 20, .species = POKEMON_NASGNET},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 16, .level_max = 20, .species = POKEMON_KLEINSTEIN},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 16, .level_max = 20, .species = POKEMON_SANDAN},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 16, .level_max = 20, .species = POKEMON_ZUBAT},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 16, .level_max = 20, .species = POKEMON_NASGNET},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 16, .level_max = 20, .species = POKEMON_KLEINSTEIN},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 16, .level_max = 20, .species = POKEMON_SANDAN},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 17, .level_max = 20, .species = POKEMON_ZUBAT},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 17, .level_max = 20, .species = POKEMON_NASGNET},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 17, .level_max = 20, .species = POKEMON_KLEINSTEIN},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 18, .level_max = 21, .species = POKEMON_STOLLUNIOR},
};

static wild_pokemon_habitat wild_pokemon_0_6_grass = {
	.frequency = 4, .data = wild_pokemon_0_6_grass_entries
};

static wild_pokemon_entry wild_pokemon_0_7_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 22, .level_max = 24, .species = POKEMON_MARILL},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 22, .level_max = 24, .species = POKEMON_KRABBY},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 22, .level_max = 25, .species = POKEMON_ZUBAT},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 23, .level_max = 24, .species = POKEMON_FLEGMON},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 23, .level_max = 25, .species = POKEMON_KRABBY},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 23, .level_max = 24, .species = POKEMON_ZUBAT},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 24, .level_max = 26, .species = POKEMON_FLEGMON},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 23, .level_max = 26, .species = POKEMON_KRABBY},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 24, .level_max = 25, .species = POKEMON_ZUBAT},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 24, .level_max = 27, .species = POKEMON_MARILL},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 25, .level_max = 28, .species = POKEMON_KRABBY},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 27, .level_max = 29, .species = POKEMON_AZUMARILL},
};

static wild_pokemon_habitat wild_pokemon_0_7_grass = {
	.frequency = 1, .data = wild_pokemon_0_7_grass_entries
};

static wild_pokemon_entry wild_pokemon_0_7_water_entries[5] = {
	[WILD_POKEMON_DENSITY_WATER_0_60_PERCENT] = 
		{.level_min = 25, .level_max = 32, .species = POKEMON_KRABBY},
	[WILD_POKEMON_DENSITY_WATER_1_30_PERCENT] = 
		{.level_min = 25, .level_max = 32, .species = POKEMON_KREBSCORPS},
	[WILD_POKEMON_DENSITY_WATER_2_5_PERCENT] = 
		{.level_min = 27, .level_max = 33, .species = POKEMON_KRABBY},
	[WILD_POKEMON_DENSITY_WATER_3_4_PERCENT] = 
		{.level_min = 25, .level_max = 34, .species = POKEMON_KINGLER},
	[WILD_POKEMON_DENSITY_WATER_3_1_PERCENT] = 
		{.level_min = 30, .level_max = 35, .species = POKEMON_KINGLER},
};

static wild_pokemon_habitat wild_pokemon_0_7_water = {
	.frequency = 10, .data = wild_pokemon_0_7_water_entries
};

static wild_pokemon_entry wild_pokemon_0_7_rod_entries[10] = {
	[WILD_POKEMON_DENSITY_OLD_ROD_0_70_PERCENT] = 
		{.level_min = 20, .level_max = 22, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_OLD_ROD_1_30_PERCENT] = 
		{.level_min = 20, .level_max = 22, .species = POKEMON_KRABBY},
	[WILD_POKEMON_DENSITY_GOOD_ROD_0_60_PERCENT] = 
		{.level_min = 20, .level_max = 22, .species = POKEMON_FLEGMON},
	[WILD_POKEMON_DENSITY_GOOD_ROD_1_20_PERCENT] = 
		{.level_min = 20, .level_max = 22, .species = POKEMON_KRABBY},
	[WILD_POKEMON_DENSITY_GOOD_ROD_2_20_PERCENT] = 
		{.level_min = 20, .level_max = 22, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_0_40_PERCENT] = 
		{.level_min = 20, .level_max = 22, .species = POKEMON_KRABBY},
	[WILD_POKEMON_DENSITY_SUPER_ROD_1_40_PERCENT] = 
		{.level_min = 20, .level_max = 24, .species = POKEMON_FLEGMON},
	[WILD_POKEMON_DENSITY_SUPER_ROD_2_15_PERCENT] = 
		{.level_min = 20, .level_max = 24, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_3_4_PERCENT] = 
		{.level_min = 20, .level_max = 24, .species = POKEMON_KINGLER},
	[WILD_POKEMON_DENSITY_SUPER_ROD_4_1_PERCENT] = 
		{.level_min = 25, .level_max = 25, .species = POKEMON_KINGLER},
};

static wild_pokemon_habitat wild_pokemon_0_7_rod = {
	.frequency = 30, .data = wild_pokemon_0_7_rod_entries
};

static wild_pokemon_entry wild_pokemon_1_0_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 16, .level_max = 20, .species = POKEMON_SAMURZEL},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 16, .level_max = 20, .species = POKEMON_KNILZ},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 16, .level_max = 20, .species = POKEMON_WAUMPEL},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 16, .level_max = 20, .species = POKEMON_MYRAPLA},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 16, .level_max = 20, .species = POKEMON_SAMURZEL},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 16, .level_max = 20, .species = POKEMON_KNILZ},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 16, .level_max = 20, .species = POKEMON_SCHALOKO},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 16, .level_max = 20, .species = POKEMON_KNILZ},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 16, .level_max = 20, .species = POKEMON_PANEKON},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 16, .level_max = 20, .species = POKEMON_PUDOX},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 16, .level_max = 20, .species = POKEMON_BLANAS},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 20, .level_max = 24, .species = POKEMON_TENGULIST},
};

static wild_pokemon_habitat wild_pokemon_1_0_grass = {
	.frequency = 9, .data = wild_pokemon_1_0_grass_entries
};

static wild_pokemon_entry wild_pokemon_1_0_water_entries[5] = {
	[WILD_POKEMON_DENSITY_WATER_0_60_PERCENT] = 
		{.level_min = 35, .level_max = 35, .species = POKEMON_ENTON},
	[WILD_POKEMON_DENSITY_WATER_1_30_PERCENT] = 
		{.level_min = 35, .level_max = 35, .species = POKEMON_GEHWEIHER},
	[WILD_POKEMON_DENSITY_WATER_2_5_PERCENT] = 
		{.level_min = 33, .level_max = 35, .species = POKEMON_GEHWEIHER},
	[WILD_POKEMON_DENSITY_WATER_3_4_PERCENT] = 
		{.level_min = 35, .level_max = 35, .species = POKEMON_ENTORON},
	[WILD_POKEMON_DENSITY_WATER_3_1_PERCENT] = 
		{.level_min = 35, .level_max = 35, .species = POKEMON_ENTORON},
};

static wild_pokemon_habitat wild_pokemon_1_0_water = {
	.frequency = 10, .data = wild_pokemon_1_0_water_entries
};

static wild_pokemon_entry wild_pokemon_1_0_other_entries[5] = {
	[WILD_POKEMON_DENSITY_OTHER_0_30_PERCENT] = 
		{.level_min = 20, .level_max = 25, .species = POKEMON_PARAGONI},
	[WILD_POKEMON_DENSITY_OTHER_1_25_PERCENT] = 
		{.level_min = 20, .level_max = 25, .species = POKEMON_TANNZA},
	[WILD_POKEMON_DENSITY_OTHER_2_20_PERCENT] = 
		{.level_min = 20, .level_max = 25, .species = POKEMON_KASTADUR},
	[WILD_POKEMON_DENSITY_OTHER_3_15_PERCENT] = 
		{.level_min = 20, .level_max = 25, .species = POKEMON_PARAGONI},
	[WILD_POKEMON_DENSITY_OTHER_4_10_PERCENT] = 
		{.level_min = 20, .level_max = 25, .species = POKEMON_KASTADUR},
};

static wild_pokemon_habitat wild_pokemon_1_0_other = {
	.frequency = 138, .data = wild_pokemon_1_0_other_entries
};

static wild_pokemon_entry wild_pokemon_1_0_rod_entries[10] = {
	[WILD_POKEMON_DENSITY_OLD_ROD_0_70_PERCENT] = 
		{.level_min = 14, .level_max = 14, .species = POKEMON_SCHMERBE},
	[WILD_POKEMON_DENSITY_OLD_ROD_1_30_PERCENT] = 
		{.level_min = 14, .level_max = 14, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_GOOD_ROD_0_60_PERCENT] = 
		{.level_min = 36, .level_max = 36, .species = POKEMON_GARADOS},
	[WILD_POKEMON_DENSITY_GOOD_ROD_1_20_PERCENT] = 
		{.level_min = 36, .level_max = 36, .species = POKEMON_WELSAR},
	[WILD_POKEMON_DENSITY_GOOD_ROD_2_20_PERCENT] = 
		{.level_min = 36, .level_max = 36, .species = POKEMON_WELSAR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_0_40_PERCENT] = 
		{.level_min = 48, .level_max = 48, .species = POKEMON_WELSAR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_1_40_PERCENT] = 
		{.level_min = 48, .level_max = 48, .species = POKEMON_WELSAR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_2_15_PERCENT] = 
		{.level_min = 48, .level_max = 48, .species = POKEMON_GARADOS},
	[WILD_POKEMON_DENSITY_SUPER_ROD_3_4_PERCENT] = 
		{.level_min = 55, .level_max = 55, .species = POKEMON_WELSAR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_4_1_PERCENT] = 
		{.level_min = 55, .level_max = 55, .species = POKEMON_WELSAR},
};

static wild_pokemon_habitat wild_pokemon_1_0_rod = {
	.frequency = 38, .data = wild_pokemon_1_0_rod_entries
};

static wild_pokemon_entry wild_pokemon_1_126_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 26, .level_max = 31, .species = POKEMON_KLEINSTEIN},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 26, .level_max = 31, .species = POKEMON_MAGBY},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 26, .level_max = 31, .species = POKEMON_SCHNECKMAG},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 26, .level_max = 31, .species = POKEMON_SMOGON},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 27, .level_max = 31, .species = POKEMON_KLEINSTEIN},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 27, .level_max = 31, .species = POKEMON_MAGBY},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 27, .level_max = 31, .species = POKEMON_SCHNECKMAG},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 27, .level_max = 32, .species = POKEMON_SMOGON},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 28, .level_max = 32, .species = POKEMON_KLEINSTEIN},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 28, .level_max = 33, .species = POKEMON_MAGBY},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 29, .level_max = 33, .species = POKEMON_SCHNECKMAG},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 33, .level_max = 35, .species = POKEMON_SMOGON},
};

static wild_pokemon_habitat wild_pokemon_1_126_grass = {
	.frequency = 2, .data = wild_pokemon_1_126_grass_entries
};

static wild_pokemon_entry wild_pokemon_silvania_wald_clouds_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 24, .level_max = 27, .species = POKEMON_BIBOR},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 23, .level_max = 27, .species = POKEMON_WABLU},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 23, .level_max = 27, .species = POKEMON_SCHWALBINI},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 23, .level_max = 27, .species = POKEMON_BIBOR},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 23, .level_max = 27, .species = POKEMON_WABLU},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 23, .level_max = 27, .species = POKEMON_BIBOR},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 24, .level_max = 28, .species = POKEMON_SCHWALBINI},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 25, .level_max = 28, .species = POKEMON_WABLU},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 26, .level_max = 29, .species = POKEMON_SCHWALBINI},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 26, .level_max = 29, .species = POKEMON_BIBOR},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 27, .level_max = 29, .species = POKEMON_BIBOR},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 29, .level_max = 32, .species = POKEMON_PAPINELLA},
};

static wild_pokemon_habitat wild_pokemon_silvania_wald_clouds_grass = {
	.frequency = 2, .data = wild_pokemon_silvania_wald_clouds_grass_entries
};

static wild_pokemon_entry wild_pokemon_1_30_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 35, .level_max = 35, .species = POKEMON_DARTIGNIS},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 35, .level_max = 35, .species = POKEMON_KLEINSTEIN},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 35, .level_max = 36, .species = POKEMON_SCHNECKMAG},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 35, .level_max = 36, .species = POKEMON_DARTIGNIS},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 36, .level_max = 37, .species = POKEMON_KLEINSTEIN},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 36, .level_max = 37, .species = POKEMON_SCHNECKMAG},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 36, .level_max = 37, .species = POKEMON_DARTIGNIS},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 28, .level_max = 37, .species = POKEMON_GEOROK},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 37, .level_max = 38, .species = POKEMON_SCHNECKMAG},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 37, .level_max = 37, .species = POKEMON_DARTIGNIS},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 37, .level_max = 37, .species = POKEMON_GEOROK},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 39, .level_max = 40, .species = POKEMON_MAGCARGO},
};

static wild_pokemon_habitat wild_pokemon_1_30_grass = {
	.frequency = 9, .data = wild_pokemon_1_30_grass_entries
};

static wild_pokemon_entry wild_pokemon_1_30_other_entries[5] = {
	[WILD_POKEMON_DENSITY_OTHER_0_30_PERCENT] = 
		{.level_min = 37, .level_max = 38, .species = POKEMON_VULPIX},
	[WILD_POKEMON_DENSITY_OTHER_1_25_PERCENT] = 
		{.level_min = 37, .level_max = 38, .species = POKEMON_DARTIGNIS},
	[WILD_POKEMON_DENSITY_OTHER_2_20_PERCENT] = 
		{.level_min = 37, .level_max = 38, .species = POKEMON_CAMAUB},
	[WILD_POKEMON_DENSITY_OTHER_3_15_PERCENT] = 
		{.level_min = 37, .level_max = 38, .species = POKEMON_VULPIX},
	[WILD_POKEMON_DENSITY_OTHER_4_10_PERCENT] = 
		{.level_min = 38, .level_max = 40, .species = POKEMON_MAGMAR},
};

static wild_pokemon_habitat wild_pokemon_1_30_other = {
	.frequency = 145, .data = wild_pokemon_1_30_other_entries
};

static wild_pokemon_entry wild_pokemon_tafelberg_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 24, .level_max = 27, .species = POKEMON_SPOINK},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 24, .level_max = 27, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 24, .level_max = 27, .species = POKEMON_SPOINK},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 24, .level_max = 27, .species = POKEMON_FLABEBE},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 24, .level_max = 27, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 24, .level_max = 27, .species = POKEMON_SPOINK},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 24, .level_max = 27, .species = POKEMON_FLABEBE},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 24, .level_max = 27, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 25, .level_max = 28, .species = POKEMON_SPOINK},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 25, .level_max = 28, .species = POKEMON_FLABEBE},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 25, .level_max = 28, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 30, .level_max = 32, .species = POKEMON_PELIPPER},
};

static wild_pokemon_habitat wild_pokemon_tafelberg_grass = {
	.frequency = 7, .data = wild_pokemon_tafelberg_grass_entries
};

static wild_pokemon_entry wild_pokemon_tafelberg_water_entries[5] = {
	[WILD_POKEMON_DENSITY_WATER_0_60_PERCENT] = 
		{.level_min = 32, .level_max = 32, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_WATER_1_30_PERCENT] = 
		{.level_min = 32, .level_max = 34, .species = POKEMON_QUABBEL},
	[WILD_POKEMON_DENSITY_WATER_2_5_PERCENT] = 
		{.level_min = 32, .level_max = 34, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_WATER_3_4_PERCENT] = 
		{.level_min = 33, .level_max = 35, .species = POKEMON_KRABBY},
	[WILD_POKEMON_DENSITY_WATER_3_1_PERCENT] = 
		{.level_min = 34, .level_max = 35, .species = POKEMON_WAILMER},
};

static wild_pokemon_habitat wild_pokemon_tafelberg_water = {
	.frequency = 4, .data = wild_pokemon_tafelberg_water_entries
};

static wild_pokemon_entry wild_pokemon_tafelberg_other_entries[5] = {
	[WILD_POKEMON_DENSITY_OTHER_0_30_PERCENT] = 
		{.level_min = 27, .level_max = 30, .species = POKEMON_GEHWEIHER},
	[WILD_POKEMON_DENSITY_OTHER_1_25_PERCENT] = 
		{.level_min = 27, .level_max = 30, .species = POKEMON_NATU},
	[WILD_POKEMON_DENSITY_OTHER_2_20_PERCENT] = 
		{.level_min = 27, .level_max = 32, .species = POKEMON_SPOINK},
	[WILD_POKEMON_DENSITY_OTHER_3_15_PERCENT] = 
		{.level_min = 27, .level_max = 32, .species = POKEMON_GEHWEIHER},
	[WILD_POKEMON_DENSITY_OTHER_4_10_PERCENT] = 
		{.level_min = 30, .level_max = 35, .species = POKEMON_MASKEREGEN},
};

static wild_pokemon_habitat wild_pokemon_tafelberg_other = {
	.frequency = 138, .data = wild_pokemon_tafelberg_other_entries
};


static wild_pokemon_entry wild_pokemon_tafelberg_rod_entries[10] = {
	[WILD_POKEMON_DENSITY_OLD_ROD_0_70_PERCENT] = 
		{.level_min = 23, .level_max = 25, .species = POKEMON_QUABBEL},
	[WILD_POKEMON_DENSITY_OLD_ROD_1_30_PERCENT] = 
		{.level_min = 23, .level_max = 25, .species = POKEMON_STERNDU},
	[WILD_POKEMON_DENSITY_GOOD_ROD_0_60_PERCENT] = 
		{.level_min = 23, .level_max = 25, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_GOOD_ROD_1_20_PERCENT] = 
		{.level_min = 23, .level_max = 25, .species = POKEMON_REMORAID},
	[WILD_POKEMON_DENSITY_GOOD_ROD_2_20_PERCENT] = 
		{.level_min = 23, .level_max = 25, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_0_40_PERCENT] = 
		{.level_min = 15, .level_max = 25, .species = POKEMON_KRABBY},
	[WILD_POKEMON_DENSITY_SUPER_ROD_1_40_PERCENT] = 
		{.level_min = 15, .level_max = 25, .species = POKEMON_KRABBY},
	[WILD_POKEMON_DENSITY_SUPER_ROD_2_15_PERCENT] = 
		{.level_min = 15, .level_max = 25, .species = POKEMON_KINGLER},
	[WILD_POKEMON_DENSITY_SUPER_ROD_3_4_PERCENT] = 
		{.level_min = 25, .level_max = 35, .species = POKEMON_TENTOXA},
	[WILD_POKEMON_DENSITY_SUPER_ROD_4_1_PERCENT] = 
		{.level_min = 25, .level_max = 35, .species = POKEMON_STERNDU},
};

static wild_pokemon_habitat wild_pokemon_tafelberg_rod = {
	.frequency = 25, .data = wild_pokemon_tafelberg_rod_entries
};

static wild_pokemon_entry wild_pokemon_1_81_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 26, .level_max = 30, .species = POKEMON_CAMAUB},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 26, .level_max = 30, .species = POKEMON_KLEINSTEIN},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 26, .level_max = 30, .species = POKEMON_SCHNECKMAG},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 26, .level_max = 30, .species = POKEMON_KLEINSTEIN},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 26, .level_max = 30, .species = POKEMON_SCHNECKMAG},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 26, .level_max = 30, .species = POKEMON_SCHNECKMAG},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 26, .level_max = 32, .species = POKEMON_KLEINSTEIN},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 26, .level_max = 32, .species = POKEMON_KLEINSTEIN},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 26, .level_max = 32, .species = POKEMON_GEOROK},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 26, .level_max = 32, .species = POKEMON_GEOROK},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 26, .level_max = 32, .species = POKEMON_KLEINSTEIN},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 31, .level_max = 32, .species = POKEMON_MAGMAR},
};

static wild_pokemon_habitat wild_pokemon_1_81_grass = {
	.frequency = 3, .data = wild_pokemon_1_81_grass_entries
};

static wild_pokemon_entry wild_pokemon_1_82_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 26, .level_max = 30, .species = POKEMON_KLEINSTEIN},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 26, .level_max = 30, .species = POKEMON_SMOGON},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 26, .level_max = 30, .species = POKEMON_MAGBY},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 27, .level_max = 31, .species = POKEMON_CAMAUB},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 27, .level_max = 31, .species = POKEMON_KLEINSTEIN},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 27, .level_max = 31, .species = POKEMON_SMOGON},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 27, .level_max = 32, .species = POKEMON_MAGBY},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 28, .level_max = 32, .species = POKEMON_KLEINSTEIN},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 28, .level_max = 32, .species = POKEMON_SMOGON},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 28, .level_max = 33, .species = POKEMON_MAGBY},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 29, .level_max = 33, .species = POKEMON_KLEINSTEIN},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 32, .level_max = 34, .species = POKEMON_SMOGON},
};

static wild_pokemon_habitat wild_pokemon_1_82_grass = {
	.frequency = 3, .data = wild_pokemon_1_82_grass_entries
};

static wild_pokemon_entry wild_pokemon_1_82_other_entries[5] = {
	[WILD_POKEMON_DENSITY_OTHER_0_30_PERCENT] = 
		{.level_min = 5, .level_max = 20, .species = POKEMON_KLEINSTEIN},
	[WILD_POKEMON_DENSITY_OTHER_1_25_PERCENT] = 
		{.level_min = 10, .level_max = 20, .species = POKEMON_KLEINSTEIN},
	[WILD_POKEMON_DENSITY_OTHER_2_20_PERCENT] = 
		{.level_min = 15, .level_max = 30, .species = POKEMON_KLEINSTEIN},
	[WILD_POKEMON_DENSITY_OTHER_3_15_PERCENT] = 
		{.level_min = 25, .level_max = 40, .species = POKEMON_GEOROK},
	[WILD_POKEMON_DENSITY_OTHER_4_10_PERCENT] = 
		{.level_min = 30, .level_max = 40, .species = POKEMON_GEOROK},
};

static wild_pokemon_habitat wild_pokemon_1_82_other = {
	.frequency = 50, .data = wild_pokemon_1_82_other_entries
};

static wild_pokemon_entry wild_pokemon_route_2_clouds_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 32, .level_max = 35, .species = POKEMON_KRAMURX},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 32, .level_max = 35, .species = POKEMON_SCHWALBINI},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 33, .level_max = 35, .species = POKEMON_SHNEBEDECK},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 33, .level_max = 35, .species = POKEMON_QUIEKEL},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 33, .level_max = 35, .species = POKEMON_SCHWALBINI},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 33, .level_max = 35, .species = POKEMON_KRAMURX},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 33, .level_max = 35, .species = POKEMON_SHNEBEDECK},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 34, .level_max = 35, .species = POKEMON_SCHWALBINI},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 34, .level_max = 36, .species = POKEMON_QUIEKEL},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 34, .level_max = 36, .species = POKEMON_KRAMURX},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 34, .level_max = 36, .species = POKEMON_KRAMURX},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 35, .level_max = 36, .species = POKEMON_SCHWALBOSS},
};

static wild_pokemon_habitat wild_pokemon_route_2_clouds_grass = {
	.frequency = 7, .data = wild_pokemon_route_2_clouds_grass_entries
};

static wild_pokemon_entry wild_pokemon_route_2_clouds_rod_entries[10] = {
	[WILD_POKEMON_DENSITY_OLD_ROD_0_70_PERCENT] = 
		{.level_min = 9, .level_max = 11, .species = POKEMON_SCHMERBE},
	[WILD_POKEMON_DENSITY_OLD_ROD_1_30_PERCENT] = 
		{.level_min = 9, .level_max = 11, .species = POKEMON_KANIVANHA},
	[WILD_POKEMON_DENSITY_GOOD_ROD_0_60_PERCENT] = 
		{.level_min = 25, .level_max = 35, .species = POKEMON_SCHMERBE},
	[WILD_POKEMON_DENSITY_GOOD_ROD_1_20_PERCENT] = 
		{.level_min = 25, .level_max = 35, .species = POKEMON_KANIVANHA},
	[WILD_POKEMON_DENSITY_GOOD_ROD_2_20_PERCENT] = 
		{.level_min = 25, .level_max = 35, .species = POKEMON_SCHMERBE},
	[WILD_POKEMON_DENSITY_SUPER_ROD_0_40_PERCENT] = 
		{.level_min = 25, .level_max = 35, .species = POKEMON_SCHMERBE},
	[WILD_POKEMON_DENSITY_SUPER_ROD_1_40_PERCENT] = 
		{.level_min = 45, .level_max = 50, .species = POKEMON_KANIVANHA},
	[WILD_POKEMON_DENSITY_SUPER_ROD_2_15_PERCENT] = 
		{.level_min = 45, .level_max = 50, .species = POKEMON_WELSAR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_3_4_PERCENT] = 
		{.level_min = 45, .level_max = 50, .species = POKEMON_WELSAR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_4_1_PERCENT] = 
		{.level_min = 45, .level_max = 55, .species = POKEMON_WELSAR},
};

static wild_pokemon_habitat wild_pokemon_route_2_clouds_rod = {
	.frequency = 49, .data = wild_pokemon_route_2_clouds_rod_entries
};

static wild_pokemon_entry wild_pokemon_route_2_clouds_water_entries[5] = {
	[WILD_POKEMON_DENSITY_WATER_0_60_PERCENT] = 
		{.level_min = 37, .level_max = 39, .species = POKEMON_LOTURZEL},
	[WILD_POKEMON_DENSITY_WATER_1_30_PERCENT] = 
		{.level_min = 37, .level_max = 40, .species = POKEMON_FELINO},
	[WILD_POKEMON_DENSITY_WATER_2_5_PERCENT] = 
		{.level_min = 38, .level_max = 40, .species = POKEMON_LOMBRERO},
	[WILD_POKEMON_DENSITY_WATER_3_4_PERCENT] = 
		{.level_min = 38, .level_max = 41, .species = POKEMON_SCHWALBINI},
	[WILD_POKEMON_DENSITY_WATER_3_1_PERCENT] = 
		{.level_min = 39, .level_max = 42, .species = POKEMON_PUPPANCE},
};

static wild_pokemon_habitat wild_pokemon_route_2_clouds_water = {
	.frequency = 7, .data = wild_pokemon_route_2_clouds_water_entries
};

static wild_pokemon_entry wild_pokemon_route_2_clouds_other_entries[5] = {
	[WILD_POKEMON_DENSITY_OTHER_0_30_PERCENT] = 
		{.level_min = 37, .level_max = 40, .species = POKEMON_PUPPANCE},
	[WILD_POKEMON_DENSITY_OTHER_1_25_PERCENT] = 
		{.level_min = 37, .level_max = 40, .species = POKEMON_FELINO},
	[WILD_POKEMON_DENSITY_OTHER_2_20_PERCENT] = 
		{.level_min = 37, .level_max = 40, .species = POKEMON_GEOROK},
	[WILD_POKEMON_DENSITY_OTHER_3_15_PERCENT] = 
		{.level_min = 37, .level_max = 40, .species = POKEMON_MORLORD},
	[WILD_POKEMON_DENSITY_OTHER_4_10_PERCENT] = 
		{.level_min = 37, .level_max = 40, .species = POKEMON_PUPPANCE},
};

static wild_pokemon_habitat wild_pokemon_route_2_clouds_other = {
	.frequency = 2, .data = wild_pokemon_route_2_clouds_other_entries
};


static wild_pokemon_entry wild_pokemon_unown_ruins_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 24, .level_max = 27, .species = POKEMON_ICOGNITO},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 23, .level_max = 27, .species = POKEMON_ICOGNITO},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 23, .level_max = 27, .species = POKEMON_ICOGNITO},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 23, .level_max = 27, .species = POKEMON_ICOGNITO},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 23, .level_max = 27, .species = POKEMON_ICOGNITO},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 23, .level_max = 27, .species = POKEMON_ICOGNITO},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 24, .level_max = 28, .species = POKEMON_ICOGNITO},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 25, .level_max = 28, .species = POKEMON_ICOGNITO},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 26, .level_max = 29, .species = POKEMON_ICOGNITO},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 26, .level_max = 29, .species = POKEMON_ICOGNITO},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 27, .level_max = 29, .species = POKEMON_ICOGNITO},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 28, .level_max = 32, .species = POKEMON_ICOGNITO},
};

static wild_pokemon_habitat wild_pokemon_unown_ruins_grass = {
	.frequency = 2, .data = wild_pokemon_unown_ruins_grass_entries
};

static wild_pokemon_entry wild_pokemon_route_2_cave_rod_entries[10] = {
	[WILD_POKEMON_DENSITY_OLD_ROD_0_70_PERCENT] = 
		{.level_min = 9, .level_max = 11, .species = POKEMON_KRABBY},
	[WILD_POKEMON_DENSITY_OLD_ROD_1_30_PERCENT] = 
		{.level_min = 9, .level_max = 11, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_GOOD_ROD_0_60_PERCENT] = 
		{.level_min = 25, .level_max = 35, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_GOOD_ROD_1_20_PERCENT] = 
		{.level_min = 25, .level_max = 35, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_GOOD_ROD_2_20_PERCENT] = 
		{.level_min = 25, .level_max = 35, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_0_40_PERCENT] = 
		{.level_min = 25, .level_max = 35, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_1_40_PERCENT] = 
		{.level_min = 45, .level_max = 50, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_SUPER_ROD_2_15_PERCENT] = 
		{.level_min = 45, .level_max = 50, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_3_4_PERCENT] = 
		{.level_min = 45, .level_max = 50, .species = POKEMON_KINGLER},
	[WILD_POKEMON_DENSITY_SUPER_ROD_4_1_PERCENT] = 
		{.level_min = 45, .level_max = 55, .species = POKEMON_KINGLER},
};

static wild_pokemon_habitat wild_pokemon_route_2_cave_rod = {
	.frequency = 49, .data = wild_pokemon_route_2_cave_rod_entries
};

static wild_pokemon_entry wild_pokemon_route_2_cave_water_entries[5] = {
	[WILD_POKEMON_DENSITY_WATER_0_60_PERCENT] = 
		{.level_min = 20, .level_max = 25, .species = POKEMON_KRABBY},
	[WILD_POKEMON_DENSITY_WATER_1_30_PERCENT] = 
		{.level_min = 20, .level_max = 25, .species = POKEMON_MARILL},
	[WILD_POKEMON_DENSITY_WATER_2_5_PERCENT] = 
		{.level_min = 25, .level_max = 30, .species = POKEMON_ZUBAT},
	[WILD_POKEMON_DENSITY_WATER_3_4_PERCENT] = 
		{.level_min = 30, .level_max = 35, .species = POKEMON_GOLBAT},
	[WILD_POKEMON_DENSITY_WATER_3_1_PERCENT] = 
		{.level_min = 30, .level_max = 35, .species = POKEMON_KINGLER},
};

static wild_pokemon_habitat wild_pokemon_route_2_cave_water = {
	.frequency = 7, .data = wild_pokemon_route_2_cave_water_entries
};

static wild_pokemon_entry wild_pokemon_route_9_clouds_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 29, .level_max = 31, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 28, .level_max = 31, .species = POKEMON_KRAMURX},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 28, .level_max = 31, .species = POKEMON_SCHWALBINI},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 28, .level_max = 31, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 28, .level_max = 31, .species = POKEMON_KRAMURX},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 28, .level_max = 31, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 29, .level_max = 32, .species = POKEMON_SCHWALBINI},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 30, .level_max = 33, .species = POKEMON_KRAMURX},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 30, .level_max = 33, .species = POKEMON_SCHWALBINI},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 30, .level_max = 34, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 31, .level_max = 34, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 33, .level_max = 35, .species = POKEMON_PELIPPER},
};

static wild_pokemon_habitat wild_pokemon_route_9_clouds_grass = {
	.frequency = 2, .data = wild_pokemon_route_9_clouds_grass_entries
};

static wild_pokemon_entry wild_pokemon_route_10_clouds_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 33, .level_max = 33, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 33, .level_max = 34, .species = POKEMON_KLEINSTEIN},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 33, .level_max = 34, .species = POKEMON_MEDITIE},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 33, .level_max = 34, .species = POKEMON_SKORGLA},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 34, .level_max = 34, .species = POKEMON_MACHOLLO},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 35, .level_max = 35, .species = POKEMON_NINCADA},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 34, .level_max = 35, .species = POKEMON_NINCADA},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 34, .level_max = 35, .species = POKEMON_SKORGLA},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 35, .level_max = 35, .species = POKEMON_KLEINSTEIN},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 35, .level_max = 35, .species = POKEMON_GEOROK},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 35, .level_max = 35, .species = POKEMON_NINJASK},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 36, .level_max = 37, .species = POKEMON_PELIPPER},
};

static wild_pokemon_habitat wild_pokemon_route_10_clouds_grass = {
	.frequency = 25, .data = wild_pokemon_route_10_clouds_grass_entries
};


static wild_pokemon_entry wild_pokemon_route_10_clouds_other_entries[12] = {
	[WILD_POKEMON_DENSITY_OTHER_0_30_PERCENT] = 
		{.level_min = 35, .level_max = 37, .species = POKEMON_NINJASK},
	[WILD_POKEMON_DENSITY_OTHER_1_25_PERCENT] = 
		{.level_min = 35, .level_max = 37, .species = POKEMON_PHANPY},
	[WILD_POKEMON_DENSITY_OTHER_2_20_PERCENT] = 
		{.level_min = 35, .level_max = 38, .species = POKEMON_ONIX},
	[WILD_POKEMON_DENSITY_OTHER_3_15_PERCENT] = 
		{.level_min = 36, .level_max = 38, .species = POKEMON_NINJASK},
	[WILD_POKEMON_DENSITY_OTHER_4_10_PERCENT] = 
		{.level_min = 37, .level_max = 39, .species = POKEMON_DONPHAN},
};


static wild_pokemon_habitat wild_pokemon_route_10_clouds_other = {
	.frequency = 165, .data = wild_pokemon_route_10_clouds_other_entries
};

static wild_pokemon_entry wild_pokemon_15_0_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 9, .level_max = 12, .species = POKEMON_VOLTILAMM},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 8, .level_max = 11, .species = POKEMON_KNOFENSA},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 9, .level_max = 13, .species = POKEMON_MYRAPLA},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 9, .level_max = 13, .species = POKEMON_MAEHIKEL},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 7, .level_max = 14, .species = POKEMON_VOLTILAMM},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 9, .level_max = 13, .species = POKEMON_KNOFENSA},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 8, .level_max = 11, .species = POKEMON_MYRAPLA},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 8, .level_max = 11, .species = POKEMON_MAEHIKEL},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 8, .level_max = 11, .species = POKEMON_VOLTILAMM},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 8, .level_max = 11, .species = POKEMON_VOLTILAMM},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 8, .level_max = 11, .species = POKEMON_KNOFENSA},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 15, .level_max = 15, .species = POKEMON_WAATY},
};

static wild_pokemon_habitat wild_pokemon_15_0_grass = {
	.frequency = 16, .data = wild_pokemon_15_0_grass_entries
};

static wild_pokemon_entry wild_pokemon_15_0_water_entries[5] = {
	[WILD_POKEMON_DENSITY_WATER_0_60_PERCENT] = 
		{.level_min = 26, .level_max = 30, .species = POKEMON_LOTURZEL},
	[WILD_POKEMON_DENSITY_WATER_1_30_PERCENT] = 
		{.level_min = 28, .level_max = 33, .species = POKEMON_LOMBRERO},
	[WILD_POKEMON_DENSITY_WATER_2_5_PERCENT] = 
		{.level_min = 28, .level_max = 30, .species = POKEMON_MARILL},
	[WILD_POKEMON_DENSITY_WATER_3_4_PERCENT] = 
		{.level_min = 30, .level_max = 35, .species = POKEMON_AZUMARILL},
	[WILD_POKEMON_DENSITY_WATER_3_1_PERCENT] = 
		{.level_min = 27, .level_max = 35, .species = POKEMON_AZUMARILL},
};

static wild_pokemon_habitat wild_pokemon_15_0_water = {
	.frequency = 11, .data = wild_pokemon_15_0_water_entries
};

static wild_pokemon_entry wild_pokemon_15_0_other_entries[5] = {
	[WILD_POKEMON_DENSITY_OTHER_0_30_PERCENT] = 
		{.level_min = 10, .level_max = 14, .species = POKEMON_MOGELBAUM},
	[WILD_POKEMON_DENSITY_OTHER_1_25_PERCENT] = 
		{.level_min = 10, .level_max = 14, .species = POKEMON_CLAVION},
	[WILD_POKEMON_DENSITY_OTHER_2_20_PERCENT] = 
		{.level_min = 10, .level_max = 14, .species = POKEMON_MAEHIKEL},
	[WILD_POKEMON_DENSITY_OTHER_3_15_PERCENT] = 
		{.level_min = 12, .level_max = 14, .species = POKEMON_MOGELBAUM},
	[WILD_POKEMON_DENSITY_OTHER_4_10_PERCENT] = 
		{.level_min = 14, .level_max = 16, .species = POKEMON_MILTANK},
};

static wild_pokemon_habitat wild_pokemon_15_0_other = {
	.frequency = 130, .data = wild_pokemon_15_0_other_entries
};

static wild_pokemon_entry wild_pokemon_15_0_rod_entries[10] = {
	[WILD_POKEMON_DENSITY_OLD_ROD_0_70_PERCENT] = 
		{.level_min = 9, .level_max = 13, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_OLD_ROD_1_30_PERCENT] = 
		{.level_min = 11, .level_max = 14, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_GOOD_ROD_0_60_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_GOOD_ROD_1_20_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_GOOD_ROD_2_20_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_0_40_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_1_40_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_2_15_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_3_4_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_GARADOS},
	[WILD_POKEMON_DENSITY_SUPER_ROD_4_1_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_GARADOS},
};

static wild_pokemon_habitat wild_pokemon_15_0_rod = {
	.frequency = 75, .data = wild_pokemon_15_0_rod_entries
};

static wild_pokemon_entry wild_pokemon_route_3_clouds_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 24, .level_max = 27, .species = POKEMON_DARTIRI},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 23, .level_max = 27, .species = POKEMON_WABLU},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 23, .level_max = 27, .species = POKEMON_SCHWALBINI},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 23, .level_max = 27, .species = POKEMON_DARTIRI},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 23, .level_max = 27, .species = POKEMON_WABLU},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 23, .level_max = 27, .species = POKEMON_DARTIRI},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 24, .level_max = 28, .species = POKEMON_SCHWALBINI},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 25, .level_max = 28, .species = POKEMON_WABLU},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 26, .level_max = 29, .species = POKEMON_SCHWALBINI},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 26, .level_max = 29, .species = POKEMON_DARTIRI},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 27, .level_max = 29, .species = POKEMON_DARTIRI},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 29, .level_max = 32, .species = POKEMON_DARTIGNIS},
};

static wild_pokemon_habitat wild_pokemon_route_3_clouds_grass = {
	.frequency = 2, .data = wild_pokemon_route_3_clouds_grass_entries
};

static wild_pokemon_entry wild_pokemon_15_4_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 10, .level_max = 13, .species = POKEMON_SCHWALBINI},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 10, .level_max = 13, .species = POKEMON_WABLU},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 10, .level_max = 13, .species = POKEMON_SCHWALBINI},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 10, .level_max = 13, .species = POKEMON_STARAVIA},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 10, .level_max = 13, .species = POKEMON_SCHWALBINI},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 10, .level_max = 13, .species = POKEMON_SCHWALBINI},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 10, .level_max = 13, .species = POKEMON_DARTIRI},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 10, .level_max = 13, .species = POKEMON_STARALILI},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 10, .level_max = 13, .species = POKEMON_DARTIRI},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 10, .level_max = 13, .species = POKEMON_WABLU},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 10, .level_max = 13, .species = POKEMON_DARTIRI},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 14, .level_max = 17, .species = POKEMON_STARAVIA},
};

static wild_pokemon_habitat wild_pokemon_15_4_grass = {
	.frequency = 6, .data = wild_pokemon_15_4_grass_entries
};

static wild_pokemon_entry wild_pokemon_route_4_clouds_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 24, .level_max = 27, .species = POKEMON_KRAMURX},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 23, .level_max = 27, .species = POKEMON_WABLU},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 23, .level_max = 27, .species = POKEMON_SCHWALBINI},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 23, .level_max = 27, .species = POKEMON_KRAMURX},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 23, .level_max = 27, .species = POKEMON_WABLU},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 23, .level_max = 27, .species = POKEMON_KRAMURX},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 24, .level_max = 28, .species = POKEMON_SCHWALBINI},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 25, .level_max = 28, .species = POKEMON_WABLU},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 26, .level_max = 29, .species = POKEMON_SCHWALBINI},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 26, .level_max = 29, .species = POKEMON_KRAMURX},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 27, .level_max = 29, .species = POKEMON_KRAMURX},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 28, .level_max = 32, .species = POKEMON_SCHWALBINI},
};

static wild_pokemon_habitat wild_pokemon_route_4_clouds_grass = {
	.frequency = 2, .data = wild_pokemon_route_4_clouds_grass_entries
};

static wild_pokemon_entry wild_pokemon_route_4_south_cave_grass_entries[12] = {
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

static wild_pokemon_habitat wild_pokemon_route_4_south_cave_grass = {
	.frequency = 1, .data = wild_pokemon_route_4_south_cave_grass_entries
};

static wild_pokemon_entry wild_pokemon_route_4_cloud_cave_grass_entries[12] = {
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

static wild_pokemon_habitat wild_pokemon_route_4_cloud_cave_grass = {
	.frequency = 2, .data = wild_pokemon_route_4_cloud_cave_grass_entries
};

static wild_pokemon_entry wild_pokemon_route_5_clouds_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 33, .level_max = 35, .species = POKEMON_WABLU},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 33, .level_max = 35, .species = POKEMON_SCHWALBINI},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 33, .level_max = 35, .species = POKEMON_DARTIGNIS},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 33, .level_max = 35, .species = POKEMON_WABLU},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 3, .level_max = 35, .species = POKEMON_SCHWALBINI},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 33, .level_max = 35, .species = POKEMON_WABLU},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 34, .level_max = 35, .species = POKEMON_DARTIGNIS},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 34, .level_max = 35, .species = POKEMON_SCHWALBINI},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 34, .level_max = 36, .species = POKEMON_DARTIGNIS},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 34, .level_max = 36, .species = POKEMON_WABLU},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 34, .level_max = 36, .species = POKEMON_WABLU},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 34, .level_max = 36, .species = POKEMON_SCHWALBOSS},
};

static wild_pokemon_habitat wild_pokemon_route_5_clouds_grass = {
	.frequency = 2, .data = wild_pokemon_route_5_clouds_grass_entries
};


static wild_pokemon_entry wild_pokemon_route_5_cave_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 30, .level_max = 33, .species = POKEMON_WEBARAK},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 30, .level_max = 33, .species = POKEMON_ZUBAT},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 30, .level_max = 33, .species = POKEMON_KNILZ},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 30, .level_max = 33, .species = POKEMON_WEBARAK},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 30, .level_max = 33, .species = POKEMON_ZUBAT},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 30, .level_max = 34, .species = POKEMON_KNILZ},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 30, .level_max = 34, .species = POKEMON_WEBARAK},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 30, .level_max = 34, .species = POKEMON_WEBARAK},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 31, .level_max = 34, .species = POKEMON_WEBARAK},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 32, .level_max = 29, .species = POKEMON_ARIADOS},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 32, .level_max = 35, .species = POKEMON_ARIADOS},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 32, .level_max = 35, .species = POKEMON_ARIADOS},
};

static wild_pokemon_habitat wild_pokemon_route_5_cave_grass = {
	.frequency = 2, .data = wild_pokemon_route_5_cave_grass_entries
};

static wild_pokemon_entry wild_pokemon_route_6_clouds_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 24, .level_max = 27, .species = POKEMON_KRAMURX},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 23, .level_max = 27, .species = POKEMON_DARTIRI},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 23, .level_max = 27, .species = POKEMON_DARTIGNIS},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 23, .level_max = 27, .species = POKEMON_KRAMURX},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 23, .level_max = 27, .species = POKEMON_DARTIRI},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 23, .level_max = 27, .species = POKEMON_KRAMURX},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 24, .level_max = 28, .species = POKEMON_DARTIGNIS},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 25, .level_max = 28, .species = POKEMON_DARTIRI},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 26, .level_max = 29, .species = POKEMON_DARTIGNIS},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 26, .level_max = 29, .species = POKEMON_KRAMURX},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 27, .level_max = 29, .species = POKEMON_KRAMURX},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 28, .level_max = 32, .species = POKEMON_DARTIGNIS},
};

static wild_pokemon_habitat wild_pokemon_route_6_clouds_grass = {
	.frequency = 2, .data = wild_pokemon_route_6_clouds_grass_entries
};


static wild_pokemon_entry wild_pokemon_route_6_clouds_water_entries[5] = {
	[WILD_POKEMON_DENSITY_WATER_0_60_PERCENT] = 
		{.level_min = 22, .level_max = 27, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_WATER_1_30_PERCENT] = 
		{.level_min = 22, .level_max = 27, .species = POKEMON_DARTIRI},
	[WILD_POKEMON_DENSITY_WATER_2_5_PERCENT] = 
		{.level_min = 25, .level_max = 30, .species = POKEMON_LOTURZEL},
	[WILD_POKEMON_DENSITY_WATER_3_4_PERCENT] = 
		{.level_min = 30, .level_max = 35, .species = POKEMON_LOTURZEL},
	[WILD_POKEMON_DENSITY_WATER_3_1_PERCENT] = 
		{.level_min = 30, .level_max = 35, .species = POKEMON_LOMBRERO},
};

static wild_pokemon_habitat wild_pokemon_route_6_clouds_water = {
	.frequency = 7, .data = wild_pokemon_route_6_clouds_water_entries
};

static wild_pokemon_entry wild_pokemon_route_6_clouds_rod_entries[10] = {
	[WILD_POKEMON_DENSITY_OLD_ROD_0_70_PERCENT] = 
		{.level_min = 9, .level_max = 11, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_OLD_ROD_1_30_PERCENT] = 
		{.level_min = 9, .level_max = 11, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_GOOD_ROD_0_60_PERCENT] = 
		{.level_min = 25, .level_max = 35, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_GOOD_ROD_1_20_PERCENT] = 
		{.level_min = 25, .level_max = 35, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_GOOD_ROD_2_20_PERCENT] = 
		{.level_min = 25, .level_max = 35, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_0_40_PERCENT] = 
		{.level_min = 25, .level_max = 35, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_1_40_PERCENT] = 
		{.level_min = 45, .level_max = 50, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_SUPER_ROD_2_15_PERCENT] = 
		{.level_min = 45, .level_max = 50, .species = POKEMON_SEEPER},
	[WILD_POKEMON_DENSITY_SUPER_ROD_3_4_PERCENT] = 
		{.level_min = 45, .level_max = 50, .species = POKEMON_TENTOXA},
	[WILD_POKEMON_DENSITY_SUPER_ROD_4_1_PERCENT] = 
		{.level_min = 45, .level_max = 55, .species = POKEMON_SEEPER},
};

static wild_pokemon_habitat wild_pokemon_route_6_clouds_rod = {
	.frequency = 49, .data = wild_pokemon_route_6_clouds_rod_entries
};

static wild_pokemon_entry wild_pokemon_18_2_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 24, .level_max = 27, .species = POKEMON_ZUBAT},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 24, .level_max = 27, .species = POKEMON_CAMAUB},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 24, .level_max = 27, .species = POKEMON_MACHOLLO},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 25, .level_max = 28, .species = POKEMON_ZUBAT},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 25, .level_max = 27, .species = POKEMON_CAMAUB},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 25, .level_max = 27, .species = POKEMON_MACHOLLO},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 26, .level_max = 27, .species = POKEMON_ZUBAT},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 26, .level_max = 28, .species = POKEMON_CAMAUB},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 27, .level_max = 29, .species = POKEMON_GOLBAT},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 28, .level_max = 30, .species = POKEMON_MASCHOCK},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 29, .level_max = 32, .species = POKEMON_CAMAUB},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 30, .level_max = 33, .species = POKEMON_CAMAUB},
};

static wild_pokemon_habitat wild_pokemon_18_2_grass = {
	.frequency = 4, .data = wild_pokemon_18_2_grass_entries
};

static wild_pokemon_entry wild_pokemon_18_3_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 32, .level_max = 34, .species = POKEMON_VULPIX},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 32, .level_max = 34, .species = POKEMON_SCHNECKMAG},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 33, .level_max = 34, .species = POKEMON_MAGBY},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 33, .level_max = 35, .species = POKEMON_CAMAUB},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 33, .level_max = 35, .species = POKEMON_VULPIX},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 33, .level_max = 35, .species = POKEMON_SCHNECKMAG},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 34, .level_max = 35, .species = POKEMON_CAMAUB},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 34, .level_max = 35, .species = POKEMON_MAGBY},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 34, .level_max = 36, .species = POKEMON_VULPIX},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 35, .level_max = 36, .species = POKEMON_SCHNECKMAG},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 35, .level_max = 37, .species = POKEMON_CAMAUB},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 37, .level_max = 37, .species = POKEMON_MAGMAR},
};

static wild_pokemon_habitat wild_pokemon_18_3_grass = {
	.frequency = 24, .data = wild_pokemon_18_3_grass_entries
};

static wild_pokemon_entry wild_pokemon_18_3_other_entries[5] = {
	[WILD_POKEMON_DENSITY_OTHER_0_30_PERCENT] = 
		{.level_min = 35, .level_max = 37, .species = POKEMON_FUKANO},
	[WILD_POKEMON_DENSITY_OTHER_1_25_PERCENT] = 
		{.level_min = 35, .level_max = 37, .species = POKEMON_HUNDUSTER},
	[WILD_POKEMON_DENSITY_OTHER_2_20_PERCENT] = 
		{.level_min = 36, .level_max = 38, .species = POKEMON_FUKANO},
	[WILD_POKEMON_DENSITY_OTHER_3_15_PERCENT] = 
		{.level_min = 36, .level_max = 38, .species = POKEMON_HUNDUSTER},
	[WILD_POKEMON_DENSITY_OTHER_4_10_PERCENT] = 
		{.level_min = 38, .level_max = 38, .species = POKEMON_PANZAERON},
};

static wild_pokemon_habitat wild_pokemon_18_3_other = {
	.frequency = 79, .data = wild_pokemon_18_3_other_entries
};

static wild_pokemon_entry wild_pokemon_ceometria_clouds_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 30, .level_max = 33, .species = POKEMON_TRAUNFUGIL},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 30, .level_max = 33, .species = POKEMON_SHUPPET},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 30, .level_max = 33, .species = POKEMON_NEBULAK},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 30, .level_max = 33, .species = POKEMON_TRAUNFUGIL},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 31, .level_max = 33, .species = POKEMON_KRAMURX},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 31, .level_max = 34, .species = POKEMON_TRAUNFUGIL},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 31, .level_max = 34, .species = POKEMON_NEBULAK},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 31, .level_max = 34, .species = POKEMON_SHUPPET},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 32, .level_max = 34, .species = POKEMON_TRAUNFUGIL},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 32, .level_max = 35, .species = POKEMON_KRAMURX},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 33, .level_max = 35, .species = POKEMON_KRAMURX},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 35, .level_max = 38, .species = POKEMON_ALPOLLO},
};

static wild_pokemon_habitat wild_pokemon_ceometria_clouds_grass = {
	.frequency = 2, .data = wild_pokemon_ceometria_clouds_grass_entries
};

static wild_pokemon_entry wild_pokemon_tafelberg_south_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 31, .level_max = 33, .species = POKEMON_DIGDA},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 31, .level_max = 33, .species = POKEMON_MENKI},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 31, .level_max = 33, .species = POKEMON_MACHOLLO},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 31, .level_max = 33, .species = POKEMON_KLEINSTEIN},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 31, .level_max = 34, .species = POKEMON_MEDITIE},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 32, .level_max = 34, .species = POKEMON_MACHOLLO},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 32, .level_max = 34, .species = POKEMON_MENKI},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 32, .level_max = 34, .species = POKEMON_KLEINSTEIN},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 33, .level_max = 34, .species = POKEMON_MEDITIE},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 33, .level_max = 35, .species = POKEMON_KLEINSTEIN},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 34, .level_max = 35, .species = POKEMON_MASCHOCK},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 34, .level_max = 36, .species = POKEMON_MASCHOCK},
};

static wild_pokemon_habitat wild_pokemon_tafelberg_south_grass = {
	.frequency = 9, .data = wild_pokemon_tafelberg_south_grass_entries
};

static wild_pokemon_entry wild_pokemon_tafelberg_west_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 31, .level_max = 33, .species = POKEMON_FELINO},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 31, .level_max = 33, .species = POKEMON_MEDITIE},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 31, .level_max = 33, .species = POKEMON_STARALILI},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 31, .level_max = 33, .species = POKEMON_KLEINSTEIN},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 31, .level_max = 34, .species = POKEMON_FELINO},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 32, .level_max = 34, .species = POKEMON_STARALILI},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 32, .level_max = 34, .species = POKEMON_DARTIRI},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 32, .level_max = 34, .species = POKEMON_FELINO},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 33, .level_max = 34, .species = POKEMON_MEDITIE},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 33, .level_max = 35, .species = POKEMON_KLEINSTEIN},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 34, .level_max = 35, .species = POKEMON_DARTIGNIS},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 34, .level_max = 36, .species = POKEMON_GEOROK},
};

static wild_pokemon_habitat wild_pokemon_tafelberg_west_grass = {
	.frequency = 9, .data = wild_pokemon_tafelberg_west_grass_entries
};

static wild_pokemon_entry wild_pokemon_tafelberg_south_other_entries[5] = {
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

static wild_pokemon_habitat wild_pokemon_tafelberg_south_other = {
	.frequency = 180, .data = wild_pokemon_tafelberg_south_other_entries
};

static wild_pokemon_entry wild_pokemon_tafelberg_west_water_entries[5] = {
	[WILD_POKEMON_DENSITY_WATER_0_60_PERCENT] = 
		{.level_min = 35, .level_max = 35, .species = POKEMON_FELINO},
	[WILD_POKEMON_DENSITY_WATER_1_30_PERCENT] = 
		{.level_min = 35, .level_max = 35, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_WATER_2_5_PERCENT] = 
		{.level_min = 35, .level_max = 35, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_WATER_3_4_PERCENT] = 
		{.level_min = 35, .level_max = 35, .species = POKEMON_LOMBRERO},
	[WILD_POKEMON_DENSITY_WATER_3_1_PERCENT] = 
		{.level_min = 37, .level_max = 38, .species = POKEMON_MORLORD},
};

static wild_pokemon_habitat wild_pokemon_tafelberg_west_water = {
	.frequency = 15, .data = wild_pokemon_tafelberg_west_water_entries
};

static wild_pokemon_entry wild_pokemon_tafelberg_west_other_entries[5] = {
	[WILD_POKEMON_DENSITY_OTHER_0_30_PERCENT] = 
		{.level_min = 33, .level_max = 35, .species = POKEMON_FELINO},
	[WILD_POKEMON_DENSITY_OTHER_1_25_PERCENT] = 
		{.level_min = 33, .level_max = 35, .species = POKEMON_BLANAS},
	[WILD_POKEMON_DENSITY_OTHER_2_20_PERCENT] = 
		{.level_min = 33, .level_max = 36, .species = POKEMON_GERADAKS},
	[WILD_POKEMON_DENSITY_OTHER_3_15_PERCENT] = 
		{.level_min = 34, .level_max = 36, .species = POKEMON_FLOETTE},
	[WILD_POKEMON_DENSITY_OTHER_4_10_PERCENT] = 
		{.level_min = 34, .level_max = 36, .species = POKEMON_DUFLOR},
};

static wild_pokemon_habitat wild_pokemon_tafelberg_west_other = {
	.frequency = 180, .data = wild_pokemon_tafelberg_west_other_entries
};

static wild_pokemon_entry wild_pokemon_tafelberg_south_water_entries[5] = {
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

static wild_pokemon_habitat wild_pokemon_tafelberg_south_water = {
	.frequency = 15, .data = wild_pokemon_tafelberg_south_water_entries
};

static wild_pokemon_entry wild_pokemon_tafelberg_south_rod_entries[10] = {
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

static wild_pokemon_habitat wild_pokemon_tafelberg_south_rod = {
	.frequency = 6, .data = wild_pokemon_tafelberg_south_rod_entries
};

static wild_pokemon_entry wild_pokemon_route_8_clouds_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 24, .level_max = 27, .species = POKEMON_KLINGPLIM},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 23, .level_max = 27, .species = POKEMON_WABLU},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 23, .level_max = 27, .species = POKEMON_SCHWALBINI},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 23, .level_max = 27, .species = POKEMON_KLINGPLIM},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 23, .level_max = 27, .species = POKEMON_WABLU},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 23, .level_max = 27, .species = POKEMON_KLINGPLIM},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 24, .level_max = 28, .species = POKEMON_SCHWALBINI},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 25, .level_max = 28, .species = POKEMON_WABLU},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 26, .level_max = 29, .species = POKEMON_SCHWALBINI},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 26, .level_max = 29, .species = POKEMON_KLINGPLIM},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 27, .level_max = 29, .species = POKEMON_KLINGPLIM},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 31, .level_max = 33, .species = POKEMON_SCHWALBOSS},
};

static wild_pokemon_habitat wild_pokemon_route_8_clouds_grass = {
	.frequency = 2, .data = wild_pokemon_route_8_clouds_grass_entries
};

static wild_pokemon_entry wild_pokemon_route_11_clouds_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 30, .level_max = 33, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 30, .level_max = 33, .species = POKEMON_SHUPPET},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 30, .level_max = 33, .species = POKEMON_NEBULAK},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 30, .level_max = 33, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 31, .level_max = 33, .species = POKEMON_KRAMURX},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 31, .level_max = 34, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 31, .level_max = 34, .species = POKEMON_NEBULAK},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 31, .level_max = 34, .species = POKEMON_SHUPPET},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 32, .level_max = 34, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 32, .level_max = 35, .species = POKEMON_KRAMURX},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 33, .level_max = 35, .species = POKEMON_KRAMURX},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 35, .level_max = 38, .species = POKEMON_ALPOLLO},
};

static wild_pokemon_habitat wild_pokemon_route_11_clouds_grass = {
	.frequency = 2, .data = wild_pokemon_route_11_clouds_grass_entries
};

static wild_pokemon_entry wild_pokemon_route_12_clouds_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 30, .level_max = 33, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 30, .level_max = 33, .species = POKEMON_SCHWALBINI},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 30, .level_max = 33, .species = POKEMON_WABLU},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 30, .level_max = 33, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 31, .level_max = 33, .species = POKEMON_KRAMURX},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 31, .level_max = 34, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 31, .level_max = 34, .species = POKEMON_WABLU},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 31, .level_max = 34, .species = POKEMON_SCHWALBINI},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 32, .level_max = 34, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 32, .level_max = 35, .species = POKEMON_KRAMURX},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 33, .level_max = 35, .species = POKEMON_KRAMURX},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 35, .level_max = 38, .species = POKEMON_PELIPPER},
};

static wild_pokemon_habitat wild_pokemon_route_12_clouds_grass = {
	.frequency = 2, .data = wild_pokemon_route_12_clouds_grass_entries
};

static wild_pokemon_entry wild_pokemon_route_7_castle_grass_entries[12] = {
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

static wild_pokemon_habitat wild_pokemon_route_7_castle_grass = {
  .frequency = 30, .data = wild_pokemon_route_7_castle_grass_entries
};

static wild_pokemon_entry wild_pokemon_route_7_castle_other_entries[5] = {
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

static wild_pokemon_habitat wild_pokemon_route_7_castle_other = {
  .frequency = 128, .data = wild_pokemon_route_7_castle_other_entries
};


static wild_pokemon_entry wild_pokemon_route_7_castle_water_entries[5] = {
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


static wild_pokemon_habitat wild_pokemon_route_7_castle_water = {
	.frequency = 4, .data = wild_pokemon_route_7_castle_water_entries
};

static wild_pokemon_entry wild_pokemon_route_7_castle_rod_entries[10] = {
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

static wild_pokemon_habitat wild_pokemon_route_7_castle_rod = {
	.frequency = 75, .data = wild_pokemon_route_7_castle_rod_entries
};

static wild_pokemon_entry wild_pokemon_route_7_north_grass_entries[12] = {
  [WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] =
    {.level_min = 34, .level_max = 38, .species = POKEMON_VULPIX},
  [WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] =
    {.level_min = 34, .level_max = 36, .species = POKEMON_MAGBY},
  [WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] =
    {.level_min = 34, .level_max = 36, .species = POKEMON_PIKACHU},
  [WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] =
    {.level_min = 34, .level_max = 38, .species = POKEMON_NIDORANM},
  [WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] =
    {.level_min = 34, .level_max = 38, .species = POKEMON_NIDORANW},
  [WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] =
    {.level_min = 34, .level_max = 38, .species = POKEMON_VULPIX},
  [WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] =
    {.level_min = 34, .level_max = 38, .species = POKEMON_PIKACHU},
  [WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] =
    {.level_min = 34, .level_max = 38, .species = POKEMON_NIDORINA},
  [WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] =
    {.level_min = 37, .level_max = 39, .species = POKEMON_NIDORINO},
  [WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] =
    {.level_min = 37, .level_max = 40, .species = POKEMON_MAGMAR},
  [WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] =
    {.level_min = 38, .level_max = 40, .species = POKEMON_NIDORINA},
  [WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] =
    {.level_min = 39, .level_max = 41, .species = POKEMON_NIDORINO},
};

static wild_pokemon_habitat wild_pokemon_route_7_north_grass = {
  .frequency = 30, .data = wild_pokemon_route_7_north_grass_entries
};

static wild_pokemon_entry wild_pokemon_route_7_north_other_entries[5] = {
  [WILD_POKEMON_DENSITY_OTHER_0_30_PERCENT] =
    {.level_min = 35, .level_max = 40, .species = POKEMON_MAGMAR},
  [WILD_POKEMON_DENSITY_OTHER_1_25_PERCENT] =
    {.level_min = 35, .level_max = 41, .species = POKEMON_NIDORINO},
  [WILD_POKEMON_DENSITY_OTHER_2_20_PERCENT] =
    {.level_min = 35, .level_max = 40, .species = POKEMON_NIDORINA},
  [WILD_POKEMON_DENSITY_OTHER_3_15_PERCENT] =
    {.level_min = 35, .level_max = 42, .species = POKEMON_RAICHU},
  [WILD_POKEMON_DENSITY_OTHER_4_10_PERCENT] =
    {.level_min = 38, .level_max = 42, .species = POKEMON_FUKANO},
};

static wild_pokemon_habitat wild_pokemon_route_7_north_other = {
  .frequency = 128, .data = wild_pokemon_route_7_north_other_entries
};


static wild_pokemon_entry wild_pokemon_3_0_water_entries[5] = {
	[WILD_POKEMON_DENSITY_WATER_0_60_PERCENT] = 
		{.level_min = 33, .level_max = 35, .species = POKEMON_LOTURZEL},
	[WILD_POKEMON_DENSITY_WATER_1_30_PERCENT] = 
		{.level_min = 33, .level_max = 35, .species = POKEMON_MASKEREGEN},
	[WILD_POKEMON_DENSITY_WATER_2_5_PERCENT] = 
		{.level_min = 33, .level_max = 35, .species = POKEMON_LOTURZEL},
	[WILD_POKEMON_DENSITY_WATER_3_4_PERCENT] = 
		{.level_min = 33, .level_max = 35, .species = POKEMON_MASKEREGEN},
	[WILD_POKEMON_DENSITY_WATER_3_1_PERCENT] = 
		{.level_min = 34, .level_max = 35, .species = POKEMON_LOTURZEL},
};

static wild_pokemon_habitat wild_pokemon_3_0_water = {
	.frequency = 9, .data = wild_pokemon_3_0_water_entries
};

static wild_pokemon_entry wild_pokemon_3_0_rod_entries[10] = {
	[WILD_POKEMON_DENSITY_OLD_ROD_0_70_PERCENT] = 
		{.level_min = 11, .level_max = 11, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_OLD_ROD_1_30_PERCENT] = 
		{.level_min = 11, .level_max = 1, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_GOOD_ROD_0_60_PERCENT] = 
		{.level_min = 22, .level_max = 25, .species = POKEMON_FLEGMON},
	[WILD_POKEMON_DENSITY_GOOD_ROD_1_20_PERCENT] = 
		{.level_min = 22, .level_max = 25, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_GOOD_ROD_2_20_PERCENT] = 
		{.level_min = 22, .level_max = 25, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_0_40_PERCENT] = 
		{.level_min = 35, .level_max = 38, .species = POKEMON_FLEGMON},
	[WILD_POKEMON_DENSITY_SUPER_ROD_1_40_PERCENT] = 
		{.level_min = 35, .level_max = 38, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_2_15_PERCENT] = 
		{.level_min = 35, .level_max = 38, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_3_4_PERCENT] = 
		{.level_min = 35, .level_max = 38, .species = POKEMON_GARADOS},
	[WILD_POKEMON_DENSITY_SUPER_ROD_4_1_PERCENT] = 
		{.level_min = 35, .level_max = 38, .species = POKEMON_FLEGMON},
};

static wild_pokemon_habitat wild_pokemon_3_0_rod = {
	.frequency = 66, .data = wild_pokemon_3_0_rod_entries
};

static wild_pokemon_entry wild_pokemon_3_1_water_entries[5] = {
	[WILD_POKEMON_DENSITY_WATER_0_60_PERCENT] = 
		{.level_min = 25, .level_max = 30, .species = POKEMON_LOTURZEL},
	[WILD_POKEMON_DENSITY_WATER_1_30_PERCENT] = 
		{.level_min = 25, .level_max = 30, .species = POKEMON_ENTON},
	[WILD_POKEMON_DENSITY_WATER_2_5_PERCENT] = 
		{.level_min = 25, .level_max = 30, .species = POKEMON_LOTURZEL},
	[WILD_POKEMON_DENSITY_WATER_3_4_PERCENT] = 
		{.level_min = 27, .level_max = 30, .species = POKEMON_LOMBRERO},
	[WILD_POKEMON_DENSITY_WATER_3_1_PERCENT] = 
		{.level_min = 27, .level_max = 32, .species = POKEMON_LOMBRERO},
};

static wild_pokemon_habitat wild_pokemon_3_1_water = {
	.frequency = 15, .data = wild_pokemon_3_1_water_entries
};

static wild_pokemon_entry wild_pokemon_3_1_rod_entries[10] = {
	[WILD_POKEMON_DENSITY_OLD_ROD_0_70_PERCENT] = 
		{.level_min = 9, .level_max = 12, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_OLD_ROD_1_30_PERCENT] = 
		{.level_min = 9, .level_max = 13, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_GOOD_ROD_0_60_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_GOOD_ROD_1_20_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_GOOD_ROD_2_20_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_0_40_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_1_40_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_2_15_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_3_4_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_GARADOS},
	[WILD_POKEMON_DENSITY_SUPER_ROD_4_1_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_GARADOS},
};

static wild_pokemon_habitat wild_pokemon_3_1_rod = {
	.frequency = 88, .data = wild_pokemon_3_1_rod_entries
};

static wild_pokemon_entry wild_pokemon_route_9_water_entries[5] = {
	[WILD_POKEMON_DENSITY_WATER_0_60_PERCENT] = 
		{.level_min = 26, .level_max = 32, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_WATER_1_30_PERCENT] = 
		{.level_min = 26, .level_max = 30, .species = POKEMON_QUABBEL},
	[WILD_POKEMON_DENSITY_WATER_2_5_PERCENT] = 
		{.level_min = 26, .level_max = 29, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_WATER_3_4_PERCENT] = 
		{.level_min = 27, .level_max = 33, .species = POKEMON_SEEPER},
	[WILD_POKEMON_DENSITY_WATER_3_1_PERCENT] = 
		{.level_min = 30, .level_max = 34, .species = POKEMON_SEEPER},
};

static wild_pokemon_habitat wild_pokemon_route_9_water = {
	.frequency = 4, .data = wild_pokemon_route_9_water_entries
};

static wild_pokemon_entry wild_pokemon_route_9_rod_entries[10] = {
	[WILD_POKEMON_DENSITY_OLD_ROD_0_70_PERCENT] = 
		{.level_min = 21, .level_max = 24, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_OLD_ROD_1_30_PERCENT] = 
		{.level_min = 21, .level_max = 24, .species = POKEMON_QUABBEL},
	[WILD_POKEMON_DENSITY_GOOD_ROD_0_60_PERCENT] = 
		{.level_min = 32, .level_max = 35, .species = POKEMON_WAILMER},
	[WILD_POKEMON_DENSITY_GOOD_ROD_1_20_PERCENT] = 
		{.level_min = 32, .level_max = 35, .species = POKEMON_KRABBY},
	[WILD_POKEMON_DENSITY_GOOD_ROD_2_20_PERCENT] = 
		{.level_min = 33, .level_max = 36, .species = POKEMON_STERNDU},
	[WILD_POKEMON_DENSITY_SUPER_ROD_0_40_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_SUPER_ROD_1_40_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_KANIVANHA},
	[WILD_POKEMON_DENSITY_SUPER_ROD_2_15_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_TENTOXA},
	[WILD_POKEMON_DENSITY_SUPER_ROD_3_4_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_QUABBEL},
	[WILD_POKEMON_DENSITY_SUPER_ROD_4_1_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_TOHAIDO},
};

static wild_pokemon_habitat wild_pokemon_route_9_rod = {
	.frequency = 75, .data = wild_pokemon_route_9_rod_entries
};

static wild_pokemon_entry wild_pokemon_route_10_water_entries[5] = {
	[WILD_POKEMON_DENSITY_WATER_0_60_PERCENT] = 
		{.level_min = 26, .level_max = 32, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_WATER_1_30_PERCENT] = 
		{.level_min = 26, .level_max = 30, .species = POKEMON_QUABBEL},
	[WILD_POKEMON_DENSITY_WATER_2_5_PERCENT] = 
		{.level_min = 26, .level_max = 29, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_WATER_3_4_PERCENT] = 
		{.level_min = 27, .level_max = 33, .species = POKEMON_WAILMER},
	[WILD_POKEMON_DENSITY_WATER_3_1_PERCENT] = 
		{.level_min = 30, .level_max = 35, .species = POKEMON_TENTOXA},
};

static wild_pokemon_habitat wild_pokemon_route_10_water = {
	.frequency = 4, .data = wild_pokemon_route_10_water_entries
};

static wild_pokemon_entry wild_pokemon_route_10_rod_entries[10] = {
	[WILD_POKEMON_DENSITY_OLD_ROD_0_70_PERCENT] = 
		{.level_min = 21, .level_max = 24, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_OLD_ROD_1_30_PERCENT] = 
		{.level_min = 21, .level_max = 24, .species = POKEMON_QUABBEL},
	[WILD_POKEMON_DENSITY_GOOD_ROD_0_60_PERCENT] = 
		{.level_min = 32, .level_max = 35, .species = POKEMON_WAILMER},
	[WILD_POKEMON_DENSITY_GOOD_ROD_1_20_PERCENT] = 
		{.level_min = 32, .level_max = 35, .species = POKEMON_KRABBY},
	[WILD_POKEMON_DENSITY_GOOD_ROD_2_20_PERCENT] = 
		{.level_min = 33, .level_max = 36, .species = POKEMON_KANIVANHA},
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

static wild_pokemon_habitat wild_pokemon_route_10_rod = {
	.frequency = 75, .data = wild_pokemon_route_10_rod_entries
};

static wild_pokemon_entry wild_pokemon_route_11_water_entries[5] = {
	[WILD_POKEMON_DENSITY_WATER_0_60_PERCENT] = 
		{.level_min = 26, .level_max = 32, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_WATER_1_30_PERCENT] = 
		{.level_min = 26, .level_max = 30, .species = POKEMON_NEBULAK},
	[WILD_POKEMON_DENSITY_WATER_2_5_PERCENT] = 
		{.level_min = 26, .level_max = 29, .species = POKEMON_QUABBEL},
	[WILD_POKEMON_DENSITY_WATER_3_4_PERCENT] = 
		{.level_min = 27, .level_max = 33, .species = POKEMON_QUABBEL},
	[WILD_POKEMON_DENSITY_WATER_3_1_PERCENT] = 
		{.level_min = 30, .level_max = 35, .species = POKEMON_ALPOLLO},
};

static wild_pokemon_habitat wild_pokemon_route_11_water = {
	.frequency = 4, .data = wild_pokemon_route_11_water_entries
};

static wild_pokemon_entry wild_pokemon_route_11_rod_entries[10] = {
	[WILD_POKEMON_DENSITY_OLD_ROD_0_70_PERCENT] = 
		{.level_min = 21, .level_max = 26, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_OLD_ROD_1_30_PERCENT] = 
		{.level_min = 21, .level_max = 26, .species = POKEMON_QUABBEL},
	[WILD_POKEMON_DENSITY_GOOD_ROD_0_60_PERCENT] = 
		{.level_min = 32, .level_max = 35, .species = POKEMON_WAILMER},
	[WILD_POKEMON_DENSITY_GOOD_ROD_1_20_PERCENT] = 
		{.level_min = 32, .level_max = 35, .species = POKEMON_STERNDU},
	[WILD_POKEMON_DENSITY_GOOD_ROD_2_20_PERCENT] = 
		{.level_min = 33, .level_max = 36, .species = POKEMON_KANIVANHA},
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

static wild_pokemon_habitat wild_pokemon_route_11_rod = {
	75, .data = wild_pokemon_route_11_rod_entries
};

static wild_pokemon_entry wild_pokemon_forest_cemetery_grass_entries[12] = {
  [WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] =
    {.level_min = 34, .level_max = 38, .species = POKEMON_NEBULAK},
  [WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] =
    {.level_min = 34, .level_max = 36, .species = POKEMON_PARAGONI},
  [WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] =
    {.level_min = 34, .level_max = 36, .species = POKEMON_ZWIRRLICHT},
  [WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] =
    {.level_min = 34, .level_max = 38, .species = POKEMON_SHUPPET},
  [WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] =
    {.level_min = 34, .level_max = 38, .species = POKEMON_NEBULAK},
  [WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] =
    {.level_min = 34, .level_max = 38, .species = POKEMON_PARAGONI},
  [WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] =
    {.level_min = 34, .level_max = 38, .species = POKEMON_TRAGOSSO},
  [WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] =
    {.level_min = 34, .level_max = 38, .species = POKEMON_TRAGOSSO},
  [WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] =
    {.level_min = 37, .level_max = 39, .species = POKEMON_ALPOLLO},
  [WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] =
    {.level_min = 37, .level_max = 40, .species = POKEMON_TRAGOSSO},
  [WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] =
    {.level_min = 38, .level_max = 40, .species = POKEMON_SHUPPET},
  [WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] =
    {.level_min = 39, .level_max = 42, .species = POKEMON_TROMBORK},
};

static wild_pokemon_habitat wild_pokemon_forest_cemetery_grass = {
  .frequency = 30, .data = wild_pokemon_forest_cemetery_grass_entries
};

static wild_pokemon_entry wild_pokemon_forest_cemetery_other_entries[5] = {
  [WILD_POKEMON_DENSITY_OTHER_0_30_PERCENT] =
    {.level_min = 35, .level_max = 40, .species = POKEMON_PALIMPALIM},
  [WILD_POKEMON_DENSITY_OTHER_1_25_PERCENT] =
    {.level_min = 35, .level_max = 31, .species = POKEMON_TRAUNFUGIL},
  [WILD_POKEMON_DENSITY_OTHER_2_20_PERCENT] =
    {.level_min = 35, .level_max = 30, .species = POKEMON_WEBARAK},
  [WILD_POKEMON_DENSITY_OTHER_3_15_PERCENT] =
    {.level_min = 35, .level_max = 32, .species = POKEMON_WEBARAK},
  [WILD_POKEMON_DENSITY_OTHER_4_10_PERCENT] =
    {.level_min = 38, .level_max = 42, .species = POKEMON_ZWIRRKLOP},
};

static wild_pokemon_habitat wild_pokemon_forest_cemetery_other = {
  .frequency = 128, .data = wild_pokemon_forest_cemetery_other_entries
};

static wild_pokemon_entry wild_pokemon_route_12_east_grass_entries[12] = {
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

static wild_pokemon_habitat wild_pokemon_route_12_east_grass = {
  .frequency = 30, .data = wild_pokemon_route_12_east_grass_entries
};

static wild_pokemon_entry wild_pokemon_route_12_east_other_entries[5] = {
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

static wild_pokemon_habitat wild_pokemon_route_12_east_other = {
  .frequency = 128, .data = wild_pokemon_route_12_east_other_entries
};

static wild_pokemon_entry wild_pokemon_route_12_east_water_entries[5] = {
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


static wild_pokemon_habitat wild_pokemon_route_12_east_water = {
	.frequency = 4, .data = wild_pokemon_route_12_east_water_entries
};

static wild_pokemon_entry wild_pokemon_route_12_east_rod_entries[10] = {
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

static wild_pokemon_habitat wild_pokemon_route_12_east_rod = {
	.frequency = 75, .data = wild_pokemon_route_12_east_rod_entries
};

static wild_pokemon_entry wild_pokemon_route_12_west_grass_entries[12] = {
  [WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] =
    {.level_min = 34, .level_max = 38, .species = POKEMON_OWEI},
  [WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] =
    {.level_min = 34, .level_max = 36, .species = POKEMON_WINGULL},
  [WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] =
    {.level_min = 34, .level_max = 36, .species = POKEMON_STERNDU},
  [WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] =
    {.level_min = 34, .level_max = 38, .species = POKEMON_ENTON},
  [WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] =
    {.level_min = 34, .level_max = 38, .species = POKEMON_SANDAN},
  [WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] =
    {.level_min = 34, .level_max = 38, .species = POKEMON_KRABBY},
  [WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] =
    {.level_min = 34, .level_max = 38, .species = POKEMON_STERNDU},
  [WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] =
    {.level_min = 34, .level_max = 38, .species = POKEMON_MUSCHAS},
  [WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] =
    {.level_min = 37, .level_max = 39, .species = POKEMON_ENTON},
  [WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] =
    {.level_min = 37, .level_max = 40, .species = POKEMON_ENTORON},
  [WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] =
    {.level_min = 38, .level_max = 40, .species = POKEMON_MUSCHAS},
  [WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] =
    {.level_min = 39, .level_max = 41, .species = POKEMON_PELIPPER},
};

static wild_pokemon_habitat wild_pokemon_route_12_west_grass = {
  .frequency = 30, .data = wild_pokemon_route_12_west_grass_entries
};

static wild_pokemon_entry wild_pokemon_route_12_west_other_entries[5] = {
  [WILD_POKEMON_DENSITY_OTHER_0_30_PERCENT] =
    {.level_min = 35, .level_max = 40, .species = POKEMON_AUSTOS},
  [WILD_POKEMON_DENSITY_OTHER_1_25_PERCENT] =
    {.level_min = 35, .level_max = 41, .species = POKEMON_KOKOWEI},
  [WILD_POKEMON_DENSITY_OTHER_2_20_PERCENT] =
    {.level_min = 35, .level_max = 40, .species = POKEMON_KINGLER},
  [WILD_POKEMON_DENSITY_OTHER_3_15_PERCENT] =
    {.level_min = 35, .level_max = 42, .species = POKEMON_KOKOWEI},
  [WILD_POKEMON_DENSITY_OTHER_4_10_PERCENT] =
    {.level_min = 38, .level_max = 42, .species = POKEMON_SANDAMER},
};

static wild_pokemon_habitat wild_pokemon_route_12_west_other = {
  .frequency = 128, .data = wild_pokemon_route_12_west_other_entries
};


static wild_pokemon_entry wild_pokemon_route_12_west_water_entries[5] = {
	[WILD_POKEMON_DENSITY_WATER_0_60_PERCENT] = 
		{.level_min = 37, .level_max = 41, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_WATER_1_30_PERCENT] = 
		{.level_min = 37, .level_max = 41, .species = POKEMON_SEEPER},
	[WILD_POKEMON_DENSITY_WATER_2_5_PERCENT] = 
		{.level_min = 36, .level_max = 40, .species = POKEMON_QUABBEL},
	[WILD_POKEMON_DENSITY_WATER_3_4_PERCENT] = 
		{.level_min = 38, .level_max = 41, .species = POKEMON_WAILMER},
	[WILD_POKEMON_DENSITY_WATER_3_1_PERCENT] = 
		{.level_min = 39, .level_max = 42, .species = POKEMON_SEEMON},
};


static wild_pokemon_habitat wild_pokemon_route_12_west_water = {
	.frequency = 4, .data = wild_pokemon_route_12_west_water_entries
};

static wild_pokemon_entry wild_pokemon_route_12_west_rod_entries[10] = {
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
		{.level_min = 53, .level_max = 55, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_SUPER_ROD_1_40_PERCENT] = 
		{.level_min = 54, .level_max = 56, .species = POKEMON_KANIVANHA},
	[WILD_POKEMON_DENSITY_SUPER_ROD_2_15_PERCENT] = 
		{.level_min = 51, .level_max = 56, .species = POKEMON_TENTOXA},
	[WILD_POKEMON_DENSITY_SUPER_ROD_3_4_PERCENT] = 
		{.level_min = 51, .level_max = 57, .species = POKEMON_TOHAIDO},
	[WILD_POKEMON_DENSITY_SUPER_ROD_4_1_PERCENT] = 
		{.level_min = 55, .level_max = 59, .species = POKEMON_TOHAIDO},
};

static wild_pokemon_habitat wild_pokemon_route_12_west_rod = {
	.frequency = 75, .data = wild_pokemon_route_12_west_rod_entries
};

static wild_pokemon_entry wild_pokemon_route_7_grass_entries[12] = {
  [WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] =
    {.level_min = 32, .level_max = 37, .species = POKEMON_OWEI},
  [WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] =
    {.level_min = 33, .level_max = 36, .species = POKEMON_MARILL},
  [WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] =
    {.level_min = 33, .level_max = 36, .species = POKEMON_WINGULL},
  [WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] =
    {.level_min = 33, .level_max = 37, .species = POKEMON_KREBSCORPS},
  [WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] =
    {.level_min = 34, .level_max = 38, .species = POKEMON_KRABBY},
  [WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] =
    {.level_min = 34, .level_max = 37, .species = POKEMON_PELIPPER},
  [WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] =
    {.level_min = 34, .level_max = 36, .species = POKEMON_MUSCHAS},
  [WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] =
    {.level_min = 34, .level_max = 37, .species = POKEMON_MUSCHAS},
  [WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] =
    {.level_min = 35, .level_max = 37, .species = POKEMON_KREBSCORPS},
  [WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] =
    {.level_min = 35, .level_max = 38, .species = POKEMON_WINGULL},
  [WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] =
    {.level_min = 37, .level_max = 39, .species = POKEMON_KINGLER},
  [WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] =
    {.level_min = 37, .level_max = 39, .species = POKEMON_AUSTOS},
};

static wild_pokemon_habitat wild_pokemon_route_7_grass = {
  .frequency = 30, .data = wild_pokemon_route_7_grass_entries
};

static wild_pokemon_entry wild_pokemon_route_7_other_entries[5] = {
  [WILD_POKEMON_DENSITY_OTHER_0_30_PERCENT] =
    {.level_min = 35, .level_max = 41, .species = POKEMON_AUSTOS},
  [WILD_POKEMON_DENSITY_OTHER_1_25_PERCENT] =
    {.level_min = 35, .level_max = 42, .species = POKEMON_KOKOWEI},
  [WILD_POKEMON_DENSITY_OTHER_2_20_PERCENT] =
    {.level_min = 35, .level_max = 41, .species = POKEMON_AUSTOS},
  [WILD_POKEMON_DENSITY_OTHER_3_15_PERCENT] =
    {.level_min = 35, .level_max = 43, .species = POKEMON_KREBUTACK},
  [WILD_POKEMON_DENSITY_OTHER_4_10_PERCENT] =
    {.level_min = 38, .level_max = 43, .species = POKEMON_KOKOWEI},
};

static wild_pokemon_habitat wild_pokemon_route_7_other = {
  .frequency = 128, .data = wild_pokemon_route_7_other_entries
};


static wild_pokemon_entry wild_pokemon_3_19_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 3, .level_max = 3, .species = POKEMON_FIFFYEN},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 3, .level_max = 3, .species = POKEMON_DARTIRI},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 3, .level_max = 3, .species = POKEMON_FIFFYEN},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 3, .level_max = 3, .species = POKEMON_ZIGZACHS},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 2, .level_max = 2, .species = POKEMON_STARALILI},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 2, .level_max = 2, .species = POKEMON_STARALILI},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 3, .level_max = 3, .species = POKEMON_STARALILI},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 3, .level_max = 3, .species = POKEMON_FIFFYEN},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 3, .level_max = 3, .species = POKEMON_STARALILI},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 4, .level_max = 4, .species = POKEMON_STARALILI},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 5, .level_max = 5, .species = POKEMON_STARALILI},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 4, .level_max = 4, .species = POKEMON_STARALILI},
};

static wild_pokemon_habitat wild_pokemon_3_19_grass = {
	.frequency = 39, .data = wild_pokemon_3_19_grass_entries
};

static wild_pokemon_entry wild_pokemon_3_19_other_entries[5] = {
	[WILD_POKEMON_DENSITY_OTHER_0_30_PERCENT] = 
		{.level_min = 8, .level_max = 10, .species = POKEMON_FUKANO},
	[WILD_POKEMON_DENSITY_OTHER_1_25_PERCENT] = 
		{.level_min = 7, .level_max = 11, .species = POKEMON_NIDORANW},
	[WILD_POKEMON_DENSITY_OTHER_2_20_PERCENT] = 
		{.level_min = 8, .level_max = 11, .species = POKEMON_NIDORANM},
	[WILD_POKEMON_DENSITY_OTHER_3_15_PERCENT] = 
		{.level_min = 7, .level_max = 11, .species = POKEMON_SNUBBULL},
	[WILD_POKEMON_DENSITY_OTHER_4_10_PERCENT] = 
		{.level_min = 8, .level_max = 12, .species = POKEMON_SNUBBULL},
};

static wild_pokemon_habitat wild_pokemon_3_19_other = {
	.frequency = 75, .data = wild_pokemon_3_19_other_entries
};

static wild_pokemon_entry wild_pokemon_3_2_water_entries[5] = {
	[WILD_POKEMON_DENSITY_WATER_0_60_PERCENT] = 
		{.level_min = 23, .level_max = 29, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_WATER_1_30_PERCENT] = 
		{.level_min = 24, .level_max = 30, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_WATER_2_5_PERCENT] = 
		{.level_min = 25, .level_max = 31, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_WATER_3_4_PERCENT] = 
		{.level_min = 30, .level_max = 33, .species = POKEMON_PELIPPER},
	[WILD_POKEMON_DENSITY_WATER_3_1_PERCENT] = 
		{.level_min = 30, .level_max = 33, .species = POKEMON_PELIPPER},
};

static wild_pokemon_habitat wild_pokemon_3_2_water = {
	.frequency = 5, .data = wild_pokemon_3_2_water_entries
};

static wild_pokemon_entry wild_pokemon_3_2_rod_entries[10] = {
	[WILD_POKEMON_DENSITY_OLD_ROD_0_70_PERCENT] = 
		{.level_min = 6, .level_max = 12, .species = POKEMON_QUABBEL},
	[WILD_POKEMON_DENSITY_OLD_ROD_1_30_PERCENT] = 
		{.level_min = 6, .level_max = 12, .species = POKEMON_QUABBEL},
	[WILD_POKEMON_DENSITY_GOOD_ROD_0_60_PERCENT] = 
		{.level_min = 6, .level_max = 12, .species = POKEMON_QUABBEL},
	[WILD_POKEMON_DENSITY_GOOD_ROD_1_20_PERCENT] = 
		{.level_min = 6, .level_max = 12, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_GOOD_ROD_2_20_PERCENT] = 
		{.level_min = 6, .level_max = 12, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_SUPER_ROD_0_40_PERCENT] = 
		{.level_min = 6, .level_max = 12, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_SUPER_ROD_1_40_PERCENT] = 
		{.level_min = 1, .level_max = 1, .species = POKEMON_APOQUALLYP},
	[WILD_POKEMON_DENSITY_SUPER_ROD_2_15_PERCENT] = 
		{.level_min = 1, .level_max = 1, .species = POKEMON_APOQUALLYP},
	[WILD_POKEMON_DENSITY_SUPER_ROD_3_4_PERCENT] = 
		{.level_min = 1, .level_max = 1, .species = POKEMON_TENTOXA},
	[WILD_POKEMON_DENSITY_SUPER_ROD_4_1_PERCENT] = 
		{.level_min = 1, .level_max = 1, .species = POKEMON_TENTOXA},
};

static wild_pokemon_habitat wild_pokemon_3_2_rod = {
	.frequency = 124, .data = wild_pokemon_3_2_rod_entries
};

static wild_pokemon_entry wild_pokemon_3_21_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 17, .level_max = 19, .species = POKEMON_KNACKLION},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 17, .level_max = 19, .species = POKEMON_PUPPANCE},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 17, .level_max = 19, .species = POKEMON_SANDAN},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 17, .level_max = 19, .species = POKEMON_DIGDA},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 17, .level_max = 19, .species = POKEMON_KNACKLION},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 17, .level_max = 19, .species = POKEMON_DIGDA},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 17, .level_max = 19, .species = POKEMON_SANDAN},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 17, .level_max = 19, .species = POKEMON_PUPPANCE},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 17, .level_max = 19, .species = POKEMON_DIGDA},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 17, .level_max = 19, .species = POKEMON_DIGDA},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 17, .level_max = 19, .species = POKEMON_SANDAN},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 19, .level_max = 22, .species = POKEMON_SANDAN},
};

static wild_pokemon_habitat wild_pokemon_3_21_grass = {
	.frequency = 17, .data = wild_pokemon_3_21_grass_entries
};

static wild_pokemon_entry wild_pokemon_3_21_other_entries[5] = {
	[WILD_POKEMON_DENSITY_OTHER_0_30_PERCENT] = 
		{.level_min = 16, .level_max = 19, .species = POKEMON_TUSKA},
	[WILD_POKEMON_DENSITY_OTHER_1_25_PERCENT] = 
		{.level_min = 16, .level_max = 20, .species = POKEMON_TUSKA},
	[WILD_POKEMON_DENSITY_OTHER_2_20_PERCENT] = 
		{.level_min = 16, .level_max = 21, .species = POKEMON_TUSKA},
	[WILD_POKEMON_DENSITY_OTHER_3_15_PERCENT] = 
		{.level_min = 18, .level_max = 22, .species = POKEMON_SANDAMER},
	[WILD_POKEMON_DENSITY_OTHER_4_10_PERCENT] = 
		{.level_min = 25, .level_max = 25, .species = POKEMON_SANDAMER},
};

static wild_pokemon_habitat wild_pokemon_3_21_other = {
	.frequency = 154, .data = wild_pokemon_3_21_other_entries
};

static wild_pokemon_entry wild_pokemon_3_22_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 24, .level_max = 27, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 24, .level_max = 27, .species = POKEMON_MACHOLLO},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 24, .level_max = 28, .species = POKEMON_MEDITIE},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 24, .level_max = 27, .species = POKEMON_LOTURZEL},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 24, .level_max = 28, .species = POKEMON_MARILL},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 24, .level_max = 28, .species = POKEMON_MACHOLLO},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 25, .level_max = 29, .species = POKEMON_MEDITIE},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 24, .level_max = 28, .species = POKEMON_MEDITIE},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 25, .level_max = 28, .species = POKEMON_LOMBRERO},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 26, .level_max = 29, .species = POKEMON_LOMBRERO},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 27, .level_max = 30, .species = POKEMON_AZUMARILL},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 28, .level_max = 30, .species = POKEMON_MASCHOCK},
};

static wild_pokemon_habitat wild_pokemon_3_22_grass = {
	.frequency = 21, .data = wild_pokemon_3_22_grass_entries
};

static wild_pokemon_entry wild_pokemon_3_22_water_entries[5] = {
	[WILD_POKEMON_DENSITY_WATER_0_60_PERCENT] = 
		{.level_min = 5, .level_max = 10, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_WATER_1_30_PERCENT] = 
		{.level_min = 10, .level_max = 20, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_WATER_2_5_PERCENT] = 
		{.level_min = 20, .level_max = 30, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_WATER_3_4_PERCENT] = 
		{.level_min = 30, .level_max = 35, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_WATER_3_1_PERCENT] = 
		{.level_min = 30, .level_max = 35, .species = POKEMON_TENTACHA},
};

static wild_pokemon_habitat wild_pokemon_3_22_water = {
	.frequency = 2, .data = wild_pokemon_3_22_water_entries
};

static wild_pokemon_entry wild_pokemon_3_22_other_entries[5] = {
	[WILD_POKEMON_DENSITY_OTHER_0_30_PERCENT] = 
		{.level_min = 23, .level_max = 26, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_OTHER_1_25_PERCENT] = 
		{.level_min = 21, .level_max = 26, .species = POKEMON_MARILL},
	[WILD_POKEMON_DENSITY_OTHER_2_20_PERCENT] = 
		{.level_min = 23, .level_max = 25, .species = POKEMON_GEHWEIHER},
	[WILD_POKEMON_DENSITY_OTHER_3_15_PERCENT] = 
		{.level_min = 23, .level_max = 25, .species = POKEMON_PANDIR},
	[WILD_POKEMON_DENSITY_OTHER_4_10_PERCENT] = 
		{.level_min = 28, .level_max = 28, .species = POKEMON_PANDIR},
};

static wild_pokemon_habitat wild_pokemon_3_22_other = {
	.frequency = 159, .data = wild_pokemon_3_22_other_entries
};

static wild_pokemon_entry wild_pokemon_3_22_rod_entries[10] = {
	[WILD_POKEMON_DENSITY_OLD_ROD_0_70_PERCENT] = 
		{.level_min = 5, .level_max = 5, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_OLD_ROD_1_30_PERCENT] = 
		{.level_min = 5, .level_max = 5, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_GOOD_ROD_0_60_PERCENT] = 
		{.level_min = 5, .level_max = 15, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_GOOD_ROD_1_20_PERCENT] = 
		{.level_min = 5, .level_max = 15, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_GOOD_ROD_2_20_PERCENT] = 
		{.level_min = 5, .level_max = 15, .species = POKEMON_KRABBY},
	[WILD_POKEMON_DENSITY_SUPER_ROD_0_40_PERCENT] = 
		{.level_min = 15, .level_max = 25, .species = POKEMON_KRABBY},
	[WILD_POKEMON_DENSITY_SUPER_ROD_1_40_PERCENT] = 
		{.level_min = 15, .level_max = 25, .species = POKEMON_KRABBY},
	[WILD_POKEMON_DENSITY_SUPER_ROD_2_15_PERCENT] = 
		{.level_min = 15, .level_max = 25, .species = POKEMON_KINGLER},
	[WILD_POKEMON_DENSITY_SUPER_ROD_3_4_PERCENT] = 
		{.level_min = 25, .level_max = 35, .species = POKEMON_GARADOS},
	[WILD_POKEMON_DENSITY_SUPER_ROD_4_1_PERCENT] = 
		{.level_min = 25, .level_max = 35, .species = POKEMON_GARADOS},
};

static wild_pokemon_habitat wild_pokemon_3_22_rod = {
	.frequency = 20, .data = wild_pokemon_3_22_rod_entries
};

static wild_pokemon_entry wild_pokemon_3_23_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 30, .level_max = 33, .species = POKEMON_SCHWALBINI},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 30, .level_max = 33, .species = POKEMON_WABLU},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 30, .level_max = 33, .species = POKEMON_MEDITIE},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 30, .level_max = 33, .species = POKEMON_WABLU},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 30, .level_max = 33, .species = POKEMON_WABLU},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 31, .level_max = 33, .species = POKEMON_WAATY},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 31, .level_max = 34, .species = POKEMON_MEDITIE},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 31, .level_max = 34, .species = POKEMON_WABLU},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 31, .level_max = 34, .species = POKEMON_SPOINK},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 32, .level_max = 34, .species = POKEMON_SPOINK},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 31, .level_max = 34, .species = POKEMON_SPOINK},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 32, .level_max = 35, .species = POKEMON_GROINK},
};

static wild_pokemon_habitat wild_pokemon_3_23_grass = {
	.frequency = 21, .data = wild_pokemon_3_23_grass_entries
};

static wild_pokemon_entry wild_pokemon_3_23_other_entries[5] = {
	[WILD_POKEMON_DENSITY_OTHER_0_30_PERCENT] = 
		{.level_min = 25, .level_max = 28, .species = POKEMON_SNUBBULL},
	[WILD_POKEMON_DENSITY_OTHER_1_25_PERCENT] = 
		{.level_min = 26, .level_max = 28, .species = POKEMON_SPOINK},
	[WILD_POKEMON_DENSITY_OTHER_2_20_PERCENT] = 
		{.level_min = 28, .level_max = 32, .species = POKEMON_WABLU},
	[WILD_POKEMON_DENSITY_OTHER_3_15_PERCENT] = 
		{.level_min = 29, .level_max = 32, .species = POKEMON_SPOINK},
	[WILD_POKEMON_DENSITY_OTHER_4_10_PERCENT] = 
		{.level_min = 32, .level_max = 34, .species = POKEMON_AMPHAROS},
};

static wild_pokemon_habitat wild_pokemon_3_23_other = {
	.frequency = 200, .data = wild_pokemon_3_23_other_entries
};

static wild_pokemon_entry wild_pokemon_route_5_water_entries[5] = {
	[WILD_POKEMON_DENSITY_WATER_0_60_PERCENT] = 
		{.level_min = 5, .level_max = 10, .species = POKEMON_LOTURZEL},
	[WILD_POKEMON_DENSITY_WATER_1_30_PERCENT] = 
		{.level_min = 10, .level_max = 20, .species = POKEMON_LOTURZEL},
	[WILD_POKEMON_DENSITY_WATER_2_5_PERCENT] = 
		{.level_min = 20, .level_max = 30, .species = POKEMON_MARILL},
	[WILD_POKEMON_DENSITY_WATER_3_4_PERCENT] = 
		{.level_min = 30, .level_max = 35, .species = POKEMON_ENTON},
	[WILD_POKEMON_DENSITY_WATER_3_1_PERCENT] = 
		{.level_min = 30, .level_max = 35, .species = POKEMON_ENTORON},
};

static wild_pokemon_habitat wild_pokemon_route_5_water = {
	.frequency = 2, .data = wild_pokemon_route_5_water_entries
};

static wild_pokemon_entry wild_pokemon_route_5_rod_entries[10] = {
	[WILD_POKEMON_DENSITY_OLD_ROD_0_70_PERCENT] = 
		{.level_min = 5, .level_max = 5, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_OLD_ROD_1_30_PERCENT] = 
		{.level_min = 5, .level_max = 5, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_GOOD_ROD_0_60_PERCENT] = 
		{.level_min = 35, .level_max = 40, .species = POKEMON_FLEGMON},
	[WILD_POKEMON_DENSITY_GOOD_ROD_1_20_PERCENT] = 
		{.level_min = 35, .level_max = 40, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_GOOD_ROD_2_20_PERCENT] = 
		{.level_min = 35, .level_max = 40, .species = POKEMON_FLEGMON},
	[WILD_POKEMON_DENSITY_SUPER_ROD_0_40_PERCENT] = 
		{.level_min = 35, .level_max = 40, .species = POKEMON_FLEGMON},
	[WILD_POKEMON_DENSITY_SUPER_ROD_1_40_PERCENT] = 
		{.level_min = 35, .level_max = 40, .species = POKEMON_FLEGMON},
	[WILD_POKEMON_DENSITY_SUPER_ROD_2_15_PERCENT] = 
		{.level_min = 35, .level_max = 40, .species = POKEMON_FLEGMON},
	[WILD_POKEMON_DENSITY_SUPER_ROD_3_4_PERCENT] = 
		{.level_min = 25, .level_max = 35, .species = POKEMON_FLEGMON},
	[WILD_POKEMON_DENSITY_SUPER_ROD_4_1_PERCENT] = 
		{.level_min = 25, .level_max = 35, .species = POKEMON_GARADOS},
};

static wild_pokemon_habitat wild_pokemon_route_5_rod = {
	.frequency = 20, .data = wild_pokemon_route_5_rod_entries
};

static wild_pokemon_entry wild_pokemon_3_24_water_entries[5] = {
	[WILD_POKEMON_DENSITY_WATER_0_60_PERCENT] = 
		{.level_min = 25, .level_max = 32, .species = POKEMON_ENTON},
	[WILD_POKEMON_DENSITY_WATER_1_30_PERCENT] = 
		{.level_min = 25, .level_max = 32, .species = POKEMON_MARILL},
	[WILD_POKEMON_DENSITY_WATER_2_5_PERCENT] = 
		{.level_min = 25, .level_max = 30, .species = POKEMON_ENTON},
	[WILD_POKEMON_DENSITY_WATER_3_4_PERCENT] = 
		{.level_min = 30, .level_max = 35, .species = POKEMON_ENTON},
	[WILD_POKEMON_DENSITY_WATER_3_1_PERCENT] = 
		{.level_min = 30, .level_max = 35, .species = POKEMON_ENTON},
};

static wild_pokemon_habitat wild_pokemon_3_24_water = {
	.frequency = 2, .data = wild_pokemon_3_24_water_entries
};

static wild_pokemon_entry wild_pokemon_3_24_rod_entries[10] = {
	[WILD_POKEMON_DENSITY_OLD_ROD_0_70_PERCENT] = 
		{.level_min = 5, .level_max = 5, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_OLD_ROD_1_30_PERCENT] = 
		{.level_min = 5, .level_max = 5, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_GOOD_ROD_0_60_PERCENT] = 
		{.level_min = 5, .level_max = 15, .species = POKEMON_KREBSCORPS},
	[WILD_POKEMON_DENSITY_GOOD_ROD_1_20_PERCENT] = 
		{.level_min = 5, .level_max = 15, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_GOOD_ROD_2_20_PERCENT] = 
		{.level_min = 5, .level_max = 15, .species = POKEMON_QUABBEL},
	[WILD_POKEMON_DENSITY_SUPER_ROD_0_40_PERCENT] = 
		{.level_min = 15, .level_max = 25, .species = POKEMON_KREBSCORPS},
	[WILD_POKEMON_DENSITY_SUPER_ROD_1_40_PERCENT] = 
		{.level_min = 20, .level_max = 30, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_2_15_PERCENT] = 
		{.level_min = 15, .level_max = 25, .species = POKEMON_GARADOS},
	[WILD_POKEMON_DENSITY_SUPER_ROD_3_4_PERCENT] = 
		{.level_min = 15, .level_max = 25, .species = POKEMON_ENTON},
	[WILD_POKEMON_DENSITY_SUPER_ROD_4_1_PERCENT] = 
		{.level_min = 25, .level_max = 35, .species = POKEMON_ENTON},
};

static wild_pokemon_habitat wild_pokemon_3_24_rod = {
	.frequency = 20, .data = wild_pokemon_3_24_rod_entries
};

static wild_pokemon_entry wild_pokemon_3_3_water_entries[5] = {
	[WILD_POKEMON_DENSITY_WATER_0_60_PERCENT] = 
		{.level_min = 30, .level_max = 30, .species = POKEMON_SEEPER},
	[WILD_POKEMON_DENSITY_WATER_1_30_PERCENT] = 
		{.level_min = 30, .level_max = 30, .species = POKEMON_SEEPER},
	[WILD_POKEMON_DENSITY_WATER_2_5_PERCENT] = 
		{.level_min = 30, .level_max = 30, .species = POKEMON_SEEPER},
	[WILD_POKEMON_DENSITY_WATER_3_4_PERCENT] = 
		{.level_min = 30, .level_max = 35, .species = POKEMON_SEEMON},
	[WILD_POKEMON_DENSITY_WATER_3_1_PERCENT] = 
		{.level_min = 32, .level_max = 35, .species = POKEMON_SEEDRAKING},
};

static wild_pokemon_habitat wild_pokemon_3_3_water = {
	.frequency = 17, .data = wild_pokemon_3_3_water_entries
};

static wild_pokemon_entry wild_pokemon_3_3_rod_entries[10] = {
	[WILD_POKEMON_DENSITY_OLD_ROD_0_70_PERCENT] = 
		{.level_min = 13, .level_max = 16, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_OLD_ROD_1_30_PERCENT] = 
		{.level_min = 13, .level_max = 16, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_GOOD_ROD_0_60_PERCENT] = 
		{.level_min = 5, .level_max = 15, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_GOOD_ROD_1_20_PERCENT] = 
		{.level_min = 5, .level_max = 15, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_GOOD_ROD_2_20_PERCENT] = 
		{.level_min = 5, .level_max = 15, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_0_40_PERCENT] = 
		{.level_min = 15, .level_max = 25, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_1_40_PERCENT] = 
		{.level_min = 15, .level_max = 25, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_2_15_PERCENT] = 
		{.level_min = 15, .level_max = 25, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_3_4_PERCENT] = 
		{.level_min = 25, .level_max = 35, .species = POKEMON_GARADOS},
	[WILD_POKEMON_DENSITY_SUPER_ROD_4_1_PERCENT] = 
		{.level_min = 25, .level_max = 35, .species = POKEMON_GARADOS},
};

static wild_pokemon_habitat wild_pokemon_3_3_rod = {
	.frequency = 10, .data = wild_pokemon_3_3_rod_entries
};

static wild_pokemon_entry wild_pokemon_3_4_water_entries[5] = {
	[WILD_POKEMON_DENSITY_WATER_0_60_PERCENT] = 
		{.level_min = 30, .level_max = 30, .species = POKEMON_MARILL},
	[WILD_POKEMON_DENSITY_WATER_1_30_PERCENT] = 
		{.level_min = 30, .level_max = 30, .species = POKEMON_KANIVANHA},
	[WILD_POKEMON_DENSITY_WATER_2_5_PERCENT] = 
		{.level_min = 30, .level_max = 30, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_WATER_3_4_PERCENT] = 
		{.level_min = 35, .level_max = 35, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_WATER_3_1_PERCENT] = 
		{.level_min = 30, .level_max = 35, .species = POKEMON_TENTACHA},
};

static wild_pokemon_habitat wild_pokemon_3_4_water = {
	.frequency = 13, .data = wild_pokemon_3_4_water_entries
};

static wild_pokemon_entry wild_pokemon_3_41_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 5, .level_max = 7, .species = POKEMON_FRIZELBLIZ},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 5, .level_max = 7, .species = POKEMON_TRASLA},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 5, .level_max = 7, .species = POKEMON_WAUMPEL},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 5, .level_max = 7, .species = POKEMON_ABRA},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 5, .level_max = 7, .species = POKEMON_KOKUNA},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 5, .level_max = 7, .species = POKEMON_HORNLIU},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 5, .level_max = 7, .species = POKEMON_MENKI},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 5, .level_max = 7, .species = POKEMON_ABRA},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 5, .level_max = 7, .species = POKEMON_MENKI},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 5, .level_max = 7, .species = POKEMON_MENKI},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 5, .level_max = 7, .species = POKEMON_MENKI},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 10, .level_max = 10, .species = POKEMON_BIBOR},
};

static wild_pokemon_habitat wild_pokemon_3_41_grass = {
	.frequency = 16, .data = wild_pokemon_3_41_grass_entries
};

static wild_pokemon_entry wild_pokemon_3_41_water_entries[5] = {
	[WILD_POKEMON_DENSITY_WATER_0_60_PERCENT] = 
		{.level_min = 20, .level_max = 25, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_WATER_1_30_PERCENT] = 
		{.level_min = 20, .level_max = 25, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_WATER_2_5_PERCENT] = 
		{.level_min = 25, .level_max = 30, .species = POKEMON_MARILL},
	[WILD_POKEMON_DENSITY_WATER_3_4_PERCENT] = 
		{.level_min = 30, .level_max = 35, .species = POKEMON_MARILL},
	[WILD_POKEMON_DENSITY_WATER_3_1_PERCENT] = 
		{.level_min = 30, .level_max = 35, .species = POKEMON_AZUMARILL},
};

static wild_pokemon_habitat wild_pokemon_3_41_water = {
	.frequency = 7, .data = wild_pokemon_3_41_water_entries
};

static wild_pokemon_entry wild_pokemon_3_41_other_entries[5] = {
	[WILD_POKEMON_DENSITY_OTHER_0_30_PERCENT] = 
		{.level_min = 9, .level_max = 12, .species = POKEMON_VOLTOBAL},
	[WILD_POKEMON_DENSITY_OTHER_1_25_PERCENT] = 
		{.level_min = 9, .level_max = 12, .species = POKEMON_ZIGZACHS},
	[WILD_POKEMON_DENSITY_OTHER_2_20_PERCENT] = 
		{.level_min = 10, .level_max = 14, .species = POKEMON_SAMURZEL},
	[WILD_POKEMON_DENSITY_OTHER_3_15_PERCENT] = 
		{.level_min = 10, .level_max = 14, .species = POKEMON_SAMURZEL},
	[WILD_POKEMON_DENSITY_OTHER_4_10_PERCENT] = 
		{.level_min = 10, .level_max = 15, .species = POKEMON_SAMURZEL},
};

static wild_pokemon_habitat wild_pokemon_3_41_other = {
	.frequency = 151, .data = wild_pokemon_3_41_other_entries
};

static wild_pokemon_entry wild_pokemon_3_41_rod_entries[10] = {
	[WILD_POKEMON_DENSITY_OLD_ROD_0_70_PERCENT] = 
		{.level_min = 9, .level_max = 11, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_OLD_ROD_1_30_PERCENT] = 
		{.level_min = 9, .level_max = 11, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_GOOD_ROD_0_60_PERCENT] = 
		{.level_min = 25, .level_max = 35, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_GOOD_ROD_1_20_PERCENT] = 
		{.level_min = 25, .level_max = 35, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_GOOD_ROD_2_20_PERCENT] = 
		{.level_min = 25, .level_max = 35, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_0_40_PERCENT] = 
		{.level_min = 25, .level_max = 35, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_1_40_PERCENT] = 
		{.level_min = 45, .level_max = 50, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_SUPER_ROD_2_15_PERCENT] = 
		{.level_min = 45, .level_max = 50, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_3_4_PERCENT] = 
		{.level_min = 45, .level_max = 50, .species = POKEMON_TENTOXA},
	[WILD_POKEMON_DENSITY_SUPER_ROD_4_1_PERCENT] = 
		{.level_min = 45, .level_max = 55, .species = POKEMON_GARADOS},
};

static wild_pokemon_habitat wild_pokemon_3_41_rod = {
	.frequency = 49, .data = wild_pokemon_3_41_rod_entries
};

static wild_pokemon_entry wild_pokemon_3_57_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 2, .level_max = 3, .species = POKEMON_FLABEBE},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 2, .level_max = 3, .species = POKEMON_FIFFYEN},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 2, .level_max = 3, .species = POKEMON_ZIGZACHS},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 3, .level_max = 3, .species = POKEMON_FLABEBE},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 3, .level_max = 3, .species = POKEMON_FIFFYEN},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 3, .level_max = 3, .species = POKEMON_ZIGZACHS},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 3, .level_max = 3, .species = POKEMON_FLABEBE},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 3, .level_max = 3, .species = POKEMON_FIFFYEN},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 3, .level_max = 3, .species = POKEMON_ZIGZACHS},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 3, .level_max = 4, .species = POKEMON_FLABEBE},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 3, .level_max = 4, .species = POKEMON_FIFFYEN},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 3, .level_max = 4, .species = POKEMON_ZIGZACHS},
};

static wild_pokemon_habitat wild_pokemon_3_57_grass = {
	.frequency = 21, .data = wild_pokemon_3_57_grass_entries
};

static wild_pokemon_entry wild_pokemon_3_57_water_entries[5] = {
	[WILD_POKEMON_DENSITY_WATER_0_60_PERCENT] = 
		{.level_min = 5, .level_max = 35, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_WATER_1_30_PERCENT] = 
		{.level_min = 5, .level_max = 15, .species = POKEMON_QUABBEL},
	[WILD_POKEMON_DENSITY_WATER_2_5_PERCENT] = 
		{.level_min = 30, .level_max = 35, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_WATER_3_4_PERCENT] = 
		{.level_min = 30, .level_max = 35, .species = POKEMON_TENTOXA},
	[WILD_POKEMON_DENSITY_WATER_3_1_PERCENT] = 
		{.level_min = 30, .level_max = 35, .species = POKEMON_TENTOXA},
};

static wild_pokemon_habitat wild_pokemon_3_57_water = {
	.frequency = 6, .data = wild_pokemon_3_57_water_entries
};

static wild_pokemon_entry wild_pokemon_3_57_other_entries[5] = {
	[WILD_POKEMON_DENSITY_OTHER_0_30_PERCENT] = 
		{.level_min = 9, .level_max = 11, .species = POKEMON_ABRA},
	[WILD_POKEMON_DENSITY_OTHER_1_25_PERCENT] = 
		{.level_min = 7, .level_max = 11, .species = POKEMON_HORNLIU},
	[WILD_POKEMON_DENSITY_OTHER_2_20_PERCENT] = 
		{.level_min = 8, .level_max = 11, .species = POKEMON_ABRA},
	[WILD_POKEMON_DENSITY_OTHER_3_15_PERCENT] = 
		{.level_min = 8, .level_max = 11, .species = POKEMON_WATTZAPF},
	[WILD_POKEMON_DENSITY_OTHER_4_10_PERCENT] = 
		{.level_min = 9, .level_max = 12, .species = POKEMON_WATTZAPF},
};

static wild_pokemon_habitat wild_pokemon_3_57_other = {
	.frequency = 75, .data = wild_pokemon_3_57_other_entries
};

static wild_pokemon_entry wild_pokemon_3_57_rod_entries[10] = {
	[WILD_POKEMON_DENSITY_OLD_ROD_0_70_PERCENT] = 
		{.level_min = 5, .level_max = 5, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_OLD_ROD_1_30_PERCENT] = 
		{.level_min = 5, .level_max = 5, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_GOOD_ROD_0_60_PERCENT] = 
		{.level_min = 5, .level_max = 15, .species = POKEMON_SEEPER},
	[WILD_POKEMON_DENSITY_GOOD_ROD_1_20_PERCENT] = 
		{.level_min = 5, .level_max = 15, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_GOOD_ROD_2_20_PERCENT] = 
		{.level_min = 5, .level_max = 15, .species = POKEMON_SEEPER},
	[WILD_POKEMON_DENSITY_SUPER_ROD_0_40_PERCENT] = 
		{.level_min = 15, .level_max = 25, .species = POKEMON_SEEPER},
	[WILD_POKEMON_DENSITY_SUPER_ROD_1_40_PERCENT] = 
		{.level_min = 15, .level_max = 25, .species = POKEMON_SEEPER},
	[WILD_POKEMON_DENSITY_SUPER_ROD_2_15_PERCENT] = 
		{.level_min = 15, .level_max = 25, .species = POKEMON_GARADOS},
	[WILD_POKEMON_DENSITY_SUPER_ROD_3_4_PERCENT] = 
		{.level_min = 25, .level_max = 35, .species = POKEMON_SEEMON},
	[WILD_POKEMON_DENSITY_SUPER_ROD_4_1_PERCENT] = 
		{.level_min = 35, .level_max = 40, .species = POKEMON_SEEPER},
};

static wild_pokemon_habitat wild_pokemon_3_57_rod = {
	.frequency = 20, .data = wild_pokemon_3_57_rod_entries
};


static wild_pokemon_entry wild_pokemon_3_67_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 19, .level_max = 21, .species = POKEMON_DIGDA},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 19, .level_max = 22, .species = POKEMON_ZUBAT},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 19, .level_max = 23, .species = POKEMON_MACHOLLO},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 19, .level_max = 23, .species = POKEMON_DIGDA},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 19, .level_max = 23, .species = POKEMON_ZUBAT},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 19, .level_max = 23, .species = POKEMON_MACHOLLO},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 19, .level_max = 23, .species = POKEMON_DIGDA},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 19, .level_max = 23, .species = POKEMON_ZUBAT},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 19, .level_max = 23, .species = POKEMON_MACHOLLO},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 19, .level_max = 23, .species = POKEMON_DIGDA},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 20, .level_max = 24, .species = POKEMON_ZUBAT},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 24, .level_max = 26, .species = POKEMON_MACHOLLO},
};

static wild_pokemon_habitat wild_pokemon_3_67_grass = {
	.frequency = 3, .data = wild_pokemon_3_67_grass_entries
};

static wild_pokemon_entry wild_pokemon_3_67_water_entries[5] = {
	[WILD_POKEMON_DENSITY_WATER_0_60_PERCENT] = 
		{.level_min = 35, .level_max = 35, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_WATER_1_30_PERCENT] = 
		{.level_min = 35, .level_max = 35, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_WATER_2_5_PERCENT] = 
		{.level_min = 35, .level_max = 35, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_WATER_3_4_PERCENT] = 
		{.level_min = 35, .level_max = 35, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_WATER_3_1_PERCENT] = 
		{.level_min = 35, .level_max = 35, .species = POKEMON_TENTOXA},
};

static wild_pokemon_habitat wild_pokemon_3_67_water = {
	.frequency = 15, .data = wild_pokemon_3_67_water_entries
};

static wild_pokemon_entry wild_pokemon_3_67_rod_entries[10] = {
	[WILD_POKEMON_DENSITY_OLD_ROD_0_70_PERCENT] = 
		{.level_min = 20, .level_max = 20, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_OLD_ROD_1_30_PERCENT] = 
		{.level_min = 20, .level_max = 20, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_GOOD_ROD_0_60_PERCENT] = 
		{.level_min = 40, .level_max = 40, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_GOOD_ROD_1_20_PERCENT] = 
		{.level_min = 40, .level_max = 40, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_GOOD_ROD_2_20_PERCENT] = 
		{.level_min = 40, .level_max = 40, .species = POKEMON_TENTOXA},
	[WILD_POKEMON_DENSITY_SUPER_ROD_0_40_PERCENT] = 
		{.level_min = 40, .level_max = 40, .species = POKEMON_TENTOXA},
	[WILD_POKEMON_DENSITY_SUPER_ROD_1_40_PERCENT] = 
		{.level_min = 40, .level_max = 40, .species = POKEMON_TENTOXA},
	[WILD_POKEMON_DENSITY_SUPER_ROD_2_15_PERCENT] = 
		{.level_min = 50, .level_max = 50, .species = POKEMON_TENTOXA},
	[WILD_POKEMON_DENSITY_SUPER_ROD_3_4_PERCENT] = 
		{.level_min = 50, .level_max = 50, .species = POKEMON_TENTOXA},
	[WILD_POKEMON_DENSITY_SUPER_ROD_4_1_PERCENT] = 
		{.level_min = 50, .level_max = 50, .species = POKEMON_TENTOXA},
};

static wild_pokemon_habitat wild_pokemon_3_67_rod = {
	.frequency = 6, .data = wild_pokemon_3_67_rod_entries
};

static wild_pokemon_entry wild_pokemon_3_7_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 4, .level_max = 7, .species = POKEMON_KNOFENSA},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 4, .level_max = 7, .species = POKEMON_NIDORANW},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 4, .level_max = 7, .species = POKEMON_FLABEBE},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 4, .level_max = 7, .species = POKEMON_NIDORANM},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 4, .level_max = 7, .species = POKEMON_ENECO},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 4, .level_max = 7, .species = POKEMON_NIDORANW},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 5, .level_max = 7, .species = POKEMON_NIDORANM},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 5, .level_max = 7, .species = POKEMON_NIDORANM},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 6, .level_max = 7, .species = POKEMON_ENECO},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 6, .level_max = 7, .species = POKEMON_KNOFENSA},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 8, .level_max = 8, .species = POKEMON_NIDORANW},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 8, .level_max = 8, .species = POKEMON_NIDORANM},
};

static wild_pokemon_habitat wild_pokemon_3_7_grass = {
	.frequency = 24, .data = wild_pokemon_3_7_grass_entries
};

static wild_pokemon_entry wild_pokemon_3_7_other_entries[5] = {
	[WILD_POKEMON_DENSITY_OTHER_0_30_PERCENT] = 
		{.level_min = 7, .level_max = 9, .species = POKEMON_TANNZA},
	[WILD_POKEMON_DENSITY_OTHER_1_25_PERCENT] = 
		{.level_min = 7, .level_max = 9, .species = POKEMON_SAMURZEL},
	[WILD_POKEMON_DENSITY_OTHER_2_20_PERCENT] = 
		{.level_min = 7, .level_max = 9, .species = POKEMON_BUMMELZ},
	[WILD_POKEMON_DENSITY_OTHER_3_15_PERCENT] = 
		{.level_min = 7, .level_max = 9, .species = POKEMON_TANNZA},
	[WILD_POKEMON_DENSITY_OTHER_4_10_PERCENT] = 
		{.level_min = 10, .level_max = 11, .species = POKEMON_SAMURZEL},
};

static wild_pokemon_habitat wild_pokemon_3_7_other = {
	.frequency = 130, .data = wild_pokemon_3_7_other_entries
};

static wild_pokemon_entry wild_pokemon_3_70_grass_entries[12] = {
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

static wild_pokemon_habitat wild_pokemon_3_70_grass = {
	.frequency = 9, .data = wild_pokemon_3_70_grass_entries
};

static wild_pokemon_entry wild_pokemon_3_74_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 13, .level_max = 16, .species = POKEMON_PONITA},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 13, .level_max = 16, .species = POKEMON_MAEHIKEL},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 13, .level_max = 16, .species = POKEMON_MYRAPLA},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 13, .level_max = 16, .species = POKEMON_RIHORN},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 14, .level_max = 16, .species = POKEMON_PONITA},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 14, .level_max = 16, .species = POKEMON_MAEHIKEL},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 14, .level_max = 16, .species = POKEMON_PONITA},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 14, .level_max = 16, .species = POKEMON_RIHORN},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 15, .level_max = 17, .species = POKEMON_MAEHIKEL},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 15, .level_max = 17, .species = POKEMON_TAUROS},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 15, .level_max = 17, .species = POKEMON_TAUROS},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 18, .level_max = 18, .species = POKEMON_TAUROS},
};

static wild_pokemon_habitat wild_pokemon_3_74_grass = {
	.frequency = 23, .data = wild_pokemon_3_74_grass_entries
};

static wild_pokemon_entry wild_pokemon_3_74_other_entries[5] = {
	[WILD_POKEMON_DENSITY_OTHER_0_30_PERCENT] = 
		{.level_min = 13, .level_max = 17, .species = POKEMON_PONITA},
	[WILD_POKEMON_DENSITY_OTHER_1_25_PERCENT] = 
		{.level_min = 13, .level_max = 17, .species = POKEMON_KNACKLION},
	[WILD_POKEMON_DENSITY_OTHER_2_20_PERCENT] = 
		{.level_min = 13, .level_max = 17, .species = POKEMON_SKORGLA},
	[WILD_POKEMON_DENSITY_OTHER_3_15_PERCENT] = 
		{.level_min = 14, .level_max = 17, .species = POKEMON_SKORGLA},
	[WILD_POKEMON_DENSITY_OTHER_4_10_PERCENT] = 
		{.level_min = 16, .level_max = 18, .species = POKEMON_SKORGLA},
};

static wild_pokemon_habitat wild_pokemon_3_74_other = {
	.frequency = 134, .data = wild_pokemon_3_74_other_entries
};

static wild_pokemon_entry wild_pokemon_3_76_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 32, .level_max = 34, .species = POKEMON_GERADAKS},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 32, .level_max = 34, .species = POKEMON_SCHWALBINI},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 32, .level_max = 34, .species = POKEMON_KRAMURX},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 32, .level_max = 34, .species = POKEMON_WABLU},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 32, .level_max = 34, .species = POKEMON_PUMMELUFF},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 32, .level_max = 34, .species = POKEMON_KRAMURX},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 33, .level_max = 34, .species = POKEMON_WABLU},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 33, .level_max = 34, .species = POKEMON_SCHWALBINI},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 34, .level_max = 34, .species = POKEMON_PUMMELUFF},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 33, .level_max = 35, .species = POKEMON_KRAMURX},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 34, .level_max = 35, .species = POKEMON_WABLU},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 35, .level_max = 36, .species = POKEMON_GERADAKS},
};

static wild_pokemon_habitat wild_pokemon_3_76_grass = {
	.frequency = 3, .data = wild_pokemon_3_76_grass_entries
};

static wild_pokemon_entry wild_pokemon_3_76_other_entries[5] = {
	[WILD_POKEMON_DENSITY_OTHER_0_30_PERCENT] = 
		{.level_min = 35, .level_max = 37, .species = POKEMON_WABLU},
	[WILD_POKEMON_DENSITY_OTHER_1_25_PERCENT] = 
		{.level_min = 35, .level_max = 37, .species = POKEMON_GERADAKS},
	[WILD_POKEMON_DENSITY_OTHER_2_20_PERCENT] = 
		{.level_min = 35, .level_max = 37, .species = POKEMON_LEDIAN},
	[WILD_POKEMON_DENSITY_OTHER_3_15_PERCENT] = 
		{.level_min = 35, .level_max = 37, .species = POKEMON_KNUDDELUFF},
	[WILD_POKEMON_DENSITY_OTHER_4_10_PERCENT] = 
		{.level_min = 35, .level_max = 37, .species = POKEMON_KRAMURX},
};

static wild_pokemon_habitat wild_pokemon_3_76_other = {
	.frequency = 134, .data = wild_pokemon_3_76_other_entries
};

static wild_pokemon_entry wild_pokemon_3_8_grass_entries[12] = {
  [WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] =
    {.level_min = 14, .level_max = 17, .species = POKEMON_MOBAI},
  [WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] =
    {.level_min = 14, .level_max = 17, .species = POKEMON_ELEKID},
  [WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] =
    {.level_min = 15, .level_max = 17, .species = POKEMON_AZURILL},
  [WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] =
    {.level_min = 15, .level_max = 17, .species = POKEMON_MAGBY},
  [WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] =
    {.level_min = 15, .level_max = 17, .species = POKEMON_KLINGPLIM},
  [WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] =
    {.level_min = 15, .level_max = 18, .species = POKEMON_FLUFFELUFF},
  [WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] =
    {.level_min = 15, .level_max = 18, .species = POKEMON_RABAUZ},
  [WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] =
    {.level_min = 15, .level_max = 18, .species = POKEMON_RABAUZ},
  [WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] =
    {.level_min = 16, .level_max = 18, .species = POKEMON_KLINGPLIM},
  [WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] =
    {.level_min = 17, .level_max = 19, .species = POKEMON_ELEKID},
  [WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] =
    {.level_min = 18, .level_max = 19, .species = POKEMON_FLUFFELUFF},
  [WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] =
    {.level_min = 20, .level_max = 21, .species = POKEMON_MOBAI},
};

static wild_pokemon_habitat wild_pokemon_3_8_grass = {
  .frequency = 30, .data = wild_pokemon_3_8_grass_entries
};

static wild_pokemon_entry wild_pokemon_3_8_other_entries[5] = {
  [WILD_POKEMON_DENSITY_OTHER_0_30_PERCENT] =
    {.level_min = 18, .level_max = 21, .species = POKEMON_KLINGPLIM},
  [WILD_POKEMON_DENSITY_OTHER_1_25_PERCENT] =
    {.level_min = 18, .level_max = 21, .species = POKEMON_AZURILL},
  [WILD_POKEMON_DENSITY_OTHER_2_20_PERCENT] =
    {.level_min = 18, .level_max = 21, .species = POKEMON_MAGBY},
  [WILD_POKEMON_DENSITY_OTHER_3_15_PERCENT] =
    {.level_min = 19, .level_max = 21, .species = POKEMON_TOGEPI},
  [WILD_POKEMON_DENSITY_OTHER_4_10_PERCENT] =
    {.level_min = 18, .level_max = 21, .species = POKEMON_RIOLU},
};

static wild_pokemon_habitat wild_pokemon_3_8_other = {
  .frequency = 128, .data = wild_pokemon_3_8_other_entries
};

static wild_pokemon_entry wild_pokemon_3_8_water_entries[5] = {
  [WILD_POKEMON_DENSITY_WATER_0_60_PERCENT] =
    {.level_min = 25, .level_max = 30, .species = POKEMON_MARILL},
  [WILD_POKEMON_DENSITY_WATER_1_30_PERCENT] =
    {.level_min = 25, .level_max = 35, .species = POKEMON_GEHWEIHER},
  [WILD_POKEMON_DENSITY_WATER_2_5_PERCENT] =
    {.level_min = 30, .level_max = 35, .species = POKEMON_ENTON},
  [WILD_POKEMON_DENSITY_WATER_3_4_PERCENT] =
    {.level_min = 25, .level_max = 35, .species = POKEMON_LOTURZEL},
  [WILD_POKEMON_DENSITY_WATER_3_1_PERCENT] =
    {.level_min = 30, .level_max = 39, .species = POKEMON_AZUMARILL},
};

static wild_pokemon_habitat wild_pokemon_3_8_water = {
  .frequency = 2, .data = wild_pokemon_3_8_water_entries
};

static wild_pokemon_entry wild_pokemon_3_8_rod_entries[10] = {
  [WILD_POKEMON_DENSITY_OLD_ROD_0_70_PERCENT] =
    {.level_min = 5, .level_max = 5, .species = POKEMON_KARPADOR},
  [WILD_POKEMON_DENSITY_OLD_ROD_1_30_PERCENT] =
    {.level_min = 5, .level_max = 5, .species = POKEMON_KARPADOR},
  [WILD_POKEMON_DENSITY_GOOD_ROD_0_60_PERCENT] =
    {.level_min = 25, .level_max = 35, .species = POKEMON_KARPADOR},
  [WILD_POKEMON_DENSITY_GOOD_ROD_1_20_PERCENT] =
    {.level_min = 25, .level_max = 35, .species = POKEMON_FLEGMON},
  [WILD_POKEMON_DENSITY_GOOD_ROD_2_20_PERCENT] =
    {.level_min = 25, .level_max = 35, .species = POKEMON_KARPADOR},
  [WILD_POKEMON_DENSITY_SUPER_ROD_0_40_PERCENT] =
    {.level_min = 35, .level_max = 50, .species = POKEMON_KARPADOR},
  [WILD_POKEMON_DENSITY_SUPER_ROD_1_40_PERCENT] =
    {.level_min = 35, .level_max = 40, .species = POKEMON_KARPADOR},
  [WILD_POKEMON_DENSITY_SUPER_ROD_2_15_PERCENT] =
    {.level_min = 35, .level_max = 45, .species = POKEMON_FLEGMON},
  [WILD_POKEMON_DENSITY_SUPER_ROD_3_4_PERCENT] =
    {.level_min = 40, .level_max = 45, .species = POKEMON_KARPADOR},
  [WILD_POKEMON_DENSITY_SUPER_ROD_4_1_PERCENT] =
    {.level_min = 45, .level_max = 50, .species = POKEMON_GARADOS},
};

static wild_pokemon_habitat wild_pokemon_3_8_rod = {
  .frequency = 10, .data = wild_pokemon_3_8_rod_entries
};



static wild_pokemon_entry wild_pokemon_laubdorf_water_entries[5] = {
	[WILD_POKEMON_DENSITY_WATER_0_60_PERCENT] = 
		{.level_min = 26, .level_max = 32, .species = POKEMON_QUABBEL},
	[WILD_POKEMON_DENSITY_WATER_1_30_PERCENT] = 
		{.level_min = 26, .level_max = 30, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_WATER_2_5_PERCENT] = 
		{.level_min = 26, .level_max = 29, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_WATER_3_4_PERCENT] = 
		{.level_min = 27, .level_max = 33, .species = POKEMON_KRABBY},
	[WILD_POKEMON_DENSITY_WATER_3_1_PERCENT] = 
		{.level_min = 30, .level_max = 34, .species = POKEMON_PELIPPER},
};

static wild_pokemon_habitat wild_pokemon_laubdorf_water = {
	.frequency = 4, .data = wild_pokemon_laubdorf_water_entries
};

static wild_pokemon_entry wild_pokemon_laubdorf_rod_entries[10] = {
	[WILD_POKEMON_DENSITY_OLD_ROD_0_70_PERCENT] = 
		{.level_min = 21, .level_max = 24, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_OLD_ROD_1_30_PERCENT] = 
		{.level_min = 21, .level_max = 24, .species = POKEMON_QUABBEL},
	[WILD_POKEMON_DENSITY_GOOD_ROD_0_60_PERCENT] = 
		{.level_min = 32, .level_max = 35, .species = POKEMON_WAILMER},
	[WILD_POKEMON_DENSITY_GOOD_ROD_1_20_PERCENT] = 
		{.level_min = 32, .level_max = 35, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_GOOD_ROD_2_20_PERCENT] = 
		{.level_min = 33, .level_max = 36, .species = POKEMON_QUABBEL},
	[WILD_POKEMON_DENSITY_SUPER_ROD_0_40_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_SUPER_ROD_1_40_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_KANIVANHA},
	[WILD_POKEMON_DENSITY_SUPER_ROD_2_15_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_TENTOXA},
	[WILD_POKEMON_DENSITY_SUPER_ROD_3_4_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_QUABBEL},
	[WILD_POKEMON_DENSITY_SUPER_ROD_4_1_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_TOHAIDO},
};

static wild_pokemon_habitat wild_pokemon_laubdorf_rod = {
	.frequency = 120, .data = wild_pokemon_laubdorf_rod_entries
};

static wild_pokemon_entry wild_pokemon_ardeal_dungeon_grass_entries[12] = {
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

static wild_pokemon_habitat wild_pokemon_ardeal_dungeon_grass = {
	.frequency = 2, .data = wild_pokemon_ardeal_dungeon_grass_entries
};

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

static wild_pokemon_habitat wild_pokemon_dark_tower = {
	.frequency = 2, .data = wild_pokemon_dark_tower_grass
};

static wild_pokemon_entry wild_pokemon_power_plant_inside_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 32, .level_max = 34, .species = POKEMON_MAGNETILO},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 32, .level_max = 34, .species = POKEMON_VOLTOBAL},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 32, .level_max = 35, .species = POKEMON_FRIZELBLIZ},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 33, .level_max = 34, .species = POKEMON_PIKACHU},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 33, .level_max = 35, .species = POKEMON_ELEKTEK},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 32, .level_max = 35, .species = POKEMON_MAGNETILO},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 34, .level_max = 36, .species = POKEMON_VOLTOBAL},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 34, .level_max = 36, .species = POKEMON_FRIZELBLIZ},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 34, .level_max = 36, .species = POKEMON_ELEKTEK},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 35, .level_max = 36, .species = POKEMON_MAGNETON},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 36, .level_max = 37, .species = POKEMON_MAGNETON},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 37, .level_max = 38, .species = POKEMON_VOLTENSO},
};

static wild_pokemon_habitat wild_pokemon_power_plant_inside_grass = {
	.frequency = 2, .data = wild_pokemon_power_plant_inside_grass_entries
};

static wild_pokemon_entry wild_pokemon_meriana_city_clouds_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 31, .level_max = 33, .species = POKEMON_MENKI},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 31, .level_max = 33, .species = POKEMON_WABLU},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 31, .level_max = 33, .species = POKEMON_MACHOLLO},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 31, .level_max = 34, .species = POKEMON_MENKI},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 31, .level_max = 34, .species = POKEMON_WABLU},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 32, .level_max = 34, .species = POKEMON_MENKI},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 32, .level_max = 35, .species = POKEMON_MACHOLLO},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 32, .level_max = 35, .species = POKEMON_WABLU},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 33, .level_max = 35, .species = POKEMON_MACHOLLO},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 33, .level_max = 35, .species = POKEMON_MENKI},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 34, .level_max = 35, .species = POKEMON_MENKI},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 35, .level_max = 37, .species = POKEMON_RASAFF},
};

static wild_pokemon_habitat wild_pokemon_meriana_city_clouds_grass = {
	.frequency = 20, .data = wild_pokemon_meriana_city_clouds_grass_entries
};

static wild_pokemon_entry wild_pokemon_meriana_city_clouds_other_entries[5] = {
	[WILD_POKEMON_DENSITY_OTHER_0_30_PERCENT] = 
		{.level_min = 24, .level_max = 26, .species = POKEMON_RABAUZ},
	[WILD_POKEMON_DENSITY_OTHER_1_25_PERCENT] = 
		{.level_min = 25, .level_max = 26, .species = POKEMON_MEDITIE},
	[WILD_POKEMON_DENSITY_OTHER_2_20_PERCENT] = 
		{.level_min = 25, .level_max = 26, .species = POKEMON_FLOETTE},
	[WILD_POKEMON_DENSITY_OTHER_3_15_PERCENT] = 
		{.level_min = 25, .level_max = 25, .species = POKEMON_MASCHOCK},
	[WILD_POKEMON_DENSITY_OTHER_4_10_PERCENT] = 
		{.level_min = 28, .level_max = 28, .species = POKEMON_MEDITALIS},
};

static wild_pokemon_habitat wild_pokemon_meriana_city_clouds_other = {
	.frequency = 180, .data = wild_pokemon_meriana_city_clouds_other_entries
};


static wild_pokemon_entry wild_pokemon_silvania_clouds_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 31, .level_max = 33, .species = POKEMON_KRAMURX},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 31, .level_max = 33, .species = POKEMON_WABLU},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 31, .level_max = 33, .species = POKEMON_SCHWALBINI},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 31, .level_max = 34, .species = POKEMON_KRAMURX},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 31, .level_max = 34, .species = POKEMON_WABLU},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 32, .level_max = 34, .species = POKEMON_KRAMURX},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 32, .level_max = 35, .species = POKEMON_SCHWALBINI},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 32, .level_max = 35, .species = POKEMON_WABLU},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 33, .level_max = 35, .species = POKEMON_SCHWALBINI},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 33, .level_max = 35, .species = POKEMON_KRAMURX},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 34, .level_max = 35, .species = POKEMON_KRAMURX},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 35, .level_max = 37, .species = POKEMON_SCHWALBOSS},
};

static wild_pokemon_habitat wild_pokemon_silvania_clouds_grass = {
	.frequency = 2, .data = wild_pokemon_silvania_clouds_grass_entries
};

static wild_pokemon_entry wild_pokemon_kaskada_clouds_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 29, .level_max = 30, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 30, .level_max = 31, .species = POKEMON_ENTON},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 30, .level_max = 31, .species = POKEMON_SCHWALBINI},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 31, .level_max = 32, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 31, .level_max = 33, .species = POKEMON_LOTURZEL},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 31, .level_max = 33, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 32, .level_max = 34, .species = POKEMON_SCHWALBINI},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 32, .level_max = 34, .species = POKEMON_ENTON},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 32, .level_max = 33, .species = POKEMON_LOMBRERO},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 33, .level_max = 34, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 33, .level_max = 35, .species = POKEMON_ENTORON},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 33, .level_max = 36, .species = POKEMON_PELIPPER},
};

static wild_pokemon_habitat wild_pokemon_kaskada_clouds_grass = {
	.frequency = 12, .data = wild_pokemon_kaskada_clouds_grass_entries
};

static wild_pokemon_entry wild_pokemon_8_11_water_entries[5] = {
	[WILD_POKEMON_DENSITY_WATER_0_60_PERCENT] = 
		{.level_min = 35, .level_max = 37, .species = POKEMON_QUABBEL},
	[WILD_POKEMON_DENSITY_WATER_1_30_PERCENT] = 
		{.level_min = 36, .level_max = 38, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_WATER_2_5_PERCENT] = 
		{.level_min = 35, .level_max = 37, .species = POKEMON_KREBSCORPS},
	[WILD_POKEMON_DENSITY_WATER_3_4_PERCENT] = 
		{.level_min = 35, .level_max = 38, .species = POKEMON_KRABBY},
	[WILD_POKEMON_DENSITY_WATER_3_1_PERCENT] = 
		{.level_min = 36, .level_max = 39, .species = POKEMON_KRABBY},
};

static wild_pokemon_habitat wild_pokemon_8_11_water = {
	.frequency = 13, .data = wild_pokemon_8_11_water_entries
};

static wild_pokemon_entry wild_pokemon_8_11_rod_entries[10] = {
	[WILD_POKEMON_DENSITY_OLD_ROD_0_70_PERCENT] = 
		{.level_min = 21, .level_max = 24, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_OLD_ROD_1_30_PERCENT] = 
		{.level_min = 21, .level_max = 24, .species = POKEMON_QUABBEL},
	[WILD_POKEMON_DENSITY_GOOD_ROD_0_60_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_KRABBY},
	[WILD_POKEMON_DENSITY_GOOD_ROD_1_20_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_GOOD_ROD_2_20_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_KRABBY},
	[WILD_POKEMON_DENSITY_SUPER_ROD_0_40_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_QUABBEL},
	[WILD_POKEMON_DENSITY_SUPER_ROD_1_40_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_KRABBY},
	[WILD_POKEMON_DENSITY_SUPER_ROD_2_15_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_QUABBEL},
	[WILD_POKEMON_DENSITY_SUPER_ROD_3_4_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_KINGLER},
	[WILD_POKEMON_DENSITY_SUPER_ROD_4_1_PERCENT] = 
		{.level_min = 0, .level_max = 0, .species = POKEMON_GARADOS},
};

static wild_pokemon_habitat wild_pokemon_8_11_rod = {
	.frequency = 75, .data = wild_pokemon_8_11_rod_entries
};

static wild_pokemon_entry wild_pokemon_orina_city_clouds_grass_entries[12] = {
	[WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 24, .level_max = 27, .species = POKEMON_KRAMURX},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 23, .level_max = 27, .species = POKEMON_SCHWALBINI},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 23, .level_max = 27, .species = POKEMON_SMOGON},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 23, .level_max = 27, .species = POKEMON_KRAMURX},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 23, .level_max = 27, .species = POKEMON_SCHWALBINI},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 23, .level_max = 27, .species = POKEMON_KRAMURX},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 24, .level_max = 28, .species = POKEMON_DARTIGNIS},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 25, .level_max = 28, .species = POKEMON_SCHWALBINI},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 26, .level_max = 29, .species = POKEMON_SMOGON},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 26, .level_max = 29, .species = POKEMON_KRAMURX},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 27, .level_max = 29, .species = POKEMON_KRAMURX},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 28, .level_max = 32, .species = POKEMON_SCHWALBOSS},
};

static wild_pokemon_habitat wild_pokemon_orina_city_clouds_grass = {
	.frequency = 2, .data = wild_pokemon_orina_city_clouds_grass_entries
};


static wild_pokemon_entry wild_pokemon_orina_city_clouds_water_entries[5] = {
	[WILD_POKEMON_DENSITY_WATER_0_60_PERCENT] = 
		{.level_min = 22, .level_max = 27, .species = POKEMON_WINGULL},
	[WILD_POKEMON_DENSITY_WATER_1_30_PERCENT] = 
		{.level_min = 22, .level_max = 27, .species = POKEMON_SCHWALBINI},
	[WILD_POKEMON_DENSITY_WATER_2_5_PERCENT] = 
		{.level_min = 25, .level_max = 30, .species = POKEMON_LOTURZEL},
	[WILD_POKEMON_DENSITY_WATER_3_4_PERCENT] = 
		{.level_min = 30, .level_max = 35, .species = POKEMON_LOTURZEL},
	[WILD_POKEMON_DENSITY_WATER_3_1_PERCENT] = 
		{.level_min = 30, .level_max = 35, .species = POKEMON_LOMBRERO},
};

static wild_pokemon_habitat wild_pokemon_orina_city_clouds_water = {
	.frequency = 7, .data = wild_pokemon_orina_city_clouds_water_entries
};

static wild_pokemon_entry wild_pokemon_orina_city_clouds_rod_entries[10] = {
	[WILD_POKEMON_DENSITY_OLD_ROD_0_70_PERCENT] = 
		{.level_min = 9, .level_max = 11, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_OLD_ROD_1_30_PERCENT] = 
		{.level_min = 9, .level_max = 11, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_GOOD_ROD_0_60_PERCENT] = 
		{.level_min = 25, .level_max = 35, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_GOOD_ROD_1_20_PERCENT] = 
		{.level_min = 25, .level_max = 35, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_GOOD_ROD_2_20_PERCENT] = 
		{.level_min = 25, .level_max = 35, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_0_40_PERCENT] = 
		{.level_min = 25, .level_max = 35, .species = POKEMON_KARPADOR},
	[WILD_POKEMON_DENSITY_SUPER_ROD_1_40_PERCENT] = 
		{.level_min = 45, .level_max = 50, .species = POKEMON_TENTACHA},
	[WILD_POKEMON_DENSITY_SUPER_ROD_2_15_PERCENT] = 
		{.level_min = 45, .level_max = 50, .species = POKEMON_SEEPER},
	[WILD_POKEMON_DENSITY_SUPER_ROD_3_4_PERCENT] = 
		{.level_min = 45, .level_max = 50, .species = POKEMON_TENTOXA},
	[WILD_POKEMON_DENSITY_SUPER_ROD_4_1_PERCENT] = 
		{.level_min = 45, .level_max = 55, .species = POKEMON_SEEPER},
};

static wild_pokemon_habitat wild_pokemon_orina_city_clouds_rod = {
	.frequency = 49, .data = wild_pokemon_orina_city_clouds_rod_entries
};


static wild_pokemon_entry sonnaufeld_cloud_grass_entries[12] = {
    [WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 31, .level_max = 34, .species = POKEMON_WABLU},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 31, .level_max = 34, .species = POKEMON_MYRAPLA},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 31, .level_max = 34, .species = POKEMON_KNOFENSA},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 31, .level_max = 34, .species = POKEMON_WAUMPEL},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 31, .level_max = 34, .species = POKEMON_STARALILI},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 31, .level_max = 34, .species = POKEMON_DUFLOR},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 32, .level_max = 35, .species = POKEMON_PANEKON},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 32, .level_max = 35, .species = POKEMON_SCHALOKO},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 32, .level_max = 36, .species = POKEMON_KNOFENSA},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 33, .level_max = 36, .species = POKEMON_ULTRIGARIA},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 34, .level_max = 37, .species = POKEMON_ULTRIGARIA},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 35, .level_max = 38, .species = POKEMON_PAPINELLA},
};

static wild_pokemon_habitat sonnaufeld_cloud_grass = {
	.frequency = 28, .data = sonnaufeld_cloud_grass_entries
};

static wild_pokemon_entry sonnaufeld_cloud_other_entries[5] = {
	[WILD_POKEMON_DENSITY_OTHER_0_30_PERCENT] = 
		{.level_min = 35, .level_max = 37, .species = POKEMON_PANEKON},
	[WILD_POKEMON_DENSITY_OTHER_1_25_PERCENT] = 
		{.level_min = 35, .level_max = 37, .species = POKEMON_SCHALOKO},
	[WILD_POKEMON_DENSITY_OTHER_2_20_PERCENT] = 
		{.level_min = 35, .level_max = 37, .species = POKEMON_MUNTIER},
	[WILD_POKEMON_DENSITY_OTHER_3_15_PERCENT] = 
		{.level_min = 35, .level_max = 37, .species = POKEMON_LEPUMENTAS},
	[WILD_POKEMON_DENSITY_OTHER_4_10_PERCENT] = 
		{.level_min = 37, .level_max = 40, .species = POKEMON_ULTRIGARIA},
};

static wild_pokemon_habitat sonnaufeld_cloud_other = {
	.frequency = 138, .data = sonnaufeld_cloud_other_entries
};

static wild_pokemon_entry route_2_clouds_cave_grass_entries[12] = {
    [WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 31, .level_max = 34, .species = POKEMON_KLEINSTEIN},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 31, .level_max = 34, .species = POKEMON_ZUBAT},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 31, .level_max = 34, .species = POKEMON_ONIX},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 31, .level_max = 34, .species = POKEMON_KLEINSTEIN},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 31, .level_max = 34, .species = POKEMON_ONIX},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 31, .level_max = 34, .species = POKEMON_ZUBAT},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 32, .level_max = 35, .species = POKEMON_ZUBAT},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 32, .level_max = 35, .species = POKEMON_GEOROK},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 32, .level_max = 36, .species = POKEMON_ONIX},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 33, .level_max = 36, .species = POKEMON_GOLBAT},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 34, .level_max = 37, .species = POKEMON_GOLBAT},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 35, .level_max = 38, .species = POKEMON_GEOROK},
};

static wild_pokemon_habitat route_2_clouds_cave_grass = {
	.frequency = 5, .data = route_2_clouds_cave_grass_entries
};


static wild_pokemon_entry route_2_clouds_cave_ice_grass_entries[12] = {
    [WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 31, .level_max = 34, .species = POKEMON_KLEINSTEIN},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 31, .level_max = 34, .species = POKEMON_ZUBAT},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 31, .level_max = 34, .species = POKEMON_QUIEKEL},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 31, .level_max = 34, .species = POKEMON_SHNEBEDECK},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 31, .level_max = 34, .species = POKEMON_QUIEKEL},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 31, .level_max = 34, .species = POKEMON_SHNEBEDECK},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 32, .level_max = 35, .species = POKEMON_QUIEKEL},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 32, .level_max = 35, .species = POKEMON_GOLBAT},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 32, .level_max = 36, .species = POKEMON_GEOROK},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 33, .level_max = 36, .species = POKEMON_KEIFEL},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 34, .level_max = 37, .species = POKEMON_KEIFEL},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 35, .level_max = 38, .species = POKEMON_SHNEBEDECK},
};

static wild_pokemon_habitat route_2_clouds_cave_ice_grass = {
	.frequency = 5, .data = route_2_clouds_cave_ice_grass_entries
};

static wild_pokemon_entry wild_pokemon_anemonia_clouds_cave_grass_entries[12] = {
    [WILD_POKEMON_DENSITY_GRASS_0_20_PERCENT] = 
		{.level_min = 32, .level_max = 34, .species = POKEMON_KLEINSTEIN},
	[WILD_POKEMON_DENSITY_GRASS_1_20_PERCENT] = 
		{.level_min = 32, .level_max = 34, .species = POKEMON_KNILZ},
	[WILD_POKEMON_DENSITY_GRASS_2_10_PERCENT] = 
		{.level_min = 32, .level_max = 34, .species = POKEMON_ZUBAT},
	[WILD_POKEMON_DENSITY_GRASS_3_10_PERCENT] = 
		{.level_min = 32, .level_max = 34, .species = POKEMON_MYRAPLA},
	[WILD_POKEMON_DENSITY_GRASS_4_10_PERCENT] = 
		{.level_min = 32, .level_max = 34, .species = POKEMON_WEBARAK},
	[WILD_POKEMON_DENSITY_GRASS_5_10_PERCENT] = 
		{.level_min = 32, .level_max = 34, .species = POKEMON_KLEINSTEIN},
	[WILD_POKEMON_DENSITY_GRASS_6_5_PERCENT] = 
		{.level_min = 33, .level_max = 34, .species = POKEMON_KNILZ},
	[WILD_POKEMON_DENSITY_GRASS_7_5_PERCENT] = 
		{.level_min = 33, .level_max = 35, .species = POKEMON_ZUBAT},
	[WILD_POKEMON_DENSITY_GRASS_8_4_PERCENT] = 
		{.level_min = 34, .level_max = 35, .species = POKEMON_MYRAPLA},
	[WILD_POKEMON_DENSITY_GRASS_9_4_PERCENT] = 
		{.level_min = 34, .level_max = 36, .species = POKEMON_GEOROK},
	[WILD_POKEMON_DENSITY_GRASS_10_1_PERCENT] = 
		{.level_min = 34, .level_max = 36, .species = POKEMON_GOLBAT},
	[WILD_POKEMON_DENSITY_GRASS_11_1_PERCENT] = 
		{.level_min = 35, .level_max = 36, .species = POKEMON_GOLBAT},
};

static wild_pokemon_habitat wild_pokemon_anemonia_clouds_cave_grass = {
	.frequency = 2, .data = wild_pokemon_anemonia_clouds_cave_grass_entries
};

wild_pokemon_data wild_pokemon[] = {
  {
		.bank = 3, .map = 0,
		.grass = NULL,
		.water = &wild_pokemon_3_0_water,
		.other = NULL,
		.rod = &wild_pokemon_3_0_rod,
	},
	{
		.bank = 3, .map = 1,
		.grass = NULL,
		.water = &wild_pokemon_3_1_water,
		.other = NULL,
		.rod = &wild_pokemon_3_1_rod,
	},
	{
		.bank = 3, .map = 2,
		.grass = NULL,
		.water = &wild_pokemon_3_2_water,
		.other = NULL,
		.rod = &wild_pokemon_3_2_rod,
	},
	{
		.bank = 6, .map = 2,
		.grass = NULL,
		.water = NULL,
		.other = NULL,
		.rod = NULL,
	},
	{
		.bank = 3, .map = 19,
		.grass = &wild_pokemon_3_19_grass,
		.water = NULL,
		.other = &wild_pokemon_3_19_other,
		.rod = NULL,
	},
	{
		.bank = 3, .map = 76,
		.grass = &wild_pokemon_3_76_grass,
		.water = NULL,
		.other = &wild_pokemon_3_76_other,
		.rod = NULL,
	},
	{
		.bank = 3, .map = 57,
		.grass = &wild_pokemon_3_57_grass,
		.water = &wild_pokemon_3_57_water,
		.other = &wild_pokemon_3_57_other,
		.rod = &wild_pokemon_3_57_rod,
	},
	{
		.bank = 3, .map = 72,
		.grass = NULL,
		.water = NULL,
		.other = NULL,
		.rod = NULL,
	},
	{
		.bank = 3, .map = 41,
		.grass = &wild_pokemon_3_41_grass,
		.water = &wild_pokemon_3_41_water,
		.other = &wild_pokemon_3_41_other,
		.rod = &wild_pokemon_3_41_rod,
	},
	{
		.bank = 3, .map = 70,
		.grass = &wild_pokemon_3_70_grass,
		.water = NULL,
		.other = NULL,
		.rod = NULL,
	},
	{
		.bank = 15, .map = 0,
		.grass = &wild_pokemon_15_0_grass,
		.water = &wild_pokemon_15_0_water,
		.other = &wild_pokemon_15_0_other,
		.rod = &wild_pokemon_15_0_rod,
	},
	{
		.bank = 15, .map = 4,
		.grass = &wild_pokemon_15_4_grass,
		.water = NULL, 
		.other = NULL,
		.rod = NULL,
	},
	{
		.bank = 15, .map = 5,
		.grass = &wild_pokemon_15_4_grass,
		.water = NULL, 
		.other = NULL,
		.rod = NULL,
	},
	{
		.bank = 3, .map = 3,
		.grass = NULL,
		.water = &wild_pokemon_3_3_water,
		.other = NULL,
		.rod = &wild_pokemon_3_3_rod,
	},
	{
		.bank = 1, .map = 0,
		.grass = &wild_pokemon_1_0_grass,
		.water = &wild_pokemon_1_0_water,
		.other = &wild_pokemon_1_0_other,
		.rod = &wild_pokemon_1_0_rod,
	},
	{
		.bank = 0, .map = 5,
		.grass = &wild_pokemon_0_5_grass,
		.water = NULL,
		.other = NULL,
		.rod = NULL,
	},
	{
		.bank = 0, .map = 6,
		.grass = &wild_pokemon_0_6_grass,
		.water = NULL,
		.other = NULL,
		.rod = NULL,
	},
	{
		.bank = 0, .map = 7,
		.grass = &wild_pokemon_0_7_grass,
		.water = &wild_pokemon_0_7_water,
		.other = NULL,
		.rod = &wild_pokemon_0_7_rod,
	},
	{
		.bank = 3, .map = 21,
		.grass = &wild_pokemon_3_21_grass,
		.water = NULL,
		.other = &wild_pokemon_3_21_other,
		.rod = NULL,
	},
	{
		.bank = 3, .map = 67,
		.grass = &wild_pokemon_3_67_grass,
		.water = &wild_pokemon_3_67_water,
		.other = NULL,
		.rod = &wild_pokemon_3_67_rod,
	},
	{
		.bank = 3, .map = 74,
		.grass = &wild_pokemon_3_74_grass,
		.water = NULL,
		.other = &wild_pokemon_3_74_other,
		.rod = NULL,
	},
	{
		.bank = 3, .map = 4,
		.grass = NULL,
		.water = &wild_pokemon_3_4_water,
		.other = NULL,
		.rod = NULL,
	},
	{
		.bank = 8, .map = 11,
		.grass = NULL,
		.water = &wild_pokemon_8_11_water,
		.other = NULL,
		.rod = &wild_pokemon_8_11_rod,
	},
	{
		.bank = 1, .map = 59,
		.grass = &wild_pokemon_tafelberg_grass,
		.water = &wild_pokemon_tafelberg_water,
		.other = &wild_pokemon_tafelberg_other,
		.rod = &wild_pokemon_tafelberg_rod,
	},
	{
		.bank = 3, .map = 22,
		.grass = &wild_pokemon_3_22_grass,
		.water = &wild_pokemon_3_22_water,
		.other = &wild_pokemon_3_22_other,
		.rod = &wild_pokemon_3_22_rod,
	},
	{
		.bank = 3, .map = 23,
		.grass = &wild_pokemon_3_23_grass,
		.water = &wild_pokemon_route_5_water,
		.other = &wild_pokemon_3_23_other,
		.rod = &wild_pokemon_route_5_rod,
	},
	{
		.bank = 17, .map = 2,
		.grass = &wild_pokemon_route_5_clouds_grass,
		.water = NULL,
		.other = NULL,
		.rod = NULL,
	},
	{
		.bank = 3, .map = 24,
		.grass = NULL,
		.water = &wild_pokemon_3_24_water,
		.other = NULL,
		.rod = &wild_pokemon_3_24_rod,
	},
	{
		.bank = 18, .map = 2,
		.grass = &wild_pokemon_18_2_grass,
		.water = NULL,
		.other = NULL,
		.rod = NULL,
	},
	{
		.bank = 18, .map = 3,
		.grass = &wild_pokemon_18_3_grass,
		.water = NULL,
		.other = &wild_pokemon_18_3_other,
		.rod = NULL,
	},
	{
		.bank = 1, .map = 30,
		.grass = &wild_pokemon_1_30_grass,
		.water = NULL,
		.other = &wild_pokemon_1_30_other,
		.rod = NULL,
	},
	{
		.bank = 0, .map = 12,
		.grass = &wild_pokemon_0_12_grass,
		.water = NULL,
		.other = NULL,
		.rod = NULL,
	},
	{
		.bank = 1, .map = 81,
		.grass = &wild_pokemon_1_81_grass,
		.water = NULL,
		.other = NULL,
		.rod = NULL,
	},
	{
		.bank = 1, .map = 82,
		.grass = &wild_pokemon_1_82_grass,
		.water = NULL,
		.other = &wild_pokemon_1_82_other,
		.rod = NULL,
	},
	{
		.bank = 1, .map = 126,
		.grass = &wild_pokemon_1_126_grass,
		.water = NULL,
		.other = NULL,
		.rod = NULL,
	},
	{
		.bank = 3, .map = 7,
		.grass = &wild_pokemon_3_7_grass,
		.water = &wild_pokemon_3_41_water,
		.other = &wild_pokemon_3_7_other,
		.rod = &wild_pokemon_3_41_rod,
	},
	{
		.bank = 11, .map = 2,
		.grass = &wild_pokemon_route_2_clouds_grass,
		.water = &wild_pokemon_route_2_clouds_water,
		.rod = &wild_pokemon_route_2_clouds_rod,
	},
	{
		.bank = 11, .map = 3,
		.grass = &wild_pokemon_route_2_clouds_grass,
		.water = &wild_pokemon_route_2_clouds_water,
		.rod = &wild_pokemon_route_2_clouds_rod,
		.other = &wild_pokemon_route_2_clouds_other,
	},
	{
	    .bank = 3, .map = 8,
	    .grass = &wild_pokemon_3_8_grass,
	    .water = &wild_pokemon_3_8_water,
	    .other = &wild_pokemon_3_8_other,
	    .rod = &wild_pokemon_3_8_rod,
	},
	{
		.bank = 3, .map = 9,
		.water = &wild_pokemon_laubdorf_water, .rod = &wild_pokemon_laubdorf_rod,
		.grass = NULL, .other = NULL
	},
	{
		.bank = 3, .map = 10,
		.water = &wild_pokemon_route_9_water, .rod = &wild_pokemon_route_9_rod,
		.grass = NULL, .other = NULL

	},
	{
		.bank = 13, .map = 0,
		.water = &wild_pokemon_route_9_water, .rod = &wild_pokemon_route_9_rod,
		.grass = NULL, .other = NULL

	},
	{
		.bank = 3, .map = 11,
		.water = &wild_pokemon_route_10_water, .rod = &wild_pokemon_route_10_rod,
		.grass = NULL, .other = NULL

	},
	{
		.bank = 14, .map = 0,
		.water = NULL, .rod = NULL,
		.grass = &wild_pokemon_route_10_clouds_grass, .other = &wild_pokemon_route_10_clouds_other

	},
	{
		.bank = 3, .map = 12,
		.water = &wild_pokemon_route_11_water, .rod = &wild_pokemon_route_11_rod,
		.grass = NULL, .other = NULL

	},
	{
		.bank = 3, .map = 14,
		.grass = &wild_pokemon_forest_cemetery_grass, .other = &wild_pokemon_forest_cemetery_other,
		.water = NULL, .rod = NULL
	},
	{
		.bank = 3, .map = 15,
		.grass = &wild_pokemon_route_12_east_grass, .other = &wild_pokemon_route_12_east_other,
		.water = &wild_pokemon_route_12_east_water, .rod = &wild_pokemon_route_12_east_rod
	},
	{
		.bank = 9, .map = 0,
		.grass = &wild_pokemon_orina_city_clouds_grass,
		.water = &wild_pokemon_orina_city_clouds_water,
		.rod = &wild_pokemon_orina_city_clouds_rod,
	},
	{
		.bank = 18, .map = 0,
		.grass = &wild_pokemon_route_6_clouds_grass,
		.water = &wild_pokemon_route_6_clouds_water,
		.rod = &wild_pokemon_route_6_clouds_rod,
	},
	{
		.bank = 10, .map = 2,
		.grass = &wild_pokemon_route_6_clouds_grass,
		.water = &wild_pokemon_route_6_clouds_water,
		.rod = &wild_pokemon_route_6_clouds_rod,
	},
	{
		.bank = 21, .map = 0,
		.grass = &wild_pokemon_route_6_clouds_grass,
	},
	{
		.bank = 5, .map = 1,
		.grass = &wild_pokemon_meriana_city_clouds_grass,
		.other = &wild_pokemon_meriana_city_clouds_other,
	},
	{
		.bank = 16, .map = 0,
		.grass = &wild_pokemon_route_4_clouds_grass,
	},
	{
		.bank = 8, .map = 1,
		.grass = &wild_pokemon_kaskada_clouds_grass,
		.water = &wild_pokemon_route_6_clouds_water,
		.rod = &wild_pokemon_route_6_clouds_rod,
	},
	{
		.bank = 22, .map = 0,
		.grass = &wild_pokemon_tafelberg_west_grass,
		.other = &wild_pokemon_tafelberg_west_other,
		.water = &wild_pokemon_tafelberg_west_water,
		.rod = &wild_pokemon_tafelberg_south_rod,
	},
	{
		.bank = 7, .map = 0,
		.grass = &wild_pokemon_silvania_clouds_grass,
	},
	{
		.bank = 15, .map = 2,
		.grass = &wild_pokemon_route_3_clouds_grass,
	},
	{
		.bank = 1, .map = 2,
		.grass = &wild_pokemon_silvania_wald_clouds_grass,
	},
	{
		.bank = 23, .map = 0,
		.grass = &wild_pokemon_route_8_clouds_grass,
		.water = &wild_pokemon_route_6_clouds_water,
		.rod = &wild_pokemon_route_6_clouds_rod,
	},
	{
		.bank = 12, .map = 5,
		.grass = &wild_pokemon_route_8_clouds_grass,
	},
	{
		.bank = 13, .map = 4,
		.grass = &wild_pokemon_route_9_clouds_grass,
	},
	{
		.bank = 13, .map = 5,
		.grass = &wild_pokemon_route_9_clouds_grass,
	},
	{
		.bank = 6, .map = 6,
		.grass = &wild_pokemon_route_9_clouds_grass,
	},
	{
		.bank = 14, .map = 0,
		.grass = &wild_pokemon_route_10_clouds_grass,
	},
	{
		.bank = 24, .map = 0,
		.grass = &wild_pokemon_kaskada_clouds_grass,
		.water = &wild_pokemon_route_6_clouds_water,
		.rod = &wild_pokemon_route_6_clouds_rod,
	},
	{
		.bank = 25, .map = 0,
		.grass = &wild_pokemon_route_11_clouds_grass,
		.water = &wild_pokemon_route_6_clouds_water,
		.rod = &wild_pokemon_route_6_clouds_rod,
	},
	{
		.bank = 19, .map = 9,
		.grass = &wild_pokemon_ceometria_clouds_grass,
	},
	{
		.bank = 26, .map = 0,
		.grass = &wild_pokemon_route_12_clouds_grass,
	},
	{
		.bank = 26, .map = 1,
		.grass = &wild_pokemon_route_12_clouds_grass,
	},
	{
			.bank = 11, .map = 4, .grass = &wild_pokemon_unown_ruins_grass
	},
	{
			.bank = 6, .map = 7, .grass = &wild_pokemon_unown_ruins_grass
	},
	{
			.bank = 8, .map = 2, .grass = &wild_pokemon_unown_ruins_grass
	},
	{
			.bank = 9, .map = 4, .grass = &wild_pokemon_unown_ruins_grass
	},
	{
			.bank = 12, .map = 7, .grass = &wild_pokemon_unown_ruins_grass
	},
	{
			.bank = 27, .map = 1, .grass = &wild_pokemon_unown_ruins_grass
	},
	{
			.bank = 3, .map = 16, .water = &wild_pokemon_route_12_west_water, .rod = &wild_pokemon_route_12_west_rod,
			.grass = &wild_pokemon_route_12_west_grass, .other = &wild_pokemon_route_12_west_other,
	},
	{
			.bank = 3, .map = 17, .water = &wild_pokemon_route_12_west_water, .rod = &wild_pokemon_route_12_west_rod,
	},
	{
			.bank = 29, .map = 3, .grass = &wild_pokemon_route_7_north_grass, .other = &wild_pokemon_route_7_north_other,
	},
	{
			.bank = 29, .map = 2, .grass = &wild_pokemon_route_7_castle_grass, .other = &wild_pokemon_route_7_castle_other,
			.water = &wild_pokemon_route_7_castle_water, .rod = &wild_pokemon_route_7_castle_rod,
	},
	{
			.bank = 3, .map = 18, .grass = &wild_pokemon_route_7_grass, .other = &wild_pokemon_route_7_other,
			.water = &wild_pokemon_route_7_castle_water, .rod = &wild_pokemon_route_7_castle_rod,
	},
	{
			.bank = 29, .map = 1, .grass = &wild_pokemon_route_7_grass, .other = &wild_pokemon_route_7_other,
			.water = &wild_pokemon_route_7_castle_water, .rod = &wild_pokemon_route_7_castle_rod,
	},
	{
			.bank = 31, .map = 16, .grass = &wild_pokemon_ardeal_dungeon_grass,
	},
	{.bank = 32, .map = 0, .grass = &wild_pokemon_dark_tower,},
	{.bank = 32, .map = 1, .grass = &wild_pokemon_dark_tower,},
	{.bank = 32, .map = 2, .grass = &wild_pokemon_dark_tower,},
	{.bank = 32, .map = 3, .grass = &wild_pokemon_dark_tower,},
	{.bank = 32, .map = 4, .grass = &wild_pokemon_dark_tower,},
	{
		.bank = 11, .map = 5,
		.grass = &wild_pokemon_3_70_grass,
		.water = &wild_pokemon_route_2_cave_water,
		.other = NULL,
		.rod = &wild_pokemon_route_2_cave_rod,
	},{
		.bank = 11, .map = 6,
		.grass = &wild_pokemon_3_70_grass,
		.water = &wild_pokemon_route_2_cave_water,
		.other = NULL,
		.rod = &wild_pokemon_route_2_cave_rod,
	}, {
		.bank = 22, .map = 2,
		.water = &wild_pokemon_0_7_water,
		.rod = &wild_pokemon_0_7_rod,
		.grass = &wild_pokemon_0_6_grass,
	}, {
		.bank = 22, .map = 4,
		.grass = &wild_pokemon_tafelberg_south_grass,
		.other = &wild_pokemon_tafelberg_south_other,
		.water = &wild_pokemon_tafelberg_south_water,
		.rod = &wild_pokemon_tafelberg_south_rod,
	},
	{
		.bank = 8, .map = 14,
		.grass = &wild_pokemon_0_7_grass,
	},
	{
		.bank = 17, .map = 0,
		.grass = &wild_pokemon_route_5_cave_grass,
	},
	{
		.bank = 17, .map = 1,
		.grass = &wild_pokemon_route_5_cave_grass,
	},
	{
		.bank = 17, .map = 4,
		.grass = &wild_pokemon_route_5_cave_grass,
	},
	{
		.bank = 17, .map = 5,
		.grass = &wild_pokemon_route_5_cave_grass,
	},
	{
		.bank = 17, .map = 6,
		.grass = &wild_pokemon_route_5_cave_grass,
	},
	{
		.bank = 17, .map = 7,
		.grass = &wild_pokemon_route_5_cave_grass,
	}, {
		.bank = 4, .map = 5,
		.grass = &wild_pokemon_3_76_grass,
		.water = NULL,
		.other = NULL,
		.rod = NULL,
	}, {
		.bank = 16, .map = 5,
		.grass = &wild_pokemon_route_4_cloud_cave_grass,
	}, {
		.bank = 34, .map = 0,
		.grass = &wild_pokemon_power_plant_inside_grass,
	},
	{
		.bank = 1, .map = 31,
		.grass = &wild_pokemon_18_2_grass,
	},
	{
		.bank = 16, .map = 2,
		.water = &wild_pokemon_0_7_water,
		.rod = &wild_pokemon_0_7_rod,
		.grass = &wild_pokemon_route_4_south_cave_grass,
	},
	{
		.bank = 35, .map = 3,
		.grass = &sonnaufeld_cloud_grass, .other = &sonnaufeld_cloud_other,
	},
	{
		.bank = 11, .map = 7, .grass = &route_2_clouds_cave_grass,
	},
	{
		.bank = 11, .map = 8, .grass = &route_2_clouds_cave_grass,
	},
	{
		.bank = 11, .map = 9, .grass = &route_2_clouds_cave_ice_grass,
	},
	{
		.bank = 4, .map = 6, .grass = &wild_pokemon_anemonia_clouds_cave_grass,
	},
	{
	    .bank = 0xFF, .map = 0xFF, .field_2 = 0xFF, .field_3 = 0xFF,
	    .grass = NULL, .water = NULL, .other = NULL, .rod = NULL
	},
};


#endif