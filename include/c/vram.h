/*
 * vram.h
 *
 *  Created on: May 1, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_VRAM_H_
#define INCLUDE_C_VRAM_H_

#include "types.h"

#define CHARBASE(x) ((void*)(0x06000000 + 0x4000 * x))
#define MAPBASE(x) ((u16*)(0x06000000 + 0x800 * x))
#define OAMCHARBASE(x) ((void*)(0x06010000 + 32 * x))

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
  // In rs each byte only holds
  u8 rs;
} bg_tile;

/**
 * Copies all graphics in the graphic queue to their destinations using the DMA
 */
void graphic_queue_proceed();

#endif /* INCLUDE_C_VRAM_H_ */
