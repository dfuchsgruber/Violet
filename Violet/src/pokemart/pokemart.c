#include "types.h"
#include "tile/block.h"
#include "map/header.h"
#include "tile/coordinate.h"
#include "pokemart.h"
#include "overworld/sprite.h"

static void pokemart_draw_block(s16 x, s16 y, const u16 *src) {
    pokemart_bg3_tilemap[2 * x + 64 * y + 64 + 0] = src[0];
    pokemart_bg3_tilemap[2 * x + 64 * y + 64 + 1] = src[1];
    pokemart_bg3_tilemap[2 * x + 64 * y + 64 + 32 + 0] = src[2];
    pokemart_bg3_tilemap[2 * x + 64 * y + 64 + 32 + 1] = src[3];
    pokemart_bg2_tilemap[2 * x + 64 * y + 64 + 0] = src[4];
    pokemart_bg2_tilemap[2 * x + 64 * y + 64 + 1] = src[5];
    pokemart_bg2_tilemap[2 * x + 64 * y + 64 + 32 + 0] = src[6];
    pokemart_bg2_tilemap[2 * x + 64 * y + 64 + 32 + 1] = src[7];
    pokemart_bg1_tilemap[2 * x + 64 * y + 64 + 0] = src[8];
    pokemart_bg1_tilemap[2 * x + 64 * y + 64 + 1] = src[9];
    pokemart_bg1_tilemap[2 * x + 64 * y + 64 + 32 + 0] = src[10];
    pokemart_bg1_tilemap[2 * x + 64 * y + 64 + 32 + 1] = src[11];
}

void pokemart_draw_overworld_bgs() {
    coordinate_t center;
    player_get_facing_position(&center.x, &center.y);
    center.x = (s16)(center.x - 2);
    center.y = (s16)(center.y - 3);
    for (s16 j = 0; j < 10; j++) {
        for (s16 i = 0; i < 5; i++) {
            u16 block_idx = block_get_by_pos((s16)(center.x + i), (s16)(center.y + j));
            if (block_idx < 0x280) {
                pokemart_draw_block(i, j, (u16*)(mapheader_virtual.footer->tileset1->blocks) + 12 * block_idx);
            } else {
                pokemart_draw_block(i, j, (u16*)(mapheader_virtual.footer->tileset2->blocks) + 12 * (block_idx - 0x280));
            }
        }
    }
}


void pokemart_create_npc_oams() {
    for (int i = 0; i < 16; i++) {
        if (pokemart_viewport_npcs[i].npc_idx == 16) 
            continue;
        const overworld_sprite *ow = overworld_get_by_npc(npcs + pokemart_viewport_npcs[i].npc_idx);
        u8 oam_idx = overworld_create_oam_with_callback_by_npc(npcs + pokemart_viewport_npcs[i].npc_idx, oam_null_callback,
            (s16)(pokemart_viewport_npcs[i].x * 16 - 8), 
            (s16)(pokemart_viewport_npcs[i].y * 16 + 48 - ow->height / 2), 2);
        oam_gfx_anim_start(oams + oam_idx, (u8)pokemart_viewport_npcs[i].anim_idx);
    }
}