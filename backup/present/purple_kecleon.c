/*
 * purple_kecleon.c
 *
 *  Created on: Oct 1, 2018
 *      Author: dominik
 */
#include "types.h"
#include "pokemon/virtual.h"
#include "constants/species.h"
#include "constants/attacks.h"
#include "constants/pokemon_attributes.h"
#include "pokepad/pokedex/operator.h"
#include "agbmemory.h"
#include "language.h"
#include "vars.h"
#include "constants/vars.h"

void present_give_purple_kecleon() {
	u8 ot[] = PSTRING("Wodka");
	u32 tid = tid_by_ot_name(ot);
	pokemon *p = malloc(sizeof(pokemon));
	pid_t pid = {.value = 0};
	pokemon_new(p, POKEMON_KECLEON_PURPLE, 15, 0, false, pid, true, tid);
	pokemon_set_attribute(p, ATTRIBUTE_OT_NAME, ot);
	pokemon_rotate_and_push_attack(p, ATTACK_DRACHENTANZ);
	// Set 31-ivs
	u8 iv = 31;
	for (int i = 0; i < 6; i++) {
		pokemon_set_attribute(p, (u8)(ATTRIBUTE_HP_IV + i), &iv);
	}
	pokemon_set_hidden_ability(&p->box);
	int result = pokemon_give_with_player_not_ot(p);
	if (result != 2) {
		pokedex_operator(POKEMON_KECLEON_PURPLE, POKEDEX_SET | POKEDEX_SEEN, true);
		pokedex_operator(POKEMON_KECLEON_PURPLE, POKEDEX_SET | POKEDEX_CAUGHT, true);
	}
	free(p);
	*var_access(LASTRESULT) = (u16)result;
}
