#include "map/tileset.h"
#include "types.h"

extern u8 gfx_tileset_anim_power_plant_inside_sparksTiles[];

static tileset_animation tileset_power_plant_inside_animations[] = {
    {.cycle = 2, .speed = 8, .start_tile = 0x390, .num_tiles = 32, .gfx = gfx_tileset_anim_power_plant_inside_sparksTiles}};

static tileset_animation_header tileset_power_plant_inside_animations_head = {
    ARRAY_COUNT(tileset_power_plant_inside_animations), tileset_power_plant_inside_animations};

static void tileset_power_plant_inside_anim(u16 clk) {
    generic_tileset_anim_proceed_all(&tileset_power_plant_inside_animations_head, clk);
}

void tileset_power_plant_inside_anim_init() {
    tileset_anim_clk1_cycle = generic_tileset_anim_get_clk(&tileset_power_plant_inside_animations_head);
    tileset_anim_1 = tileset_power_plant_inside_anim;
}
