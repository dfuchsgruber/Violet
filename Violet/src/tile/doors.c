#include "types.h"
#include "tile/door_animation.h"


static u8 door_animation_0_palettes[] = {8, 8, 8, 8, 8, 8, 8, 8};
static u8 door_animation_1_palettes[] = {2, 2, 2, 2, 2, 2, 2, 2};
static u8 door_animation_2_palettes[] = {7, 7, 7, 7, 7, 7, 7, 7};
static u8 door_animation_3_palettes[] = {10, 10, 10, 10, 10, 10, 10, 10};
static u8 door_animation_4_palettes[] = {8, 8, 8, 8, 8, 8, 8, 8};
static u8 door_animation_5_palettes[] = {8, 8, 8, 8, 8, 8, 8, 8};
static u8 door_animation_6_palettes[] = {8, 8, 8, 8, 8, 8, 8, 8};
static u8 door_animation_7_palettes[] = {11, 11, 11, 11, 11, 11, 11, 11};
static u8 door_animation_8_palettes[] = {7, 7, 7, 7, 7, 7, 7, 7};
static u8 door_animation_9_palettes[] = {8, 8, 8, 8, 8, 8, 8, 8};
static u8 door_animation_10_palettes[] = {7, 7, 7, 7, 7, 7, 7, 7};
static u8 door_animation_11_palettes[] = {9, 9, 9, 9, 9, 9, 9, 9};
static u8 door_animation_12_palettes[] = {8, 8, 8, 8, 8, 8, 8, 8};
static u8 door_animation_13_palettes[] = {10, 10, 10, 10, 10, 10, 10, 10};
static u8 door_animation_haweiland_palettes[] = {10, 10, 10, 10, 10, 10, 10, 10};
static u8 door_animation_blackbeard_ship_palettes[] = {7, 7, 7, 7, 7, 7, 7, 7};
static u8 door_animation_meriana_city_palettes[] = {7, 7, 7, 7, 7, 7, 7, 7};
static u8 door_animation_route_4_palettes[] = {12, 12, 12, 12, 12, 12, 12, 12};
static u8 door_animation_sonnaufeld_palettes[] = {7, 7, 7, 7, 7, 7, 7, 7};

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
extern u32 gfx_tileset_door_anim_12Tiles[];
extern u32 gfx_tileset_door_anim_13Tiles[];
extern u32 gfx_tileset_haweiland_door_animTiles[];
extern u32 gfx_maptileset_blackbeard_ship_door_animTiles[];
extern u32 gfx_maptileset_meriana_city_doorTiles[];
extern u32 gfx_tileset_door_anim_sonnaufeldTiles[];

door_animation door_animations[] = {
    {0x2AA, 0, 0, gfx_tileset_door_anim_0Tiles, door_animation_0_palettes},
    {0x27A, 1, 0, gfx_tileset_door_anim_1Tiles, door_animation_1_palettes},
    {0x2C5, 0, 0, gfx_tileset_door_anim_2Tiles, door_animation_2_palettes},
    {0x333, 1, 0, gfx_tileset_door_anim_3Tiles, door_animation_3_palettes},
    {0x314, 0, 0, gfx_tileset_door_anim_4Tiles, door_animation_4_palettes},
    {0x305, 0, 0, gfx_tileset_door_anim_5Tiles, door_animation_5_palettes},
    {0x2c9, 0, 0, gfx_tileset_door_anim_6Tiles, door_animation_6_palettes},
    {0x2c1, 0, 0, gfx_tileset_door_anim_7Tiles, door_animation_7_palettes},
    {0x2b2, 0, 0, gfx_tileset_door_anim_8Tiles, door_animation_8_palettes},
    {0x36a, 1, 0, gfx_tileset_door_anim_9Tiles, door_animation_9_palettes},
    {0x291, 1, 0, gfx_tileset_door_anim_10Tiles, door_animation_10_palettes},
    {0x2D9, 0, 0, gfx_tileset_door_anim_11Tiles, door_animation_11_palettes},
    {0x2DD, 0, 0, gfx_tileset_door_anim_12Tiles, door_animation_12_palettes},
    {0x34B, 0, 0, gfx_tileset_door_anim_13Tiles, door_animation_13_palettes},
    {.block = 0x2F2, .type = DOOR_ANIM_TYPE_STANDARD, .double_tiled = false, .gfx = gfx_tileset_haweiland_door_animTiles, .palette_map = door_animation_haweiland_palettes},
    {.block = 0x2ca, .type = DOOR_ANIM_TYPE_STANDARD, .double_tiled = false, .gfx = gfx_maptileset_blackbeard_ship_door_animTiles, .palette_map = door_animation_blackbeard_ship_palettes},
    {.block = 0x36b, .type = DOOR_ANIM_TYPE_STANDARD, .double_tiled = false, .gfx = gfx_maptileset_meriana_city_doorTiles, .palette_map = door_animation_meriana_city_palettes},
    {0x19e, 0, 0, gfx_tileset_door_anim_13Tiles, door_animation_route_4_palettes}, // same as ceometria, i am just recycling the house basically...
    {.block = 0x3b9, .type = DOOR_ANIM_TYPE_STANDARD, .double_tiled = false, .gfx = gfx_tileset_door_anim_sonnaufeldTiles, .palette_map = door_animation_sonnaufeld_palettes},
    {0, 0, 0, 0, 0},
};

