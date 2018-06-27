/*
 * blocks.c
 *
 *  Created on: Jun 27, 2018
 *      Author: dominik
 */

#include "types.h"
#include "dungeon/dungeon2.h"
#include "dungeon/cave.h"
#include "debug.h"
#include "agbmemory.h"
#include "bios.h"
#include "tile/block.h"
#include "data_structures.h"

#define COORDINATE_PACK(x,y) ((x << 16) | y)
#define COORDINATE_UNPACK_X(packed) ((packed >> 16) & 0xFFFF)
#define COORDINATE_UNPACK_Y(packed) (packed & 0xFFFF)

void dungeon2_cave_set_ground(int x, int y, dungeon_generator2 *dg2) {
  // TODO decoration items
  (void)dg2;
  block_set_by_pos((s16)(x + 7), (s16)(y + 7), 0x281);
}

void dungeon2_cave_set_rock(int x, int y, dungeon_generator2 *dg2) {
  // TODO different rocks
  (void)dg2;
  block_set_by_pos((s16)(x + 7), (s16)(y + 7), 0x282 | BLOCK_SOLID);
}

int dungeon2_cave_count_adjacent_of_type(int x, int y, u8 type, u8 *map, dungeon_generator2 *dg2) {
  int adjacent = 0;
  for (int i = 0; i < 4; i++) {
    int dx = dg2_cross_neighbourhood[i][0], dy = dg2_cross_neighbourhood[i][1];
    if (map[(y + dy) * dg2->width + x + dx] == type) adjacent++;
  }
  return adjacent;
}

void dungeon2_cave_set_wall(int x, int y, u8 *map, bool is_ground, dungeon_generator2 *dg2) {
  // TODO wall adjustment
  (void)is_ground;

  u16 block = 1;
  // Assemble a bitpattern for the adjacency to boost speed
  int pattern = 0;
  for (int dx = -1; dx < 2; dx++) {
    for (int dy = -1; dy < 2; dy++) {
      pattern *= 2;
      if (map[(y + dy) * dg2->width + x + dx] == DG2_WALL) pattern += 1;
    }
  }
  // Pattern bits look like this
  //    8         7        6       5        4       3        2       1       0
  // (-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 0), (0, 1), (1, -1), (1, 0), (1, 1)

  int pattern_adjacent = pattern & (2 + 8 + 32 + 128);

  if (pattern_adjacent == (2 + 8 + 32 + 128)) {  // all adjacents are walls
    if (!(pattern & 256)) { // nw missing
      block = 0x2A4 | BLOCK_SOLID;
    } else if (!(pattern & 64)) { //sw missing
      block = 0x29C | BLOCK_SOLID;
    } else if (!(pattern & 4)) { // no missing
      block = 0x2A3 | BLOCK_SOLID;
    } else if (!(pattern & 1)) { // so missing
      block = 0x29B | BLOCK_SOLID;
    } else {
      block = 0x291 | BLOCK_SOLID;
    }
  }
  // Three adjacent tiles
    else if (pattern_adjacent == (8 + 32 + 128)) { // (1, 0) missing
    block = 0x292 | BLOCK_SOLID;
  } else if (pattern_adjacent == (2 + 32 + 128)) { // (0, 1) missing
    block = 0x299 | BLOCK_SOLID;
  } else if (pattern_adjacent == (2 + 8 + 128)) { // (0, -1) missing
    block = 0x289 | BLOCK_SOLID;
  } else if (pattern_adjacent == (2 + 8 + 32)) { // (-1, 0) missing
    block = 0x290 | BLOCK_SOLID;
  }
  // Two adjacent tiles
    else if (pattern_adjacent == (2 + 8)) { // Adjacency below and right
    block = 0x288 | BLOCK_SOLID;
  } else if (pattern_adjacent == (8 + 128)) { // Adjacency below and left
    block = 0x28A | BLOCK_SOLID;
  } else if (pattern_adjacent == (2 + 32)) { // Adjacency above and right
    block = 0x298 | BLOCK_SOLID;
  } else if (pattern_adjacent == (32 + 128)) { // Adjacency above and left
    block = 0x29A | BLOCK_SOLID;
  }
  block_set_by_pos((s16)(x + 7), (s16)(y + 7), block);
}

bool dungeon2_cave_wall_can_be_drawn(u8 *map, int x, int y, dungeon_generator2 *dg2) {
  int adjacent_walls = dungeon2_cave_count_adjacent_of_type(x, y, DG2_WALL, map, dg2);
  if (adjacent_walls == 4) {
    // Edge case: If no & sw OR nw & so are missing the tile is not drawable as well
    if (map[(y - 1) * dg2->width + x - 1] != DG2_WALL
        && map[(y + 1) * dg2->width + x + 1] != DG2_WALL) {
      return false;
    } else if (map[(y - 1) * dg2->width + x + 1] != DG2_WALL &&
        map[(y + 1) * dg2->width + x - 1] != DG2_WALL) {
      return false;
    }
    return true;
  }
  // If less than 2 adjacent walls it can not be drawn for sure
  if (adjacent_walls < 2) return false;
  if (adjacent_walls == 2) {
    // Check that we have not encountered a pipe
    if (map[y * dg2->width + x - 1] == DG2_WALL && map[y * dg2->width + x + 1] == DG2_WALL)
      return false;
    if (map[(y - 1) * dg2->width + x] == DG2_WALL && map[(y + 1) * dg2->width + x] == DG2_WALL)
      return false;
  }
  return true;
}

void dungeon2_cave_draw_map(u8 *map, bool is_ground, dungeon_generator2 *dg2) {

  // Initialize a queue for all walls that might be problematic
  ring_queue_t queue;
  ring_queue_new(&queue, (size_t)(dg2->width * dg2->height));

  // First iterate over the entire map and find "problematic walls"
  for (int x = 1; x < dg2->width - 1; x++) {
    for (int y = 1; y < dg2->height - 1; y++) {
      // Count wall neighbours in the cross neighbourhood
      if (map[y * dg2->width + x] == DG2_WALL ) {
        if(dungeon2_cave_wall_can_be_drawn(map, x, y, dg2)) {
          // Draw this wall right now
          dungeon2_cave_set_wall(x, y, map, is_ground, dg2);
        } else {
          // Enqueue this wall as it can not be drawn
          ring_queue_enqueue(&queue, COORDINATE_PACK(x, y));
        }
      } else {
        // Set ground block
        dungeon2_cave_set_ground(x, y, dg2);
      }
    }
  }

  // Fix the walls that were enqueued
  while (!ring_queue_empty(&queue)) {
    int head = ring_queue_pop(&queue);
    int x = COORDINATE_UNPACK_X(head), y = COORDINATE_UNPACK_Y(head);
    dprintf("Fixing (%d, %d)\n", x, y);
    // Set this to a rock
    dungeon2_cave_set_rock(x, y, dg2);
    map[y * dg2->width + x] = DG2_ROCK;
    // Enqueue adjacent wall tiles, we changed their adjacenent wall count
    for (int i = 0; i < 4; i++) {
      int x2 = dg2_cross_neighbourhood[i][0] + x, y2 = dg2_cross_neighbourhood[i][1] + y;
      if (x2 > 0 && x2 < dg2->width - 1 && y2 > 0 && y2 < dg2->height - 1 &&
          map[y2 * dg2->width + x2] == DG2_WALL) {
        if (dungeon2_cave_wall_can_be_drawn(map, x2, y2, dg2)) {
          // Simply redraw the wall
          dungeon2_cave_set_wall(x2, y2, map, is_ground, dg2);
        } else {
          // Fix this tile as well
          ring_queue_enqueue(&queue, COORDINATE_PACK(x2, y2));
        }
      }
    }
  }
  ring_queue_del(&queue);
}


void dungeon2_compute_blocks_cave(u8 *map, u8 *over, dungeon_generator2 *dg2){
    //u8 *map2 = malloc(sizeof(u8) * (size_t)(dg2->width * dg2->height));
  (void)over;
  dungeon2_cave_draw_map(map, false, dg2);
}
