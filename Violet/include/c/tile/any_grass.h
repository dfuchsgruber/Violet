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
    ANY_GRASS_CLOUD,
};

enum {
    TAG_ANY_GRASS_ASH = 0x1080,
    TAG_ANY_GRASS_GRAVEYARD,
    TAG_ANY_GRASS_HAWEILAND,
    TAG_ANY_GRASS_CLOUD,
    TAG_ROCK_CLIMB,
    TAG_ROCK_CLIMB_SKY_ISLANG,
    TAG_PLAYER_PALETTE_VANILLA,
} any_grass_tags;

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
 * Translates coordinates of the overworld effect into screen coordinates
 * @param initial x coordinate
 * @param initial y coordinate
 * @param dx relative x coordinate
 * @param dy relative y coordinate
 **/
void overworld_effect_ow_coordinates_to_screen_coordinates(s16 *x, s16 *y, s16 dx, s16 dy);

/**
 * Callback for overworld effects that are destroyed once their gfx animation has finished.
 * Expects the type of gfx animation to be stored in private[0]
 * @param self self-reference
 **/
void overworld_effect_oam_callback_wait_for_gfx_animation(oam_object *self);

/**
 * Deletes an overworld effect.
 * @param o the oam the effect used
 * @param effect_idx the effect that is to be deleted
 **/
void overworld_effect_delete(oam_object *o, u8 effect_idx);

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

/**
 * Checks if a palette tag is associated with any ground effect
 * @param tag the tag to check
 * @return if the palette tag is associated with a ground effect
 **/
bool tag_is_ground_effect(u16 tag);

#endif /* INCLUDE_C_TILE_ANY_GRASS_H_ */
