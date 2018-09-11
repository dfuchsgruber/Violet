/*
 * wild_pokemon.c
 *
 *  Created on: Sep 1, 2018
 *      Author: dominik
 */
#include "types.h"
#include "vars.h"
#include "constants/vars.h"
#include "map/wild_pokemon.h"
#include "constants/species.h"
#include "debug.h"
#include "pokemon/virtual.h"
#include "prng.h"
#include "save.h"
#include "data_structures.h"
#include "agbmemory.h"

u16 trainerschool_wildbattle_secondary_starter_prng() {
	u32 *state = (u32*)gp_stack_peek();
	return (u16)(_prng_xorshift(state));
}

u16 trainerschool_wildbattle_secondary_starter_feature_generator() {
	int correct_answers = *var_access(TRAINERSCHOOL_CORRECT_ANSWERS);
	if (correct_answers) {;
		int p = trainerschool_wildbattle_secondary_starter_prng();
		return (u16)(p / correct_answers);
	}
	// If you answered no question correctly, you gain nothing
	return 511;
}

bool trainerschool_wildbattle_initialize_secondary_starter() {
	if (*var_access(TRAINERSCHOOL_PROGRESS) == 6) {
		// Spawn the secondary starter
		u16 species = 0;
		switch (*var_access(STARTER_SELECTED)) {
		case 0 : // Grass starter
			species = POKEMON_GLUMANDA;
			break;
		case 1: // Fire starter
			species = POKEMON_SCHIGGY;
			break;
		case 2: // Water starter
			species = POKEMON_BISASAM;
			break;
		default:
			derrf("Unkown starter selection value %d\n", *var_access(STARTER_SELECTED));
		}
		pokemon_clear_opponent_party();
		// Spawn the encounter with the seed algorithm
		// Initialize the seed with the TID
		int *tid_ptr = malloc(sizeof(int));
		*tid_ptr = save2->tid_0 | (save2->tid_1 << 8) | (save2->tid_2<< 16) |
				(save2->tid_3 << 24);
		gp_stack_push((int)tid_ptr);
		// Determine the pid (apart from shinyness)
		pid_t pid = {(u32)(trainerschool_wildbattle_secondary_starter_feature_generator() |
				trainerschool_wildbattle_secondary_starter_feature_generator() << 16)};
		pokemon_spawn_by_seed_algorithm(&opponent_pokemon[0], species, 5, 32,
		    true, pid, false, 0, trainerschool_wildbattle_secondary_starter_feature_generator,
			trainerschool_wildbattle_secondary_starter_prng);
		// If all ten questions were answered correctly, set the pokemon to shiny
		if (*var_access(TRAINERSCHOOL_CORRECT_ANSWERS) == 10) {
			opponent_pokemon[0].pid.fields.shinyness = 0;
		}
		gp_stack_pop();
		free(tid_ptr);
		return true;
	}
	return false;
}

