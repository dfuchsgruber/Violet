#ifndef H_DUNGEON_GENERATE
#define H_DUNGEON_GENERATE

#include "types.h"
#include "map.h"
#include <stdbool.h>

typedef struct room {
	u16 width;
	u16 height;
	s16 x;
	s16 y;
	s16 connector_x;
	s16 connector_y;
	bool expanded;
	bool presence;
	u8 roomx;
	u8 roomy;
	u8 region;
}room;

typedef struct dungeon_generator {
	u32 seed;
	u32 initial_seed;
	
	map_data *map;
	u16 width;
	u16 height;
	u16 rooms_per_line;
	u16 rooms_per_row;
	u8 room_frequency; //is devided by 256
	u8 min_rooms;
	room *rooms;
	u8 regions;
	u8 *dbuf;
	
	
}dungeon_generator;


typedef struct dungeon_data{
	
	u8 is_dungeon_generated;
	u8 room_frequency;
	u8 rooms_per_line;
	u8 rooms_per_row;
	u16 width;
	u16 height;
	u32 seed;
	
	
} dungeon_data;

typedef struct dungeon_flags{
	u8 header_initialized : 1;
	u8 blocks_initialized : 1;
	u8 other : 6;
} dungeon_flags;

dungeon_flags *dflags = (dungeon_flags*) 0x203CEC4;

#endif