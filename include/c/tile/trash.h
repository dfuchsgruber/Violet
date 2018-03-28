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
int get_tile_hash_by_facing(u8 facing, int m);
int a_hash(s16 x, s16 y, u8 map, u8 bank, int m);
void new_a_vector();
u32 tile_get_field_by_pos(s16 x, s16 y, u8 field);

#endif /* INCLUDE_C_TILE_TRASH_H_ */
