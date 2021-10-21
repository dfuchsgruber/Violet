#ifndef H_ITEM_BERRY_POUCH
#define H_ITEM_BERRY_POUCH

#include "types.h"

enum {
    BERRY_POUCH_CONTEXT_MENU_ACTION_USE = 0,
    BERRY_POUCH_CONTEXT_MENU_ACTION_TOSS,
    BERRY_POUCH_CONTEXT_MENU_ACTION_GIVE,
    BERRY_POUCH_CONTEXT_MENU_ACTION_EXIT,
    BERRY_POUCH_CONTEXT_MENU_ACTION_COMPOST, // Replaces : BERRY_POUCH_CONTEXT_MENU_ACTION_NONE,
};

typedef struct {
    void (*continuation)(void);
    u8 type;
    u8 allow_select;
    u8 unused_06;
    u16 list_menu_current_row;
    u16 list_menu_scroll_offset;
} berry_pouch_state2_t;

extern berry_pouch_state2_t berry_pouch_state2;

extern u8 *berry_pouch_context_menu_options;
extern u8 berry_pouch_context_menu_options_count;

/**
 * Action for the berry pouch with standard context menu
 * @param self self-reference
 */
void berry_pouch_action_standard_context_menu(u8 self);

/**
 * Action for the berry pouch for giving berries to party pokemon
 * @param self self-reference
 */
void berry_pouch_action_give_berry(u8 self);

/**
 * Action for the berry pouch for selling berries
 * @param self self-reference
 */
void berry_pouch_action_sell(u8 self);

/**
 * Action for the berry pouch for giving berry to a pc pokemon
 * @param self self-reference
 */
void berry_pouch_action_give_berry_from_pc(u8 self);

/**
 * Gets the tbox idx of a variable tbox
 * @param idx which variable box to access
 * @return the tbox_idx
 */
u8 berry_pouch_get_variable_tbox_idx(u8 idx);

/**
 * Deletes (and frees) a variable tbox
 * @param idx which variable tbox to access
 */
void berry_pouch_variable_tbox_delete(u8 idx);

/**
 * Initializes the ui for selecting a quantity to toss
 * @param self self-reference
 * @param message the text to display
 */
void berry_pouch_initialize_toss_quantity_selection(u8 self, u8 *message);

/**
 * Creates scroll indicators for tossing berries
 */
void berry_pouch_tossing_create_scroll_indicators();

/**
 * Adjusts the quantity selected by keypad input
 * @param quantity the quantity
 * @param max the maximal
 * @return if the quantity changed
 */
bool berry_pouch_adjust_quantity_by_key_input(u16 *quantity, u16 max);

/**
 * Prints the currently selected quantity
 * @param tbox_idx in which box to print
 * @param quantity how many to print
 * @param number_digits how many digits to print at most
 */
void berry_pouch_print_quantity(u8 tbox_idx, u16 quantity, u8 number_digits);

/**
 * Deletes the scroll indicators
 */
void berry_pouch_scroll_indicators_delete();

/**
 * Gets the name of a berry item with the number prefix
 * @param idx which item is selected (in the pouch, i.e. the idx of the list)
 * @param dst where to put the name
 */
void berry_pouch_get_item_name_with_prefix(u16 idx, u8 *dst);

void berry_pouch_print_string(u8 tbox_idx, u8 fontId, const u8 *str, u8 x, u8 y, u8 letter_spacing, u8 line_spacing, u8 speed, u8 color);

/**
 * Gets the tbox idx of a varaible tbox and creates it if not present
 * @param idx the variable idx
 * @return the tbox idx
 */
u8 berry_pouch_get_or_create_variable_tbox(u8 idx);

/**
 * After printing how many were tossed, waits for a keypress and then clears the ui and returns
 * @param self self-reference
 */
void berry_pouch_toss_wait_keypress(u8 self);

/**
 * Callback to be invoked after the player did not confirm the quantity to be tossed
 * @param self self-reference
 */
void berry_pouch_tossing_aborted(u8 self);

/**
 * Relocates the cursor from the list menu
 * @param cursor_idx where to locate the cursor
 * @param color_idx in which color to draw the cursor
 */
void berry_pouch_set_arrow_cursor_from_list_menu(u8 cursor_idx, u8 color_idx);

/**
 * Destroys remenants of the context menu, reinitalizes cursor and palette for the main context and resumes the main context
 * @param self self-reference
 */
void berry_pouch_return_to_main(u8 self);

#endif // H_ITEM_BERRY_POUCH
