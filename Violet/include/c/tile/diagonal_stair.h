/*
 * diagonal_stair.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_TILE_DIAGONAL_STAIR_H_
#define INCLUDE_C_TILE_DIAGONAL_STAIR_H_

#define BEHAVIOR_SIDE_STAIR_WEST 0xB4
#define BEHAVIOR_SIDE_STAIR_EAST 0xB5

#define DIAG_NO 0x80
#define DIAG_SO 0x81
#define DIAG_SW 0x82
#define DIAG_NW 0x83

/**
 * Checks if an npc can perform a diagonal move.
 * @param n the npc
 * @param x_to_origin the original direction that would be reached without a diagonal move
 * @param y_to_orogin the original direction that would be reached without a diagonal move
 * @param direction the direction to walk into
 * @return the collision that happens after attempting the diagonal move
 */
u8 npc_attempt_diagonal_move(npc *n, s16 x_to_origin, s16 y_to_origin, u8 direction);

#endif /* INCLUDE_C_TILE_DIAGONAL_STAIR_H_ */
