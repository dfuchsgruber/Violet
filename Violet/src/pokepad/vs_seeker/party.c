#include "dungeon/dungeon2.h"
#include "types.h"
#include "pokepad/vs_seeker.h"
#include "trainer/trainer.h"
#include "trainer/virtual.h"
#include "prng.h"
#include "debug.h"


void vs_seeker_setup_trainer_party(u16 trainer_idx, trainer *trainer_dst, trainer_pokemon *party_dst) {
    u8 mean, std;
    dungeon2_get_wild_pokemon_level_distribution(&mean, &std);
    u32 rng_state = trainer_idx;
    *trainer_dst = trainers[trainer_idx];
    trainer_dst->party = party_dst;
    for (int i = 0; i < trainer_dst->pokemon_cnt; i++) {
        int deviation = (u16)_prng_xorshift(&rng_state) % (2 * std);
        u8 level = (u8)MIN(100, MAX(2, mean - std + deviation));
        party_dst[i] = trainers[trainer_idx].party[i];
        party_dst[i].level = MIN(100, MAX(party_dst[i].level, level));
    }
    DEBUG("Setting up rematch trainer party for trainer %d", trainer_idx);
    // TODO: Generate some additional pokemon, add items, etc. based on the story progression
}