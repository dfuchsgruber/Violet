#include "types.h"
#include <stdbool.h>
#include "trainer/build.h"
#include "pokemon/virtual.h"
#include "constants/natures.h"
#include "constants/pokemon_attributes.h"
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

static trainer_build_t trainer_builds [14] = {

    {0x19,
        {0, 0, 0, 0, 0, 0}, 0}, //None
    {NATURE_HART,
        {4, 252, 0, 252, 0, 0}, 0}, //physical sweep attack preference
    {NATURE_FROH,
        {4, 252, 0, 252, 0, 0}, 0}, //physical sweep init preference
    {NATURE_MAESSIG,
        {4, 0, 252, 252, 0, 0}, 0}, //special sweep sattack preference

    {NATURE_SCHEU,
        {4, 0, 252, 252, 0, 0}, 0}, //special sweep init preference
    {NATURE_KUEHN,
        {252, 0, 252, 0, 0, 4}, 0}, //physical wall attack minus
    {NATURE_PFIFFIG,
        {252, 0, 252, 0, 0, 4}, 0}, //physical wall sattack minus
    {NATURE_STILL,
        {252, 0, 4, 0, 0, 252}, 0}, //special wall attack minus

    {NATURE_SACHT,
        {252, 0, 4, 0, 0, 252}, 0}, //special wall sattack minus
    {0x19,
        {40, 40, 40, 40, 40, 40}, 0}, //balanced weak
    {0x19,
        {85, 85, 85, 85, 85, 85}, 0}, //balanced strong
    {NATURE_NAIV,
        {0, 252, 0, 4, 252, 0}, 0}, //mixed sweeper

    {NATURE_HART,
        {252, 252, 0, 4, 0, 0}, 0}, //tanky phyiscal
    {NATURE_MAESSIG,
        {252, 0, 0, 4, 252, 0}, 0} //tanky special 

};

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

int trainer_build_party(pokemon *dst_party, u16 trainer_id) {
	if (trainer_id == 0x400) return 0; // No idea, but in vanilla they do it, so...
	if (!(battle_flags & BATTLE_TOWER) && !(battle_flags & BATTLE_EREADER)
			&& !(battle_flags & BATTLE_31) && (battle_flags & BATTLE_TRAINER)) {
		// Build trainer
		pokemon_clear_opponent_party();
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
	return 0;
}


void trainer_pokemon_new(pokemon *poke, union union_build_field field) {
	// Obtain the prng state that was seeded with the trainer id
	if (!field.value) {
		switch (*(var_access(DIFFICULTY))) {
			case 0:
			case 1:
			case 2:
			default:
				return;
			case 3:
				//difficult
				field.bitfield.build = 9;
				break;
			case 4:
				//very difficult
				field.bitfield.build = 10;
				break;
		}
		field.bitfield.ability = (u8) (trainer_pokemon_prng() & 1); //random ability still
	}

	pid_t p = {(u32)pokemon_get_attribute(poke, 0, 0)};
	p.fields.is_shiny = field.bitfield.shinyness ? 1 : 0;
	if (p.fields.nature < 0x19)
		p.fields.nature = (trainer_builds[field.bitfield.build].nature);
	pokemon_set_attribute(poke, ATTRIBUTE_PID, &p);

	u8 ability = field.bitfield.ability & 1;
	pokemon_set_attribute(poke, ATTRIBUTE_ABILITY, &ability);

	if (field.bitfield.hability) {
		pokemon_set_hidden_ability(poke);
	}

	if (!pokemon_get_attribute(poke, 0xC, 0)) {
		pokemon_set_attribute(poke, 0xC, &trainer_builds[field.bitfield.build].prefered_item);
	}

	int i;
	for (i = 0; i < 6; i++) {
		u8 effective_ev = (u8) (trainer_builds[field.bitfield.build].evs[i] >> 2);
		pokemon_set_effective_ev(poke, i, effective_ev);
	}
	pokemon_calculate_stats(poke);
}
