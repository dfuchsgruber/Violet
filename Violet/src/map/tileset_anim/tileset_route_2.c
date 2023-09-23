#include "types.h"
#include "map/tileset.h"

extern const u16 gfx_tileset_animation_route_2_sunflowerTiles[];

static const tileset_animation tileset_route_2_animations[] = {
    {
		.cycle = 4, .speed = 16, .start_tile = 0x315, .num_tiles = 8,
		.gfx = gfx_tileset_animation_route_2_sunflowerTiles
    }
};

static const tileset_animation_header tileset_route_2_animations_head = {
    1, tileset_route_2_animations
};


void tileset_route_2_anim(u16 clk){
    generic_tileset_anim_proceed_all(&tileset_route_2_animations_head, clk);
}

void tileset_route_2_anim_init(){
    tileset_anim_clk1_cycle = generic_tileset_anim_get_clk(&tileset_route_2_animations_head);
    tileset_anim_1 = tileset_route_2_anim;
}

