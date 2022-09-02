/*
 * list_menu.h
 *
 *  Created on: Mar 7, 2019
 *      Author: dominik
 */

#ifndef INCLUDE_C_LIST_MENU_H_
#define INCLUDE_C_LIST_MENU_H_

#include "types.h"
#include "text.h"

#define LIST_MENU_NOTHING_CHOSEN -1
#define LIST_MENU_B_PRESSED -2
#define LIST_MENU_HEADER -3

#define LIST_MENU_NO_MULTIPLE_SCROLL     0
#define LIST_MENU_MULTIPLE_SCROLL_DPAD   1
#define LIST_MENU_MULTIPLE_SCROLL_L_R 2

typedef struct {
  const u8 *text;
  int idx;
} list_menu_item;

struct list_menu;
typedef struct list_menu list_menu;

typedef struct {
  list_menu_item *items;
  void (*cursor_moved_callback)(int idx, u8 on_initialize, list_menu *list);
  void (*item_print_callback)(u8 tbox_idx, int idx, u8 y);
  u16 item_cnt;
  u16 max_items_showed;
  u8 tbox_idx;
  u8 header_x;
  u8 item_x;
  u8 cursor_x;
  u8 up_text_y:4; // x1, x2, x4, x8 = xF
  u8 cursor_pal:4; // x10, x20, x40, x80 = xF0
  u8 fill_value:4; // x1, x2, x4, x8 = xF
  u8 cursor_shadow_color:4; // x10, x20, x40, x80 = xF0
  u8 letter_spacing:3;
  u8 item_vertical_padding:3;
  u8 scroll_multiple:2; // x40, x80 = xC0
  u8 font:6; // x1, x2, x4, x8, x10, x20 = x3F
  u8 cursor_kind:2; // x40, x80
} list_menu_template;

typedef struct list_menu
{
    list_menu_template _template;
    u16 cursor_position;
    u16 items_above;
    u8 unk_1C;
    u8 unk_1D;
    u8 callback_idx;
    u8 unk_1F;
} list_menu_t;

typedef struct {
  u8 x_offset;
  u8 y_offset;
  u8 cursor_idx;
  u8 cursor_min;
  u8 cursor_max;
  u8 tbox_idx;
  u8 font;
  u8 field_7;
  u8 line_height;
  u8 field_9;
  u8 field_10;
  u8 field_11;
} gp_list_menu_t;

extern gp_list_menu_t gp_list_menu;

extern list_menu_template gp_list_menu_template;

/**
 * Generic callback for moving the cursor in a list menu. Plays only sound 5.
 * @param idx the index of the current item
 * @param on_initialize true if and only if the menu is initialized
 * @param list the list items
 */
void list_menu_generic_cursor_callback(int idx, u8 on_initialize, list_menu *list);

/**
 * Creates a new list menu.
 * @param _template the template for the list menu to create
 * @param scroll_offset current scroll offset
 * @param selected_row the index of the currently selected item
 * @return idx of the list menu handler (big callback)
 */
u8 list_menu_new(list_menu_template *_template, u16 scroll_offset, u16 selected_row);

/**
 * Processes the input of a list handler.
 * @param list_menu_handler_callback_idx callback index of the list menu handler
 * @return the input
 */
int list_menu_process_input(u8 list_menu_handler_callback_idx);

/**
 * Returns the scroll offset and row of a list menu handler.
 * @param list_menu_handler_callback_idx callback index of the list menu handler
 * @param scroll_offset memory address where to put: How many elements are "scrolled-away", i.e. not visible and above the currently visible sublist
 * @param row memory address where to put: The cursors x-position in the currently visible sublist
 */
void list_menu_get_scroll_and_row(u8 list_menu_handler_callback_idx, u16 *scroll_offset, u16 *row);

/**
 * Removes a list menu handler.
 * @param list_menu_handler_callback_idx callback index of the list menu handler
 * @param scroll_offset if not null, places the current scroll offset at this memory location
 * @param selected_row if not null, places the currently selected row at this memory location
 */
void list_menu_remove(u8 list_menu_handler_callback_idx, u16 *scroll_offset, u16 *selected_row);

// Dont ask me why this is inconsistent with the list_menu's constants for key presses
#define GP_LIST_MENU_B_PRESSED -1

/**
 * Processes the input of the gp list menu and closes it upon selection (or B press).
 * @return the result of processing the input
 **/
int gp_list_menu_process_input_and_close_on_selection();

/**
 * Prints (i.e. redraws) a list menu
 * @param callback_idx the callback of the list menu
 **/
void list_menu_print(u8 callback_idx);

/**
 * Prints a yes/no box on the gp list template.
 * @param tbox the box to create
 * @param font the font to use
 * @param x x coordinate of the text
 * @param y y coordiante of the text
 * @param base_tile base tile of the border frame
 * @param pal the palette of the border frame
 * @param border_base_tile where to initially place the cursor
 **/
void gp_list_menu_yes_no_new(tboxdata *tbox, u8 font, u8 x, u8 y, u16 border_base_tile, u8 pal, u8 initial_cursor_position);

typedef struct {
  void (*yes_callback)(u8);
  void (*no_callback)(u8);
} yes_no_box_callbacks_t;

/**
 * @brief Prints a yes / no box on the gp list template in a callback and executes pre-defined functions on key-press.
 * 
 * @param cb_idx The callback to handle the yes / no box
 * @param tbox in which tbox
 * @param font in which font
 * @param x left margin within the box (in pixels)
 * @param y top marign within the box (in pixels)
 * @param frame_base_tile at which base tile the frame is located
 * @param frame_pal in which pal to print the box
 * @param callbacks the callbacks to execute on yes / no press
 */
void gp_list_menu_yes_no_new_with_callbacks(u8 cb_idx, tboxdata *tbox, u8 font, u8 x, u8 y, u16 frame_base_tile, u8 frame_pal, yes_no_box_callbacks_t *callbacks);

/**
 * @brief Gets the y coordinate (in pixels) of the cursor of a list menu
 * 
 * @param list_menu_cb_idx The list menu
 * @return u8 The y coordinate of the cursor in pixels
 */
u8 list_menu_get_cursor_y_pixel(u8 list_menu_cb_idx);

enum {
  CURSOR_DIMENSION_WIDTH = 0,
  CURSOR_DIMENSION_HEIGHT,
};

/**
 * @brief Gets the dimension of a list cursor in a given font
 * 
 * @param font The font of the cursor
 * @param dimension The dimension to get (one of CURSOR_DIMENSION_WIDTH, CURSOR_DIMENSION_HEIGHT)
 * @return u16 the dimension
 */
u16 list_menu_get_cursor_dimension(u8 font, u8 dimension);

enum {
    LIST_MENU_ATTRIBUTE_MOVECURSORFUNC = 0,
    LIST_MENU_ATTRIBUTE_MOVECURSORFUNC2,
    LIST_MENU_ATTRIBUTE_TOTALITEMS,
    LIST_MENU_ATTRIBUTE_MAXSHOWED,
    LIST_MENU_ATTRIBUTE_WINDOWID,
    LIST_MENU_ATTRIBUTE_HEADERX,
    LIST_MENU_ATTRIBUTE_ITEMX,
    LIST_MENU_ATTRIBUTE_CURSORX,
    LIST_MENU_ATTRIBUTE_UPTEXTY,
    LIST_MENU_ATTRIBUTE_CURSORPAL,
    LIST_MENU_ATTRIBUTE_FILLVALUE,
    LIST_MENU_ATTRIBUTE_CURSORSHADOWPAL,
    LIST_MENU_ATTRIBUTE_LETTERSPACING,
    LIST_MENU_ATTRIBUTE_ITEMVERTICALPADDING,
    LIST_MENU_ATTRIBUTE_SCROLLMULTIPLE,
    LIST_MENU_ATTRIBUTE_FONTID,
    LIST_MENU_ATTRIBUTE_CURSORKIND,
};

/**
 * @brief Sets an attribute of a list menu
 * 
 * @param list_menu_cb_idx the list menu
 * @param attribute the attribute to set
 * @param value the value to set the attribute to
 */
void list_menu_set_attribute(u8 list_menu_cb_idx, u8 attribute, int value);

/**
 * @brief Gets an attribute of a list menu
 * 
 * @param list_menu_cb_idx the list menu
 * @param attribute the attribute to get
 * @return int the attribute
 */
int list_menu_get_attribute(u8 list_menu_cb_idx, u8 attribute);

/**
 * @brief Updates the `cursor_position` and `items_above` attributes of `list` for scrolling once
 * 
 * @param list the list to update
 * @param is_moving_down if to scroll down or up
 * @return u8 the result
 */
u8 list_menu_update_cursor_position_and_items_above(list_menu *list, bool is_moving_down);

/**
 * @brief Prints items to the box of the list menu
 * 
 * @param list the list to print
 * @param start_index starting from which index
 * @param y_offset at which y offset
 * @param num_items how many items to print
 */
void list_menu_print_items(list_menu *list, u16 start_index, u16 y_offset, u16 num_items);

/**
 * @brief Calls the cursor move callback if present
 * 
 * @param list the list on which the callback is to be called
 * @param on_init if the cursor is moved on initialization
 */

void list_menu_call_cursor_move_callback(list_menu *list, bool on_init);
/**
 * @brief Searches for an item in the list menu and places the cursor there
 * 
 * @param cb_idx the callback of the list menu
 * @param item_idx which item to find: an item is selected if its `idx` attribute matches `item_idx`
 * @param call_cursor_move_callback if true, the cursor_move callback is invoked
 * @return true 
 * @return false 
 */
bool list_menu_search(u8 cb_idx, int item_idx, bool call_cursor_move_callback);

#endif /* INCLUDE_C_LIST_MENU_H_ */
