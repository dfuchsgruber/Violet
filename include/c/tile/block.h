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
    u32 hm_usage : 5;
    u32 field_2 : 4;
    u32 field_3 : 6;
    u32 field_4 : 3; //if 0 no wildbattle triggered, 1 fetch data from wild grass table, 2 water
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

extern coordinate walking_directions[];


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
void player_get_position(s16 *x, s16 *y);

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
bool tile_is_reflective_water(u8 behavior);

#endif /* INCLUDE_C_TILE_BLOCK_H_ */
