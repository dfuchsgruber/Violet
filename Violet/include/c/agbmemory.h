/*
 * memory.h
 *
 *  Created on: May 1, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_AGBMEMORY_H_
#define INCLUDE_C_AGBMEMORY_H_

/**
 * Initializes the allocation heap
 * @param start start of the heap memory
 * @param size size of the heap memory
 */
void malloc_init(void *start, u32 size);

/**
 * Allocates heap memory.
 * @param Size of memory to allocate
 * @return Pointer to allocated memory
 */
void *malloc(size_t);

/**
 * Frees allocated heap memory.
 * @param ptr Memory that was allocated on heap
 */
void free(void* ptr);

/**
 * Allocates heap memory and fills it with zeroes.
 * @param size Size of memory to allocate
 * @return Pointer to allocated memory
 */
void* malloc_and_clear(size_t size);

/**
 * Memory copy.
 * @param Destination
 * @param Source
 * @param Size
 */
void *memcpy(void*, const void*, size_t);

/**
 * Memory set.
 * @param Destination
 * @param value
 * @param Size
 */
void *memset(void*, int, size_t);

#endif /* INCLUDE_C_AGBMEMORY_H_ */
