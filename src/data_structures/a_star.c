#include "types.h"
#include "stdbool.h"
#include "data_structures.h"
#include "tile/block.h"
#include "overworld/npc.h"
#include "math.h"
#include "agbmemory.h"

int a_star_compute_path(u8 *path, s16 to_x, s16 to_y, npc *original_walker) {

    npc *walker = (npc*) malloc(sizeof (npc));
    memcpy(walker, original_walker, sizeof (npc));

    s16 from_x = walker->dest_x;
    s16 from_y = walker->dest_y;

    //First we init the hashmap and the heap
    hashmap *map = hashmap_init(29);
    dyn_arr *heap = dyn_arr_init(1);

    int start_key = a_star_to_key(from_x, from_y);
    binary_heap_insert(0, start_key, heap);
    hashmap_put((u32) start_key, (int) 0xABCDABCD, map);

    /**
    int *track = (int*)0x020370E0;
    int track_index = 0;
     **/

    while (heap->size) {

        /**
        int h;
        for (h = 0; h < heap->size; h++){
            track[track_index++] = heap->array[h].key;
            track[track_index++] = heap->array[h].value;
        }
        track[track_index++] = -80;
         **/

        //As long as we have nodes to work with we use a star algorithm
        int dist_next = (int) heap->array[0].key; //distance of the node we dequeue
        int key_current = binary_heap_remove(0, heap); //remove min of heap

        /**
        for (h = 0; h < heap->size; h++){
            track[track_index++] = heap->array[h].key;
            track[track_index++] = heap->array[h].value;
        }
        track[track_index++] = -79;
         **/


        //Now we do for each neighbour an adding
        s16 x_current = (s16) (key_current >> 16);
        s16 y_current = (s16) (key_current);

        int i;
        for (i = 1; i < 5; i++) {

            s16 x_nei = (s16) (x_current + walking_directions[i].x);
            s16 y_nei = (s16) (y_current + walking_directions[i].y);
            int key_nei = a_star_to_key(x_nei, y_nei);

            //track[track_index++] = key_nei;
            if (!hashmap_contains((u32) key_nei, map) && a_star_is_connected(x_nei, y_nei, x_current, y_current, walker)) {
                //track[track_index++] = key_nei;
                if (x_nei == to_x && y_nei == to_y) {
                    //Now we need to reconstruct the path
                    hashmap_put((u32) key_nei, key_current, map);
                    int path_length = a_star_reconstruct(path, to_x, to_y, map);
                    hashmap_free(map);
                    dyn_arr_free(heap);
                    free(walker);
                    return path_length;
                }
                //we add the neighbour to the queue and to closed list, since there is no possibilty for a shorter way (due to the fact that the graph is a tile based graph)
                int prio_nei = dist_next + ABS(x_nei - to_x) + ABS(y_nei - to_y) + 1; //We use x+y as heuristic and 1 as edge weight
                hashmap_put((u32) key_nei, key_current, map); //Set parent of neighbour node to the current node
                binary_heap_insert((u32) prio_nei, key_nei, heap);
            }

        }

    }
    hashmap_free(map);
    dyn_arr_free(heap);
    free(walker);
    path[0] = 0xFE;
    return 0;

}

int a_star_reconstruct(u8 *path, s16 dest_x, s16 dest_y, hashmap *nodes) {
    int path_length = 0;
    int current_key = a_star_to_key(dest_x, dest_y);
    int prev;

    do {
        prev = hashmap_get((u32) current_key, nodes);
        if ((u32) prev == 0xABCDABCD)
            break;
        s16 x_prev = (s16) (prev >> 16);
        s16 y_prev = (s16) (prev);
        s16 x_current = (s16) (current_key >> 16);
        s16 y_current = (s16) (current_key);

        if (x_prev < x_current) { //RIGHT
            path[path_length++] = 0x13;
        } else if (x_prev > x_current) { //LEFT
            path[path_length++] = 0x12;
        } else if (y_prev < y_current) { //DOWN
            path[path_length++] = 0x10;
        } else { //UP
            path[path_length++] = 0x11;
        }
        current_key = prev;
    } while ((u32) prev != 0xABCDABCD);

    u8 *path_buf = (u8*) malloc((u32) path_length);


    int i;
    for (i = 0; i < path_length; i++) {
        path_buf[i] = path[path_length - i - 1];
    }
    memcpy(path, path_buf, (u32) path_length);

    path[i++] = 0xFE;
    free(path_buf);
    return i;
}

int a_star_to_key(s16 x, s16 y) {

    return ((u16) x << 16) | (u16) y;
}

bool a_star_is_connected(s16 dest_x, s16 dest_y, s16 from_x, s16 from_y, npc *walker) {

    //First we find the direction of the movement
    s16 dx = (s16) (dest_x - from_x);
    s16 dy = (s16) (dest_y - from_y);
    int i;
    for (i = 0; i <= 9; i++) {
        if (i == 9) {
            return false;
        }
        if (walking_directions[i].x == dx && walking_directions[i].y == dy)
            break;
    }
    u8 dir = (u8) i;

    walker->rectangle.x = 0;
    walker->rectangle.y = 0;
    walker->height.previous = walker->height.current;
    walker->height.current = (u8)(block_get_level(from_x, from_y) & 0xF);
    walker->dest_x = dest_x;
    walker->dest_y = dest_y;
    walker->facing.lower = (u8)(dir & 0xF);
    walker->facing.higher = (u8)(dir & 0xF);
    walker->from_x = from_x;
    walker->from_y = from_y;
    u8 result = npc_is_tile_blocked(walker, dest_x, dest_y, dir);
    /*
    if (result){
        u16 *marker = (u16*)0x020370E0;
        marker[0] = result;
        marker[1] = from_x;
        marker[2] = from_y;
        marker[3] = dest_x;
        marker[4] = dest_y;
        while(true){}
    }
     */
    return !result;
}
