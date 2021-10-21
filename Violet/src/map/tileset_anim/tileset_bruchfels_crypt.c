#include "map/tileset.h"
#include "types.h"

extern u8 gfx_tileset_bruchfels_crypt_anim_torchTiles[];

tileset_animation tileset_bruchfels_crypt_animations[] = {
    {
        .cycle = 4,
        .speed = 16,
        .start_tile = 0x2c2,
        .num_tiles = 2,
        gfx_tileset_bruchfels_crypt_anim_torchTiles,
    },
};

tileset_animation_header tileset_bruchfels_crypt_animations_head = {
    ARRAY_COUNT(tileset_bruchfels_crypt_animations), tileset_bruchfels_crypt_animations};

void tileset_bruchfels_crypt_anim(u16 clk) {
    generic_tileset_anim_proceed_all(&tileset_bruchfels_crypt_animations_head, clk);
}

void tileset_bruchfels_crypt_anim_init() {
    tileset_anim_clk0_cycle = generic_tileset_anim_get_clk(&tileset_bruchfels_crypt_animations_head);
    tileset_anim_0 = tileset_bruchfels_crypt_anim;
}
