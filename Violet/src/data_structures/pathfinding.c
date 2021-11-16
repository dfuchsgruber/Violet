#include "types.h"
#include "stdbool.h"
#include "data_structures.h"
#include "tile/block.h"
#include "overworld/npc.h"
#include "math.h"
#include "agbmemory.h"
#include "debug.h"
#include "constants/movements.h"
#include "callbacks.h"
#include "overworld/script.h"

static void a_star_state_delete(a_star_state *state) {
    hashmap_free(state->predecessor);
    hashmap_free(state->g);
    hashmap_free(state->closed);
    dyn_arr_free(state->queue);
    free(state);
}

static void a_star_done(u8 self) {
    big_callbacks[self].params[0] = true;
}

static void a_star_big_callback(u8 self) {
    a_star_state *state = (a_star_state*)big_callback_get_int(self, 1);
    int steps = 0;

    while (steps < state->steps_per_frame && state->queue->size) {
        a_star_key key = {.value = binary_heap_remove(0, state->queue)}; // Remove node with minimal distance
        int distance = hashmap_get((u32)key.value, state->g);
        if (hashmap_contains((u32)key.value, state->closed))
            continue;
        hashmap_put((u32)key.value, 0, state->closed); // Close this vertex
        DEBUG("Expanding 0x%x, 0x%x with heading %d\n", key.state.x - 7, key.state.y - 7, key.state.heading);
        if (key.state.x == state->x_destination && key.state.y == state->y_destination) {
            a_star_reconstruct(state->path, key, state->predecessor, state->speed);
            // Free resources
            a_star_state_delete(state);
            big_callbacks[self].function = a_star_done;
            return;
        }
        for (int i = 1; i < 5; i++) {
            s16 x_adjacent = (s16) (key.state.x + walking_directions[i].x);
            s16 y_adjacent = (s16) (key.state.y + walking_directions[i].y);
            a_star_key key_adjacent = {.state = {.x = (s16)(x_adjacent & 0x1FFF), .y = (s16)(y_adjacent & 0x1FFF), .heading = (s8)(i & 7)}};
            if (!a_star_is_connected(x_adjacent, y_adjacent, key.state.x, key.state.y, &state->original_walker))
                continue;

            // Employ manhattan-distance heuristic and edge weights of 1
            int distance_adjacent = distance + A_STAR_COST_SCALING; //We use x+y as heuristic and 1 as edge weight
            // Add heuristic
            int heuristic = A_STAR_COST_SCALING * (ABS(x_adjacent - state->x_destination) + ABS(y_adjacent - state->y_destination));
            // Add cost for turning
            if (i != key.state.heading)
                distance_adjacent += 1;
            // Enqueue only if the cost is decreasing
            if (hashmap_contains((u32)key_adjacent.value, state->closed))
                continue;
            if (hashmap_contains((u32)key_adjacent.value, state->g) && distance_adjacent >= hashmap_get((u32)key_adjacent.value, state->g)) 
                continue;
            hashmap_put((u32)key_adjacent.value, key.value, state->predecessor);
            hashmap_put((u32)key_adjacent.value, distance_adjacent, state->g);
                binary_heap_insert((u32) (distance_adjacent + heuristic), key_adjacent.value, state->queue);
        }
        steps++;
    }
    if (state->queue->size == 0) {
        DEBUG("Could not find an a-star path\n");
        state->path[0] = STOP;
        a_star_state_delete(state);
        big_callbacks[self].function = a_star_done;
    }
}

u8 a_star_compute_path(u8 *path, s16 x_destination, s16 y_destination, npc *original_walker, u8 speed, int steps_per_frame) {
    DEBUG("A star for warlker person %d \n", original_walker->overworld_id);
    a_star_state *state = malloc(sizeof(a_star_state));
    state->original_walker = *original_walker;

    //First we init the hashmap and the heap
    hashmap *predecessor = hashmap_init(A_STAR_NUM_BUCKETS);
    hashmap *g = hashmap_init(A_STAR_NUM_BUCKETS);
    hashmap *closed = hashmap_init(A_STAR_NUM_BUCKETS);
    dyn_arr *queue = dyn_arr_init(A_STAR_INITIAL_QUEUE_SIZE);

    a_star_key key = {.state = {.x = (int)(original_walker->dest_x & 0x1FFF), .y = (int)(original_walker->dest_y & 0x1FFF), .heading = DIR_NONE}};
    binary_heap_insert(0, key.value, queue);
    hashmap_put((u32)key.value, (int) A_STAR_PREDECESSOR_NONE, predecessor);
    hashmap_put((u32)key.value, 0, g);

    state->g = g;
    state->predecessor = predecessor;
    state->closed = closed;
    state->queue = queue;
    state->path = path;
    state->x_destination = x_destination;
    state->y_destination = y_destination;
    state->steps_per_frame = steps_per_frame;
    state->speed = speed;

    u8 callback_idx = big_callback_new(a_star_big_callback, 15);
    big_callbacks[callback_idx].params[0] = false;
    big_callback_set_int(callback_idx, 1, (int)state);
    return callback_idx;
}

static u8 direction_and_speed_to_movement[][5] = {
    [A_STAR_SPEED_SLOW] = {
        [DIR_NONE] = 0,
        [DIR_DOWN] = STEP_DOWN_VERY_SLOW,
        [DIR_UP] = STEP_UP_VERY_SLOW,
        [DIR_LEFT] = STEP_LEFT_VERY_SLOW,
        [DIR_RIGHT] = STEP_RIGHT_VERY_SLOW,
    },
    [A_STAR_SPEED_NORMAL] = {
        [DIR_NONE] = 0,
        [DIR_DOWN] = STEP_DOWN,
        [DIR_UP] = STEP_UP,
        [DIR_LEFT] = STEP_LEFT,
        [DIR_RIGHT] = STEP_RIGHT,
    },
    [A_STAR_SPEED_FAST] = {
        [DIR_NONE] = 0,
        [DIR_DOWN] = STEP_DOWN_FAST,
        [DIR_UP] = STEP_UP_FAST,
        [DIR_LEFT] = STEP_LEFT_FAST,
        [DIR_RIGHT] = STEP_RIGHT_FAST,
    },
};

int a_star_reconstruct(u8 *path, a_star_key key, hashmap *predecessors, u8 speed) {
    int path_length = 0;
    int predecessor;
    do {
        predecessor = hashmap_get((u32) key.value, predecessors);
        if ((u32) predecessor == A_STAR_PREDECESSOR_NONE)
            break;
        a_star_key predecessor_key = {.value = (int)predecessor};
        if (key.state.heading != DIR_NONE)
            path[path_length++] = direction_and_speed_to_movement[speed][key.state.heading];
        key = predecessor_key;
    } while ((u32)key.value != A_STAR_PREDECESSOR_NONE);


    // Reverse the order of moves
    int i = 0, j = path_length - 1;
    while (i < j) {
        u8 tmp = path[i];
        path[i] = path[j];
        path[j] = tmp;
        i++;
        j--;
    }
    path[path_length++] = STOP;
    return path_length;
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
    walker->direction.facing = (u8)(dir & 0xF);
    walker->direction.movement = (u8)(dir & 0xF);
    walker->from_x = from_x;
    walker->from_y = from_y;
    u8 result = npc_get_collision(walker, dest_x, dest_y, dir);
    return !result;
}
