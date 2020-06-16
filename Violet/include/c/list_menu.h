/*
 * list_menu.h
 *
 *  Created on: Mar 7, 2019
 *      Author: dominik
 */

#ifndef INCLUDE_C_LIST_MENU_H_
#define INCLUDE_C_LIST_MENU_H_

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
    u16 scroll_offset;
    u16 current_row;
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

#define LIST_MENU_NOTHING_CHOSEN -1
#define LIST_MENU_B_PRESSED -2
/**
 * Processes the input of a list handler.
 * @param list_menu_handler_callback_idx callback index of the list menu handler
 * @return the input
 */
int list_menu_process_input(u8 list_menu_handler_callback_idx);

/**
 * Returns the scroll offset and row of a list menu handler.
 * @param list_menu_handler_callback_idx callback index of the list menu handler
 * @param scroll_offset memory location of the scroll offset
 * @param row memory location of the row
 */
void list_menu_get_scroll_and_row(u8 list_menu_handler_callback_idx, u16 *scroll_offset, u16 *row);

/**
 * Removes a list menu handler.
 * @param list_menu_handler_callback_idx callback index of the list menu handler
 * @param scroll_offset if not null, places the current scroll offset at this memory location
 * @param selected_row if not null, places the currently selected row at this memory location
 */
void list_menu_remove(u8 list_menu_handler_callback_idx, u16 *scroll_offset, u16 *selected_row);

/**
 * Processes the input of the gp list menu and closes it upon selection (or B press).
 * @return the result of processing the input
 **/
int gp_list_menu_process_input_and_close_on_selection();

#endif /* INCLUDE_C_LIST_MENU_H_ */
