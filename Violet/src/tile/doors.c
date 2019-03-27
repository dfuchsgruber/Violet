#include "types.h"
#include "tile/door_animation.h"


u8 door_animation_0_palettes[] = {8, 8, 8, 8, 8, 8, 8, 8};
u8 door_animation_1_palettes[] = {2, 2, 2, 2, 2, 2, 2, 2};
u8 door_animation_2_palettes[] = {7, 7, 7, 7, 7, 7, 7, 7};
u8 door_animation_3_palettes[] = {10, 10, 10, 10, 10, 10, 10, 10};
u8 door_animation_4_palettes[] = {8, 8, 8, 8, 8, 8, 8, 8};
u8 door_animation_5_palettes[] = {8, 8, 8, 8, 8, 8, 8, 8};
u8 door_animation_6_palettes[] = {8, 8, 8, 8, 8, 8, 8, 8};
u8 door_animation_7_palettes[] = {11, 11, 11, 11, 11, 11, 11, 11};
u8 door_animation_8_palettes[] = {7, 7, 7, 7, 7, 7, 7, 7};
u8 door_animation_9_palettes[] = {8, 8, 8, 8, 8, 8, 8, 8};
u8 door_animation_10_palettes[] = {7, 7, 7, 7, 7, 7, 7, 7};
u8 door_animation_11_palettes[] = {9, 9, 9, 9, 9, 9, 9, 9};

extern u32 gfx_tileset_door_anim_0Tiles[];
extern u32 gfx_tileset_door_anim_1Tiles[];
extern u32 gfx_tileset_door_anim_2Tiles[];
extern u32 gfx_tileset_door_anim_3Tiles[];
extern u32 gfx_tileset_door_anim_4Tiles[];
extern u32 gfx_tileset_door_anim_5Tiles[];
extern u32 gfx_tileset_door_anim_6Tiles[];
extern u32 gfx_tileset_door_anim_7Tiles[];
extern u32 gfx_tileset_door_anim_8Tiles[];
extern u32 gfx_tileset_door_anim_9Tiles[];
extern u32 gfx_tileset_door_anim_10Tiles[];
extern u32 gfx_tileset_door_anim_11Tiles[];

door_animation door_animations[] = {
    {0x2AA, 0, 0, gfx_tileset_door_anim_0Tiles, door_animation_0_palettes},
    {0x27A, 1, 0, gfx_tileset_door_anim_1Tiles, door_animation_1_palettes},
    {0x2C5, 0, 0, gfx_tileset_door_anim_2Tiles, door_animation_2_palettes},
    {0x333, 1, 0, gfx_tileset_door_anim_3Tiles, door_animation_3_palettes},
    {0x2FC, 0, 0, gfx_tileset_door_anim_4Tiles, door_animation_4_palettes},
    {0x305, 0, 0, gfx_tileset_door_anim_5Tiles, door_animation_5_palettes},
    {0x2c9, 0, 0, gfx_tileset_door_anim_6Tiles, door_animation_6_palettes},
    {0x2c1, 0, 0, gfx_tileset_door_anim_7Tiles, door_animation_7_palettes},
    {0x2b2, 0, 0, gfx_tileset_door_anim_8Tiles, door_animation_8_palettes},
    {0x36a, 1, 0, gfx_tileset_door_anim_9Tiles, door_animation_9_palettes},
    {0x291, 1, 0, gfx_tileset_door_anim_10Tiles, door_animation_10_palettes},
    {0x2D9, 0, 0, gfx_tileset_door_anim_11Tiles, door_animation_11_palettes},
    {0, 0, 0, 0, 0}
};

