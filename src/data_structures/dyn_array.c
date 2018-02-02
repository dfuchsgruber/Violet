#include "types.h"
#include "stdbool.h"
#include "data_structures.h"
#include "romfuncs.h"

dyn_arr *dyn_arr_init(int array_size) {
    dyn_arr *arr = (dyn_arr*) malloc(sizeof (dyn_arr));
    arr->array = (dyn_arr_node*) cmalloc(sizeof (dyn_arr_node)*(u32) array_size);
    arr->array_size = array_size;
    arr->size = 0;
    return arr;
}

void dyn_arr_free(dyn_arr *arr) {
    free(arr->array);
    free(arr);
}

/**
 * Swaps to elements inside the heap array
 * @param a
 * @param b
 * @param array
 */
void dyn_arr_swap(int a, int b, dyn_arr_node *array) {

    u32 key_tmp = array[a].key;
    int val_tmp = array[a].value;
    array[a].key = array[b].key;
    array[a].value = array[b].value;
    array[b].key = key_tmp;
    array[b].value = val_tmp;
}

/**
 * Resizes the array if overhead is too great or the array is too short
 * @param size
 * @param heap
 */
void dyn_arr_resize(int size, dyn_arr *heap) {
    dyn_arr_node *array_x;
    if (size > heap->array_size) {
        array_x = (dyn_arr_node*) cmalloc(sizeof (dyn_arr_node)*(u32) size * 2);
        memcpy(array_x, heap->array, sizeof (dyn_arr_node)*(u32) heap->array_size);
        heap->array_size = size * 2;
        heap->size = size;
    } else if (size <= heap->array_size / 2) {
        array_x = (dyn_arr_node*) cmalloc(sizeof (dyn_arr_node)*(u32) heap->array_size / 2);
        memcpy(array_x, heap->array, sizeof (dyn_arr_node)*(u32) size);
        heap->array_size /= 2;
        heap->size = size;
    } else {
        heap->size = size;
        return;
    }
    //if we have reached this point we need to change the array references
    free(heap->array);
    heap->array = array_x;
}