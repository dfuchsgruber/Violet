#include "types.h"
#include "map/tileset.h"

extern u16 gfx_maptileset_clouds_kaskada_animation_stegTiles[];
extern u16 gfx_maptileset_clouds_kaskada_animation_well_lowerTiles[];
extern u16 gfx_maptileset_clouds_kaskada_animation_well_upperTiles[];
extern u16 gfx_maptileset_clouds_kaskada_animation_stoneTiles[];

static tileset_animation animations[] = {
    {.cycle = 4, .speed = 16, .start_tile = 0x390, .num_tiles = 15, .gfx = gfx_maptileset_clouds_kaskada_animation_stegTiles},
    {.cycle = 4, .speed = 16, .start_tile = 0x375, .num_tiles = 9, .gfx = gfx_maptileset_clouds_kaskada_animation_well_upperTiles},
    {.cycle = 4, .speed = 16, .start_tile = 0x385, .num_tiles = 9, .gfx = gfx_maptileset_clouds_kaskada_animation_well_lowerTiles},
    {.cycle = 4, .speed = 16, .start_tile = 0x35c, .num_tiles = 3, .gfx = gfx_maptileset_clouds_kaskada_animation_stoneTiles},
};

static tileset_animation_header animations_header = {
    ARRAY_COUNT(animations), animations,
};


static void tileset_animation_callback(u16 clk){
    generic_tileset_anim_proceed_all(&animations_header, clk);
}

void tileset_clouds_kaskada_animation_initialize(){
    tileset_anim_clk1_cycle = generic_tileset_anim_get_clk(&animations_header);
    tileset_anim_1 = tileset_animation_callback;
}
