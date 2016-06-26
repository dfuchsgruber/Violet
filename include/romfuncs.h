#ifndef H_ROMFUNCS
#define H_ROMFUNCS
#include <stdbool.h>

//static functions in ROM
u8 get_item_effect_param (u16 item_id);
void init_fadescreen(u8 type, u8 unkown);
void set_callback1(void (*function)());
void *malloc(u32 size);
void oam_reset();
void setflag(u16 flag);
void clearflag(u16 flag);
void set_io(u16 ioreg, u16 value);
void apply_bg_configs(u8 bgid, u8 charbase, u8 mapbase, u8 size, u8 colmode, u8 priority, u8 mosaic, u8 unkown);
void bg_update_and_show(u8 bgid);
void lz77uncompvram (void*source, void*destination);
void lz77uncompwram (void*source, void*destination);
void cb1handling();
void bg_copy_vram(u8 bgid, void*source, u16 size, u16 starttile, u8 mode);
void cpuset (void*source, void*destination, int cnt_and_mode);
void cpufastset (u32*source, u32*destination, u32 cnt_and_mode);
u32* translate_text_data_into_box(u8* freespace, u8 bgid, u8 x, u8 y, u8 w, u8 h, u8 palID, u16 startTile);
u8 spawn_tbox(u8*boxdata);
void fill_box_bg (u8 boxid, u8 filler);
void prepeare_bg_for_tbox(u8 boxid);
void display_tbox_transbg (u8 boxid, u8 font, u8 unkown, u8 border_distance, u8 line_distance_u, u8 line_distance_l, u8* font_col_map, u8 display_all_boxes, u8 text[]);
u32* bg_get_tilemap (u8 bgid);
u32 get_pokemons_attribute (void*pokemon_offset, int requested_attribute, void*freespace);
u32 set_pokemons_attribute (void*pokemon_offset, u16 requested_attribute, void*values);
u8 charlen_of_hex_value_dec_format(u32 value);
void hex_to_dec_String (u8*dest, u32 value, u8 mode, u8 charlength);
void memcopy (void* dest, void*source, u32 size);
void recalculate_stats(void*pokemon_offset);
void load_uncomp_pal_into_RAM(void*source, u16 dest_col, u16 bytecount);
u8 countpokemon();
void cry(u16 pokeID, u8 feature);
void sound(u16 soundID);
void map_reload();
void free(void* ptr);
void color_blend(u16 color_id_to_blend, u16 color_count, u8 intesity, u16 color_to_blend_into);
void remove_big_callback(u8 cbid);
void init_script(void* script);
u8 spawn_big_callback(void*function, u8 priority);
void* malloc_fill(u32 size);
u8 allocate_rotscale();
void set_rotscale_param (u8 id, u16 v0, u16 v1, u16 v2, u16 v3);
void pokemenu_free();
void remove_all_big_callbacks();
void bg_reset(u8 unkown); //usually called with unkown = 0x0
void bg_setup (u8 bgtilemode, void*configs, u8 configsnum);
void bg_sync_display_and_show (u8 bgid);
void free_all_tboxes();
void bg_hide (u8 bgid);
void bg_display_sync();
void load_comp_pal_into_RAM(void* source, u16 dest_col, u16 bytecount);
u16 get_io(u16 reg);
void free_tbox(u8 boxid);
void flush_tbox (u8 boxid, u8 unkown);
void string_decrypt(u8* destination, u8* source);
void playsong1 (u16 song, u8 feature);
void map_reload_small();
void obj_pal_reset();
void bg_set_tilemap(u8 bgid, void* tilemap);
void display_box_no_transbg (u8 boxid, u8 font, u8* text, u8 unkown, u8 border, u8 display_all, u8 unkown2);
u16* vardecrypt(u16 var);
bool is_function_listed_as_callback (void* func);
u8 get_callback_id_by_func(void *func);
void load_graphic_for_wandler (u8 user_index, u8 target_index, u8 unkown);
bool is_opponent (u8 index);
u8 get_ability(u16 species, u8 fields);
bool checkflag (u16 flag);
void battle_printmsg (u8* str, u16 duration);
void init_attack();
void bsc_executer();
u8* concatenate_strings (u8* first, u8* second); //returns the offset of the 0xFF bytes of the two strings
u8* strcpy (u8* s1, u8* s2);
bool is_double_battle();
//void load_and_alloc_obj_vram_lz77 (graphic*g);	defined in oams.h
u8 ability_management(u8 state, u8 attacker_slot, u8 unkown, u8 defender_ability, u16 active_attack);
void battle_callback1();
void get_current_tile_position(s16 *x, s16 *y);
u16 get_block_id (s16 x, s16 y);
void set_block_id (s16 x, s16 y, u16 block);
void special_x8E_update_map_graphics();
u16 random_change_seed();
u16 get_block_info_behaviour (s16 x, s16 y);
void warp_setup (u8 bank, u8 map, u8 exit, s16 x, s16 y);
void warp_setup_callbacks();
void script_wait_for_warp();
void script_halt();
void dma3_controller_reset();
void bghscrollset(u8 bgid, int x, int y);
void bgvscrollset(u8 bgid, int x, int y);
//
u32 __umod (u32 dividend, u32 divisor);
int __sqrt(int x);
script npc_get_script (u8 npc_id);
u16 trainer_get_unaligned_hword (void *src);
u16 trainer_get_flag();
bool get_npc_id_by_overworld(u8 overworld_id, u8 map, u8 bank, u8 *result);
void list_add(u8 *list, u8 *size, u8 value);
u8 pokemon_menu_context_get_current_item_index();
void tbox_flush_and_free_if_present (u8 *boxid);
bool outdoor_moves_usable();
bool map_is_x40_x0();
void pokemenu_opts_clear_pokemenu_and_printstr(u8 string_id);
void pokemenu_task_wait_for_keypress_and_return_to_select(u8 self);
void pokemenu_init_textrenderer(u8 *text, u8 unkown);
void pokemenu_task_wait_for_textrenderer(u8 self);
void surfer_init_proper_error_message();
void script_resume();
u8 get_current_weather();
void save_increment_key(u8 key);
void rain_sound_fadeout();
void startmenu_close();

#endif