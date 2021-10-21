

#include "map/tileset.h"
#include "types.h"

extern u16 gfx_tileset_cloud_ruins_anim_torchTiles[];

tileset_animation tileset_cloud_ruins_animations[] = {
    {.cycle = 4, .speed = 16, .start_tile = 0x2ad, .num_tiles = 2, .gfx = gfx_tileset_cloud_ruins_anim_torchTiles},
};

tileset_animation_header tileset_cloud_ruins_animation_head = {
    1, tileset_cloud_ruins_animations};

void tileset_cloud_ruins_anim(u16 clk) {
    generic_tileset_anim_proceed_all(&tileset_cloud_ruins_animation_head, clk);
}

void tileset_cloud_ruins_anim_init() {
    tileset_anim_clk1_cycle = generic_tileset_anim_get_clk(&tileset_cloud_ruins_animation_head);
    tileset_anim_1 = tileset_cloud_ruins_anim;
}
