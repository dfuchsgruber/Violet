#include "types.h"
#include "map/tileset.h"

extern u8 gfx_maptileset_silvania_animation_sparklesTiles[];

tileset_animation tileset_silvania_animations[] = {
    {
		.cycle = 6, .speed = 8, .start_tile = 0x282, .num_tiles = 4 * 3,
		.gfx = gfx_maptileset_silvania_animation_sparklesTiles
    }
};

tileset_animation_header tileset_silvania_animations_head = {
    ARRAY_COUNT(tileset_silvania_animations), tileset_silvania_animations
};


void tileset_silvania_anim(u16 clk){
    generic_tileset_anim_proceed_all(&tileset_silvania_animations_head, clk);
}

void tileset_silvania_anim_init(){
    tileset_anim_clk1_cycle = generic_tileset_anim_get_clk(&tileset_silvania_animations_head);
    tileset_anim_1 = tileset_silvania_anim;
}