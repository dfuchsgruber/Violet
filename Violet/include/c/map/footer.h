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

map_footer_t *get_mapfooter();

/**
 * @brief Loads the tiles of the primary and secondary tileset
 * 
 * @param footer the footer to load tiles of
 */
void overworld_load_tilesets(map_footer_t *footer);

/**
 * @brief Loads the palettes of tilesets and applies dns effects (highlights certain colors)
 * 
 * @param footer the footer to load pals of
 */
void overworld_load_tileset_pals(map_footer_t *footer);

/**
 * @brief Loads the palettes of tilesets as are (does not apply palette effects)
 * 
 * @param footer the footer to load the pals of
 */
void overworld_load_tileset_pals_without_palette_effects(map_footer_t *footer);

/**
 * Draws a block onto the bg and schedules a vram copy for bg1-bg3.
 * @param f the footer to use
 * @param offset at which offset to put the block
 * @param x the x coordiante in the map
 * @param y the y coordinate in the map
 **/
void map_draw_block_at_position(map_footer_t *f, u16 offset, s16 x, s16 y);

u16 *overworld_bg1_tilemap;
u16 *overworld_bg2_tilemap;
u16 *overworld_bg3_tilemap;

#endif /* INCLUDE_C_MAP_FOOTER_H_ */
