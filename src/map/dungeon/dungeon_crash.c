#include "../../header/dungeon_generator.h"
#include "../../header/map.h"
#include "../../header/types.h"
#include "../../header/save.h"
#include "../../header/romfuncs.h"
#include "../../header/item.h"
#include "../../header/overworld_script.h"

extern bool is_dungeon_map(u8 bank, u8 map);

bool dungeon_crash();
void special_dungeon_warpback();

static u8 earthquake_script [] = {
	O_SCRIPT_SETVAR(0x8004, 3),
	O_SCRIPT_SETVAR(0x8005, 3),
	O_SCRIPT_SETVAR(0x8006, 35),
	O_SCRIPT_SETVAR(0x8007, 5),
	O_SCRIPT_SPECIAL(0x136),
	O_SCRIPT_MSGBOX(0x8810281, 6),
	O_SCRIPT_SPECIAL(0x16),
	O_SCRIPT_WAITSTATE,
	O_SCRIPT_END
};

bool dungeon_crash(){
	
	s16 coordinates[2];
	get_current_tile_position(&coordinates[0], &coordinates[1]);
	if (is_dungeon_map((*save1)->bank,(*save1)->map)){	
		if (((*vardecrypt(0x50E1))++ >= 2*(dmem->dgen.width + dmem->dgen.height)) ||
			get_block_info_behaviour(coordinates[0], coordinates[1]) == 0xB0){
			//init_script((void*)0x8719D01);
			init_script(&earthquake_script);
			return true;
		}
	}
	return false;
}

void special_dungeon_warpback(){
	
	warp_setup(dmem->dgen.from_bank, dmem->dgen.from_map, 0xFF, dmem->dgen.from_x, dmem->dgen.from_y);
	warp_setup_callbacks();
	script_wait_for_warp();
	
}