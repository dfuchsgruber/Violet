#ifndef H_ANIM_ENGINE
#define H_ANIM_ENGINE


typedef struct ae_memory {
	
	u16 current_frame;
	u32 current_programm;
	u8 link_numbers;
	u8 callback_id;
	bool active;
	u32 links [8];
	u16 lframes [8];
	u16 vars[16];
} ae_memory;

typedef void (*ae_cmd)(ae_memory* mem);

extern void init_anim_engine();
void callback(u8 callback_id);
void execute_frame(ae_memory* mem);
u8 read_byte(ae_memory* mem);
u16 read_unaligned_hword_read_only(ae_memory*mem);
u32 read_unaligned_word (ae_memory* mem);
u16 read_unaligned_hword (ae_memory* mem);
u16 read_param(ae_memory* mem);
void render_tbox(u8 cbid);
void obj_move (u8 cbid);
void fade (u8 cb_id);
void callback_maintain();

/**
/ Command Functions
**/
void cmdx00_end(ae_memory* mem);
void cmdx01_call(ae_memory* mem);
void cmdx02_jump(ae_memory* mem);
void cmdx03_oam_new(ae_memory* mem);
void cmdx04_oam_delete(ae_memory* mem);
void cmdx05_oam_vram_load(ae_memory* mem);
void cmdx06_oam_vram_free(ae_memory* mem);
void cmdx07_oam_despawn(ae_memory* mem);
void cmdx08_spawn_callback(ae_memory* mem);
void cmdx09_bg_reset(ae_memory* mem);
void cmdx0A_bg_setup(ae_memory* mem);
void cmdx0B_bg_sync_and_show(ae_memory* mem);
void cmdx0C_bg_hide(ae_memory* mem);
void cmdx0D_bg_display_sync();
void cmdx0E_bg_override(ae_memory* mem);
void cmdx0F_load_obj_pal (ae_memory* mem);
void cmdx10_free_obj_pal(ae_memory* mem);
void cmdx11_get_io(ae_memory* mem);
void cmdx12_set_io_to_var(ae_memory* mem);
void cmdx13_set_io_to_value(ae_memory*mem);
void cmdx14_prepare_tbox (ae_memory*mem);
void cmdx15_display_text_inst (ae_memory*mem);
void cmdx16_clear_textbox (ae_memory*mem);
void cmdx17_display_rendered_tbox (ae_memory*mem);
void cmdx18_rendered_tbox_event (ae_memory* mem);
void cmdx19_objmove (ae_memory* mem);
extern void anim_engine_cmdx1A(ae_memory* mem);
void cmdx1B_gfx_anim_set(ae_memory*mem);
void cmdx1C_rs_anim_set (ae_memory*mem);
void cmdx1D_loadpal (ae_memory*mem);
void cmdx1E_fade (ae_memory*mem);
void cmdx1F_invertcolors (ae_memory* mem);
void cmdx20_sound (ae_memory* mem);
void cmdx21_song (ae_memory* mem);
void cmdx22_cry (ae_memory* mem);
void cmdx23_maintain();



#endif