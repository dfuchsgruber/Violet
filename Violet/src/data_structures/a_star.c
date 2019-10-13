#include "types.h"
#include "stdbool.h"
#include "data_structures.h"
#include "tile/block.h"
#include "overworld/npc.h"
#include "math.h"
#include "agbmemory.h"
#include "debug.h"
#include "constants/movements.h"

int a_star_compute_path(u8 *path, s16 x_destination, s16 y_destination, npc *original_walker) {

    npc *walker = malloc(sizeof(npc));
    memcpy(walker, original_walker, sizeof(npc));

    //First we init the hashmap and the heap
    hashmap *predecessor = hashmap_init(39);
    dyn_arr *queue = dyn_arr_init(A_STAR_INITIAL_QUEUE_SIZE);


    int key = a_star_coordinates_to_key(walker->dest_x, walker->dest_y);
    binary_heap_insert(0, key, queue);
    hashmap_put((u32)key, (int) A_STAR_PREDECESSOR_NONE, predecessor);
    s16 x = 0, y = 0;

    while (queue->size) {
        int distance = (int) queue->array[0].key;  // Distance of node to dequeue
        key = binary_heap_remove(0, queue); // Remove node with minimal distance
        a_star_key_to_coordinates(key, &x, &y);

        if (x == x_destination && y == y_destination) {
            int path_length = a_star_reconstruct(path, x_destination, y_destination, predecessor);
            // Free resources
            hashmap_free(predecessor);
            dyn_arr_free(queue);
            free(walker);
            return path_length;
        }

        for (int i = 1; i < 5; i++) {
            s16 x_adjacent = (s16) (x + walking_directions[i].x);
            s16 y_adjacent = (s16) (y + walking_directions[i].y);
            int key_adjacent = a_star_coordinates_to_key(x_adjacent, y_adjacent);

            if (!hashmap_contains((u32) key_adjacent, predecessor) && 
                a_star_is_connected(x_adjacent, y_adjacent, x, y, walker)) {
                hashmap_put((u32) key_adjacent, key, predecessor);

                // Employ manhattan-distance heuristic and edge weights of 1
                int priority_adjacent = distance + ABS(x_adjacent - x_destination) + ABS(y_adjacent - y_destination) + 1; //We use x+y as heuristic and 1 as edge weight
                binary_heap_insert((u32) priority_adjacent, key_adjacent, queue);
            }
        }
    }
    derrf("Could not find an a-star path\n");
    hashmap_free(predecessor);
    dyn_arr_free(queue);
    free(walker);
    path[0] = STOP;
    return 0;
}

int a_star_reconstruct(u8 *path, s16 dest_x, s16 dest_y, hashmap *predecessors) {
    int path_length = 0;
    int key = a_star_coordinates_to_key(dest_x, dest_y);
    int predecessor;
    s16 x_previous = 0, y_previous = 0, x = 0, y = 0;
    do {
        predecessor = hashmap_get((u32) key, predecessors);
        if ((u32) predecessor == A_STAR_PREDECESSOR_NONE)
            break;
        a_star_key_to_coordinates(predecessor, &x_previous, &y_previous);
        a_star_key_to_coordinates(key, &x, &y);

        if (x_previous < x) {
            path[path_length++] = STEP_RIGHT;
        } else if (x_previous > x) {
            path[path_length++] = STEP_LEFT;
        } else if (y_previous < y) {
            path[path_length++] = STEP_DOWN;
        } else {
            path[path_length++] = STEP_UP;
        }
        key = predecessor;
    } while ((u32) key != A_STAR_PREDECESSOR_NONE);

    u8 *path_buf = (u8*) malloc((u32) path_length);

    // Reverse the order of moves
    int i;
    for (i = 0; i < path_length; i++) {
        path_buf[i] = path[path_length - i - 1];
    }
    memcpy(path, path_buf, (u32) path_length);

    path[i++] = STOP;
    free(path_buf);
    return i;
}

int a_star_coordinates_to_key(s16 x, s16 y) {
    return ((u16) x << 16) | (u16) y;
}

void a_star_key_to_coordinates(int key, s16 *x, s16 *y) {
    *x = (s16)(key >> 16);
    *y = (s16)(key);
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
    return !result;
}
