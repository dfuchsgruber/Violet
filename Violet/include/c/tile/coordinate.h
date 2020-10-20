/*
 * coordinate.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_TILE_COORDINATE_H_
#define INCLUDE_C_TILE_COORDINATE_H_

typedef struct {
    s16 x;
    s16 y;
} coordinate_t;

typedef struct {
	coordinate_t coordinates;
	u8 height;
} position_t;

/**
 * Initializes the position structure with the player's data.
 * @param pos the position structure to initialize
 */
void player_get_position(position_t *pos);

/**
 * Initializes the structure with the tile the player is facing. If the player is on height 0=any,
 * the height of the tile they are facing will be 0=any as well.
 * @param pos the position structure to initialize
 */
void player_get_position_faced(position_t *pos);

#endif /* INCLUDE_C_TILE_COORDINATE_H_ */
