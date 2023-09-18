#include "types.h"
#include "overworld/script.h"
#include "flags.h"
#include "constants/species.h"
#include "prng.h"
#include "save.h"
#include "agbmemory.h"
#include "text.h"
#include "pokemon/names.h"
#include "pokepad/pokedex/operator.h"

static const u16 quest_species[] = {
    POKEMON_SKORGLA, POKEMON_SNUBBULL, POKEMON_PANDIR, POKEMON_KASTADUR, POKEMON_WATTZAPF, POKEMON_FUKANO, POKEMON_VOLTOBAL,
    POKEMON_SCHLURP, POKEMON_TANNZA, 0xFFFF
};

static void quest_shuffle_species(u16 *quest_species) {
    u32 state = PLAYER_TID;
    for (int i = (int)ARRAY_COUNT(quest_species) - 1; i > 0; i--) {
        int j = (u16)_prng_xorshift(&state) % i;
        u16 tmp = quest_species[i];
        quest_species[i] = quest_species[j];
        quest_species[j] = tmp;
    }
}

u16 route_7_secret_power_lab_count_missing_species() {
    u16 shuffled_species[ARRAY_COUNT(quest_species)];
    memcpy(shuffled_species, quest_species, sizeof(quest_species));
    quest_shuffle_species(shuffled_species);
    u16 cnt = 0;
    for (int i = 0; i < 3; i++) {
        if (!pokedex_operator(shuffled_species[i], POKEDEX_GET | POKEDEX_CAUGHT, true)) {
            strcpy(ow_script_string_buffers[cnt], pokemon_names[shuffled_species[i]]);
            cnt++;
        }
    }
    return cnt;
}

void route_7_secret_power_lab_buffer_all_species() {
    u16 shuffled_species[ARRAY_COUNT(quest_species)];
    memcpy(shuffled_species, quest_species, sizeof(quest_species));
    quest_shuffle_species(shuffled_species);
    for (int i = 0; i < 3; i++) {
        strcpy(ow_script_string_buffers[i], pokemon_names[shuffled_species[i]]);
        
    }
}