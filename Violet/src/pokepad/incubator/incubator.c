/*
 * incubator.c
 *
 *  Created on: Mar 7, 2019
 *      Author: dominik
 */

#include "types.h"
#include "pokepad/incubator.h"
#include "pokemon/virtual.h"
#include "agbmemory.h"
#include "save.h"
#include "constants/pokemon_attributes.h"
#include "pokemon/basestat.h"

int incubator_available_slots() {
  // TODO:
  return 2; // For testing
}

int incubator_egg_get_progress(box_pokemon *egg) {
  int species = box_pokemon_get_attribute(egg, ATTRIBUTE_SPECIES, 0);
  int cycles_total = basestats[species].egg_cycles;
  int cycles_remaining = box_pokemon_get_attribute(egg, ATTRIBUTE_HAPPINESS, 0);
  return (cycles_total - cycles_remaining) * 64 / cycles_total;
}

void incubator_remove_egg(int slot, box_pokemon *target) {
  if (target) memcpy(target, &cmem.incubator_slots[slot], sizeof(box_pokemon));
  memset(&cmem.incubator_slots[slot], 0, sizeof(box_pokemon));
  cmem.incubator_ready &= (u8)(~(1 << slot));
}

void incubator_clear() {
  for (int i = 0; i < 3; i++) {
    memset(&cmem.incubator_slots[i], 0, sizeof(box_pokemon));
    cmem.incubator_ready &= (u8)(~(1 << i));
  }
}
