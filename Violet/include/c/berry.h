#ifndef H_BERRY
#define H_BERRY

#include "types.h"

typedef struct {
    u8 berry;
    u8 stage : 7;
    u8 growth_sparkle : 1; // Unused in Violet
    u16 timer;
    u8 yield;
    u8 regrowth_count : 4; // Unused in Violet
    u8 watered1 : 1;
    u8 watered2 : 1;
    u8 watered3 : 1;
    u8 watered4 : 1;
    u8 field_6;
    u8 field_7;
} berry_tree;

typedef struct { // From pokeemerald
    /*0x00*/ u8 name[7];
    /*0x07*/ u8 firmness;
    /*0x08*/ u16 size;
    /*0x0A*/ u8 max_yield;
    /*0x0B*/ u8 min_yield;
    /*0x0C*/ const u8 *description1;
    /*0x10*/ const u8 *description2;
    /*0x14*/ u8 stage_duration;
    /*0x15*/ u8 spicy;
    /*0x16*/ u8 dry;
    /*0x17*/ u8 sweet;
    /*0x18*/ u8 bitter;
    /*0x19*/ u8 sour;
    /*0x1A*/ u8 smoothness;
} berry;

extern berry berries[];

#endif