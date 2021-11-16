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
#include "dungeon/dungeon2.h"

u16 trainer_pokemon_prng() {
	return (u16)_prng_xorshift(&(fmem.trainer_prng_state));
}

static u8 trainer_pokemon_get_level(u8 level) {
	if (level == TRAINER_POKEMON_LEVEL_STORY_BASED) {
		u8 mean = 5;
		u8 std = 0;
		dungeon2_get_wild_pokemon_level_distribution(&mean, &std);
		level = mean;
	} else if (level == TRAINER_POKEMON_LEVEL_STORY_BASED_PLUS_ONE_STD) {
		u8 mean = 5;
		u8 std = 0;
		dungeon2_get_wild_pokemon_level_distribution(&mean, &std);
		level = (u8)(mean + std);
	}
	return MIN(100, MAX(1, level));
}

void trainer_pokemon_new_custom_item_default_attacks(pokemon *dst,
		trainer_pokemon_custom_item_default_attacks *party) {
	// Obtain the prng state that was seeded with the trainer id
	pid_t pid = pokemon_new_pid_by_prng(trainer_pokemon_prng);
	pid.fields.is_shiny = 0;
	pokemon_new(dst, party->species, trainer_pokemon_get_level(party->level), party->ivs, true, pid, false, 0);
	trainer_pokemon_new(dst, party->build);
	// Custom item
	pokemon_set_attribute(dst, ATTRIBUTE_ITEM, &(party->item));
}

void trainer_pokemon_new_custom_item_custom_attacks(pokemon *dst,
		trainer_pokemon_custom_item_custom_attacks *party) {
	// Obtain the prng state that was seeded with the trainer id
	pid_t pid = pokemon_new_pid_by_prng(trainer_pokemon_prng);
	pid.fields.is_shiny = 0;
	pokemon_new(dst, party->species, trainer_pokemon_get_level(party->level), party->ivs, true, pid, false, 0);
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
	pokemon_new(dst, party->species, trainer_pokemon_get_level(party->level), party->ivs, true, pid, false, 0);
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
	pokemon_new(dst, party->species, trainer_pokemon_get_level(party->level), party->ivs, true, pid, false, 0);
	trainer_pokemon_new(dst, party->build);
}


static int party_setup_by_trainer_idx(pokemon *dst_party, u16 trainer_id) {
	if (trainer_id >= 0x1e0 && trainer_id < 0x1e4)
		dungeon2_init_trainer(trainer_id);
	// To generate a trainer consistent pid we use a pseudo rng
	fmem.trainer_prng_state = trainer_id;
	size_t idxs[6] = {0, 1, 2, 3, 4, 5};
	if (*var_access(DIFFICULTY) == DIFFICULTY_HARD) {  // Shuffle
		shuffle(idxs, trainers[trainer_id].pokemon_cnt, NULL);
	}
	for (int j = 0; j < trainers[trainer_id].pokemon_cnt; j++)
		DEBUG("Shuffled team order %d : %d\n", j, idxs[j]);
	for (int j = 0; j < trainers[trainer_id].pokemon_cnt; j++) {
		if (trainers[trainer_id].uses_custom_items &&
				trainers[trainer_id].uses_custom_moves) {
			trainer_pokemon_custom_item_custom_attacks* party =
					(trainer_pokemon_custom_item_custom_attacks*)trainers[trainer_id].party;
			trainer_pokemon_new_custom_item_custom_attacks(&dst_party[j], &party[idxs[j]]);
		} else if (trainers[trainer_id].uses_custom_items) {
			trainer_pokemon_custom_item_default_attacks* party =
					(trainer_pokemon_custom_item_default_attacks*)trainers[trainer_id].party;
			trainer_pokemon_new_custom_item_default_attacks(&dst_party[j], &party[idxs[j]]);
		} else if (trainers[trainer_id].uses_custom_moves) {
			trainer_pokemon_default_item_custom_attacks* party =
					(trainer_pokemon_default_item_custom_attacks*)trainers[trainer_id].party;
			trainer_pokemon_new_default_item_custom_attacks(&dst_party[j], &party[idxs[j]]);
		} else {
			trainer_pokemon_default_item_default_attacks* party =
					(trainer_pokemon_default_item_default_attacks*)trainers[trainer_id].party;
			trainer_pokemon_new_default_item_default_attacks(&dst_party[j], &party[idxs[j]]);
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
		case DIFFICULTY_HARD: ev_difficulty = 21; break; // 84 EVs on each stat
		}
	if (field.bitfield.build_idx == TRAINER_BUILD_NONE) {
		// Distribute evs according to difficulty
		for (int i = 0; i < 6; i++) {
			pokemon_set_effective_ev(poke, i, ev_difficulty);
			pokemon_set_potential_ev(poke, i, (u8)(4 * ev_difficulty));
		}
	} else {
		// Apply the build of the trainer
		u8 effective_ev_story;
		switch(*var_access(VAR_STORY_STATE)) {
			case STORY_STATE_SILVANIA_FOREST_DONE: 
			case STORY_STATE_FELSIGE_ODENIS_RIVAL_DONE:
			case STORY_STATE_BLUETENBACH_GYM_DONE:
			case STORY_STATE_ROUTE_6_MISTRAL_IGVA_DONE:
				effective_ev_story = 7; 
				break;
			case STORY_STATE_VULCANO_DONE: 
				effective_ev_story = 15; 
				break;
			default:
				effective_ev_story = 0;
				break;
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

		// Apply gender, if persent
		if (trainer_builds[field.bitfield.build_idx].use_gender) {
			pid.fields.gender_partial = (u32)((trainer_builds[field.bitfield.build_idx].gender >> 1) & 0x7F); // TODO?
		}

		DEBUG("Building pokemon species %d with ability bit %d -> ability is %d\n", pokemon_get_attribute(poke, ATTRIBUTE_SPECIES, 0), ability, pokemon_get_ability(poke));
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
