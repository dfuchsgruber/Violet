#ifndef H_GP_MENU
#define H_GP_MENU

#include "types.h"

typedef struct
{
    const u8 *text;
    union {
        void (*void_u8)(u8);
        u8 (*u8_void)(void);
    } function;
} menu_action_t;

#define GP_MENU_B_PRESSED -1
#define GP_MENU_NOTHING_CHOSEN -2

/**
 * @brief Initializes a menu
 * 
 * @param tbox_idx in which box
 * @param font which font to use
 * @param x the x coordinate in pixels relative to the box upper left corner at which to print items
 * @param y the y coordinate in pixels relative to the box upper left corner
 * @param cursor_height height of the cursor
 * @param num_items the number of items in the menu
 * @param initial_item_idx at which item to initially start
 * @return u8 the position of the cursor
 */
u8 gp_menu_initialize_with_unmuted_a_press(u8 tbox_idx, u8 font, u8 x, u8 y, u8 cursor_height, u8 num_items, u8 initial_item_idx);

/**
 * @brief Prints the items of the gp menu
 * 
 * @param tbox_idx in which box
 * @param font in which font
 * @param left_margin the margin to the left border
 * @param top_margin the margin to the top border
 * @param letter_spacing letter spacing
 * @param line_height the height of each line
 * @param num_items the number of items to print
 * @param items all possible items
 * @param item_idxs the idxs of which items to print (must match `num_items` in length)
 */
void gp_menu_print_items(u8 tbox_idx, u8 font, u8 left_margin, u8 top_margin, u8 letter_spacing,
                        u8 line_height, u8 num_items, const menu_action_t *items, const u8 *item_idxs);

/**
 * @brief Processes inputs for the gp menu such that the cursor does not wrap around
 * 
 * @return int The input
 */
int gp_menu_process_input_no_wrap_around();


#endif