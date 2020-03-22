#ifndef H_ANIM_ENGINE
#define H_ANIM_ENGINE

#include <stdbool.h>
#include "color.h"
#include "text.h"

typedef struct anim_engine_task{
    int priority;
    int id;
    struct anim_engine_task *prev;
    struct anim_engine_task *next;
    void (*callback)(struct anim_engine_task*);
    void *vars;
} anim_engine_task;

typedef struct ae_memory {
    u16 current_frame;
    u8 *current_programm;
    u8 link_numbers;
    u8 callback_id;
    bool active;
    u8 *links [8];
    u16 lframes [8];
    u16 vars[16];
    color_t *pal_restore_save;
    anim_engine_task *root;
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
    u16 speed;
    tbox_font_colormap *color_map;
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

extern u8 **anim_script_table;


void init_anim_engine_by_table();
void init_anim_engine(u8 *script);
void anim_engine_callback(u8 callback_id);
void anim_engine_execute_frame(ae_memory* mem);
u8 anim_engine_read_byte(ae_memory* mem);
u16 anim_engine_get_hword(ae_memory*mem);
u32 anim_engine_read_word(ae_memory* mem);
u16 anim_engine_read_hword(ae_memory* mem);
u16 anim_engine_read_param(ae_memory* mem);
//void anim_engine_tbox_renderer(u8 cbid);
void anim_engine_text_renderer(anim_engine_task *t);
void _obj_move_linear_trace(anim_engine_task *self);
void anim_engine_fader(anim_engine_task *self);
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
void anim_engine_bg_free_task(anim_engine_task *self);
void cmdx28_bg_displacement_reset();
void cmdx29_bg_vmap_init(ae_memory *mem);
void cmdx2A_bg_vmap_drop(ae_memory *mem);
void cmdx2B_bg_scroll(ae_memory *mem);
void anim_engine_bg_scroller(anim_engine_task *self);
void cmdx2C_mapreload();
void cmdx2D_force_pals_to_black();
void cmdx2E_bg_clear_map(ae_memory *mem);
void cmdx2F_setvar(ae_memory *mem);
void cmdx30_fade_obj_pal(ae_memory *mem);
void cmdx31_tbox_flush(ae_memory *mem);
void cmdx32_pal_restore_force_current(ae_memory *mem);
void cmdx33_jump_if_female(ae_memory *mem);
void cmdx34_setflag(ae_memory *mem);
void cmdx35_pal_restore_snapshot(ae_memory *mem);
void cmdx36_load_obj_pal_from_struct(ae_memory *mem);
void _obj_move_sine_trace(u8 self);
void cmdx37_obj_move_trace(ae_memory *mem);
void ae_mapreloader();

void anim_engine_yin_yang_fade_big_callback(u8 self);

void anim_engine_task_nullsub(anim_engine_task *root);

/**
 * Executes all anim engine tasks
 * @param head
 */
void anim_engine_tasks_execute(anim_engine_task *root);

/**
 * Removes an anim engine task
 * You must never remove the root task
 * @param self
 * @return -1 if attempted to delete root, 0 otherwise
 */
int anim_engine_task_delete(anim_engine_task *self);

/**
 * Removes all anim tasks except the root node
 * @param root
 */
void anim_engine_task_delete_all(anim_engine_task *root);

/**
 * Creates new anim task with given priority
 * @param priority priority of new task. Will be executed after all tasks of
 * same priority
 * @param callback the callback function
 * @param size_var_space size of allocated memory for variables
 * if 0 is passed no memory will be allocated
 * @param root root task
 * @return NULL on failure (not enough consecutive memory), pointer to task
 * structure else
 */
anim_engine_task *anim_engine_task_new(int priority,
        void (*callback)(anim_engine_task*),
        unsigned int size_var_space, anim_engine_task *root);


/**
 * Sets up the anim engine root task
 * @return the root task
 */
anim_engine_task *anim_engine_task_setup();

/**
 * Frees all tasks and the root element (engine must re reinitialized)
 * @param root
 */
void anim_engine_task_tear_down(anim_engine_task *root);

/**
 * Returns next availible task id
 * Each id is only assigned once during lifetime of engine
 * meaning they are not recycled after deletion
 * @param root
 * @return next free task id -1 if no task id availible
 */
int anim_engine_task_next_id(anim_engine_task *root);


/**
 * Returns an anim engine task by its id
 * @param root
 * @param id
 * @return pointer to the task struct or NULL if id is not present
 */
anim_engine_task *anim_engine_task_get_by_id(anim_engine_task *root, int id);

#endif
