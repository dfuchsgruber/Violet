
#include "map/tileset.h"
#include "types.h"

extern u16 gfx_maptileset_dungeon_tent_and_campfire_anim_fireTiles[];

static tileset_animation tileset_dungeon_forest_tent_animations[] = {
    {.cycle = 4, .speed = 16, .start_tile = 0x310, .num_tiles = 6, .gfx = gfx_maptileset_dungeon_tent_and_campfire_anim_fireTiles},
};

static tileset_animation_header tileset_dungeon_forest_tent_animation_head = {
    1, tileset_dungeon_forest_tent_animations};

static void tileset_dungeon_forest_tent_anim(u16 clk) {
    generic_tileset_anim_proceed_all(&tileset_dungeon_forest_tent_animation_head, clk);
}

void tileset_dungeon_forest_tent_animation_initialize() {
    tileset_anim_clk1_cycle = generic_tileset_anim_get_clk(&tileset_dungeon_forest_tent_animation_head);
    tileset_anim_1 = tileset_dungeon_forest_tent_anim;
}
