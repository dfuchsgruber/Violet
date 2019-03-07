/*
 * egg_moves.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_POKEMON_EGG_MOVES_H_
#define INCLUDE_C_POKEMON_EGG_MOVES_H_

#include "types.h"
#include "pokemon/virtual.h"

typedef struct {
	u16 words[9];
	u8 player_name[8]; // terminated with 0xFF
	u8 tid[4];
	u16 species;
	u16 item;
} mail_stru;

typedef struct {
	mail_stru message;
	u8 ot_name[8]; // terminated with 0xFF
	u8 pokemon_name[11]; // terminated with 0xFF
	u8 game_language : 4;
	u8 pokemon_language : 4;
} daycare_mail_stru;

typedef struct {
	box_pokemon pokemon;
	daycare_mail_stru mail;
	u32 step_counter;
} daycare_pokemon;

typedef struct {
	daycare_pokemon pokemon[2];
	u16 offspring_present : 1;
	u16 offspring_nature : 15;
	// u16 offspring_personality_lower; // why would you only store this, thats akward!
	u8 step_counter;
} daycare_stru;

extern u16 *pokemon_egg_moves[];
extern u8 str_egg[];

/**
 * Returns a pointer to a list of attacks describing the egg moves obtainable by
 * a pokemon.
 * @param species The pokemon species to find egg moves for.
 * @param size A pointer where the function stores the size of the egg move list.
 * @return Egg moves array.
 */
u16 *pokemon_get_egg_moves(u16 species, int *size);

/**
 * Gets the compatibility score for the pokemon currently in the daycare
 * @param daycare the daycare structure
 * @return the compatilbilty score for the pokemon in the daycare
 */
u8 daycare_get_compatibility_score(daycare_stru *daycare);

/**
 * Creates an egg in the daycare using the daycare structure of the first saveblock.
 */
void _daycare_spawn_egg();

/**
 * Calculates how many steps the current egg cycle needs.
 * @return the length of a cycle for an egg
 */
u8 breeding_get_cycle_steps();

/**
 * Checks if the player party contains at least one pokemon with flame body.
 * @return if the player party has at least one pokemon with flame body.
 */
bool pokemon_player_party_has_flamebody();

/**
 * Creates a new egg found in the overworld of some species.
 * @param species the species to create an egg of
 * @paran catch_location the catch location assigned with the egg
 * @param dst the memory to place the pokemon at
 */
void overworld_egg_new(u16 species, int catch_location, pokemon *dst);

#endif /* INCLUDE_C_POKEMON_EGG_MOVES_H_ */
