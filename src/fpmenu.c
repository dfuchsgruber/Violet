#include "types.h"
#include "romfuncs.h"
#include "oams.h"
#include "fpmenu.h"
#include "pokemon.h"
#include "utils.h"
#include "bg.h"
#include "text.h"

#define bgset 0x93c1b00
#define bgmap 0x93c2700
#define bgpal 0x93c2a00

#define arrowup 0x93c2ad0
#define arrowleft 0x93c2a40
#define arrowpal 0x93c2aa0



//function to initalize the callback1
void init_fp_menu(u8 id){
	//initializing fp_memory for the callback (32 bytes)
	*((void**)0x020370D0) = malloc(sizeof(fp_memory));
	fp_memory *mem = *((fp_memory**)0x020370D0);
	mem->status = 0;//default state 0
	mem->oam_pokepic = 0xFF;
	mem->current_stat = 0x0;
	mem->current_slot = *((u8*)0x0203B0A9);
	mem->redraw_request = 0x0;
	mem->poke_anim_mode = 0x0;
	mem->color_anim_mode = 0x0;
	mem->color_anim_intensity = 0x0;
	mem->color_anim_delay = 0x0;
	mem->arrow_anim_mode = 0x0;
	mem->arrow_anim_cnt = 0x0;
	mem->arrow_anim_delay = 0x0;
	set_callback1(fp_callback);
	load_uncomp_pal_into_RAM((u32*)(0x84711DC), 0xe0, 0x20);
	init_fadescreen(1,0);
	remove_big_callback(id);
}

//the callback itself
void fp_callback(){
	cb1handling();
	//waiting for end of the fading
	u8* fading_flags = (u8*)(0x02037AB8+0x7);
	if (((*fading_flags)&0x80) == 0){
		fp_memory *mem = *((fp_memory**)0x020370D0);
		switch (mem->status){
			case 0:{
			//status 0 -- initializing components
				//freeing the stuff from the pokemenu
				remove_all_big_callbacks();
				pokemenu_free();
				oam_reset();
				pal_allocation_reset();
                                
				//building the bgs
				u32 bgcnfgs [2] = {0x1F8, 0x11D1};
				bg_setup (0, (bg_config*)bgcnfgs, 2);
				bg_sync_display_and_show(0);
				bg_sync_display_and_show(1);
				bg_hide(2);
				bg_hide(3);
				bg_display_sync();
				
				
				
				setflag(0x916);//anti bg_scrolling_hack
				//bg_scrolling to 0x0
				set_io(0x14, 0x0);
				set_io(0x16, 0x0);
				set_io(0x18, 0x0);
				set_io(0x1a, 0x0);
				set_io(0x1c, 0x0);
				set_io(0x1e, 0x0);
				//configurate backgrounds
				//BG1
				//apply_bg_configs(0x1, 0x0, 0x1E, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
				//bg_update_and_show(0x1);
				//loading the background graphics
				mem->bgtileset = (u32*)malloc(0x2000);
				mem->bgtilemap = (u32*)malloc(0x800);
				mem->bg0set = (u32*)malloc_fill(0x2000);
				mem->bg0map = (u32*)malloc_fill(0x800);
				lz77uncompwram((u32*)bgset, mem->bgtileset);
				lz77uncompwram((u32*)bgmap, mem->bgtilemap);
				bg_copy_vram(0x1, mem->bgtileset, 0x2000, 0x0, 0x1);
				bg_copy_vram(0x1, mem->bgtilemap, 0x800, 0x0, 0x2);
				bg_copy_vram(0x0, mem->bg0set, 0x2000, 0x0, 0x1);
				bg_copy_vram(0x0, mem->bg0map, 0x800, 0x0, 0x2);
				lz77uncompwram((u32*)0x9379f00,(u32*)0x020371F8);
				
				//bgpalette
				lz77uncompwram((u32*)bgpal,(u32*)(0x0201C000));
				memcopy ((void*)0x020371F8, (void*)(0x0201C000), 0x20);
				
				
				//now we have to init all our textboxes
				
				//spawn textboxes
				mem->tb_name = setup_textbox(0, 3, 1, 15, 2, 0xF, 0x42);
				mem->tb_level = setup_textbox(0, 13, 4, 5, 2, 0xF, 0x42+30);
				mem->tb_fpused = setup_textbox(0, 13, 7, 5, 2, 0xF, 0x42+40);
				mem->tb_hp = setup_textbox(0, 21, 4, 3, 2, 0xF, 0x42+50);
				mem->tb_atk = setup_textbox(0, 26, 4, 3, 2, 0xF, 0x42+56);
				mem->tb_def = setup_textbox(0, 21, 7, 3, 2, 0xF, 0x42+62);
				mem->tb_int = setup_textbox(0, 26, 7, 3, 2, 0xF, 0x42+68);
				mem->tb_satk = setup_textbox(0, 21, 10, 3, 2, 0xF, 0x42+74);
				mem->tb_sdef = setup_textbox(0, 26, 10, 3, 2, 0xF, 0x42+80);
				mem->tb_currentstat = setup_textbox(0, 3, 12, 11, 2, 0xF, 0x42+86);
				mem->tb_availible = setup_textbox(0, 15, 15, 3, 2, 0xF, 0x42+108);
				mem->tb_used = setup_textbox(0, 15, 18, 3, 2, 0xF, 0x42+114);
				mem->tb_bonus = setup_textbox(0, 24, 15, 5, 2, 0xF, 0x42+120);
				
				//spawn oam for arrows
				sprite arrow_up_final_oam = {0,0x4000, 0x1000, 0x0};
				sprite arrow_down_final_oam = {0x000,0x6000, 0x1000, 0x0};
				sprite arrow_left_final_oam = {0,0x4000, 0x1000, 0x0};
				sprite arrow_right_final_oam = {0x000,0x5000, 0x1000, 0x0};
				
				graphic graphic_arrow = {(void*)arrowup,0x80,0x1338};
				graphic graphic_arrow2 = {(void*)arrowleft,0x80,0x1339};
				
				oam_template arrow_template_up ={0x1338, 0xFFFF, &arrow_up_final_oam, (gfx_frame**)0x08231Bc0, &graphic_arrow,(rotscale_frame**)0x08231Bcc, oam_null_callback};
				oam_template arrow_template_down ={0x1338, 0xFFFF, &arrow_down_final_oam, (gfx_frame**)0x08231Bc0, &graphic_arrow,(rotscale_frame**)0x08231Bcc, oam_null_callback};
				oam_template arrow_template_left ={0x1339, 0xFFFF, &arrow_left_final_oam, (gfx_frame**)0x08231Bc0, &graphic_arrow2,(rotscale_frame**)0x08231Bcc, oam_null_callback};
				oam_template arrow_template_right ={0x1339, 0xFFFF, &arrow_right_final_oam, (gfx_frame**)0x08231Bc0, &graphic_arrow2,(rotscale_frame**)0x08231Bcc, oam_null_callback};
				
				load_and_alloc_obj_vram_lz77(&graphic_arrow);
				load_and_alloc_obj_vram_lz77(&graphic_arrow2);
				
				
				lz77uncompwram((u32*)arrowpal,(u32*)(0x02037418));

				
				mem->oam_arrowup = generate_oam_forward_search(&arrow_template_up, 16, 32, 0);
				mem->oam_arrowdown = generate_oam_forward_search(&arrow_template_down, 16, 76, 0);
				mem->oam_arrowleft = generate_oam_forward_search(&arrow_template_left, 12, 100, 0);
				mem->oam_arrowright = generate_oam_forward_search(&arrow_template_right, 124, 100, 0);
				
				fp_load_pokemon((void*)(0x02024284+mem->current_slot*0x64), mem->current_stat, mem);
				
				//exit
				mem->last_pressed_key = *((u16*)0x04000130);
				init_fadescreen(0,0);
				break;
			}
			case 1:{
				if (mem->delay == 0){
					//status wait for key input;
					u16 current_input = *((u16*)0x04000130);
					u16 last_input = mem->last_pressed_key;
					mem->last_pressed_key = current_input;
					if (current_input != last_input){
						//something in input has chanced
						u16 key_id = 0;
						u16 new_presses = (u16)(last_input&(~current_input));
						while (new_presses != 0){
							new_presses = new_presses>>1;
							key_id++;
						}
						//*((u8*)0x020370D4) = key_id;
						switch (key_id){
							case 1:{
								//A pressed
								//calculating availible FPs
								void* pokemon_offset = (void*)(0x02024284+mem->current_slot*0x64);
								u32 afp = get_pokemons_attribute (pokemon_offset, (u16)(0x1a+mem->current_stat), 0x0); 
								u8 rcontest = 0x16;	//requested contest attribute
								switch (mem->current_stat){
									case 1:
										rcontest = 0x17;
										break;
									case 2:
										rcontest = 0x18;
										break;
									case 3:
										rcontest = 0x21;
										break;
									case 4:
										rcontest = 0x2f;
										break;
									case 5:
										rcontest = 0x30;
										break;
								}
								u32 ufp = get_pokemons_attribute (pokemon_offset, rcontest, 0x0)&0x3F;
								u32 dif = (afp>=4*ufp)?(afp-4*ufp):0;
								u32 fpused = get_fp_used(pokemon_offset);
								
								if (dif > 3 && ufp<63 && fpused < 510){
									//proceding a FP usage
									ufp += 1;
									u8 new_value = (u8)((get_pokemons_attribute (pokemon_offset, rcontest, 0x0)&(u32)(~0x3F))|ufp);
									set_pokemons_attribute (pokemon_offset, rcontest, &new_value);
									recalculate_stats(pokemon_offset);
									
									fp_load_stats(pokemon_offset, mem->current_stat, mem);
									
									sound(84);
									mem->delay = 0x10;
									
									
								
								}else{
									//not enough FP availible for FP usage / 252 FPs were already used
									sound(26);
									mem->delay = 0x10;
								}
								
								
								
								
								break;
							}
							case 2:{
								//B pressed
								init_fadescreen(1,0);
								mem->status = 3;
								sound(5);
								break;
							}
							case 5:{
								//RIGHT pressed
								mem->current_stat = (mem->current_stat==5)? 0x0: (u8)(mem->current_stat+1);
								fp_load_stat((void*)(0x02024284+mem->current_slot*0x64), mem->current_stat, mem);
								sound(5);
								mem->delay = 0x10;
								break;
							}
							case 6:{
								//LEFT pressed
								mem->current_stat = (mem->current_stat==0)? 0x5: (u8)(mem->current_stat-1);
								fp_load_stat((void*)(0x02024284+mem->current_slot*0x64), mem->current_stat, mem);
								sound(5);
								mem->delay = 0x10;
								break;
							}
							case 8:{
								//DOWN pressed
								u8 pcnt = countpokemon();//teampoke
								if (pcnt != 1){
									//no reload when there is only one pokemon
									mem->current_slot = (mem->current_slot==(pcnt-1))? 0x0: (u8)(mem->current_slot+1);
									fp_load_pokemon((void*)(0x02024284+mem->current_slot*0x64), mem->current_stat, mem);
									}
								break;
							}
							case 7:{
								//UP pressed
								u8 pcnt = countpokemon();//teampoke
								if (pcnt != 1){
									//no reload when there is only one pokemon
									mem->current_slot = (mem->current_slot==(0x0))? (u8)(pcnt-1): (u8)(mem->current_slot-1);
									fp_load_pokemon((void*)(0x02024284+mem->current_slot*0x64), mem->current_stat, mem);
									}
								break;
							}
						}
					}
				}else{mem->delay = (u8)(mem->delay-1);}
				break;
			}
			case 2:{
				//loading a new pokemon
				//checking if redraw requested
				if (mem->redraw_request !=0x0){
					if (mem->redraw_request == 0xFFFF){
						oam_object* pkmoam = (oam_object*)(0x0202063C+(0x44*mem->oam_pokepic));
						pkmoam->final_oam.attr0 = (u16)(pkmoam->final_oam.attr0 &~ 0x200); //making oam visible
						mem->redraw_request = 0x0;
					}else{
						
						u32 *tileset = (mem->redraw_request == 0xFFFE) ? (u32*)0x8e3b4cc : pokemon_frontsprites[mem->redraw_request].sprite;
						u32 *palette = (u32*)0x8E3B680;
						if (mem->redraw_request != 0xFFFE){
							palette = ((((*((u32*)(0x02024284+mem->current_slot*0x64)))<<0x8)>>0x10)>0x200)?
                                                            pokemon_pals[mem->redraw_request].pal : pokemon_shiny_pals[mem->redraw_request].pal;
						}
						
						
						//redraw
						//redrawing the tileset
						lz77uncompwram(tileset, (u32*)(0x0201C000));
						cpuset((u32*)(0x0201C000), (u32*)(0x06010000+(mem->pokepic_start_tile<<5)),0x400);
						
						//palette of pokepic
						lz77uncompwram(palette,(u32*)(0x0201C000));
						load_uncomp_pal_into_RAM((u32*)(0x0201C000), 0x100, 0x20);
						
						mem->redraw_request = 0xFFFF;
					}
				}else{
					//launch animation
					oam_object* pkmoam = (oam_object*)(0x0202063C+(0x44*mem->oam_pokepic));
					//pkmoam->final_oam.attr0 = pkmoam->final_oam.attr0 &~ 0x200; //making oam visible
					if (mem->poke_anim_mode == 0){
						//raising it up
						pkmoam->y2 = (s16)(pkmoam->y2-1);
						if (pkmoam->y2 == -10){mem->poke_anim_mode = 1;} //switching to down
					}else{
						//bringing it down
						pkmoam->y2 = (s16)(pkmoam->y2+2);
						if (pkmoam->y2 == 0){mem->poke_anim_mode = 0;} //switching to down
					}
					mem->delay--;
					if (mem->delay == 0){mem->status=1;}
				}
				break;
			}
			case 3:{
				//setting return values for menu
				*((u8*)0x0203B16C) = mem->current_slot; //slot of the pokemon to return to 
				
				//free all alocated ram
				free((void*)mem->bgtileset);
				free((void*)mem->bgtilemap);
				free((void*)mem->bg0map);
				free((void*)mem->bg0set);
				free((void*)mem);
				free_all_tboxes();
				
				clearflag(0x916);
				set_callback1((void*)0x8122df5);
				
				//map_reload();
			}			
		}
		//color_animation
		fp_do_color_animation(mem);
		//arrow_animation
		fp_do_arrow_animation(mem);
	}
}

u8 setup_textbox(u8 bgid, u8 x, u8 y, u8 w, u8 h, u8 palID, u16 startTile){
	tboxdata boxdata;
	tbox_data_new(&boxdata, bgid, x, y, w, h, palID, startTile);
	u8 boxid = tbox_new(&boxdata);
	tbox_flush(boxid, 0);
	tbox_tilemap_draw(boxid);
	return boxid;
}

void fp_display_box(u8 boxid, u8 font, u8 unkown, u8 border_distance, u8 line_distance_u, u8 line_distance_l, u8*font_col_map, u8 display_all_boxes, u8*text){
	tbox_flush(boxid, 0);
	tbox_print_string(boxid, font, unkown, border_distance, line_distance_u, line_distance_l, font_col_map, display_all_boxes, text );
}

//loads all stat-related values of a pokemon
void fp_load_stats(void*pokemon_offset, u8 requested_stat, fp_memory* mem){
	if (requested_stat < 6){
		
		bool isEgg = (bool)(get_pokemons_attribute(pokemon_offset, 0x2D, 0) & 1);
		
		u8 str[] = {0,0,0,0,0xFF};
		u8 fontcolmap[] = {0,2,1,0};
		
		//load the pokemons fpused
		if (!isEgg){
			u32 fpused = get_fp_used(pokemon_offset);
			hex_to_dec_String(str, fpused, 0, charlen_of_hex_value_dec_format(fpused));
		}
		fp_display_box(mem->tb_fpused, 2, 0, 0, 0, 0, fontcolmap, 0x0, (u8*)str);
		
		//hp
		if (!isEgg){
			u32 hp = get_pokemons_attribute (pokemon_offset, 0x3a, 0x0);
			hex_to_dec_String(str, hp, 0, charlen_of_hex_value_dec_format(hp));
		}
		fp_display_box(mem->tb_hp, 2, 0, 0, 0, 0, fontcolmap, 0x0, (u8*)str);
		
		//atk
		if (!isEgg){
			u32 atk = get_pokemons_attribute (pokemon_offset, 0x3b, 0x0);
			hex_to_dec_String(str, atk, 0, charlen_of_hex_value_dec_format(atk));
		}
		fp_display_box(mem->tb_atk, 2, 0, 0, 0, 0, fontcolmap, 0x0, (u8*)str);
		
		//def
		if (!isEgg){
			u32 def = get_pokemons_attribute (pokemon_offset, 0x3c, 0x0);
			hex_to_dec_String(str, def, 0, charlen_of_hex_value_dec_format(def));
		}
		fp_display_box(mem->tb_def, 2, 0, 0, 0, 0, fontcolmap, 0x0, (u8*)str);
		
		//int
		if (!isEgg){
			u32 _int = get_pokemons_attribute (pokemon_offset, 0x3d, 0x0);
			hex_to_dec_String(str, _int, 0, charlen_of_hex_value_dec_format(_int));
		}
		fp_display_box(mem->tb_int, 2, 0, 0, 0, 0, fontcolmap, 0x0, (u8*)str);
		
		//satk
		if (!isEgg){
			u32 satk = get_pokemons_attribute (pokemon_offset, 0x3e, 0x0);
			hex_to_dec_String(str, satk, 0, charlen_of_hex_value_dec_format(satk));
		}
		fp_display_box(mem->tb_satk, 2, 0, 0, 0, 0, fontcolmap, 0x0, (u8*)str);
		
		//sdef
		if (!isEgg){
			u32 sdef = get_pokemons_attribute (pokemon_offset, 0x3f, 0x0);
			hex_to_dec_String(str, sdef, 0, charlen_of_hex_value_dec_format(sdef));
		}
		fp_display_box(mem->tb_sdef, 2, 0, 0, 0, 0, fontcolmap, 0x0, (u8*)str);
		
		fp_load_stat(pokemon_offset, requested_stat, mem);
	}
}

//loads a stat of a certain pokemon
void fp_load_stat(void*pokemon_offset, u8 requested_stat, fp_memory* mem){
	//0,1,2,3,4,5 = hp,atk,def,int,satk,sdef
	if (requested_stat < 6){
	
		bool isEgg = (bool)(get_pokemons_attribute(pokemon_offset, 0x2D, 0) & 1);
		
		u8 fontcolmap[] = {0,2,1,0};
		
		//stat name
		void* names[]={(void*)0x81BB2F8, (void*)0x81BB317, (void*)0x81BB31F, (void*)0x81BB337,(void*)0x81BB325, (void*)0x81BB32E};//pointers to name strings
		fp_display_box(mem->tb_currentstat, 2, 0, 0, 0, 0, fontcolmap, 0x0, (u8*)names[requested_stat]);

		//availible fps
		u32 afp = get_pokemons_attribute (pokemon_offset, (u16)(0x1a+requested_stat), 0x0); 
		//used fps
		u8 rcontest = 0x16;	//requested contest attribute
		switch (requested_stat){
			case 1:
				rcontest = 0x17;
				break;
			case 2:
				rcontest = 0x18;
				break;
			case 3:
				rcontest = 0x21;
				break;
			case 4:
				rcontest = 0x2f;
				break;
			case 5:
				rcontest = 0x30;
				break;
		}
		u32 ufp = 4*(get_pokemons_attribute (pokemon_offset, rcontest, 0x0)&0x3F);
		afp = (afp>=ufp)?(afp-ufp):0;
		
		//*((u32*)0x020370c0) = ufp;
		//now we make strings out of the values
		u8 str[] = {0,0,0,0xFF};
		
		//availible fps
		if (!isEgg){
			hex_to_dec_String(str, (u32)afp, 0, charlen_of_hex_value_dec_format(afp));
		}
		fp_display_box(mem->tb_availible, 2, 0, 0, 0, 0, fontcolmap, 0x0, (u8*)str);
		
		//used fps
		if (!isEgg){
			hex_to_dec_String(str, (u32)ufp, 0, charlen_of_hex_value_dec_format(ufp));
		}
		fp_display_box(mem->tb_used, 2, 0, 0, 0, 0, fontcolmap, 0x0, (u8*)str);
		
		//bonus
		//for the bonus calculation we subtract a reference value (0 ev) from the current value
		u32 current_val = get_pokemons_attribute (pokemon_offset, (u16)(0x3A+requested_stat), 0x0);
		//cloning the pokemon for a reference value
		u8 buffer[0x64];
		memcopy((void*)buffer, pokemon_offset, 0x64);
		u32 zero = 0;
		set_pokemons_attribute ((void*)buffer, rcontest, &zero);
		recalculate_stats((void*)buffer);
		
		//memcopy((void*)0x020370D4,(void*)buffer, 0x64);
		
		u32 dif = current_val - get_pokemons_attribute ((void*)buffer, (u16)(0x3A+requested_stat), 0x0);
		if (!isEgg){
			hex_to_dec_String(str, dif, 0, charlen_of_hex_value_dec_format(dif));
		}
		fp_display_box(mem->tb_bonus, 2, 0, 0, 0, 0, fontcolmap, 0x0, (u8*)str);
		
		bg_copy_vram(0, bg_get_tilemap(0), 0x800, 0, 2);
	}
}

//loads a pokemon including a stat with animation
void fp_load_pokemon (void*pokemon_offset, u8 requested_stat, fp_memory* mem){
	//0,1,2,3,4,5 = hp,atk,def,int,satk,sdef
	if (requested_stat < 6){
		
		bool isEgg = (bool)(get_pokemons_attribute(pokemon_offset, 0x2D, 0) & 1);
		u8 fontcolmap[] = {0,2,1,0};
		
		//load the pokemons name
		u8 name[] = {0xBF,0xDD,0xFF,0,0,0,0,0,0,0, 0xFF};
		
		if (!isEgg){
			memcopy((void*)name, (void*)(pokemon_offset+0x8), 10);
		}
		fp_display_box(mem->tb_name, 2, 0, 0, 0, 0, fontcolmap, 0x0, (u8*)name);
		
		u8 str[] = {0x0,0x0,0,0xFF};
		
		//load the pokemons level
		u32 level = get_pokemons_attribute (pokemon_offset, 0x38, 0x0);
		if (!isEgg){
			hex_to_dec_String(str, level, 0, charlen_of_hex_value_dec_format(level));
		}
		fp_display_box(mem->tb_level, 2, 0, 0, 0, 0, fontcolmap, 0x0, (u8*)str);
		
		//pokepic
		u16 spezies = (u16)get_pokemons_attribute (pokemon_offset, 0xb, 0x0);
		if (mem->oam_pokepic == 0xFF){
			//initialize pokepic 
			sprite s = {0,0xc000, 0x0, 0x0};
			oam_template template = {spezies, 0xFFFF, &s, (gfx_frame**)0x08231Bc0, &pokemon_frontsprites[spezies], (rotscale_frame**)0x08231Bcc, oam_null_callback};
			mem->pokepic_start_tile = load_and_alloc_obj_vram_lz77(&pokemon_frontsprites[spezies]);
			mem->oam_pokepic = generate_oam_forward_search(&template, 64, 56, 0);
			
			//palette of pokepic
			void* palette = ((((*((u32*)pokemon_offset))<<0x8)>>0x10)>0x200)?pokemon_pals[spezies].pal : pokemon_shiny_pals[spezies].pal;
			load_comp_pal_into_RAM(palette, 256, 32);
		}else{
			//update pokepic
			if (isEgg){
				mem->redraw_request = 0xFFFE;
			}else{
				
				//first we disable the pokepic
				oam_object* pkmoam = (oam_object*)(0x0202063C+(0x44*mem->oam_pokepic));
				pkmoam->final_oam.attr0 = pkmoam->final_oam.attr0 | 0x200; 
				mem->redraw_request = spezies;
				/*
				lz77uncompwram((u32*)(*((u32*)(0x08234F7C+(spezies<<3)))), (u32*)(0x0201C000));
				cpuset((u32*)(0x0201C000), (u32*)(0x06010000+(mem->pokepic_start_tile<<5)),0x400);
				*/
			}
		}
		
		fp_load_stats(pokemon_offset, requested_stat, mem);
		
		//now the cry
		if (!isEgg){	
			cry(spezies, 0);
		}
		
		mem->status = 2;
		mem->delay = 0x1e;
	}
}

//does the color animation
void fp_do_color_animation(fp_memory* mem){
	u16 colors[] = {0x372a, 0x31df, 0x4Dcd, 0x7FB7, 0x439F, 0x3212};
	//*((u16*)0x020370D4) = colors[mem->current_stat];
	if (mem->color_anim_delay == 0){
		if (mem->color_anim_mode == 0){
			//raising intensity
			mem->color_anim_intensity = (u8)(mem->color_anim_intensity+1);
			if (mem->color_anim_intensity == 8){mem->color_anim_mode = 1;}
		}else{
			//lowering intensity
			mem->color_anim_intensity = (u8)(mem->color_anim_intensity-1);
			if (mem->color_anim_intensity == 0){mem->color_anim_mode = 0;}
		}
		//applying intensity to palettes
		color_blend(0x100, 0x10, mem->color_anim_intensity, colors[mem->current_stat]);
		mem->color_anim_delay = 0x2;
	}else{
		mem->color_anim_delay = (u8)(mem->color_anim_delay -1);
	}
}

//does arrow animations
void fp_do_arrow_animation(fp_memory* mem){
	//getting the oams of the arrows
	if (mem->arrow_anim_delay == 0){
		oam_object* oam_up = (oam_object*)(0x0202063C+(0x44*mem->oam_arrowup));
		oam_object* oam_down = (oam_object*)(0x0202063C+(0x44*mem->oam_arrowdown));
		oam_object* oam_left = (oam_object*)(0x0202063C+(0x44*mem->oam_arrowleft));
		oam_object* oam_right = (oam_object*)(0x0202063C+(0x44*mem->oam_arrowright));
		if (mem->arrow_anim_mode == 0){
			//mode 0
			mem->arrow_anim_cnt = (u8)(mem->arrow_anim_cnt+1);
			if (mem->arrow_anim_cnt == 4){mem->arrow_anim_mode = 1;}
		}else{
			//mode 1
			mem->arrow_anim_cnt = (u8)(mem->arrow_anim_cnt-1);
			if (mem->arrow_anim_cnt == 0){mem->arrow_anim_mode = 0;}
		}
		oam_up->y2 = (s16)(-((mem->arrow_anim_cnt)));
		oam_down->y2 = (s16)((mem->arrow_anim_cnt));
		oam_left->x2 = (s16)(-((mem->arrow_anim_cnt)));
		oam_right->x2 = (s16)((mem->arrow_anim_cnt));
		
		mem->arrow_anim_delay = 0x4;
	}else{mem->arrow_anim_delay = (u8)(mem->arrow_anim_delay-1);}
}

u32 get_fp_used (void* pokemon_offset){
	return 4*((get_pokemons_attribute (pokemon_offset, 0x16, 0x0)&0x3F)+(get_pokemons_attribute (pokemon_offset, 0x17, 0x0)&0x3F)
		+(get_pokemons_attribute (pokemon_offset, 0x18, 0x0)&0x3F)+(get_pokemons_attribute (pokemon_offset, 0x21, 0x0)&0x3F)+
		(get_pokemons_attribute (pokemon_offset, 0x2f, 0x0)&0x3F)+(get_pokemons_attribute (pokemon_offset, 0x30, 0x0)&0x3F));
	
}


