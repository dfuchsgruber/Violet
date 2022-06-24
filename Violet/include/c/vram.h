/*
 * vram.h
 *
 *  Created on: May 1, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_VRAM_H_
#define INCLUDE_C_VRAM_H_

#include "types.h"

// Bitfield for a single bg map entry in text mode
typedef struct {
  u16 tile_number : 10;
  u16 hflip : 1;
  u16 vflip : 1;
  u16 palette : 4;
} bg_text_tile;

// Union for bg map entry either in text mode or rs mode
typedef union {
  bg_text_tile text;
  u16 text_value;
} bg_tile;

#define CHARBASE_PLUS_OFFSET(charbase, offset) ((u32*)(0x06000000 + 0x4000 * (charbase) + 32 * (offset)))
#define CHARBASE(charbase) (CHARBASE_PLUS_OFFSET(charbase, 0))
#define MAPBASE(x) ((bg_tile*)(0x06000000 + 0x800 * (x)))
#define OAMCHARBASE(x) ((u32*)(0x06010000 + 32 * (x)))

/**
 * Copies all graphics in the graphic queue to their destinations using the DMA
 */
void graphic_queue_proceed();

#endif /* INCLUDE_C_VRAM_H_ */
