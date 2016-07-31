#ifndef HSAVE
#define HSAVE
#include "map.h"
#include "dungeon_generator.h"
#include "rtc.h"
#include "pokepad.h"


typedef struct saveblock1 {
	
	s16 x;
	s16 y;
	u8 bank;
	u8 map;
        u8 unkown_0[0x16];
        s8 healingplace_bank;
        u8 healingplace_map;
	u8 unkown_1[0x6];
        u8 last_outdoor_bank;
        u8 last_outdoor_map;
        u8 unkown[0xA];
	u8 flash_circle_size;
	u8 field_31;
	u16 current_footer_id;
	//TODO
	
	
}saveblock1;

typedef struct saveblock2{
    
    u8 unkown[0x13];
    u8 detector_state; //original key swtiching
    u8 text_speed;
    u8 sound_state : 1;
    u8 unkown_2 : 7;
} saveblock2;

typedef struct custom_memory{
	
	//dungeon_data ddata;
	mapheader dhead;
	mapfooter footer;
	dungeon_generator dgen;
	map_events devents;
	map_event_warp ladder;
	map_event_person dpers[5];
        
        //trash memory (generall a vector memory)
	u8 trash_flags[16];
        rtc_timestamp a_gen_time;
        u8 a_vector[4];
        pokepad_memory *pad_mem;
	
}custom_memory;


saveblock1 **save1 = (saveblock1**)0x03004F58;
saveblock2 **save2 = (saveblock2**)0x03004F5C;
custom_memory *cmem = (custom_memory*)0x0203C610;

#endif