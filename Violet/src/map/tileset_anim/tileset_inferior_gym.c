/*
 * tileset_inferior_gym.c
 *
 *  Created on: Mar 5, 2019
 *      Author: dominik
 */
#include "types.h"
#include "map/tileset.h"

extern const u16 gfx_tileset_inferior_gym_anim_0Tiles[];

static const tileset_animation tileset_inferior_gym_animations[] = {
    {
		.cycle = 4, .speed = 16, .start_tile = 0x2E0, .num_tiles = 4,
		.gfx = gfx_tileset_inferior_gym_anim_0Tiles
    }
};

static const tileset_animation_header tileset_inferior_gym_animations_head = {
    1, tileset_inferior_gym_animations
};


void tileset_inferior_gym_anim(u16 clk){
    generic_tileset_anim_proceed_all(&tileset_inferior_gym_animations_head, clk);
}

void tileset_inferior_gym_anim_init(){
    tileset_anim_clk0_cycle = generic_tileset_anim_get_clk(&tileset_inferior_gym_animations_head);
    tileset_anim_0 = tileset_inferior_gym_anim;
}

