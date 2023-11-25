/*
 * basestat.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_POKEMON_BASESTAT_H_
#define INCLUDE_C_POKEMON_BASESTAT_H_

#include "pokemon/count.h"
#include "constants/pokemon_colors.h"
#include "constants/pokemon_types.h"

#define LINKED_PKMN_CNT 8

typedef struct {
    u8 base_hp;
    u8 base_atk;
    u8 base_def;
    u8 base_speed;
    u8 base_satk;
    u8 base_sdef;
    u8 type1;
    u8 type2;
    u8 catch_rate;
    u8 exp_yield;

    struct {
        u16 hp : 2;
        u16 att : 2;
        u16 def : 2;
        u16 speed : 2;
        u16 satt : 2;
        u16 sdef : 2;
        u16 padding : 4;
    } ev_yield;
    u16 common_item;
    u16 rare_item;
    u8 gender_value;
    u8 egg_cycles;
    u8 base_happiness;
    u8 level_up_type;
    u8 egg_group_1;
    u8 egg_group_2;
    u8 ability1;
    u8 ability2;
    u8 safari_rate;
    u8 flipped : 1;
    u8 color : 7;
    u8 hidden_ability;
    u8 form;
} basestat;

extern const basestat basestats[POKEMON_CNT];
extern const u8 *const pokemon_color_names[NUM_POKEMON_COLORS];

extern const u32 pokemon_experience_tables[6][101];

// Those species are "linked" to other species
extern const u16 pokemon_linked[LINKED_PKMN_CNT];

extern const u8 *pokemon_nature_strings[];
extern const u8 *const str_pokemon_type_names[NUM_TYPES];

#endif /* INCLUDE_C_POKEMON_BASESTAT_H_ */
