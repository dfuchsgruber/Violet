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
#include "berry.h"
#include "constants/sav_keys.h"
#include "vars.h"
#include "item/tm_hm.h"
#include "overworld/map_control.h"
#include "item/fishing.h"
#include "data_structures.h"

static u8 str_use[] = LANGDEP(PSTRING("O.K."), PSTRING("Use"));
static u8 str_give[] = LANGDEP(PSTRING("Geben"), PSTRING("Give"));
static u8 str_toss[] =  LANGDEP(PSTRING("Müll"), PSTRING("Toss"));
static u8 str_cancel[] = LANGDEP(PSTRING("Zurück"), PSTRING("Cancel"));
static u8 str_select[] = LANGDEP(PSTRING("Select"), PSTRING("Select"));
static u8 str_deselect[] = LANGDEP(PSTRING("Select"), PSTRING("Select"));
static u8 str_walk[] = LANGDEP(PSTRING("Laufen"), PSTRING("Walk"));
static u8 str_equip_bait[] = LANGDEP(PSTRING("Ausrüsten"), PSTRING("Equip"));
static u8 str_unequip_bait[] = LANGDEP(PSTRING("Entfernen"), PSTRING("Unequip"));

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

static void bag_reinitialize_list() {
    u8 pocket_idx = bag_get_current_pocket();
    list_menu_remove(BAG2_STATE->list_menu_cb_idx, fmem.bag_cursor_position + POCKET_TO_BAG_POCKETS_IDX(pocket_idx), fmem.bag_cursor_items_above + POCKET_TO_BAG_POCKETS_IDX(pocket_idx));
    bag_initialize_compute_item_counts();
    bag_initialize_list_cursor_positions();
    bag_build_item_list();
    BAG2_STATE->list_menu_cb_idx = list_menu_new(&gp_list_menu_template, fmem.bag_cursor_position[POCKET_TO_BAG_POCKETS_IDX(pocket_idx)], fmem.bag_cursor_items_above[POCKET_TO_BAG_POCKETS_IDX(pocket_idx)]);
    bg_virtual_sync_reqeust_push(0);
}

void bag_reinitialize_list_and_scroll_menu_indicators_and_return_to_idle_callback(u8 self) {
    bag_reinitialize_list();
    bag_print_item_description(bag_get_current_slot_in_current_pocket());
    tbox_tilemap_draw(BAG_TBOX_DESCRIPTION);
    big_callbacks[self].function = bag_reinitialize_scroll_menu_indicators_and_return_to_idle_callback;
}

void bag_close_message_and_return_to_idle_callback(u8 self)  {
    // tbox_flush_map(BAG_TBOX_MESSAGE);
    tbox_clear_message(BAG_TBOX_MESSAGE, false);
    bg_virtual_sync_reqeust_push(0);
    bag_reinitialize_list_and_scroll_menu_indicators_and_return_to_idle_callback(self);
}

void bag_wait_a_button_and_close_message_and_return_to_idle_callback(u8 self) {
    if (super.keys_new.keys.A) {
        play_sound(5);
        bag_close_message_and_return_to_idle_callback(self);
    }
} 

void bag_wait_a_button_and_close_message_and_close_bag(u8 self) {
    if (super.keys_new.keys.A) {
        play_sound(5);
        // tbox_flush_map(BAG_TBOX_MESSAGE);
        tbox_clear_message(BAG_TBOX_MESSAGE, false);
        bg_virtual_sync_reqeust_push(0);
        bag_close(self, ITEM_NONE, false);
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
        tbox_free(BAG2_STATE->tbox_context_menu);
        tbox_flush_map(BAG_TBOX_CONTEXT_MENU_TEXT);
        tbox_tilemap_draw(BAG_TBOX_LIST);
        bg_virtual_sync_reqeust_push(0);
        if ((item_get_type(item_activated) && pokemon_get_number_in_party() == 0)) {
            bag_print_string(self, 2, str_there_is_no_pokemon, bag_wait_a_button_and_close_message_and_return_to_idle_callback);
        } else {
            big_callbacks[self].params[3] = false;
            field_function(self);
        }
    }
}

static void bag_context_menu_item_cancel(u8 self) {
    tbox_flush_all(BAG2_STATE->tbox_context_menu, 0x00);
    tbox_flush_map(BAG2_STATE->tbox_context_menu);
    tbox_free(BAG2_STATE->tbox_context_menu);
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
    } else if (super.keys_new.keys.right) {
        if (BAG2_STATE->toss_current_number < BAG2_STATE->toss_max_number) {
            BAG2_STATE->toss_current_number = (u16)MIN(BAG2_STATE->toss_max_number, BAG2_STATE->toss_current_number + 10);
            return true;
        }
    } else if (super.keys_new.keys.left) {
        if (BAG2_STATE->toss_current_number > 1) {
            BAG2_STATE->toss_current_number = (u16)MAX(1, BAG2_STATE->toss_current_number - 10);
            return true;
        }
    }
    return false;
}

static u8 str_tossed_items[] = LANGDEP(PSTRING("BUFFER_1 ×BUFFER_2\nweggeworfen."), PSTRING("Tossed BUFFER_1 ×BUFFER_2."));

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

static u8 str_confirm_toss[] = LANGDEP(PSTRING("BUFFER_1 ×BUFFER_2\nwirklich wegwerfen?"), PSTRING("Toss\nBUFFER_1 ×BUFFER_2?"));

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

static scroll_indicator_template scroll_indicator_quantity_toss_template = {
    .arrow0_type = SCROLL_ARROW_UP, .arrow0_x = 212, .arrow0_y = 120,
    .arrow1_type = SCROLL_ARROW_DOWN, .arrow1_x = 212, .arrow1_y = 152,
    .arrow0_threshold = 0, 
    .arrow1_threshold = 1000,
    .tiles_tag = 110,
    .pal_tag = 110,
};

static scroll_indicator_template scroll_indicator_quantity_sell_template = {
    .arrow0_type = SCROLL_ARROW_UP, .arrow0_x = 168, .arrow0_y = 120,
    .arrow1_type = SCROLL_ARROW_DOWN, .arrow1_x = 168, .arrow1_y = 152,
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
    BAG2_STATE->scroll_indicator_quantity_cb_idx = scroll_indicator_new(&scroll_indicator_quantity_toss_template, &BAG2_STATE->toss_current_number);
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
        tbox_free(BAG2_STATE->tbox_quantity);
        bg_virtual_sync_reqeust_push(0);
        scroll_indicator_delete(BAG2_STATE->scroll_indicator_quantity_cb_idx);
        bag_confirm_toss(self);
    } else if (super.keys_new.keys.B) {
        play_sound(5);
        tbox_flush_set(BAG2_STATE->tbox_quantity, 0x00);
        tbox_flush_map_and_frame(BAG2_STATE->tbox_quantity);
        tbox_free(BAG2_STATE->tbox_quantity);
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
    tbox_free(BAG2_STATE->tbox_context_menu);
    tbox_flush_map(BAG_TBOX_CONTEXT_MENU_TEXT);
    tbox_tilemap_draw(BAG_TBOX_LIST);
    bg_virtual_sync_reqeust_push(0);

    u8 pocket = bag_get_current_pocket();
    u16 quantity = item_get_quantity_by_pocket_position(pocket, bag_get_current_slot_in_current_pocket());
    BAG2_STATE->toss_max_number = quantity;
    BAG2_STATE->toss_current_number = 1;

    // DEBUG("Quantity is %d, item is %d\n", quantity, item_get_idx_by_pocket_position(pocket, bag_get_current_slot_in_current_pocket()));
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
    tbox_free(BAG2_STATE->tbox_context_menu);
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

static void bag_context_menu_item_toggle_select(u8 self) {
    if (save1->registered_item == item_activated)
        save1->registered_item = ITEM_NONE;
    else
        save1->registered_item = item_activated;
    bag_reinitialize_list();
    // tbox_flush_map(BAG_TBOX_MESSAGE_WITH_YES_NO);
    bg_virtual_sync_reqeust_push(0);
    bag_context_menu_item_cancel(self);
}

static void bag_context_menu_item_battle_use(u8 self) {
    void (*battle_function)(u8) = item_get_battle_function(item_activated);
    DEBUG("Use item %d with battle func 0x%x", item_activated, battle_function);
    if (battle_function) {
        tbox_flush_all(BAG2_STATE->tbox_context_menu, 0x00);
        tbox_flush_map(BAG2_STATE->tbox_context_menu);
        tbox_free(BAG2_STATE->tbox_context_menu);
        tbox_flush_map(BAG_TBOX_CONTEXT_MENU_TEXT);
        tbox_tilemap_draw(BAG_TBOX_LIST);
        bg_virtual_sync_reqeust_push(0);
        battle_function(self);
    }
}

static void bag_equip_bait_continuation() {
    u16 item_idx_rod = (u16)gp_stack_pop();
    if (item_activated != ITEM_NONE) {
        item_rod_equip_bait(item_idx_rod, item_activated);
    }
	bag_open(BAG_CONTEXT_OVERWORLD, BAG_OPEN_KEYITEMS, NULL);
}

static void bag_initalize_with_context_equip_bait() {
	bag_open(BAG_CONTEXT_EQUIP_BAIT, BAG_OPEN_BAIT, NULL);
	bag_set_continuation(bag_equip_bait_continuation);
}

static void bag_equip_bait(u8 self) {
    gp_stack_push(item_activated);
	bag_set_continuation(bag_initalize_with_context_equip_bait);
	bag_fade_out_and_continuation(self);
}


static void bag_equip_bait_confirm_yes(u8 self) {
    // tbox_clear_message(BAG_TBOX_MESSAGE_WITH_YES_NO, false);
    tbox_flush_map_and_frame(BAG_TBOX_MESSAGE_WITH_YES_NO);
    bag_equip_bait(self);
}

static yes_no_box_callbacks_t yes_no_callbacks_equip_bait = {
    .no_callback = bag_toss_confirm_no,
    .yes_callback = bag_equip_bait_confirm_yes,
};

static u8 str_confirm_equip_bait[] = LANGDEP(
    PSTRING("BUFFER_2 ist\nausgerüstet. Wechsel?"),
    PSTRING("BUFFER_2 is\nequipped. Continue?")
);

static void bag_confirm_equip(u8 self) {
    strcpy(buffer0, item_get_name(item_activated));
    strcpy(buffer1, item_get_name(item_rod_get_equipped_bait(item_activated)));
    string_decrypt(strbuf, str_confirm_equip_bait);
    tbox_draw_std_frame_by_base_tile_and_pal(BAG_TBOX_MESSAGE_WITH_YES_NO, true, BAG_START_TILE_BORDER_STD, BAG_PAL_IDX_BORDER_STD);
    tbox_print_string(BAG_TBOX_MESSAGE_WITH_YES_NO, 2, 0, 0, 0, 0, &bag_font_colormap_std, 0, strbuf);
    bg_virtual_sync_reqeust_push(0);
    tboxdata template = {.bg_id = 0, .h = 2 * 2, .w = 5, .x = 30 - 5 - 1, .y = (u8)(20 - 1 - (2 * 2)), .pal = 14, .start_tile = bag_context_menu_get_start_tile()};
    gp_list_menu_yes_no_new_with_callbacks(self, &template, 2, 0, 0, BAG_START_TILE_BORDER_STD, BAG_PAL_IDX_BORDER_STD, &yes_no_callbacks_equip_bait);
}

static void bag_context_menu_item_equip_bait(u8 self) {
    // Close the context menu and hide tboxes
    tbox_flush_all(BAG2_STATE->tbox_context_menu, 0x00);
    tbox_flush_map(BAG2_STATE->tbox_context_menu);
    tbox_free(BAG2_STATE->tbox_context_menu);
    tbox_flush_map(BAG_TBOX_CONTEXT_MENU_TEXT);
    tbox_tilemap_draw(BAG_TBOX_LIST);
    bg_virtual_sync_reqeust_push(0);

    if (item_rod_get_equipped_bait(item_activated) != ITEM_NONE) {
        big_callbacks[self].function = bag_confirm_equip;
    } else {
        bag_equip_bait(self);
    }   
}

static u8 str_unequiped_bait[] = LANGDEP(
    PSTRING("BUFFER_1 wurde von\nBUFFER_2 entfernt."),
    PSTRING("BUFFER_1 was\nremoved from BUFFER_2.")
);

static void bag_context_menu_item_unequip_bait(u8 self) {
    // Close the context menu and hide tboxes
    tbox_flush_all(BAG2_STATE->tbox_context_menu, 0x00);
    tbox_flush_map(BAG2_STATE->tbox_context_menu);
    tbox_free(BAG2_STATE->tbox_context_menu);
    tbox_flush_map(BAG_TBOX_CONTEXT_MENU_TEXT);
    tbox_tilemap_draw(BAG_TBOX_LIST);
    bg_virtual_sync_reqeust_push(0);
    
    strcpy(buffer0, item_get_name(item_rod_get_equipped_bait(item_activated)));
    strcpy(buffer1, item_get_name(item_activated));
    string_decrypt(strbuf, str_unequiped_bait);
    item_rod_equip_bait(item_activated, ITEM_NONE);
    bag_print_string(self, 2, strbuf, bag_toss_or_sell_wait_a_or_b_press_and_redraw_all);
}

static void bag_equip_bait_from_bait_pocket_continuation() {
    u16 item_idx_rod = (u16)gp_stack_pop();
    (void)item_idx_rod; // The rod was already equipped 
	bag_open(BAG_CONTEXT_OVERWORLD, BAG_OPEN_BAIT, NULL);
}

static void bag_initalize_with_context_equip_bait_from_bait_pocket() {
	bag_open(BAG_CONTEXT_SELECT_ROD_TO_EQUIP_BAIT, BAG_OPEN_KEYITEMS, NULL);
	bag_set_continuation(bag_equip_bait_from_bait_pocket_continuation);
}

static void bag_context_menu_item_equip_bait_from_bait_pocket(u8 self) {

    // Close the context menu and hide tboxes
    tbox_flush_all(BAG2_STATE->tbox_context_menu, 0x00);
    tbox_flush_map(BAG2_STATE->tbox_context_menu);
    tbox_free(BAG2_STATE->tbox_context_menu);
    tbox_flush_map(BAG_TBOX_CONTEXT_MENU_TEXT);
    tbox_tilemap_draw(BAG_TBOX_LIST);
    bg_virtual_sync_reqeust_push(0);

    gp_stack_push(item_activated);
	bag_set_continuation(bag_initalize_with_context_equip_bait_from_bait_pocket);
	bag_fade_out_and_continuation(self);
}



menu_action_t bag_context_menu_items[NUM_BAG_CONTEXT_MENU_ITEMS] = {
    [BAG_CONTEXT_MENU_USE] = {.text = str_use, .function = {.void_u8 = bag_context_menu_item_use}},
    [BAG_CONTEXT_MENU_GIVE] = {.text = str_give, .function = {.void_u8 = bag_context_menu_item_give}},
    [BAG_CONTEXT_MENU_TOSS] = {.text = str_toss, .function = {.void_u8 = bag_context_menu_item_toss}},
    [BAG_CONTEXT_MENU_CANCEL] = {.text = str_cancel, .function = {.void_u8 = bag_context_menu_item_cancel}},
    [BAG_CONTEXT_MENU_SELECT] = {.text = str_select, .function = {.void_u8 = bag_context_menu_item_toggle_select}},
    [BAG_CONTEXT_MENU_DESELECT] = {.text = str_deselect, .function = {.void_u8 = bag_context_menu_item_toggle_select}},
    [BAG_CONTEXT_MENU_WALK] = {.text = str_walk, .function = {.void_u8 = bag_context_menu_item_use}},
    [BAG_CONTEXT_MENU_BATTLE_USE] = {.text = str_use, .function = {.void_u8 = bag_context_menu_item_battle_use}},
    [BAG_CONTEXT_MENU_EQUIP_BAIT] = {.text = str_equip_bait, .function = {.void_u8 = bag_context_menu_item_equip_bait}},
    [BAG_CONTEXT_MENU_UNEQUIP_BAIT] = {.text = str_unequip_bait, .function = {.void_u8 = bag_context_menu_item_unequip_bait}},
    [BAG_CONTEXT_MENU_EQUIP_BAIT_FROM_BAIT_POCKET] = {.text = str_equip_bait, .function = {.void_u8 = bag_context_menu_item_equip_bait_from_bait_pocket}}, 
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

static void bag_item_selected_party_give(u8 self) {
    bag_disable_ui();
    if (item_can_be_tossed(item_activated)) {
        bag_close(self, item_activated, true);
    } else {
        strcpy(buffer0, item_get_name(item_activated));
        string_decrypt(strbuf, str_cant_be_given);
        bag_print_string(self, 2, strbuf, bag_wait_a_button_and_close_message_and_return_to_idle_callback);
    }
}

static void bag_item_selected_overworld(u8 self) {
    bag_disable_ui();
    u8 context_menu[4];
    u8 num_items = 0;
    if (item_get_pocket(item_activated) == POCKET_BAIT) {
            context_menu[num_items++] = BAG_CONTEXT_MENU_EQUIP_BAIT_FROM_BAIT_POCKET;
    } else if (item_get_field_function(item_activated)) {
        if (item_activated == ITEM_FAHRRAD && overworld_flag_get(PLAYER_STATE_BIKING))
            context_menu[num_items++] = BAG_CONTEXT_MENU_WALK;
        else
            context_menu[num_items++] = BAG_CONTEXT_MENU_USE;
    }
    if (item_is_rod(item_activated)) {
        context_menu[num_items++] = BAG_CONTEXT_MENU_EQUIP_BAIT;
        if (item_rod_get_equipped_bait(item_activated) != ITEM_NONE)
            context_menu[num_items++] = BAG_CONTEXT_MENU_UNEQUIP_BAIT;
    }
    if (item_get_pocket(item_activated) == POCKET_KEY_ITEMS) {
        if (save1->registered_item == item_activated)
            context_menu[num_items++] = BAG_CONTEXT_MENU_DESELECT;
        else
            context_menu[num_items++] = BAG_CONTEXT_MENU_SELECT;
    } else if (item_can_be_tossed(item_activated)) {
            context_menu[num_items++] = BAG_CONTEXT_MENU_GIVE;
            context_menu[num_items++] = BAG_CONTEXT_MENU_TOSS;
    }
    context_menu[num_items++] = BAG_CONTEXT_MENU_CANCEL;
    bag_open_context_menu(context_menu, num_items);
    big_callbacks[self].function = bag_context_menu_overworld_handle_input;
    // big_callbacks[self].function = (void(*)(u8))nullsub;
};

static void bag_print_money() {
    tboxdata template = {.bg_id = 0, .h = 3, .w = 8, .x = 1, .y = 1, .pal = 14, .start_tile = (u16)(bag_context_menu_get_start_tile() + 50)};
    BAG2_STATE->tbox_money = tbox_new(&template);
    tbox_tilemap_draw(BAG2_STATE->tbox_money);
    tbox_print_money_and_frame(BAG2_STATE->tbox_money, BAG_START_TILE_BORDER_STD, BAG_PAL_IDX_BORDER_STD, money_get(&save1->money));
}

static void bag_sell_confirm_no(u8 self) {
    // tbox_clear_message(BAG_TBOX_MESSAGE_WITH_YES_NO, false);
    tbox_flush_map_and_frame(BAG2_STATE->tbox_money);
    tbox_free(BAG2_STATE->tbox_money);
    tbox_flush_map_and_frame(BAG_TBOX_MESSAGE_WITH_YES_NO);
    tbox_tilemap_draw(BAG_TBOX_POCKET_NAME);
    bg_virtual_sync_reqeust_push(0);
    bag_print_item_description(bag_get_current_slot_in_current_pocket());
    big_callbacks[self].function = (void(*)(u8))bag_menu_cancel_redraw_description_and_scroll_menu_indicators_and_return_to_idle_callback;
}

static void bag_sold_item_wait_a_b_press(u8 self) {
    if (sound_is_playing())
        return;
    if (super.keys_new.keys.A || super.keys_new.keys.B) {
        play_sound(5);
        tbox_flush_map_and_frame(BAG2_STATE->tbox_money);
        tbox_free(BAG2_STATE->tbox_money);
        tbox_clear_message(BAG_TBOX_MESSAGE, false);
        bag_print_item_description(bag_get_current_slot_in_current_pocket());
        tbox_tilemap_draw(BAG_TBOX_DESCRIPTION);
        tbox_tilemap_draw(BAG_TBOX_POCKET_NAME);
        bg_virtual_sync_reqeust_push(0);
        big_callbacks[self].function = bag_reinitialize_scroll_menu_indicators_and_return_to_idle_callback;
    }
}

static void bag_sold_item(u8 self) {
    play_sound(248);
    item_remove(item_activated, BAG2_STATE->toss_current_number);
    int money = item_get_price(item_activated) / 2 * BAG2_STATE->toss_current_number;
    money_add(&save1->money, (u32)money);
    tbox_update_money(BAG2_STATE->tbox_money, money_get(&save1->money), 0);
    u8 pocket_idx = bag_get_current_pocket();
    list_menu_remove(BAG2_STATE->list_menu_cb_idx, fmem.bag_cursor_position + POCKET_TO_BAG_POCKETS_IDX(pocket_idx), fmem.bag_cursor_items_above + POCKET_TO_BAG_POCKETS_IDX(pocket_idx));
    bag_initialize_compute_item_counts();
    bag_initialize_list_cursor_positions();
    bag_build_item_list();
    BAG2_STATE->list_menu_cb_idx = list_menu_new(&gp_list_menu_template, fmem.bag_cursor_position[POCKET_TO_BAG_POCKETS_IDX(pocket_idx)], fmem.bag_cursor_items_above[POCKET_TO_BAG_POCKETS_IDX(pocket_idx)]);
    bg_virtual_sync_reqeust_push(0);
    big_callbacks[self].function = bag_sold_item_wait_a_b_press;
}

static u8 str_sold_item[] = LANGDEP(PSTRING("BUFFER_1 ×BUFFER_2 wurde im\nTausch gegen BUFFER_3POKEDOLLAR übergeben."), PSTRING("Exchanged BUFFER_1 ×BUFFER_2\nagainst BUFFER_3POKEDOLLAR."));

static void bag_sell_confirm_yes(u8 self) {
    tbox_flush_map_and_frame(BAG_TBOX_MESSAGE_WITH_YES_NO);
    bg_virtual_sync_reqeust_push(0);
    bag_print_string(self, 2, str_sold_item, bag_sold_item);
}


static yes_no_box_callbacks_t yes_no_callbacks_sell = {
    .no_callback = bag_sell_confirm_no,
    .yes_callback = bag_sell_confirm_yes,
};

static u8 str_confirm_sell[] = LANGDEP(PSTRING("BUFFER_1 ×BUFFER_2 für\nBUFFER_3POKEDOLLAR verkaufen?"), PSTRING("Sell BUFFER_1 ×BUFFER_2\nfor BUFFER_3POKEDOLLAR?"));

static void bag_confirm_sell(u8 self) {
    int money = item_get_price(item_activated) / 2 * BAG2_STATE->toss_current_number;
    itoa(buffer2, money, ITOA_NO_PADDING, 7);
    strcpy(buffer0, item_get_name(item_activated));
    itoa(buffer1, BAG2_STATE->toss_current_number, ITOA_NO_PADDING, 3);
    string_decrypt(strbuf, str_confirm_sell);
    tbox_draw_std_frame_by_base_tile_and_pal(BAG_TBOX_MESSAGE_WITH_YES_NO, true, BAG_START_TILE_BORDER_STD, BAG_PAL_IDX_BORDER_STD);
    tbox_print_string(BAG_TBOX_MESSAGE_WITH_YES_NO, 2, 0, 0, 0, 0, &bag_font_colormap_std, 0, strbuf);
    bg_virtual_sync_reqeust_push(0);
    tboxdata template = {.bg_id = 0, .h = 2 * 2, .w = 5, .x = 30 - 5 - 1, .y = (u8)(20 - 1 - (2 * 2)), .pal = 14, .start_tile = bag_context_menu_get_start_tile()};
    gp_list_menu_yes_no_new_with_callbacks(self, &template, 2, 0, 0, BAG_START_TILE_BORDER_STD, BAG_PAL_IDX_BORDER_STD, &yes_no_callbacks_sell);
}

static void bag_sell_initialize_quantity(u8 *str, u8 number_digits) {
    tbox_draw_std_frame_by_base_tile_and_pal(BAG_TBOX_MESSAGE_WITH_SELL_QUANTITY, true, BAG_START_TILE_BORDER_STD, BAG_PAL_IDX_BORDER_STD);
    tbox_print_string(BAG_TBOX_MESSAGE_WITH_SELL_QUANTITY, 2, 0, 0, 0, 0, &bag_font_colormap_std, 0, str);
    bg_virtual_sync_reqeust_push(0);
    tboxdata template = {.bg_id = 0, .h = 2 * 2, .w = 10, .x = 30 - 10 - 1, .y = (u8)(20 - 1 - (2 * 2)), .pal = 14, .start_tile = bag_context_menu_get_start_tile()};
    BAG2_STATE->tbox_quantity = tbox_new(&template);
    tbox_tilemap_draw(BAG2_STATE->tbox_quantity);
    tbox_draw_std_frame_by_base_tile_and_pal(BAG2_STATE->tbox_quantity, false, BAG_START_TILE_BORDER_SET_STYLE, BAG_PAL_IDX_SET_STYLE);
    bag_toss_or_sell_update_quantity(number_digits);
    BAG2_STATE->scroll_indicator_quantity_cb_idx = scroll_indicator_new(&scroll_indicator_quantity_sell_template, &BAG2_STATE->toss_current_number);
}
static void bag_sell_update_money() {
    tbox_print_money_at(BAG2_STATE->tbox_quantity, 40, 10, (u32)(item_get_price(item_activated) / 2 * BAG2_STATE->toss_current_number), 0);
}

static void bag_select_quantity_to_sell(u8 self) {
    if (bag_toss_or_sell_process_input()) {
        play_sound(5);
        bag_toss_or_sell_update_quantity(3);
        bag_sell_update_money();
    } else if (super.keys_new.keys.A) {
        play_sound(5);
        tbox_flush_map_and_frame(BAG2_STATE->tbox_quantity);
        tbox_free(BAG2_STATE->tbox_quantity);
        bg_virtual_sync_reqeust_push(0);
        scroll_indicator_delete(BAG2_STATE->scroll_indicator_quantity_cb_idx);
        bag_confirm_sell(self);
    } else if (super.keys_new.keys.B) {
        play_sound(5);
        tbox_flush_map_and_frame(BAG2_STATE->tbox_quantity);
        tbox_free(BAG2_STATE->tbox_quantity);
        tbox_flush_map_and_frame(BAG2_STATE->tbox_money);
        tbox_free(BAG2_STATE->tbox_money);
        tbox_tilemap_draw(BAG_TBOX_POCKET_NAME);
        bg_virtual_sync_reqeust_push(0);
        scroll_indicator_delete(BAG2_STATE->scroll_indicator_quantity_cb_idx);
        bag_reinitialize_list_and_scroll_menu_indicators_and_return_to_idle_callback(self);
    }
    (void)self;
}

static u8 str_cant_sell_that[] = LANGDEP(PSTRING("BUFFER_1? Tut mir leid,\naber das kann ich nicht kaufen."), PSTRING("BUFFER_1?\nSorry but I can't buy that."));
static u8 str_sell_how_many[] = LANGDEP(PSTRING("Wie viele\nverkaufen?"), PSTRING("Sell how many?"));

static void bag_item_selected_sell(u8 self) {
    bag_disable_ui();
    if (item_can_be_tossed(item_activated) && item_get_price(item_activated) > 0) {
        bag_print_money();
        u8 pocket = bag_get_current_pocket();
        u16 quantity = item_get_quantity_by_pocket_position(pocket, bag_get_current_slot_in_current_pocket());
        BAG2_STATE->toss_max_number = MIN(999, quantity);
        BAG2_STATE->toss_current_number = 1;
        if (BAG2_STATE->toss_max_number == 1) {
            big_callbacks[self].function = bag_confirm_sell;
        } else {
            bag_sell_initialize_quantity(str_sell_how_many, 3);
            bag_sell_update_money();
            big_callbacks[self].function = bag_select_quantity_to_sell;
        }

    } else {
        strcpy(buffer0, item_get_name(item_activated));
        string_decrypt(strbuf, str_cant_sell_that);
        bag_print_string(self, 2, strbuf, bag_wait_a_button_and_close_message_and_return_to_idle_callback);
    }
}


static void bag_deposit_wait_a_or_b_press_and_redraw_all(u8 self) {
    if (super.keys_new.keys.A || super.keys_new.keys.B) {
        play_sound(5);
        DEBUG("Item activated %d x %d\n", item_activated, BAG2_STATE->toss_current_number);
        item_remove(item_activated, BAG2_STATE->toss_current_number);
        tbox_clear_message(BAG_TBOX_MESSAGE_WITH_YES_NO, false);
        bg_virtual_sync_reqeust_push(0);
        bag_reinitialize_list_and_scroll_menu_indicators_and_return_to_idle_callback(self);
    }
}

static u8 str_no_space_to_deposit[] = LANGDEP(PSTRING("Auf deinem PC ist kein\nPlatz dafür!"), PSTRING("There is no room on your\nitem pc."));
static u8 str_deposited[] = LANGDEP(PSTRING("BUFFER_1 ×BUFFER_2\nwurde abgelegt."), PSTRING("Deposited\nBUFFER_1 ×BUFFER_2"));

static void bag_deposit_item(u8 self) {
    if (item_add_to_pc(item_activated, BAG2_STATE->toss_current_number)) {
        strcpy(buffer0, item_get_name(item_activated));
        itoa(buffer1, BAG2_STATE->toss_current_number, ITOA_NO_PADDING, 3);
        string_decrypt(strbuf, str_deposited);
        tbox_draw_std_frame_by_base_tile_and_pal(BAG_TBOX_MESSAGE_WITH_YES_NO, true, BAG_START_TILE_BORDER_STD, BAG_PAL_IDX_BORDER_STD);
        tbox_print_string(BAG_TBOX_MESSAGE_WITH_YES_NO, 2, 0, 0, 0, 0, &bag_font_colormap_std, 0, strbuf);
        bg_virtual_sync_reqeust_push(0);
        big_callbacks[self].function = bag_deposit_wait_a_or_b_press_and_redraw_all;
    } else {
        bag_print_string(self, 2, str_no_space_to_deposit, bag_wait_a_button_and_close_message_and_return_to_idle_callback);
    }
}

static void bag_select_quantity_to_deposit(u8 self) {
    (void)self;
    if (bag_toss_or_sell_process_input()) {
        play_sound(5);
        bag_toss_or_sell_update_quantity(3);
    } else if (super.keys_new.keys.A) {
        play_sound(5);
        tbox_flush_set(BAG2_STATE->tbox_quantity, 0x00);
        tbox_flush_map_and_frame(BAG2_STATE->tbox_quantity);
        tbox_free(BAG2_STATE->tbox_quantity);
        bg_virtual_sync_reqeust_push(0);
        scroll_indicator_delete(BAG2_STATE->scroll_indicator_quantity_cb_idx);
        bag_deposit_item(self);
    } else if (super.keys_new.keys.B) {
        play_sound(5);
        tbox_flush_set(BAG2_STATE->tbox_quantity, 0x00);
        tbox_flush_map_and_frame(BAG2_STATE->tbox_quantity);
        tbox_free(BAG2_STATE->tbox_quantity);
        bg_virtual_sync_reqeust_push(0);
        scroll_indicator_delete(BAG2_STATE->scroll_indicator_quantity_cb_idx);
        bag_reinitialize_list_and_scroll_menu_indicators_and_return_to_idle_callback(self);
    }
}

static u8 str_cant_deposit[] = LANGDEP(PSTRING("BUFFER_1 kann nicht\nabgelegt werden."), PSTRING("BUFFER_1 can not\nbe deposited."));
static u8 str_deposit_how_many[] = LANGDEP(PSTRING("Wie viele\nablegen?"), PSTRING("How many to\ndeposit?"));

static void bag_item_selected_deposit(u8 self) {
    bag_disable_ui();
    if (item_can_be_tossed(item_activated)) {
        u8 pocket = bag_get_current_pocket();
        u16 quantity = item_get_quantity_by_pocket_position(pocket, bag_get_current_slot_in_current_pocket());
        BAG2_STATE->toss_max_number = MIN(999, quantity);
        BAG2_STATE->toss_current_number = 1;
        if (quantity == 1) {
            bag_deposit_item(self);
        } else {
            bag_toss_or_sell_initiaize_quantity(str_deposit_how_many, 3);
            big_callbacks[self].function = bag_select_quantity_to_deposit;
        }
    } else {
        strcpy(buffer0, item_get_name(item_activated));
        string_decrypt(strbuf, str_cant_deposit);
        bag_print_string(self, 2, strbuf, bag_wait_a_button_and_close_message_and_return_to_idle_callback);
    }
}

static u8 str_no_space_for_mulch[] = LANGDEP(PSTRING("Du hast keinen Platz\nfür BUFFER_1 ×BUFFER_2."), PSTRING("You have no room for\nBUFFER_1 ×BUFFER_2."));
static u8 str_composted[] = LANGDEP(PSTRING("Du hast BUFFER_1 ×BUFFER_2\nzu BUFFER_3 kompostiert."), PSTRING("You composted BUFFER_1 ×BUFFER_2\nto BUFFER_3."));

static void bag_compost_item(u8 self) {
    if (item_has_room(ITEM_MULCH, BAG2_STATE->toss_current_number)) {
        item_remove(item_activated, BAG2_STATE->toss_current_number);
        item_add(ITEM_MULCH, BAG2_STATE->toss_current_number);
        strcpy(buffer0, item_get_name(item_activated));
        itoa(buffer1, BAG2_STATE->toss_current_number, ITOA_NO_PADDING, 3);
        strcpy(buffer2, item_get_name(ITEM_MULCH));
        string_decrypt(strbuf, str_composted);
        bag_print_string(self, 2, strbuf, bag_wait_a_button_and_close_message_and_return_to_idle_callback);
        // tbox_draw_std_frame_by_base_tile_and_pal(BAG_TBOX_MESSAGE, true, BAG_START_TILE_BORDER_STD, BAG_PAL_IDX_BORDER_STD);
        // tbox_print_string(BAG_TBOX_MESSAGE, 2, 0, 0, 0, 0, &bag_font_colormap_std, 0, strbuf);
        // bg_virtual_sync_reqeust_push(0);
        // big_callbacks[self].function = bag_compost_wait_a_or_b_press_and_redraw_all;
    } else {
        strcpy(buffer0, item_get_name(ITEM_MULCH));
        itoa(buffer1, BAG2_STATE->toss_current_number, ITOA_NO_PADDING, 3);
        string_decrypt(strbuf, str_no_space_for_mulch);
        bag_print_string(self, 2, strbuf, bag_wait_a_button_and_close_message_and_return_to_idle_callback);
    }
}

static void bag_select_quantity_to_compost(u8 self) {
    (void)self;
    if (bag_toss_or_sell_process_input()) {
        play_sound(5);
        bag_toss_or_sell_update_quantity(3);
    } else if (super.keys_new.keys.A) {
        play_sound(5);
        tbox_flush_set(BAG2_STATE->tbox_quantity, 0x00);
        tbox_flush_map_and_frame(BAG2_STATE->tbox_quantity);
        tbox_free(BAG2_STATE->tbox_quantity);
        bg_virtual_sync_reqeust_push(0);
        scroll_indicator_delete(BAG2_STATE->scroll_indicator_quantity_cb_idx);
        bag_compost_item(self);
    } else if (super.keys_new.keys.B) {
        play_sound(5);
        tbox_flush_set(BAG2_STATE->tbox_quantity, 0x00);
        tbox_flush_map_and_frame(BAG2_STATE->tbox_quantity);
        tbox_free(BAG2_STATE->tbox_quantity);
        bg_virtual_sync_reqeust_push(0);
        scroll_indicator_delete(BAG2_STATE->scroll_indicator_quantity_cb_idx);
        bag_reinitialize_list_and_scroll_menu_indicators_and_return_to_idle_callback(self);
    }
}

static u8 str_cant_compost[] = LANGDEP(PSTRING("BUFFER_1 kann nicht\nkompostiert werden."), PSTRING("BUFFER_1 can not\nbe composted."));
static u8 str_compost_how_many[] = LANGDEP(PSTRING("Wie viele\nkompostieren?"), PSTRING("How many to\ncompost?"));

static void bag_item_selected_compost(u8 self) {
    bag_disable_ui();
    if (item_can_be_tossed(item_activated)) {
        u8 pocket = bag_get_current_pocket();
        u16 quantity = item_get_quantity_by_pocket_position(pocket, bag_get_current_slot_in_current_pocket());
        BAG2_STATE->toss_max_number = MIN(999, quantity);
        BAG2_STATE->toss_current_number = 1;
        if (quantity == 1) {
            bag_compost_item(self);
        } else {
            bag_toss_or_sell_initiaize_quantity(str_compost_how_many, 3);
            big_callbacks[self].function = bag_select_quantity_to_compost;
        }
    } else {
        strcpy(buffer0, item_get_name(item_activated));
        string_decrypt(strbuf, str_cant_compost);
        bag_print_string(self, 2, strbuf, bag_wait_a_button_and_close_message_and_return_to_idle_callback);
    }
}

static u8 str_cant_be_planted[] = LANGDEP(PSTRING("BUFFER_1 kann nicht\ngepflanzt werden."), PSTRING("BUFFER_1 can not\nbe planted."));

static void bag_item_selected_plant_berry(u8 self) {
    bag_disable_ui();
    if (item_can_be_tossed(item_activated)) {
        *var_access(LASTRESULT) = 1; // Berry planted
        save_increment_key(SAV_KEY_PLANTED_BERRIES);
        item_remove(item_activated, 1);
        u8 berry_tree_idx = (u8)*var_access(0x8000);
        berry_tree_initialize(berry_tree_idx, (u8)ITEM_IDX_TO_BERRY_IDX(item_activated), BERRY_STAGE_DIRT_PILE);
        cmem.berry_trees[berry_tree_idx].replanted = 1;
        bag_close(self, item_activated, true);
    } else {
        strcpy(buffer0, item_get_name(item_activated));
        string_decrypt(strbuf, str_cant_be_planted);
        bag_print_string(self, 2, strbuf, bag_wait_a_button_and_close_message_and_return_to_idle_callback);
    }
}

static u8 str_tm_recharged[] = LANGDEP(
	PSTRING("BUFFER_1\nwurde wieder aufgeladen."),
	PSTRING("BUFFER_1\nwas recharged.")
);

static void bag_recharge_wait_for_sound(u8 self) {
    if (!sound_is_playing()) {
        bag_reinitialize_list();
        strcpy(buffer0, item_get_name(item_activated));
        string_decrypt(strbuf, str_tm_recharged);
        bag_print_string(self, 2, strbuf, bag_wait_a_button_and_close_message_and_close_bag);
    }
}

static u8 str_hms_cant_be_recharged[] = LANGDEP(
	PSTRING("Vms müssen nicht aufgeladen werden!"),
	PSTRING("Hms don't need to be recharged!")
);

static u8 str_tm_doesnt_need_recharge[] = LANGDEP(
	PSTRING("BUFFER_1\nmuss nicht aufgeladen werden!"),
	PSTRING("BUFFER_1\ndoesn't need to be recharged!")
);

static void bag_item_selected_recharge(u8 self) {
    bag_disable_ui();
    if (!item_is_tm(item_activated)) {
        strcpy(buffer0, item_get_name(item_activated));
        string_decrypt(strbuf, str_hms_cant_be_recharged);
        bag_print_string(self, 2, strbuf, bag_wait_a_button_and_close_message_and_return_to_idle_callback);
    } else if (!tm_is_used(ITEM_IDX_TO_TM_IDX(item_activated))) {
        strcpy(buffer0, item_get_name(item_activated));
        string_decrypt(strbuf, str_tm_doesnt_need_recharge);
        bag_print_string(self, 2, strbuf, bag_wait_a_button_and_close_message_and_return_to_idle_callback);
    } else {
        item_remove(ITEM_ENERGIEDISK, 1);
		tm_set_unused(ITEM_IDX_TO_TM_IDX(item_activated));
		play_sound(27);
		big_callbacks[self].function = bag_recharge_wait_for_sound;
    }
}

static u8 bag_context_menu_battle[] = {BAG_CONTEXT_MENU_BATTLE_USE, BAG_CONTEXT_MENU_CANCEL};
static u8 bag_context_menu_battle_no_function[] = {BAG_CONTEXT_MENU_CANCEL};

static void bag_item_selected_battle(u8 self) {
    bag_disable_ui();
    if (item_get_battle_function(item_activated))
        bag_open_context_menu(bag_context_menu_battle, ARRAY_COUNT(bag_context_menu_battle));
    else
        bag_open_context_menu(bag_context_menu_battle_no_function, ARRAY_COUNT(bag_context_menu_battle_no_function));
    big_callbacks[self].function = bag_context_menu_overworld_handle_input;
}

static void bag_item_selected_equip_bait(u8 self) {
    bag_disable_ui();
    bag_close(self, item_activated, false);
}

static void bag_wait_sound_effect_and_close_bag(u8 self) {
    if (!sound_is_playing()) {
        if (BAG2_STATE->delay > 0) {
            BAG2_STATE->delay--;
        } else {
            bag_close(self, item_activated, false);
        }
    }
}

static u8 str_is_no_rod[] = LANGDEP(PSTRING("Nur eine Angel kann mit\nBUFFER_2 ausgerüstet werden."), PSTRING("BUFFER_2 can only\nbe equipped to a rod."));
static u8 str_is_already_equipped[] = LANGDEP(PSTRING("BUFFER_1 ist bereits\nmit BUFFER_2 ausgerüstet."), PSTRING("BUFFER_2 is already\nequipped to BUFFER_1."));

static void bag_item_selected_equip_to_rod(u8 self) {
    bag_disable_ui();
    u16 bait_idx = (u16)gp_stack_peek();
    if (item_is_rod(item_activated)) {
        if (item_rod_get_equipped_bait(item_activated) == bait_idx) {
            strcpy(buffer0, item_get_name(item_activated));
            strcpy(buffer1, item_get_name(bait_idx));
            string_decrypt(strbuf, str_is_already_equipped);
            bag_print_string(self, 2, strbuf, bag_wait_a_button_and_close_message_and_return_to_idle_callback);
        } else {
            play_sound(29);
            BAG2_STATE->delay = 40;
            item_rod_equip_bait(item_activated, bait_idx);
            bag_reinitialize_list();
            bag_print_item_description(bag_get_current_slot_in_current_pocket());
            tbox_tilemap_draw(BAG_TBOX_DESCRIPTION);
            big_callbacks[self].function = bag_wait_sound_effect_and_close_bag;
        }
    } else {
        strcpy(buffer0, item_get_name(item_activated));
        strcpy(buffer1, item_get_name(bait_idx));
        string_decrypt(strbuf, str_is_no_rod);
        bag_print_string(self, 2, strbuf, bag_wait_a_button_and_close_message_and_return_to_idle_callback);
    }
}

void (*bag_item_selected_by_context[NUM_BAG_CONTEXTS])(u8) = {
    [BAG_CONTEXT_OVERWORLD] = bag_item_selected_overworld,
    [BAG_CONTEXT_PARTY_GIVE] = bag_item_selected_party_give,
    [BAG_CONTEXT_SELL] = bag_item_selected_sell,
    [BAG_CONTEXT_DEPOSIT] = bag_item_selected_deposit,
    [BAG_CONTEXT_COMPOST] = bag_item_selected_compost,
    [BAG_CONTEXT_PLANT_BERRY] = bag_item_selected_plant_berry,
    [BAG_CONTEXT_RECHARGE_TM_HM] = bag_item_selected_recharge,
    [BAG_CONTEXT_BATTLE] = bag_item_selected_battle,
    [BAG_CONTEXT_EQUIP_BAIT]  = bag_item_selected_equip_bait,
    [BAG_CONTEXT_SELECT_ROD_TO_EQUIP_BAIT] = bag_item_selected_equip_to_rod,
};