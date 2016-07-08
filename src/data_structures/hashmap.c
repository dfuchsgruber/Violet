#include "types.h"
#include "romfuncs.h"
#include "stdbool.h"
#include "data_structures.h"

hashmap *init_hashmap(int buckets){
    hashmap *map = (hashmap*)malloc(sizeof(hashmap));
    map->size = 0;
    map->buckets = (dyn_arr*)malloc_fill(sizeof(dyn_arr)*buckets);
    map->map_size = buckets;
    int i;
    for(i = 0; i < 4; i++){
        map->a[i] = (u8)random_change_seed();
    }
    return map;
}

void free_hashmap(hashmap *map){
    int i;
    for(i = 0; i < map; i++){
        if(map->buckets[i]){
            dyn_arr_free(map->buckets[i]);
        }
    }
    free(map);
}

int hash(u32 key, hashmap *map){
    int hash = 0;
    int i;
    for (i = 0; i < 4; i++){
        hash += ((key & (0xFF<<i*8)) >> (i * 8)) * map->a[i];
    }
    return __umod(hash, map->map_size);
}

bool contains(u32 key, hashmap *map){
    int bucket = hash(key, map);
    if (map->buckets[bucket]){
        int i;
        for (i = 0; i < map->buckets[bucket]->size; i++){
            if (map->buckets[bucket]->array[i].key == key)
                return true;
        }
    }
    return false;
}

void put(u32 key, int value, hashmap *map){
    int bucket = hash(key, map);
    if (!map->buckets[bucket]){
        map->buckets[bucket] = dyn_arr_init(1);
        map->buckets[bucket]->array[0].key = key;
        map->buckets[bucket]->array[0].value = value;
        return;
    }
    int i;
    for (i = 0; i < map->buckets[bucket]->size; i++){
        if (map->buckets[bucket]->array[i].key == key){
            map->buckets[bucket]->array[i].value = value;
            return;
        }
    }
}
