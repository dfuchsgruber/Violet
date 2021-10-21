/*
 * egg_hatching.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_TILE_EGG_HATCHING_H_
#define INCLUDE_C_TILE_EGG_HATCHING_H_
#include "pokemon/virtual.h"
#include "stdbool.h"

void egg_warm_update();
bool pokemon_party_has_flamebody();
void pokemon_hatch_decrement(pokemon *p);

#endif /* INCLUDE_C_TILE_EGG_HATCHING_H_ */
