#include "types.h"
#include "pokemon/roamer.h"
#include "save.h"
#include "agbmemory.h"
#include "constants/species.h"
#include "constants/roamers.h"
#include "constants/pokemon_attributes.h"
#include "constants/map_namespaces.h"
#include "prng.h"
#include "vars.h"
#include "debug.h"
#include "flags.h"
#include "constants/flags.h"

u16 roamer_species[NUM_ROAMERS] = {
    [ROAMER_ARKTOS] = POKEMON_ARKTOS,
    [ROAMER_ZAPDOS] = POKEMON_ZAPDOS,
    [ROAMER_LAVADOS] = POKEMON_LAVADOS
};

roamer_map_t roamer_maps[NUM_ROAMER_MAPS] = {
    // Route 1
    {.bank = 3, .map_idx = 76, .adjacent_maps = {
        {.bank = 11, .map_idx = 2}, // Route 2
    }},
    // Route 2
    {.bank = 11, .map_idx = 2, .adjacent_maps = {
        {.bank = 3, .map_idx = 76}, // Route 1,
        {.bank = 17, .map_idx = 2}, // Route 5
    }},
    // Route 5
    {.bank = 17, .map_idx = 2, .adjacent_maps  = {
        {.bank = 11, .map_idx = 2}, // Route 2
    }},
    // Route 10
    {.bank = 14, .map_idx = 0, .adjacent_maps = {
    }},

};


void roamer_reset_all() {
    for (int i = 0; i < NUM_ROAMERS; i++) {
        roamer_reset(i);
    }
}

void roamer_reset(int roamer_idx) {
    memset(&cmem.roamers[roamer_idx], 0, sizeof(roamer_state_t));
    for (int j = 0; j < 3; j++) {
        cmem.roamer_histories[roamer_idx][j].bank = 0;
        cmem.roamer_histories[roamer_idx][j].map_idx = 0;
    }
    cmem.roamer_locations[roamer_idx].bank = 0;
    cmem.roamer_locations[roamer_idx].map_idx = 0;
}

void roamer_initialize(int roamer_idx) {
    pid_t pid = {0};
    pokemon_new(&opponent_pokemon[0], roamer_species[roamer_idx], ROAMER_LEVEL, POKEMON_NEW_RANDOM_IVS, false, pid, false, 0);
    roamer_state_t *roamer = &cmem.roamers[roamer_idx];
    pid.value = (u32)pokemon_get_attribute(opponent_pokemon, ATTRIBUTE_PID, 0);
    roamer->pid = pid;
    dprintf("Roamer %d initialized with pid %x (shiny: %d)\n", roamer_idx, roamer->pid, roamer->pid.fields.is_shiny);
    roamer->ivs = (u32)pokemon_get_attribute(opponent_pokemon, ATTRIBUTE_IVS, 0);
    roamer->hp = (u16)pokemon_get_attribute(opponent_pokemon, ATTRIBUTE_TOTAL_HP, 0);
    for (int i = 0; i < 4; i++) {
        roamer->pps[i] = (u8)pokemon_get_attribute(opponent_pokemon, (u8)(ATTRIBUTE_PP1 + i), 0);
    }
    roamer->status = 0;
    roamer->is_present = 1;
    int roamer_map_idx = rnd16() % NUM_ROAMER_MAPS;
    cmem.roamer_locations[roamer_idx].bank = roamer_maps[roamer_map_idx].bank;
    cmem.roamer_locations[roamer_idx].map_idx = roamer_maps[roamer_map_idx].map_idx;
}

void special_roamer_reset_and_initialize() {
    int roamer_idx = *var_access(0x8004);
    roamer_reset(roamer_idx);
    roamer_initialize(roamer_idx);
}

void roamer_history_update() {
    if (checkflag(ROAMER_LOCATIONS_FIXED)) return;
    for (int i = 0; i < NUM_ROAMERS; i++) {
        cmem.roamer_histories[i][2].bank = cmem.roamer_histories[i][1].bank;
        cmem.roamer_histories[i][2].map_idx = cmem.roamer_histories[i][1].map_idx;
        cmem.roamer_histories[i][1].bank = cmem.roamer_histories[i][0].bank;
        cmem.roamer_histories[i][1].map_idx = cmem.roamer_histories[i][0].map_idx;
        cmem.roamer_histories[i][0].bank = cmem.roamer_locations[i].bank;
        cmem.roamer_histories[i][0].map_idx = cmem.roamer_locations[i].map_idx;
    }
}

void roamer_randomize_position(int roamer_idx) {
    if (checkflag(ROAMER_LOCATIONS_FIXED)) return;
    if (cmem.roamers[roamer_idx].is_present) {
        u8 new_map_idx, new_bank;
        do {
            int new_idx = rnd16() % NUM_ROAMER_MAPS;
            new_bank = roamer_maps[new_idx].bank;
            new_map_idx = roamer_maps[new_idx].map_idx;
        } while (new_bank == cmem.roamer_locations[roamer_idx].bank && new_map_idx == cmem.roamer_locations[roamer_idx].map_idx);
        cmem.roamer_locations[roamer_idx].bank = new_bank;
        cmem.roamer_locations[roamer_idx].map_idx = new_map_idx;
        dprintf("Roamer %d randomized position to %d.%d\n", roamer_idx, new_bank, new_map_idx);
    }
}

void roamer_randomize_position_all() {
    for (int i = 0; i < NUM_ROAMERS; i++) {
        roamer_randomize_position(i);
    }
}

void roamer_move_all() {
    for (int i = 0; i < NUM_ROAMERS; i++) {
        if (cmem.roamers[i].is_present) {
            if (rnd16() % 16 == 0) {
                // 1/16 chance that the roamer randomly changes their location
                roamer_randomize_position(i);
                dprintf("Roamer %d randomly changed their location\n", i);
            } else {
                // Find the index in the roamer map table
                u8 roamer_map_idx;
                for (roamer_map_idx = 0; roamer_map_idx < NUM_ROAMER_MAPS; roamer_map_idx++) {
                    if (cmem.roamer_locations[i].map_idx == roamer_maps[roamer_map_idx].map_idx &&
                        cmem.roamer_locations[i].bank == roamer_maps[roamer_map_idx].bank) {
                        break;
                    }
                }
                if (roamer_map_idx >= NUM_ROAMER_MAPS) {
                    derrf("Roamer location does not correspond to any roamer map.\n");
                    return;
                }
                // Find an adjacent map_idx to reloacte the roamer
                u8 new_bank;
                u8 new_map_idx;
                do {
                    int new_idx = rnd16() % ROAMER_MAP_MAX_NUMBER_ADJACENT_MAPS;
                    new_bank = roamer_maps[roamer_map_idx].adjacent_maps[new_idx].bank;
                    new_map_idx = roamer_maps[roamer_map_idx].adjacent_maps[new_idx].map_idx;
                    if (new_map_idx == 0 && new_bank == 0) {
                        dprintf("Roamer %d stayed on map %d.%d\n", i, cmem.roamer_locations[i].bank, cmem.roamer_locations[i].map_idx);
                        return;
                    }
                } while (new_map_idx == cmem.roamer_histories[i][2].map_idx && new_bank == cmem.roamer_histories[i][2].bank);
                cmem.roamer_locations[i].bank = new_bank;
                cmem.roamer_locations[i].map_idx = new_map_idx;
                dprintf("Roamer %d moved to %d.%d\n", i, new_bank, new_map_idx);
            }
        }
    }
}

void pokemon_new_roamer(int roamer_idx) {
    dprintf("New roamer spawning with pid %x\n", cmem.roamers[roamer_idx].pid);
    pokemon_new_and_set_ivs(opponent_pokemon, roamer_species[roamer_idx], ROAMER_LEVEL, cmem.roamers[roamer_idx].ivs, cmem.roamers[roamer_idx].pid);
    dprintf("New roamer spawned with pid %x\n", pokemon_get_attribute(opponent_pokemon, ATTRIBUTE_PID, 0));
    pokemon_set_attribute(opponent_pokemon, ATTRIBUTE_STATUS, &cmem.roamers[roamer_idx].status);
    pokemon_set_attribute(opponent_pokemon, ATTRIBUTE_CURRENT_HP, &cmem.roamers[roamer_idx].hp);
    for (int i = 0; i < 4; i++) {
        pokemon_set_attribute(opponent_pokemon, (u8)(ATTRIBUTE_PP1 + i), &cmem.roamers[roamer_idx].pps[i]);
    }
}

bool roamer_is_present(u8 bank, u8 map_idx, int roamer_idx) {
    return cmem.roamers[roamer_idx].is_present && cmem.roamer_locations[roamer_idx].bank == bank &&
    cmem.roamer_locations[roamer_idx].map_idx == map_idx;
}

bool wild_pokemon_spawn_roamer() {
    for (u8 i = 0; i < NUM_ROAMERS; i++) {
        dprintf("Roamer %d is present %d at %d.%d\n", i, cmem.roamers[i].is_present, cmem.roamer_locations[i].bank, cmem.roamer_locations[i].map_idx);
        if (roamer_is_present(save1->bank, save1->map, i) && rnd16() % 2 == 0) {
            pokemon_new_roamer(i);
            fmem.roamer_last_encountered = i;
            return true;
        }
    }
    return false;
}

void roamer_last_encountered_update_and_randomize_position() {
    int roamer_idx = fmem.roamer_last_encountered;
    cmem.roamers[roamer_idx].hp = (u16)pokemon_get_attribute(opponent_pokemon, ATTRIBUTE_CURRENT_HP, 0);
    cmem.roamers[roamer_idx].status = (u8)pokemon_get_attribute(opponent_pokemon, ATTRIBUTE_STATUS, 0);
    for (int i = 0; i < 4; i++) {
        cmem.roamers[roamer_idx].pps[i] = (u8)pokemon_get_attribute(opponent_pokemon, (u8)(ATTRIBUTE_PP1 + i), 0);
    }
    roamer_randomize_position(roamer_idx);
}

void roamer_last_encountered_set_not_present() {
    cmem.roamers[fmem.roamer_last_encountered].is_present = false;
}

int species_to_roamer_idx(u16 species) {
    for (int i = 0; i < NUM_ROAMERS; i++) {
        if (species == roamer_species[i]) {
            return i;
        }
    }
    return -1;
}

u8 roamer_get_namespace(int roamer_idx) {
    if (cmem.roamers[roamer_idx].is_present) {
        return get_mapheader(cmem.roamer_locations[roamer_idx].bank, cmem.roamer_locations[roamer_idx].map_idx)->map_namespace;
    } else {
        return MAP_NAMESPACE_NONE;
    }
}