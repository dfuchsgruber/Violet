#ifndef H_POKEMART
#define H_POKEMART

#include "types.h"

extern u16 *pokemart_bg1_tilemap;
extern u16 *pokemart_bg3_tilemap;
extern u16 *pokemart_bg2_tilemap;

typedef struct {
    u16 npc_idx;
    s16 x;
    s16 y;
    u16 anim_idx;
} pokemart_viewport_npc;

extern pokemart_viewport_npc pokemart_viewport_npcs[16];

#endif
