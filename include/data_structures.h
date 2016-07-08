/* 
 * File:   bin_heap.h
 * Author: Domi
 *
 * Created on 7. Juli 2016, 13:31
 */

#ifndef BIN_HEAP_H
#define	BIN_HEAP_H

typedef struct{
    
    u32 key;
    int value;
    
} dyn_arr_node;


typedef struct{

    int size;
    int array_size;
    dyn_arr_node *array;
    
} dyn_arr;

dyn_arr *dyn_arr_init(int size);

void dyn_arr_free(dyn_arr *heap);

void dyn_arr_swap(int a, int b, dyn_arr_node *array);

void dyn_arr_resize(int size, dyn_arr *heap);

void binary_heap_decrease_key(int a, dyn_arr_node *array, u32 key_new);

void binary_heap_insert(u32 key, int priority, dyn_arr *heap);

dyn_arr_node *binary_heap_remove(int i, dyn_arr *heap);


typedef struct{
    
    int size;
    int map_size;
    dyn_arr **buckets;
    u8 a[4];
    
} hashmap;

#endif	/* BIN_HEAP_H */

