/*
 * incubator.c
 *
 *  Created on: Mar 7, 2019
 *      Author: dominik
 */

#include "pokepad/incubator.h"
#include "agbmemory.h"
#include "constants/flags.h"
#include "constants/pokemon_attributes.h"
#include "constants/vars.h"
#include "flags.h"
#include "pokemon/basestat.h"
#include "pokemon/virtual.h"
#include "save.h"
#include "types.h"
#include "vars.h"

int incubator_available_slots() {
    if (checkflag(FLAG_INCUBATOR)) {
        return *var_access(INCUBATOR_SLOTS);
    }
    return 0;
}

bool incubator_has_empty_slots() {
    for (int i = 0; i < incubator_available_slots(); i++) {
        if (box_pokemon_get_attribute(&cmem.incubator_slots[i], ATTRIBUTE_SPECIES, 0) == 0)
            return true;
    }
    return false;
}

int incubator_egg_get_progress(box_pokemon *egg) {
    int species = box_pokemon_get_attribute(egg, ATTRIBUTE_SPECIES, 0);
    if (species == 0)
        return 0;
    int cycles_total = basestats[species].egg_cycles;
    int cycles_remaining = box_pokemon_get_attribute(egg, ATTRIBUTE_HAPPINESS, 0);
    if (cycles_remaining == BREEDING_CYCLES_HATCH_IMMEDIATLEY)
        cycles_remaining = 0;
    return (cycles_total - cycles_remaining) * 64 / cycles_total;
}

void incubator_remove_egg(int slot, box_pokemon *target) {
    if (target)
        memcpy(target, &cmem.incubator_slots[slot], sizeof(box_pokemon));
    memset(&cmem.incubator_slots[slot], 0, sizeof(box_pokemon));
}

void incubator_clear() {
    for (int i = 0; i < 3; i++) {
        memset(&cmem.incubator_slots[i], 0, sizeof(box_pokemon));
    }
}

bool incubator_attempt_add_slot() {
    int num_hatches = save_get_key(SAVE_KEY_EGGS_HATCHED);
    *var_access(0x8004) = (u16)num_hatches;
    u16 slots_available = 0;
    if (checkflag(FLAG_INCUBATOR)) {
        slots_available = 1;
        if (num_hatches > 3)
            slots_available++;
        if (num_hatches > 15)
            slots_available++;
        // Check if previously less slots were available
        if (incubator_available_slots() < slots_available) {
            *var_access(INCUBATOR_SLOTS) = slots_available;
            return true;
        }
    }
    return false;
}
