#include "types.h"
#include "map/healing_place.h"
#include "worldmap.h"
#include "constants/healingplaces.h"

/**
 * Healingplaces are associated with flight positions (or rather vice versa).
 * That is, when sethealingplace is called, the information of the flight position associated
 * with the healing place is saved.
 * When the player whites out or uses Teleport, this flight position is then used to retrieve
 * the healing place idx back. The structs listed in this file then describe to which map
 * and position and target person the player is warped.
 **/


// The namespace -> worldmapflag association is hardcoded unfortunately...
stru_flight_position flight_positions[NUM_HEALING_PLACES] = {
    // bank, map, x, y, d
    [HEALINGPLACE_AMONIA - 1] = {3, 0, 0xe, 0x10, 0}, // Amonia
    [HEALINGPLACE_MERIANA_CITY - 1] = {3, 1, 72, 29, 0}, // Meriana City
    [HEALINGPLACE_AKTANIA - 1] = {3, 2, 0x1f, 0x28, 0}, // Bruchfels
    [HEALINGPLACE_SILVANIA_CITY - 1] = {3, 3, 0x1c, 0xA, 0}, // Kranzdorf
    [HEALINGPLACE_KASKADA - 1] = {3, 4, 0x2f, 0x2e, 0}, // Kaskada
    [HEALINGPLACE_ORINA_CITY - 1] = {3, 5, 31, 37, 0}, // Orina City
    [HEALINGPLACE_INFERIOR - 1] = {3, 6, 28, 17, 0}, // Inferior
    [HEALINGPLACE_CEOMETRIA - 1] = {3, 13, 0x13, 0x12, 0}, // Ceometria
    [HEALINGPLACE_LAUBDORF - 1] = {3, 9, 0x13, 0x2b, 0}, // Laubkind-Dorf
    [HEALINGPLACE_HAWEILAND - 1] = {3, 17, 0x1e, 0x15, 0}, // Haweiland
    [HEALINGPLACE_BBSHIP - 1] = {33, 0, 3, 5, 0}, // Shouldn't be able to fly there though...
    [HEALINGPLACE_TANNS_LAB - 1] = {3, 25, 0x8, 0x22, 0}, // Tann's Lab
    [HEALINGPLACE_DESERT - 1] = {3, 26, 0x15, 0x27, 0},
    [NUM_HEALING_PLACES - 1] = {0xFF, 0xFF, 0, 0, 0}
};


/**
 * Note how broken the vanilla implementation of the healing place system is:
 * The script command sethealingplace actually looks for the index in the flight_position table,
 * copies the data into the savefile and nothing else.
 * When whiteout is called the savefile data is used to retrieve the flight_position index and
 * this index - 1 ...
 * We simply copy this system and extra extend it by a table for positions to spawn the hiro at
 */

stru_healing_place_map healing_place_maps[NUM_HEALING_PLACES] = {
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
    [HEALINGPLACE_BBSHIP - 1] = {33, 0},
    [HEALINGPLACE_TANNS_LAB - 1] = {35, 0},
    [HEALINGPLACE_DESERT - 1] = {37, 0},
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
    [HEALINGPLACE_BBSHIP - 1] = 0xFF,
    [HEALINGPLACE_TANNS_LAB - 1] = 1,
    [HEALINGPLACE_DESERT - 1] = 1,
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
        [HEALINGPLACE_BBSHIP - 1] = {3, 5},
        [HEALINGPLACE_TANNS_LAB - 1] = {0x7, 0x4},
        [HEALINGPLACE_DESERT - 1] = {7, 4},
		[NUM_HEALING_PLACES - 1] = {-1, -1}
};

