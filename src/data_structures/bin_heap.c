/* 
 * File:   bin_heap.c
 * Author: Domi
 *
 * Created on 7. Juli 2016, 13:31
 */

#include "types.h"
#include "stdbool.h"
#include "data_structures.h"
#include "romfuncs.h"



dyn_arr *dyn_arr_init(int size){
    dyn_arr *arr = (dyn_arr*)malloc(sizeof(dyn_arr));
    arr->array = (dyn_arr_node*)malloc_fill(sizeof(dyn_arr_node)*size);
    arr->array_size = size;
    arr->size = 0;
    return arr;
}

void dyn_arr_free(dyn_arr *arr){
    free(arr->array);
    free(arr);
}

/**
 * Swaps to elements inside the heap array
 * @param a
 * @param b
 * @param array
 */
void dyn_arr_swap(int a, int b, dyn_arr_node *array){
    dyn_arr_node *tmp = (dyn_arr_node*)malloc(sizeof(dyn_arr_node));
    memcopy(tmp, &array[a], sizeof(dyn_arr_node));
    memcopy (&array[a], &array[b], sizeof(dyn_arr_node));
    memcopy (&array[b], tmp, sizeof(dyn_arr_node));
    free(tmp);
}

/**
 * Restores heap invariance of heap at root position = a
 * @param a
 * @param heap
 */
void binary_heap_heapify(int a, dyn_arr *heap){
    int i = a;
    do {
        int min = i;
        int left = 2*i + 1;
        int right = 2*i + 2;
        if (left < heap->array_size && heap->array[left].key < heap->array[min].key)
            min = left;
        if (right < heap->array_size && heap->array[right].key < heap->array[min].key)
            min = right;
        if (min == i)
            break;
        dyn_arr_swap(i, min, heap->array);
    }while(true);
}

/**
 * Resizes the array if overhead is too great or the array is too short
 * @param size
 * @param heap
 */
void dyn_arr_resize(int size, dyn_arr *heap){
    dyn_arr_node *array_x;
    if (size > heap->array_size){
        array_x = (dyn_arr_node*)malloc_fill(sizeof(dyn_arr_node)*heap->array_size * 2);
        memcopy(array_x, heap->array, sizeof(dyn_arr_node)*heap->size);
        heap->array_size *= 2;
        heap->size = size;
    }else if(size <= heap->array_size / 2){
        array_x = (dyn_arr_node*)malloc_fill(sizeof(dyn_arr_node)*heap->array_size / 2);
        memcopy(array_x, heap->array, sizeof(dyn_arr_node)*size);
        heap->array_size /= 2;
        heap->size = size;
    }else{
        heap->size = size;
        return;
    }
    //if we have reached this point we need to change the array references
    free(heap->array);
    heap->array = array_x;
}

/**
 * Decreases a key for a node in the heap
 * @param a position in heap
 * @param array 
 * @param key_new
 */
void binary_heap_decrease_key(int a, dyn_arr_node *array, u32 key_new){
    int i = a;
    if (key_new <= array[i].key){
        array[i].key = key_new;
        //Now we push the key upwards
        while(i  && array[i].key < array[(i-1)/2].key){
            dyn_arr_swap(i, (i-1)/2, array);
            i = (i-1)/2;
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
void binary_heap_insert(u32 key, int value, dyn_arr *heap){
    int i = heap->size;
    dyn_arr_resize(i+1, heap);
    heap->array[i].key = key;
    heap->array[i].value = value;
    binary_heap_decrease_key(i, heap->array, key);
}

/**
 * Removes a node from the binary heap
 * @param i
 * @param heap
 * @return 
 */
dyn_arr_node *binary_heap_remove(int i, dyn_arr *heap){
    
}




