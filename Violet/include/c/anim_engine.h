#ifndef H_ANIM_ENGINE
#define H_ANIM_ENGINE

#include "types.h"
#include "color.h"
#include "text.h"
#include "constants/cutscenes.h"

typedef struct anim_engine_task{
    int priority;
    int id;
    struct anim_engine_task *prev;
    struct anim_engine_task *next;
    void (*callback)(struct anim_engine_task*);
    void *vars;
} anim_engine_task;

typedef struct animation_engine_state_t {
    u16 current_frame;
    const u8 *script;
    u8 callback_id;
    u8 active : 1;
    u8 paused : 1;
    int delayed;
    u8 num_printers_waited_for;
    u8 stack_size;
    const u8 *stack[8];
    u16 vars[16];
    color_t *pal_restore_save;
    anim_engine_task *root; // Doubly-linked list, sorted by priority
} animation_engine_state_t ;

extern EWRAM animation_engine_state_t *animation_engine_state;
extern const u8 *const cutscene_scripts[NUM_CUTSCENES];

void init_anim_engine_by_table();
void anim_engine_initiatlize(const u8 *script);
void anim_engine_callback(u8 callback_id);
void anim_engine_execute_frame(animation_engine_state_t * mem);
u8 anim_engine_read_byte(animation_engine_state_t * mem);
u16 anim_engine_get_hword(animation_engine_state_t *mem);
u32 anim_engine_read_word(animation_engine_state_t * mem);
u16 anim_engine_read_hword(animation_engine_state_t * mem);
u16 anim_engine_read_param(animation_engine_state_t * mem);
//void anim_engine_tbox_renderer(u8 cbid);
void _obj_move_linear_trace(anim_engine_task *self);
void anim_engine_fader(anim_engine_task *self);
void callback_maintain();
/**
/ Command Functions
 **/
void cmdx00_end(animation_engine_state_t * mem);
void cmdx01_call(animation_engine_state_t * mem);
void cmdx02_jump(animation_engine_state_t * mem);
void cmdx03_oam_new(animation_engine_state_t * mem);
void cmdx04_oam_delete(animation_engine_state_t * mem);
void cmdx05_oam_vram_load(animation_engine_state_t * mem);
void cmdx06_oam_vram_free(animation_engine_state_t * mem);
void cmdx07_oam_despawn(animation_engine_state_t * mem);
void cmdx08_spawn_callback(animation_engine_state_t * mem);
void cmdx09_bg_reset(animation_engine_state_t * mem);
void cmdx0A_bg_setup(animation_engine_state_t * mem);
void cmdx0B_bg_sync_and_show(animation_engine_state_t * mem);
void cmdx0C_bg_hide(animation_engine_state_t * mem);
void cmdx0D_bg_display_sync();
void cmdx0E_bg_override(animation_engine_state_t * mem);
void cmdx0F_load_obj_pal(animation_engine_state_t * mem);
void cmdx10_free_obj_pal(animation_engine_state_t * mem);
void cmdx11_get_io(animation_engine_state_t * mem);
void cmdx12_set_io_to_var(animation_engine_state_t * mem);
void cmdx13_set_io_to_value(animation_engine_state_t *mem);
void cmdx14_prepare_tbox(animation_engine_state_t *mem);
void cmdx15_display_text_inst(animation_engine_state_t *mem);
void cmdx16_clear_textbox(animation_engine_state_t *mem);
void cmdx17_display_rendered_tbox(animation_engine_state_t *mem);
void cmdx18_rendered_tbox_event(animation_engine_state_t * mem);
void cmdx19_objmove(animation_engine_state_t * mem);
void anim_engine_cmdx1A(animation_engine_state_t * mem);
void cmdx1B_gfx_anim_set(animation_engine_state_t *mem);
void cmdx1C_rs_anim_set(animation_engine_state_t *mem);
void cmdx1D_loadpal(animation_engine_state_t *mem);
void cmdx1E_fade(animation_engine_state_t *mem);
void cmdx1F_invertcolors(animation_engine_state_t * mem);
void cmdx20_sound(animation_engine_state_t * mem);
void cmdx21_song(animation_engine_state_t * mem);
void cmdx22_cry(animation_engine_state_t * mem);
void cmdx23_maintain();
void cmdx24_script_notify();
void cmdx25_oam_reset();
void cmdx26_callback_reset(animation_engine_state_t *mem);
void cmdx27_dma3_controller_reset();
void anim_engine_bg_free_task(anim_engine_task *self);
void cmdx28_bg_displacement_reset();
void cmdx29_bg_vmap_init(animation_engine_state_t *mem);
void cmdx2A_bg_vmap_drop(animation_engine_state_t *mem);
void cmdx2B_bg_scroll(animation_engine_state_t *mem);
void anim_engine_bg_scroller(anim_engine_task *self);
void cmdx2C_mapreload();
void cmdx2D_force_pals_to_black();
void cmdx2E_bg_clear_map(animation_engine_state_t *mem);
void cmdx2F_setvar(animation_engine_state_t *mem);
void cmdx30_fade_obj_pal(animation_engine_state_t *mem);
void cmdx31_tbox_flush(animation_engine_state_t *mem);
void cmdx32_pal_restore_force_current(animation_engine_state_t *mem);
void cmdx33_jump_if_female(animation_engine_state_t *mem);
void cmdx34_setflag(animation_engine_state_t *mem);
void cmdx35_pal_restore_snapshot(animation_engine_state_t *mem);
void cmdx36_load_obj_pal_from_struct(animation_engine_state_t *mem);
void _obj_move_sine_trace(u8 self);
void cmdx37_obj_move_trace(animation_engine_state_t *mem);
void cmdx38_tbox_and_interrupt(animation_engine_state_t *mem);
void cmdx39_pause(animation_engine_state_t *mem);
void cmdx3A_task_delete_all(animation_engine_state_t *mem);
void cmd_nop(animation_engine_state_t *mem);
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
