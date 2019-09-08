#ifndef H_ITEM_ENIGMA_BERRY
#define H_ITEM_ENIGMA_BERRY

#include "types.h"

typedef struct {
    u8 name[7];
    u8 firmness;
    u16 size;
    u8 max_yield;
    u8 min_yield;
    u8 *description1;
    u8 *description2;
    u8 stage_duration;
    u8 spicy;
    u8 dry;
    u8 sweet;
    u8 bitter;
    u8 sour;
    u8 smoothness;
    u8 item_effect[18];
    u8 hold_effect;
    u8 hold_effect_parameter;
    u32 checksum;
} engima_berry_t;


#endif