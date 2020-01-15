/*
 * block.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_TILE_BLOCK_H_
#define INCLUDE_C_TILE_BLOCK_H_

#include "tile/coordinate.h"

#define BDATA_BEHAVIOUR 0
#define BDATA_HM_USAGE 1
#define BDATA_TRIGGERS_WILDBATTLE 4
#define TRIGGERS_WILDBATTLE_GRASS 1
#define TRIGGERS_WILDBATTLE_WATER 2

typedef struct bdata {
    u32 behavior : 9;
    u32 hm_usage : 5; // probably flags
    u32 field_2 : 4;
    u32 field_3 : 6;
    u32 wild_pokemon_type : 3; //if 0 no wildbattle triggered, 1 fetch data from wild grass table, 2 water
    u32 field_5 : 2;
    u32 field_6 : 2;
    u32 field_7 : 1;

} bdata;

/**
 * Gets a certain tile field by its position
 * @param x the x coordinate
 * @param y the y coorindate
 * @param the field id
 * @return the field value
 */
u32 block_get_field_by_pos(s16 x, s16 y, u8 field);

/**
 * Gets a certian tile field by the blocks field data
 * @param bdata the information compressed into 32 bit
 * @param field the field to extract
 */
u32 block_get_field(bdata data, int field);

typedef union union_block_data {
    bdata data;
    u32 value;
} block_data;


#define FIELD_BEHAVIOR 0
#define FIELD_HM_USAGE 1

// Coordinate displacements for walking directions

#define DIR_NONE 0
#define DIR_DOWN 1
#define DIR_UP 2
#define DIR_LEFT 3
#define DIR_RIGHT 4
#define DIR_DIANW 5
#define DIR_DIANE 6
#define DIR_DIASE 7
#define DIR_DIASW 8

extern coordinate_t walking_directions[];

/** Moves a position in any direction.
 * @param direction the direction in which to move in
 * @param x x coordinate of the position
 * @param y y coordinate of the position
 **/
void coordinates_apply_direction(int direction,short *x,short *y);

/**
 * Redraws a single block in the map
 * @param x the AM x coordiante + 7 (camera origin relative)
 * @param y the AM y coordinate + 7 (camera origin relative)
 */
void map_draw_block(s16 x, s16 y);

/**
 * Returns the player position
 * @param x offset to store the x coordinate
 * @param y offset to store the y coordinate
 */
void player_get_coordinates(s16 *x, s16 *y);

/**
 * Returns the id of a block at a certain position
 * @param x the x coordinate
 * @param y the y coordinate
 * @return the block id at x, y
 */
u16 block_get_by_pos(s16 x, s16 y);

/**
 * Sets the block id at a certain position together with its level
 * @param x the x coordinate
 * @param y the y coordinate
 * @param block the id to set at x, y
 */
void block_set_by_pos_with_level(s16 x, s16 y, u16 block_and_level);

#define BLOCK_SOLID 0xC00

/**
 * Sets the block id at a certain position
 * @param x the x coordinate
 * @param y the y coordinate
 * @param block the id to set at x, y
 */
void block_set_by_pos(s16 x, s16 y, u16 block);

/**
 * Updates all blocks on the maps with their RAM state (used by special 0x8E)
 */
void blocks_update();

/**
 * Returns the behaviour of a block at a certain position
 * @param x the x coordinate
 * @param y the y cooordinate
 * @return the behaviour field of this block
 */
u16 block_get_behaviour_by_pos(s16 x, s16 y);

/**
 * Gets the position the player is facing
 * @param x the offset to store the x coordinate
 * @param y the offset to store the y coordinate
 */
void player_get_facing_position(s16 *x, s16 *y);

/**
 * Gets the level of a block
 * @param x the x coordinate of the block
 * @param y the y coordinate of the block
 * @return the level of the block at x, y
 */
u8 block_get_level(s16 x, s16 y);

/**
 * Checks if a tile is reflective
 * @param behavior the bevhavior to check
 * @return if the tile behavior is reflective
 */
bool behaviour_is_reflective_water(u8 behavior);

/**
 * Checks if a tile's behavior is water, but too strong of a stream to surf on.
 * @param behaviour the behaviour byte to check
 * @return if the tile behaviour is a strong stream of water
 */
bool behaviour_is_surf_strong_stream(u8 behaviour);

/**
 * Checks if a tile's behavior is that of a waterfall.
 * @param behaviour the behaviour byte to check
 * @return if the tile behaviour is a waterfall
 */
bool behaviour_is_waterfall(u8 behaviour);

/**
 * Checks if at least one pokemon of the player has surf
 * @return if at least one pokemon of the player has surf
 */
bool player_pokemon_has_surf();

/**
 * Checks if the player can surf on the tile he is facing. If he already is surfing false is
 * returned.
 * @return if the player can trigger a new surf on the tile currently faced
 */
bool player_can_use_surf_on_tile_faced();

/**
 * Checks if the player can use waterfall in his current state, i.e. if he is facing upwards.
 * @return if the player can use waterfall in his current state
 */
bool player_can_use_waterfall_on_tile_faced();

/**
 * Checks if a movement triggers a legde. Does not consider if the tile "after" the ledge has collisions on its own.
 * @param x the x position where the movement happens
 * @param y the y position where the movement happens
 * @param direction the direction in which to move
 * @return if this movement triggers a ledge behaviour
 **/
bool block_ledge_triggered(s16 x,s16 y,u8 direction);


#endif /* INCLUDE_C_TILE_BLOCK_H_ */
