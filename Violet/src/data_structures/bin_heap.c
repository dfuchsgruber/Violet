/* 
 * File:   bin_heap.c
 * Author: Domi
 *
 * Created on 7. Juli 2016, 13:31
 */

#include "agbmemory.h"
#include "data_structures.h"
#include "stdbool.h"
#include "types.h"

/**
 * Restores heap invariance of heap at root position (sift downn)
 * @param a
 * @param heap
 */
void binary_heap_heapify(int a, dyn_arr *heap) {
    int i = a;
    do {
        int min = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < heap->size && heap->array[left].key < heap->array[min].key)
            min = left;
        if (right < heap->size && heap->array[right].key < heap->array[min].key)
            min = right;
        if (min == i)
            break;
        dyn_arr_swap(i, min, heap->array);
        i = min;
    } while (true);
}

/**
 * Decreases a key for a node in the heap
 * @param a position in heap
 * @param array 
 * @param key_new
 */
void binary_heap_decrease_key(int a, dyn_arr_node *array, u32 key_new) {
    int i = a;
    if (key_new <= array[i].key) {
        array[i].key = key_new;
        //Now we push the key upwards
        while (i && array[i].key < array[(i - 1) / 2].key) {
            dyn_arr_swap(i, (i - 1) / 2, array);
            i = (i - 1) / 2;
        }
    }
}

/**
 * Inserts a new node in the heap
 * @param key
 * @param value
 * @param heap
 * @return the index in the heap (may change after other operations on heap)
 */
void binary_heap_insert(u32 key, int value, dyn_arr *heap) {
    int i = heap->size;
    dyn_arr_resize(i + 1, heap);
    heap->array[i].key = key;
    heap->array[i].value = value;
    binary_heap_decrease_key(i, heap->array, key);
}

/**
 * Removes a node from the binary heap
 * @param i index to remove from
 * @param heap
 * @return the key that was removed
 */
int binary_heap_remove(int i, dyn_arr *heap) {
    int last = heap->size - 1;
    int value = heap->array[i].value;
    dyn_arr_swap(i, last, heap->array);
    dyn_arr_resize(last, heap);
    if (i != last) {
        if (i == 0 || heap->array[i].key > heap->array[(i - 1) / 2].key) {
            binary_heap_heapify(i, heap);
        } else {
            binary_heap_decrease_key(i, heap->array, heap->array[i].key);
        }
    }
    return value;
}
