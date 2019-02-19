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


u8 effective_ev_attributes[6] = {
		[STAT_HP] = ATTRIBUTE_COOLNESS,
		[STAT_ATTACK] = ATTRIBUTE_BEAUTY,
		[STAT_DEFENSE] = ATTRIBUTE_CUTENESS,
		[STAT_SPEED] = ATTRIBUTE_SMARTNESS,
		[STAT_SPECIAL_ATTACK] = ATTRIBUTE_TOUGHNESS,
		[STAT_SPECIAL_DEFENSE] = ATTRIBUTE_SHEEN
};

u8 potential_ev_attributes[6] = {
		[STAT_HP] = ATTRIBUTE_HP_EV, [STAT_ATTACK] = ATTRIBUTE_ATT_EV,
		[STAT_DEFENSE] = ATTRIBUTE_DEF_EV, [STAT_SPEED] = ATTRIBUTE_INIT_EV,
		[STAT_SPECIAL_ATTACK] = ATTRIBUTE_SATT_EV, [STAT_SPECIAL_DEFENSE] = ATTRIBUTE_SDEF_EV
};

void pokemon_set_effective_ev(pokemon *p, int stat, u8 ev) {
	int value = pokemon_get_attribute(p, effective_ev_attributes[stat], 0) & (~0x3F);
	value |= ev;
	pokemon_set_attribute(p, effective_ev_attributes[stat], &value);
}

u8 pokemon_get_effective_ev(pokemon *p, int stat) {
	return (u8) (pokemon_get_attribute(p, effective_ev_attributes[stat], 0) & 0x3F);
}

void pokemon_set_potential_ev(pokemon *p, int stat, u8 ev) {
	pokemon_set_attribute(p, potential_ev_attributes[stat], &ev);
}

u8 pokemon_get_potential_ev(pokemon *p, int stat) {
	return (u8) pokemon_get_attribute(p, potential_ev_attributes[stat], 0);
}
