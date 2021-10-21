/*
 * dma.h
 *
 *  Created on: May 12, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_DMA_H_
#define INCLUDE_C_DMA_H_

#include "io.h"
#include "types.h"

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
 * Checks if the dma3 is busy copying stuff (probably into vram).
 * @param idx if to wait for any specific request. if -1 is passed, we wait for any request
 * @return if the dma3 is busy
 */
bool dma3_busy(s16 idx);

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

#define DMA_SET(num, src, dest, count, control)              \
    {                                                        \
        vu32 *io_regs = (vu32 *)IO_DMA_REGS(num);            \
        io_regs[0] = (vu32)(src);                            \
        io_regs[1] = (vu32)(dest);                           \
        io_regs[2] = (vu32)(DMA_SIZE(count) | (u32)control); \
        io_regs[2];                                          \
    }

#define DMA_COPY(num, src, dest, size, bit) \
    DMA_SET(num,                            \
            src,                            \
            dest,                           \
            (size) / (bit / 8),             \
            (DMA_ENABLE | DMA_TIMING_IMMIDIATLY | DMA_TRANSFER_TYPE_##bit##_BIT | DMA_SRC_INCREMENT | DMA_DST_INCREMENT))

#define DMA_COPY_16(num, src, dest, size) DMA_COPY(num, src, dest, size, 16)
#define DMA_COPY_32(num, src, dest, size) DMA_COPY(num, src, dest, size, 32)

#define DMA_ENABLE (1 << 31)
#define DMA_INTERRUPT_REQ (1 << 30)
#define DMA_TIMING_IMMIDIATLY (0 << 28)
#define DMA_TIMING_VBLANK (1 << 28)
#define DMA_TIMING_HBLANK (2 << 28)
#define DMA_TIMING_SPECIAL (3 << 28)
#define DMA_DRQ_FROM_GAME_PAK (1 << 27)
#define DMA_TRANSFER_TYPE_16_BIT (0 << 26)
#define DMA_TRANSFER_TYPE_32_BIT (1 << 26)
#define DMA_REPEAT (1 << 25)
#define DMA_SRC_INCREMENT (0 << 23)
#define DMA_SRC_DECREMENT (1 << 23)
#define DMA_SRC_FIXED (2 << 23)
#define DMA_DST_INCREMENT (0 << 21)
#define DMA_DST_DECREMENT (1 << 21)
#define DMA_DST_FIXED (2 << 21)
#define DMA_DST_RELOAD (3 << 21)
#define DMA_SIZE(x) (x)

void dma0_init_scanline(void *dst, int dma0_cntrl, dma0_scanline_flipflop_t flipflop);

#endif /* INCLUDE_C_DMA_H_ */
