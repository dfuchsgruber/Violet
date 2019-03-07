/*
 * incubator.h
 *
 *  Created on: Mar 6, 2019
 *      Author: dominik
 */

#ifndef INCLUDE_C_POKEPAD_INCUBATOR_H_
#define INCLUDE_C_POKEPAD_INCUBATOR_H_

#include "types.h"

typedef struct {
  u8 from_outdoor;
} incubator_state_stru;

/**
 * Returns the number of available slots for the incubator
 * @return the number of slots avaialable for the incubator
 */
int incubator_available_slots();

extern u16 gfx_incubator_ui_0Tiles[];
extern u16 gfx_incubator_ui_0Map[];
extern u16 gfx_incubator_ui_0Pal[];

#endif /* INCLUDE_C_POKEPAD_INCUBATOR_H_ */
