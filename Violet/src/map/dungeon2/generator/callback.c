
#include "types.h"
#include "map/header.h"
#include "save.h"
#include "dungeon/dungeon2.h"
#include "dungeon/callback.h"
#include "debug.h"
#include "math.h"
#include "bios.h"
#include "agbmemory.h"
#include "prng.h"
#include "callbacks.h"
#include "circle.h"

static void dungeon2_callback_done(u8 self) {
    (void)self;
}

static void dungeon2_enlarge_callback(u8 self) {
    u16 *vars = big_callbacks[self].params;
    u8 *src = (u8*)big_callback_get_int(self, 2);
    u8 *dst = (u8*)big_callback_get_int(self, 4);
    dungeon_generator2 *dg2 = (dungeon_generator2*)big_callback_get_int(self, 6);
    int step = 0;
    while (step < vars[1] && vars[0] < dg2->height) {
        for (int x = 0; x < dg2->width; x++) {
            int adjacent_walls = 0;
            int y = vars[0];
            for(int k = 0; k < 4; k++){
                int i = dg2_cross_neighbourhood[k][0];
                int j = dg2_cross_neighbourhood[k][1];
                if(src[(y + j) * dg2->width + x + i] == DG2_WALL)
                    adjacent_walls++;
            }
            if (adjacent_walls == 4 && src[y * dg2->width + x] == DG2_WALL)
                dst[y * dg2->width + x] = DG2_WALL;
            else
                dst[y * dg2->width + x] = DG2_SPACE;
        }
        vars[0]++;
        step++;
    }
    if (vars[0] >= dg2->height)
        big_callbacks[self].function = dungeon2_callback_done;
}

u8 dungeon2_enlarge_with_callback(u8 *src, u8 *dst, dungeon_generator2 *dg2, u16 lines_per_frame) {
    u8 cb_idx = big_callback_new(dungeon2_enlarge_callback, 10);
    big_callbacks[cb_idx].params[0] = 0;
    big_callbacks[cb_idx].params[1] = lines_per_frame;
    big_callback_set_int(cb_idx, 2, (int)src);
    big_callback_set_int(cb_idx, 4, (int)dst);
    big_callback_set_int(cb_idx, 6, (int)dg2);
    return cb_idx;
}

bool dungeon2_enlarge_with_callback_finished(u8 cb_idx) {
    if (big_callbacks[cb_idx].function == dungeon2_callback_done) {
        big_callback_delete(cb_idx);
        return true;
    }
    return false;
}

static void dungeon2_contract_callback(u8 self) {
    u16 *vars = big_callbacks[self].params;
    u8 *src = (u8*)big_callback_get_int(self, 2);
    u8 *dst = (u8*)big_callback_get_int(self, 4);
    dungeon_generator2 *dg2 = (dungeon_generator2*)big_callback_get_int(self, 6);
    int step = 0;
    while (step < vars[1] && vars[0] < dg2->height) {
        for (int x = 0; x < dg2->width; x++) {
            int adjacent_walls = 0;
            int y = vars[0];
            for(int k = 0; k < 4; k++){
                int i = dg2_cross_neighbourhood[k][0];
                int j = dg2_cross_neighbourhood[k][1];
                if(src[(y + j) * dg2->width + x + i] == DG2_WALL)
                    adjacent_walls++;
            }
            if(adjacent_walls > 0 || src[y * dg2->width + x] == DG2_WALL)
                dst[y * dg2->width + x] = DG2_WALL;
            else
                dst[y * dg2->width + x] = DG2_SPACE;
                }
        vars[0]++;
        step++;
    }
    if (vars[0] >= dg2->height)
        big_callbacks[self].function = dungeon2_callback_done;
}

u8 dungeon2_contract_with_callback(u8 *src, u8 *dst, dungeon_generator2 *dg2, u16 lines_per_frame) {
    u8 cb_idx = big_callback_new(dungeon2_contract_callback, 10);
    big_callbacks[cb_idx].params[0] = 0;
    big_callbacks[cb_idx].params[1] = lines_per_frame;
    big_callback_set_int(cb_idx, 2, (int)src);
    big_callback_set_int(cb_idx, 4, (int)dst);
    big_callback_set_int(cb_idx, 6, (int)dg2);
    return cb_idx;
}

bool dungeon2_contract_with_callback_finished(u8 cb_idx) {
    if (big_callbacks[cb_idx].function == dungeon2_callback_done) {
        big_callback_delete(cb_idx);
        return true;
    }
    return false;
}

static void dungeon2_apply_callback(u8 self) {
    u16 *vars = big_callbacks[self].params;
    u8 *src = (u8*)big_callback_get_int(self, 2);
    u8 *dst = (u8*)big_callback_get_int(self, 4);
    dungeon_generator2 *dg2 = (dungeon_generator2*)big_callback_get_int(self, 6);
    int step = 0;
    u8 tile = (u8)vars[8];
    while (step < vars[1] && vars[0] < dg2->height) {
        for (int x = 0; x < dg2->width; x++) {
            int y = vars[0];
            if (src[y * dg2->width + x] == tile)
                dst[y * dg2->width + x] = tile;
        }
        vars[0]++;
        step++;
    }
    if (vars[0] >= dg2->height)
        big_callbacks[self].function = dungeon2_callback_done;
}

u8 dungeon2_apply_with_callback(u8 *src, u8 *dst, u8 tile, dungeon_generator2 *dg2, u16 lines_per_frame) {
    u8 cb_idx = big_callback_new(dungeon2_apply_callback, 10);
    big_callbacks[cb_idx].params[0] = 0;
    big_callbacks[cb_idx].params[1] = lines_per_frame;
    big_callback_set_int(cb_idx, 2, (int)src);
    big_callback_set_int(cb_idx, 4, (int)dst);
    big_callback_set_int(cb_idx, 6, (int)dg2);
    big_callbacks[cb_idx].params[8] = tile;
    return cb_idx;
}

bool dungeon2_apply_with_callback_finished(u8 cb_idx) {
    if (big_callbacks[cb_idx].function == dungeon2_callback_done) {
        big_callback_delete(cb_idx);
        return true;
    }
    return false;
}

static void dungeon2_fold_function_over_map_callback(u8 self) {
    u16 *vars = big_callbacks[self].params;
    u8 *src = (u8*)big_callback_get_int(self, 2);
    u8 *dst = (u8*)big_callback_get_int(self, 4);
    dungeon_generator2 *dg2 = (dungeon_generator2*)big_callback_get_int(self, 6);
    void (*f)(u8*, u8*, dungeon_generator2*, int, int) = (void (*)(u8*, u8*, dungeon_generator2*, int, int))big_callback_get_int(self, 8);
    int step = 0;
    while (step < vars[1] && vars[0] < dg2->height) {
        for (int x = 0; x < dg2->width; x++) {
            f(src, dst, dg2, x, vars[0]);
        }
        vars[0]++;
        step++;
    }
    if (vars[0] >= dg2->height)
        big_callbacks[self].function = dungeon2_callback_done;
}

u8 dungeon2_fold_function_over_map(u8 *src, u8 *dst, dungeon_generator2 *dg2, u16 lines_per_frame, void (*f)(u8 *, u8 *, dungeon_generator2 *, int, int)) {
    u8 cb_idx = big_callback_new(dungeon2_fold_function_over_map_callback, 10);
    big_callbacks[cb_idx].params[0] = 0;
    big_callbacks[cb_idx].params[1] = lines_per_frame;
    big_callback_set_int(cb_idx, 2, (int)src);
    big_callback_set_int(cb_idx, 4, (int)dst);
    big_callback_set_int(cb_idx, 6, (int)dg2);
    big_callback_set_int(cb_idx, 8, (int)f);
    return cb_idx;
}

bool dungeon2_fold_function_over_map_finished(u8 cb_idx) {
    if (big_callbacks[cb_idx].function == dungeon2_callback_done) {
        big_callback_delete(cb_idx);
        return true;
    }
    return false;
}

static void dungeon2_initialize_map_by_paths_callback(u8 self) {
    u16 *vars = big_callbacks[self].params;
    u8 *map = (u8*)big_callback_get_int(self, 3);
    int (*nodes)[2] = (int (*)[2])big_callback_get_int(self, 5);
    dungeon_generator2 *dg2 = (dungeon_generator2*) big_callback_get_int(self, 7);
    int excluded_nodes_mask = big_callback_get_int(self, 9);
    int step = 0;
    DEBUG("Initialize by path callback; progress %d/%d, steps per frame %d\n", vars[0], vars[1], vars[2]);
    while (step < vars[1] && vars[0] < vars[2]) {
        int node_idx = vars[0]++;
        if (excluded_nodes_mask & (1 << node_idx))
            continue;
        int other_candidates[node_idx];
        int other_candidates_size = 0;
        for (int i = 0; i < node_idx; i++) {
            if (!(excluded_nodes_mask & (1 << i)))
                other_candidates[other_candidates_size++] = i;
        }
        if (other_candidates_size > 0) {
            int other = other_candidates[dungeon2_rnd_16(dg2) % other_candidates_size];
            dungeon2_connect_nodes(nodes[node_idx], nodes[other], dg2, map);
        }
        step++;
    }
    if (vars[0] >= vars[2]) 
        big_callbacks[self].function = dungeon2_callback_done;
}

u8 dungeon2_initialize_map_by_paths(u8 *map, int (*nodes)[2], u16 num_nodes, u16 steps_per_frame, dungeon_generator2 *dg2, int excluded_nodes_mask) {
    u8 cb_idx = big_callback_new(dungeon2_initialize_map_by_paths_callback, 0);
    big_callbacks[cb_idx].params[0] = 1;
    big_callbacks[cb_idx].params[1] = steps_per_frame;
    big_callbacks[cb_idx].params[2] = num_nodes;
    big_callback_set_int(cb_idx, 3, (int)map);
    big_callback_set_int(cb_idx, 5, (int)nodes);
    big_callback_set_int(cb_idx, 7, (int)dg2);
    big_callback_set_int(cb_idx, 9, excluded_nodes_mask);
    return cb_idx;
}

bool dungeon2_initialize_map_by_paths_finished(u8 cb_idx) {
    if (big_callbacks[cb_idx].function == dungeon2_callback_done) {
        big_callback_delete(cb_idx);
        return true;
    }
    return false;
}

void dungeon2_enlarge_foldable(u8 *src, u8 *dst, dungeon_generator2 *dg2, int x, int y) {
    int adjacent_walls = 0;
    for(int k = 0; k < 4; k++){
        int i = dg2_cross_neighbourhood[k][0];
        int j = dg2_cross_neighbourhood[k][1];
        if(src[(y + j) * dg2->width + x + i] == DG2_WALL)
            adjacent_walls++;
    }
    if(adjacent_walls == 4 && src[y * dg2->width + x] == DG2_WALL)
        dst[y * dg2->width + x] = DG2_WALL;
    else
        dst[y * dg2->width + x] = DG2_SPACE;
}

void dungeon2_contract_foldable(u8 *src, u8 *dst, dungeon_generator2 *dg2, int x, int y) {
    int adjacent_walls = 0;
    for(int k = 0; k < 4; k++){
        int i = dg2_cross_neighbourhood[k][0];
        int j = dg2_cross_neighbourhood[k][1];
        if(src[(y + j) * dg2->width + x + i] == DG2_WALL)
            adjacent_walls++;
    }
    if(adjacent_walls > 0 || src[y * dg2->width + x] == DG2_WALL)
        dst[y * dg2->width + x] = DG2_WALL;
    else
        dst[y * dg2->width + x] = DG2_SPACE;
}

void dungeon2_apply_space_foldable(u8 *src, u8 *dst, dungeon_generator2 *dg2, int x, int y) {
    if (src[y * dg2->width + x] == DG2_SPACE)
    dst[y * dg2->width + x] = DG2_SPACE;
}

static void dungeon2_create_connected_layout_callback(u8 self) {
  create_connected_layout_state_t *state = (create_connected_layout_state_t*) big_callback_get_int(self, 0);
  dungeon_generator2 *dg2 = state->dg2;
  DEBUG("Create connected layout in state %d\n", state->state);
  switch (state->state) {
    case 0: { // Initialize maps
      int _dg2_wall = DG2_WALL | (DG2_WALL << 8);
      cpuset(&_dg2_wall, state->map1, CPUSET_HALFWORD | CPUSET_FILL |
              CPUSET_HALFWORD_SIZE(dg2->width * dg2->height));
      cpuset(&_dg2_wall, state->map2, CPUSET_HALFWORD | CPUSET_FILL |
              CPUSET_HALFWORD_SIZE(dg2->width * dg2->height));
      cpuset(&_dg2_wall, state->map_paths, CPUSET_HALFWORD | CPUSET_FILL |
              CPUSET_HALFWORD_SIZE(dg2->width * dg2->height));
      state->state++;
      break;
    }
    case 1: {
        state->cb_idx_to_wait_for = dungeon2_initialize_map_by_paths(state->map_paths, state->nodes, dg2->nodes, 
            DG2_CREATE_CONNECTED_LAYOUT_NODE_CONNECTION_STEPS_PER_FRAME, dg2, state->excluded_nodes_mask);
        state->state++;
        break;
    }
    case 2: {
        if (dungeon2_initialize_map_by_paths_finished(state->cb_idx_to_wait_for)) {
            // Copy the paths map to map1
            cpuset(state->map_paths, state->map1, CPUSET_HALFWORD | CPUSET_COPY | CPUSET_HALFWORD_SIZE(dg2->width * dg2->height));
            state->state++;
        }
        break;
    }
    case 3: {
        state->cb_idx_to_wait_for = dungeon2_enlarge_with_callback(state->map1, state->map2, dg2, 
            DG2_ENLARGE_LINES_PER_FRAME);
        state->state++;
        break;
    }
    case 4: {
        if (dungeon2_enlarge_with_callback_finished(state->cb_idx_to_wait_for))
            state->state++;
        break;
    }
    case 5: {
        state->cb_idx_to_wait_for = dungeon2_contract_with_callback(state->map2, state->map1, dg2, 
            DG2_CONTRACT_LINES_PER_FRAME);
        state->state++;
        break;
    }
    case 6: {
        if (dungeon2_contract_with_callback_finished(state->cb_idx_to_wait_for))
            state->state++;
        break;
    }
    case 7: {
        state->cb_idx_to_wait_for = dungeon2_apply_with_callback(state->map_paths, state->map1, DG2_SPACE, dg2, 
            DG2_APPLY_LINES_PER_FRAME);
        state->state++;
        break;
    }
    case 8: {
        if (dungeon2_apply_with_callback_finished(state->cb_idx_to_wait_for))
            state->state++;
        break;
    }
    case 9: {
        cpufastset(state->map1, state->result, CPUFASTSET_COPY | CPUFASTSET_SIZE(sizeof(u8) * (size_t)dg2->width * (size_t)dg2->height));
        big_callbacks[self].function = dungeon2_callback_done;
        break;
    }
  }
} 

u8 dungeon2_create_connected_layout_with_callback(dungeon_generator2 *dg2, int (*nodes)[2], u8 *dst, int excluded_nodes_mask) {
  u8 cb_idx = big_callback_new(dungeon2_create_connected_layout_callback, 10);
  create_connected_layout_state_t *state = malloc_and_clear(sizeof(create_connected_layout_state_t));
  big_callback_set_int(cb_idx, 0, (int)state);
  state->map1 = malloc(sizeof(u8) * (size_t)(dg2->width * dg2->height));
  state->map2 = malloc(sizeof(u8) * (size_t)(dg2->width * dg2->height));
  state->map_paths = malloc(sizeof(u8) * (size_t)(dg2->width * dg2->height));
  state->result = dst;
  state->nodes = nodes;
  state->dg2 = dg2;
  state->excluded_nodes_mask = excluded_nodes_mask;
  return cb_idx;
}

bool dungeon2_create_connected_layout_with_callback_finished(u8 cb_idx) {
  if (big_callbacks[cb_idx].function == dungeon2_callback_done) {
    create_connected_layout_state_t *state = (create_connected_layout_state_t*) big_callback_get_int(cb_idx, 2);
    free(state->map1);
    free(state->map2);
    free(state->map_paths);
    free(state);
    big_callback_delete(cb_idx);
    return true;
  }
  return false;
}

static inline int score_node(int nodes[][2], int idx, dungeon_generator2 *dg2) {
  if (idx == 0) return INT_MAX;
  FIXED min_dist = INT_MAX;
  FIXED mean_dist = 0;
  for (int i = 0; i < idx; i++) {
    int dx = nodes[idx][0] - nodes[i][0];
    int dy = nodes[idx][1] - nodes[i][1];
    FIXED l2_dist = FIXED_SQRT(INT_TO_FIXED(dx * dx + dy * dy));
    min_dist = MIN(min_dist, l2_dist);
    mean_dist = FIXED_ADD(mean_dist, l2_dist);
  }
  mean_dist = FIXED_DIV(mean_dist, INT_TO_FIXED(idx));
  // Weight the two norms
  int loss = dg2->node_metric_lambda_min * FIXED_TO_INT(min_dist) +
      dg2->node_metric_lambda_l2 * FIXED_TO_INT(mean_dist);
  return loss;
}

static void dungeon2_get_nodes_callback(u8 self) {
    dungeon_generator2 *dg2 = (dungeon_generator2*) big_callback_get_int(self, 2);
    int (*nodes)[2] = (int(*)[2])big_callback_get_int(self, 4);
    u16 *vars = big_callbacks[self].params;
    switch (vars[6]) {
        case 0: { // Initialize the sampling procedure of nodes
            vars[7] = 0; // nodes sampled
            big_callback_set_int(self, 8, INT_TO_FIXED(0)); // best node score
            vars[6]++;
            FALL_THROUGH;
        }
        case 1: { // Sample nodes
            int step = 0;
            int idx = vars[0];
            int xrange = dg2->width - 2 * (dg2->margin + 1); // Use a larger margin since we may offset the sample by | 1
            int yrange = dg2->height - 2 * (dg2->margin + 1);
            int xoffset = dg2->margin;
            int yoffset = dg2->margin;
            if (idx >= DG2_NODE_PATTERN && idx < DG2_NODE_PATTERN + DG2_MAX_NUM_PATTERNS) { // If a pattern is at the node, we need an even larger margin
                xrange -= 2 * dg2->pattern_margin;
                yrange -= 2 * dg2->pattern_margin;
                xoffset += dg2->pattern_margin;
                yoffset += dg2->pattern_margin;
            }
            FIXED best_score = big_callback_get_int(self, 8);
            // DEBUG("Sampling for node %d: %d / %d candidates.\n", vars[0], vars[7], dg2->node_samples);
            while (step < DG2_NODE_SAMPLES_PER_FRAME && vars[7] < dg2->node_samples) {
                // Odd node coordinates ensure the correct placements of patterns
                nodes[idx][0] = (xoffset + dungeon2_rnd_16(dg2) % xrange) | 1; 
                nodes[idx][1] = (yoffset + dungeon2_rnd_16(dg2) % yrange) | 1;
                FIXED score = score_node(nodes, idx, dg2);
                // DEBUG("Cadidate %d,%d: Score 0x%x\n", nodes[idx][0], nodes[idx][1], score);
                if (score > best_score) {
                    best_score = score;
                    vars[10] = (u16)nodes[idx][0];
                    vars[11] = (u16)nodes[idx][1];
                }
                step++;
                vars[7]++;
            }
            big_callback_set_int(self, 8, best_score);
            if (vars[7] < dg2->node_samples)
                break;
            vars[6]++;
            FALL_THROUGH;
        }
        case 2: { // Propose best node
            int idx = vars[0];
            nodes[idx][0] = vars[10];
            nodes[idx][1] = vars[11];
            if (dungeon2_propose_node(nodes, idx, dg2)) { // Node was accepted
                DEBUG("Callback sampled node %d: %d,%d\n", vars[0], vars[10], vars[11]);
                vars[0]++;
                if (vars[0] >= vars[1]) { // All nodes have been sampled
                    big_callbacks[self].function = dungeon2_callback_done;
                    return;
                }
            }
            vars[6] = 0; // Sample a new set of nodes
            break;
        }
    }
}

bool dungeon2_get_nodes_with_callback_finished(u8 cb_idx) {
    if (big_callbacks[cb_idx].function == dungeon2_callback_done) {
        big_callback_delete(cb_idx);
        return true;
    }
    return false;
}

u8 dungeon2_get_nodes_with_callback(int nodes[][2], u8 num_nodes, dungeon_generator2* dg2) {
    u8 cb_idx = big_callback_new(dungeon2_get_nodes_callback, 0);
    big_callbacks[cb_idx].params[0] = 0;
    big_callbacks[cb_idx].params[1] = num_nodes;
    big_callback_set_int(cb_idx, 2, (int)dg2);
    big_callback_set_int(cb_idx, 4, (int)nodes);
    return cb_idx;
}

static void dungeon2_create_patch_layout_callback(u8 self) {
    u8 *dst = (u8*)big_callback_get_int(self, 2);
    int excluded_node_mask = big_callback_get_int(self, 4);
    dungeon_generator2 *dg2 = (dungeon_generator2*) big_callback_get_int(self, 6);
    int (*nodes)[2] = (int (*)[2]) big_callback_get_int(self, 8);
    u16 *vars = big_callbacks[self].params;
    switch (vars[0]) {
        case 0: {
            int _dg2_space = DG2_WALL | (DG2_WALL << 8);
            cpuset(&_dg2_space, dst, CPUSET_HALFWORD | CPUSET_FILL | 
                    CPUSET_HALFWORD_SIZE(dg2->width * dg2->height));
            vars[0]++;
            vars[1] = 0;
            break;
        }
        case 1: {
            int step = 0;
            while (step < DG2_CREATE_PATCH_LAYOUT_NODES_PER_FRAME && vars[1] < dg2->nodes) {
                int node_idx = vars[1]++;
                if (excluded_node_mask & (1 << node_idx)) {
                    DEBUG("Dont create patch arround node %d\n", node_idx);
                    continue;
                }
                step++;
                int x_node = nodes[node_idx][0];
                int y_node = nodes[node_idx][1];
                for (int radius = 0; radius <= 4; radius++) {
                    for (size_t j = 0; j < circle_coordinates_by_radius[radius].size; j++) {
                        int x = x_node + circle_coordinates_by_radius[radius].coordinates[j].x;
                        int y = y_node + circle_coordinates_by_radius[radius].coordinates[j].y;
                        dst[y * dg2->width + x] = DG2_SPACE;
                    }
                }
            }
            if (vars[1] >= dg2->nodes)
                big_callbacks[self].function = dungeon2_callback_done;
            break;
        }
    }
}

bool dungeon2_create_patch_layout_with_callback_finished(u8 cb_idx) {
    if (big_callbacks[cb_idx].function == dungeon2_callback_done) {
        big_callback_delete(cb_idx);
        return true;
    }
    return false;
}

u8 dungeon2_create_patch_layout_with_callback(dungeon_generator2 *dg2, int nodes[][2], u8 *dst, int excluded_nodes_mask) {
    u8 cb_idx = big_callback_new(dungeon2_create_patch_layout_callback, 10);
    big_callback_set_int(cb_idx, 2, (int)dst);
    big_callback_set_int(cb_idx, 4, excluded_nodes_mask);
    big_callback_set_int(cb_idx, 6, (int)dg2);
    big_callback_set_int(cb_idx, 8, (int)nodes);
    big_callbacks[cb_idx].params[0] = 0;
    return cb_idx;
}
