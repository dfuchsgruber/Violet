#include "types.h"
#include "map/tileset.h"

extern const u16 gfx_maptileset_blackbeard_ship_light_animTiles[];

static const tileset_animation tileset_blackbeard_ship_animations[] = {
    {
		.cycle = 4, .speed = 32, .start_tile = 0x338, .num_tiles = 4,
		.gfx = gfx_maptileset_blackbeard_ship_light_animTiles
    }
};

static const tileset_animation_header tileset_blackbeard_ship_animations_head = {
    1, tileset_blackbeard_ship_animations
};


void tileset_blackbeard_ship_anim(u16 clk){
    generic_tileset_anim_proceed_all(&tileset_blackbeard_ship_animations_head, clk);
}

void tileset_blackbeard_ship_anim_init(){
    tileset_anim_clk1_cycle = generic_tileset_anim_get_clk(&tileset_blackbeard_ship_animations_head);
    tileset_anim_1 = tileset_blackbeard_ship_anim;
}

