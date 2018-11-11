/*
 * evolution.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_POKEMON_EVOLUTION_H_
#define INCLUDE_C_POKEMON_EVOLUTION_H_

#include "pokemon/count.h"

typedef struct {
        u16 method;
        u16 condition;
        u16 target;
        u16 baby_trigger_item;
    } pokemon_evolution;

extern pokemon_evolution **pokemon_evolutions[POKEMON_CNT];

/**
 * Gets the basis stage of a species
 * @param species the species to get the basis stage of
 * @return the basis stage species
 */
u16 pokemon_get_basis_stage(u16 species);

/**
 * Checks if a pokemon can evolve.
 * @param species The species to check for evolutions
 * @return if the species can evolve
 */
bool pokemon_can_evolve (u16 species);

#endif /* INCLUDE_C_POKEMON_EVOLUTION_H_ */
