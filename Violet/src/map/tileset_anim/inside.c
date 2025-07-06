#include "types.h"
#include "map/tileset.h"
#include "debug.h"
#include "tile/tv.h"

extern const u16 gfx_tileset_inside_anim_tvTiles[];

static const tileset_animation tileset_inside_animations[] = {
    {
        .cycle=5,
        .speed=4,
        .start_tile=0x100,
        .num_tiles=14,
        .gfx=gfx_tileset_inside_anim_tvTiles,
        .is_active=tv_broadcast_is_on
    },
};

static const tileset_animation_header tileset_inside_animations_head = {
    ARRAY_COUNT(tileset_inside_animations), tileset_inside_animations
};


void tileset_inside_anim(u16 clk){
    generic_tileset_anim_proceed_all(&tileset_inside_animations_head, clk);
}

void tileset_inside_anim_init(){
    tileset_anim_clk0_cycle = generic_tileset_anim_get_clk(&tileset_inside_animations_head);
    tileset_anim_0 = tileset_inside_anim;
}
