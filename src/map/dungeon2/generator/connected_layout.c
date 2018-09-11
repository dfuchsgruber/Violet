/*
 * connected_layout.c
 *
 *  Created on: Jun 23, 2018
 *      Author: dominik
 */

#include "types.h"
#include "map/header.h"
#include "save.h"
#include "dungeon/dungeon2.h"
#include "debug.h"
#include "math.h"
#include "bios.h"
#include "agbmemory.h"
#include "prng.h"

int dungeon2_propose_node(int nodes[][2], int idx, dungeon_generator2 *dg2) {
  (void)dg2;
  for (int i = 0; i < idx; i++) {
    if (nodes[i][0] == nodes[idx][0] && nodes[i][1] == nodes[idx][1]) {
      return 0;
    }
  }
  return 1;
}

int dungeon2_node_distance(int nodes[][2], int idx, dungeon_generator2 *dg2) {
  if (idx == 0) return INT_MAX;
  FIXED min_dist = INT_MAX;
  FIXED mean_dist = 0;
  for (int i = 0; i < idx; i++) {
    int dx = nodes[idx][0] - nodes[i][0];
    int dy = nodes[idx][1] - nodes[i][1];
    FIXED l2_dist = FIXED_SQRT(INT_TO_FIXED(dx * dx + dy * dy));
    min_dist = min(min_dist, l2_dist);
    mean_dist = FIXED_ADD(mean_dist, l2_dist);
    //dprintf("L2 dist %d, Mean dist %d\n", FIXED_TO_INT(l2_dist), FIXED_TO_INT(mean_dist));
  }
  mean_dist = FIXED_DIV(mean_dist, INT_TO_FIXED(idx));
  // Weight the two norms
  int loss = dg2->node_metric_lambda_min * FIXED_TO_INT(min_dist) +
      dg2->node_metric_lambda_l2 * FIXED_TO_INT(mean_dist);
  return loss;
}


void dungeon2_sample_node(int nodes[][2], int idx, dungeon_generator2 *dg2) {

  // Calculate the range for nodes to be generated
  int margin = dg2->margin;
  int width = dg2->width;
  int height = dg2->height;
  int xrange = width - 2 * margin;
  int yrange = height - 2 * margin;
  if (xrange <= 0 || yrange <= 0) {
    derrf("Parameters for dungeon2 do not allow node generation!\n");
    return;
  }

  // Use rejection sampling to sample a node
  int best_x = -1, best_y = -1;
  FIXED best_loss = INT_TO_FIXED(0);


  for (size_t sample = 0; sample < dg2->node_samples; sample++) {
    // Propose a new node
    nodes[idx][0] = margin + (dungeon2_rnd_int(dg2) % xrange);
    nodes[idx][1] = margin + (dungeon2_rnd_int(dg2) % yrange);
    FIXED loss = dungeon2_node_distance(nodes, idx, dg2);
    if (loss > best_loss) {
      best_loss = loss;
      best_x = nodes[idx][0];
      best_y = nodes[idx][1];
    }
  }
  // Return this node
  dprintf("Sampled node (%d, %d)\n", best_x, best_y);
  nodes[idx][0] = best_x;
  nodes[idx][1] = best_y;
}

/**
int dungeon2_get_marginal_nodes(int nodes[][2], dungeon_generator2 *dg2) {

  int margin = dg2->margin;
  int node_margin = dg2->node_margin;
  int xrange = dg2->width - 2 * margin;
  int yrange = dg2->height - 2 * margin;
  if (xrange <= 0 || yrange <= 0) {
    derrf("Parameters for dungeon2 do not allow marginal node generation!\n");
  }

  int idx = 0;
  // Get node with x in [margin, margin + node_margin)
  do {
    nodes[idx][0] = margin + (dungeon2_rnd_int(dg2) % node_margin);
    nodes[idx][1] = margin + (dungeon2_rnd_int(dg2) % yrange);
  } while (!dungeon2_propose_node(nodes, idx, dg2));
  idx++;

  // Get node with x in [width - margin - node_margin - 1, width - margin)
  do {
    nodes[idx][0] = margin + xrange - node_margin + (dungeon2_rnd_int(dg2) % node_margin);
    nodes[idx][1] = margin + (dungeon2_rnd_int(dg2) % yrange);
  } while (!dungeon2_propose_node(nodes, idx, dg2));
  idx++;

  // Get node with y in [margin, margin + node_margin)
  do {
    nodes[idx][1] = margin + (dungeon2_rnd_int(dg2) % node_margin);
    nodes[idx][0] = margin + (dungeon2_rnd_int(dg2) % xrange);
  } while (!dungeon2_propose_node(nodes, idx, dg2));
  idx++;

  // Get node with x in [width - margin - node_margin - 1, width - margin)
  do {
    nodes[idx][1] = margin + yrange - node_margin + (dungeon2_rnd_int(dg2) % node_margin);
    nodes[idx][0] = margin + (dungeon2_rnd_int(dg2) % xrange);
  } while (!dungeon2_propose_node(nodes, idx, dg2));
  idx++;

  return idx;
}
**/
void dungeon2_get_nodes(int nodes[][2], int num_nodes, dungeon_generator2 *dg2, bool random_nodes) {

  if (!random_nodes) {
    // Reset state of prng to assert the same nodes every time
    dg2->seed = dg2->initial_seed;
  }

  for (int node_idx = 0 ; node_idx < num_nodes; node_idx++) {
    // Sample a node
    do {
      dprintf("Sampling node %d\n", node_idx);
      dungeon2_sample_node(nodes, node_idx, dg2);
    } while (!dungeon2_propose_node(nodes, node_idx, dg2));

  }
  /**
  // Depercated

  // Generate marginal nodes
  if (num_nodes < 4) {
    derrf("Number of nodes < 4 (could not generate 4 marginal nodes)");
    return;
  }
  int node_idx = dungeon2_get_marginal_nodes(nodes, dg2);

  // Generate nodes
  for (; node_idx < num_nodes; node_idx++) {
    do {
      nodes[node_idx][0] = margin + (dungeon2_rnd_int(dg2) % xrange);
      nodes[node_idx][1] = margin + (dungeon2_rnd_int(dg2) % yrange);
    } while (!dungeon2_propose_node(nodes, node_idx, dg2));
  }
  **/
}

#define STATE_SP 0
#define STATE_RND (1 ^ STATE_SP)

void dungeon2_connect_nodes_sp_next_step(int p[2], int q[2], dungeon_generator2 *dg2) {
  (void)dg2;
  int dx = q[0] - p[0];
  int dy = q[1] - p[1];
  if (abs(dx) > abs(dy)) {
    p[0] += sign(dx);
  } else {
    p[1] += sign(dy);
  }
}

void dungeon2_connect_nodes_rnd_next_step(int p[2], int q[2], dungeon_generator2 *dg2){
  (void)q;
  int width = dg2->width;
  int height = dg2->height;
  int margin = dg2->margin;
  while(1) {
    int idx = dungeon2_rnd_int(dg2) % 4;
    int x = p[0] + dg2_cross_neighbourhood[idx][0];
    int y = p[1] + dg2_cross_neighbourhood[idx][1];
    if (x >= margin && x < width - margin && y >= margin
        && y < height - margin) {
      p[0] = x;
      p[1] = y;
      return;
    }
  }
}

void dungeon2_connect_nodes(int p[2], int q[2], dungeon_generator2 *dg2, u8 *map) {
  dprintf("Connecting (%d, %d) @ %x to (%d, %d) @%x \n", p[0], p[1], (int)p, q[0], q[1], (int)q);
  int strategy = STATE_SP;
  int from[2] = {p[0], p[1]};
  FIXED prob = dg2->path_randomness;
  while (from[0] != q[0] || from[1] != q[1]) {
    map[from[1] * dg2->width + from[0]] = DG2_SPACE;
    // Check if strategy is changed
    if (dungeon2_rnd_16(dg2) < prob) {
      // No strategy change: prob *= path_randomness
      prob = FIXED_MUL(prob, dg2->path_randomness);
    } else {
      // Change strategy
      prob = dg2->path_randomness;
      strategy ^= 1;
    }
    if (strategy == STATE_SP) {
      dungeon2_connect_nodes_sp_next_step(from, q, dg2);
    } else if (strategy == STATE_RND) {
      dungeon2_connect_nodes_rnd_next_step(from, q, dg2);
    }
  }
  map[q[1] * dg2->width + q[0]] = DG2_SPACE;
}

void dungeon2_init_by_paths(u8 *map, dungeon_generator2 *dg2, bool random_nodes){
    // Get all nodes
    int nodes[dg2->nodes][2];
    dungeon2_get_nodes(nodes, dg2->nodes, dg2, random_nodes);

    // Connect all nodes to one layout
    for (int i = 1; i < dg2->nodes; i++) {
      // nodes[i] is not connected to the map so far
      int j = dungeon2_rnd_int(dg2) % i;
      // Connect it with node j
      dungeon2_connect_nodes(nodes[i], nodes[j], dg2, map);
    }
}

void dungeon2_print_map(u8 *map, dungeon_generator2 *dg2) {
  int nodes[dg2->nodes][2];
  dungeon2_get_nodes(nodes, dg2->nodes, dg2, false);
  char charmap[dg2->width + 5];
      for (int y = 0; y < dg2->height; y++) {
        int x;
        for (x = 0; x < dg2->width; x++) {
          if (map[y * dg2->width + x] == DG2_SPACE) charmap[x] = ' ';
          else if (map[y * dg2->width + x] == DG2_WALL) charmap[x] = '#';
          else charmap[x] = 'R';
          for (int i = 0; i < dg2->nodes; i++) {
                      if (x == nodes[i][0] && y == nodes [i][1])
                        charmap[x] = 'x';
          }
        }
        charmap[x++] = ' ';
        charmap[x++] = (char) (48 + y / 10);
        charmap[x++] = (char) (48 + y % 10);
        charmap[x++] = '\n';
        charmap[x++] = 0;
        dprintf(charmap);
       }
}

u8 *dungeon2_create_connected_layout(dungeon_generator2 *dg2, bool random_nodes){
    u8 *map1 = malloc(sizeof(u8) * (size_t)(dg2->width * dg2->height));
    u8 *map2 = malloc(sizeof(u8) * (size_t)(dg2->width * dg2->height));
    u8 *map_paths = malloc(sizeof(u8) * (size_t)(dg2->width * dg2->height));


    int _dg2_wall = DG2_WALL | (DG2_WALL << 8);
    cpuset(&_dg2_wall, map1, CPUSET_HALFWORD | CPUSET_FILL |
            ((dg2->width * dg2->height) / 2));
    cpuset(&_dg2_wall, map2, CPUSET_HALFWORD | CPUSET_FILL |
            ((dg2->width * dg2->height) / 2));
    cpuset(&_dg2_wall, map_paths, CPUSET_HALFWORD | CPUSET_FILL |
            ((dg2->width * dg2->height) / 2));

    dungeon2_init_by_paths(map_paths, dg2, random_nodes);

    // Copy the paths map to map1
    cpuset(map_paths, map1, CPUSET_HALFWORD | CPUSET_COPY | ((dg2->width * dg2->height) / 2));
    dungeon2_enlarge(map1, map2, dg2);
    dungeon2_contract(map2, map1, dg2);
    dungeon2_apply(map_paths, map1, DG2_SPACE, dg2);
    dungeon2_print_map(map1, dg2);

    free(map_paths);
    free(map2);

    return map1;
}
