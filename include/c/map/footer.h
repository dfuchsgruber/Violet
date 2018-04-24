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
} mapfooter;


extern mapfooter *mapfooters[];
mapfooter *mapfooter_virtual = (mapfooter*)0x03004F90;

mapfooter *get_mapfooter();

void tile_init(mapfooter *foot);

void map_delta_to_map_tile(mapfooter *foot, u16 map_tile_id, s16 x_relative, s16 y_relative);

#endif /* INCLUDE_C_MAP_FOOTER_H_ */