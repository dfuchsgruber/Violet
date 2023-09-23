/*
 * effort_values.c
 *
 *  Created on: Feb 16, 2019
 *      Author: dominik
 */
#include "types.h"
#include "pokemon/virtual.h"
#include "constants/pokemon_stat_names.h"
#include "constants/pokemon_attributes.h"
#include "debug.h"
#include "constants/items.h"
#include "item/item.h"
#include "item/pokeball.h"
#include "save.h"
#include "constants/item_hold_effects.h"
#include "pokemon/basestat.h"

const u8 effective_ev_attributes[6] = {
		[STAT_HP] = ATTRIBUTE_COOLNESS,
		[STAT_ATTACK] = ATTRIBUTE_BEAUTY,
		[STAT_DEFENSE] = ATTRIBUTE_CUTENESS,
		[STAT_SPEED] = ATTRIBUTE_SMARTNESS,
		[STAT_SPECIAL_ATTACK] = ATTRIBUTE_TOUGHNESS,
		[STAT_SPECIAL_DEFENSE] = ATTRIBUTE_SHEEN
};

const u8 potential_ev_attributes[6] = {
		[STAT_HP] = ATTRIBUTE_HP_EV, [STAT_ATTACK] = ATTRIBUTE_ATT_EV,
		[STAT_DEFENSE] = ATTRIBUTE_DEF_EV, [STAT_SPEED] = ATTRIBUTE_INIT_EV,
		[STAT_SPECIAL_ATTACK] = ATTRIBUTE_SATT_EV, [STAT_SPECIAL_DEFENSE] = ATTRIBUTE_SDEF_EV
};

void pokemon_set_effective_ev(pokemon *p, int stat, u8 ev) {
	DEBUG("Set ev for stat %d to %d\n", stat, ev);
	int value = pokemon_get_attribute(p, effective_ev_attributes[stat], 0) & (~0x3F);
	value |= ev;
	pokemon_set_attribute(p, effective_ev_attributes[stat], &value);
}

u8 pokemon_get_effective_ev(const pokemon *p, int stat) {
	return (u8) (pokemon_get_attribute(p, effective_ev_attributes[stat], 0) & 0x3F);
}

void pokemon_set_potential_ev(pokemon *p, int stat, u8 ev) {
	pokemon_set_attribute(p, potential_ev_attributes[stat], &ev);
}

u8 pokemon_get_potential_ev(const pokemon *p, int stat) {
	return (u8) pokemon_get_attribute(p, potential_ev_attributes[stat], 0);
}

void pokemon_get_evs(pokemon *p, u16 defeated_species) {
	u8 evs[6] = {0};
	u8 hold_effect;
	if (pokemon_get_attribute(p, ATTRIBUTE_ITEM, NULL) == ITEM_ENIGMABEERE) {
		hold_effect = save1->enigma_berry.hold_effect;
	} else {
		hold_effect = item_get_hold_effect((u16)pokemon_get_attribute(p, ATTRIBUTE_ITEM, NULL));
	}
	int multiplier = 1;
	if (pokemon_get_pokerus(p, POKERUS_GET_SINGLE_POKEMON))
		multiplier *= 2;
	if (hold_effect == HOLD_EFFECT_MACHO_BRACE)
		multiplier *= 2;
	evs[STAT_HP] = basestats[defeated_species].ev_yield.hp;
	evs[STAT_ATTACK] = basestats[defeated_species].ev_yield.att;
	evs[STAT_DEFENSE] = basestats[defeated_species].ev_yield.def;
	evs[STAT_SPEED] = basestats[defeated_species].ev_yield.speed;
	evs[STAT_SPECIAL_ATTACK] = basestats[defeated_species].ev_yield.satt;
	evs[STAT_SPECIAL_DEFENSE] = basestats[defeated_species].ev_yield.sdef;
	u8 ball_idx = (u8)pokemon_get_attribute(p, ATTRIBUTE_CATCH_INFO, NULL);
	switch (ball_idx) {
		case BALL_HP:
			evs[STAT_HP]++; break;
		case BALL_ATTACK:
			evs[STAT_ATTACK]++; break;
		case BALL_DEFENSE:
			evs[STAT_DEFENSE]++; break;
		case BALL_SPEED:
			evs[STAT_SPEED]++; break;
		case BALL_SPECIAL_ATTACK:
			evs[STAT_SPECIAL_ATTACK]++; break;
		case BALL_SPECIAL_DEFENSE:
			evs[STAT_SPECIAL_DEFENSE]++; break;
	}
	for (int i = STAT_HP; i <= STAT_SPECIAL_DEFENSE; i++) {
		int ev = pokemon_get_potential_ev(p, i);
		// DEBUG("Pokemon 0x%x has pot ev %d (stat %d)\n", p, ev, i);
		ev = MIN(255, ev + multiplier * evs[i]);
		// DEBUG("Raised ev to %d\n", ev);
		pokemon_set_potential_ev(p, i, (u8)ev);
	}
}