#include "types.h"
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
#include "debug.h"
#include "dungeon/dungeon2.h"
#include "trainer/virtual.h"

EWRAM trainer_pokemon dynamic_trainer_party[NUM_DYNAMIC_TRAINER_POKEMON] = {0};

u16 trainer_pokemon_prng() {
	return (u16)_prng_xorshift(&(trainer_prng_state));
}

u8 trainer_pokemon_get_level(u8 level) {
	u8 mean = 5, std = 0;
	dungeon2_get_wild_pokemon_level_distribution(&mean, &std);
	switch (level) {
		case TRAINER_POKEMON_LEVEL_STORY_BASED:
			level = mean;
			break;
		case TRAINER_POKEMON_LEVEL_STORY_BASED_PLUS_ONE_STD:
			level = (u8)(level + std);
			break;
	}
	switch (*var_access(DIFFICULTY)) {
		case DIFFICULTY_EASY:
			level = (u8)MAX(1, level - std);
			break;
		case DIFFICULTY_HARD:
			level = (u8)MIN(100, level + std + (std / 2));
			break;
	}
	return MIN(100, MAX(1, level));
}

static u8 get_default_ev() {
	switch (*var_access(VAR_STORY_STATE)) {
		case STORY_STATE_SILVANIA_FOREST_DONE: 
		case STORY_STATE_FELSIGE_ODENIS_RIVAL_DONE:
		case STORY_STATE_BLUETENBACH_GYM_DONE:
		case STORY_STATE_ROUTE_6_MISTRAL_IGVA_DONE:
			return 28;
		case STORY_STATE_VULCANO_DONE: 
			return 16;
		default:
			return 0;
	}
}

static u8 get_default_iv() {
	switch (*var_access(VAR_STORY_STATE)) {
		case STORY_STATE_SILVANIA_FOREST_DONE: 
		case STORY_STATE_FELSIGE_ODENIS_RIVAL_DONE:
		case STORY_STATE_BLUETENBACH_GYM_DONE:
		case STORY_STATE_ROUTE_6_MISTRAL_IGVA_DONE:
			return 9;
		default:
			return 0;
	}

}

static void trainer_pokemon_new(pokemon *p, const trainer_pokemon *template) {
	pid_t pid = pokemon_new_pid_by_prng(template->species, trainer_pokemon_prng);
	pid.fields.is_shiny = false; // by default, trainers will not have shinies
	if (template->ability_set)
		pid.fields.ability = template->pid.fields.ability;
	if (template->gender_set)
		pid.fields.is_female = template->pid.fields.is_female;
	if (template->shiny_set)
		pid.fields.is_shiny = template->pid.fields.is_shiny;
	if (template->hidden_power_type_set)
		pid.fields.hidden_power_type = template->pid.fields.hidden_power_type;
	if (template->hidden_power_strength_set)
		pid.fields.hidden_power_strength = template->pid.fields.hidden_power_strength;
	if (template->unown_letter_set)
		pid.fields.unown_letter = template->pid.fields.unown_letter;
	if (template->nature_set)
		pid.fields.nature = template->pid.fields.nature;
	if (template->form_set)
		pid.fields.form = template->pid.fields.form;
	pokemon_new(p, template->species, trainer_pokemon_get_level(template->level), 0, true, pid, false, 0);
	u8 default_ev = get_default_ev();
	u8 default_iv = get_default_iv();
	for (int i = 0; i < 6; i++) {
		pokemon_set_attribute(p, ATTRIBUTE_HP_IV + i, 
			template->ivs_set ? template->ivs + i : &default_iv);
		pokemon_set_effective_ev(p, i,
			(u8)(template->evs_set ? template->evs[i] / 4 : default_ev / 4));
		pokemon_set_potential_ev(p, i,
			template->evs_set ? template->evs[i] : default_ev);
	}
	if (template->held_item)
		pokemon_set_attribute(p, ATTRIBUTE_ITEM, &template->held_item);
	if (template->moves_set) {
		for (int i = 0; i < 4; i++) {
			pokemon_set_attribute(p, ATTRIBUTE_ATTACK1 + i, template->moves + i);
			pokemon_set_attribute(p, ATTRIBUTE_PP1 + i, &attacks[template->moves[i]].pp);
		}
	}
	if (template->hidden_ability)
		pokemon_set_hidden_ability(&p->box);
	if (template->nickname)
		pokemon_set_attribute(p, ATTRIBUTE_NICKNAME, template->nickname);
	pokemon_calculate_stats(p);
	// DEBUG("Trainer mon effective evs [%d, %d, %d, %d, %d, %d]\n",
	// 	pokemon_get_effective_ev(p, 0), pokemon_get_effective_ev(p, 1), pokemon_get_effective_ev(p, 2),
	// 	pokemon_get_effective_ev(p, 3), pokemon_get_effective_ev(p, 4), pokemon_get_effective_ev(p, 5));
	DEBUG("Trainer mon stats [%d, %d, %d, %d, %d, %d]\n",
		pokemon_get_attribute(p, ATTRIBUTE_TOTAL_HP, NULL), pokemon_get_attribute(p, ATTRIBUTE_ATK, NULL),
		pokemon_get_attribute(p, ATTRIBUTE_DEF, NULL), pokemon_get_attribute(p, ATTRIBUTE_INIT, NULL),
		pokemon_get_attribute(p, ATTRIBUTE_SATK, NULL), pokemon_get_attribute(p, ATTRIBUTE_SDEF, NULL)
		);
}


static int party_setup_by_trainer_idx(pokemon *dst_party, u16 trainer_id) {
	if (trainer_id >= 0x1e0 && trainer_id < 0x1e4)
		dungeon2_init_trainer(trainer_id);
	// To generate a trainer consistent pid we use a pseudo rng
	trainer_prng_state = trainer_id;
	size_t idxs[6] = {0, 1, 2, 3, 4, 5};
	if (*var_access(DIFFICULTY) == DIFFICULTY_HARD) {  // Shuffle
		shuffle(idxs, trainers[trainer_id].pokemon_cnt, NULL);
	}
	for (int j = 0; j < trainers[trainer_id].pokemon_cnt; j++)
		DEBUG("Shuffled team order %d : %d\n", j, idxs[j]);
	for (int j = 0; j < trainers[trainer_id].pokemon_cnt; j++) {
		trainer_pokemon_new(dst_party + j, trainers[trainer_id].party + j);
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
			num_pokemon_setup += party_setup_by_trainer_idx(opponent_pokemon + 3, trainer_varsB.trainer_id);
	}
	return num_pokemon_setup;
}

void ally_party_setup() {
	u16 trainer_idx = *var_access(VAR_ALLY);
	memset(player_pokemon + 3, 0, 3 * sizeof(pokemon));
	party_setup_by_trainer_idx(player_pokemon + 3, trainer_idx);
	u32 tid = (u32)(trainer_pokemon_prng() % 100000);
	// Change OT-name
	trainer_prng_state = trainer_idx;
	for (int i = 3; i < 6; i++) {
		if (pokemon_get_attribute(player_pokemon + i, ATTRIBUTE_SPECIES, 0) != 0) {
			pokemon_set_attribute(player_pokemon + i, ATTRIBUTE_OT_NAME, trainer_get_name(trainer_idx));
			pokemon_set_attribute(player_pokemon + i, ATTRIBUTE_TID, &tid);
		}
	}
}

