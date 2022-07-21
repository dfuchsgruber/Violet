/*
 * party.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_TRAINER_PARTY_H_
#define INCLUDE_C_TRAINER_PARTY_H_

#define TRAINER_POKEMON_LEVEL_STORY_BASED 254
#define TRAINER_POKEMON_LEVEL_STORY_BASED_PLUS_ONE_STD 253

#include "pokemon/virtual.h"

typedef struct {
    pid_t pid;
    u32 ability_set : 1;
    u32 gender_set : 1;
    u32 shiny_set : 1;
    u32 hidden_power_type_set : 1;
    u32 hidden_power_strength_set : 1;
    u32 unown_letter_set : 1;
    u32 nature_set : 1;
    u32 form_set : 1;
    u32 moves_set : 1;
    u32 hidden_ability : 1;
    u32 evs_set : 1;
    u32 ivs_set : 1;
    u8 ivs[6];
    u8 evs[6];
    u8 level;
    u16 species;
    u16 held_item;
    u16 moves[4];
    u8 *nickname;
} trainer_pokemon;

/**
 * @brief Gets the level of a trainer pokemon
 * 
 * @param level the level to translate (respect constants)
 * @return u8 the actual level
 */
u8 trainer_pokemon_get_level(u8 level);

#endif /* INCLUDE_C_TRAINER_PARTY_H_ */
