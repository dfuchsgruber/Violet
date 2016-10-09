#include "types.h"
#include "romfuncs.h"
#include "rtc.h"
#include "map.h"
#include "color.h"
#include "save.h"
#include "battle.h"
#include "dns.h"


void battle_bg_load(u8 bg_id){
	
	lz77uncompvram(battle_bgs[bg_id].tileset, (void*)0x6008000);
	lz77uncompvram(battle_bgs[bg_id].tilemap, (void*)0x600D000);
	
	if (*vardecrypt(VAR_TIMEZONE) && dns_on()){
		
		color *buf = (color*)malloc(0x60);
		color *prebuf = (color*)0x02037ACC;
		lz77uncompwram(battle_bgs[bg_id].pal, prebuf);
		
		color over = dns_get_over();
		u8 alpha = dns_get_alpha();
		
		int i;
		for (i = 0; i < 0x30; i++){
			color original = prebuf[i];
			color new = blend_multiply(original, over, alpha);
			buf[i] = new;
		}
		
		load_uncomp_pal_into_RAM(buf, 0x20, 0x60);
		
		free(buf);
	}else{
		load_comp_pal_into_RAM(battle_bgs[bg_id].pal, 0x20, 0x60);
	}
}