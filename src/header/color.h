#include "types.h"

#ifndef COLOR
#define COLOR

typedef struct rgb{
	u16 red : 5;
	u16 green : 5;
	u16 blue : 5;
	u16 unused : 1;
} rgb;

typedef union color{
	
	u16 value;
	rgb rgb;
	
}color;

color alpha_blend (color original, color overlay, u8 alpha);

#endif