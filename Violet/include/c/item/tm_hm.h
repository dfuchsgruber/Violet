#ifndef H_ITEM_TM_HM
#define H_ITEM_TM_HM

#include "types.h"
#include "list_menu.h"
#include "constants/items.h"
#include "color.h"

#define TM_HM_LIST_MENU_STR_LENGTH 0x30

#define ITEM_IS_TM(item_idx) (((item_idx) >= ITEM_TM01) && ((item_idx) <= ITEM_TM50))
#define ITEM_IS_HM(item_idx) (((item_idx) >= ITEM_VM01) && ((item_idx) <= ITEM_VM08))
#define ITEM_IS_TM_OR_HM(item_idx) (ITEM_IS_TM(item_idx) || ITEM_IS_HM(item_idx))
#define ITEM_IDX_TO_TM_IDX(item_idx) ((item_idx) - ITEM_TM01)
#define ITEM_IDX_TO_HM_IDX(item_idx) ((item_idx) - ITEM_VM01)
#define TM_IDX_TO_ITEM_IDX(tm_idx) ((tm_idx) + ITEM_TM01)
#define TM_HM_IDX_TO_HM_IDX(tm_hm_idx) ((tm_hm_idx) - NUM_TMS)

#define NUM_TMS 50
#define NUM_HMS 8
#define IS_TM(tm_hm_idx)((tm_hm_idx) < NUM_TMS)

enum tm_hm_type
{
    TMHM_FROM_OVERWORLD,
    TMHM_FROM_RECHARGE, // formerly: TMHM_FROMPARTYGIVE, but now hms and tms cant be given via their key item
    TMHM_FROM_SELLING,
    TMHM_FROM_PC,
    TMHM_FROM_BATTLE,
    TMCASE_NA
};

extern list_menu_item *tm_hm_list_menu_items;
extern u8 (*tm_hm_list_menu_strs)[TM_HM_LIST_MENU_STR_LENGTH];
extern const u16 tm_hm_to_attack[NUM_TMS + NUM_HMS];

typedef struct {
    void (* saved_callback)(void);
    u8 tm_oam_idx;
    u8 max_tms_shown;
    u8 num_tms;
    u8 tbox_idx_context;
    u8 scroll_indicator_idx;
    u16 current_idx;
    const u8 * menu_action_idxs;
    u8 num_menu_actions;
    s16 seq_idx;
    u8 filler_14[8];
} tm_hm_state_t;

extern tm_hm_state_t *tm_hm_state;

extern const color_t pal_hm_symbol[2];

/**
 * Initializes the tm / hm used flags
 **/
void tm_used_initialize();

/**
 * Checks if a tm can't be used
 * @param tm_idx the idx of the tm
 **/
bool tm_is_used(int tm_idx);

/**
 * Sets a tm to be used
 * @param tm_idx the idx of the tm
 **/
void tm_set_used(int tm_idx);

/**
 * Places the hm box inside a tbox
 * @param tbox_idx in which box to put it in
 * @param x horizontal offset
 * @param y vertical offset
 **/
void tm_hm_place_hm_in_tbox(u8 tbox_idx, u8 x, u8 y);

/**
 * Translates an item idx (of an tm or hm) to an attack that it represents
 * @param item_idx the item
 * @return the associated attack
 **/
u16 item_idx_to_attack(u16 item_idx);

/**
 * Callback for the tm hm menu on moving the cursor
 * @param idx where the cursor is moved
 * @param on_initialize if it is the intialization
 * @param list the list menu
 **/
void tm_hm_list_menu_cursor_moved_callback(int idx, u8 on_initialize, list_menu *list);

/**
 * Delets the context menu tbox in hm tm menu and writes -1
 * @param where the context menu idx is
 **/
void tm_hm_context_menu_delete(u8 *tbox_idx);

/**
 * Prints the message that there are no pokemon in the party
 * @param self self-reference
 **/
void tm_hm_print_no_pokemon(u8 self);

/**
 * Callback for using an hm / tm
 * @param self self-reference
 * @param function unused
 **/
void item_use_callback_tm_hm(u8 self, void (*function)(u8));

/**
 * Fades out from the tm hm menu
 *  @param self self-reference
 **/
void tm_hm_fade_out_and_exit(u8 self);

/**
 * Prints a string and afterwards executes the continuation.
 * @param self self-reference
 * @param tbox_idx where to print the string
 * @param str the string to print
 * @param continuation the function to set the callback to after the string was printed
 **/
void tm_hm_print_string_with_continuation(u8 self, u8 tbox_idx, u8 *str, void (*continuation)(u8));

/**
 * Continuation callback that waits for a keypress after an error message was printed
 * @param self self-reference
 **/
void tm_hm_wait_for_keypress_after_error_message(u8 self);

/**
 * Initializes the tm hm case
 * @param context in which context to initialize it
 * @param continuation what callback to continue after it closes
 * @param param2
 **/
void tm_hm_initialize(u8 context, void (*continuation)(), u8 param2);

/**
 * Item field effect of the energy disk
 * @param self self-reference
 **/
void item_field_effect_energiedisk(u8 self);

/**
 * @brief Checks if an item as a hm
 * 
 * @param item_idx the item to check
 * @return true 
 * @return false 
 */
bool item_is_hm(u16 item_idx);

/**
 * @brief Checks if an item is a tm
 * 
 * @param item_idx the item to check
 * @return true 
 * @return false 
 */
bool item_is_tm(u16 item_idx);

/**
 * @brief Sets a tm to unused (and therefore usable)
 * 
 * @param tm_idx the index of the tm (not item_idx! use ITEM_IDX_TO_TM_IDX to get the tm index in that case)
 */
void tm_set_unused(int tm_idx);

/**
 * @brief Field functions for all tms and hms
 * 
 * @param self self-reference
 */
void tm_hm_field_function(u8 self);

#endif