#include "../header/types.h"
#include "../header/romfuncs.h"
#include "../header/rtc.h"
#include "../header/map.h"
#include "../header/color.h"

void dns_blend_colors(u16 start_col, u16 col_cnt, color overlay, u8 alpha);

void dns_apply_shaders(u16 start_col, u16 col_cnt){
	
	u16 timezone = *vardecrypt(VAR_TIMEZONE);
	if (timezone){
		
		u16 o = 0;
		u8 alpha = 0;
		switch(timezone){
			case 1:{
				alpha = 9;
				o = 0x2c20;
				break;
			}
		}
		
		color overlay = {o};
		dns_blend_colors(start_col, col_cnt, overlay, alpha);
			
		
	}
	
}


void dns_blend_colors(u16 start_col, u16 col_cnt, color overlay, u8 alpha){
	
	u16 *pal_save_copy = (u16*) 0x020371F8;
	u16 end_col = (u16)(start_col + col_cnt);
	while(start_col < end_col){
		u16 original = pal_save_copy[start_col];
		color c_original = {original};
		color new = alpha_blend(c_original, overlay, alpha);
		pal_save_copy[start_col] = new.value;
		start_col++;
	}
}