/*
 * healing_place.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_MAP_HEALING_PLACE_H_
#define INCLUDE_C_MAP_HEALING_PLACE_H_

#include "save.h"
#include "tile/coordinate.h"
#include "constants/healingplaces.h"

typedef struct{
    u16 bank;
    u16 map;
} stru_healing_place_map;

extern const stru_healing_place_map healing_place_maps[NUM_HEALING_PLACES];
extern const u8 healing_place_target_persons[NUM_HEALING_PLACES];
extern const coordinate_t healing_place_target_coordinates[NUM_HEALING_PLACES];

#endif /* INCLUDE_C_MAP_HEALING_PLACE_H_ */
