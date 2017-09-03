#ifndef H_ANIM_ENGINE
#define H_ANIM_ENGINE

#include <stdbool.h>

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

typedef struct text_render_flags_s {
    u8 linebreak : 1;
    u8 paragraph : 1;
    u8 end : 1;
    u8 free : 1;
    u8 pass_linebreak : 1;
    u8 pass_paragraph : 1;
    u8 pass_end : 1;
    u8 pass_free : 1;
} text_render_flags_s;

typedef union text_render_flags {
    u8 value;
    text_render_flags_s flags;
} text_render_flags;

typedef struct aetr_memory {
    u8 *o_text;
    u8 *source;
    u8 *destination;
    text_render_flags flags;
    u16 delay_timer;
    u16 delay;
    u8 *color_map;
    u8 boxid;
    u8 font;
    u8 unkown;
    u8 border_distance;
    u8 line_distance_u;
    u8 line_distance_l;
    u8 display_flag;
    u8 bg_id;

} aetr_memory;

typedef void (*ae_cmd)(ae_memory* mem);

extern void **anim_script_table;

void init_anim_engine_by_table();
void init_anim_engine(void *script);
void anim_engine_callback(u8 callback_id);
void anim_engine_execute_frame(ae_memory* mem);
u8 anim_engine_read_byte(ae_memory* mem);
u16 anim_engine_get_hword(ae_memory*mem);
u32 anim_engine_read_word(ae_memory* mem);
u16 anim_engine_read_hword(ae_memory* mem);
u16 anim_engine_read_param(ae_memory* mem);
//void anim_engine_tbox_renderer(u8 cbid);
void anim_engine_text_renderer(u8 self);
void anim_engine_obj_mover(u8 cbid);
void anim_engine_fader(u8 cb_id);
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
void cmdx0F_load_obj_pal(ae_memory* mem);
void cmdx10_free_obj_pal(ae_memory* mem);
void cmdx11_get_io(ae_memory* mem);
void cmdx12_set_io_to_var(ae_memory* mem);
void cmdx13_set_io_to_value(ae_memory*mem);
void cmdx14_prepare_tbox(ae_memory*mem);
void cmdx15_display_text_inst(ae_memory*mem);
void cmdx16_clear_textbox(ae_memory*mem);
void cmdx17_display_rendered_tbox(ae_memory*mem);
void cmdx18_rendered_tbox_event(ae_memory* mem);
void cmdx19_objmove(ae_memory* mem);
void anim_engine_cmdx1A(ae_memory* mem);
void cmdx1B_gfx_anim_set(ae_memory*mem);
void cmdx1C_rs_anim_set(ae_memory*mem);
void cmdx1D_loadpal(ae_memory*mem);
void cmdx1E_fade(ae_memory*mem);
void cmdx1F_invertcolors(ae_memory* mem);
void cmdx20_sound(ae_memory* mem);
void cmdx21_song(ae_memory* mem);
void cmdx22_cry(ae_memory* mem);
void cmdx23_maintain();
void cmdx24_script_notify();
void cmdx25_oam_reset();
void cmdx26_callback_reset(ae_memory *mem);
void cmdx27_dma3_controller_reset();
void anim_engine_bg_free_task(u8 self);
void cmdx28_bg_scroll_reset();
void cmdx29_bg_vmap_init(ae_memory *mem);
void cmdx2A_bg_vmap_drop(ae_memory *mem);
void cmdx2B_bg_scroll(ae_memory *mem);
void anim_engine_bg_scroller(u8 self);
void cmdx2C_mapreload();
void cmdx2D_force_pals_to_black();
void cmdx2E_bg_clear_map(ae_memory *mem);
void cmdx2F_setvar(ae_memory *mem);
void cmdx30_fade_obj_pal(ae_memory *mem);
void cmdx31_tbox_flush(ae_memory *mem);
void cmdx32_pal_restore_force_current(ae_memory *mem);
void ae_mapreloader();

void anim_engine_yin_yang_fade_big_callback(u8 self);

#endif