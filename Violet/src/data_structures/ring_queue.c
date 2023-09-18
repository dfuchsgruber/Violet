/*
 * ring_queue.c
 *
 *  Created on: Jun 27, 2018
 *      Author: dominik
 */

#include "types.h"
#include "agbmemory.h"
#include "data_structures.h"
#include "debug.h"

bool ring_queue_new(ring_queue_t *queue, size_t max_size) {
  // Try to allocate memeory
  int *elems = malloc(sizeof(int) * max_size);
  if (!elems) return false;
  queue->max_size = max_size;
  queue->head = 0;
  queue->size = 0;
  queue->elems = elems;
  return true;
}

bool ring_queue_enqueue(ring_queue_t *queue, int element) {
  if (queue->size >= queue->max_size) return false;  // Queue is full
  queue->elems[(queue->head + (queue->size)++) % queue->max_size] = element;
  return true;
}

int ring_queue_pop(ring_queue_t *queue) {
  if (queue->size == 0) {
    ERROR("Can not pop from emtpy queue\n");
    return -1;
  }
  int element = queue->elems[queue->head];
  queue->head = (queue->head + 1) % queue->max_size;
  queue->size--;
  return element;
}

bool ring_queue_empty(const ring_queue_t *queue) {
  return queue->size == 0;
}

void ring_queue_del(ring_queue_t *queue) {
  free(queue->elems);
}
