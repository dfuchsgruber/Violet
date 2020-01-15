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
#include "dungeon/ocean.h"
#include "save.h"
#include "debug.h"
#include "constants/flags.h"
#include "constants/vars.h"
#include "flags.h"
#include "math.h"
#include "vars.h"
#include "pokemon/virtual.h"

u16 dungeon_ocean_wild_pokemon_water_common[] = {
	POKEMON_TENTACHA,
	POKEMON_JUROB,
	POKEMON_QUABBEL,
	POKEMON_MARILL,
	POKEMON_WINGULL,
	POKEMON_SEEMOPS,
	POKEMON_ENTON,
	POKEMON_WAILMER,
	0xFFFF
};

u16 dungeon_ocean_wild_pokemon_water_rare[] = {
	POKEMON_SEEJONG,
	POKEMON_PELIPPER,
	POKEMON_ENTORON,
	POKEMON_SEEPER,
	POKEMON_REMORAID,
	POKEMON_KINGLER,
	POKEMON_TENTOXA,
	0xFFFF
};

u16 dungeon_ocean_wild_pokemon_water_super_rare[] = {
	POKEMON_GARADOS,
	POKEMON_SEEMON,
	POKEMON_OCTILLERY,
	POKEMON_WAILORD,
	POKEMON_DRATINI,
  POKEMON_SEEJONG,
  POKEMON_JUGONG,
  POKEMON_AUSTOS,
  POKEMON_TOHAIDO,
	0xFFFF
};

u16 dungeon_ocean_wild_pokemon_rod[] = {
	POKEMON_KARPADOR,
	POKEMON_TENTACHA,
	POKEMON_MUSCHAS,
	POKEMON_KRABBY,
	POKEMON_KREBSCORPS,
	0xFFFF
};

u16 dungeon_ocean_wild_pokemon_good_rod[] = {
	POKEMON_SEEPER,
	POKEMON_PERLU,
	POKEMON_REMORAID,
	POKEMON_KANIVANHA,
	0xFFFF
};

u16 dungeon_ocean_wild_pokemon_super_rod[] = {
	POKEMON_TOHAIDO,
	POKEMON_RELICANTH,
	POKEMON_KREBUTACK,
	POKEMON_KINGLER,
	0xFFFF
};


void dungeon2_set_encounter_ocean() {
  dungeon_generator2 *dg2 = &(cmem.dg2);
  dungeon2_ocean_init_state(dg2);
  pokemon_clear_opponent_party();

  u16 species = *var_access(DUNGEON_OVERWORLD_SPECIES);
  u8 mean = 0, std_deviation = 0;
  dungeon2_get_wild_pokemon_level_distribution(&mean, &std_deviation);
  mean = (u8)(mean + std_deviation + std_deviation / 2); // High level for this pokemon

  int level = FIXED_TO_INT(FIXED_ADD(INT_TO_FIXED(mean), FIXED_MUL(INT_TO_FIXED(std_deviation),
        dungeon2_rnd_normal(dg2))));
  level = MAX(MIN(level, 100), 2);

  pid_t p = {dungeon2_rnd(dg2)};

  pokemon_spawn_by_seed_algorithm(&opponent_pokemon[0], species, (u8)level, 32, true, p, false, 0,
      dungeon2_encounter_rnd_generator, dungeon2_encounter_rnd_generator);
}

void dungeon2_init_wild_pokemon_ocean(dungeon_generator2 *dg2) {
  // Pick four common pokemon
  u16 common_pokemon[2];
  dungeon2_pick_wild_pokemon(common_pokemon, 2, dungeon_ocean_wild_pokemon_water_common, dg2);
  // Pick one rare pokemon
  u16 rare_pokemon[3];
  dungeon2_pick_wild_pokemon(rare_pokemon, 2, dungeon_ocean_wild_pokemon_water_rare, dg2);
  // Pick one super rare pokemon
  u16 super_rare_pokemon[2];
  dungeon2_pick_wild_pokemon(super_rare_pokemon, 1, dungeon_ocean_wild_pokemon_water_super_rare,
		  dg2);

  *var_access(DUNGEON_OVERWORLD_SPECIES) = super_rare_pokemon[0];

  fmem.dwild_pokemon.grass = NULL;
  fmem.dwild_pokemon.water = &(fmem.dwild_habitat_water);
  fmem.dwild_pokemon.other = NULL;
  fmem.dwild_pokemon.rod = &(fmem.dwild_habitat_rod);
  fmem.dwild_habitat_water.frequency = DTYPE_OCEAN_WILD_POKEMON_FREQUENCY_WATER;
  fmem.dwild_habitat_water.data = fmem.dwild_data_water;
  fmem.dwild_habitat_rod.frequency = DTYPE_OCEAN_WILD_POKEMON_FREQUENCY_ROD;
  fmem.dwild_habitat_rod.data = fmem.dwild_data_rod;

  // Water

  // The first common pokemon has 60%, the second 30% probability
  fmem.dwild_data_water[0].species = common_pokemon[0];
  fmem.dwild_data_water[1].species = common_pokemon[1];

  // The two rare pokemon have a 5% probatility each
  fmem.dwild_data_water[2].species = rare_pokemon[0];
  fmem.dwild_data_water[3].species = rare_pokemon[1];
  fmem.dwild_data_water[4].species = rare_pokemon[1];

  // Rod

  // The rod pokemon have 70% and 30% probability
  dungeon2_pick_wild_pokemon(common_pokemon, 2, dungeon_ocean_wild_pokemon_rod, dg2);
  fmem.dwild_data_rod[0].species = common_pokemon[0];
  fmem.dwild_data_rod[1].species = common_pokemon[1];

  // The good rod pokemon have 60% and 40% probability
  dungeon2_pick_wild_pokemon(rare_pokemon, 3, dungeon_ocean_wild_pokemon_good_rod, dg2);
  fmem.dwild_data_rod[2].species = rare_pokemon[0];
  fmem.dwild_data_rod[3].species = rare_pokemon[1];
  fmem.dwild_data_rod[4].species = rare_pokemon[1];

  // The super rood pokemon: 60% a good rod, 30% for the first, 10% for the second
  dungeon2_pick_wild_pokemon(super_rare_pokemon, 2, dungeon_ocean_wild_pokemon_super_rod, dg2);
  fmem.dwild_data_rod[5].species = rare_pokemon[2];
  fmem.dwild_data_rod[6].species = super_rare_pokemon[0];
  fmem.dwild_data_rod[7].species = super_rare_pokemon[1];
  fmem.dwild_data_rod[8].species = super_rare_pokemon[1];
  fmem.dwild_data_rod[9].species = super_rare_pokemon[1];

  u8 mean = 0;
  u8 std_deviation = 0;
  u8 level_min = 0;
  u8 level_max = 0;
  dungeon2_get_wild_pokemon_level_distribution(&mean, &std_deviation);

  for(int i = 0; i < 5; i++) {
    dungeon2_wild_pokemon_sample_level_boundaries(&level_min, &level_max,
        (i < 6) ? mean : (u8)(mean + std_deviation), std_deviation, dg2);
    fmem.dwild_data_water[i].level_min = level_min;
    fmem.dwild_data_water[i].level_max = level_max;
  }

  for(int i = 0; i < 10; i++) {
	  dungeon2_wild_pokemon_sample_level_boundaries(&level_min, &level_max,
		  (i < 6) ? mean : (u8)(mean + std_deviation), std_deviation, dg2);
	  fmem.dwild_data_rod[i].level_min = level_min;
	  fmem.dwild_data_rod[i].level_max = level_max;
	}

}


