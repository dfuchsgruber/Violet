/*
 * wild_pokemon.c
 *
 *  Created on: Jun 3, 2018
 *      Author: dominik
 */

#include "types.h"
#include "dungeon2.h"
#include "prng.h"

void dungeon2_pick_wild_pokemon(u16 *dst, int number, u16 *src) {
  int size = 0;
  while(src[size] != 0xFFFF) size++;
  for(int picked = 0; picked < number; picked++) {
    // Pick an index not in dst[:picked]
    while(1) {
      u16 suggestion = src[rnd16() % size];
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
    u8 std_deviation) {
  FIXED fx1 = FIXED_ADD(INT_TO_FIXED(mean), FIXED_MUL(INT_TO_FIXED(std_deviation), rnd_normal()));
  FIXED fx2 = FIXED_ADD(INT_TO_FIXED(mean), FIXED_MUL(INT_TO_FIXED(std_deviation), rnd_normal()));
  int x1 = FIXED_TO_INT(fx1);
  int x2 = FIXED_TO_INT(fx2);
  if (x1 < 2) { x1 = 2; }
  if (x1 > 100) { x1 = 100; }
  if (x2 < 2) { x2 = 2; }
  if (x2 > 100) { x2 = 100; }
  if (x1 < x2) {
    *level_min = (u8)x1;
    *level_max = (u8)x2;
  } else {
    *level_min = (u8)x2;
    *level_max = (u8)x1;
  }
}

