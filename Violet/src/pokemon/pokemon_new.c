#include "types.h"
#include "pokemon/virtual.h"
#include "pokemon/breeding.h"
#include "pokemon/basestat.h"
#include "debug.h"
#include "constants/pokemon_attributes.h"
#include "prng.h"
#include "agbmemory.h"

static void pokemon_new_ivs_by_prngs(int *ivs, u8 default_iv, pokemon_new_prngs *prngs,
		u16(*rng)()) {
    int i;
    for (i = 0; i < 6; i++) {
      if (default_iv < 32) {
        ivs[i] = default_iv;
      } else {
        ivs[i] = MIN(31, (rng() & 31) + 31 - MIN(31, (prngs->prngs[POKEMON_NEW_PRNG_MODULUS_IV_BASE + i]() / 16)));
      }
    }
}

static u16 default_pokemon_new_prng() {
  return (u16)(rnd16() & 511);
}


void pokemon_new_by_prngs(pokemon *p, u16 species, u8 level, u8 default_iv,
    bool pid_determined, pid_t pid, bool tid_determined, u32 tid, pokemon_new_prngs *prngs, 
	u16(*rng)()) {

	if (!rng) rng = rnd16;  // default rng
  
    //first we random a pid
    if (!pid_determined)
      pid = pokemon_new_pid(species);

    if (!prngs->prngs[POKEMON_NEW_PRNG_MODULUS_SHINY]()) {
        pid.fields.is_shiny = 1;
    } else {
    	pid.fields.is_shiny = 0;
    }

    // Set hidden power strength
    pid.fields.hidden_power_strength = (u8)((7 - ((prngs->prngs[POKEMON_NEW_PRNG_MODULUS_HIDDEN_POWER_STRENGTH]() >> 6) & 7)) & 7);

    pokemon_new(p, species, level, default_iv, true, pid, tid_determined, tid);
    //now we add ivs
    int i;
    int ivs[6];
    pokemon_new_ivs_by_prngs(ivs, default_iv, prngs, rng);
    for (i = 0; i < 6; i++) {
		pokemon_set_attribute(p, (u16) (ATTRIBUTE_HP_IV + i), &ivs[i]);
    }
    //now we add hidden ability
    if (prngs->prngs[POKEMON_NEW_PRNG_MODULUS_HIDDEN_ABILITY]() < 16)
    	pokemon_set_hidden_ability(&p->box);

    int r;
    //now we add egg moves
    int egg_move_cnt = 0;
    const u16 *egg_moves_rom = pokemon_get_egg_moves(species, &egg_move_cnt);
    if (egg_move_cnt) {
    	u16 *egg_moves = malloc(sizeof(u16) * (u32)egg_move_cnt);
    	memcpy(egg_moves, egg_moves_rom, sizeof(u16) * (u32)egg_move_cnt);
      DEBUG("Returned egg moves %x for species %d of size %d\n", egg_moves, species, egg_move_cnt);
      for (int attached = 0; attached < 4 && egg_move_cnt > 0; attached++) {
        //we attach a random egg move
        if (prngs->prngs[POKEMON_NEW_PRNG_MODULUS_EGG_MOVES]() >= 32) continue; 
        int n = rng() % egg_move_cnt;
        if (pokemon_append_attack(p, egg_moves[n]) == 0xFFFF) {
          pokemon_rotate_and_push_attack(p, egg_moves[n]);
        }
        egg_moves[n] = egg_moves[--egg_move_cnt];
      }
      free(egg_moves);
    }

    //now we give the item
    r = prngs->prngs[POKEMON_NEW_PRNG_MODULUS_ITEM]();
    if (r < 32) {
        const u16 *item = &basestats[species].common_item;
        if (r < 8 && basestats[species].rare_item) {
            item = &basestats[species].rare_item;
        }
        pokemon_set_attribute(p, ATTRIBUTE_ITEM, item);
    }
    pokemon_calculate_stats(p);
}

void pokemon_new_by_prng(pokemon *p, u16 species, u8 level, u8 default_iv,
    bool pid_determined, pid_t pid, bool tid_determined, u32 tid, u16 (*pokemon_new_prng)(), 
	u16(*rng)()) {
    if (!pokemon_new_prng) pokemon_new_prng = default_pokemon_new_prng;
    pokemon_new_prngs prngs = {0};
    for (size_t i = 0; i < POKEMON_NEW_PRNG_NUM_MODULUS; i++) {
      prngs.prngs[i] = pokemon_new_prng;
    }
    pokemon_new_by_prngs(p, species, level, default_iv, pid_determined, pid, tid_determined, tid, &prngs, rng);
  }
