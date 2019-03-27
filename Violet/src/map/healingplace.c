#include "types.h"
#include "map/healing_place.h"
#include "worldmap.h"

/**
 * Note how broken the vanilla implementation of the healing place system is:
 * The script command sethealingplace actually looks for the index in the flight_position table,
 * copies the data into the savefile and nothing else.
 * When whiteout is called the savefile data is used to retrieve the flight_position index and
 * this index - 1 ...
 * We simply copy this system and extra extend it by a table for positions to spawn the hiro at
 */

stru_healing_place healing_places[NUM_HEALING_PLACES] = {
    {4, 0}, // Healing place 1
    {5, 4}, // Healing place 2
    {6, 5}, // Healing place 3
    {7, 3}, // Healing place 4
    {8, 0}, // Healing place 5
    {9, 1}, // Healing place 6
    {10, 12}, // Healing place 7
	{12, 0}, // Healing place 8, Laubdorf
    {0xFFFF, 0xFFFF}
};

u8 healing_place_target_persons[NUM_HEALING_PLACES] = {
    1, 1, 3, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0xFF
};

coordinate_t healing_place_target_coordinates[NUM_HEALING_PLACES] = {
		{0x12, 0x6}, // Healing place 1
		{0x7, 0x4}, // Healing place 2
		{0x7, 0x4}, // Healing place 3
		{0x7, 0x4}, // Healing place 4
		{0x7, 0x4}, // Healing place 5
		{0x7, 0x4}, // Healing place 6
		{0x7, 0x4}, // Healing place 7
		{0x7, 0x4}, // Healing place 8, Laubdorf
		{-1, -1}
};

