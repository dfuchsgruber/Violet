#ifndef H_MAP_BLUETENBACH_GYM
#define H_MAP_BLUETENBACH_GYM

#include "types.h"
#include "map/footer.h"

#define BLUTENBACH_GYM_ROTATING_WALL_TAG 0x88B
#define BLUETENBACH_GYM_BANK 8
#define BLUETENBACH_GYM_MAP_IDX 12

extern const u8 gfx_tileset_bluetenbach_gym_rotating_wallsTiles[];
extern const u8 gfx_tileset_bluetenbach_gym_rotating_wallsPal[];

typedef struct  {
    map_footer_t *footer;
    s16 x;
    s16 y;
} bluetenbach_gym_rotating_wall_t;

#endif