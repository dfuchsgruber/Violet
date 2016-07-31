/* 
 * File:   overworlds.c
 * Author: Domi
 *
 * Created on 26. Juni 2016, 21:14
 */

#include "types.h"
#include "overworld_sprites.h"
#include "gfx.h"

static graphic overworld_sprite_mskate_sprites[]= {
    {&gfx_pskate_0Tiles, 0x200, 0},
    {&gfx_pskate_1Tiles, 0x200, 0},
    {&gfx_pskate_2Tiles, 0x200, 0},
    {&gfx_pskate_3Tiles, 0x200, 0},
    {&gfx_pskate_4Tiles, 0x200, 0},
    {&gfx_pskate_5Tiles, 0x200, 0},
    {&gfx_pskate_6Tiles, 0x200, 0},
    {&gfx_pskate_7Tiles, 0x200, 0},
    {&gfx_pskate_8Tiles, 0x200, 0}
};

overworld_sprite ow_mskate = {
    0xFFFF, 0x1100+0, 0x1102, 0x200,
    32, 32, 0x10, 0x1, 0x0, 0x0,
    OW_FINAL_OAM_32_32, OW_FORMATION_32_32,
    OW_ANIM_STANDARD_NPC, overworld_sprite_mskate_sprites,
    ROTSCALE_TABLE_NULL
};

static graphic overworld_sprite_igva_sprites[]= {
    {&gfx_ow_igva_0Tiles, 0x100, 0},
    {&gfx_ow_igva_1Tiles, 0x100, 0},
    {&gfx_ow_igva_2Tiles, 0x100, 0},
    {&gfx_ow_igva_3Tiles, 0x100, 0},
    {&gfx_ow_igva_4Tiles, 0x100, 0},
    {&gfx_ow_igva_5Tiles, 0x100, 0},
    {&gfx_ow_igva_6Tiles, 0x100, 0},
    {&gfx_ow_igva_7Tiles, 0x100, 0},
    {&gfx_ow_igva_8Tiles, 0x100, 0}
};

overworld_sprite ow_igva = {
    0xFFFF, 0x1100+6, 0x11FF, 0x100,
    16, 32, 0x15, 0x1, 0x0, 0x8,
    OW_FINAL_OAM_16_32, OW_FORMATION_16_32,
    OW_ANIM_STANDARD_NPC, overworld_sprite_igva_sprites,
    ROTSCALE_TABLE_NULL
};

static graphic overworld_sprite_bbship_sprites[] = {
    {&gfx_ow_bbshipTiles, 0x1000, 0},
    {&gfx_ow_bbshipTiles, 0x1000, 0},
    {&gfx_ow_bbshipTiles, 0x1000, 0},
    {&gfx_ow_bbshipTiles, 0x1000, 0},
    {&gfx_ow_bbshipTiles, 0x1000, 0},
    {&gfx_ow_bbshipTiles, 0x1000, 0},
    {&gfx_ow_bbshipTiles, 0x1000, 0},
    {&gfx_ow_bbshipTiles, 0x1000, 0},
    {&gfx_ow_bbshipTiles, 0x1000, 0}
};

overworld_sprite ow_bbship = {
    0xFFFF, 0x1100+0x15, 0x11FF, 0x1000,
    128, 64, 0x1A, 0x0, 0x0, 0x0,
    OW_FINAL_OAM_128_64, OW_FORMATION_128_64,
    OW_ANIM_STANDARD_NPC, overworld_sprite_bbship_sprites,
    ROTSCALE_TABLE_NULL
};

static graphic overworld_sprite_mpirate_sprites []={
    {&gfx_ow_mpirate_0Tiles, 0x100, 0},
    {&gfx_ow_mpirate_1Tiles, 0x100, 0},
    {&gfx_ow_mpirate_2Tiles, 0x100, 0},
    {&gfx_ow_mpirate_3Tiles, 0x100, 0},
    {&gfx_ow_mpirate_4Tiles, 0x100, 0},
    {&gfx_ow_mpirate_5Tiles, 0x100, 0},
    {&gfx_ow_mpirate_6Tiles, 0x100, 0},
    {&gfx_ow_mpirate_7Tiles, 0x100, 0},
    {&gfx_ow_mpirate_8Tiles, 0x100, 0}
};

overworld_sprite ow_mpirate = {
    0xFFFF, 0x1100+6, 0x11FF, 0x100,
    16, 32, 0x15, 0x1, 0x0, 0x8,
    OW_FINAL_OAM_16_32, OW_FORMATION_16_32,
    OW_ANIM_STANDARD_NPC, overworld_sprite_mpirate_sprites,
    ROTSCALE_TABLE_NULL
};

