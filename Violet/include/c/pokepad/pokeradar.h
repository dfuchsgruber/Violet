/*
 * pokeradar.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_POKEPAD_POKERADAR_H_
#define INCLUDE_C_POKEPAD_POKERADAR_H_

#include "tile/coordinate.h"

extern u8 *script_pokeradar;
extern u8 *script_pokeradar_alert;
extern u8 *script_pokeradar_poschange;
extern u8 *script_pokeradar_flee;

bool pokeradar_npc_alert(u8 npc_id);
bool pokeradar_determine_position(coordinate_t *result);
void pokeradar_callback_return_to_ow_and_init_script();
void pokeradar_init(bool is_outdoor);
u8 pokeradar_prepeare();
void pokeradar_spawn_pokemon();
u16 pokeradar_next_seed();
bool pokeradar_step();

#endif /* INCLUDE_C_POKEPAD_POKERADAR_H_ */
