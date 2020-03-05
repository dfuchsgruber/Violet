#include "types.h"
#include "map/tileset.h"

extern u16 gfx_tileset_clouds_anim_waterTiles[];
extern u16 gfx_tileset_clouds_anim_waterfallTiles[];
extern u16 gfx_tileset_clouds_anim_torchTiles[];

tileset_animation tileset_clouds_animations[] = {
    {.cycle = 4, .speed = 16, .start_tile = 0x100, .num_tiles = 52, .gfx = gfx_tileset_clouds_anim_waterTiles},
    {.cycle = 4, .speed = 16, .start_tile = 0x134, .num_tiles = 10, .gfx = gfx_tileset_clouds_anim_waterfallTiles},
    {.cycle = 4, .speed = 16, .start_tile = 0x147, .num_tiles = 2, .gfx = gfx_tileset_clouds_anim_torchTiles},
};

tileset_animation_header tileset_clouds_animation_head = {
    3, tileset_clouds_animations
};


void tileset_clouds_anim(u16 clk){
    generic_tileset_anim_proceed_all(&tileset_clouds_animation_head, clk);
}

void tileset_clouds_anim_init(){
    tileset_anim_clk0_cycle = generic_tileset_anim_get_clk(&tileset_clouds_animation_head);
    tileset_anim_0 = tileset_clouds_anim;
}
