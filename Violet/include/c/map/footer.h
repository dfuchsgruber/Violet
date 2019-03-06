/*
 * footer.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_MAP_FOOTER_H_
#define INCLUDE_C_MAP_FOOTER_H_

#include "map/tileset.h"

typedef struct map_block {
    u16 block_id : 10;
    u16 level : 6;
} map_block;

typedef struct mapfooter {
    u32 width;
    u32 height;
    u16 *border_blocks;
    map_block *map;
    tileset *tileset1;
    tileset *tileset2;
    u8 border_width;
    u8 border_height;
    u16 padding;
} map_footer_t;


extern map_footer_t *mapfooters[];
extern map_footer_t mapfooter_virtual;

map_footer_t *get_mapfooter();

void tile_init(map_footer_t *foot);

void map_delta_to_map_tile(map_footer_t *foot, u16 map_tile_id, s16 x_relative, s16 y_relative);

#endif /* INCLUDE_C_MAP_FOOTER_H_ */
