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
#include "dungeon/dungeon2.h"
#include "dungeon/cave.h"
#include "save.h"
#include "debug.h"
#include "constants/flags.h"
#include "constants/vars.h"
#include "flags.h"
#include "math.h"
#include "vars.h"
#include "pokemon/virtual.h"

u16 dungeon_cave_wild_pokemon_common[] = {
    POKEMON_SANDAN,
    POKEMON_ZUBAT,
    POKEMON_DIGDA,
    POKEMON_MACHOLLO,
    POKEMON_KLEINSTEIN,
    POKEMON_ONIX,
    POKEMON_TRAGOSSO,
    POKEMON_RABAUZ,
    POKEMON_NASGNET,
    POKEMON_MEDITIE,
    POKEMON_STOLLUNIOR,
    POKEMON_PUMMELUFF,
    0xFFFF
};

u16 dungeon_cave_wild_pokemon_rare[] = {
    POKEMON_SONNFEL,
    POKEMON_LUNASTEIN,
    POKEMON_SANDAMER,
    POKEMON_GEOROK,
    POKEMON_SKORGLA,
    POKEMON_BRONZEL,
    0xFFFF
};

u16 dungeon_cave_wild_pokemon_super_rare[] = {
    POKEMON_STOLLRAK,
    POKEMON_ZOBIRIS,
    POKEMON_LARVITAR,
    POKEMON_MASCHOCK,
    POKEMON_FLUNKIFER,
    0xFFFF
};

void dungeon2_cave_wild_pokemon_level_distribution(u8 *mean, u8 *std_deviation) {
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

void dungeon2_set_encounter_cave() {
  dungeon_generator2 *dg2 = &(cmem->dg2);
  dungeon2_cave_init_state(dg2);
  pokemon_clear_opponent_party();

  u16 species = *var_access(DUNGEON_OVERWORLD_SPECIES);
  u8 mean = 0, std_deviation = 0;
  dungeon2_cave_wild_pokemon_level_distribution(&mean, &std_deviation);
  mean = (u8)(mean + 2 * std_deviation); // High level for this pokemon

  int level = FIXED_TO_INT(FIXED_ADD(INT_TO_FIXED(mean), FIXED_MUL(INT_TO_FIXED(std_deviation),
        dungeon2_rnd_normal(dg2))));
  level = max(min(level, 100), 2);

  pid_t p = {dungeon2_rnd(dg2)};

  pokemon_spawn_by_seed_algorithm(&opponent_pokemon[0], species, (u8)level, 0, true, p, false, 0,
      dungeon2_encounter_rnd_generator);
}

void dungeon2_init_wild_pokemon_cave(dungeon_generator2 *dg2) {
  // Pick four common pokemon
  u16 common_pokemon[4];
  dungeon2_pick_wild_pokemon(common_pokemon, 4, dungeon_cave_wild_pokemon_common, dg2);
  // Pick one rare pokemon
  u16 rare_pokemon[2];
  dungeon2_pick_wild_pokemon(rare_pokemon, 2, dungeon_cave_wild_pokemon_rare, dg2);
  // Pick one super rare pokemon
  u16 super_rare_pokemon[1];
  dungeon2_pick_wild_pokemon(super_rare_pokemon, 1, dungeon_cave_wild_pokemon_super_rare, dg2);

  *var_access(DUNGEON_OVERWORLD_SPECIES) = super_rare_pokemon[0];

  dprintf("Wild data grass %d\n", fmem->dwild_data_grass);
  fmem->dwild_pokemon.grass = &(fmem->dwild_habitat_grass);
  fmem->dwild_pokemon.water = NULL;
  fmem->dwild_pokemon.other = NULL;
  fmem->dwild_pokemon.rod = NULL;
  fmem->dwild_habitat_grass.frequency = DTYPE_CAVE_WILD_POKEMON_FREQUENCY;
  fmem->dwild_habitat_grass.data = fmem->dwild_data_grass;

  // Each of the common pokemon has a 20% probability
  fmem->dwild_data_grass[0].species = common_pokemon[0];
  fmem->dwild_data_grass[1].species = common_pokemon[1];
  fmem->dwild_data_grass[2].species = common_pokemon[2];
  fmem->dwild_data_grass[3].species = common_pokemon[2];
  fmem->dwild_data_grass[4].species = common_pokemon[3];
  fmem->dwild_data_grass[5].species = common_pokemon[3];

  // The first rare pokemon has a 14% probability
  fmem->dwild_data_grass[6].species = rare_pokemon[0];
  fmem->dwild_data_grass[7].species = rare_pokemon[0];
  fmem->dwild_data_grass[8].species = rare_pokemon[0];

  // The other rare pokemon has a 6% probability
  fmem->dwild_data_grass[9].species = rare_pokemon[1];
  fmem->dwild_data_grass[10].species = rare_pokemon[1];
  fmem->dwild_data_grass[11].species = rare_pokemon[1];

  u8 mean = 0;
  u8 std_deviation = 0;
  u8 level_min = 0;
  u8 level_max = 0;
  dungeon2_cave_wild_pokemon_level_distribution(&mean, &std_deviation);

  for(int i = 0; i < 12; i++) {
    dungeon2_wild_pokemon_sample_level_boundaries(&level_min, &level_max,
        (i < 6) ? mean : (u8)(mean + std_deviation), std_deviation, dg2);
    fmem->dwild_data_grass[i].level_min = level_min;
    fmem->dwild_data_grass[i].level_max = level_max;
  }
}


