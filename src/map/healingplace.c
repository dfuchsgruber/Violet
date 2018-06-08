#include "types.h"
#include "map/healing_place.h"

/**
 * Note how broken the vanilla implementation of the healing place system is:
 * The script command sethealingplace actually looks for the index in the flight_position table,
 * copies the data into the savefile and nothing else.
 * When whiteout is called the savefile data is used to retrieve the flight_position index and
 * this index - 2 is the number that is used to index healing_places...
 */

stru_healing_place healing_places[NUM_HEALING_PLACES] = {
    {4, 0}, // Healing place 2
    {5, 4}, // Healing place 3
    {6, 5}, // Healing place 4
    {7, 3}, // Healing place 5
    {8, 0}, // Healing place 6
    {9, 1}, // Healing place 7
    {10, 12}, // Healing place 8
    {0xFFFF, 0xFFFF}
};

u8 healing_place_target_persons[NUM_HEALING_PLACES] = {
    1, 1, 3, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0xFF
};
