/*
 * trash.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_TILE_TRASH_H_
#define INCLUDE_C_TILE_TRASH_H_

void special_set_trashflag();
void generate_trash_item(u8 facing);
bool check_trashflag(u8 facing);
void set_trashflag(u8 facing);
/**
 * Calculates the "hash" of a block (hashes sequence {x, y, bank, map}
 * @param facing the direction the player is facing
 * @param m the number of buckets to hash into
 * @return the "hash" of the block
 */
u32 get_tile_hash_by_facing(u8 facing, size_t m);
u32 block_get_field_by_pos(s16 x, s16 y, u8 field);

#endif /* INCLUDE_C_TILE_TRASH_H_ */
