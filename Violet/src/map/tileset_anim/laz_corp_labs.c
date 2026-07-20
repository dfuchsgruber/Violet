#include "types.h"
#include "map/tileset.h"


extern const u8 gfx_tileset_animation_laz_corp_lab_cloudsTiles[];
extern const u8 gfx_tileset_animation_laz_corp_lab_cloudsPal[];
static const tileset_animation tileset_laz_corp_labs_animations[] = {
    {
        .cycle = 8, .speed = 8, .start_tile = 0x3E0, .num_tiles = 21, .gfx = gfx_tileset_animation_laz_corp_lab_cloudsTiles,
    },
};

static const tileset_animation_header tileset_laz_corp_labs_animations_head = {
    (int)ARRAY_COUNT(tileset_laz_corp_labs_animations), tileset_laz_corp_labs_animations
};

void tileset_laz_corp_labs_anim(u16 clk){
    generic_tileset_anim_proceed_all(&tileset_laz_corp_labs_animations_head, clk);
}

void tileset_laz_corp_labs_anim_initialize(){
    tileset_anim_clk1_cycle = generic_tileset_anim_get_clk(&tileset_laz_corp_labs_animations_head);
    tileset_anim_1 = tileset_laz_corp_labs_anim;
}
