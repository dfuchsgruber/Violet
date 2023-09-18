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
#include "overworld/effect.h"

typedef struct map_tileset_info {
    u8 compression_used;
    u8 color_section : 1; //0 and 1 are possible
    u8 padding : 7;
    u8 field_2;
    u8 field_3;

} map_tileset_info;

typedef struct tileset {
    const map_tileset_info info;
    const void *graphic;
    const u16 *colors; //6 * 16 colors
    const bg_tile *blocks;
    void *(*animation_init)();
    const block_data *behaviours;
    const any_grass_header_t *any_grasses;
} tileset;

typedef struct {
    u16 cycle;
    u16 speed;
    u16 start_tile;
    u16 num_tiles;
    const void *gfx;
} tileset_animation;

typedef struct {
    size_t cnt;
    const tileset_animation *animations;
} tileset_animation_header;

extern u16 tileset_anim_clk0;
extern u16 tileset_anim_clk0_cycle;
extern u16 tileset_anim_clk1;
extern u16 tileset_anim_clk1_cycle;
extern void (*tileset_anim_0)(u16);
extern void (*tileset_anim_1)(u16);

u16 generic_tileset_anim_get_clk(const tileset_animation_header *anim_header);

void generic_tileset_anim_proceed(const tileset_animation *anim, u16 clk);

void generic_tileset_anim_proceed_all(const tileset_animation_header *anim_header,
        u16 clk);

void overworld_load_tileset_pal(const tileset *t, u16 dst_col, u16 bytecnt);

/**
 * Initializes the animations of the secondary tileset, but not general map effects like cloud upstreams
 **/
void _tileset_secondary_animation_initialize();

/**
 * Proceeds tileset animation callbacks and clocks. Called by the overworld_proceed function.
 */
void tileset_anim_proceed();

/**
 * Checks if a primary tileset is a cloud primary tileset
 * @param tsp the tileset
 * @return if the tileset is a cloud tileset
 **/
bool tileset_primary_is_clouds(const tileset *tsp);

extern const tileset maptileset0;
extern const tileset maptileset1;
extern const tileset maptileset2;
extern const tileset maptileset3;
extern const tileset maptileset4;
extern const tileset maptileset_orina_city;
extern const tileset maptileset249598;
extern const tileset maptileset302795;
extern const tileset maptileset242637;
extern const tileset maptileset251828;
extern const tileset maptileset_laubdorf;
extern const tileset maptileset_ceometria;
extern const tileset maptileset_haweiland;
extern const tileset maptileset_clouds;
extern const tileset maptileset_clouds_dark_green;
extern const tileset maptileset_clouds_canyon;
extern const tileset maptileset_clouds_pink;
extern const tileset maptileset_clouds_blue;
extern const tileset maptileset_cloud_ruins;
extern const tileset maptileset_cloud_ardeal;
extern const tileset maptileset_blackbeard_ship;
extern const tileset maptileset0_kaskada;
extern const tileset maptileset0_route_4;
extern const tileset maptileset0_aktania;

#endif /* INCLUDE_C_MAP_TILESET_H_ */
