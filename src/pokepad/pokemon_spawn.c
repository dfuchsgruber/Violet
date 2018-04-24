#include "types.h"
#include "romfuncs.h"
#include "pokemon/virtual.h"
#include "pokemon/egg_moves.h"
#include "pokemon/basestat.h"
#include "pokepad/state.h"
#include "debug.h"
#include "constants/pokemon_attributes.h"

void pokemon_spawn_by_algorithm_generate_ivs(bool *iv_det, int seed) {
    int i;
    for (i = 0; i < 6; i++)
        iv_det[i] = false;
    while (seed < 128) {
        iv_det[rnd16() % 6] = true;
        seed += 16;
    }
}

void pokemon_spawn_by_seed_algorithm(pokemon *p, u16 species, u8 level, u8 ev_spread, bool tid_determined, u32 tid, u16(*seed_generator)()) {
    //dprintf("Spawning pokemon by seed algorithm: species %d, level %d, ev_spread %d, tid_det %d, tid %x, seed_gen %x\n",
    //        species, level, ev_spread, tid_determined, tid, seed_generator);

    //first we random a pid
    pid pid = {(u32) (rnd16() | rnd16() << 16)};

    if (!seed_generator()) {
        pid.fields.shinyness = 0;
    }
    pokemon_new(p, species, level, ev_spread, true, pid, tid_determined, tid);
    //now we add ivs
    int i;
    bool iv_det[6];
    pokemon_spawn_by_algorithm_generate_ivs(iv_det, seed_generator());
    int value = 31;
    for (i = 0; i < 6; i++) {
        if (iv_det[i]) {
            set_pokemons_attribute(p, (u16) (ATTRIBUTE_HP_IV + i), &value);
        }
    }
    //now we add hidden ability
    value = 0x80;
    if (seed_generator() < 16) {
        set_pokemons_attribute(p, ATTRIBUTE_COOLNESS, &value);
    }

    //now we add egg moves
    int egg_move_cnt = 0;
    u16 *egg_moves = pokemon_get_egg_moves(species, &egg_move_cnt);
    dprintf("Returned egg moves %x for species %d of size %d\n", egg_moves, species, egg_move_cnt);
    int seed = seed_generator();
    int attached = 0;
    while (seed < 64 && egg_move_cnt && attached < 4 && egg_move_cnt) {
        //we attach a random egg move
        int n = rnd16() % egg_move_cnt;
        if (pokemon_append_attack(&opponent_pokemon[0], egg_moves[n]) == 0xFFFF) {
            pokemon_rotate_and_push_attack(&opponent_pokemon[0], egg_moves[n]);
        }
        egg_moves[n] = egg_moves[--egg_move_cnt];
        attached++;
        seed += 16;
    }

    //now we give the item
    seed = seed_generator();
    if (seed < 32) {
        u16 *item = &basestats[species].common_item;
        if (seed < 8 && basestats[species].rare_item) {
            item = &basestats[species].rare_item;
        }
        set_pokemons_attribute(p, ATTRIBUTE_ITEM, item);
    }
    recalculate_stats(&opponent_pokemon[0]);
}



