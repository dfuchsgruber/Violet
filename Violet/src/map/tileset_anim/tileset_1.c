#include "types.h"
#include "map/tileset.h"

extern u16 gfx_tileset_1_anim_waterTiles[];

static tileset_animation tileset_1_animations[] = {
    {
        .cycle = 5, .speed = 16, .start_tile = 0x3b2, .num_tiles = 10, .gfx = gfx_tileset_1_anim_waterTiles,
    },
};

static tileset_animation_header tileset_1_animations_head = {
    (int)ARRAY_COUNT(tileset_1_animations), tileset_1_animations
};

void tileset_1_anim(u16 clk){
    generic_tileset_anim_proceed_all(&tileset_1_animations_head, clk);
}

void tileset_1_anim_init(){
    tileset_anim_clk1_cycle = generic_tileset_anim_get_clk(&tileset_1_animations_head);
    tileset_anim_1 = tileset_1_anim;
}
