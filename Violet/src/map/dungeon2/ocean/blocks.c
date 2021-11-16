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

#define WALL_SET_GROUND 0
#define WALL_SET_SAND 1

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
	block_set_by_pos_with_level((s16)(x + 7), (s16)(y + 7), block);
}


void dungeon2_ocean_set_wall_sand(int x, int y, u8 *map, dungeon_generator2 *dg2) {
	u16 block;
	// Assemble a bitpattern for the adjacency to boost speed
	int pattern = dungeon2_cave_get_adjacency_pattern(x, y, map, dg2);
	int pattern_adjacent = pattern & (2 + 8 + 32 + 128);

	switch (pattern_adjacent) {
		case (2 + 8 + 32 + 128) : {
			// all adjacents are walls
			if (!(pattern & 256)) { // nw missing
				block = 0x1E3 | 0x3000;
			} else if (!(pattern & 64)) { //sw missing
				block = 0x1EB | 0x3000;
			} else if (!(pattern & 4)) { // no missing
				block = 0x1E4 | 0x3000;
			} else if (!(pattern & 1)) { // so missing
				block = 0x1EC | 0x3000;
			} else {
				if (!(dungeon2_rnd_16(dg2) & 63)) {
					block = 0x1E1 | 0x3000;
				} else {
					block = 0x1C9 | 0x3000;
				}
			}
				break;
		}
		// Three adjacent walls
		case (8 + 32 + 128) : { // (1, 0) missing
			block = 0x1E2 | 0x3000;
			break;
		}
		case (2 + 32 + 128) : { // (0, 1) missing
			block = 0x1E9 | 0x3000;
			break;
		}
		case (2 + 8 + 128) : { // (0, -1) missing
			block = 0x1D9 | 0x3000;
			break;
		}
		case (2 + 8 + 32) : { // (-1, 0) missing
			block = 0x1E0 | 0x3000;
			break;
		}
		// Two adjacent walls
		case (2 + 8) : { // Adjacency below and right
			block = 0x1D8 | 0x3000;
			break;
		}
		case (8 + 128) : { // Adjacency below and left
			block = 0x1DA | 0x3000;
			break;
		}
		case (2 + 32) : { // Adjacency above and right
			block = 0x1E8 | 0x3000;
			break;
		}
		case (32 + 128) : { // Adjacency above and left
			block = 0x1EA | 0x3000;
			break;
		}
		default : block = 0; // Should not happen
	}
	block_set_by_pos_with_level((s16)(x + 7), (s16)(y + 7), block);
}

void dungeon2_ocean_set_wall(int x, int y, u8 *map, u8 *is_map_border, int type,
		dungeon_generator2 *dg2) {
	switch (type) {
		case WALL_SET_GROUND : {
			if (!(is_map_border[x + dg2->width * y] & DG2_OCEAN_IS_FIXED)) {
				if (is_map_border[x + dg2->width * y] & DG2_OCEAN_IS_BORDER) {
					//dungeon2_ocean_set_wall_border(x, y, map, is_map_border, dg2);
					block_set_by_pos_with_level((s16)(x + 7), (s16)(y + 7), 0x1CD | 0x1000);

				} else {
					dungeon2_ocean_set_wall_inner(x, y, map, dg2);
				}
			}
			break;
		}
		case WALL_SET_SAND : {
			dungeon2_ocean_set_wall_sand(x, y, map, dg2);
		}
	}
}

void dungeon2_ocean_draw_map(u8 *map, u8 *is_map_border, int type, dungeon_generator2 *dg2) {

	// Initialize a queue for all walls that might be problematic
	ring_queue_t queue;
	ring_queue_new(&queue, (size_t)(dg2->width * dg2->height));

	// First iterate over the entire map and find "problematic walls"
	for (int x = 0; x < dg2->width; x++) {
		for (int y = 0; y < dg2->height; y++) {
			if (x == 0 || x == dg2->width - 1 || y == 0 || y == dg2->height - 1) {
				// The border is ensured to be untouched
				if (type == WALL_SET_GROUND) {
					block_set_by_pos_with_level((s16)(x + 7), (s16)(y + 7) , 0x1CD | BLOCK_SOLID);
				}
				continue;
			}
			// Count wall neighbours in the cross neighbourhood
			if (map[y * dg2->width + x] == DG2_WALL ) {
				if(dungeon2_cave_wall_can_be_drawn(map, x, y, dg2)) {
					// Draw this wall right now
					dungeon2_ocean_set_wall(x, y, map, is_map_border, type, dg2);
				} else {
					// Enqueue this wall as it can not be drawn
					ring_queue_enqueue(&queue, COORDINATE_PACK(x, y));
				}
			} else {
				if (type == WALL_SET_GROUND) {
					// For the ocean there basically is no decoration whatsoever
					block_set_by_pos_with_level((s16)(x + 7), (s16)(y + 7), 0x1CD | 0x1000);
				}
			}
		}
	}

	// Fix the walls that were enqueued
	while (!ring_queue_empty(&queue)) {
		int head = ring_queue_pop(&queue);
		int x = COORDINATE_UNPACK_X(head), y = COORDINATE_UNPACK_Y(head);
		//DEBUG("Fixing (%d, %d)\n", x, y);
		// There are no 1-block rocks in the water tileset -> make them traversable as well
		block_set_by_pos_with_level((s16)(x + 7), (s16)(y + 7), 0x1CD | 0x1000);
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
						dungeon2_ocean_set_wall(x2, y2, map, is_map_border, type, dg2);
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
		  // DEBUG("Flood fill %d, %d\n", x, y);
		  is_map_border[y * dg2->height + x] |= DG2_OCEAN_IS_BORDER;
		  for (int i = 0; i < 4; i++) {
			  int x2 = x + dg2_cross_neighbourhood[i][0];
			  int y2 = y + dg2_cross_neighbourhood[i][1];
			  if (x2 >= 0 && x2 < dg2->width && y >= 0 && y < dg2->height) {
				  stack[stack_size++] = COORDINATE_PACK(x2, y2);
				  // DEBUG("Stack size %d\n", stack_size);
			  }
		  }
	  }
	}
	free(stack);
}


void dungeon2_ocean_draw_border(u8 *map, u8 *is_map_border, dungeon_generator2 *dg2) {
	(void)map;
	for (int x = 0; x < dg2->width; x+=2) {
		for (int y = 0; y < dg2->height; y+=2) {
			// Check if one adjacent cluster contains non-borders
			bool has_adjacent_non_borders = false;
			for (int i = 0; i < 4; i++) {
				int x2 = x + 2 * dg2_cross_neighbourhood[i][0];
				int y2 = y + 2 * dg2_cross_neighbourhood[i][1];
				if (x2 >= 0 && y2 >= 0 && x2 < dg2->width - 1 && y2 < dg2->height - 1) {
					// Check only the root (cluster should be aligned now)
					if (!(is_map_border[x2 + y2 * dg2->width] & DG2_OCEAN_IS_BORDER)) {
						has_adjacent_non_borders = true;
					}
				}
			}
			if (has_adjacent_non_borders &&
					(is_map_border[x + y * dg2->width] & DG2_OCEAN_IS_BORDER)) {
				// Draw a rock cluster
				if (dungeon2_rnd_16(dg2) & 1) {
					// First kind of cluster
					block_set_by_pos_with_level((s16)(x + 7), (s16)(y + 7), 0x1F2 | 0x400);
					block_set_by_pos_with_level((s16)(x + 8), (s16)(y + 7), 0x1F3 | 0x400);
					block_set_by_pos_with_level((s16)(x + 7), (s16)(y + 8), 0x1FA | 0x400);
					block_set_by_pos_with_level((s16)(x + 8), (s16)(y + 8), 0x1FB | 0x400);
				} else {
					// Second kind of cluster
					block_set_by_pos_with_level((s16)(x + 7), (s16)(y + 7), 0x1F0 | 0x400);
					block_set_by_pos_with_level((s16)(x + 8), (s16)(y + 7), 0x1F1 | 0x400);
					block_set_by_pos_with_level((s16)(x + 7), (s16)(y + 8), 0x1F8 | 0x400);
					block_set_by_pos_with_level((s16)(x + 8), (s16)(y + 8), 0x1F9 | 0x400);
				}
			}
		}
	}

}

void dungeon2_ocean_align_border(u8 *map, u8 *is_map_border, dungeon_generator2 *dg2) {
	for (int x = 0; x < dg2->width; x+=2) {
		for (int y = 0; y < dg2->height; y+=2) {
			int num_border_walls = 0;
			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 2; j++) {
					if ((is_map_border[x + i + (y + j) * dg2->width] & DG2_OCEAN_IS_BORDER)
							&& (map[x + i + (y + j) * dg2->width] == DG2_WALL)) {
						num_border_walls++;
					}
				}
			}
			// Check if the cluster is full
			if (num_border_walls < 4) {
				for (int i = 0; i < 2; i++) {
					for (int j = 0; j < 2; j++) {
						if (num_border_walls > 0) {
							// Remove map walls
							map[x + i + (y + j) * dg2->width] = DG2_ROCK;
						}
						is_map_border[x + i + (y + j) * dg2->width] &=
								(u8)(~DG2_OCEAN_IS_BORDER);
					}
				}
			}

		}
	}
}

void dungeon2_ocean_clear_nodes(u8 *map, dungeon_generator2 *dg2) {
	  int nodes[dg2->nodes][2];
	  dungeon2_get_nodes(nodes, dg2->nodes, dg2, false);
	  for (int i = 0; i < dg2->nodes; i++) {
		  for (int dx = -1; dx < 2; dx++) {
			  for (int dy = -1; dy < 2; dy++) {
				  int x = nodes[i][0] + dx;
				  int y = nodes[i][1] + dy;
				  if (x >= 1 && x < dg2->width - 1 && y >= 1 && y < dg2->height - 1) {
					  map[x + y * dg2->width] = DG2_SPACE;
				  }
			  }
		  }
	  }
}

void dungeon2_compute_blocks_ocean(u8 *map, u8 *over, dungeon_generator2 *dg2){
  (void)over;

  // dungeon2_print_map(map, dg2);

  // Remove walls that are in the 3x3 neighbourhood of nodes
  dungeon2_ocean_clear_nodes(map, dg2);

  // dungeon2_print_map(map, dg2);

  // Drawing walls for the ocean:
  // First, as for the cave, remove cirtical wall patterns in the actual map, such that rocks can
  // be rendered. Walls connected to (0, 0) will be renderd with dark water and line of rocks
  // seperating them from the ocean.

  u8 *is_map_border = malloc_and_clear(sizeof(u8) * (size_t)(dg2->width * dg2->height));
  dungeon2_ocean_flood_fill_borders(map, is_map_border, dg2);

  // Now draw the map
  dungeon2_ocean_draw_map(map, is_map_border, WALL_SET_GROUND, dg2);

  // dungeon2_print_map(map, dg2);
  // dungeon2_print_map(is_map_border, dg2);

  dungeon2_ocean_align_border(map, is_map_border, dg2);

  // dungeon2_print_map(is_map_border, dg2);
  // dungeon2_print_map(map, dg2);

  // Draw the ring of rocks as border
  dungeon2_ocean_draw_border(map, is_map_border, dg2);

  // dungeon2_print_map(map, dg2);
  // dungeon2_print_map(over, dg2);

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

  dungeon2_print_map(over, dg2);

  dungeon2_ocean_draw_map(over, is_map_border, WALL_SET_SAND, dg2);
}




