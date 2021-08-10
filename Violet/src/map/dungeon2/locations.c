/*
 * locate.c
 *
 *  Created on: Jun 3, 2018
 *      Author: dominik
 */
#include "types.h"
#include "dungeon/dungeon2.h"
#include "save.h"
#include "tile/dungeon.h"
#include "tile/block.h"
#include "debug.h"
#include "vars.h"

dungeon_location dungeon_locations[NUM_DUNGEON_LOCATIONS] = {
	/*
    {3, 0, 0x25, 0xd, DTYPE_FOREST}, // Anomia
    {3, 19, 0x2, 0x28, DTYPE_FOREST}, // Route 1
    {3, 19, 0x24, 0x1E, DTYPE_FOREST},
    {3, 19, 0x1F, 0x6, DTYPE_FOREST},

    {3, 41, 0x1F, 0x4E, DTYPE_FOREST}, // Route 2
    {3, 41, 0x12, 0x24, DTYPE_FOREST},
    {3, 41, 0x20, 0x7, DTYPE_FOREST},
    {3, 41, 0x7, 0x8, DTYPE_FOREST},

    {15, 0, 0x9, 0x2C, DTYPE_FOREST}, // Route 3
    {3, 3, 0x17, 0xE, DTYPE_FOREST}, // Kranzdorf,
    {3, 74, 0x13, 0x4, DTYPE_FOREST}, // Feslige Oednis
    {3, 74, 0x8, 0x10, DTYPE_FOREST},

    {3, 22, 0x6, 0x26, DTYPE_FOREST}, // Route 4
    {3, 23, 0x3A, 0x10, DTYPE_FOREST}, // Route 5
    {3, 23, 0x20, 0x11, DTYPE_FOREST},
    {3, 23, 0x20, 0x1E, DTYPE_FOREST},

    {3, 1, 0x39, 0x6, DTYPE_CAVE}, // Meriana City
    {3, 74, 0x2E, 0x4, DTYPE_CAVE}, // Feslige Odenis
    {1, 59, 0x18, 0x1A, DTYPE_CAVE}, // Kuestenberg
    {3, 57, 0x34, 0x1F, DTYPE_FOREST}, // Trainerschule

    {3, 41, 0x2C, 0x14, DTYPE_CAVE}, // Route 2,
    {1, 0, 0x23, 0x2A, DTYPE_FOREST}, // Kranzwald
	{3, 74, 0x2F, 0x14, DTYPE_CAVE}, // Felsige Odenis
	{3, 4, 0x35, 0x3, DTYPE_CAVE}, // Kaskada

	{3, 1, 0xb, 0xd, DTYPE_CAVE}, // Meriana City
	{3, 41, 0x12, 0x54, DTYPE_OCEAN}, // Route 2
	{3, 41, 0x37, 0x22, DTYPE_CAVE},
	{3, 7, 0x4, 0x17, DTYPE_CAVE},

	{3, 7, 0x26, 0x4, DTYPE_CAVE},
	{3, 7, 0x45, 0xE, DTYPE_CAVE},
	{3, 8, 0x23, 0x28, DTYPE_FOREST}, // Route 8
	{3, 10, 0x4, 0x37, DTYPE_OCEAN}, // Route 9

	{3, 10, 0x1, 0x1f, DTYPE_OCEAN},
	{3, 11, 0x2, 0x8, DTYPE_OCEAN}, // Route 10
	{3, 11, 0x3, 0x16, DTYPE_OCEAN},
	{3, 11, 0x1, 0x26, DTYPE_OCEAN},

	{3, 11, 0x1, 0x44, DTYPE_OCEAN},
	{3, 11, 0x23, 0x1C, DTYPE_OCEAN},
	{3, 11, 0x25, 0x6, DTYPE_OCEAN},
	{3, 11, 0x22, 0x39, DTYPE_OCEAN},
	*/
    // TODO
};

void dungeon_map_set_tiles() {
	if (dungeon_get_type()) return;
	u8 current_bank = save1->bank;
	u8 current_map = save1->map;
	for (int i = 0; i < NUM_DUNGEON_LOCATIONS; i++) {
		if (dungeon_locations[i].bank == current_bank && dungeon_locations[i].map == current_map) {
			// Check if the dungeon is present with current a-vector
			if (!dungeon_flag_check(i)) {
				int x = dungeon_locations[i].x;
				int y = dungeon_locations[i].y;
				// Set the appropriate tiles
				if (dungeon_locations[i].type == DTYPE_FOREST) {
					// Forest: The coordinates are the left-bottom most tile of the entrance
					block_set_by_pos((s16)(x + 7), (s16)(y + 7), 0x25D | BLOCK_SOLID);
					block_set_by_pos((s16)(x + 8), (s16)(y + 7), 0x265 | BLOCK_SOLID);
					block_set_by_pos((s16)(x + 7), (s16)(y + 6), 0x266 | BLOCK_SOLID);
					block_set_by_pos((s16)(x + 8), (s16)(y + 6), 0x267 | BLOCK_SOLID);
				} else if (dungeon_locations[i].type == DTYPE_CAVE) {
					// Cave: The coordinates are the only tile
					block_set_by_pos((s16)(x + 7), (s16)(y + 7), 0x25F | BLOCK_SOLID);
				} else if (dungeon_locations[i].type == DTYPE_OCEAN) {
					// Ocean: The coordinates are the left-top most tile of the entrance
					block_set_by_pos((s16)(x + 7), (s16)(y + 7), 0x26E | BLOCK_SOLID);
					block_set_by_pos((s16)(x + 8), (s16)(y + 7), 0x26F | BLOCK_SOLID);
					block_set_by_pos((s16)(x + 7), (s16)(y + 8), 0x276 | BLOCK_SOLID);
					block_set_by_pos((s16)(x + 8), (s16)(y + 8), 0x277 | BLOCK_SOLID);

				} else {
					derrf("Unkown dungeon type to spawn %d\n", dungeon_locations[i].type);
				}
			}
		}
	}
}


int dungeon_get_location_idx(u8 bank, u8 map, s16 x, s16 y) {
	for(int i = 0; i < NUM_DUNGEON_LOCATIONS; i++) {
		if(dungeon_locations[i].type == DTYPE_FOREST) {
			// Either match direct coordinates or the one right to the coordinate
			//(entrance is 2 blocks big)
			if(bank == dungeon_locations[i].bank && map == dungeon_locations[i].map &&
					(x == dungeon_locations[i].x || x == dungeon_locations[i].x + 1) &&
					y == dungeon_locations[i].y)
			return i;
		} else if (dungeon_locations[i].type == DTYPE_CAVE) {
			// Only match the coordinates, the entrance is only 1 block big
			if(bank == dungeon_locations[i].bank && map == dungeon_locations[i].map &&
					x == dungeon_locations[i].x && y == dungeon_locations[i].y)
			return i;
		} else if (dungeon_locations[i].type == DTYPE_OCEAN) {
			if (bank == dungeon_locations[i].bank && map == dungeon_locations[i].map &&
					(x == dungeon_locations[i].x || x == dungeon_locations[i].x + 1) &&
					(y == dungeon_locations[i].y || y == dungeon_locations[i].y + 1)) {
				return i;
			}
		}
	}
	return -1;
}

int dungeon_get_location_idx_player_is_facing() {
	s16 coordinates[2];
	player_get_facing_position(&coordinates[0], &coordinates[1]);

	// Transform overworld coordinates to map coordinates
	coordinates[0] = (s16)(coordinates[0] - 7);
	coordinates[1] = (s16)(coordinates[1] - 7);
	return dungeon_get_location_idx(save1->bank, save1->map, coordinates[0],
			coordinates[1]);
}

int dungeon_map_entrance_get_type() {
	int dungeon_idx = dungeon_get_location_idx_player_is_facing();
	if (dungeon_idx == -1) {
		derrf("No dungeon matches the current entrance\n");
	}
	return dungeon_locations[dungeon_idx].type;
}

void dungeon_map_entrance_set_flag() {
	dprintf("Set flag for dungeon %d\n", *var_access(0x8000));
	dungeon_flag_set(*var_access(0x8000));
}


void dungeon2_seed_init() {
	u32 dungeon_idx = *var_access(0x8000);
	u32 seq[1] = {dungeon_idx};
	cmem.dg2.initial_seed = daily_events_hash(seq, 1);
	dprintf("Setup seed for dungeon %d to %d\n", dungeon_idx, cmem.dg2.initial_seed);
}
