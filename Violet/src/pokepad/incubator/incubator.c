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

bool incubator_has_empty_slots() {
  for (int i = 0; i < incubator_available_slots(); i++) {
    if (box_pokemon_get_attribute(&cmem.incubator_slots[i], ATTRIBUTE_SPECIES, 0) == 0) return true;
  }
  return false;
}

int incubator_egg_get_progress(box_pokemon *egg) {
  int species = box_pokemon_get_attribute(egg, ATTRIBUTE_SPECIES, 0);
  if (species == 0) return 0;
  int cycles_total = basestats[species].egg_cycles;
  int cycles_remaining = box_pokemon_get_attribute(egg, ATTRIBUTE_HAPPINESS, 0);
  if (cycles_remaining == BREEDING_CYCLES_HATCH_IMMEDIATLEY) cycles_remaining = 0;
  return (cycles_total - cycles_remaining) * 64 / cycles_total;
}

void incubator_remove_egg(int slot, box_pokemon *target) {
  if (target) memcpy(target, &cmem.incubator_slots[slot], sizeof(box_pokemon));
  memset(&cmem.incubator_slots[slot], 0, sizeof(box_pokemon));
}

void incubator_clear() {
  for (int i = 0; i < 3; i++) {
    memset(&cmem.incubator_slots[i], 0, sizeof(box_pokemon));
  }
}
