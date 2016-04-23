#include "../header/types.h"
#include "../header/romfuncs.h"
#include "../header/oams.h"
#include "../header/callbacks.h"
#include "../header/battle.h"
#include "../header/basestats.h"
#include "../header/trainer.h"
#include "../header/item.h"
#include "../header/save.h"
#include <stdbool.h>
#include "../header/unaligned_types.h"
#include "../header/pokemon.h"
#include "../header/map.h"
#include "dynamic_map.h"

extern mapheader *compute_dungeon_header();
extern void compute_dungeon_blocks();

mapheader *get_mapheader(u8 bank, u8 map);
mapfooter *get_mapfooter();
bool is_dungeon_map(u8 bank, u8 map);

mapheader *get_mapheader(u8 bank, u8 map){
	if(is_dungeon_map(bank, map)){
		//return (mapheader*)0x8350558;
		return compute_dungeon_header();
	}else{
		return ((*mapbank_table_ptr)[bank]).maps[map];
	}
}

mapfooter *get_mapfooter(){
	
	if(is_dungeon_map( (*save1)->bank, (*save1)->map)){
		compute_dungeon_blocks();
		return &(dmem->footer);
	}
	
	//return standard map header
	u16 current_footer = (*save1)->current_footer_id;
	if (current_footer){
		return ((*main_map_table_ptr)[current_footer - 1]);
	}
	return (mapfooter*)0;
}

bool is_dungeon_map(u8 bank, u8 map){
	return ((checkflag(FLAG_LOAD_DMAP)) && map == 10 && bank == 0);
}