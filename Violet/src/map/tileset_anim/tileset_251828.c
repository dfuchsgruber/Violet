#include "types.h"
#include "map/tileset.h"

extern const u16 gfx_tileset_251828_anim_0Tiles[];
extern const u16 gfx_tileset_251828_anim_1Tiles[];

static const tileset_animation tileset_251828_animations[] = {
    {
        .cycle=4,
        .speed=16,
        .start_tile=656,
        .num_tiles=4,
        .gfx=gfx_tileset_251828_anim_0Tiles
    },
    {
        .cycle=4,
        .speed=16,
        .start_tile=661,
        .num_tiles=8,
        .gfx=gfx_tileset_251828_anim_1Tiles
    }
};

static const tileset_animation_header tileset_251828_animations_head = {
    ARRAY_COUNT(tileset_251828_animations), tileset_251828_animations
};


void tileset_251828_anim(u16 clk){
    generic_tileset_anim_proceed_all(&tileset_251828_animations_head, clk);
}

void tileset_251828_anim_init(){
    tileset_anim_clk1_cycle = generic_tileset_anim_get_clk(&tileset_251828_animations_head);
    tileset_anim_1 = tileset_251828_anim;
}
