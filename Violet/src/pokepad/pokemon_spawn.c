#include "types.h"
#include "pokemon/virtual.h"
#include "pokemon/breeding.h"
#include "pokemon/basestat.h"
#include "pokepad/state.h"
#include "debug.h"
#include "constants/pokemon_attributes.h"
#include "prng.h"
#include "agbmemory.h"

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

static u16 default_feature_generator() {
  return (u16)(rnd16() & 511);
}

void pokemon_spawn_by_seed_algorithm(pokemon *p, u16 species, u8 level, u8 default_iv,
    bool pid_determined, pid_t pid, bool tid_determined, u32 tid, u16(*feature_generator)(),
	u16(*rng)()) {

	if (!rng) rng = rnd16;  // default rng
  if (!feature_generator) feature_generator = default_feature_generator; // Why use the seed algorithm then in the first place?

    //first we random a pid
    if (!pid_determined)
      pid = pokemon_new_pid(species);

    if (!feature_generator()) {
        pid.fields.is_shiny = 1;
    } else {
    	pid.fields.is_shiny = 0;
    }

    // Set hidden power strength
    pid.fields.hidden_power_strength = (u8)((7 - ((feature_generator() >> 6) & 7)) & 7);

    pokemon_new(p, species, level, default_iv, true, pid, tid_determined, tid);
    //now we add ivs
    int i;
    int ivs[6];
    pokemon_spawn_by_algorithm_generate_ivs(ivs, default_iv, feature_generator, rng);
    for (i = 0; i < 6; i++) {
		pokemon_set_attribute(p, (u16) (ATTRIBUTE_HP_IV + i), &ivs[i]);
    }
    //now we add hidden ability
    if (feature_generator() < 16)
    	pokemon_set_hidden_ability(&p->box);

    int r;
    //now we add egg moves
    int egg_move_cnt = 0;
    u16 *egg_moves_rom = pokemon_get_egg_moves(species, &egg_move_cnt);
    if (egg_move_cnt) {
    	u16 *egg_moves = malloc(sizeof(u16) * (u32)egg_move_cnt);
    	memcpy(egg_moves, egg_moves_rom, sizeof(u16) * (u32)egg_move_cnt);
      DEBUG("Returned egg moves %x for species %d of size %d\n", egg_moves, species, egg_move_cnt);
      for (int attached = 0; attached < 4 && egg_move_cnt > 0; attached++) {
        //we attach a random egg move
        if (feature_generator() >= 32) continue; 
        int n = rng() % egg_move_cnt;
        if (pokemon_append_attack(&opponent_pokemon[0], egg_moves[n]) == 0xFFFF) {
          pokemon_rotate_and_push_attack(&opponent_pokemon[0], egg_moves[n]);
        }
        egg_moves[n] = egg_moves[--egg_move_cnt];
      }
      free(egg_moves);
    }

    //now we give the item
    r = feature_generator();
    if (r < 32) {
        u16 *item = &basestats[species].common_item;
        if (r < 8 && basestats[species].rare_item) {
            item = &basestats[species].rare_item;
        }
        pokemon_set_attribute(p, ATTRIBUTE_ITEM, item);
    }
    pokemon_calculate_stats(&opponent_pokemon[0]);
}



