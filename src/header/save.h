#ifndef HSAVE
#define HSAVE
#include "map.h"
#include "dungeon_generator.h"


typedef struct saveblock1 {
	
	s16 x;
	s16 y;
	u8 bank;
	u8 map;
	u8 unkown[0x2A];
	u8 flash_circle_siize;
	u8 field_31;
	u16 current_footer_id;
	//TODO
	
	
}saveblock1;

typedef struct dungeon_memory{
	
	dungeon_data ddata;
	mapheader dhead;
	mapfooter footer;
	dungeon_generator dgen;
	
}dungeon_memory;


saveblock1 **save1 = (saveblock1**)0x03004F58;
dungeon_memory *dmem = (dungeon_memory*)0x0203C610;

#endif