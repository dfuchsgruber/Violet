#include "types.h"
#include "romfuncs.h"
#include "tile.h"


u8 door_animation_0_palettes[] = {8, 8, 8, 8, 8, 8, 8, 8};
u8 door_animation_1_palettes[] = {2, 2, 2, 2, 2, 2, 2, 2};
u8 door_animation_2_palettes[] = {7, 7, 7, 7, 7, 7, 7, 7};
u8 door_animation_3_palettes[] = {10, 10, 10, 10, 10, 10, 10, 10};
u8 door_animation_4_palettes[] = {8, 8, 8, 8, 8, 8, 8, 8};

extern u32 gfx_tileset_door_anim_0Tiles[];
extern u32 gfx_tileset_door_anim_1Tiles[];
extern u32 gfx_tileset_door_anim_2Tiles[];
extern u32 gfx_tileset_door_anim_3Tiles[];
extern u32 gfx_tileset_door_anim_4Tiles[];

door_animation door_animations[] = {
    {0x2AA, 0, 0, gfx_tileset_door_anim_0Tiles, door_animation_0_palettes},
    {0x27A, 1, 0, gfx_tileset_door_anim_1Tiles, door_animation_1_palettes},
    {0x2C5, 0, 0, gfx_tileset_door_anim_2Tiles, door_animation_2_palettes},
    {0x333, 1, 0, gfx_tileset_door_anim_3Tiles, door_animation_3_palettes},
    {0x2FC, 0, 0, gfx_tileset_door_anim_4Tiles, door_animation_4_palettes},
    
    {0, 0, 0, 0, 0}
};

