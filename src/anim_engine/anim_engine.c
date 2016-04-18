#include "../header/types.h"
#include "../header/romfuncs.h"
#include "../header/oams.h"
#include "../header/callbacks.h"
#include <stdbool.h>


typedef struct memory {
	
	u16 current_frame;
	u32 current_programm;
	u8 link_numbers;
	u8 callback_id;
	bool active;
	u32 links [8];
	u16 lframes [8];
	u16 vars[16];
} memory;

typedef void (*cmd)(memory* mem);

/**
/ Method to initalize the callback
**/
extern void init_anim_engine();
void callback(u8 callback_id);
void execute_frame(memory* mem);
u8 read_byte(memory* mem);
u16 read_unaligned_hword_read_only(memory*mem);
u32 read_unaligned_word (memory* mem);
u16 read_unaligned_hword (memory* mem);
u16 read_param(memory* mem);
void render_tbox(u8 cbid);
void obj_move (u8 cbid);
void fade (u8 cb_id);


/**
/ Command Functions
**/
void cmdx00_end(memory* mem);
void cmdx01_call(memory* mem);
void cmdx02_jump(memory* mem);
void cmdx03_oam_new(memory* mem);
void cmdx04_oam_delete(memory* mem);
void cmdx05_oam_vram_load(memory* mem);
void cmdx06_oam_vram_free(memory* mem);
void cmdx07_oam_despawn(memory* mem);
void cmdx08_spawn_callback(memory* mem);
void cmdx09_bg_reset(memory* mem);
void cmdx0A_bg_setup(memory* mem);
void cmdx0B_bg_sync_and_show(memory* mem);
void cmdx0C_bg_hide(memory* mem);
void cmdx0D_bg_display_sync();
void cmdx0E_bg_override(memory* mem);
void cmdx0F_load_obj_pal (memory* mem);
void cmdx10_free_obj_pal(memory* mem);
void cmdx11_get_io(memory* mem);
void cmdx12_set_io_to_var(memory* mem);
void cmdx13_set_io_to_value(memory*mem);
void cmdx14_prepare_tbox (memory*mem);
void cmdx15_display_text_inst (memory*mem);
void cmdx16_clear_textbox (memory*mem);
void cmdx17_display_rendered_tbox (memory*mem);
void cmdx18_rendered_tbox_event (memory* mem);
void cmdx19_objmove (memory* mem);
extern void anim_engine_cmdx1A(memory* mem);
void cmdx1B_gfx_anim_set(memory*mem);
void cmdx1C_rs_anim_set (memory*mem);
void cmdx1D_loadpal (memory*mem);
void cmdx1E_fade (memory*mem);
void cmdx1F_invertcolors (memory* mem);
void cmdx20_sound (memory* mem);
void cmdx21_song (memory* mem);
void cmdx22_cry (memory* mem);


void init_anim_engine(){
	u8 callback_id = spawn_big_callback((void*)callback, 0);
	u32 callback_offset = (u32)(0x03004FE0 + 0x28*callback_id);
	
	(*((u32*)(callback_offset+0xC))) = (u32)(malloc_fill(sizeof(memory)));
	memory* mem = (*((memory**)(callback_offset+0xC)));
	
	//initalising values
	mem->current_programm = *((u32*)0x03000f14);
	mem->callback_id = callback_id;
	mem->active = true;
}

void callback(u8 callback_id){
	
	memory* mem = *((memory**)(0x03004FE0 + 0x28*callback_id+ + 0xC));	
	
	//programm read loop
	u16 keyframe = read_unaligned_hword_read_only (mem);
	while (keyframe == (mem->current_frame) && mem->active){
		
		//execution of the command with the related frame
		mem->current_programm = (u32)(mem->current_programm+2);
		execute_frame(mem);
		keyframe = read_unaligned_hword_read_only (mem);
	}
	if ((mem->active)==false){
		free(mem);
		return;
	}
	mem->current_frame = (u16)(mem->current_frame+1);
}

void execute_frame (memory* mem){
	
	static cmd cmdTable[] = {	cmdx00_end, 
								cmdx01_call, 
								cmdx02_jump,
								cmdx03_oam_new,
								cmdx04_oam_delete,
								cmdx05_oam_vram_load,
								cmdx06_oam_vram_free,
								cmdx07_oam_despawn,
								cmdx08_spawn_callback,
								cmdx09_bg_reset,
								cmdx0A_bg_setup,
								cmdx0B_bg_sync_and_show,
								cmdx0C_bg_hide,
								cmdx0D_bg_display_sync,
								cmdx0E_bg_override,
								cmdx0F_load_obj_pal,
								cmdx10_free_obj_pal,
								cmdx11_get_io,
								cmdx12_set_io_to_var,
								cmdx13_set_io_to_value,
								cmdx14_prepare_tbox,
								cmdx15_display_text_inst,
								cmdx16_clear_textbox,
								cmdx17_display_rendered_tbox,
								cmdx18_rendered_tbox_event,
								cmdx19_objmove,
								anim_engine_cmdx1A, // cmd_x1A_callasm function in Assembler Code
								cmdx1B_gfx_anim_set,
								cmdx1C_rs_anim_set,
								cmdx1D_loadpal,
								cmdx1E_fade,
								cmdx1F_invertcolors,
								cmdx20_sound,
								cmdx21_song,
								cmdx22_cry
								};
	u8 cmd_id = read_byte(mem);
	
	while (cmd_id != 0xFF){
		cmdTable[cmd_id](mem);
		cmd_id = read_byte(mem);
	}
}



/**
/ Read functions
**/

u8 read_byte (memory* mem){
	u8 result = (*((u8*)(mem->current_programm)));
	mem->current_programm = (u32)(mem->current_programm+1);
	return result;
}

u16 read_param (memory*mem){
	u16 result = read_unaligned_hword(mem);
	if ((u16)(result-0x8000) < 0x10){
		
		result = mem->vars[(u16)(result-0x8000)];
		
		//*((u16*)0x2000000) = result;
		//while(true){}
	}
	return result;
}

u32 read_unaligned_word (memory* mem){
	u32 result = (u32)(*((u8*)mem->current_programm));
	result = (u32)(result + (u32)((*(u8*)(mem->current_programm +1))<<0x8));
	result = (u32)(result + (u32)((*(u8*)(mem->current_programm +2))<<0x10));
	result = (u32)(result + (u32)((*(u8*)(mem->current_programm +3))<<0x18));
	mem->current_programm = (u32)(mem->current_programm+4);
	return result;
}

u16 read_unaligned_hword_read_only (memory* mem){
	
	u16 result = (u16)(*((u8*)mem->current_programm));
	result = (u16)(result + (u16)((*(u8*)(mem->current_programm +1))<<0x8));
	return result;
}

u16 read_unaligned_hword (memory*mem){
	
	u16 result = (u16)*((u8*)mem->current_programm);
	result = (u16)(result + (u32)((*(u8*)(mem->current_programm +1))<<0x8));
	mem->current_programm = (u32)(mem->current_programm+2);
	return result;
}




void cmdx00_end(memory* mem){
	if (mem->link_numbers == 0){
		//there are no links left -> engine is shut down
		mem->active = false;
		remove_big_callback(mem->callback_id);		
	}else{
		//there are links -> return to last element on link list
		mem->link_numbers = (u8)(mem->link_numbers-1);
		mem-> current_programm = mem->links[mem->link_numbers];
		mem-> current_frame = mem->lframes [mem->link_numbers];
	}
}

void cmdx01_call(memory* mem){
	u32 subscript = read_unaligned_word(mem);
	u16 new_frame = read_unaligned_hword(mem);
	
	if (mem->link_numbers<8){
		
		//saving the return adress and return frame
		mem->links[mem->link_numbers] = (mem->current_programm);
		mem->lframes[mem->link_numbers] = mem->current_frame;
		
		mem->link_numbers = (u8)(mem->link_numbers+1);
		mem->current_programm = subscript;
		mem->current_frame = new_frame;
		
	}
}

void cmdx02_jump(memory* mem){
	mem->current_programm = read_unaligned_word(mem);
	mem->current_frame = read_unaligned_hword(mem);
}

void cmdx03_oam_new(memory* mem){
	oam_template* template = (oam_template*)(read_unaligned_word(mem));
	s16 x = (s16)(read_unaligned_hword(mem));
	s16 y = (s16)(read_unaligned_hword(mem));
	u8 unkown = read_byte(mem);
	u16 target = (u16)(read_unaligned_hword(mem)-0x8000);
	
	//mem->vars[2] = target;
	//while(true){}
	
	//target var is 0x8000 min and 0x800F max
	if (target < 0x10){
		//*((u16*)0x2000000) = mem->vars[target];
		//while(true){}
		mem->vars[target] = generate_oam_forward_search(template, x, y, unkown);
	}
}

void cmdx04_oam_delete(memory* mem){
	
	u16 id = read_unaligned_hword(mem);
	
	if (id >= 0x8000){
		id = mem->vars[id-0x8000];
	}
	clear_oam_entry ((oam_object*)(id*0x44+0x0202063c));
}

void cmdx05_oam_vram_load(memory* mem){
	graphic* resource = (graphic*)read_unaligned_word(mem);
				
	//allocating vram
	load_and_alloc_obj_vram_lz77(resource);
}

void cmdx06_oam_vram_free(memory* mem){
	u16 oam_id = read_param(mem);
				
	//*((u16*)0x020370d0)=oam_id;
	//while (true){}
	
	oam_object* oam = (oam_object*)(oam_id*0x44+0x0202063c);
	//*((oam_object**)0x020370d0)=oam;
	//while (true){}
	free_obj_vram_by_object(oam);
}

void cmdx07_oam_despawn(memory* mem){
	u8 oam_id = (u8)read_param(mem);
	oam_object* oam = (oam_object*)(oam_id*0x44+0x0202063c);
	oam_despawn(oam);
}

void cmdx08_spawn_callback(memory* mem){
	void* function = (void*)read_unaligned_word(mem);
	u8 priority = read_byte(mem);
	u8 length = read_byte(mem);
	
	u8 cbid = spawn_big_callback(function, priority);
	big_callback* callback = (big_callback*)(0x03004FE0+cbid*0x28);
	
	//Adding params to the ram
	int i;
	for (i = 0; i<length; i++){
		callback->params[i] = read_unaligned_hword(mem);
	}
}

void cmdx09_bg_reset(memory* mem){
	bg_reset(read_byte(mem));
}

void cmdx0A_bg_setup(memory* mem){
	//command 0xA: bg_setup
	bg_setup(read_byte(mem), (void*)read_unaligned_word(mem), read_byte(mem));
}

void cmdx0B_bg_sync_and_show(memory* mem){
	//command 0xB: bg_sync_and_display
	bg_sync_display_and_show (read_byte(mem));
}

void cmdx0C_bg_hide(memory* mem){
	//command 0xC: bg_hide
	bg_hide(read_byte(mem));
}

void cmdx0D_bg_display_sync(){
	//Command 0xD: bg_display_sync
	bg_display_sync();
}

void cmdx0E_bg_override(memory* mem){
	//Command 0xE: bg_override_tilemap
	u8 bgid = read_byte(mem);
	void* graphic = (void*)read_unaligned_word(mem);
	u16 size = read_unaligned_hword(mem);
	u16 start = read_unaligned_hword(mem);
	u8 mode = read_byte(mem);
	
	
	void* buffer = (void*)malloc(size);
	lz77uncompwram (graphic, buffer);
	bg_copy_vram(bgid, buffer, size, start, mode);
	free(buffer);
}

void cmdx0F_load_obj_pal(memory* mem){
	
	u8 palid = allocate_obj_pal(read_unaligned_hword(mem));
	void* pal = (void*)read_unaligned_word(mem);
	u8 mode = read_byte(mem);
	if (palid!=0xFF){
		if (mode == 0){
			//copy only
			load_uncomp_pal_into_RAM(pal, (u16)(0x100+palid*0x10), 0x20);
		}else if (mode == 1){
			//lz77 decomp
			load_comp_pal_into_RAM(pal, (u16)(0x100+palid*0x10), 0x20);
		}		
	}
}

void cmdx10_free_obj_pal(memory* mem){
	free_obj_pal (read_unaligned_hword(mem));
}

void cmdx11_get_io(memory*mem){
	u16 var = (u16)(read_unaligned_hword(mem)-0x8000);
	u16 ioreg = read_unaligned_hword(mem);
	if (var<0x10){
		mem->vars[var] = get_io(ioreg);
		
	}
}

void cmdx12_set_io_to_var(memory*mem){
	u16 var = (u16)(read_unaligned_hword(mem)-0x8000);
	u16 ioreg = read_unaligned_hword(mem);
	if (var<0x10){
		set_io(ioreg, mem->vars[var]);
	}
}

void cmdx13_set_io_to_value(memory*mem){
	u16 val = read_unaligned_hword(mem);
	u16 ioreg = read_unaligned_hword(mem);
	set_io(ioreg, val);
}

void cmdx14_prepare_tbox(memory*mem){
	u16 target_var = (u16)(read_unaligned_hword(mem)-0x8000);
	u8 bgid = read_byte(mem);
	u8 x = read_byte(mem);
	u8 y = read_byte(mem);
	u8 w = read_byte(mem);
	u8 h = read_byte(mem);
	u8 palID = read_byte(mem);
	u16 startTile = read_unaligned_hword(mem);
	if (target_var < 0x10){
		u8 boxdata[8];
		translate_text_data_into_box(boxdata, bgid, x, y, w, h, palID, startTile);
		u8 boxid = spawn_tbox(boxdata);
		fill_box_bg(boxid, 0);
		prepeare_bg_for_tbox(boxid);
		mem->vars[target_var] = boxid;
	}
	
	
}

void cmdx15_display_text_inst (memory* mem){
	u8 boxid = (u8)read_param(mem);
	u8 font_id = read_byte(mem);
	u8 unkown = read_byte(mem);
	u8 border_distance = read_byte(mem);
	u8 line_distance_u = read_byte(mem);
	u8 line_distance_l = read_byte(mem);
	u8* font_map = (u8*)read_unaligned_word(mem);
	u8 display_flag = read_byte(mem);
	u8* string = (u8*)read_unaligned_word(mem);
	u8 bgid = read_byte(mem);
	
	//decrypting string
	u8* ram_buffer = (u8*)0x02021D18;
	string_decrypt(ram_buffer, string);
	
	fill_box_bg(boxid, 0);
	display_tbox_transbg(boxid, font_id, unkown, border_distance, line_distance_u, line_distance_l, font_map, display_flag, ram_buffer );
	bg_copy_vram(bgid, bg_get_tilemap(bgid), 0x800, 0x0, 0x2);
	
}

void cmdx16_clear_textbox (memory* mem){
	u8 boxid = (u8)read_param(mem);
	flush_tbox(boxid, 0);
	free_tbox(boxid);
	bg_copy_vram(0, bg_get_tilemap(0), 0x800, 0x0, 0x2);
}

void cmdx17_display_rendered_tbox (memory*mem){
	
	//reading all params
	u16 target_var = (u16)(read_unaligned_hword(mem)-0x8000);
	u8 boxid = (u8)read_param(mem);
	u8 text_speed = read_byte(mem);
	u8 font_id = read_byte(mem);
	u8 unkown = read_byte(mem);
	u8 border_distance = read_byte(mem);
	u8 line_distance_u = read_byte(mem);
	u8 line_distance_l = read_byte(mem);
	u8* font_map = (u8*)read_unaligned_word(mem);
	u8 display_flag = read_byte(mem);
	u8* string = (u8*)read_unaligned_word(mem);
	u8 bgid = read_byte(mem);
	
	if (target_var < 0x10){
		//decrypting string
		u8* buffer = (u8*)malloc (0x400);
		string_decrypt(buffer, string);
		
		u8 cbid = spawn_big_callback(render_tbox, 0);
		mem->vars[target_var] = cbid;
		int callback = 0x03004FE0 + 0x28*cbid;
		
		*((u8*)(callback+0x8)) = boxid;
		*((u8*)(callback+0x9)) = text_speed;
		*((u8*)(callback+0xa)) = font_id;
		*((u8*)(callback+0xb)) = unkown;
		*((u8*)(callback+0xc)) = border_distance;
		*((u8*)(callback+0xd)) = line_distance_u;
		*((u8*)(callback+0xe)) = line_distance_l;
		*((u8*)(callback+0xf)) = display_flag;
		*((u8**)(callback+0x10)) = font_map;
		*((u8**)(callback+0x14)) = buffer;
		//*((u8**)(callback+0x18)) = buffer;
		*((u8*)(callback+0x18)) = 0x0; // delay count
		*((u8*)(callback+0x19)) = 0x0; // flags
		*((u16*)(callback+0x1A)) = 0x0; //current position
		*((u8**)(callback+0x1C)) = buffer; //reference to the reseource
		*((u8*)(callback+0x20)) = bgid;
	}
}

void render_tbox(u8 cb_id){
	
	int callback = 0x03004FE0 + 0x28*cb_id;
	u8* boxid =(u8*)(callback+0x8);
	u8* text_speed = (u8*)(callback+0x9);
	u8* font_id = (u8*)(callback+0xA);
	u8* unkown = (u8*)(callback+0xB);
	u8* border_distance = (u8*)(callback+0xC);
	u8* line_distance_u = (u8*)(callback+0xD);
	u8* line_distance_l = (u8*)(callback+0xE);
	u8* display_flag = (u8*)(callback+0xF);
	u8** font_map = (u8**)(callback+0x10);
	u8** source = (u8**)(callback+0x14);
	u8* delay_cnt = (u8*)(callback+0x18);
	u8* flags = (u8*)(callback+0x19); //0,1,2 = wait n,p,end ; 3,4,5 = allowed n,p,end 
	u16* cur_pos = (u16*)(callback+0x1A);
	u8** resource = (u8**)(callback+0x1C);
	u8* bgid = (u8*)(callback+0x20);
	
	u8* buffer = (u8*)0x02021D18;

	
	if (*delay_cnt == 0){
		//delay is over -> render text
		
		//check for halt flags
		if ((((*flags)&0x1)!= 0x0) && (((*flags)&0x8)!= 0x0)){
			//wait n is set but we have token
			*flags = (u8)((*flags)&0xF6);
		}
		if ((((*flags)&0x2)!= 0x0) && (((*flags)&0x10)!= 0x0)){
			//wait p is set but we have token -> proceed to a new box
			*flags = (u8)((*flags)&0xED);
		}
		if ((((*flags)&0x4)!= 0x0) && (((*flags)&0x20)!= 0x0)){
			//wait end is set but we have token -> delete the box
			free(*resource);
			remove_big_callback(cb_id);
			flush_tbox(*boxid, 0);
			free_tbox(*boxid);
			bg_copy_vram(*bgid, bg_get_tilemap(*bgid), 0x800, 0x0, 0x2);
			return;
		}
		
		
		if (((*flags)&0x7) == 0){ //0000 0111 must be unset -> handle is not waiting
			
			u8 current_char = (*source)[*cur_pos];
			
			switch (current_char){
				case 0xFB:{
					//new box
					*flags = (u8)((*flags)|0x2); //set wait p flag
					*source = (u8*)(*source+(*cur_pos)+1);
					*cur_pos = 0x0;
					break;
				}
				case 0xFF:{
					//textbox has ended
					*flags = (u8)((*flags)|0x4); //set wait end flag
					break;
				}
				case 0xFE:{
					//next line
					*flags = (u8)((*flags)|0x1); //set wait n flag
					//do the normal copy request
				}
				default:{
					//normal copy request
					buffer[(*cur_pos)] = (*source)[(*cur_pos)];
					buffer[(*cur_pos)+1] = 0xFF;
					*cur_pos = (u16)(*cur_pos+1);
					
					//printing the new text
					fill_box_bg(*boxid, 0);
					display_tbox_transbg(*boxid, *font_id, *unkown, *border_distance, *line_distance_u, *line_distance_l, *font_map, *display_flag, buffer );
					bg_copy_vram(*bgid, bg_get_tilemap(*bgid), 0x800, 0x0, 0x2);
					
					//resetting delay
					*delay_cnt = *text_speed;
					break;
				}
			}
		}	
	}else{
		*delay_cnt = (u8)(*delay_cnt-1);
	}
}

void cmdx18_rendered_tbox_event (memory* mem){
	u8 target_cb = (u8)(read_param(mem));
	u8 event = (u8) (0x8 << read_byte(mem));
	
	int callback = (0x03004FE0 + 0x28*target_cb);
	u8* flags = (u8*)(callback+0x19); //0,1,2 = wait n,p,end ; 3,4,5 = allowed n,p,end 
	*flags = (u8)((*flags)|event);
}

void cmdx19_objmove(memory* mem){
	u8 oam_id = (u8)read_param(mem);
	u16 duration = read_unaligned_hword(mem);
	s16 x = (s16)(read_unaligned_hword(mem));
	s16 y = (s16)(read_unaligned_hword(mem));
	
	if (duration == 0){
		oam_object* oam = (oam_object*)(0x0202063c+oam_id*0x44);
		oam-> x = (u16)(oam->x + x);
		oam-> y = (u16)(oam->y + y);
	}else{
		//spawn a new callback
		u8 cbid = spawn_big_callback(obj_move, 1);
		big_callback* cb = (big_callback*)(0x03004FE0 + cbid*0x28);
		cb->params[0] = oam_id;
		cb->params[1] = (u16)x;
		cb->params[2] = (u16)y;
		cb->params[3] = duration;
		cb->params[4] = 0x0; //frame count
	}
}

void obj_move(u8 cbid){
	big_callback* cb = (big_callback*)(0x03004FE0 + cbid*0x28);
	u8 oam_id = (u8)(cb->params[0]);
	oam_object* oam = (oam_object*)(0x0202063c+oam_id*0x44);
	s16 x = (s16)(cb->params[1]);
	s16 y = (s16)(cb->params[2]);
	u16 d = cb->params[3];
	u16 t = cb->params[4];
	
	
	cb->params[4] = (u16)(t+1); //incrementing frame count 
	//calculating the movement in this frame by this formula mov_x(t) = x*t/d - (t-1)*x/d
	int x_mov = (x*t)/d - ((t-1)*x)/d;
	int y_mov = (y*t)/d - ((t-1)*y)/d;
	
	oam -> x = (u16)((oam -> x)+x_mov);
	oam -> y = (u16)((oam -> y)+y_mov);
	
	if (cb->params[4] == cb->params[3]){
		remove_big_callback(cbid);
	}
}

void cmdx1B_gfx_anim_set (memory* mem){
	u16 oam_id = read_param(mem);
	u8 anim_id = read_byte(mem);
	
	oam_object* oam = (oam_object*)(oam_id*0x44 + 0x0202063c);
	oam->anim_number = anim_id;
	gfx_init_animation (oam, 0);
	
	
}

void cmdx1C_rs_anim_set (memory* mem){
	u16 oam_id = read_param(mem);
	u8 anim_id = read_byte(mem);
	
	oam_object* oam = (oam_object*)(oam_id*0x44 + 0x0202063c);
	rotscal_new_animation (oam, anim_id);
	
}

void cmdx1D_loadpal (memory* mem){
	void* pal = (void*)read_unaligned_word(mem);
	u16 destcol = read_unaligned_hword(mem);
	u16 bytecount = read_unaligned_hword(mem);
	u8 cflag = read_byte(mem);	//compressed flag: if 0x1 data is compressed
	
	if (cflag != 0x0){
		//lz77
		load_comp_pal_into_RAM(pal, destcol, bytecount);
	}else{
		//not lz77
		load_uncomp_pal_into_RAM(pal, destcol, bytecount);
	}
}

void cmdx1E_fade (memory* mem){
	u16 color = read_unaligned_hword(mem);
	u16 dcol = read_unaligned_hword(mem);
	u16 ncol = read_unaligned_hword(mem);
	u16 duration = read_byte(mem);
	u8 bfade_flag = read_byte(mem);
	
	
	
	if (duration == 0){
		//instant fade
		if (bfade_flag == 0){
			color_blend(dcol, ncol, 0x10, color);
		}else{
			color_blend(dcol, ncol, 0x0, color);
		}
	}else{
		//initing a callback
		u8 cb_id = spawn_big_callback(fade, 1);
		big_callback* cb = (big_callback*)(0x03004FE0 + cb_id*0x28);
		cb->params[0] = color;
		cb->params[1] = dcol;
		cb->params[2] = ncol;
		cb->params[3] = duration;
		cb->params[4] = 0x0; //current frame
		cb->params[5] = bfade_flag;
	}	
}

void fade (u8 cb_id){
	//fading callback
	big_callback* cb = (big_callback*)(0x03004FE0 + cb_id*0x28);
	cb->params[4] = (u16)((cb->params[4])+1); //current frame
	
	u8 current_intensity = (u8)((cb->params[4]*0x10)/(cb->params[3]));
	
	if (cb->params[5] != 0){
		current_intensity = (u8)(0x10-current_intensity);
	}
	
	color_blend (cb->params[1], cb->params[2], current_intensity, cb->params[0]);
	
	if (cb->params[4] == cb->params[3]){
		remove_big_callback(cb_id);
	}
	
}

void cmdx1F_invertcolors (memory* mem){
	u16 startcol = read_unaligned_hword(mem);
	u16 ncol = read_unaligned_hword(mem);
	if (ncol != 0){
		u16* palcopyram = (u16*)0x020371F8;
		u16* palram = (u16*)0x020375F8;
		
		//start a inversion loop
		for (int i = startcol; i<ncol+startcol; i++){
			u16 oc = palcopyram[i];
			int red = 0x1F-(oc&0x1F);
			int blue = 0x3E0-(oc&0x3E0);
			int green = 0x7C00-(oc&0x7C00);
			palcopyram[i] = (u16)(red | blue | green);
			palram[i] = (u16)(red | blue | green);
		}
	}
}

void cmdx20_sound (memory* mem){
	u16 soundid = read_unaligned_hword(mem);
	sound(soundid);
}

void cmdx21_song (memory* mem){
	u16 songid = read_unaligned_hword(mem);
	u8 feature = read_byte(mem);
	playsong1(songid, feature);
}

void cmdx22_cry (memory* mem){
	u16 pokeid = read_unaligned_hword(mem);
	u8 feature = read_byte(mem);
	cry(pokeid, feature);
}

