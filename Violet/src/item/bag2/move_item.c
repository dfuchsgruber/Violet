#include "types.h"
#include "item/bag2.h"
#include "callbacks.h"
#include "superstate.h"
#include "menu_util.h"
#include "link.h"
#include "agbmemory.h"
#include "bg.h"
#include "dma.h"
#include "oam.h"
#include "fading.h"
#include "list_menu.h"
#include "overworld/map_control.h"
#include "io.h"
#include "bios.h"
#include "save.h"
#include "flags.h"
#include "constants/item_pockets.h"
#include "transparency.h"
#include "language.h"
#include "debug.h"
#include "list_menu.h"
#include "item/item.h"
#include "music.h"
#include "menu_indicators.h"
#include "overworld/pokemon_party_menu.h"

static void bag_set_insert_bar_visible(bool visible) {
    for (size_t i = 0; i < ARRAY_COUNT(bag2_state->oam_idx_move_item_bar); i++) {
        if (visible)
            oams[bag2_state->oam_idx_move_item_bar[i]].flags &= (u16)(~OAM_FLAG_INVISIBLE);
        else
            oams[bag2_state->oam_idx_move_item_bar[i]].flags |= OAM_FLAG_INVISIBLE;
    }
}

static void bag_set_insert_bar_set_y(u16 y) {
    for (size_t i = 0; i < ARRAY_COUNT(bag2_state->oam_idx_move_item_bar); i++) {
        oams[bag2_state->oam_idx_move_item_bar[i]].y2 = (s16)(y + 0);
    }
}

static void bag_move_item_update_bgs(u8 self) {
    if (dma3_busy(-1) || menu_util_link_is_busy())
        return;
    switch (big_callbacks[self].params[0]) {
        case 0: {
            bag_build_item_list();
            break;
        }
        case 1: {
            u8 pocket_idx = bag_get_current_pocket();
            bag2_state->list_menu_cb_idx = list_menu_new(&gp_list_menu_template, bag_cursor_position[POCKET_TO_BAG_POCKETS_IDX(pocket_idx)], bag_cursor_items_above[POCKET_TO_BAG_POCKETS_IDX(pocket_idx)]);
            break;
        }
        case 2: {
            bag_print_hint(bag_get_context_hint());
            break;
        }
        case 3: {
            bg_virtual_sync_reqeust_push(2);
            bag_set_insert_bar_visible(false);
            bag_new_scroll_indicators_pockets();
            break;
        }
        default: {
            big_callbacks[self].function = bag_idle_callback_default;
            return;
        }
    }
    big_callbacks[self].params[0]++;
}

static void bag_move_item(u8 cb_idx, u16 position_old, u16 position_new) {
    u8 pocket_idx = bag_get_current_pocket();
    if (position_old != position_new && position_old != position_new - 1) {
        item_move_in_pocket(bag_pockets[POCKET_TO_BAG_POCKETS_IDX(pocket_idx)].items, position_old, position_new);
    }
    list_menu_remove(bag2_state->list_menu_cb_idx, bag_cursor_position + POCKET_TO_BAG_POCKETS_IDX(pocket_idx), bag_cursor_items_above + POCKET_TO_BAG_POCKETS_IDX(pocket_idx));
    if (position_old < position_new)
        bag_cursor_items_above[POCKET_TO_BAG_POCKETS_IDX(pocket_idx)]--;
    bag2_state->is_moving_item = false;
    big_callbacks[cb_idx].params[0] = 0;
    big_callbacks[cb_idx].function = bag_move_item_update_bgs;
}

static void bag_moving_item_handle_input(u8 self) {
    if (menu_util_link_is_busy())
        return;
    int input = list_menu_process_input(bag2_state->list_menu_cb_idx);
    u8 pocket = bag_get_current_pocket();
    list_menu_get_scroll_and_row(bag2_state->list_menu_cb_idx, bag_cursor_position + POCKET_TO_BAG_POCKETS_IDX(pocket), bag_cursor_items_above + POCKET_TO_BAG_POCKETS_IDX(pocket));
    u16 pos = (u16)(bag_cursor_position[POCKET_TO_BAG_POCKETS_IDX(pocket)] + bag_cursor_items_above[POCKET_TO_BAG_POCKETS_IDX(pocket)]);
    bag_set_insert_bar_set_y(list_menu_get_cursor_y_pixel(bag2_state->list_menu_cb_idx));
    if (super.keys_new.keys.select) {
        input = pos;
    }
    switch (input) {
        case LIST_MENU_NOTHING_CHOSEN:
            return;
        case LIST_MENU_B_PRESSED:
            play_sound(5);
            bag_move_item(self, pos, pos); // moving from p to p is not doing anything
            break;
        default:
            play_sound(5);
            bag_move_item(self, bag2_state->moving_item_original_position, (u16)input);
            break;
    }
}


static const u8 str_where_should_item_be_moved[] = LANGDEP(PSTRING("Wohin\nverschieben?"), PSTRING("Move to\nwhere?"));

void bag_start_moving_item(u8 cb_idx, u16 position) {
    DEBUG("Start moving item in bag\n");
    u16 cursor, items_above;
    list_menu_get_scroll_and_row(bag2_state->list_menu_cb_idx, &cursor, &items_above);
    list_menu_set_attribute(bag2_state->list_menu_cb_idx, LIST_MENU_ATTRIBUTE_CURSORKIND, 1);
    u8 pocket = bag_get_current_pocket();
    (void)pocket;(void)cb_idx;
    bag2_state->is_moving_item = true;
    bag2_state->moving_item_original_position = (u16)position;
    bag_print_hint(str_where_should_item_be_moved);
    bag_set_insert_bar_visible(true);
    bag_set_insert_bar_set_y(list_menu_get_cursor_y_pixel(bag2_state->list_menu_cb_idx));
    bag_item_list_print_cursor(bag2_state->list_menu_cb_idx, 2);
    bag_delete_scroll_indicators_pockets();
    bg_virtual_sync_reqeust_push(2);
    big_callbacks[cb_idx].function = bag_moving_item_handle_input;
}

bool bag_can_items_be_moved() {
    if (bag_context != BAG_CONTEXT_OVERWORLD)
        return false;
    u8 pocket_idx = bag_get_current_pocket();
    if (pocket_idx == POCKET_TM_HM || pocket_idx == POCKET_BERRIES)
        return false;
    return true;
}