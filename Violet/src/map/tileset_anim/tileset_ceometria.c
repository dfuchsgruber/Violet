#include "types.h"
#include "map/tileset.h"

extern const u16 gfx_tileset_ceometria_anim_0Tiles[];

static const tileset_animation tileset_ceometria_animations[] = {
    {
        .cycle = 2, .speed = 32, .start_tile = 0x3E7, .num_tiles = 6, 
        .gfx = gfx_tileset_ceometria_anim_0Tiles
    }
};

static const tileset_animation_header tileset_ceometria_animations_head = {
    1, tileset_ceometria_animations
};

void tileset_ceometria_anim(u16 clk){
    generic_tileset_anim_proceed_all(&tileset_ceometria_animations_head, clk);
}

void tileset_ceometria_anim_init(){
    tileset_anim_clk1_cycle = generic_tileset_anim_get_clk(&tileset_ceometria_animations_head);
    tileset_anim_1 = tileset_ceometria_anim;
}
