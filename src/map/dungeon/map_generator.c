#include "../../header/dungeon_generator.h"
#include "../../header/map.h"
#include "../../header/save.h"
#include "../../header/types.h"
#include "../../header/romfuncs.h"
#include <stdbool.h>

/**Map header data 
typedef struct mapheader{
	mapfooter *footer;
	void *events;
	void *levelscripts;
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
	
}mapheader;
**/

mapheader *compute_dungeon_header();
mapfooter *compute_dungeon_footer();
map_events *compute_dungeon_events();


static map_connections null_connections = {0, NULL};

mapheader *compute_dungeon_header(){
	
	(*save1)->flash_circle_size = 2;
	
	if (dflags->header_initialized){
		return &(dmem->dhead);
	}else{
		
		dflags->header_initialized = 1;
		
		//build the dungoen generator
		dungeon_generator *generator = &(dmem->dgen);
		//generator->initial_seed = random_change_seed() | ((u32)(random_change_seed() << 16));
		generator->seed = generator->initial_seed;
		generator->width = 65;
		generator->height = 65;
		generator->rooms_per_line = 6;
		generator->rooms_per_row = 6;
		generator->room_frequency = 0x80;
		generator->min_rooms = 8;
		
		//We make the mapheader
		dmem->dhead.footer = compute_dungeon_footer(generator);
		dmem->dhead.events = compute_dungeon_events();
		dmem->dhead.levelscripts = (void*)0x871A220;
		dmem->dhead.connections = &null_connections;
		dmem->dhead.music = 0x136;
		dmem->dhead.map_index = 0x1c1; //test index
		dmem->dhead.name_bank = 0xc4; //test namebank
		dmem->dhead.flash = 2;
		dmem->dhead.weather = WEATHER_INSIDE;
		dmem->dhead.type = 0;
		dmem->dhead.show_name = 0;
		dmem->dhead.battle_style = 0;
		
		//return (mapheader*)0x8728D54;
		return &(dmem->dhead);
		
	}
}

static u16 border [4] = {0x32A, 0x32b, 0x32c, 0x32d};

mapfooter *compute_dungeon_footer(dungeon_generator *d){
	
	dmem->footer.width = d->width;
	dmem->footer.height = d->height;
	dmem->footer.border_blocks = &border;
	dmem->footer.map = (map_block*)0x892AD80;
	dmem->footer.tileset1 = (void*) 0x082D49B8;
	dmem->footer.tileset2 = (void*) 0x082D4B20;
	dmem->footer.border_width = 2;
	dmem->footer.border_height = 2;
	return &(dmem->footer);
	
}

static map_event_warp nullwarp = {0, 0, 0, 0, 0, 0};
static map_events nullevents = {
	0, 1, 0, 0,
	NULL,
	&nullwarp,
	NULL,
	NULL
};

map_events *compute_dungeon_events(){
	//For now we return a static event list
	//return (map_events*) 0x0876D920;
	return &nullevents;
}

