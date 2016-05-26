#include "../header/types.h"
#include "../header/romfuncs.h"
#include "../header/rtc.h"
#include "../header/map.h"
#include "../header/color.h"
#include "../header/save.h"
#include "../header/battle.h"

void tile_init(mapfooter *foot){
	
	if (*vardecrypt(VAR_TIMEZONE) == 1){
		
		u16 *pal_save_copy = (u16*) 0x020371F8;
		
		if (foot->tileset1 == &tilesets[0]){
			//Tileset1 = 0
			pal_save_copy[0x21] = 0x377D;
			pal_save_copy[0x22] = 0x377D;
			pal_save_copy[0x25] = 0x1ABB;
		}
	}
}
