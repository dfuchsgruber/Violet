#ifndef H_MAP_BLUETENBACH_GYM
#define H_MAP_BLUETENBACH_GYM

#include "types.h"

#define BLUTENBACH_GYM_ROTATING_WALL_TAG 0x88B
#define BLUETENBACH_GYM_BANK 8
#define BLUETENBACH_GYM_MAP_IDX 12

extern const u8 gfx_tileset_bluetenbach_gym_rotating_wallsTiles[];
extern const u8 gfx_tileset_bluetenbach_gym_rotating_wallsPal[];

typedef struct {
    s16 anchor_x;
    s16 anchor_y;
    u8 is_l_shape;
    u8 rotation;
} bluetenbach_gym_rotating_wall_t;

#endif