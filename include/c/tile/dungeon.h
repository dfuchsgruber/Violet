/*
 * dungeon.h
 *
 *  Created on: Aug 18, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_TILE_DUNGEON_H_
#define INCLUDE_C_TILE_DUNGEON_H_

#include "types.h"

/**
 * Maps the current dungeon id to 0, ..., 126 using the current a-vector
 * @param dungeon_id the dungeon id to hash
 * @return the hash of the dungeon
 */
u32 dungeon_hash(int dungeon_id);


/**
 * Check if a dungeon has been visited
 * @param dungeon_id the dungeon id to check
 * @return if the dungeon has been visited
 */
bool dungeon_flag_check(int dungeon_id);

/**
 * Sets a dungeon as visited
 * @param dungeon_id the dungeon id to set to visited
 */
void dungeon_flag_set(int dungeon_id);

#endif /* INCLUDE_C_TILE_DUNGEON_H_ */
