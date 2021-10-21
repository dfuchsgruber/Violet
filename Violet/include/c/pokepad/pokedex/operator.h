/*
 * operator.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_POKEPAD_POKEDEX_OPERATOR_H_
#define INCLUDE_C_POKEPAD_POKEDEX_OPERATOR_H_

#include "pokemon/count.h"
#include "pokemon/virtual.h"
#include "types.h"

#define POKEDEX_GET 0
#define POKEDEX_SET 2
#define POKEDEX_SEEN 0
#define POKEDEX_CAUGHT 1

/**
 * Performs the pokedex operator to get/set seen and caught data of the pokedex
 * @param val the value (either species id or dex id)
 * @param op the operation
 * @param is_species_id if val is a species id
 * @return the result of the seen/caught request
 */
bool pokedex_operator(u16 val, u8 op, bool is_species_id);

/**
 * Accesses a pokedex flag
 * @param flag the flag to access
 * @param seen Whether to access the seen area (or the caught area if false)
 * @return the byte containing the desired flag
 */
u8 *pokedex_flag_access(u16 flag, bool seen);

/**
 * Counts the number of seen (or caught) pokemon
 * @param caught whether to count the caught pokemon (or seen if false)
 * @return the number of pokemon seen or caught
 */
u16 pokedex_get_number_seen_or_caught(bool caught);

/**
 * Finds the dex id of a species
 * @param species the species
 * @param the corresponding dex id
 */
u16 pokedex_get_id(u16 species);

/**
 * Performs the seen/caught get/set operator on a dex id
 * @param dex_id the dex id
 * @param op the operator
 * @return the result of the get request (seen or caught)
 */
bool pokedex_operator_by_dex_id(u16 dex_id, u8 op);

/**
 * Checks if the national dex is available
 * @return if the national dex is available
 */
bool pokedex_is_national();

/**
 * Gets the number to display in the summary for a species (which is not necessarily the dex id)
 * @param species the species
 * @return the display number
 */
u16 pokemon_get_display_number(u16 species);

/**
 * Gets the species of pokemon by its dex id
 * @param dex_id the dex id
 * @return the corresponding species
 */
u16 pokedex_get_species_by_dex_id(u16 dex_id);

/**
 * Sets a pokemon as caught and loads its pid to display the dex entry
 * @param dex_id the dex id of the pokemon caught
 * @param flags TODO
 * @param pid the pid of the pokemon caught
 */
void pokedex_set_caught_and_load_pid(u16 dex_id, u8 flags, pid_t pid);

u16 pokedex_order[POKEMON_CNT - 1];

#endif /* INCLUDE_C_POKEPAD_POKEDEX_OPERATOR_H_ */
