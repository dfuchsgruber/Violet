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
    u16 field_18;
    u8 show_name;
    u8 battle_style;

} mapheader;

int dungeon_get_type();

extern mapheader **mapbanks[];
mapheader *mapheader_virtual = (mapheader*)0x02036DFC;

mapheader *get_mapheader(u8 bank, u8 map);

#endif /* INCLUDE_C_MAP_HEADER_H_ */
