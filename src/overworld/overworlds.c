/* 
 * File:   overworlds.c
 * Author: Domi
 *
 * Created on 26. Juni 2016, 21:14
 */

#include "types.h"
#include "overworld_sprites.h"
#include "gfx.h"

static graphic overworld_sprite_mskate_sprites[] = {
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
    0xFFFF, 0x1100 + 0, 0x1102, 0x200,
    32, 32, 0x10, 0x1, 0x0, 0x0,
    OW_FINAL_OAM_32_32, OW_FORMATION_32_32,
    OW_ANIM_STANDARD_NPC, overworld_sprite_mskate_sprites,
    ROTSCALE_TABLE_NULL
};

static graphic overworld_sprite_igva_sprites[] = {
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
    0xFFFF, 0x1100 + 6, 0x11FF, 0x100,
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
    0xFFFF, 0x1100 + 0x15, 0x11FF, 0x1000,
    128, 64, 0x1A, 0x0, 0x0, 0x0,
    OW_FINAL_OAM_128_64, OW_FORMATION_128_64,
    OW_ANIM_STANDARD_NPC, overworld_sprite_bbship_sprites,
    ROTSCALE_TABLE_NULL
};

static graphic overworld_sprite_mpirate_sprites [] = {
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
    0xFFFF, 0x1100 + 6, 0x11FF, 0x100,
    16, 32, 0x15, 0x1, 0x0, 0x8,
    OW_FINAL_OAM_16_32, OW_FORMATION_16_32,
    OW_ANIM_STANDARD_NPC, overworld_sprite_mpirate_sprites,
    ROTSCALE_TABLE_NULL
};

static graphic overworld_sprite_shape_animal [] = {
    {&gfx_ow_shape_animal_0Tiles, 0x100, 0},
    {&gfx_ow_shape_animal_1Tiles, 0x100, 0},
    {&gfx_ow_shape_animal_2Tiles, 0x100, 0},
    {&gfx_ow_shape_animal_0Tiles, 0x100, 0},
    {&gfx_ow_shape_animal_0Tiles, 0x100, 0},
    {&gfx_ow_shape_animal_1Tiles, 0x100, 0},
    {&gfx_ow_shape_animal_1Tiles, 0x100, 0},
    {&gfx_ow_shape_animal_2Tiles, 0x100, 0},
    {&gfx_ow_shape_animal_2Tiles, 0x100, 0}
};

overworld_sprite ow_shape_animal = {
    0xFFFF, 0x1100 + 6, 0x11FF, 0x100,
    16, 32, 0x15, 0x1, 0x0, 0x8,
    OW_FINAL_OAM_16_32, OW_FORMATION_16_32,
    OW_ANIM_STANDARD_NPC, overworld_sprite_shape_animal,
    ROTSCALE_TABLE_NULL
};

static graphic overworld_sprite_shape_human [] = {
    {&gfx_ow_shape_human_0Tiles, 0x100, 0},
    {&gfx_ow_shape_human_1Tiles, 0x100, 0},
    {&gfx_ow_shape_human_2Tiles, 0x100, 0},
    {&gfx_ow_shape_human_0Tiles, 0x100, 0},
    {&gfx_ow_shape_human_0Tiles, 0x100, 0},
    {&gfx_ow_shape_human_1Tiles, 0x100, 0},
    {&gfx_ow_shape_human_1Tiles, 0x100, 0},
    {&gfx_ow_shape_human_2Tiles, 0x100, 0},
    {&gfx_ow_shape_human_2Tiles, 0x100, 0}
};

overworld_sprite ow_shape_human = {
    0xFFFF, 0x1100 + 6, 0x11FF, 0x100,
    16, 32, 0x15, 0x1, 0x0, 0x8,
    OW_FINAL_OAM_16_32, OW_FORMATION_16_32,
    OW_ANIM_STANDARD_NPC, overworld_sprite_shape_human,
    ROTSCALE_TABLE_NULL
};

static graphic overworld_sprite_shape_tail [] = {
    {&gfx_ow_shape_tail_0Tiles, 0x100, 0},
    {&gfx_ow_shape_tail_1Tiles, 0x100, 0},
    {&gfx_ow_shape_tail_2Tiles, 0x100, 0},
    {&gfx_ow_shape_tail_0Tiles, 0x100, 0},
    {&gfx_ow_shape_tail_0Tiles, 0x100, 0},
    {&gfx_ow_shape_tail_1Tiles, 0x100, 0},
    {&gfx_ow_shape_tail_1Tiles, 0x100, 0},
    {&gfx_ow_shape_tail_2Tiles, 0x100, 0},
    {&gfx_ow_shape_tail_2Tiles, 0x100, 0}
};

overworld_sprite ow_shape_tail = {
    0xFFFF, 0x1100 + 6, 0x11FF, 0x100,
    16, 32, 0x15, 0x1, 0x0, 0x8,
    OW_FINAL_OAM_16_32, OW_FORMATION_16_32,
    OW_ANIM_STANDARD_NPC, overworld_sprite_shape_tail,
    ROTSCALE_TABLE_NULL
};

static graphic overworld_sprite_shape_snake [] = {
    {&gfx_ow_shape_snake_0Tiles, 0x100, 0},
    {&gfx_ow_shape_snake_1Tiles, 0x100, 0},
    {&gfx_ow_shape_snake_2Tiles, 0x100, 0},
    {&gfx_ow_shape_snake_0Tiles, 0x100, 0},
    {&gfx_ow_shape_snake_0Tiles, 0x100, 0},
    {&gfx_ow_shape_snake_1Tiles, 0x100, 0},
    {&gfx_ow_shape_snake_1Tiles, 0x100, 0},
    {&gfx_ow_shape_snake_2Tiles, 0x100, 0},
    {&gfx_ow_shape_snake_2Tiles, 0x100, 0}
};

overworld_sprite ow_shape_snake = {
    0xFFFF, 0x1100 + 6, 0x11FF, 0x100,
    16, 32, 0x15, 0x1, 0x0, 0x8,
    OW_FINAL_OAM_16_32, OW_FORMATION_16_32,
    OW_ANIM_STANDARD_NPC, overworld_sprite_shape_snake,
    ROTSCALE_TABLE_NULL
};

static graphic overworld_sprite_shape_winsect [] = {
    {&gfx_ow_shape_winsect_0Tiles, 0x100, 0},
    {&gfx_ow_shape_winsect_1Tiles, 0x100, 0},
    {&gfx_ow_shape_winsect_2Tiles, 0x100, 0},
    {&gfx_ow_shape_winsect_0Tiles, 0x100, 0},
    {&gfx_ow_shape_winsect_0Tiles, 0x100, 0},
    {&gfx_ow_shape_winsect_1Tiles, 0x100, 0},
    {&gfx_ow_shape_winsect_1Tiles, 0x100, 0},
    {&gfx_ow_shape_winsect_2Tiles, 0x100, 0},
    {&gfx_ow_shape_winsect_2Tiles, 0x100, 0}
};

overworld_sprite ow_shape_winsect = {
    0xFFFF, 0x1100 + 6, 0x11FF, 0x100,
    16, 32, 0x15, 0x1, 0x0, 0x8,
    OW_FINAL_OAM_16_32, OW_FORMATION_16_32,
    OW_ANIM_STANDARD_NPC, overworld_sprite_shape_winsect,
    ROTSCALE_TABLE_NULL
};

static graphic overworld_sprite_shape_winged [] = {
    {&gfx_ow_shape_winged_0Tiles, 0x100, 0},
    {&gfx_ow_shape_winged_1Tiles, 0x100, 0},
    {&gfx_ow_shape_winged_2Tiles, 0x100, 0},
    {&gfx_ow_shape_winged_0Tiles, 0x100, 0},
    {&gfx_ow_shape_winged_0Tiles, 0x100, 0},
    {&gfx_ow_shape_winged_1Tiles, 0x100, 0},
    {&gfx_ow_shape_winged_1Tiles, 0x100, 0},
    {&gfx_ow_shape_winged_2Tiles, 0x100, 0},
    {&gfx_ow_shape_winged_2Tiles, 0x100, 0}
};

overworld_sprite ow_shape_winged = {
    0xFFFF, 0x1100 + 6, 0x11FF, 0x100,
    16, 32, 0x15, 0x1, 0x0, 0x8,
    OW_FINAL_OAM_16_32, OW_FORMATION_16_32,
    OW_ANIM_STANDARD_NPC, overworld_sprite_shape_winged,
    ROTSCALE_TABLE_NULL
};

static graphic overworld_sprite_shape_insect [] = {
    {&gfx_ow_shape_insect_0Tiles, 0x100, 0},
    {&gfx_ow_shape_insect_1Tiles, 0x100, 0},
    {&gfx_ow_shape_insect_2Tiles, 0x100, 0},
    {&gfx_ow_shape_insect_0Tiles, 0x100, 0},
    {&gfx_ow_shape_insect_0Tiles, 0x100, 0},
    {&gfx_ow_shape_insect_1Tiles, 0x100, 0},
    {&gfx_ow_shape_insect_1Tiles, 0x100, 0},
    {&gfx_ow_shape_insect_2Tiles, 0x100, 0},
    {&gfx_ow_shape_insect_2Tiles, 0x100, 0}
};

overworld_sprite ow_shape_insect = {
    0xFFFF, 0x1100 + 6, 0x11FF, 0x100,
    16, 32, 0x15, 0x1, 0x0, 0x8,
    OW_FINAL_OAM_16_32, OW_FORMATION_16_32,
    OW_ANIM_STANDARD_NPC, overworld_sprite_shape_insect,
    ROTSCALE_TABLE_NULL
};

static graphic overworld_sprite_shape_head [] = {
    {&gfx_ow_shape_head_0Tiles, 0x100, 0},
    {&gfx_ow_shape_head_1Tiles, 0x100, 0},
    {&gfx_ow_shape_head_2Tiles, 0x100, 0},
    {&gfx_ow_shape_head_0Tiles, 0x100, 0},
    {&gfx_ow_shape_head_0Tiles, 0x100, 0},
    {&gfx_ow_shape_head_1Tiles, 0x100, 0},
    {&gfx_ow_shape_head_1Tiles, 0x100, 0},
    {&gfx_ow_shape_head_2Tiles, 0x100, 0},
    {&gfx_ow_shape_head_2Tiles, 0x100, 0}
};

overworld_sprite ow_shape_head = {
    0xFFFF, 0x1100 + 6, 0x11FF, 0x100,
    16, 32, 0x15, 0x1, 0x0, 0x8,
    OW_FINAL_OAM_16_32, OW_FORMATION_16_32,
    OW_ANIM_STANDARD_NPC, overworld_sprite_shape_head,
    ROTSCALE_TABLE_NULL
};

static graphic overworld_sprite_shape_arms [] = {
    {&gfx_ow_shape_arms_0Tiles, 0x100, 0},
    {&gfx_ow_shape_arms_1Tiles, 0x100, 0},
    {&gfx_ow_shape_arms_2Tiles, 0x100, 0},
    {&gfx_ow_shape_arms_0Tiles, 0x100, 0},
    {&gfx_ow_shape_arms_0Tiles, 0x100, 0},
    {&gfx_ow_shape_arms_1Tiles, 0x100, 0},
    {&gfx_ow_shape_arms_1Tiles, 0x100, 0},
    {&gfx_ow_shape_arms_2Tiles, 0x100, 0},
    {&gfx_ow_shape_arms_2Tiles, 0x100, 0}
};

overworld_sprite ow_shape_arms = {
    0xFFFF, 0x1100 + 6, 0x11FF, 0x100,
    16, 32, 0x15, 0x1, 0x0, 0x8,
    OW_FINAL_OAM_16_32, OW_FORMATION_16_32,
    OW_ANIM_STANDARD_NPC, overworld_sprite_shape_arms,
    ROTSCALE_TABLE_NULL
};

static graphic overworld_sprite_shape_legs [] = {
    {&gfx_ow_shape_legs_0Tiles, 0x100, 0},
    {&gfx_ow_shape_legs_1Tiles, 0x100, 0},
    {&gfx_ow_shape_legs_2Tiles, 0x100, 0},
    {&gfx_ow_shape_legs_0Tiles, 0x100, 0},
    {&gfx_ow_shape_legs_0Tiles, 0x100, 0},
    {&gfx_ow_shape_legs_1Tiles, 0x100, 0},
    {&gfx_ow_shape_legs_1Tiles, 0x100, 0},
    {&gfx_ow_shape_legs_2Tiles, 0x100, 0},
    {&gfx_ow_shape_legs_2Tiles, 0x100, 0}
};

overworld_sprite ow_shape_legs = {
    0xFFFF, 0x1100 + 6, 0x11FF, 0x100,
    16, 32, 0x15, 0x1, 0x0, 0x8,
    OW_FINAL_OAM_16_32, OW_FORMATION_16_32,
    OW_ANIM_STANDARD_NPC, overworld_sprite_shape_legs,
    ROTSCALE_TABLE_NULL
};

static graphic overworld_sprite_shape_tentacles [] = {
    {&gfx_ow_shape_tentacles_0Tiles, 0x100, 0},
    {&gfx_ow_shape_tentacles_1Tiles, 0x100, 0},
    {&gfx_ow_shape_tentacles_2Tiles, 0x100, 0},
    {&gfx_ow_shape_tentacles_0Tiles, 0x100, 0},
    {&gfx_ow_shape_tentacles_0Tiles, 0x100, 0},
    {&gfx_ow_shape_tentacles_1Tiles, 0x100, 0},
    {&gfx_ow_shape_tentacles_1Tiles, 0x100, 0},
    {&gfx_ow_shape_tentacles_2Tiles, 0x100, 0},
    {&gfx_ow_shape_tentacles_2Tiles, 0x100, 0}
};

overworld_sprite ow_shape_tentacles = {
    0xFFFF, 0x1100 + 6, 0x11FF, 0x100,
    16, 32, 0x15, 0x1, 0x0, 0x8,
    OW_FINAL_OAM_16_32, OW_FORMATION_16_32,
    OW_ANIM_STANDARD_NPC, overworld_sprite_shape_tentacles,
    ROTSCALE_TABLE_NULL
};

static graphic overworld_sprite_shape_fish [] = {
    {&gfx_ow_shape_fish_0Tiles, 0x100, 0},
    {&gfx_ow_shape_fish_1Tiles, 0x100, 0},
    {&gfx_ow_shape_fish_2Tiles, 0x100, 0},
    {&gfx_ow_shape_fish_0Tiles, 0x100, 0},
    {&gfx_ow_shape_fish_0Tiles, 0x100, 0},
    {&gfx_ow_shape_fish_1Tiles, 0x100, 0},
    {&gfx_ow_shape_fish_1Tiles, 0x100, 0},
    {&gfx_ow_shape_fish_2Tiles, 0x100, 0},
    {&gfx_ow_shape_fish_2Tiles, 0x100, 0}
};

overworld_sprite ow_shape_fish = {
    0xFFFF, 0x1100 + 6, 0x11FF, 0x100,
    16, 32, 0x15, 0x1, 0x0, 0x8,
    OW_FINAL_OAM_16_32, OW_FORMATION_16_32,
    OW_ANIM_STANDARD_NPC, overworld_sprite_shape_fish,
    ROTSCALE_TABLE_NULL
};

static graphic overworld_sprite_shape_ball [] = {
    {&gfx_ow_shape_ball_0Tiles, 0x100, 0},
    {&gfx_ow_shape_ball_1Tiles, 0x100, 0},
    {&gfx_ow_shape_ball_2Tiles, 0x100, 0},
    {&gfx_ow_shape_ball_0Tiles, 0x100, 0},
    {&gfx_ow_shape_ball_0Tiles, 0x100, 0},
    {&gfx_ow_shape_ball_1Tiles, 0x100, 0},
    {&gfx_ow_shape_ball_1Tiles, 0x100, 0},
    {&gfx_ow_shape_ball_2Tiles, 0x100, 0},
    {&gfx_ow_shape_ball_2Tiles, 0x100, 0}
};

overworld_sprite ow_shape_ball = {
    0xFFFF, 0x1100 + 6, 0x11FF, 0x100,
    16, 32, 0x15, 0x1, 0x0, 0x8,
    OW_FINAL_OAM_16_32, OW_FORMATION_16_32,
    OW_ANIM_STANDARD_NPC, overworld_sprite_shape_ball,
    ROTSCALE_TABLE_NULL
};

static graphic overworld_sprite_shape_multi [] = {
    {&gfx_ow_shape_multi_0Tiles, 0x100, 0},
    {&gfx_ow_shape_multi_1Tiles, 0x100, 0},
    {&gfx_ow_shape_multi_2Tiles, 0x100, 0},
    {&gfx_ow_shape_multi_0Tiles, 0x100, 0},
    {&gfx_ow_shape_multi_0Tiles, 0x100, 0},
    {&gfx_ow_shape_multi_1Tiles, 0x100, 0},
    {&gfx_ow_shape_multi_1Tiles, 0x100, 0},
    {&gfx_ow_shape_multi_2Tiles, 0x100, 0},
    {&gfx_ow_shape_multi_2Tiles, 0x100, 0}
};

overworld_sprite ow_shape_multi = {
    0xFFFF, 0x1100 + 6, 0x11FF, 0x100,
    16, 32, 0x15, 0x1, 0x0, 0x8,
    OW_FINAL_OAM_16_32, OW_FORMATION_16_32,
    OW_ANIM_STANDARD_NPC, overworld_sprite_shape_multi,
    ROTSCALE_TABLE_NULL
};

static graphic overworld_sprite_mistral [] = {
    {&gfx_ow_mistral_0Tiles, 0x100, 0},
    {&gfx_ow_mistral_1Tiles, 0x100, 0},
    {&gfx_ow_mistral_2Tiles, 0x100, 0},
    {&gfx_ow_mistral_3Tiles, 0x100, 0},
    {&gfx_ow_mistral_4Tiles, 0x100, 0},
    {&gfx_ow_mistral_5Tiles, 0x100, 0},
    {&gfx_ow_mistral_6Tiles, 0x100, 0},
    {&gfx_ow_mistral_7Tiles, 0x100, 0},
    {&gfx_ow_mistral_8Tiles, 0x100, 0}
};

overworld_sprite ow_mistral = {
    0xFFFF, 0x1100 + 6, 0x11FF, 0x100,
    16, 32, 0x15, 0x1, 0x0, 0x8,
    OW_FINAL_OAM_16_32, OW_FORMATION_16_32,
    OW_ANIM_STANDARD_NPC, overworld_sprite_mistral,
    ROTSCALE_TABLE_NULL
};

static graphic overworld_sprite_manus [] = {
    {&gfx_ow_manus_0Tiles, 0x100, 0},
    {&gfx_ow_manus_1Tiles, 0x100, 0},
    {&gfx_ow_manus_2Tiles, 0x100, 0},
    {&gfx_ow_manus_3Tiles, 0x100, 0},
    {&gfx_ow_manus_4Tiles, 0x100, 0},
    {&gfx_ow_manus_5Tiles, 0x100, 0},
    {&gfx_ow_manus_6Tiles, 0x100, 0},
    {&gfx_ow_manus_7Tiles, 0x100, 0},
    {&gfx_ow_manus_8Tiles, 0x100, 0}
};

overworld_sprite ow_manus = {
    0xFFFF, 0x1100 + 4, 0x11FF, 0x100,
    16, 32, 0x15, 0x1, 0x0, 0x8,
    OW_FINAL_OAM_16_32, OW_FORMATION_16_32,
    OW_ANIM_STANDARD_NPC, overworld_sprite_manus,
    ROTSCALE_TABLE_NULL
};

static graphic overworld_sprite_altaria [] = {
    {&gfx_ow_altaria_0Tiles, 0x200, 0},
    {&gfx_ow_altaria_0Tiles, 0x200, 0},
    {&gfx_ow_altaria_0Tiles, 0x200, 0},
    {&gfx_ow_altaria_0Tiles, 0x200, 0},
    {&gfx_ow_altaria_1Tiles, 0x200, 0},
    {&gfx_ow_altaria_0Tiles, 0x200, 0},
    {&gfx_ow_altaria_1Tiles, 0x200, 0},
    {&gfx_ow_altaria_0Tiles, 0x200, 0},
    {&gfx_ow_altaria_1Tiles, 0x200, 0}
};

overworld_sprite ow_altaria = {
    0xFFFF, 0x1100 + 6, 0x11FF, 0x200,
    32, 32, 0x15, 0x1, 0x0, 0x0,
    OW_FINAL_OAM_32_32, OW_FORMATION_32_32,
    OW_ANIM_HO_OH, overworld_sprite_altaria,
    ROTSCALE_TABLE_NULL
};

static graphic overworld_sprite_cloudrider_fem [] = {
    {&gfx_ow_cloudrider_fem_0Tiles, 0x200, 0},
    {&gfx_ow_cloudrider_fem_1Tiles, 0x200, 0},
    {&gfx_ow_cloudrider_fem_2Tiles, 0x200, 0},
    {&gfx_ow_cloudrider_fem_0Tiles, 0x200, 0},
    {&gfx_ow_cloudrider_fem_0Tiles, 0x200, 0},
    {&gfx_ow_cloudrider_fem_1Tiles, 0x200, 0},
    {&gfx_ow_cloudrider_fem_1Tiles, 0x200, 0},
    {&gfx_ow_cloudrider_fem_2Tiles, 0x200, 0},
    {&gfx_ow_cloudrider_fem_2Tiles, 0x200, 0}
};

overworld_sprite ow_cloudrider_fem = {
    0xFFFF, 0x1100 + 6, 0x11FF, 0x200,
    32, 32, 0x15, 0x1, 0x0, 0x0,
    OW_FINAL_OAM_32_32, OW_FORMATION_32_32,
    OW_ANIM_STANDARD_NPC, overworld_sprite_cloudrider_fem,
    ROTSCALE_TABLE_NULL
};

static graphic overworld_sprite_cloudrider_male [] = {
    {&gfx_ow_cloudrider_male_0Tiles, 0x200, 0},
    {&gfx_ow_cloudrider_male_1Tiles, 0x200, 0},
    {&gfx_ow_cloudrider_male_2Tiles, 0x200, 0},
    {&gfx_ow_cloudrider_male_0Tiles, 0x200, 0},
    {&gfx_ow_cloudrider_male_0Tiles, 0x200, 0},
    {&gfx_ow_cloudrider_male_1Tiles, 0x200, 0},
    {&gfx_ow_cloudrider_male_1Tiles, 0x200, 0},
    {&gfx_ow_cloudrider_male_2Tiles, 0x200, 0},
    {&gfx_ow_cloudrider_male_2Tiles, 0x200, 0}
};

overworld_sprite ow_cloudrider_male = {
    0xFFFF, 0x1100 + 6, 0x11FF, 0x200,
    32, 32, 0x15, 0x1, 0x0, 0x0,
    OW_FINAL_OAM_32_32, OW_FORMATION_32_32,
    OW_ANIM_STANDARD_NPC, overworld_sprite_cloudrider_male,
    ROTSCALE_TABLE_NULL
};

static graphic overworld_sprite_moltres [] = {
    {&gfx_ow_moltres_0Tiles, 0x800, 0},
    {&gfx_ow_moltres_0Tiles, 0x800, 0},
    {&gfx_ow_moltres_0Tiles, 0x800, 0},
    {&gfx_ow_moltres_0Tiles, 0x800, 0},
    {&gfx_ow_moltres_1Tiles, 0x800, 0},
    {&gfx_ow_moltres_0Tiles, 0x800, 0},
    {&gfx_ow_moltres_1Tiles, 0x800, 0},
    {&gfx_ow_moltres_0Tiles, 0x800, 0},
    {&gfx_ow_moltres_1Tiles, 0x800, 0}
};

overworld_sprite ow_moltres = {
    0xFFFF, 0x1100 + 3, 0x11FF, 0x800,
    64, 64, 0x12, 0x1, 0x0, 0,
    OW_FINAL_OAM_64_64, OW_FORMATION_64_64,
    OW_ANIM_STANDARD_NPC, overworld_sprite_moltres,
    ROTSCALE_TABLE_NULL
};

static graphic overworld_sprites_diserakt [] = {
    {&gfx_ow_diserakt_0Tiles, 0x100, 0},
    {&gfx_ow_diserakt_2Tiles, 0x100, 0},
    {&gfx_ow_diserakt_1Tiles, 0x100, 0},
    {&gfx_ow_diserakt_0Tiles, 0x100, 0},
    {&gfx_ow_diserakt_0Tiles, 0x100, 0},
    {&gfx_ow_diserakt_2Tiles, 0x100, 0},
    {&gfx_ow_diserakt_2Tiles, 0x100, 0},
    {&gfx_ow_diserakt_1Tiles, 0x100, 0},
    {&gfx_ow_diserakt_1Tiles, 0x100, 0},
};

overworld_sprite ow_diserakt = {
    0xFFFF, 0x1100 + 4, 0x11FF, 0x100,
    16, 32, 0x13, 0x1, 0x0, 0x0,
    OW_FINAL_OAM_16_32, OW_FORMATION_16_32,
    OW_ANIM_STANDARD_NPC, overworld_sprites_diserakt,
    ROTSCALE_TABLE_NULL
};

static graphic overworld_sprite_groudon [] = {
    {&gfx_ow_groudon_0Tiles, 0x800, 0},
    {&gfx_ow_groudon_0Tiles, 0x800, 0},
    {&gfx_ow_groudon_0Tiles, 0x800, 0},
    {&gfx_ow_groudon_1Tiles, 0x800, 0},
    {&gfx_ow_groudon_2Tiles, 0x800, 0},
    {&gfx_ow_groudon_1Tiles, 0x800, 0},
    {&gfx_ow_groudon_2Tiles, 0x800, 0},
    {&gfx_ow_groudon_1Tiles, 0x800, 0},
    {&gfx_ow_groudon_2Tiles, 0x800, 0}
};

overworld_sprite ow_groudon = {
    0xFFFF, 0x1100 + 3, 0x11FF, 0x800,
    64, 64, 0x12, 0x1, 0x0, 0,
    OW_FINAL_OAM_64_64, OW_FORMATION_64_64,
    OW_ANIM_STANDARD_NPC, overworld_sprite_groudon,
    ROTSCALE_TABLE_NULL
};

static graphic overworld_sprite_rubys [] = {
    {&gfx_ow_rubys_0Tiles, 0x100, 0},
    {&gfx_ow_rubys_1Tiles, 0x100, 0},
    {&gfx_ow_rubys_2Tiles, 0x100, 0},
    {&gfx_ow_rubys_3Tiles, 0x100, 0},
    {&gfx_ow_rubys_4Tiles, 0x100, 0},
    {&gfx_ow_rubys_5Tiles, 0x100, 0},
    {&gfx_ow_rubys_6Tiles, 0x100, 0},
    {&gfx_ow_rubys_7Tiles, 0x100, 0},
    {&gfx_ow_rubys_8Tiles, 0x100, 0}
};

overworld_sprite ow_rubys = {
    0xFFFF, 0x1100 + 6, 0x11FF, 0x100,
    16, 32, 0x15, 0x1, 0x0, 0x8,
    OW_FINAL_OAM_16_32, OW_FORMATION_16_32,
    OW_ANIM_STANDARD_NPC, overworld_sprite_rubys,
    ROTSCALE_TABLE_NULL
};
