/*
 * blocks.c
 *
 *  Created on: Jun 27, 2018
 *      Author: dominik
 */

#include "types.h"
#include "save.h"
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

#define WALL_SET_GROUND 0
#define WALL_SET_LEVEL 1
#define WALL_SET_SAND 2

void dungeon2_cave_set_ground(int x, int y, dungeon_generator2 *dg2) {
  (void)dg2;
  u16 block = 0x285;
  save1->dungeon_blocks[y * dg2->width + x] = block;
}

static const u16 dungeon2_cave_rocks_ground[] = {
    0x286 | BLOCK_SOLID, 0x287 | BLOCK_SOLID
};

static const u16 dungeon2_cave_rocks_level[] = {
    0x28e | BLOCK_SOLID, 0x28f | BLOCK_SOLID
};

void dungeon2_cave_set_rock(int x, int y, int type, dungeon_generator2 *dg2) {
  (void)dg2;
  switch (type) {
    case WALL_SET_GROUND: {
      if (dungeon2_rnd_16(dg2) < 0x4000) {
        // Omit the the rock
        dungeon2_cave_set_ground(x, y, dg2);
      } else {
        save1->dungeon_blocks[y * dg2->width + x] = dungeon2_cave_rocks_ground[dungeon2_rnd_16(dg2) % ARRAY_COUNT(dungeon2_cave_rocks_ground)];
      }
      break;
    }
    case WALL_SET_LEVEL: {
      if (dungeon2_rnd_16(dg2) < 0x800) {
        save1->dungeon_blocks[y * dg2->width + x] = dungeon2_cave_rocks_level[dungeon2_rnd_16(dg2) % ARRAY_COUNT(dungeon2_cave_rocks_level)];
      } else {
        // Omit the the rock
        save1->dungeon_blocks[y * dg2->width + x] = 0x289 | BLOCK_SOLID;
      }
      break;
    }
    case WALL_SET_SAND:
        // Omit the the rock
        dungeon2_cave_set_ground(x, y, dg2);
      break;
  }
}

void dungeon2_cave_set_wall(int x, int y, u8 *map, int type, dungeon_generator2 *dg2) {
  u16 upper_left = 0;
  u16 walk_mask = 0;
  switch (type) {
    case WALL_SET_GROUND:
      upper_left = 0x280;
      walk_mask = BLOCK_SOLID;
      break;
    case WALL_SET_LEVEL:
      upper_left = 0x298;
      walk_mask = BLOCK_SOLID;
      break;
    case WALL_SET_SAND:
      upper_left = 0x2b0;
      walk_mask = 0;
      break;
  }

  u16 block;
  // Assemble a bitpattern for the adjacency to boost speed
  int pattern = dungeon2_cave_get_adjacency_pattern(x, y, map, dg2);
  int pattern_adjacent = pattern & (ADJ_MASK_E | ADJ_MASK_S | ADJ_MASK_N | ADJ_MASK_W);

  switch (pattern_adjacent) {
    case (ADJ_MASK_E | ADJ_MASK_S | ADJ_MASK_N | ADJ_MASK_W) : {
      // 4 Adjacent walls, these blocks are shared among all types
      if (!(pattern & ADJ_MASK_NW)) { // nw missing
        block = (u16)((upper_left + 0xc) | walk_mask);
      } else if (!(pattern & ADJ_MASK_SW)) { //sw missing
        block = (u16)((upper_left + 0x4) | walk_mask);
      } else if (!(pattern & ADJ_MASK_NE)) { // no missing
        block = (u16)((upper_left + 0xb) | walk_mask);
      } else if (!(pattern & ADJ_MASK_SE)) { // so missing
        block = (u16)((upper_left + 0x3) | walk_mask);
      } else {
        block = (u16)((upper_left + 0x9) | walk_mask);
      }
      break;
    }
    // Three adjacent walls
    case (ADJ_MASK_S + ADJ_MASK_N + ADJ_MASK_W) : {
      block = (u16)((upper_left + 0xA) | walk_mask);
      break;
    }
    case (ADJ_MASK_E + ADJ_MASK_N + ADJ_MASK_W) : {
      block = (u16)((upper_left + 0x11) | walk_mask);
      break;
    }
    case (ADJ_MASK_E + ADJ_MASK_S + ADJ_MASK_W) : {
      block = (u16)((upper_left + 0x1) | walk_mask);
      break;
    }
    case (ADJ_MASK_E + ADJ_MASK_N + ADJ_MASK_S) : {
      block = (u16)((upper_left + 0x8) | walk_mask);
      break;
    }
    // Two adjacent walls
    case (ADJ_MASK_E | ADJ_MASK_S) : {
      block = (u16)((upper_left + 0x0) | walk_mask);
      break;
    }
    case (ADJ_MASK_S + ADJ_MASK_W) : { // Adjacency below and left
      block = (u16)((upper_left + 0x2) | walk_mask);
      break;
    }
    case (ADJ_MASK_E + ADJ_MASK_N) : { // Adjacency above and right
      block = (u16)((upper_left + 0x10) | walk_mask);
      break;
    }
    case (ADJ_MASK_N + ADJ_MASK_W) : { // Adjacency above and left
      block = (u16)((upper_left + 0x12) | walk_mask);
      break;
    }
    default : {
      ERROR("Invalid adjacency pattern for position %x,%x to set a ground wall: 0x%x\n", x, y, pattern_adjacent);
      block = 0; // Should not happen
    }
  }
  save1->dungeon_blocks[y * dg2->width + x] = block;
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
  else if (adjacent_walls < 2) return false;
  else if (adjacent_walls == 2) {
    // Check that we have not encountered a pipe
    if (map[y * dg2->width + x - 1] == DG2_WALL && map[y * dg2->width + x + 1] == DG2_WALL)
      return false;
    if (map[(y - 1) * dg2->width + x] == DG2_WALL && map[(y + 1) * dg2->width + x] == DG2_WALL)
      return false;
  }

  // Pattern bits look like this
  //    8         7        6       5        4       3        2       1       0
  // (-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 0), (0, 1), (1, -1), (1, 0), (1, 1)

  else if (adjacent_walls == 3) {
    // block opposing the missing adjacent are expected to be full
    int pattern = dungeon2_cave_get_adjacency_pattern(x, y, map, dg2);
    switch (pattern & (2 + 8 + 32 + 128)) {
      case (8 + 32 + 128) : { // (1, 0) missing, expect west diagonal tiles as walls
        return (pattern & 256) && (pattern & 64);
      }
      case (2 + 32 + 128) : { // (0, 1) missing, expect north diagonal tiles as walls
        return (pattern & 256) && (pattern & 4);
      }
      case (2 + 8 + 128) : { // (0, -1) missing, expect south diagonal tiles as walls
        return (pattern & 64) && (pattern & 1);
      }
      case (2 + 8 + 32) : { // (-1, 0) missing, expect the east diagonal tiles as walls
        return (pattern & 1) && (pattern & 4);
      }
    }

  }
  return true;
}

void dungeon2_cave_draw_map(u8 *map, int type, dungeon_generator2 *dg2) {

  // Initialize a queue for all walls that might be problematic
  ring_queue_t queue;
  ring_queue_new(&queue, (size_t)(dg2->width * dg2->height));

  // Fill borders
  for (int x = 0; x < dg2->width; x++) {
    save1->dungeon_blocks[x] = 0x289 | BLOCK_SOLID;
    save1->dungeon_blocks[(dg2->height - 1) * dg2->width + x] = 0x289 | BLOCK_SOLID; 
  }
  for (int y = 1; y < dg2->height - 1; y++) {
    save1->dungeon_blocks[dg2->width * y] = 0x289 | BLOCK_SOLID;
    save1->dungeon_blocks[dg2->width * y + dg2->width - 1] = 0x289 | BLOCK_SOLID; 
  }

  // First iterate over the entire map and find "problematic walls"
  for (int x = 1; x < dg2->width - 1; x++) {
    for (int y = 1; y < dg2->height - 1; y++) {
      if (map[y * dg2->width + x] == DG2_WALL ) {
        if(dungeon2_cave_wall_can_be_drawn(map, x, y, dg2)) {
          dungeon2_cave_set_wall(x, y, map, type, dg2);
        } else {
          // Enqueue this wall as it can not be drawn
          if (y == 0)
            DEBUG("Enqueue wall at %d, %d\n", x, y);
          ring_queue_enqueue(&queue, COORDINATE_PACK(x, y));
        }
      } else if (type == WALL_SET_GROUND){
        // Set ground block if we are at ground level
        dungeon2_cave_set_ground(x, y, dg2);
      }
    }
  }

  // Fix the walls that were enqueued
  while (!ring_queue_empty(&queue)) {
    int head = ring_queue_pop(&queue);
    int x = COORDINATE_UNPACK_X(head), y = COORDINATE_UNPACK_Y(head);
    //DEBUG("Fixing (%d, %d)\n", x, y);
    // Set this to a rock
    dungeon2_cave_set_rock(x, y, type, dg2);
    map[y * dg2->width + x] = DG2_ROCK;
    // Enqueue adjacent wall tiles, we changed their adjacenent wall count
    for (int dx = -1; dx < 2; dx++) {
      for (int dy = -1; dy < 2; dy++) {
        if (dx == 0 && dy == 0) continue;
        int x2 = dx + x, y2 = dy + y;
        if (x2 > 0 && x2 < dg2->width - 1 && y2 > 0 && y2 < dg2->height - 1 &&
                  map[y2 * dg2->width + x2] == DG2_WALL) {
          if (dungeon2_cave_wall_can_be_drawn(map, x2, y2, dg2)) {
            // Simply redraw the wall
            dungeon2_cave_set_wall(x2, y2, map, type, dg2);
          } else {
            // Fix this tile as well
            ring_queue_enqueue(&queue, COORDINATE_PACK(x2, y2));
          }
        }
      }
    }
  }
  ring_queue_del(&queue);
}

void dungeon2_cave_remove_walls(u8 *map, u8 *target, FIXED removal_rate, dungeon_generator2 *dg2) {
  for (int x = 1; x < dg2->width - 1; x++) {
    for (int y = 1; y < dg2->height - 1; y++) {
      target[y * dg2->width + x] = map[y * dg2->width + x];
      if (map[y * dg2->width + x] == DG2_WALL) {
        // Check if the this wall block is adjacent to space and remove if that is the case
        if (dungeon2_cave_get_adjacency_pattern(x, y, map, dg2) != ADJ_ALL) {
          if ((dungeon2_rnd_16(dg2) % INT_TO_FIXED(1)) < removal_rate)
            target[y * dg2->width + x] = DG2_SPACE;
        }
      }
    }
  }
}

void dungeon2_set_blocks_cave(u8 *map, u8 *over, dungeon_generator2 *dg2){
  (void)over;

  // Remove the walls in over
  for (int x = 0; x < dg2->width; x++) {
    for (int y = 0; y < dg2->height; y++) {
      // We actually want the patches to be walls in order to render them, so we invert
      // wall -> space, space -> wall
      // Also remove overlaps with the map free space, so we will
      if (map[y * dg2->width + x] == DG2_WALL) {
        over[y * dg2->width + x] = DG2_SPACE;
      } else {
        if (over[y * dg2->width + x] == DG2_WALL)
          over[y * dg2->width + x] = DG2_SPACE;
        else
          over[y * dg2->width + x] = DG2_WALL;
      }
    }
  }
  // dungeon2_print_map(map, dg2);

  dungeon2_cave_draw_map(map, WALL_SET_GROUND, dg2);
  
  // Allocate a map that can be manipulated in order to remove walls
  u8 *map2 = malloc(sizeof(u8) * (size_t)(dg2->width * dg2->height));
  u16 walls = DG2_WALL | (DG2_WALL << 8);
  cpuset(&walls, map2, CPUSET_FILL | CPUSET_HALFWORD | CPUSET_HALFWORD_SIZE(sizeof(u8) * (size_t)(dg2->width * dg2->height)));
  dungeon2_cave_remove_walls(map, map2, INT_TO_FIXED(1), dg2);
  dungeon2_cave_remove_walls(map2, map, FIXED_DIV(INT_TO_FIXED(5), INT_TO_FIXED(100)), dg2);
  dungeon2_cave_draw_map(map, WALL_SET_LEVEL, dg2);
  // dungeon2_print_map(map, dg2);
  dungeon2_cave_remove_walls(map, map2, INT_TO_FIXED(1), dg2);
  dungeon2_cave_remove_walls(map2, map, FIXED_DIV(INT_TO_FIXED(55), INT_TO_FIXED(100)), dg2);
  dungeon2_cave_draw_map(map, WALL_SET_LEVEL, dg2);
  // dungeon2_print_map(map, dg2);
  free(map2);

  // Draw the sand
  dungeon2_cave_draw_map(over, WALL_SET_SAND, dg2);
  // dungeon2_print_map_with_nodes(over, dg2, NULL, 0);

}
