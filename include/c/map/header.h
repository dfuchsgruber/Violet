/*
 * header.h
 *
 *  Created on: Mar 28, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_MAP_HEADER_H_
#define INCLUDE_C_MAP_HEADER_H_

#include "map/footer.h"
#include "map/levelscript.h"
#include "map/connection.h"
#include "map/header.h"
#include "map/event.h"

typedef struct mapheader {
    mapfooter *footer;
    map_events *events;
    levelscript_head *levelscripts;
    map_connections *connections;
    u16 music;
    u16 map_index; //main table is used when map is loaded
    u8 name_bank;
    u8 flash;
    u8 weather;
    u8 type;
    u8 worldmap_shape_id; // Used to associate the map with a shape in the worldmap pattern of the namespace
    u8 field_19;
    u8 show_name;
    u8 battle_style;

} mapheader;

int dungeon_get_type();

extern mapheader **mapbanks[];
extern mapheader mapheader_virtual;

/**
 * Gets a mapheader by the current bank and map id
 * @param bank the desired bank
 * @param map the desired map id
 * @return the mapheader object
 */
mapheader *get_mapheader(u8 bank, u8 map);

/**
 * Checks if the current map is 40.0
 * @return if the current map is in bank 40 the and has map id 0
 */
bool map_is_x40_x0();

/**
 * Returns the idx of a warp on a certain map or -1 if there is no warp.
 * @param map the map to check on
 * @param position the position where the warp is required to be
 * @return the warp idx or -1 if there is no warp
 */
s8 map_get_warp_idx_by_position(mapheader *map, position_t *position);

/**
 * Checks if a map type represents an outside map.
 * @param map_type the map type
 * @return if the map represents an outside map
 */
bool map_type_is_outside (u8 map_type);

#endif /* INCLUDE_C_MAP_HEADER_H_ */
