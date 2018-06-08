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

