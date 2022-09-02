#include "types.h"
#include "list_menu.h"
#include "callbacks.h"
#include "debug.h"

bool list_menu_search(u8 cb_idx, int item_idx, bool call_cursor_move_callback) {
    list_menu *list = (list_menu*) big_callbacks[cb_idx].params;
    // First, check if the desired item exists in the list
    bool exists = false;
    for (int i = 0; i < list->_template.item_cnt; i++) {
        if (list->_template.items[i].idx != LIST_MENU_HEADER && list->_template.items[i].idx == item_idx) {
            exists = true;
            break;
        }
    }
    DEBUG("Looking for item %d, exists %d\n", item_idx, exists);
    if (!exists)
        return false;
    // Now, find the item: We reset cursor and items above to 0 and scroll down
    list->cursor_position = 0;
    list->items_above = 0;
    while (list->_template.items[list->cursor_position + list->items_above].idx != item_idx) {
        list_menu_update_cursor_position_and_items_above(list, true);
    }
    DEBUG("Found item %d with cursor pos %d and items above %d\n", item_idx, list->cursor_position, list->items_above);
    // Re-draw
    list_menu_print(cb_idx);
    if (call_cursor_move_callback)
        list_menu_call_cursor_move_callback(list, false);
    return true;
}