#include "map/tileset.h"
#include "types.h"

extern u16 gfx_tileset_anim_dark_tower_fireTiles[];

static tileset_animation animations[] = {
    {.cycle = 4, .speed = 16, .start_tile = 0x31C, .num_tiles = 4, .gfx = gfx_tileset_anim_dark_tower_fireTiles},
};

static tileset_animation_header animation_header = {
    1, animations};

static void tileset_animation_callback(u16 clk) {
    generic_tileset_anim_proceed_all(&animation_header, clk);
}

void tileset_dark_tower_anim_init() {
    tileset_anim_clk0_cycle = generic_tileset_anim_get_clk(&animation_header);
    tileset_anim_0 = tileset_animation_callback;
}
