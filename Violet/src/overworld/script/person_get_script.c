/*
 * person_get_script.c
 *
 *  Created on: Feb 4, 2019
 *      Author: dominik
 */

#include "types.h"
#include "overworld/script.h"
#include "map/event.h"
#include "vars.h"
#include "debug.h"
#include "constants/person_script_stds.h"
#include "save.h"
#include "pokemon/virtual.h"
#include "prng.h"
#include "battle/state.h"

extern u8 ow_script_person_pokeball[];
extern u8 ow_script_person_egg[];
extern u8 ow_script_person_pokemon[];
extern u8 ow_script_aggressive_wild[];

static u16 aggressive_wild_pokemon_feature_generator() {
	return (u16)(rnd16() % 200);
}

void aggressive_wild_pokemon_new() {
	u16 species = *var_access(0x8000);
	u8 level = (u8)(*var_access(0x8001));
	pid_t pid = {0};
	pokemon_spawn_by_seed_algorithm(opponent_pokemon, species, level, 32, false, pid, false, 0, aggressive_wild_pokemon_feature_generator, NULL);
}

void battle_initialize_aggressive_wild() {
	super.saved_callback = battle_continuation_wild_legendary_battle_end;
	battle_flags = BATTLE_AGGRESSIVE_WILD | BATTLE_LEGENDARY;
	battle_initialize(battle_get_intro_type(), 0);
	save_increment_key(8);
	save_increment_key(9);
	overworld_script_halt();
}


u8 *person_get_script(u8 target_idx, u8 map_id, u8 bank) {
	map_event_person *p = map_get_person(target_idx, map_id, bank);
	switch(p->script_std) {
	case PERSON_ITEM:
		*var_access(0x8000) = p->value;
		*var_access(0x8001) = 1;
		return ow_script_person_pokeball;
	case PERSON_EGG:
		// dprintf("Person egg\n");
		*var_access(0x8000) = p->value;
		return ow_script_person_egg;
	case PERSON_POKEMON:
		*var_access(0x8000) = p->value;
		return ow_script_person_pokemon;
	case PERSON_AGGRESSIVE_POKEMON:
		*var_access(0x8000) = p->value;
		*var_access(0x8001) = p->argument;
		return ow_script_aggressive_wild;
	default:
		return p->script;
	}
}
