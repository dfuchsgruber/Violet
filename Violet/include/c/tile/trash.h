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

/**
 * Checks if the flag of a trash can is set.
 * @param x the x position of the trash can
 * @param y the y position of the trash can
 * @param bank the bank of the trash can
 * @param map_idx the map index of the trash can
 * @return if the flag of the trash can is set
 **/
bool trash_checkflag(s16 x, s16 y, u8 bank, u8 map_idx);

/**
 * Set the flag of a trash can.
 * @param x the x position of the trash can
 * @param y the y position of the trash can
 * @param bank the bank of the trash can
 * @param map_idx the map index of the trash can
 **/
void trash_setflag(s16 x, s16 y, u8 bank, u8 map_idx);

/**
 * Generates a hash for a certain position on a map.
 * @param x the x coordinate
 * @param y the y coordinate
 * @param bank the bank of the position
 * @param map_idx the map_idx of the position
 * @return a 16-bit hash in range [0, m-1] of this very position
 **/
u16 tile_hash_by_position(s16 x, s16 y, u8 bank, u8 map_idx, size_t m);

u32 block_get_field_by_pos(s16 x, s16 y, u8 field);

#endif /* INCLUDE_C_TILE_TRASH_H_ */
