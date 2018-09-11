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

u8 ev_finals[6] = {0x16, 0x17, 0x18, 0x21, 0x2F, 0x30};

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

void build_trainer_pokemon_custom_item_default_attacks(pokemon *dst,
		trainer_pokemon_custom_item_default_attacks *party) {
	// Obtain the prng state that was seeded with the trainer id
	u32 *prng_state = (u32*)gp_stack_peek();
	pid_t pid = {_prng_xorshift(prng_state)};
	pid.fields.shinyness = 0x201;
	pokemon_new(dst, party->species, party->level, party->ivs, true, pid, false, 0);
	build_trainer_pokemon(dst, party->build);
	// Custom item
	pokemon_set_attribute(dst, ATTRIBUTE_ITEM, &(party->item));
}

void build_trainer_pokemon_custom_item_custom_attacks(pokemon *dst,
		trainer_pokemon_custom_item_custom_attacks *party) {
	// Obtain the prng state that was seeded with the trainer id
	u32 *prng_state = (u32*)gp_stack_peek();
	pid_t pid = {_prng_xorshift(prng_state)};
	pid.fields.shinyness = 0x201;
	pokemon_new(dst, party->species, party->level, party->ivs, true, pid, false, 0);
	build_trainer_pokemon(dst, party->build);
	// Custom item
	pokemon_set_attribute(dst, ATTRIBUTE_ITEM, &(party->item));
	// Custom attacks
	for (int i = 0; i < 4; i++) {
		pokemon_set_attribute(dst, (u8)(ATTRIBUTE_ATTACK1 + i), &(party->moves[i]));
		pokemon_set_attribute(dst, (u8)(ATTRIBUTE_PP1 + i), &(attacks[party->moves[i]].pp));
	}
}

void build_trainer_pokemon_default_item_custom_attacks(pokemon *dst,
		trainer_pokemon_default_item_custom_attacks *party) {
	// Obtain the prng state that was seeded with the trainer id
	u32 *prng_state = (u32*)gp_stack_peek();
	pid_t pid = {_prng_xorshift(prng_state)};
	pid.fields.shinyness = 0x201;
	pokemon_new(dst, party->species, party->level, party->ivs, true, pid, false, 0);
	build_trainer_pokemon(dst, party->build);
	// Custom attacks
	for (int i = 0; i < 4; i++) {
		pokemon_set_attribute(dst, (u8)(ATTRIBUTE_ATTACK1 + i), &(party->moves[i]));
		pokemon_set_attribute(dst, (u8)(ATTRIBUTE_PP1 + i), &(attacks[party->moves[i]].pp));
	}
}

void build_trainer_pokemon_default_item_default_attacks(pokemon *dst,
		trainer_pokemon_default_item_default_attacks *party) {
	// Obtain the prng state that was seeded with the trainer id
	u32 *prng_state = (u32*)gp_stack_peek();
	pid_t pid = {_prng_xorshift(prng_state)};
	pid.fields.shinyness = 0x201;
	pokemon_new(dst, party->species, party->level, party->ivs, true, pid, false, 0);
	build_trainer_pokemon(dst, party->build);
}

int build_trainer(pokemon *dst_party, u16 trainer_id) {
	if (trainer_id == 0x400) return 0; // No idea, but in vanilla they do it, so...
	if (!battle_state->items_prohibited && !battle_state->items_prohibited2
			&& !battle_state->field_31 && battle_state->trainer_battle) {
		// Build trainer
		pokemon_clear_opponent_party();
		// To generate a trainer consistent pid we use a pseudo rng
		u32 *state = malloc(sizeof(u32));
		*state = trainer_id;
		gp_stack_push((int)state);
		for (int i = 0; i < trainers[trainer_id].pokemon_cnt; i++) {
			if (trainers[trainer_id].uses_custom_items &&
					trainers[trainer_id].uses_custom_moves) {
				trainer_pokemon_custom_item_custom_attacks* party =
						(trainer_pokemon_custom_item_custom_attacks*)trainers[trainer_id].party;
				build_trainer_pokemon_custom_item_custom_attacks(&dst_party[i], &party[i]);
			} else if (trainers[trainer_id].uses_custom_items) {
				trainer_pokemon_custom_item_default_attacks* party =
						(trainer_pokemon_custom_item_default_attacks*)trainers[trainer_id].party;
				build_trainer_pokemon_custom_item_default_attacks(&dst_party[i], &party[i]);
			} else if (trainers[trainer_id].uses_custom_moves) {
				trainer_pokemon_default_item_custom_attacks* party =
						(trainer_pokemon_default_item_custom_attacks*)trainers[trainer_id].party;
				build_trainer_pokemon_default_item_custom_attacks(&dst_party[i], &party[i]);
			} else {
				trainer_pokemon_default_item_default_attacks* party =
						(trainer_pokemon_default_item_default_attacks*)trainers[trainer_id].party;
				build_trainer_pokemon_default_item_default_attacks(&dst_party[i], &party[i]);
			}
		}
		gp_stack_pop();
		free(state);
		*((u32*)battle_state) |= trainers[trainer_id].battle_state;
		return trainers[trainer_id].pokemon_cnt;
	}
	return 0;
}


void build_trainer_pokemon(pokemon *poke, union union_build_field field) {
	// Obtain the prng state that was seeded with the trainer id
	u32 *prng_state = (u32*)gp_stack_peek();
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
		field.bitfield.ability = (u8) (_prng_xorshift(prng_state) & 1); //random ability still
	}

	pid_t p = {(u32)pokemon_get_attribute(poke, 0, 0)};
	p.fields.shinyness = field.bitfield.shinyness ? 0 : 0x201;
	if (p.fields.nature < 0x19)
		p.fields.nature = (trainer_builds[field.bitfield.build].nature);
	pokemon_set_attribute(poke, 0, &p);

	u8 ability = field.bitfield.ability & 1;
	pokemon_set_attribute(poke, ATTRIBUTE_ABILITY, &ability);

	u8 poke_coolness_field = (u8) (pokemon_get_attribute(poke, 0x16, 0) & 0x7F);
	poke_coolness_field = (u8) (poke_coolness_field | (field.bitfield.hability << 7));
	pokemon_set_attribute(poke, 0x16, &poke_coolness_field);

	if (!pokemon_get_attribute(poke, 0xC, 0)) {
		pokemon_set_attribute(poke, 0xC, &trainer_builds[field.bitfield.build].prefered_item);
	}

	int i;
	for (i = 0; i < 6; i++) {
		u8 effective_ev = (u8) (trainer_builds[field.bitfield.build].evs[i] >> 2);
		effective_ev = (u8) ((pokemon_get_attribute(poke, ev_finals[i], 0) & 0xC0) | effective_ev);
		pokemon_set_attribute(poke, ev_finals[i], &effective_ev);
	}
	pokemon_calculate_stats(poke);
}
