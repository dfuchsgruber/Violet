#ifndef H_MAP_ROUTE_2_HOUSE
#define H_MAP_ROUTE_2_HOUSE

#include "types.h"

#define ROUTE_2_HOUSE_BANK 11
#define ROUTE_2_HOUSE_MAP 1

#define ROUTE_2_HOUSE_SPECIAL_ENCOUNTER_ODDS 35 // in 100

extern const struct {
    u16 species;
    u8 level;
    u8 probability;
} wild_pokemon_route_2_house_special_encounters[];

/**
 * Checks if the current map is the route 2 house.
 * @return true if the current map is the route 2 house, false otherwise
 */
bool map_is_route_2_house();

/**
 * Tries to initialize a special encounter for the route 2 house from a list of special encounters.
 * @return true if a special encounter was initialized, false otherwise
 */
bool wild_battle_route_2_house_initialize_special_encounter();

/**
 * Returns the index of a special encounter for the route 2 house.
 * @return in 0x8004 the index of a special encounter for the route 2 house
 */
void route_2_house_get_special_encounter_species();

#endif