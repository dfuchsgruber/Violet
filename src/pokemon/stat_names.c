/*
 * stat_names.c
 *
 *  Created on: Feb 17, 2019
 *      Author: dominik
 */

#include "types.h"
#include "pokemon/names.h"
#include "constants/pokemon_stat_names.h"

u8 *pokemon_get_state_name(u8 stat) {
	switch(stat){
	case STAT_HP: return pokemon_stat_names[POKEMON_STAT_NAME_HP];
	case STAT_ATTACK: return pokemon_stat_names[POKEMON_STAT_NAME_ATTACK];
	case STAT_DEFENSE: return pokemon_stat_names[POKEMON_STAT_NAME_DEFENSE];
	case STAT_SPEED: return pokemon_stat_names[POKEMON_STAT_NAME_SPEED];
	case STAT_SPECIAL_ATTACK: return pokemon_stat_names[POKEMON_STAT_NAME_SPECIAL_ATTACK];
	case STAT_SPECIAL_DEFENSE: return pokemon_stat_names[POKEMON_STAT_NAME_SPECIAL_DEFENSE];
	default: return 0;
	}

}
