/*
 * wild_pokemon.c
 *
 *  Created on: Jun 3, 2018
 *      Author: dominik
 */

#include "types.h"
#include "constants/species.h"
#include "map/wild_pokemon.h"
#include "prng.h"
#include "dungeon2.h"
#include "save.h"
#include "debug.h"
#include "constants/flags.h"
#include "flags.h"

u16 dungeon_forest_wild_pokemon_common[] = {
    POKEMON_PARAGONI,
    POKEMON_PIKACHU,
    POKEMON_DUFLOR,
    POKEMON_KASTADUR,
    POKEMON_ULTRIGARIA,
    POKEMON_LEDYBA,
    POKEMON_WEBARAK,
    POKEMON_FLABEBE,
    POKEMON_BLANAS,
    POKEMON_KNILZ,
    POKEMON_BUMMELZ,
    0xFFFF
};

u16 dungeon_forest_wild_pokemon_rare[] = {
    POKEMON_BIBOR,
    POKEMON_MOGELBAUM,
    POKEMON_GRIFFEL,
    POKEMON_KRAMURX,
    POKEMON_TEDDIURSA,
    POKEMON_PUDOX,
    POKEMON_PAPINELLA,
    POKEMON_SCHWALBOSS,
    POKEMON_MASKEREGEN,
    0xFFFF
};

u16 dungeon_forest_wild_pokemon_super_rare[] = {
    POKEMON_SICHLOR,
    POKEMON_PINSIR,
    POKEMON_SKARABORN,
    0xFFFF
};

void dungeon2_forest_wild_pokemon_level_distribution(u8 *mean, u8 *std_deviation) {
  if(checkflag(FRBADGE_4)) {
    *mean = 34;
    *std_deviation = 3;
  } else if (checkflag(FRBADGE_3)) {
    *mean = 26;
    *std_deviation = 3;
  } else if (checkflag(FRBADGE_2)) {
    *mean = 16;
    *std_deviation = 2;
  } else if (checkflag(FRBADGE_1)) {
    *mean = 10;
    *std_deviation = 2;
  } else {
    *mean = 5;
    *std_deviation = 1;
  }
}

void dungeon2_init_wild_pokemon_forest(dungeon_generator2 *dg2) {
  (void)dg2;
  // Pick four common pokemon
  u16 common_pokemon[4];
  dungeon2_pick_wild_pokemon(common_pokemon, 4, dungeon_forest_wild_pokemon_common);
  // Pick one rare pokemon
  u16 rare_pokemon[1];
  dungeon2_pick_wild_pokemon(rare_pokemon, 1, dungeon_forest_wild_pokemon_rare);
  // Pick one super rare pokemon
  u16 super_rare_pokemon[1];
  dungeon2_pick_wild_pokemon(super_rare_pokemon, 1, dungeon_forest_wild_pokemon_super_rare);

  fmem->dwild_pokemon.grass = &(fmem->dwild_habitat_grass);
  fmem->dwild_pokemon.water = NULL;
  fmem->dwild_pokemon.other = NULL;
  fmem->dwild_pokemon.rod = NULL;
  fmem->dwild_habitat_grass.frequency = DTYPE_FOREST_WILD_POKEMON_FREQUENCY;
  fmem->dwild_habitat_grass.data = fmem->dwild_data_grass;

  // Each of the common pokemon has a 20% probability
  fmem->dwild_data_grass[0].species = common_pokemon[0];
  fmem->dwild_data_grass[1].species = common_pokemon[1];
  fmem->dwild_data_grass[2].species = common_pokemon[2];
  fmem->dwild_data_grass[3].species = common_pokemon[2];
  fmem->dwild_data_grass[4].species = common_pokemon[3];
  fmem->dwild_data_grass[5].species = common_pokemon[3];

  // The rare pokemon has a 14% probability
  fmem->dwild_data_grass[6].species = rare_pokemon[0];
  fmem->dwild_data_grass[7].species = rare_pokemon[0];
  fmem->dwild_data_grass[8].species = rare_pokemon[0];

  // The super rare pokemon has a 6% probability
  fmem->dwild_data_grass[9].species = super_rare_pokemon[0];
  fmem->dwild_data_grass[10].species = super_rare_pokemon[0];
  fmem->dwild_data_grass[11].species = super_rare_pokemon[0];

  u8 mean = 0;
  u8 std_deviation = 0;
  u8 level_min = 0;
  u8 level_max = 0;
  dungeon2_forest_wild_pokemon_level_distribution(&mean, &std_deviation);

  for(int i = 0; i < 12; i++) {
    dprintf("Mean %d, std %d, min %d, max %d\n", mean, std_deviation, level_min, level_max);
    dungeon2_wild_pokemon_sample_level_boundaries(&level_min, &level_max, mean, std_deviation);
    fmem->dwild_data_grass[i].level_min = level_min;
    fmem->dwild_data_grass[i].level_max = level_max;
  }
}


