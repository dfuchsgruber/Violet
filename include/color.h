#include "types.h"

#ifndef COLOR
#define COLOR

typedef struct rgb {
    u16 red : 5;
    u16 green : 5;
    u16 blue : 5;
    u16 unused : 1;
} rgb;

typedef union color {
    u16 value;
    rgb rgb;

} color;

typedef struct {
    color *palette;
    u16 tag;
    u16 filler;
} pal_resource;

color alpha_blend(color original, color overlay, u8 alpha);
color color_multiply(color original, color overlay);
color blend_multiply(color original, color overlay, u8 alpha);
color greyscale(color original);

color *pal_restore = (color*) 0x020371F8;
color *pals = (color*) 0x020375F8;
color *pal_tmp = (color*) 0x02037ACC;

#endif