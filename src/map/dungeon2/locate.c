/*
 * locate.c
 *
 *  Created on: Jun 3, 2018
 *      Author: dominik
 */
#include "types.h"
#include "dungeon/dungeon2.h"


dungeon_location dungeon_locations[NUM_DUNGEON_LOCATIONS] = {
    {3, 0, 0x12, 0xC, DTYPE_FOREST}, // Anomia
    {3, 19, 0x2, 0x28, DTYPE_FOREST}, // Route 1
    {3, 19, 0x24, 0x1E, DTYPE_FOREST},
    {3, 19, 0x1F, 0x6, DTYPE_FOREST},

    {3, 41, 0x1F, 0x2B, DTYPE_FOREST}, // Route 2
    {3, 41, 0x2D, 0x13, DTYPE_FOREST},
    {3, 41, 0x20, 0x7, DTYPE_FOREST},
    {3, 41, 0x7, 0x8, DTYPE_FOREST},

    {15, 0, 0x9, 0x25, DTYPE_FOREST}, // Route 3
    {3, 3, 0x17, 0xE, DTYPE_FOREST} // Silvania,
    // TODO
};

int dungeon_get_location_index(u8 bank, u8 map, s16 x, s16 y, u8 type) {
  for(int i = 0; i < NUM_DUNGEON_LOCATIONS; i++) {
    if(type == DTYPE_FOREST) {
      // Either match direct coordinates or the one right to the coordinate (entrance is 2 tiles big)
      if(bank == dungeon_locations[i].bank && map == dungeon_locations[i].map &&
          (x == dungeon_locations[i].x || x == dungeon_locations[i].x + 1) &&
          y == dungeon_locations[i].y && type == dungeon_locations[i].type)
        return i;
    }
  }
  return -1;
}

