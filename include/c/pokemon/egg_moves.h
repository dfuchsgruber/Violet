/*
 * egg_moves.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_POKEMON_EGG_MOVES_H_
#define INCLUDE_C_POKEMON_EGG_MOVES_H_

#include "egg_moves.h"

extern u16 *pokemon_egg_moves[];

/**
 * Returns a pointer to a list of attacks describing the egg moves obtainable by
 * a pokemon.
 * @param species The pokemon species to find egg moves for.
 * @param size A pointer where the function stores the size of the egg move list.
 * @return Egg moves array.
 */
u16 *pokemon_get_egg_moves(u16 species, int *size);

#endif /* INCLUDE_C_POKEMON_EGG_MOVES_H_ */
