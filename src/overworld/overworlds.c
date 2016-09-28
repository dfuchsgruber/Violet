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

static graphic overworld_sprite_shape_animal []={
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
    0xFFFF, 0x1100+6, 0x11FF, 0x100,
    16, 32, 0x15, 0x1, 0x0, 0x8,
    OW_FINAL_OAM_16_32, OW_FORMATION_16_32,
    OW_ANIM_STANDARD_NPC, overworld_sprite_shape_animal,
    ROTSCALE_TABLE_NULL
};

static graphic overworld_sprite_shape_human []={
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
    0xFFFF, 0x1100+6, 0x11FF, 0x100,
    16, 32, 0x15, 0x1, 0x0, 0x8,
    OW_FINAL_OAM_16_32, OW_FORMATION_16_32,
    OW_ANIM_STANDARD_NPC, overworld_sprite_shape_human,
    ROTSCALE_TABLE_NULL
};

static graphic overworld_sprite_shape_tail []={
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
    0xFFFF, 0x1100+6, 0x11FF, 0x100,
    16, 32, 0x15, 0x1, 0x0, 0x8,
    OW_FINAL_OAM_16_32, OW_FORMATION_16_32,
    OW_ANIM_STANDARD_NPC, overworld_sprite_shape_tail,
    ROTSCALE_TABLE_NULL
};

static graphic overworld_sprite_shape_snake []={
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
    0xFFFF, 0x1100+6, 0x11FF, 0x100,
    16, 32, 0x15, 0x1, 0x0, 0x8,
    OW_FINAL_OAM_16_32, OW_FORMATION_16_32,
    OW_ANIM_STANDARD_NPC, overworld_sprite_shape_snake,
    ROTSCALE_TABLE_NULL
};

static graphic overworld_sprite_shape_winsect []={
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
    0xFFFF, 0x1100+6, 0x11FF, 0x100,
    16, 32, 0x15, 0x1, 0x0, 0x8,
    OW_FINAL_OAM_16_32, OW_FORMATION_16_32,
    OW_ANIM_STANDARD_NPC, overworld_sprite_shape_winsect,
    ROTSCALE_TABLE_NULL
};

static graphic overworld_sprite_shape_winged []={
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
    0xFFFF, 0x1100+6, 0x11FF, 0x100,
    16, 32, 0x15, 0x1, 0x0, 0x8,
    OW_FINAL_OAM_16_32, OW_FORMATION_16_32,
    OW_ANIM_STANDARD_NPC, overworld_sprite_shape_winged,
    ROTSCALE_TABLE_NULL
};

static graphic overworld_sprite_shape_insect []={
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
    0xFFFF, 0x1100+6, 0x11FF, 0x100,
    16, 32, 0x15, 0x1, 0x0, 0x8,
    OW_FINAL_OAM_16_32, OW_FORMATION_16_32,
    OW_ANIM_STANDARD_NPC, overworld_sprite_shape_insect,
    ROTSCALE_TABLE_NULL
};

static graphic overworld_sprite_shape_head []={
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
    0xFFFF, 0x1100+6, 0x11FF, 0x100,
    16, 32, 0x15, 0x1, 0x0, 0x8,
    OW_FINAL_OAM_16_32, OW_FORMATION_16_32,
    OW_ANIM_STANDARD_NPC, overworld_sprite_shape_head,
    ROTSCALE_TABLE_NULL
};

static graphic overworld_sprite_shape_arms []={
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
    0xFFFF, 0x1100+6, 0x11FF, 0x100,
    16, 32, 0x15, 0x1, 0x0, 0x8,
    OW_FINAL_OAM_16_32, OW_FORMATION_16_32,
    OW_ANIM_STANDARD_NPC, overworld_sprite_shape_arms,
    ROTSCALE_TABLE_NULL
};

static graphic overworld_sprite_shape_legs []={
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
    0xFFFF, 0x1100+6, 0x11FF, 0x100,
    16, 32, 0x15, 0x1, 0x0, 0x8,
    OW_FINAL_OAM_16_32, OW_FORMATION_16_32,
    OW_ANIM_STANDARD_NPC, overworld_sprite_shape_legs,
    ROTSCALE_TABLE_NULL
};

static graphic overworld_sprite_shape_tentacles []={
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
    0xFFFF, 0x1100+6, 0x11FF, 0x100,
    16, 32, 0x15, 0x1, 0x0, 0x8,
    OW_FINAL_OAM_16_32, OW_FORMATION_16_32,
    OW_ANIM_STANDARD_NPC, overworld_sprite_shape_tentacles,
    ROTSCALE_TABLE_NULL
};

static graphic overworld_sprite_shape_fish []={
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
    0xFFFF, 0x1100+6, 0x11FF, 0x100,
    16, 32, 0x15, 0x1, 0x0, 0x8,
    OW_FINAL_OAM_16_32, OW_FORMATION_16_32,
    OW_ANIM_STANDARD_NPC, overworld_sprite_shape_fish,
    ROTSCALE_TABLE_NULL
};

static graphic overworld_sprite_shape_ball []={
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
    0xFFFF, 0x1100+6, 0x11FF, 0x100,
    16, 32, 0x15, 0x1, 0x0, 0x8,
    OW_FINAL_OAM_16_32, OW_FORMATION_16_32,
    OW_ANIM_STANDARD_NPC, overworld_sprite_shape_ball,
    ROTSCALE_TABLE_NULL
};

static graphic overworld_sprite_shape_multi []={
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
    0xFFFF, 0x1100+6, 0x11FF, 0x100,
    16, 32, 0x15, 0x1, 0x0, 0x8,
    OW_FINAL_OAM_16_32, OW_FORMATION_16_32,
    OW_ANIM_STANDARD_NPC, overworld_sprite_shape_multi,
    ROTSCALE_TABLE_NULL
};