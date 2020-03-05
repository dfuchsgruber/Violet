#include "types.h"
#include "map/healing_place.h"
#include "worldmap.h"
#include "constants/healingplaces.h"

/**
 * Note how broken the vanilla implementation of the healing place system is:
 * The script command sethealingplace actually looks for the index in the flight_position table,
 * copies the data into the savefile and nothing else.
 * When whiteout is called the savefile data is used to retrieve the flight_position index and
 * this index - 1 ...
 * We simply copy this system and extra extend it by a table for positions to spawn the hiro at
 */

stru_healing_place healing_places[NUM_HEALING_PLACES] = {
    [HEALINGPLACE_AMONIA - 1] = {4, 0}, 
    [HEALINGPLACE_MERIANA_CITY - 1] = {5, 4}, 
    [HEALINGPLACE_AKTANIA - 1] = {6, 5}, 
    [HEALINGPLACE_SILVANIA_CITY - 1] = {7, 3}, 
    [HEALINGPLACE_KASKADA - 1] = {8, 0}, 
    [HEALINGPLACE_ORINA_CITY - 1] = {9, 1}, 
    [HEALINGPLACE_INFERIOR - 1] = {10, 12}, 
	[HEALINGPLACE_LAUBDORF - 1] = {12, 0}, 
	[HEALINGPLACE_CEOMETRIA - 1] = {19, 0}, 
	[HEALINGPLACE_HAWEILAND - 1] = {27, 3},
    [NUM_HEALING_PLACES - 1] = {0xFFFF, 0xFFFF}
};

u8 healing_place_target_persons[NUM_HEALING_PLACES] = {
    [HEALINGPLACE_AMONIA - 1] = 1,
    [HEALINGPLACE_MERIANA_CITY - 1] = 1,
    [HEALINGPLACE_AKTANIA - 1] = 3,
    [HEALINGPLACE_SILVANIA_CITY - 1] = 1,
    [HEALINGPLACE_KASKADA - 1] = 1,
    [HEALINGPLACE_ORINA_CITY - 1] = 1,
    [HEALINGPLACE_INFERIOR - 1] = 1,
	[HEALINGPLACE_LAUBDORF - 1] = 1,
	[HEALINGPLACE_CEOMETRIA - 1] = 1,
	[HEALINGPLACE_HAWEILAND - 1] = 1,
    [NUM_HEALING_PLACES - 1] = 0xFF
};

coordinate_t healing_place_target_coordinates[NUM_HEALING_PLACES] = {
		[HEALINGPLACE_AMONIA - 1] = {0x12, 0x6}, 
		[HEALINGPLACE_MERIANA_CITY - 1] = {0x7, 0x4}, 
		[HEALINGPLACE_AKTANIA - 1] = {0x7, 0x4}, 
		[HEALINGPLACE_SILVANIA_CITY - 1] = {0x7, 0x4}, 
		[HEALINGPLACE_KASKADA - 1] = {0x7, 0x4}, 
		[HEALINGPLACE_ORINA_CITY - 1] = {0x7, 0x4}, 
		[HEALINGPLACE_INFERIOR - 1] = {0x7, 0x4}, 
		[HEALINGPLACE_LAUBDORF - 1] = {0x7, 0x4}, 
		[HEALINGPLACE_CEOMETRIA - 1] = {0x7, 0x4}, 
		[HEALINGPLACE_HAWEILAND - 1] = {0x7, 0x4},
		[NUM_HEALING_PLACES - 1] = {-1, -1}
};

