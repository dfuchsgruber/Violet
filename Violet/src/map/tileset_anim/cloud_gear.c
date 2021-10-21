
#include "map/tileset.h"
#include "types.h"

extern u16 gfx_tileset_cloud_gear_anim_gearsTiles[];
extern u16 gfx_tileset_clouds_gear_anim_frameTiles[];

static tileset_animation tileset_cloud_gear_animations[] = {
    {.cycle = 2, .speed = 16, .start_tile = 0x300, .num_tiles = 6 * 4, .gfx = gfx_tileset_cloud_gear_anim_gearsTiles},
    {.cycle = 2, .speed = 16, .start_tile = 0x284, .num_tiles = 6, .gfx = gfx_tileset_clouds_gear_anim_frameTiles},
};

static tileset_animation_header tileset_cloud_gear_animation_head = {
    ARRAY_COUNT(tileset_cloud_gear_animations), tileset_cloud_gear_animations};

static void tileset_cloud_gear_anim(u16 clk) {
    generic_tileset_anim_proceed_all(&tileset_cloud_gear_animation_head, clk);
}

void tileset_cloud_gear_animation_initialize() {
    tileset_anim_clk1_cycle = generic_tileset_anim_get_clk(&tileset_cloud_gear_animation_head);
    tileset_anim_1 = tileset_cloud_gear_anim;
}
