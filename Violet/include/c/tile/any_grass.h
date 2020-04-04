/*
 * any_grass.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_TILE_ANY_GRASS_H_
#define INCLUDE_C_TILE_ANY_GRASS_H_

#include "oam.h"
#include "map/tileset.h"


enum {
    ANY_GRASS_ASH,
    ANY_GRASS_GRAVEYARD,
    ANY_GRASS_HAWEILAND,
    ANY_GRASS_CLOUD
};

typedef struct{
    tileset *tileset; // NULL if on all tilesets
    u8 triggered_by_behavior;
    oam_template *temp;
    palette *pal;
    void (*init_func)();
    u8 *(*player_step_cb)();
}any_grass;

typedef struct {
	int x, y;
	int height;
	int bg_priority;
	int target_ow_and_their_map; // (target_ow << 8) | target_ow_map
	int target_ow_bank;
	int origin_map_and_bank; // (map << 8) | bank
	int field_1C;
} overworld_effect_state_t;

extern overworld_effect_state_t overworld_effect_state;

/**
 * Gets the grass effect triggered by stepping on a tile with a certain behaviour on the current map.
 * @param behaviour the behaviour to step on
 * @return the grass effect or NULL if none is associated
 **/
any_grass *any_grass_get_on_current_map_by_behaviour(u8 behaviour);

void rock_climb_step();
void any_grass_step();
u8 *ash_grass_player_step();
u8 *any_grass_player_step_null();

/**
 * Callback for an oam spawned by the overworld effect of grass.
 * @param reference to the oam object
 */
void overworld_effect_oam_callback_grass(oam_object *self);

#endif /* INCLUDE_C_TILE_ANY_GRASS_H_ */
