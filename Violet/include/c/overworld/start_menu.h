/*
 * menu.h
 *
 *  Created on: May 2, 2018
 *      Author: dominik
 */

#ifndef INCLUDE_C_OVERWORLD_START_MENU_H_
#define INCLUDE_C_OVERWORLD_START_MENU_H_

typedef struct {
    bool (*callback)(void);
    u8 cursor;
    u8 number_items;
    u8 items[9];
    u8 initialization_state;
    u8 number_items_printed;
    u8 safari_tbox_idx;
} start_menu_state_t;

extern start_menu_state_t start_menu_state;

#define START_MENU_GFX_7_SEGMENT_TAG 0x3788
enum start_menu_clock_digit{
    START_MENU_CLOCK_HOURS_10, START_MENU_CLOCK_HOURS_1, START_MENU_CLOCK_MINUTES_10, START_MENU_CLOCK_MINUTES_1
};

extern u8 gfx_start_menu_7_segmentTiles[];
extern u8 gfx_start_menu_7_segmentPal[];

/**
 * Deletes the additional safari and clock windows of the start menu
 */
void start_menu_delete_safari();



/**
 * Builds the item idxs of the start menu
 **/
void start_menu_build();

/**
 * Initializes the textbox for the start menu.
 * @param number_items how many items are to be displayed
 * @return the box idx
 **/
u8 start_menu_tbox_initialize(u8 number_items);

/**
 * Creates a tbox for the safari balls in the start menu.
 **/
void start_menu_print_safari_balls();

/**
 * Draws a certain amount of the start menu items.
 * @param items_drawn_total pointer to how many items were drawn already
 * @param items_to_draw how many items to draw in this iteration
 * @return if all items were drawn with this iteration
 **/
bool start_menu_draw_items(u8 *items_drawn_total, u8 items_to_draw);

/**
 * TODO
 **/
u8 sub_0810f888(int uParm1,int uParm2,int uParm3,int uParm4,int param_1,int param_2, int param_3);

/**
 * Returns the box idx of the start menu box.
 * @return the box idx of the start menu box
 **/
u8 start_menu_get_tbox_idx();

/**
 * Prints the description of an item for the start menu.
 * @param str the description string to print
 **/
void start_menu_print_item_description(u8 *str);

/**
 * Start menu function that initializes saving the game
 **/
void start_menu_call_save();

u8 *start_menu_item_descriptions[9];

#endif /* INCLUDE_C_OVERWORLD_START_MENU_H_ */
