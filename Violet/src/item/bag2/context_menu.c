#include "types.h"
#include "item/bag2.h"
#include "language.h"
#include "item/item.h"
#include "overworld/pokemon_party_menu.h"
#include "callbacks.h"
#include "list_menu.h"
#include "gp_menu.h"
#include "text.h"
#include "link.h"
#include "dma.h"
#include "agbmemory.h"
#include "debug.h"
#include "pokemon/virtual.h"
#include "music.h"
#include "menu_indicators.h"

static u8 str_use[] = LANGDEP(PSTRING("O.K."), PSTRING("Use"));
static u8 str_give[] = LANGDEP(PSTRING("Geben"), PSTRING("Give"));
static u8 str_toss[] =  LANGDEP(PSTRING("Müll"), PSTRING("Toss"));
static u8 str_cancel[] = LANGDEP(PSTRING("Zurück"), PSTRING("Cancel"));

static u16 bag_context_menu_get_start_tile() {
    u16 start_tile = 0;
    for (int i = 0; i < NUM_BAG_TBOXES; i++) {
        start_tile = (u16)MAX(start_tile, bag_tboxes[i].start_tile + (bag_tboxes[i].w * bag_tboxes[i].h));
    }
    return start_tile;
}

void bag_reinitialize_scroll_menu_indicators_and_return_to_idle_callback(u8 self) {
    bag_new_scroll_indicators_items();
    bag_new_scroll_indicators_pockets();
    big_callbacks[self].function = bag_idle_callback_default;
}

void bag_reinitialize_list_and_scroll_menu_indicators_and_return_to_idle_callback(u8 self) {
    u8 pocket_idx = bag_get_current_pocket();
    list_menu_remove(BAG2_STATE->list_menu_cb_idx, fmem.bag_cursor_position + POCKET_TO_BAG_POCKETS_IDX(pocket_idx), fmem.bag_cursor_items_above + POCKET_TO_BAG_POCKETS_IDX(pocket_idx));
    bag_initialize_compute_item_counts();
    bag_initialize_list_cursor_positions();
    bag_build_item_list();
    BAG2_STATE->list_menu_cb_idx = list_menu_new(&gp_list_menu_template, fmem.bag_cursor_position[POCKET_TO_BAG_POCKETS_IDX(pocket_idx)], fmem.bag_cursor_items_above[POCKET_TO_BAG_POCKETS_IDX(pocket_idx)]);
    bag_print_item_description(bag_get_current_slot_in_current_pocket());
    tbox_tilemap_draw(BAG_TBOX_DESCRIPTION);
    bg_virtual_sync_reqeust_push(0);
    big_callbacks[self].function = bag_reinitialize_scroll_menu_indicators_and_return_to_idle_callback;
}

void bag_wait_a_button_and_close_message_and_return_to_idle_callback(u8 self) {
    if (super.keys_new.keys.A) {
        play_sound(5);
        // tbox_flush_map(BAG_TBOX_MESSAGE);
        tbox_clear_message(BAG_TBOX_MESSAGE, false);
        bg_virtual_sync_reqeust_push(0);
        bag_reinitialize_list_and_scroll_menu_indicators_and_return_to_idle_callback(self);
    }
} 

void bag_menu_cancel_redraw_description_and_scroll_menu_indicators_and_return_to_idle_callback(u8 self) {
    tbox_tilemap_draw(BAG_TBOX_DESCRIPTION);
    tbox_tilemap_draw(BAG_TBOX_LIST);
    bg_virtual_sync_reqeust_push(0);
    bag_reinitialize_scroll_menu_indicators_and_return_to_idle_callback(self);
}


static u8 str_there_is_no_pokemon[] = LANGDEP(PSTRING("Du hast keine\nPokémon."), PSTRING("There is no\nPokémon."));

static void bag_context_menu_item_use(u8 self) {
    void (*field_function)(u8) = item_get_field_function(item_activated);
    DEBUG("Use item %d with field func 0x%x", item_activated, field_function);
    if (field_function) {
        tbox_flush_all(BAG2_STATE->tbox_context_menu, 0x00);
        tbox_flush_map(BAG2_STATE->tbox_context_menu);
        tbox_free_2(BAG2_STATE->tbox_context_menu);
        tbox_flush_map(BAG_TBOX_CONTEXT_MENU_TEXT);
        tbox_tilemap_draw(BAG_TBOX_LIST);
        bg_virtual_sync_reqeust_push(0);
        if (true || (item_get_type(item_activated) && pokemon_get_number_in_party() == 0)) {
            bag_print_string(self, 2, str_there_is_no_pokemon, bag_wait_a_button_and_close_message_and_return_to_idle_callback);
        } else {
            field_function(self);
        }

    }
}

static void bag_context_menu_item_cancel(u8 self) {
    tbox_flush_all(BAG2_STATE->tbox_context_menu, 0x00);
    tbox_flush_map(BAG2_STATE->tbox_context_menu);
    tbox_free_2(BAG2_STATE->tbox_context_menu);
    tbox_flush_map(BAG_TBOX_CONTEXT_MENU_TEXT);
    bag_print_item_description(bag_get_current_slot_in_current_pocket());
    big_callbacks[self].function = (void(*)(u8))bag_menu_cancel_redraw_description_and_scroll_menu_indicators_and_return_to_idle_callback;
}

static void bag_toss_or_sell_wait_a_or_b_press_and_redraw_all(u8 self) {
    if (super.keys_new.keys.A || super.keys_new.keys.B) {
        play_sound(5);
        item_remove(item_activated, BAG2_STATE->toss_current_number);
        tbox_clear_message(BAG_TBOX_MESSAGE, false);
        bg_virtual_sync_reqeust_push(0);
        bag_reinitialize_list_and_scroll_menu_indicators_and_return_to_idle_callback(self);
    }
}

static bool bag_toss_or_sell_process_input() {
    if (super.keys_new.keys.up) {
        BAG2_STATE->toss_current_number++;
        if (BAG2_STATE->toss_current_number > BAG2_STATE->toss_max_number)
            BAG2_STATE->toss_current_number = 1;
        return true;
    } else if (super.keys_new.keys.down) {
        BAG2_STATE->toss_current_number--;
        if (BAG2_STATE->toss_current_number == 0)
            BAG2_STATE->toss_current_number = BAG2_STATE->toss_max_number;
        return true;
    } else {
        return false;
    }
}

static u8 str_tossed_items[] = LANGDEP(PSTRING("BUFFER_1×BUFFER_2\nweggeworfen."), PSTRING("Tossed BUFFER_1×BUFFER_2."));

static void bag_toss_confirm_yes(u8 self) {
    // tbox_clear_message(BAG_TBOX_MESSAGE_WITH_YES_NO, false);
    tbox_flush_map_and_frame(BAG_TBOX_MESSAGE_WITH_YES_NO);
    strcpy(buffer0, item_get_name(item_activated));
    itoa(buffer1, BAG2_STATE->toss_current_number, ITOA_NO_PADDING, 3);
    string_decrypt(strbuf, str_tossed_items);
    bag_print_string(self, 2, strbuf, bag_toss_or_sell_wait_a_or_b_press_and_redraw_all);
}

static void bag_toss_confirm_no(u8 self) {
    // tbox_clear_message(BAG_TBOX_MESSAGE_WITH_YES_NO, false);
    tbox_flush_map_and_frame(BAG_TBOX_MESSAGE_WITH_YES_NO);
    bg_virtual_sync_reqeust_push(0);
    bag_print_item_description(bag_get_current_slot_in_current_pocket());
    big_callbacks[self].function = (void(*)(u8))bag_menu_cancel_redraw_description_and_scroll_menu_indicators_and_return_to_idle_callback;
}

static yes_no_box_callbacks_t yes_no_callbacks_toss = {
    .no_callback = bag_toss_confirm_no,
    .yes_callback = bag_toss_confirm_yes,
};

static u8 str_confirm_toss[] = LANGDEP(PSTRING("BUFFER_1×BUFFER_2\nwirklich wegwerfen?"), PSTRING("Toss\nBUFFER_1×BUFFER_2?"));

static void bag_confirm_toss(u8 self) {
    strcpy(buffer0, item_get_name(item_activated));
    itoa(buffer1, BAG2_STATE->toss_current_number, ITOA_NO_PADDING, 3);
    string_decrypt(strbuf, str_confirm_toss);
    tbox_draw_std_frame_by_base_tile_and_pal(BAG_TBOX_MESSAGE_WITH_YES_NO, true, BAG_START_TILE_BORDER_STD, BAG_PAL_IDX_BORDER_STD);
    tbox_print_string(BAG_TBOX_MESSAGE_WITH_YES_NO, 2, 0, 0, 0, 0, &bag_font_colormap_std, 0, strbuf);
    bg_virtual_sync_reqeust_push(0);
    tboxdata template = {.bg_id = 0, .h = 2 * 2, .w = 5, .x = 30 - 5 - 1, .y = (u8)(20 - 1 - (2 * 2)), .pal = 14, .start_tile = bag_context_menu_get_start_tile()};
    gp_list_menu_yes_no_new_with_callbacks(self, &template, 2, 0, 0, BAG_START_TILE_BORDER_STD, BAG_PAL_IDX_BORDER_STD, &yes_no_callbacks_toss);
}

static u8 str_quantity_x[] = PSTRING("×BUFFER_1");

static void bag_toss_or_sell_update_quantity(u8 number_digits) {
    tbox_flush_set(BAG2_STATE->tbox_quantity, 0x11);
    itoa(buffer0, BAG2_STATE->toss_current_number, ITOA_PAD_ZEROS, number_digits);
    string_decrypt(strbuf, str_quantity_x);
    tbox_print_string(BAG2_STATE->tbox_quantity, 0, 4, 10, 1, 0, &bag_font_colormap_std, 0, strbuf);
}

static scroll_indicator_template scroll_indicator_quantity_template = {
    .arrow0_type = SCROLL_ARROW_UP, .arrow0_x = 212, .arrow0_y = 120,
    .arrow1_type = SCROLL_ARROW_DOWN, .arrow1_x = 212, .arrow1_y = 152,
    .arrow0_threshold = 0, 
    .arrow1_threshold = 1000,
    .tiles_tag = 110,
    .pal_tag = 110,
};

static void bag_toss_or_sell_initiaize_quantity(u8 *str, u8 number_digits) {
    tbox_draw_std_frame_by_base_tile_and_pal(BAG_TBOX_MESSAGE_WITH_YES_NO, true, BAG_START_TILE_BORDER_STD, BAG_PAL_IDX_BORDER_STD);
    tbox_print_string(BAG_TBOX_MESSAGE_WITH_YES_NO, 2, 0, 0, 0, 0, &bag_font_colormap_std, 0, str);
    bg_virtual_sync_reqeust_push(0);
    tboxdata template = {.bg_id = 0, .h = 2 * 2, .w = 5, .x = 30 - 5 - 1, .y = (u8)(20 - 1 - (2 * 2)), .pal = 14, .start_tile = bag_context_menu_get_start_tile()};
    BAG2_STATE->tbox_quantity = tbox_new(&template);
    tbox_tilemap_draw(BAG2_STATE->tbox_quantity);
    tbox_draw_std_frame_by_base_tile_and_pal(BAG2_STATE->tbox_quantity, false, BAG_START_TILE_BORDER_SET_STYLE, BAG_PAL_IDX_SET_STYLE);
    bag_toss_or_sell_update_quantity(number_digits);
    BAG2_STATE->scroll_indicator_quantity_cb_idx = scroll_indicator_new(&scroll_indicator_quantity_template, &BAG2_STATE->toss_current_number);
}

static void bag_select_quantity_to_toss(u8 self) {
    (void)self;
    if (bag_toss_or_sell_process_input()) {
        play_sound(5);
        bag_toss_or_sell_update_quantity(3);
    } else if (super.keys_new.keys.A) {
        play_sound(5);
        tbox_flush_set(BAG2_STATE->tbox_quantity, 0x00);
        tbox_flush_map_and_frame(BAG2_STATE->tbox_quantity);
        tbox_free_2(BAG2_STATE->tbox_quantity);
        bg_virtual_sync_reqeust_push(0);
        scroll_indicator_delete(BAG2_STATE->scroll_indicator_quantity_cb_idx);
        bag_confirm_toss(self);
    } else if (super.keys_new.keys.B) {
        play_sound(5);
        tbox_flush_set(BAG2_STATE->tbox_quantity, 0x00);
        tbox_flush_map_and_frame(BAG2_STATE->tbox_quantity);
        tbox_free_2(BAG2_STATE->tbox_quantity);
        bg_virtual_sync_reqeust_push(0);
        scroll_indicator_delete(BAG2_STATE->scroll_indicator_quantity_cb_idx);
        bag_reinitialize_list_and_scroll_menu_indicators_and_return_to_idle_callback(self);
    }
}

static u8 str_toss_how_many[] = LANGDEP(PSTRING("Wie viel\nwegwerfen?"), PSTRING("Toss how many?"));

static void bag_context_menu_item_toss(u8 self) {
    // Close the context menu and hide tboxes
    tbox_flush_all(BAG2_STATE->tbox_context_menu, 0x00);
    tbox_flush_map(BAG2_STATE->tbox_context_menu);
    tbox_free_2(BAG2_STATE->tbox_context_menu);
    tbox_flush_map(BAG_TBOX_CONTEXT_MENU_TEXT);
    tbox_tilemap_draw(BAG_TBOX_LIST);
    bg_virtual_sync_reqeust_push(0);

    u8 pocket = bag_get_current_pocket();
    u16 quantity = item_get_quantity_by_pocket_position(pocket, bag_get_current_slot_in_current_pocket());
    BAG2_STATE->toss_max_number = quantity;
    BAG2_STATE->toss_current_number = 1;

    DEBUG("Quantity is %d, item is %d\n", quantity, item_get_idx_by_pocket_position(pocket, bag_get_current_slot_in_current_pocket()));
    if (quantity <= 1) { // Confirm a single toss
        big_callbacks[self].function = bag_confirm_toss;
    } else { // Select quantity to toss
        bag_toss_or_sell_initiaize_quantity(str_toss_how_many, 3);
        big_callbacks[self].function = bag_select_quantity_to_toss;
    }

}

static void bag_context_menu_item_give_continuation() {
    pokemon_party_menu_state.bag_item = item_activated;
    pokemon_party_menu_init(PARTY_MENU_TYPE_FIELD, PARTY_LAYOUT_SINGLE, PARTY_ACTION_GIVE_ITEM, false, PARTY_MSG_GIVE_TO_WHICH_MON, pokemon_party_menu_big_callback_select_pokemon, bag2_return_to_last);
}

static u8 str_cant_be_given[] = LANGDEP(PSTRING("BUFFER_1 kann nicht\ngetragen werden."), PSTRING("BUFFER_1 can't be held."));

static void bag_context_menu_item_give(u8 self) {
    tbox_flush_all(BAG2_STATE->tbox_context_menu, 0x00);
    tbox_flush_map(BAG2_STATE->tbox_context_menu);
    tbox_free_2(BAG2_STATE->tbox_context_menu);
    tbox_flush_map(BAG_TBOX_CONTEXT_MENU_TEXT);
    tbox_tilemap_draw(BAG_TBOX_LIST);
    bg_virtual_sync_reqeust_push(0);
    if (item_can_be_tossed(item_activated)) {
        if (pokemon_get_number_in_party() == 0) {
            bag_print_string(self, 2, str_there_is_no_pokemon, bag_wait_a_button_and_close_message_and_return_to_idle_callback);
        } else {
            BAG2_STATE->internal_continuation = bag_context_menu_item_give_continuation;
            bag_close(self, item_activated, false);
        }
    } else {
        strcpy(buffer0, item_get_name(item_activated));
        string_decrypt(strbuf, str_cant_be_given);
        bag_print_string(self, 2, strbuf, bag_wait_a_button_and_close_message_and_return_to_idle_callback);
    }
}

menu_action_t bag_context_menu_items[NUM_BAG_CONTEXT_MENU_ITEMS] = {
    [BAG_CONTEXT_MENU_USE] = {.text = str_use, .function = {.void_u8 = bag_context_menu_item_use}},
    [BAG_CONTEXT_MENU_GIVE] = {.text = str_give, .function = {.void_u8 = bag_context_menu_item_give}},
    [BAG_CONTEXT_MENU_TOSS] = {.text = str_toss, .function = {.void_u8 = bag_context_menu_item_toss}},
    [BAG_CONTEXT_MENU_CANCEL] = {.text = str_cancel, .function = {.void_u8 = bag_context_menu_item_cancel}},
};


static u8 str_item_is_selected[] = LANGDEP(PSTRING("BUFFER_1\nist ausgewählt!"), PSTRING("BUFFER_1\nis selected!"));


static void bag_disable_ui() {
    // Disable bag ui
    bag_item_list_print_cursor(BAG2_STATE->list_menu_cb_idx, 2);
    bag_delete_scroll_indicators_pockets();
    bag_delete_scroll_indicators_items();
    tbox_flush_map(BAG_TBOX_DESCRIPTION);
    bg_virtual_sync_reqeust_push(0);
}

static void bag_open_context_menu(u8 *items, size_t num_items) {
    (void)items;(void)num_items;

    BAG2_STATE->num_context_menu_items = (u8)num_items;
    memcpy(BAG2_STATE->context_menu_items, items, num_items * sizeof(BAG2_STATE->context_menu_items[0]));

    // Create tbox context menu box
    tboxdata template = {.bg_id = 0, .h = (u8)(num_items * 2), .w = 8, .x = 30 - 8 - 1, .y = (u8)(20 - 1 - (num_items * 2)), .pal = 14, .start_tile = bag_context_menu_get_start_tile()};
    BAG2_STATE->tbox_context_menu = tbox_new(&template);
    tbox_flush_set(BAG2_STATE->tbox_context_menu, 0x11);
    tbox_tilemap_draw(BAG2_STATE->tbox_context_menu);
    tbox_draw_std_frame_by_base_tile_and_pal(BAG2_STATE->tbox_context_menu, false, BAG_START_TILE_BORDER_SET_STYLE, BAG_PAL_IDX_SET_STYLE);
    gp_menu_print_items(BAG2_STATE->tbox_context_menu, 2, (u8)list_menu_get_cursor_dimension(2, CURSOR_DIMENSION_WIDTH), 2, font_get_attribute(2, FONT_ATTRIBUTE_LETTER_SPACING),
        (u8)(font_get_attribute(2, FONT_ATTRIBUTE_MAX_LETTER_HEIGHT) + 2), (u8)num_items, bag_context_menu_items, items);
    
    gp_menu_initialize_with_unmuted_a_press(BAG2_STATE->tbox_context_menu, 2, 0, 2, (u8)(font_get_attribute(2, FONT_ATTRIBUTE_MAX_LETTER_HEIGHT) + 2), (u8)num_items, 0);
    
    bg_virtual_sync_reqeust_push(0);

    // Print the right text
    tbox_flush_set(BAG_TBOX_CONTEXT_MENU_TEXT, 0x00);
    tbox_tilemap_draw(BAG_TBOX_CONTEXT_MENU_TEXT);
    strcpy(buffer0, item_get_name(item_activated));
    string_decrypt(strbuf, str_item_is_selected);
    tbox_print_string(BAG_TBOX_CONTEXT_MENU_TEXT, 2, 0, 3, 0, 0, &bag_font_colormap_description, 0, strbuf);
}


static void bag_context_menu_overworld_handle_input(u8 self) {
    if (menu_util_link_is_busy() || dma3_busy(-1))
        return;
    int input = gp_menu_process_input_no_wrap_around();
    switch (input) {
        case GP_MENU_NOTHING_CHOSEN:
            break;
        case GP_MENU_B_PRESSED:
            bag_context_menu_items[BAG_CONTEXT_MENU_CANCEL].function.void_u8(self);
            break;
        default:
            bag_context_menu_items[BAG2_STATE->context_menu_items[input]].function.void_u8(self);
            break;
    }
}


static u8 bag_context_menu_overworld[] = {BAG_CONTEXT_MENU_USE, BAG_CONTEXT_MENU_GIVE, BAG_CONTEXT_MENU_TOSS, BAG_CONTEXT_MENU_CANCEL};
static u8 bag_context_menu_overworld_unique[] = {BAG_CONTEXT_MENU_USE, BAG_CONTEXT_MENU_CANCEL};

static void bag_item_selected_overworld(u8 self) {
    bag_disable_ui();
    if (item_can_be_tossed(item_activated))
        bag_open_context_menu(bag_context_menu_overworld, ARRAY_COUNT(bag_context_menu_overworld));
    else
        bag_open_context_menu(bag_context_menu_overworld_unique, ARRAY_COUNT(bag_context_menu_overworld_unique));
    big_callbacks[self].function = bag_context_menu_overworld_handle_input;
    // big_callbacks[self].function = (void(*)(u8))nullsub;
};



void (*bag_item_selected_by_context[NUM_BAG_CONTEXTS])(u8) = {
    [BAG_CONTEXT_OVERWORLD] = bag_item_selected_overworld,
};