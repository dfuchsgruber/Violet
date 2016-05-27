#ifndef H_FPMENU
#define H_FPMENU

typedef struct fp_memory {
	u8 status;
	u8 current_slot;
	u8 current_stat;
	u8 oam_pokepic;
	u8 oam_arrowup;
	u8 oam_arrowdown;
	u8 oam_arrowleft;
	u8 oam_arrowright;
	u8 animation_cb;
	u8 tb_name;
	u8 tb_level;
	u8 tb_fpused;
	u8 tb_hp;
	u8 tb_atk;
	u8 tb_def;
	u8 tb_int;
	u8 tb_satk;
	u8 tb_sdef;
	u8 tb_currentstat;
	u8 tb_availible;
	u8 tb_used;
	u8 tb_bonus;
	u8 delay;
	u8 poke_anim_mode;
	u8 color_anim_mode;
	u8 color_anim_intensity;
	u8 color_anim_delay;
	u8 arrow_anim_mode;
	u8 arrow_anim_cnt;
	u8 arrow_anim_delay;
	u16 redraw_request;
	u16 pokepic_start_tile;
	u16 last_pressed_key;
	u32 *bgtileset;
	u32 *bgtilemap;
	u32 *bg0set;
	u32 *bg0map;
	
} fp_memory;

void fp_callback();
u8 setup_textbox(u8 bgid, u8 x, u8 y, u8 w, u8 h, u8 palID, u16 startTile);
void fp_display_box(u8 boxid, u8 font, u8 unkown, u8 border_distance, u8 line_distance_u, u8 line_distance_l, u8*font_col_map, u8 display_all_boxes, u8*text);
void fp_load_stat(void*pokemon_offset, u8 requested_stat, fp_memory* mem);
void fp_load_pokemon (void*pokemon_offset, u8 requested_stat, fp_memory* mem);
void fp_load_stats (void*pokemon_offset, u8 requested_stat, fp_memory* mem);
void fp_do_color_animation(fp_memory* mem);
void fp_do_arrow_animation(fp_memory* mem);
u32 get_fp_used (void* pokeoffset);

#endif