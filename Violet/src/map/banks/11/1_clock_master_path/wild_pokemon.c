#include "map/wild_pokemon.h"
#include "map/route_2_house.h"
#include "prng.h"
#include "save.h"
#include "types.h"
#include "vars.h"

bool map_is_route_2_house() {
    return save1->bank == ROUTE_2_HOUSE_BANK && save1->map == ROUTE_2_HOUSE_MAP;
}

size_t route_2_house_get_special_encounter_idx() {
    u32 seq[] = {0xAF, 0xB1, ROUTE_2_HOUSE_BANK, ROUTE_2_HOUSE_MAP};
    u32 probability[16];
    size_t num_encounters = 0;
    for (size_t i = 0; i <= ARRAY_COUNT(probability) && wild_pokemon_route_2_house_special_encounters[i].species != 0; i++) {
        probability[num_encounters] = wild_pokemon_route_2_house_special_encounters[i].probability;
        num_encounters++;
    }
    gp_rng_seed(daily_events_hash(seq, ARRAY_COUNT(seq)));
    return choice(probability, num_encounters, gp_rnd16);
}

void route_2_house_get_special_encounter_species() {
    size_t idx = route_2_house_get_special_encounter_idx();
    *var_access(0x8004) = wild_pokemon_route_2_house_special_encounters[idx].species;
}

bool wild_battle_route_2_house_initialize_special_encounter() {
    if (!map_is_route_2_house())
        return false;
    if ((rnd16() % 100) >= ROUTE_2_HOUSE_SPECIAL_ENCOUNTER_ODDS)
        return false;
    size_t idx = route_2_house_get_special_encounter_idx();
    if (!wildbattle_is_allowed_by_repel(wild_pokemon_route_2_house_special_encounters[idx].level)) {
        return false;
    }
    pid_t pid = {0};
    pokemon_new(opponent_pokemon, wild_pokemon_route_2_house_special_encounters[idx].species,
                wild_pokemon_route_2_house_special_encounters[idx].level, POKEMON_NEW_RANDOM_IVS, false, pid, false, 0);
    return true;
}
