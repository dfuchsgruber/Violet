/*
 * blocks.c
 *
 *  Created on: Aug 20, 2018
 *      Author: dominik
 */

#include "types.h"
#include "dungeon/dungeon2.h"
#include "dungeon/ocean.h"
#include "dungeon/cave.h"
#include "debug.h"
#include "agbmemory.h"
#include "bios.h"
#include "tile/block.h"
#include "data_structures.h"

#define COORDINATE_PACK(x,y) (((x) << 16) | (y))
#define COORDINATE_UNPACK_X(packed) ((packed >> 16) & 0xFFFF)
#define COORDINATE_UNPACK_Y(packed) (packed & 0xFFFF)

void dungeon2_ocean_set_wall_inner(int x, int y, u8 *map, dungeon_generator2 *dg2) {
	u16 block;
	// Assemble a bitpattern for the adjacency to boost speed
	int pattern = dungeon2_cave_get_adjacency_pattern(x, y, map, dg2);
	int pattern_adjacent = pattern & (2 + 8 + 32 + 128);

	switch (pattern_adjacent) {
		case (2 + 8 + 32 + 128) : {
			// all adjacents are walls
			if (!(pattern & 256)) { // nw missing
				block = 0xDC | BLOCK_SOLID;
			} else if (!(pattern & 64)) { //sw missing
				block = 0xD4 | BLOCK_SOLID;
			} else if (!(pattern & 4)) { // no missing
				block = 0xDB | BLOCK_SOLID;
			} else if (!(pattern & 1)) { // so missing
				block = 0xD3 | BLOCK_SOLID;
			} else {
				block = 0xD9 | BLOCK_SOLID;
			}
				break;
		}
		// Three adjacent walls
		case (8 + 32 + 128) : { // (1, 0) missing
			block = 0xDA | BLOCK_SOLID;
			break;
		}
		case (2 + 32 + 128) : { // (0, 1) missing
			block = 0xE1 | BLOCK_SOLID;
			break;
		}
		case (2 + 8 + 128) : { // (0, -1) missing
			block = 0x24C | BLOCK_SOLID;
			break;
		}
		case (2 + 8 + 32) : { // (-1, 0) missing
			block = 0xD8 | BLOCK_SOLID;
			break;
		}
		// Two adjacent walls
		case (2 + 8) : { // Adjacency below and right
			block = 0x24B | BLOCK_SOLID;
			break;
		}
		case (8 + 128) : { // Adjacency below and left
			block = 0x24D | BLOCK_SOLID;
			break;
		}
		case (2 + 32) : { // Adjacency above and right
			block = 0x238 | BLOCK_SOLID;
			break;
		}
		case (32 + 128) : { // Adjacency above and left
			block = 0x239 | BLOCK_SOLID;
			break;
		}
		default : block = 0; // Should not happen
	}
	block_set_by_pos((s16)(x + 7), (s16)(y + 7), block);
}

bool dungeon2_ocean_wall_cluster_placable(int x, int y, u8 *map, u8 *is_map_border,
		dungeon_generator2 *dg2) {
	if ((is_map_border[x + dg2->width * y] & DG2_OCEAN_IS_FIXED) ||
			(is_map_border[x + dg2->width * y + 1] & DG2_OCEAN_IS_FIXED) ||
			(is_map_border[x + dg2->width * (y + 1)] & DG2_OCEAN_IS_FIXED) ||
			(is_map_border[x + dg2->width * (y + 1) + 1] & DG2_OCEAN_IS_FIXED))
		return false;
	return map[x + dg2->width * y] == DG2_WALL && map[x + dg2->width * y + 1] == DG2_WALL &&
			map[x + dg2->width * (y + 1)] == DG2_WALL &&
			map[x + dg2->width * (y + 1) + 1] == DG2_WALL;
}

bool dungeon2_ocean_wall_cluster_place(int x, int y, u8 *map, u8 *is_map_border,
		dungeon_generator2 *dg2) {
	if (!dungeon2_ocean_wall_cluster_placable(x, y, map, is_map_border, dg2)) return false;
	// Fix the tiles
	is_map_border[x + dg2->width * y] |= DG2_OCEAN_IS_FIXED;
	is_map_border[x + dg2->width * y + 1] |= DG2_OCEAN_IS_FIXED;
	is_map_border[x + dg2->width * (y + 1)] |= DG2_OCEAN_IS_FIXED;
	is_map_border[x + dg2->width * (y + 1) + 1] |= DG2_OCEAN_IS_FIXED;

	// Place the wall cluster
	if (dungeon2_rnd_16(dg2) & 1) {
		// First kind of cluster
		block_set_by_pos((s16)(x + 7), (s16)(y + 7), 0x1F2);
		block_set_by_pos((s16)(x + 8), (s16)(y + 7), 0x1F3);
		block_set_by_pos((s16)(x + 7), (s16)(y + 8), 0x1FA);
		block_set_by_pos((s16)(x + 8), (s16)(y + 8), 0x1FB);
	} else {
		// Second kind of cluster
		block_set_by_pos((s16)(x + 7), (s16)(y + 7), 0x1F0);
		block_set_by_pos((s16)(x + 8), (s16)(y + 7), 0x1F1);
		block_set_by_pos((s16)(x + 7), (s16)(y + 8), 0x1F8);
		block_set_by_pos((s16)(x + 8), (s16)(y + 8), 0x1F9);
	}
	return true;
}

void dungeon2_ocean_set_wall_border(int x, int y, u8 *map, u8 *is_map_border,
		dungeon_generator2 *dg2)  {
	// Assemble a bitpattern for the adjacency to boost speed
	int pattern = dungeon2_cave_get_adjacency_pattern(x, y, map, dg2);
	int pattern_adjacent = pattern & (2 + 8 + 32 + 128);
	if (pattern_adjacent == 2 + 8 + 32 + 128) {
		// All 4 adjacenent walls are present
		block_set_by_pos((s16)(x + 7), (s16)(y + 7), 0x1CD);
	} else {
		// Try to place a rock cluster that includes this tile
		if (dungeon2_ocean_wall_cluster_place(x, y, map, is_map_border, dg2)) return;
		if (dungeon2_ocean_wall_cluster_place(x - 1, y, map, is_map_border, dg2)) return;
		if (dungeon2_ocean_wall_cluster_place(x, y - 1, map, is_map_border, dg2)) return;
		if (dungeon2_ocean_wall_cluster_place(x - 1, y - 1, map, is_map_border, dg2)) return;

	}
}

void dungeon2_ocean_set_wall(int x, int y, u8 *map, u8 *is_map_border, dungeon_generator2 *dg2) {
	if (!(is_map_border[x + dg2->width * y] & DG2_OCEAN_IS_FIXED)) {
		if (is_map_border[x + dg2->width * y] & DG2_OCEAN_IS_BORDER) {
			//dungeon2_ocean_set_wall_border(x, y, map, is_map_border, dg2);
			block_set_by_pos((s16)(x + 7), (s16)(y + 7), 1); // 0x1CD

		} else {
			dungeon2_ocean_set_wall_inner(x, y, map, dg2);
		}
	}
}

void dungeon2_ocean_draw_map(u8 *map, u8 *is_map_border, dungeon_generator2 *dg2) {

	// Initialize a queue for all walls that might be problematic
	ring_queue_t queue;
	ring_queue_new(&queue, (size_t)(dg2->width * dg2->height));

	// First iterate over the entire map and find "problematic walls"
	for (int x = 0; x < dg2->width; x++) {
		for (int y = 0; y < dg2->height; y++) {
			if (x == 0 || x == dg2->width - 1 || y == 0 || y == dg2->height - 1) {
				// The border is ensured to be untouched
				block_set_by_pos((s16)(x + 7), (s16)(y + 7) , 0x1CD | BLOCK_SOLID);
				continue;
			}
			// Count wall neighbours in the cross neighbourhood
			if (map[y * dg2->width + x] == DG2_WALL ) {
				if(dungeon2_cave_wall_can_be_drawn(map, x, y, dg2)) {
					// Draw this wall right now
					dungeon2_ocean_set_wall(x, y, map, is_map_border, dg2);
				} else {
					// Enqueue this wall as it can not be drawn
					ring_queue_enqueue(&queue, COORDINATE_PACK(x, y));
				}
			} else {
				// For the ocean there basically is no decoration whatsoever
				block_set_by_pos((s16)(x + 7), (s16)(y + 7), 0x1CD);
			}
		}
	}

	// Fix the walls that were enqueued
	while (!ring_queue_empty(&queue)) {
		int head = ring_queue_pop(&queue);
		int x = COORDINATE_UNPACK_X(head), y = COORDINATE_UNPACK_Y(head);
		//dprintf("Fixing (%d, %d)\n", x, y);
		// There are no 1-block rocks in the water tileset -> make them traversable as well
		block_set_by_pos((s16)(x + 7), (s16)(y + 7), 0x1CD);
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
						dungeon2_ocean_set_wall(x2, y2, map, is_map_border, dg2);
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

void dungeon2_ocean_flood_fill_borders(u8 *map, u8 *is_map_border, dungeon_generator2 *dg2) {
	// Use simple flood fill to determine walls that are connected with the map border
	int *stack = malloc_and_clear(sizeof(int) * (size_t)(dg2->width * dg2->height));
	int stack_size = 1;
	stack[0] = COORDINATE_PACK(0, 0);
	while (stack_size > 0) {
	  int packed = stack[--stack_size];
	  int x = COORDINATE_UNPACK_X(packed);
	  int y = COORDINATE_UNPACK_Y(packed);
	  if (map[y * dg2->height + x] == DG2_WALL &&
			  !(is_map_border[y * dg2->height + x] & DG2_OCEAN_IS_BORDER)) {
		  // dprintf("Flood fill %d, %d\n", x, y);
		  is_map_border[y * dg2->height + x] |= DG2_OCEAN_IS_BORDER;
		  for (int i = 0; i < 4; i++) {
			  int x2 = x + dg2_cross_neighbourhood[i][0];
			  int y2 = y + dg2_cross_neighbourhood[i][1];
			  if (x2 >= 0 && x2 < dg2->width && y >= 0 && y < dg2->height) {
				  stack[stack_size++] = COORDINATE_PACK(x2, y2);
			  }
		  }
	  }
	}
	free(stack);
}


void dungeon2_ocean_draw_border_cluster(int x, int y, u8 *map, u8 *is_map_border,
		dungeon_generator2 *dg2) {
	if (dungeon2_ocean_wall_cluster_place(x, y, map, is_map_border, dg2)) return;
	if (dungeon2_ocean_wall_cluster_place(x - 1, y, map, is_map_border, dg2)) return;
	if (dungeon2_ocean_wall_cluster_place(x, y - 1, map, is_map_border, dg2)) return;
	if (dungeon2_ocean_wall_cluster_place(x - 1, y - 1, map, is_map_border, dg2)) return;
}

void dungeon2_ocean_draw_border(u8 *map, u8 *is_map_border, dungeon_generator2 *dg2) {
	// Find a tile that represents a border wall adjacent to a traversable tile
	dungeon2_print_map(map, dg2);
	bool found_tile = false;
	int x_origin = -1, y_origin = -1;
	for (x_origin = 1 ; x_origin < dg2->width - 1; x_origin++) {
		for (y_origin = 1 ; y_origin < dg2->height - 1; y_origin++) {
			int pattern = dungeon2_cave_get_adjacency_pattern(x_origin, y_origin, map, dg2);
			if (pattern != 511 &&
					(is_map_border[x_origin + dg2->width * y_origin] & DG2_OCEAN_IS_BORDER)) {
				found_tile = true;
				break;
			}
		}
		if (found_tile) break;
	}

	// Start walking with right hand rule
	int x = x_origin, y = y_origin;
	int direction = 0;
	do {
		dprintf("Set border at %d, %d with adjacency %x\n", x, y, dungeon2_cave_get_adjacency_pattern(x, y, map, dg2));
		// Set this wall
		// block_set_by_pos((s16)(x + 7), (s16)(y + 7), 0);
		dungeon2_ocean_draw_border_cluster(x, y, map, is_map_border, dg2);

		// Step into these directions preferable: turn ccw > turn cw > straight > backtrack
		int turns[4] = {1, 2, 1, 2};

		for (int i = 0; i < 4; i++) {
			direction = (direction + turns[i]) % 4;
			dprintf("Checking direction %d at %d\n", direction, i);
			// Check if with current direction the next tile is also border adjacent to water
			int x_next = x + dg2_cross_neighbourhood[direction][0];
			int y_next = y + dg2_cross_neighbourhood[direction][1];
			if (dungeon2_cave_get_adjacency_pattern(x_next, y_next, map, dg2) != 511 &&
					(is_map_border[x_next + dg2->width * y_next] & DG2_OCEAN_IS_BORDER)) {
				dprintf("Turn at %d\n", i);
				x = x_next;
				y = y_next;
				break;
			}
		}
	} while (x != x_origin || y != y_origin);


}

void dungeon2_compute_blocks_ocean(u8 *map, u8 *over, dungeon_generator2 *dg2){
  (void)over;

  // Remove the walls in over
  for (int x = 0; x < dg2->width; x++) {
    for (int y = 0; y < dg2->height; y++) {
      // Switch the layout in over: spaces will become walls and vice versa (makes rendering the
      // isles in the water way easier). Also isles must not overlap with the walls of the actual
      // map
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

  // Drawing walls for the ocean:
  // First, as for the cave, remove cirtical wall patterns in the actual map, such that rocks can
  // be rendered. Walls connected to (0, 0) will be renderd with dark water and line of rocks
  // seperating them from the ocean.

  u8 *is_map_border = malloc_and_clear(sizeof(u8) * (size_t)(dg2->width * dg2->height));
  dungeon2_ocean_flood_fill_borders(map, is_map_border, dg2);

  // Now draw the map
  dungeon2_ocean_draw_map(map, is_map_border, dg2);

  // Draw the ring of rocks as border
  dungeon2_ocean_draw_border(map, is_map_border, dg2);


  /**
    //u8 *map2 = malloc(sizeof(u8) * (size_t)(dg2->width * dg2->height));
  dungeon2_cave_draw_map(map, WALL_SET_GROUND, dg2);
  // Allocate a map that can be manipulated in order to remove walls
  u8 *map2 = malloc(sizeof(u8) * (size_t)(dg2->width * dg2->height));
  int _dg2_wall = DG2_WALL | (DG2_WALL << 8);
  cpuset(&_dg2_wall, map2, CPUSET_HALFWORD | CPUSET_FILL |
          ((dg2->width * dg2->height) / 2));
  dungeon2_cave_remove_walls(map, map2, dg2);
  dungeon2_cave_draw_map(map2, WALL_SET_LEVEL, dg2);
  dungeon2_cave_remove_walls(map2, map, dg2);
  dungeon2_cave_remove_walls(map, map2, dg2);
  dungeon2_cave_draw_map(map2, WALL_SET_LEVEL, dg2);
  free(map2);
  **/

  // Draw the sand
  //dungeon2_cave_draw_map(over, WALL_SET_SAND, dg2);

}




