#include "types.h"
#include "romfuncs.h"
#include "stdbool.h"
#include "data_structures.h"


hashmap *hashmap_init(int buckets){
    hashmap *map = (hashmap*)malloc(sizeof(hashmap));
    map->buckets = (dyn_arr**)malloc_fill(sizeof(dyn_arr*)*(u32)buckets);
    map->map_size = buckets;
    int i;
    for(i = 0; i < 4; i++){
        map->a[i] = (u8)random_change_seed();
    }
    return map;
}

void hashmap_free(hashmap *map){
    int i;
    for(i = 0; i < map->map_size; i++){
        if(map->buckets[i]){
            dyn_arr_free(map->buckets[i]);
        }
    }
    free(map->buckets);
    free(map);
}

int hashmap_hash(u32 key, hashmap *map){
    int hash = 0;
    int i;
    for (i = 0; i < 4; i++){
        int key_8 = (int)(key & (u32)(0xFF<<i*8));
        key_8 = (key_8 >> (i*8));
        hash += key_8 * map->a[i];
    }
    
    return (int)__umod((u32)hash, (u32)map->map_size);
}

bool hashmap_contains(u32 key, hashmap *map){
    int bucket = hashmap_hash(key, map);
    if (map->buckets[bucket]){
        int i;
        for (i = 0; i < map->buckets[bucket]->size; i++){
            if (map->buckets[bucket]->array[i].key == key)
                return true;
        }
    }
    return false;
}

int hashmap_get(u32 key, hashmap *map){
    int bucket = hashmap_hash(key, map);
    if (map->buckets[bucket]){
        int i;
        for (i = 0; i < map->buckets[bucket]->size; i++){
            if (map->buckets[bucket]->array[i].key == key)
                return map->buckets[bucket]->array[i].value;
        }
    }
    return NULL;
}

void hashmap_put(u32 key, int value, hashmap *map){
    int bucket = hashmap_hash(key, map);
    if (hashmap_contains(key, map)){
        
        int i;
        for (i = 0; i < map->buckets[bucket]->size; i++){
            if (map->buckets[bucket]->array[i].key == key)
                map->buckets[bucket]->array[i].value = value;
        }
    }
   
    //Value is not in hashmap
    if (!map->buckets[bucket]){
        map->buckets[bucket] = dyn_arr_init(1);
    }
    int index = map->buckets[bucket]->size;
    dyn_arr_resize(index+1, map->buckets[bucket]);
    map->buckets[bucket]->array[index].key = key;
    map->buckets[bucket]->array[index].value = value;
}

int hashmap_remove(u32 key, hashmap *map){
    
    int bucket = hashmap_hash(key, map);
    if (map->buckets[bucket]){
        int i;
        for (i = 0; i < map->buckets[bucket]->size; i++){
            if (map->buckets[bucket]->array[i].key == key){
                int value = map->buckets[bucket]->array[i].value;
                memcopy(&map->buckets[bucket]->array[i], &map->buckets[bucket]->array[i+1], (u32)(map->buckets[bucket]->array_size-i-1)* (sizeof(dyn_arr_node)));
                if(map->buckets[bucket]->size-1){
                    dyn_arr_resize(map->buckets[bucket]->size-1, map->buckets[bucket]);
                    return value;
                }else{
                    dyn_arr_free(map->buckets[bucket]);
                    map->buckets[bucket] = NULL;
                }
            }
        }
    }
    return 0;
}
