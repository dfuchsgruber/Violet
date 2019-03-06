/*
 * dma.h
 *
 *  Created on: May 12, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_DMA_H_
#define INCLUDE_C_DMA_H_

/**
 * Resets the dma3 controller
 */
void dma3_controller_reset();

/**
 * Copies all elements in the DMA3 queue using the DMA3
 */
void dma3_queue_proceed();

/**
 * Adds an element to the DMA3 copy queue
 * @param src the source
 * @param dst the destination
 * @param size the size
 */
void dma3_queue_add(void *src, void *dst, u16 size);

/**
 * Proceeds the state of the dma0
 */
void dma0_proceed();

/**
 * Resets the dma0 callback
 */
void dma0_reset_callback();


// For each line on the screen (possibly up to 540 = 2 * 240) there is room for one word
// (or 2 * 540 = 1080 hwords)
// cast to another type for setting i.e. ioregs
// usually the first hword / word is a default value
u16 dma0_scanline_frames[2][480 * 2];

typedef union {
	struct {
		u8 flipflop_cntrl;
		u8 defaults_field_16_17;
	} bytes;
	int int_value;
} dma0_scanline_flipflop_t;

#define DMA_ENABLE (1 << 31)
#define DMA_INTERRUPT_REQ (1 << 30)
#define DMA_TIMING_IMMIDIATLY (0 << 28)
#define DMA_TIMING_VBLANK (1 << 28)
#define DMA_TIMING_HBLANK (2 << 28)
#define DMA_TIMING_SPECIAL (3 << 28)
#define DMA_DRQ_FROM_GAME_PAK (1 << 27)
#define DMA_TRANSFER_TYPE_HWORD (0 << 26)
#define DMA_TRANSFER_TYPE_WORD (1 << 26)
#define DMA_REPEAT (1 << 25)
#define DMA_SRC_INCREMENT (0 << 23)
#define DMA_SRC_DECREMENT (1 << 23)
#define DMA_SRC_FIXED (2 << 23)
#define DMA_DST_INCREMENT (0 << 21)
#define DMA_DST_DECREMENT (1 << 21)
#define DMA_DST_FIXED (2 << 21)
#define DMA_DST_RELOAD (3 << 21)
#define DMA_SIZE(x) (x)

void dma0_init_scanline (void *dst, int dma0_cntrl, dma0_scanline_flipflop_t flipflop);

#endif /* INCLUDE_C_DMA_H_ */
