#include "types.h"
#include "map/tileset.h"

extern u16 gfx_maptileset_dungeon_sand_cave_anim_quicksandTiles[];

static tileset_animation tileset_dungeon_sand_cave_animations[] = {
    {.cycle = 3, .speed = 8, .start_tile = 0x2c6, .num_tiles = 4, .gfx = gfx_maptileset_dungeon_sand_cave_anim_quicksandTiles},
};

static tileset_animation_header tileset_dungeon_sand_cave_animation_head = {
    1, tileset_dungeon_sand_cave_animations
};


static void tileset_dungeon_sand_cave_anim(u16 clk){
    generic_tileset_anim_proceed_all(&tileset_dungeon_sand_cave_animation_head, clk);
}

void tileset_dungeon_sand_cave_animation_initialize(){
    tileset_anim_clk1_cycle = generic_tileset_anim_get_clk(&tileset_dungeon_sand_cave_animation_head);
    tileset_anim_1 = tileset_dungeon_sand_cave_anim;
}
