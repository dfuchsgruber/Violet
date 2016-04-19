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

mapheader *get_map_events(u8 bank, u8 map);

mapheader *get_map_events(u8 bank, u8 map){
	if(checkflag(FLAG_LOAD_DMAP)){
		return (mapheader*) 0x835053C;
	}else{
		return ((*mapbank_table_ptr)[bank]).maps[map];
		
		
	}
}