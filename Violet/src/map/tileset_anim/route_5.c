
#include "types.h"
#include "map/tileset.h"

extern u16 gfx_tileset_route_5_anim_torchTiles[];

tileset_animation tileset_route_5_animations[] = {
    {.cycle = 4, .speed = 16, .start_tile = 0x28b, .num_tiles = 2, .gfx = gfx_tileset_route_5_anim_torchTiles},
};

tileset_animation_header tileset_route_5_animation_head = {
    1, tileset_route_5_animations
};


void tileset_route_5_anim(u16 clk){
    generic_tileset_anim_proceed_all(&tileset_route_5_animation_head, clk);
}

void tileset_route_5_anim_init(){
    tileset_anim_clk1_cycle = generic_tileset_anim_get_clk(&tileset_route_5_animation_head);
    tileset_anim_1 = tileset_route_5_anim;
}
