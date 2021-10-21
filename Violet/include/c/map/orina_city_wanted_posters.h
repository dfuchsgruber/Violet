#ifndef H_MAP_ORINA_CITY_WANTED_POSTERS
#define H_MAP_ORINA_CITY_WANTED_POSTERS

#include "types.h"

typedef struct {
    u8 *name;
    u8 *description;
    const void *tiles;
    const void *palette;
    u16 flag;
} wanted_poster_t;

#define OAM_TAG_WANTED_POSTER 0x1363

#endif
