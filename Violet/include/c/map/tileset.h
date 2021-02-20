/*
 * tileset.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_MAP_TILESET_H_
#define INCLUDE_C_MAP_TILESET_H_

#include "tile/block.h"
#include "bg.h"

typedef struct map_tileset_info {
    u8 compression_used;
    u8 color_section : 1; //0 and 1 are possible
    u8 padding : 7;
    u8 field_2;
    u8 field_3;

} map_tileset_info;

typedef struct tileset {
    map_tileset_info info;
    void *graphic;
    u16 *colors; //6 * 16 colors
    bg_tile *blocks;
    void *(*animation_init)();
    block_data *behaviours;
} tileset;

typedef struct {
    u16 cycle;
    u16 speed;
    u16 start_tile;
    u16 num_tiles;
    void *gfx;
} tileset_animation;

typedef struct {
    size_t cnt;
    tileset_animation *animations;
} tileset_animation_header;

extern u16 tileset_anim_clk0;
extern u16 tileset_anim_clk0_cycle;
extern u16 tileset_anim_clk1;
extern u16 tileset_anim_clk1_cycle;
extern void (*tileset_anim_0)(u16);
extern void (*tileset_anim_1)(u16);

u16 generic_tileset_anim_get_clk(tileset_animation_header *anim_header);

void generic_tileset_anim_proceed(tileset_animation *anim, u16 clk);

void generic_tileset_anim_proceed_all(tileset_animation_header *anim_header,
        u16 clk);

void overworld_load_tileset_pal(tileset *t, u16 dst_col, u16 bytecnt);

/**
 * Proceeds tileset animation callbacks and clocks. Called by the overworld_proceed function.
 */
void tileset_anim_proceed();

extern tileset maptileset0;
extern tileset maptileset1;
extern tileset maptileset2;
extern tileset maptileset3;
extern tileset maptileset4;
extern tileset maptileset245157;
extern tileset maptileset249598;
extern tileset maptileset302795;
extern tileset maptileset242637;
extern tileset maptileset251828;
extern tileset maptileset_laubdorf;
extern tileset maptileset_ceometria;
extern tileset maptileset_haweiland;
extern tileset maptileset_clouds;
extern tileset maptileset_cloud_ruins;
extern tileset maptileset_cloud_ardeal;
extern tileset maptileset_blackbeard_ship;
extern tileset maptileset0_kaskada;
extern tileset maptileset0_route_4;

#endif /* INCLUDE_C_MAP_TILESET_H_ */
