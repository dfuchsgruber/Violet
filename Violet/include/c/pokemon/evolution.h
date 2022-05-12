/*
 * evolution.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_POKEMON_EVOLUTION_H_
#define INCLUDE_C_POKEMON_EVOLUTION_H_


#define EVOLUTION_TRIGGER_LEVEL_UP 0
#define EVOLUTION_TRIGGER_TRADE_EVO 1
#define EVOLUTION_TRIGGER_ITEM 2
#define EVOLUTION_TRIGGER_ITEM2 3
#define EVOLUTION_TRIGGER_ITEM_AND_REMOVE_HOLD_ITEM 4

#include "pokemon/count.h"

typedef struct {
        u16 method;
        u16 condition;
        u16 target;
        u16 baby_trigger_item;
    } pokemon_evolution;

extern pokemon_evolution *pokemon_evolutions[POKEMON_CNT];

extern void (*evolution_continuation)();

/**
 * Uses a limited-depth dfs to find all items occuring anywhere in the evolution line of a pokemon
 * @param species the species to check: dfs is initialized from its base stage
 * @param items where to collect all items
 * @param max_size the maximal number of items to collect
 **/
size_t pokemon_get_evolution_item_line(u16 species, u16 *items, size_t max_size);

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

/**
 * Checks if a pokemon can evolve given a certian trigger type and returns the target species if so.
 * @param p the pokemon that is to be evolved
 * @param trigger_type how the evolution is triggered
 * @param arg an argument that is passed depending on the trigger type, e.g. the item of an evolution stone
 * @return the species the pokemon evolves into or 0 if no such species exists
 **/
u16 pokemon_get_evolution(pokemon * p, u8 trigger_type, u16 arg);

/**
 * Initializes callbacks and a scene for evolving a pokemon.
 * @param p the pokemon to evolve
 * @param target the species to evolve the pokemon into
 * @param can_stop_evolution if the player can abort the evolution using the B-button
 * @param party_idx the index in the player's party of the evolving pokemon
 **/
void pokemon_initialize_evolution(pokemon *p, u16 target, bool can_stop_evolution, u8 party_idx);

#endif /* INCLUDE_C_POKEMON_EVOLUTION_H_ */
