/*
 * tileset_ardeal.c
 *
 *  Created on: Mar 5, 2019
 *      Author: dominik
 */
#include "map/tileset.h"
#include "types.h"

extern u16 gfx_tileset_ardeal_anim_chandelierTiles[];

tileset_animation tileset_ardeal_animations[] = {
    {.cycle = 4, .speed = 16, .start_tile = 0x3E0, .num_tiles = 8, .gfx = gfx_tileset_ardeal_anim_chandelierTiles}};

tileset_animation_header tileset_ardeal_animations_head = {
    1, tileset_ardeal_animations};

void tileset_ardeal_anim(u16 clk) {
    generic_tileset_anim_proceed_all(&tileset_ardeal_animations_head, clk);
}

void tileset_ardeal_anim_init() {
    tileset_anim_clk1_cycle = generic_tileset_anim_get_clk(&tileset_ardeal_animations_head);
    tileset_anim_1 = tileset_ardeal_anim;
}
