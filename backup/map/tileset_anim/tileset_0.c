#include "types.h"
#include "map/tileset.h"

extern u16 gfx_tileset_0_anim_0Tiles[];
extern u16 gfx_tileset_0_anim_1Tiles[];
extern u16 gfx_tileset_0_anim_2Tiles[];
extern u16 gfx_tileset_0_anim_3Tiles[];
extern u16 gfx_tileset_0_anim_4Tiles[];
extern u16 gfx_tileset_0_anim_5Tiles[];

tileset_animation tileset_0_animations[] = {
    {
        5, 16, 508, 48, gfx_tileset_0_anim_0Tiles
    },
    {
        4, 16, 556, 60, gfx_tileset_0_anim_1Tiles
    },
    {
        8, 16, 500, 8, gfx_tileset_0_anim_2Tiles
    },
    {
        4, 16, 616, 24, gfx_tileset_0_anim_3Tiles
    },
    {
        4, 16, 480, 10, gfx_tileset_0_anim_4Tiles
    },
};

tileset_animation_header tileset_0_animations_head = {
    5, tileset_0_animations
};


void tileset_0_anim(u16 clk){
    generic_tileset_anim_proceed_all(&tileset_0_animations_head, clk);
}

void tileset_0_anim_init(){
    tileset_anim_clk0_cycle = generic_tileset_anim_get_clk(&tileset_0_animations_head);
    tileset_anim_0 = tileset_0_anim;
}
