#include "types.h"
#include "map/tileset.h"

extern u16 gfx_tileset_251828_anim_0Tiles[];
extern u16 gfx_tileset_251828_anim_1Tiles[];

tileset_animation tileset_251828_animations[] = {
    {
        4, 16, 656, 4, gfx_tileset_251828_anim_0Tiles
    },
    {
        4, 16, 661, 8, gfx_tileset_251828_anim_1Tiles
    }
};

tileset_animation_header tileset_251828_animations_head = {
    2, tileset_251828_animations
};


void tileset_251828_anim(u16 clk){
    generic_tileset_anim_proceed_all(&tileset_251828_animations_head, clk);
}

void tileset_251828_anim_init(){
    tileset_anim_clk1_cycle = generic_tileset_anim_get_clk(&tileset_251828_animations_head);
    tileset_anim_1 = tileset_251828_anim;
}
