#include "types.h"
#include "map/tileset.h"
#include "debug.h"

extern const u16 gfx_tileset_0_anim_0Tiles[];
extern const u16 gfx_tileset_0_anim_1Tiles[];
extern const u16 gfx_tileset_0_anim_2Tiles[];
extern const u16 gfx_tileset_0_anim_3Tiles[];
extern const u16 gfx_tileset_0_anim_4Tiles[];
extern const u16 gfx_tileset_0_anim_5Tiles[];

static const tileset_animation tileset_0_animations[] = {
    {
        .cycle=5,
        .speed=16,
        .start_tile=508,
        .num_tiles=48,
        .gfx=gfx_tileset_0_anim_0Tiles
    },
    {
        .cycle=4,
        .speed=16,
        .start_tile=556,
        .num_tiles=60,
        .gfx=gfx_tileset_0_anim_1Tiles
    },
    {
        .cycle=8,
        .speed=16,
        .start_tile=500,
        .num_tiles=8,
        .gfx=gfx_tileset_0_anim_2Tiles
    },
    {
        .cycle=4,
        .speed=16,
        .start_tile=616,
        .num_tiles=24,
        .gfx=gfx_tileset_0_anim_3Tiles
    },
    {
        .cycle=4,
        .speed=16,
        .start_tile=480,
        .num_tiles=10,
        .gfx=gfx_tileset_0_anim_4Tiles
    },
};

static const tileset_animation_header tileset_0_animations_head = {
    ARRAY_COUNT(tileset_0_animations), tileset_0_animations
};


void tileset_0_anim(u16 clk){
    generic_tileset_anim_proceed_all(&tileset_0_animations_head, clk);
}

void tileset_0_anim_init(){
    tileset_anim_clk0_cycle = generic_tileset_anim_get_clk(&tileset_0_animations_head);
    tileset_anim_0 = tileset_0_anim;
}
