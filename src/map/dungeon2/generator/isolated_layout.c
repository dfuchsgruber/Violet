/*
 * isolated_layout.c
 *
 *  Created on: Aug 24, 2018
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

u8 *dungeon2_create_isolated_layout(dungeon_generator2 *dg2, int spread, size_t density,
		bool random_nodes, int exclude_node) {
  u8 *map1 = malloc(sizeof(u8) * (size_t)(dg2->width * dg2->height));
  u8 *map2 = malloc(sizeof(u8) * (size_t)(dg2->width * dg2->height));

  int _dg2_wall = DG2_WALL | (DG2_WALL << 8);
  cpuset(&_dg2_wall, map1, CPUSET_HALFWORD | CPUSET_FILL |
          ((dg2->width * dg2->height) / 2));
  cpuset(&_dg2_wall, map2, CPUSET_HALFWORD | CPUSET_FILL |
          ((dg2->width * dg2->height) / 2));

  int nodes[dg2->nodes][2];
  dungeon2_get_nodes(nodes, dg2->nodes, dg2, random_nodes);

  for (int i = 0; i < dg2->nodes; i++) {
	  // Set the node itself
	  if (i == exclude_node) continue;
	  int x = nodes[i][0], y = nodes[i][1];
	  map1[x + y * dg2->width] = DG2_SPACE;
	  // Sample arround the node
	  for (size_t j = 0; j < density; j++) {
		  int x2 = x + FIXED_TO_INT(FIXED_MUL(INT_TO_FIXED(spread), dungeon2_rnd_normal(dg2)));
		  int y2 = y + FIXED_TO_INT(FIXED_MUL(INT_TO_FIXED(spread), dungeon2_rnd_normal(dg2)));
		  x2 = MIN(MAX(1, x2), dg2->width - 2);
		  y2 = MIN(MAX(1, y2), dg2->height - 2);
		  map1[x2 + y2 * dg2->width] = DG2_SPACE;
	  }
  }

  // Enlarge
  dungeon2_enlarge(map1, map2, dg2);
  dungeon2_enlarge(map2, map1, dg2);
  dungeon2_enlarge(map1, map2, dg2);

  // If the second node was excluded explicitly clear it again (might be availible due to
  // enlargements)
  if (exclude_node < dg2->nodes) {
	  int x = nodes[exclude_node][0], y = nodes[exclude_node][1];
	  for (int dx = -1; dx < 2; dx++) {
		  for (int dy = -1; dy < 2; dy++) {
			  map2[x + dx + (y + dy) * dg2->width] = DG2_WALL;
		  }
	  }
  };

  // Contract
  dungeon2_contract(map2, map1, dg2);
  dungeon2_print_map(map1, dg2);

  free(map2);
  return map1;
}

