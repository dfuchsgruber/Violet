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

void dungeon2_pick_wild_pokemon(u16 *dst, int number, u16 *src, dungeon_generator2 *dg2) {
  int size = 0;
  while(src[size] != 0xFFFF) size++;
  for(int picked = 0; picked < number; picked++) {
    // Pick an index not in dst[:picked]
    while(1) {
      u16 suggestion = src[dungeon2_rnd_16(dg2) % size];
      // Check if suggestion is not in dst[:picked]
      int valid = 1;
      for(int i = 0; i < picked; i++) {
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

void dungeon2_wild_pokemon_sample_level_boundaries(u8 *level_min, u8 *level_max, u8 mean,
    u8 std_deviation, dungeon_generator2 *dg2) {
  FIXED fx1 = FIXED_ADD(INT_TO_FIXED(mean), FIXED_MUL(INT_TO_FIXED(std_deviation),
      dungeon2_rnd_normal(dg2)));
  FIXED fx2 = FIXED_ADD(INT_TO_FIXED(mean), FIXED_MUL(INT_TO_FIXED(std_deviation),
      dungeon2_rnd_normal(dg2)));
  int x1 = min(100, max(2, FIXED_TO_INT(fx1)));
  int x2 = min(100, max(2, FIXED_TO_INT(fx2)));
  *level_min = (u8)min(x1, x2);
  *level_max = (u8)max(x1, x2);
}

