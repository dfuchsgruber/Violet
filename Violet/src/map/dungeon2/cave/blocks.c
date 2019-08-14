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

#define WALL_SET_GROUND 0
#define WALL_SET_LEVEL 1
#define WALL_SET_SAND 2


void dungeon2_cave_set_ground(int x, int y, dungeon_generator2 *dg2) {
  // TODO decoration items
  (void)dg2;
  block_set_by_pos((s16)(x + 7), (s16)(y + 7), 0x281);
}

u16 dungeon2_cave_rocks_ground[] = {
    0x282 | BLOCK_SOLID, 0x283 | BLOCK_SOLID
};

u16 dungeon2_cave_rocks_level[] = {
    0x33C | BLOCK_SOLID, 0x33D | BLOCK_SOLID
};
void dungeon2_cave_set_rock(int x, int y, int type, dungeon_generator2 *dg2) {
  // TODO different rocks
  (void)dg2;
  switch (type) {
    case WALL_SET_GROUND: {
      if (dungeon2_rnd_16(dg2) < 0x4000) {
        // Omit the the rock
        dungeon2_cave_set_ground(x, y, dg2);
      } else {
        block_set_by_pos((s16)(x + 7), (s16)(y + 7),
            dungeon2_cave_rocks_ground[dungeon2_rnd_16(dg2) & 1]);
      }
      break;
    }
    case WALL_SET_LEVEL: {
      if (dungeon2_rnd_16(dg2) < 0x800) {
        block_set_by_pos((s16)(x + 7), (s16)(y + 7),
            dungeon2_cave_rocks_level[dungeon2_rnd_16(dg2) & 1]);
      } else {
        // Omit the the rock
        block_set_by_pos((s16)(x + 7), (s16)(y + 7), 0x291 | BLOCK_SOLID);
      }
      break;
    }
    case WALL_SET_SAND:
      block_set_by_pos((s16)(x + 7), (s16)(y + 7), 0x281);
      break;
  }
}

int dungeon2_cave_count_adjacent_of_type(int x, int y, u8 type, u8 *map, dungeon_generator2 *dg2) {
  int adjacent = 0;
  for (int i = 0; i < 4; i++) {
    int dx = dg2_cross_neighbourhood[i][0], dy = dg2_cross_neighbourhood[i][1];
    if (map[(y + dy) * dg2->width + x + dx] == type) adjacent++;
  }
  return adjacent;
}

int dungeon2_cave_get_adjacency_pattern(int x, int y, u8 *map, dungeon_generator2 *dg2) {
  int pattern = 0;
  for (int dx = -1; dx < 2; dx++) {
    for (int dy = -1; dy < 2; dy++) {
      pattern <<= 1;
      if (map[(y + dy) * dg2->width + x + dx] == DG2_WALL) pattern |= 1;
    }
  }
  // Pattern bits look like this
  //    8         7        6       5        4       3        2       1       0
  // (-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 0), (0, 1), (1, -1), (1, 0), (1, 1)
  return pattern;
}


void dungeon2_cave_set_wall_ground(int x, int y, u8 *map, dungeon_generator2 *dg2) {
  u16 block;
  // Assemble a bitpattern for the adjacency to boost speed
  int pattern = dungeon2_cave_get_adjacency_pattern(x, y, map, dg2);
  int pattern_adjacent = pattern & (2 + 8 + 32 + 128);

  switch (pattern_adjacent) {
    case (2 + 8 + 32 + 128) : {
      // all adjacents are walls
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
      break;
    }
    // Three adjacent walls
    case (8 + 32 + 128) : { // (1, 0) missing
      block = 0x292 | BLOCK_SOLID;
      break;
    }
    case (2 + 32 + 128) : { // (0, 1) missing
      block = 0x299 | BLOCK_SOLID;
      break;
    }
    case (2 + 8 + 128) : { // (0, -1) missing
      block = 0x289 | BLOCK_SOLID;
      break;
    }
    case (2 + 8 + 32) : { // (-1, 0) missing
      block = 0x290 | BLOCK_SOLID;
      break;
    }
    // Two adjacent walls
    case (2 + 8) : { // Adjacency below and right
      block = 0x288 | BLOCK_SOLID;
      break;
    }
    case (8 + 128) : { // Adjacency below and left
      block = 0x28A | BLOCK_SOLID;
      break;
    }
    case (2 + 32) : { // Adjacency above and right
      block = 0x298 | BLOCK_SOLID;
      break;
    }
    case (32 + 128) : { // Adjacency above and left
      block = 0x29A | BLOCK_SOLID;
      break;
    }
    default : block = 0; // Should not happen
  }
  block_set_by_pos((s16)(x + 7), (s16)(y + 7), block);
}

void dungeon2_cave_set_wall_level(int x, int y, u8 *map, dungeon_generator2 *dg2) {
  u16 block;
  // Assemble a bitpattern for the adjacency to boost speed
  int pattern = dungeon2_cave_get_adjacency_pattern(x, y, map, dg2);
  int pattern_adjacent = pattern & (2 + 8 + 32 + 128);

  switch (pattern_adjacent) {
    case (2 + 8 + 32 + 128) : {
      // all adjacents are walls
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
      break;
    }
    // Three adjacent walls
    case (8 + 32 + 128) : { // (1, 0) missing
      block = 0x2C7 | BLOCK_SOLID;
      break;
    }
    case (2 + 32 + 128) : { // (0, 1) missing
      block = 0x2C4 | BLOCK_SOLID;
      break;
    }
    case (2 + 8 + 128) : { // (0, -1) missing
      block = 0x2A1 | BLOCK_SOLID;
      break;
    }
    case (2 + 8 + 32) : { // (-1, 0) missing
      block = 0x2C6 | BLOCK_SOLID;
      break;
    }
    // Two adjacent walls
    case (2 + 8) : { // Adjacency below and right
      block = 0x2A0 | BLOCK_SOLID;
      break;
    }
    case (8 + 128) : { // Adjacency below and left
      block = 0x2A2 | BLOCK_SOLID;
      break;
    }
    case (2 + 32) : { // Adjacency above and right
      block = 0x2C3 | BLOCK_SOLID;
      break;
    }
    case (32 + 128) : { // Adjacency above and left
      block = 0x2C5 | BLOCK_SOLID;
      break;
    }
    default : block = 0; // Should not happen
  }
  block_set_by_pos((s16)(x + 7), (s16)(y + 7), block);
}

void dungeon2_cave_set_wall_sand(int x, int y, u8 *map, dungeon_generator2 *dg2) {
  u16 block;
  // Assemble a bitpattern for the adjacency to boost speed
  int pattern = dungeon2_cave_get_adjacency_pattern(x, y, map, dg2);
  int pattern_adjacent = pattern & (2 + 8 + 32 + 128);

  switch (pattern_adjacent) {
    case (2 + 8 + 32 + 128) : {
      // all adjacents are walls
      if (!(pattern & 256)) { // nw missing
        block = 0x2F8;
      } else if (!(pattern & 64)) { //sw missing
        block = 0x300;
      } else if (!(pattern & 4)) { // no missing
        block = 0x2F9;
      } else if (!(pattern & 1)) { // so missing
        block = 0x301;
      } else {
        block = 0x2FC;
      }
      break;
    }
    // Three adjacent walls
    case (8 + 32 + 128) : { // (1, 0) missing
      block = 0x2FD;
      break;
    }
    case (2 + 32 + 128) : { // (0, 1) missing
      block = 0x304;
      break;
    }
    case (2 + 8 + 128) : { // (0, -1) missing
      block = 0x2F4;
      break;
    }
    case (2 + 8 + 32) : { // (-1, 0) missing
      block = 0x2FB;
      break;
    }
    // Two adjacent walls
    case (2 + 8) : { // Adjacency below and right
      block = 0x2F3;
      break;
    }
    case (8 + 128) : { // Adjacency below and left
      block = 0x2F5;
      break;
    }
    case (2 + 32) : { // Adjacency above and right
      block = 0x303;
      break;
    }
    case (32 + 128) : { // Adjacency above and left
      block = 0x305;
      break;
    }
    default : block = 0; // Should not happen
  }
  block_set_by_pos((s16)(x + 7), (s16)(y + 7), block);
}

void dungeon2_cave_set_wall(int x, int y, u8 *map, int type, dungeon_generator2 *dg2) {
  switch(type) {
  case WALL_SET_GROUND:
    dungeon2_cave_set_wall_ground(x, y, map, dg2);
    break;
  case WALL_SET_LEVEL:
    dungeon2_cave_set_wall_level(x, y, map, dg2);
    break;
  case WALL_SET_SAND:
    dungeon2_cave_set_wall_sand(x, y, map, dg2);
    break;
  }
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

  // First iterate over the entire map and find "problematic walls"
  for (int x = 0; x < dg2->width; x++) {
    for (int y = 0; y < dg2->height; y++) {
      if (x == 0 || x == dg2->width - 1 || y == 0 || y == dg2->height - 1) {
        // The border is ensured to be untouched
        block_set_by_pos((s16)(x + 7), (s16)(y + 7), 0x291 | BLOCK_SOLID);
        continue;
      }
      // Count wall neighbours in the cross neighbourhood
      if (map[y * dg2->width + x] == DG2_WALL ) {
        if(dungeon2_cave_wall_can_be_drawn(map, x, y, dg2)) {
          // Draw this wall right now
          dungeon2_cave_set_wall(x, y, map, type, dg2);
        } else {
          // Enqueue this wall as it can not be drawn
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
    //dprintf("Fixing (%d, %d)\n", x, y);
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

void dungeon2_cave_remove_walls(u8 *map, u8 *target, dungeon_generator2 *dg2) {
  for (int x = 1; x < dg2->width - 1; x++) {
    for (int y = 1; y < dg2->height - 1; y++) {
      target[y * dg2->width + x] = map[y * dg2->width + x];
      if (map[y * dg2->width + x] == DG2_WALL) {
        // Check if the this wall block is adjacent to space
        if (dungeon2_cave_get_adjacency_pattern(x, y, map, dg2) != 511) {
          // Remove it
          target[y * dg2->width + x] = DG2_SPACE;
        }
      }
    }
  }
}


void dungeon2_compute_blocks_cave(u8 *map, u8 *over, dungeon_generator2 *dg2){
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

    //u8 *map2 = malloc(sizeof(u8) * (size_t)(dg2->width * dg2->height));
  dungeon2_cave_draw_map(map, WALL_SET_GROUND, dg2);
  // Allocate a map that can be manipulated in order to remove walls
  u8 *map2 = malloc(sizeof(u8) * (size_t)(dg2->width * dg2->height));
  int _dg2_wall = DG2_WALL | (DG2_WALL << 8);
  cpuset(&_dg2_wall, map2, CPUSET_HALFWORD | CPUSET_FILL |
          CPUSET_HALFWORD_SIZE(dg2->width * dg2->height));
  dungeon2_cave_remove_walls(map, map2, dg2);
  dungeon2_cave_draw_map(map2, WALL_SET_LEVEL, dg2);
  dungeon2_cave_remove_walls(map2, map, dg2);
  dungeon2_cave_remove_walls(map, map2, dg2);
  dungeon2_cave_draw_map(map2, WALL_SET_LEVEL, dg2);
  free(map2);

  // Draw the sand
  dungeon2_cave_draw_map(over, WALL_SET_SAND, dg2);

}
