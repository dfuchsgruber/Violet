#include "types.h"
#include "map/tileset.h"


extern const u8 gfx_tileset_animation_clouds_swamp_waterTiles[];
static const tileset_animation tileset_clouds_swamp_animations[] = {
    {
        .cycle = 4, .speed = 16, .start_tile = 0x2E0, .num_tiles = 15, .gfx = gfx_tileset_animation_clouds_swamp_waterTiles,
    },
};

static const tileset_animation_header tileset_clouds_swamp_animations_head = {
    (int)ARRAY_COUNT(tileset_clouds_swamp_animations), tileset_clouds_swamp_animations
};

void tileset_clouds_swamp_anim(u16 clk){
    generic_tileset_anim_proceed_all(&tileset_clouds_swamp_animations_head, clk);
}

void tileset_clouds_swamp_anim_initialize(){
    tileset_anim_clk1_cycle = generic_tileset_anim_get_clk(&tileset_clouds_swamp_animations_head);
    tileset_anim_1 = tileset_clouds_swamp_anim;
}
