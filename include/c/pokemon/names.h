/*
 * names.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_POKEMON_NAMES_H_
#define INCLUDE_C_POKEMON_NAMES_H_

#include "types.h"
#include "pokemon/count.h"

extern u8 pokemon_names[POKEMON_CNT][11];

#define POKEMON_STAT_NAME_HP 1
#define POKEMON_STAT_NAME_ATTACK 4
#define POKEMON_STAT_NAME_DEFENSE 5
#define POKEMON_STAT_NAME_SPECIAL_ATTACK 6
#define POKEMON_STAT_NAME_SPECIAL_DEFENSE 7
#define POKEMON_STAT_NAME_SPEED 8
#define POKEMON_STAT_NAME_TYPE 10

extern u8 *pokemon_stat_names[];

/**
 * Returns the string that represents the stat of a pokemon.
 * @param stat a stat that corresponds to a pokemon_stat_name constant that is visible outside battle
 * @return the stat name string or NULL
 */
u8 *pokemon_get_state_name(u8 stat);

#endif /* INCLUDE_C_POKEMON_NAMES_H_ */
