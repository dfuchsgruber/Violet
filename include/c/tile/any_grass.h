/*
 * any_grass.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_TILE_ANY_GRASS_H_
#define INCLUDE_C_TILE_ANY_GRASS_H_

#include "oam.h"

#define ANY_GRASS_CNT 7

typedef struct{
    u8 bank;
    u8 map;
    u8 triggered_by_behavior;
    bool apply_to_every_map;
    oam_template *temp;
    palette *pal;
    void (*init_func)();
    u8 *(*player_step_cb)();
}any_grass;


any_grass tile_any_grasses[7];


void any_grass_step();
u8 *ash_grass_player_step();
u8 *any_grass_player_step_null();

#endif /* INCLUDE_C_TILE_ANY_GRASS_H_ */
