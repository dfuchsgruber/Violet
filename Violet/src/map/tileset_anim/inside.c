#include "types.h"
#include "map/tileset.h"
#include "debug.h"
#include "overworld/tv.h"

extern const u8 gfx_tileset_inside_anim_tvTiles[];

static const tileset_animation tileset_inside_animations[] = {
    {
        .cycle=5,
        .speed=4,
        .start_tile=0x100,
        .num_tiles=14,
        .gfx=gfx_tileset_inside_anim_tvTiles,
    },
};

static const tileset_animation_header tileset_inside_animations_head = {
    ARRAY_COUNT(tileset_inside_animations), tileset_inside_animations
};

static const tileset_animation tileset_inside_animations_tv_off[] = {
    {
        .cycle=1,
        .speed=256,
        .start_tile=0x100,
        .num_tiles=14,
        .gfx=gfx_tileset_inside_anim_tvTiles + 14 * 5 * GRAPHIC_SIZE_4BPP(8, 8), // 5 frames of 14 tiles each, 32 bytes per tile (8x8 tiles)
    },
};

static const tileset_animation_header tileset_inside_animations_head_tv_off = {
    ARRAY_COUNT(tileset_inside_animations_tv_off), tileset_inside_animations_tv_off
};


void tileset_inside_anim(u16 clk){
    if (tv_broadcast_is_on()) {
        generic_tileset_anim_proceed_all(&tileset_inside_animations_head, clk);
    } else {
        generic_tileset_anim_proceed_all(&tileset_inside_animations_head_tv_off, clk);
    }
}

void tileset_inside_anim_init(){
    tileset_anim_clk0_cycle = generic_tileset_anim_get_clk(&tileset_inside_animations_head);
    tileset_anim_0 = tileset_inside_anim;
}
