#include "types.h"
#include "pokemon/virtual.h"
#include "pokemon/egg_moves.h"
#include "pokemon/basestat.h"
#include "pokepad/state.h"
#include "debug.h"
#include "constants/pokemon_attributes.h"
#include "prng.h"

void pokemon_spawn_by_algorithm_generate_ivs(int *ivs, u8 default_iv, u16(*feature_generator)(),
		u16(*rng)()) {
    int i;
    int p = feature_generator();
    for (i = 0; i < 6; i++) {
    	if (p < 128) {
    		ivs[i] = 31;
    		p += 16;
    	} else {
    		if (default_iv < 32) {
    			ivs[i] = default_iv;
    		} else {
    			ivs[i] = rng() & 31;
    		}
    	}
    }
}

void pokemon_spawn_by_seed_algorithm(pokemon *p, u16 species, u8 level, u8 default_iv,
    bool pid_determined, pid_t pid, bool tid_determined, u32 tid, u16(*feature_generator)(),
	u16(*rng)()) {

	if (!rng) rng = rnd16;  // default rng

    //first we random a pid
    if (!pid_determined)
      pid.value = (u32) (rng() | rng() << 16);

    if (!feature_generator()) {
        pid.fields.shinyness = 0;
    }
    pokemon_new(p, species, level, default_iv, true, pid, tid_determined, tid);
    //now we add ivs
    int i;
    int ivs[6];
    pokemon_spawn_by_algorithm_generate_ivs(ivs, default_iv, feature_generator, rng);
    for (i = 0; i < 6; i++) {
		pokemon_set_attribute(p, (u16) (ATTRIBUTE_HP_IV + i), &ivs[i]);
    }
    //now we add hidden ability
    int value = 0x80;
    if (feature_generator() < 16) {
        pokemon_set_attribute(p, ATTRIBUTE_COOLNESS, &value);
    }

    //now we add egg moves
    int egg_move_cnt = 0;
    u16 *egg_moves = pokemon_get_egg_moves(species, &egg_move_cnt);
    dprintf("Returned egg moves %x for species %d of size %d\n", egg_moves, species, egg_move_cnt);
    int seed = feature_generator();
    int attached = 0;
    while (seed < 64 && egg_move_cnt && attached < 4 && egg_move_cnt) {
        //we attach a random egg move
        int n = rng() % egg_move_cnt;
        if (pokemon_append_attack(&opponent_pokemon[0], egg_moves[n]) == 0xFFFF) {
            pokemon_rotate_and_push_attack(&opponent_pokemon[0], egg_moves[n]);
        }
        egg_moves[n] = egg_moves[--egg_move_cnt];
        attached++;
        seed += 16;
    }

    //now we give the item
    seed = feature_generator();
    if (seed < 32) {
        u16 *item = &basestats[species].common_item;
        if (seed < 8 && basestats[species].rare_item) {
            item = &basestats[species].rare_item;
        }
        pokemon_set_attribute(p, ATTRIBUTE_ITEM, item);
    }
    pokemon_calculate_stats(&opponent_pokemon[0]);
}



