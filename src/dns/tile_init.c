#include "../header/types.h"
#include "../header/romfuncs.h"
#include "../header/rtc.h"
#include "../header/map.h"
#include "../header/color.h"
#include "../header/save.h"
#include "../header/battle.h"

void tile_init(mapfooter *foot){
	
	if (foot->tileset1 == &tilesets[0] && *vardecrypt(VAR_TIMEZONE) == 1){
		//Tileset1 = 0
		u16 *pal_save_copy = (u16*) 0x020371F8;
		pal_save_copy[0x21] = 0x33BF;
		pal_save_copy[0x22] = 0x33BF;
		pal_save_copy[0x25] = 0x333E;
	}
	
}
