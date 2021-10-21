/*
 * tileset_route_7.c
 *
 *  Created on: Mar 5, 2019
 *      Author: dominik
 */
#include "map/tileset.h"
#include "types.h"

extern u16 gfx_tileset_route_7_anim_fireTiles[];

tileset_animation tileset_route_7_animations[] = {
    {.cycle = 4, .speed = 16, .start_tile = 0x37A, .num_tiles = 4, .gfx = gfx_tileset_route_7_anim_fireTiles}};

tileset_animation_header tileset_route_7_animations_head = {
    1, tileset_route_7_animations};

void tileset_route_7_anim(u16 clk) {
    generic_tileset_anim_proceed_all(&tileset_route_7_animations_head, clk);
}

void tileset_route_7_anim_init() {
    tileset_anim_clk1_cycle = generic_tileset_anim_get_clk(&tileset_route_7_animations_head);
    tileset_anim_1 = tileset_route_7_anim;
}
