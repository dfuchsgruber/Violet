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

#include "trainer/build.h"
#include "pokemon/virtual.h"

typedef struct {
	u8 ivs;
	union_build_field build;
    u8 level;
    u8 field_3;
    u16 species;
    u16 field_6;
} trainer_pokemon_default_item_default_attacks;

typedef struct {
	u8 ivs;
	union_build_field build;
    u8 level;
    u8 field_3;
    u16 species;
    u16 item;
} trainer_pokemon_custom_item_default_attacks;

typedef struct {
	u8 ivs;
	union_build_field build;
    u8 level;
    u8 field_3;
    u16 species;
    u16 moves[4];
    u16 field_6;
} trainer_pokemon_default_item_custom_attacks;

typedef struct {
	u8 ivs;
	union_build_field build;
    u8 level;
    u8 field_3;
    u16 species;
    u16 item;
    u16 moves[4];
} trainer_pokemon_custom_item_custom_attacks;

typedef union{
    trainer_pokemon_default_item_default_attacks default_item_default_attacks;
    trainer_pokemon_custom_item_default_attacks custom_item_default_attacks;
    trainer_pokemon_default_item_custom_attacks default_item_custom_attacks;
    trainer_pokemon_custom_item_custom_attacks custom_item_custom_attacks;
} trainer_pokemon;


/**
 * Builds / modifies a trainer pokemon based on its build field
 * @param poke the pokemon to modify
 * @param field the build field that encodes the information about the trainer
 */
void trainer_pokemon_new(pokemon *poke, union union_build_field field);


#endif /* INCLUDE_C_TRAINER_PARTY_H_ */
