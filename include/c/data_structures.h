/* 
 * File:   bin_heap.h
 * Author: Domi
 *
 * Created on 7. Juli 2016, 13:31
 */

#ifndef BIN_HEAP_H
#define	BIN_HEAP_H

#include "overworld/npc.h"

typedef struct {
    u32 key;
    int value;

} dyn_arr_node;

typedef struct {
    int size;
    int array_size;
    dyn_arr_node *array;

} dyn_arr;

dyn_arr *dyn_arr_init(int array_size);

void dyn_arr_free(dyn_arr *heap);

void dyn_arr_swap(int a, int b, dyn_arr_node *array);

void dyn_arr_resize(int size, dyn_arr *heap);

void binary_heap_decrease_key(int a, dyn_arr_node *array, u32 key_new);

void binary_heap_insert(u32 key, int priority, dyn_arr *heap);

int binary_heap_remove(int i, dyn_arr *heap);

typedef struct {
    int map_size;
    dyn_arr **buckets;
    u8 a[4];

} hashmap;

hashmap *hashmap_init(int buckets);

void hashmap_free(hashmap *map);

int hashmap_hash(u32 key, hashmap *map);

bool hashmap_contains(u32 key, hashmap *map);

void hashmap_put(u32 key, int value, hashmap *map);

int hashmap_remove(u32 key, hashmap *map);

int hashmap_get(u32 key, hashmap *map);

int a_star_compute_path(u8 *path, s16 to_x, s16 to_y, npc *original_walker);

int a_star_reconstruct(u8 *path, s16 dest_x, s16 dest_y, hashmap *nodes);

int a_star_to_key(s16 x, s16 y);

bool a_star_is_connected(s16 dest_x, s16 dest_y, s16 from_x, s16 from_y, npc *walker);

void gp_stack_init();
bool gp_stack_push(int value);
int gp_stack_peek();
int gp_stack_pop();

typedef struct {
  int *elems;
  size_t max_size;
  size_t size;
  size_t head;
} ring_queue_t;

/**
 * Initializes a ring queue with max_size integer elements
 * @param queue the queue instance to instanciate
 * @param max size capacity of the queue
 * @return whether enough memory could be allocated
 */
bool ring_queue_new(ring_queue_t *queue, size_t max_size);

/**
 * Enqueues an element at the queue's end
 * @param queue the queue
 * @param element the element to enqueue
 * @return whether the queue had the capacity
 */
bool ring_queue_enqueue(ring_queue_t *queue, int element);

/**
 * Pops an element from the queue's front
 * Throws a generic error if the queue is empty
 * @param queue the queue
 * @return the element
 */
int ring_queue_pop(ring_queue_t *queue);

/**
 * Checks if a queue is empty
 * @param queue the queue
 * @return if the queue is empty
 */
bool ring_queue_empty(ring_queue_t *queue);

/**
 * Frees the elements of a ring queue
 * @param queue the queue to delete
 */
void ring_queue_del(ring_queue_t *queue);

#endif	/* BIN_HEAP_H */

