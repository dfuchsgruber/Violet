#include "types.h"
#include "map/tileset.h"

extern u8 gfx_tileset_cave_anim_waterTiles[];
extern u8 gfx_tileset_cave_anim_water_streamTiles[];


tileset_animation tileset_cave_animations[] = {
    {
        .cycle = 8, .speed = 16, .start_tile = 0x160, .num_tiles = 8, gfx_tileset_cave_anim_waterTiles,
    },
    {
        .cycle = 8, .speed = 16, .start_tile = 0x1D0, .num_tiles = 16, gfx_tileset_cave_anim_water_streamTiles,
    },
};

tileset_animation_header tileset_cave_animations_head = {
    ARRAY_COUNT(tileset_cave_animations), tileset_cave_animations
};


void tileset_cave_anim(u16 clk){
    generic_tileset_anim_proceed_all(&tileset_cave_animations_head, clk);
}

void tileset_cave_anim_init(){
    tileset_anim_clk0_cycle = generic_tileset_anim_get_clk(&tileset_cave_animations_head);
    tileset_anim_0 = tileset_cave_anim;
}
