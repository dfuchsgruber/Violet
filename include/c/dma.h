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
 * Resets the dma0 callback
 */
void dma0_reset_callback();

#endif /* INCLUDE_C_DMA_H_ */
