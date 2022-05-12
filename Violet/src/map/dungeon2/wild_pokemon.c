/*
 * wild_pokemon.c
 *
 *  Created on: Jun 3, 2018
 *      Author: dominik
 */


#include "types.h"
#include "dungeon/dungeon2.h"
#include "prng.h"
#include "math.h"
#include "map/header.h"
#include "dungeon/forest.h"
#include "dungeon/cave.h"
#include "dungeon/ocean.h"
#include "save.h"
#include "debug.h"
#include "flags.h"
#include "vars.h"
#include "constants/story_states.h"

void dungeon2_pick_wild_pokemon(u16 *dst, size_t number, u16 *src, size_t src_size, dungeon_generator2 *dg2) {
  for(size_t picked = 0; picked < number; picked++) {
    // Pick an index not in dst[:picked]
    while(1) {
      u16 suggestion = src[dungeon2_rnd_16(dg2) % src_size];
      // Check if suggestion is not in dst[:picked]
      int valid = 1;
      for(size_t i = 0; i < picked; i++) {
        if(dst[picked] == suggestion) {
          valid = 0;
          break;
        }
      }
      if(valid) {
        // Pick the suggestion
        dst[picked] = suggestion;
        break;
      }
    }
  }
}

void dungeon2_get_wild_pokemon_level_distribution(u8 *mean, u8 *std_deviation) {
  DEBUG("Story state is %d\n", *var_access(VAR_STORY_STATE));
  switch (*var_access(VAR_STORY_STATE)) {
    default: {
      *mean = 5;
      *std_deviation = 1;
      break;
    }
    case STORY_STATE_ROUTE_2_TANN_DONE: {
      *mean = 11;
      *std_deviation = 2;
      break;
    }
    case STORY_STATE_BRUCHFELS_DONE: {
      *mean = 16;
      *std_deviation = 2;
      break;
    }
    case STORY_STATE_FELSIGE_ODENIS_RIVAL_DONE: {
      *mean = 20;
      *std_deviation = 2;
      break;
    }
    case STORY_STATE_SILVANIA_FOREST_DONE: {
      *mean = 27,
      *std_deviation= 2;
      break;
    }
    case STORY_STATE_KUESTENBERG_DONE: {
      *mean = 31;
      *std_deviation = 3;
      break;
    }
    case STORY_STATE_BLUETENBACH_GYM_DONE: {
      *mean = 36;
      *std_deviation = 3;
      break;
    }
    case STORY_STATE_ROUTE_6_MISTRAL_IGVA_DONE: {
      *mean = 39;
      *std_deviation = 3;
      break;
    }
    case STORY_STATE_VULCANO_DONE: {
      *mean = 43;
      *std_deviation = 3;
      break;
    }
  }
}

void dungeon2_wild_pokemon_sample_level_boundaries(u8 *level_min, u8 *level_max, u8 mean,
    u8 std_deviation, dungeon_generator2 *dg2) {
  FIXED fx1 = FIXED_ADD(INT_TO_FIXED(mean), FIXED_MUL(INT_TO_FIXED(std_deviation),
      dungeon2_rnd_normal(dg2)));
  FIXED fx2 = FIXED_ADD(INT_TO_FIXED(mean), FIXED_MUL(INT_TO_FIXED(std_deviation),
      dungeon2_rnd_normal(dg2)));
  int x1 = MIN(100, MAX(2, FIXED_TO_INT(fx1)));
  int x2 = MIN(100, MAX(2, FIXED_TO_INT(fx2)));
  *level_min = (u8)MIN(x1, x2);
  *level_max = (u8)MAX(x1, x2);
}


u16 dungeon2_encounter_rnd_generator() {
  dungeon_generator2 *dg2 = &(cmem.dg2);  // is expected to be initialized
  return dungeon2_rnd_16(dg2) & 127;
}

void dungeon2_set_encounter() {
  switch (dungeon_get_type()) {
  case DTYPE_FOREST:
    dungeon2_set_encounter_forest();
    break;
  case DTYPE_CAVE:
    dungeon2_set_encounter_cave();
    break;
  case DTYPE_OCEAN:
	  dungeon2_set_encounter_ocean();
	  break;
  default:
    ERROR("Unknown dungeon type for overworld encounters %d\n", dungeon_get_type());
  }

}
