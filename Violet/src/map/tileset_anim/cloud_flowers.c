
#include "types.h"
#include "map/tileset.h"

extern u16 gfx_tileset_clouds_flowers_anim_flowersTiles[];
extern u16 gfx_tileset_clouds_gear_anim_frameTiles[];

static tileset_animation tileset_cloud_flowers_animations[] = {
    {.cycle = 4, .speed = 32, .start_tile = 0x396, .num_tiles = 8, .gfx = gfx_tileset_clouds_flowers_anim_flowersTiles},
};

static tileset_animation_header tileset_cloud_flowers_animation_head = {
    ARRAY_COUNT(tileset_cloud_flowers_animations), tileset_cloud_flowers_animations
};


static void tileset_cloud_flowers_anim(u16 clk){
    generic_tileset_anim_proceed_all(&tileset_cloud_flowers_animation_head, clk);
}

void tileset_cloud_flowers_animation_initialize(){
    tileset_anim_clk1_cycle = generic_tileset_anim_get_clk(&tileset_cloud_flowers_animation_head);
    tileset_anim_1 = tileset_cloud_flowers_anim;
}