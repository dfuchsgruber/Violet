#include "types.h"
#include "map/tileset.h"

extern u16 gfx_maptileset_dungeon_steel_cave_small_rockTiles[];
extern u16 gfx_maptileset_dungeon_steel_cave_big_rockTiles[];

static tileset_animation tileset_dungeon_steel_cave_animations[] = {
    {.cycle = 10, .speed = 8, .start_tile = 0x2f0, .num_tiles = 4, .gfx = gfx_maptileset_dungeon_steel_cave_small_rockTiles},
    {.cycle = 10, .speed = 8, .start_tile = 0x2e0, .num_tiles = 16, .gfx = gfx_maptileset_dungeon_steel_cave_big_rockTiles},
};

static tileset_animation_header tileset_dungeon_steel_cave_animation_head = {
    ARRAY_COUNT(tileset_dungeon_steel_cave_animations), tileset_dungeon_steel_cave_animations,
};


static void tileset_dungeon_steel_cave_anim(u16 clk){
    generic_tileset_anim_proceed_all(&tileset_dungeon_steel_cave_animation_head, clk);
}

void tileset_dungeon_steel_cave_animation_initialize(){
    tileset_anim_clk1_cycle = generic_tileset_anim_get_clk(&tileset_dungeon_steel_cave_animation_head);
    tileset_anim_1 = tileset_dungeon_steel_cave_anim;
}
