#include "types.h"
#include <stdbool.h>
#include "trainer/build.h"
#include "pokemon/virtual.h"
#include "constants/natures.h"
#include "constants/pokemon_attributes.h"
#include "constants/difficulties.h"
#include "constants/story_states.h"
#include "vars.h"
#include "prng.h"
#include "data_structures.h"
#include "trainer/party.h"
#include "constants/vars.h"
#include "attack.h"
#include "agbmemory.h"
#include "battle/state.h"
#include "trainer/trainer.h"
#include "save.h"
#include "constants/trainer_builds.h"
#include "debug.h"

u16 trainer_pokemon_prng() {
	return (u16)_prng_xorshift(&(fmem.trainer_prng_state));
}

void trainer_pokemon_new_custom_item_default_attacks(pokemon *dst,
		trainer_pokemon_custom_item_default_attacks *party) {
	// Obtain the prng state that was seeded with the trainer id
	pid_t pid = pokemon_new_pid_by_prng(trainer_pokemon_prng);
	pid.fields.is_shiny = 0;
	pokemon_new(dst, party->species, party->level, party->ivs, true, pid, false, 0);
	trainer_pokemon_new(dst, party->build);
	// Custom item
	pokemon_set_attribute(dst, ATTRIBUTE_ITEM, &(party->item));
}

void trainer_pokemon_new_custom_item_custom_attacks(pokemon *dst,
		trainer_pokemon_custom_item_custom_attacks *party) {
	// Obtain the prng state that was seeded with the trainer id
	pid_t pid = pokemon_new_pid_by_prng(trainer_pokemon_prng);
	pid.fields.is_shiny = 0;
	pokemon_new(dst, party->species, party->level, party->ivs, true, pid, false, 0);
	trainer_pokemon_new(dst, party->build);
	// Custom item
	pokemon_set_attribute(dst, ATTRIBUTE_ITEM, &(party->item));
	// Custom attacks
	for (int i = 0; i < 4; i++) {
		pokemon_set_attribute(dst, (u8)(ATTRIBUTE_ATTACK1 + i), &(party->moves[i]));
		pokemon_set_attribute(dst, (u8)(ATTRIBUTE_PP1 + i), &(attacks[party->moves[i]].pp));
	}
}

void trainer_pokemon_new_default_item_custom_attacks(pokemon *dst,
		trainer_pokemon_default_item_custom_attacks *party) {
	// Obtain the prng state that was seeded with the trainer id
	pid_t pid = pokemon_new_pid_by_prng(trainer_pokemon_prng);
	pid.fields.is_shiny = 0;
	pokemon_new(dst, party->species, party->level, party->ivs, true, pid, false, 0);
	trainer_pokemon_new(dst, party->build);
	// Custom attacks
	for (int i = 0; i < 4; i++) {
		pokemon_set_attribute(dst, (u8)(ATTRIBUTE_ATTACK1 + i), &(party->moves[i]));
		pokemon_set_attribute(dst, (u8)(ATTRIBUTE_PP1 + i), &(attacks[party->moves[i]].pp));
	}
}

void trainer_pokemon_new_default_item_default_attacks(pokemon *dst,
		trainer_pokemon_default_item_default_attacks *party) {
	// Obtain the prng state that was seeded with the trainer id
	pid_t pid = pokemon_new_pid_by_prng(trainer_pokemon_prng);
	pid.fields.is_shiny = 0;
	pokemon_new(dst, party->species, party->level, party->ivs, true, pid, false, 0);
	trainer_pokemon_new(dst, party->build);
}

static int party_setup_by_trainer_idx(pokemon *dst_party, u16 trainer_id) {
	// To generate a trainer consistent pid we use a pseudo rng
	fmem.trainer_prng_state = trainer_id;
	for (int i = 0; i < trainers[trainer_id].pokemon_cnt; i++) {
		if (trainers[trainer_id].uses_custom_items &&
				trainers[trainer_id].uses_custom_moves) {
			trainer_pokemon_custom_item_custom_attacks* party =
					(trainer_pokemon_custom_item_custom_attacks*)trainers[trainer_id].party;
			trainer_pokemon_new_custom_item_custom_attacks(&dst_party[i], &party[i]);
		} else if (trainers[trainer_id].uses_custom_items) {
			trainer_pokemon_custom_item_default_attacks* party =
					(trainer_pokemon_custom_item_default_attacks*)trainers[trainer_id].party;
			trainer_pokemon_new_custom_item_default_attacks(&dst_party[i], &party[i]);
		} else if (trainers[trainer_id].uses_custom_moves) {
			trainer_pokemon_default_item_custom_attacks* party =
					(trainer_pokemon_default_item_custom_attacks*)trainers[trainer_id].party;
			trainer_pokemon_new_default_item_custom_attacks(&dst_party[i], &party[i]);
		} else {
			trainer_pokemon_default_item_default_attacks* party =
					(trainer_pokemon_default_item_default_attacks*)trainers[trainer_id].party;
			trainer_pokemon_new_default_item_default_attacks(&dst_party[i], &party[i]);
		}
	}
	battle_flags |= trainers[trainer_id].battle_state;
	return trainers[trainer_id].pokemon_cnt;
	
}


int trainer_party_setup() {
	int num_pokemon_setup = 0;
	if (!(battle_flags & BATTLE_TOWER) && !(battle_flags & BATTLE_EREADER)
			&& !(battle_flags & BATTLE_31) && (battle_flags & BATTLE_TRAINER)) {
		if (battle_flags & BATTLE_TRAINER) {
			pokemon_clear_opponent_party();	
			num_pokemon_setup += party_setup_by_trainer_idx(opponent_pokemon, trainer_vars.trainer_id);
		}
		if ((battle_flags & BATTLE_TWO_TRAINERS) && (battle_flags & BATTLE_TRAINER))
			num_pokemon_setup += party_setup_by_trainer_idx(opponent_pokemon + 3, fmem.trainer_varsB.trainer_id);
	}
	return num_pokemon_setup;
}

void ally_party_setup() {
	u16 trainer_idx = *var_access(VAR_ALLY);
	memset(player_pokemon + 3, 0, 3 * sizeof(pokemon));
	party_setup_by_trainer_idx(player_pokemon + 3, trainer_idx);
	u32 tid = (u32)(trainer_pokemon_prng() % 100000);
	// Change OT-name
	fmem.trainer_prng_state = trainer_idx;
	for (int i = 3; i < 6; i++) {
		if (pokemon_get_attribute(player_pokemon + i, ATTRIBUTE_SPECIES, 0) != 0) {
			pokemon_set_attribute(player_pokemon + i, ATTRIBUTE_OT_NAME, trainer_get_name(trainer_idx));
			pokemon_set_attribute(player_pokemon + i, ATTRIBUTE_TID, &tid);
		}
	}
}


void trainer_pokemon_new(pokemon *poke, union union_build_field field) {
	pid_t pid = {.value = (u32)pokemon_get_attribute(poke, 0, 0)};
	u8 ev_difficulty = 0; // EVs that are applied due to difficulty
	switch(*var_access(DIFFICULTY)) {
		case DIFFICULTY_HARD: ev_difficulty = 7; break; // 28 EVs on each stat
		case DIFFICULTY_VERY_HARD: ev_difficulty = 21; break; // 84 EVs on each stat
		}
	if (field.bitfield.build_idx == TRAINER_BUILD_NONE) {
		// Distribute evs according to difficulty
		for (int i = 0; i < 6; i++) {
			pokemon_set_effective_ev(poke, i, ev_difficulty);
			pokemon_set_potential_ev(poke, i, (u8)(4 * ev_difficulty));
		}
	} else {
		// Apply the build of the trainer
		u8 effective_ev_story = 0;
		switch(*var_access(STORY_STATE)) {
		case STORY_STATE_SILVANIA_FOREST_CLEAR: effective_ev_story = 7; break;
		case STORY_STATE_VULCANO_CLEAR: effective_ev_story = 15; break;
		}
		effective_ev_story = (u8)(effective_ev_story + ev_difficulty);
		for (int i = 0; i < 6; i++) {
			u8 ev = trainer_builds[field.bitfield.build_idx].evs[i];
			if (ev == 255) ev = effective_ev_story;
			pokemon_set_effective_ev(poke, i, ev);
			pokemon_set_potential_ev(poke, i, (u8)(4 * ev));
		}
		// Apply nature if present
		u8 nature = trainer_builds[field.bitfield.build_idx].nature;
		if (nature != 255) {
			pid.fields.nature = (u8)(nature & 0x1F);
		}
		// Apply hidden power type
		u8 hidden_power_type = trainer_builds[field.bitfield.build_idx].hidden_power_type;
		if (hidden_power_type != 255) {
			pid.fields.hidden_power_type = (u8)(hidden_power_type & 0x1F);
		}
		// Apply hidden power strength
		u8 hidden_power_strength = trainer_builds[field.bitfield.build_idx].hidden_power_strength;
		if (hidden_power_strength != 255) {
			pid.fields.hidden_power_strength = (u8)(hidden_power_strength & 7);
		}
		// Apply the ability bit to the pokemon
		int ability = field.bitfield.ability > 0;
		pokemon_set_attribute(poke, ATTRIBUTE_ABILITY, &ability);
	}
	pid.fields.is_shiny = field.bitfield.is_shiny > 0;
	pokemon_set_attribute(poke, ATTRIBUTE_PID, &pid);
	if (field.bitfield.has_hidden_ability)
			pokemon_set_hidden_ability(&poke->box);

	if (!pokemon_get_attribute(poke, ATTRIBUTE_ITEM, 0)) {
		pokemon_set_attribute(poke, ATTRIBUTE_ITEM,
				&trainer_builds[field.bitfield.build_idx].prefered_item);
	}
	pokemon_calculate_stats(poke);
}
