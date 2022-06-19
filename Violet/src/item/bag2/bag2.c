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
#include "item/fishing.h"

static u8 bag_pocket_order[] = {
    POCKET_ITEMS, POCKET_MEDICINE, POCKET_POKEBALLS, POCKET_TM_HM, POCKET_BERRIES, POCKET_KEY_ITEMS, POCKET_BAIT,
};

static u8 bag_open_pocket_to_pocket[NUM_BAG_OPEN] = {
    [BAG_OPEN_ITEMS] = POCKET_ITEMS,
    [BAG_OPEN_KEYITEMS] = POCKET_KEY_ITEMS,
    [BAG_OPEN_POKEBALLS] = POCKET_POKEBALLS,
    [BAG_OPEN_TM_HM] = POCKET_TM_HM,
    [BAG_OPEN_BERRIES] = POCKET_BERRIES,
    [BAG_OPEN_BAIT] = POCKET_BAIT,
};

static u8 bag_pocket_switching_disabled_by_context[NUM_BAG_CONTEXTS] = {
    [BAG_CONTEXT_COMPOST] = true,
    [BAG_CONTEXT_PLANT_BERRY] = true,
    [BAG_CONTEXT_RECHARGE_TM_HM] = true,
    [BAG_CONTEXT_EQUIP_BAIT] = true,
};

u8 bag_get_current_pocket() {
    return bag_pocket_order[cmem.bag_pocket];
}

void bag_delete_scroll_indicators_items() {
    if (BAG2_STATE->scroll_indicator_items_cb_idx != 0xFF)
        scroll_indicator_delete(BAG2_STATE->scroll_indicator_items_cb_idx);
    BAG2_STATE->scroll_indicator_items_cb_idx = 0xFF;
}

void bag_delete_scroll_indicators_pockets() {
    if (BAG2_STATE->scroll_indicator_pockets_cb_idx != 0xFF)
        scroll_indicator_delete(BAG2_STATE->scroll_indicator_pockets_cb_idx);
    BAG2_STATE->scroll_indicator_pockets_cb_idx = 0xFF;
}

void bag_win0_animation(u8 self) {
    s16 *params = (s16*)big_callbacks[self].params;
    params[0] = (s16)(params[0] + params[1]);
    io_set(IO_WIN0V, (u16)IO_WINV(0, MAX(0, MIN(160, params[0]))));
    if ((params[1] > 0 && params[0] >= 160) || (params[1] < 0 && params[0] <= 0))
        big_callback_delete(self);
}

static tbox_font_colormap font_colmap_cursor_inactive = {.background = 0, .body = 3, .edge = 2};
static u8 str_cursor[] = PSTRING("▶");

void bag_item_list_print_cursor_at(u16 y, u8 color_idx) {
    if (color_idx == 0xFF) {
        tbox_fill_rectangle(BAG_TBOX_LIST, 0x00, 1, y, list_menu_get_cursor_dimension(2, CURSOR_DIMENSION_WIDTH), list_menu_get_cursor_dimension(2, CURSOR_DIMENSION_HEIGHT));
    } else {
        tbox_print_string(BAG_TBOX_LIST, 2, 1, y, 0, 0, &font_colmap_cursor_inactive, 0, str_cursor);
    }
}

void bag_item_list_print_cursor(u8 list_menu_cb_idx, u8 color_idx) {
    bag_item_list_print_cursor_at(list_menu_get_cursor_y_pixel(list_menu_cb_idx), color_idx);
}


static int bag_pockets_process_input() {
    if (BAG2_STATE->pocket_switching_disabled)
        return 0;
    else if (super.keys_new.keys.left && cmem.bag_pocket > 0)
        return -1;
    else if (super.keys_new.keys.right && cmem.bag_pocket < ARRAY_COUNT(bag_pocket_order) - 1)
        return 1;
    else
        return 0;
}


void bag_idle_callback_default(u8 self) {

    if (fading_control.active || menu_util_link_is_busy() || big_callback_is_active(bag_win0_animation))
        return;
    int switch_pockets_input = bag_pockets_process_input();
    if (switch_pockets_input != 0) {
        play_sound(246);
        bag_switch_pockets(self, cmem.bag_pocket + switch_pockets_input);
        return;
    }
    u8 pocket = bag_get_current_pocket();
    if (super.keys_new.keys.select && bag_can_items_be_moved()) {
        u16 cursor_pos, items_above;
        list_menu_get_scroll_and_row(BAG2_STATE->list_menu_cb_idx, &cursor_pos, &items_above);
        u16 item_idx = (u16)(cursor_pos + items_above);
        if (item_idx < BAG2_STATE->pocket_size[pocket]) {
            play_sound(5);
            bag_start_moving_item(self, item_idx);
            return;
        }
    }
    int input = list_menu_process_input(BAG2_STATE->list_menu_cb_idx);
    list_menu_get_scroll_and_row(BAG2_STATE->list_menu_cb_idx, fmem.bag_cursor_position + POCKET_TO_BAG_POCKETS_IDX(pocket), fmem.bag_cursor_items_above + POCKET_TO_BAG_POCKETS_IDX(pocket));
    switch (input) {
        case LIST_MENU_B_PRESSED: {
        exit_bag:
            item_activated = ITEM_NONE;
            play_sound(5);
            bag_close(self, ITEM_NONE, true);
            break;
        }
        case LIST_MENU_NOTHING_CHOSEN:
            return;
        default: {
            if (input == BAG2_STATE->pocket_size[pocket]) {
                goto exit_bag;
            } else {
                item_activated = item_get_idx_by_pocket_position(pocket, (u16)(input));
                bag_item_selected_by_context[fmem.bag_context](self);
            }
        }
    }
}

void bag_cb1(){
    big_callback_proceed();
    tbox_proceed();
    oam_animations_proceed();
    oam_proceed();
    bg_virtual_sync_reqeust_proceed();
    fading_proceed();
}

void bag_vblank_handler() {
    oam_attributes_copy();
    graphic_queue_proceed();
    pal_proceed();
    dma0_proceed();
    dma3_queue_proceed();
}

static u8 str_bag_font_color_regular[] = PSTRING("COLOR_HIGHLIGHT_SHADOW\x02\x00\x03");
static u8 str_cancel[] = LANGDEP(PSTRING("Zurück"), PSTRING("Cancel"));

void bag_format_item_string(u8 *dst, u16 item_idx) {
    // TODO: Highlight colors for empty tms
    strcpy(dst, str_bag_font_color_regular);
    u8 pocket_idx = item_get_pocket(item_idx);
    DEBUG("Format string called with %d\n", item_idx);
    if (item_idx == 0xFFFF)
        strcat(dst, str_cancel);
    else if (pocket_idx == POCKET_TM_HM) {
        tm_hm_get_str_number_and_name(dst, item_idx);
    } else if (pocket_idx == POCKET_BERRIES) {
        berry_get_str_number_and_name(dst, item_idx); 
    } else {
        strcat(dst, item_get_name(item_idx));
    }
}


static void bag_oam_callback_bag_shaking(oam_object *self) {
    if (self->flags & OAM_FLAG_ROTSCALE_ANIM_END) {
        oam_rotscale_anim_init(self, 0);
        self->callback = oam_null_callback;
    }
}

void bag_shake_oam() {
    oam_object *o = oams + BAG2_STATE->oam_idx_bag;
    if (o->flags & OAM_FLAG_ROTSCALE_ANIM_END) {
        oam_rotscale_anim_init(o, 1);
        o->callback = bag_oam_callback_bag_shaking;
    }
}

static u8 str_close_bag[] = LANGDEP(PSTRING("Beutel schließen"), PSTRING("Close bag"));

tbox_font_colormap bag_font_colormap_description = {.background = 0, .body = 1, .edge = 2};

void bag_print_item_description(u16 slot) {
    u8 pocket = bag_get_current_pocket();
    u8 *description;
    if (slot == BAG2_STATE->pocket_size[pocket])
        description = str_close_bag;
    else
        description = item_get_description(item_get_idx_by_pocket_position(pocket, slot));
    tbox_flush_set(BAG_TBOX_DESCRIPTION, 0x00);
    tbox_tilemap_draw(BAG_TBOX_DESCRIPTION);
    tbox_print_string(BAG_TBOX_DESCRIPTION, 2, 0, 3, 0, 0, &bag_font_colormap_description, 0, description);
    bg_virtual_sync_reqeust_push(bag_tboxes[BAG_TBOX_DESCRIPTION].bg_id);
}

static u8 str_equipped_bait[] = LANGDEP(
    PSTRING("Ausgerüstet:"),
    PSTRING("Equipped:")
);
static u8 str_bait_none[] = PSTRING("---");
static u8 str_bait_quantity[] = PSTRING("×BUFFER_1");

void bag_print_rod_bait(u16 slot) {
    u8 pocket = bag_get_current_pocket();
    u16 item_idx;
    if (slot == BAG2_STATE->pocket_size[pocket])
        item_idx = ITEM_NONE;
    else
        item_idx = item_get_idx_by_pocket_position(pocket, slot);
    if (item_is_rod(item_idx)) {
        tbox_flush_set(BAG_TBOX_ROD_DETAILS, 0x00);
        tbox_fill_rectangle(BAG_TBOX_ROD_DETAILS, 0x11, 0, 0, 76, (u8)(bag_tboxes[BAG_TBOX_ROD_DETAILS].y * 8));
        tbox_tilemap_draw(BAG_TBOX_ROD_DETAILS);
        tbox_print_string(BAG_TBOX_ROD_DETAILS, 0, 2, 2, 0, 0, &bag_font_colormap_pocket_hint, 0, str_equipped_bait);
        u16 bait = item_rod_get_equipped_bait(item_idx);
        u8 *bait_name;
        if (bait == ITEM_NONE) {
            bait_name = str_bait_none;
        } else {
            bait_name = item_get_name(bait);
            itoa(buffer0, MIN(999, item_get_count(bait)), ITOA_PAD_SPACES, 3);
            string_decrypt(strbuf, str_bait_quantity);
            tbox_print_string(BAG_TBOX_ROD_DETAILS, 0, 10, 40, 0, 0, &bag_font_colormap_pocket_hint, 0, strbuf);
        }
        tbox_print_string(BAG_TBOX_ROD_DETAILS, 0, 10, 16, 0, 0, &bag_font_colormap_pocket_hint, 0, bait_name);
    } else {
        tbox_flush_map(BAG_TBOX_ROD_DETAILS);
    }
    bg_virtual_sync_reqeust_push(bag_tboxes[BAG_TBOX_ROD_DETAILS].bg_id);
}

void bag_new_scroll_indicators_items() {
    u8 pocket_idx = bag_get_current_pocket();
    scroll_indicator_template indicator_template = {
        .arrow0_type = SCROLL_ARROW_UP, .arrow0_x = 160, .arrow0_y = 8,
        .arrow1_type = SCROLL_ARROW_DOWN, .arrow1_x = 160, .arrow1_y = 104,
        .arrow0_threshold = 0, 
        .arrow1_threshold = (u16) MAX(0, BAG2_STATE->pocket_size[pocket_idx] - BAG2_STATE->pocket_max_shown[pocket_idx] + 1),
        .tiles_tag = 110,
        .pal_tag = 110,
    };
    BAG2_STATE->scroll_indicator_items_cb_idx = scroll_indicator_new(&indicator_template,
        fmem.bag_cursor_position + pocket_idx - 1);
    scroll_indicator_set_oam_priority(BAG2_STATE->scroll_indicator_items_cb_idx, 2, 2);
}

static scroll_indicator_template scroll_indicator_template_pockets = {
    .arrow0_type = SCROLL_ARROW_LEFT, .arrow0_x = 8, .arrow0_y = 72,
    .arrow1_type = SCROLL_ARROW_RIGHT, .arrow1_x = 72, .arrow1_y = 72,
    .arrow0_threshold = 0, .arrow1_threshold = ARRAY_COUNT(bag_pocket_order) - 1,
    .tiles_tag = 111, .pal_tag = 111,
};

void bag_new_scroll_indicators_pockets() {
    if (BAG2_STATE->pocket_switching_disabled) {
        BAG2_STATE->scroll_indicator_pockets_cb_idx = 0xFF;
    } else {
        BAG2_STATE->scroll_indicator_pockets_cb_idx = scroll_indicator_new(&scroll_indicator_template_pockets,
            &cmem.bag_pocket);
        scroll_indicator_set_oam_priority(BAG2_STATE->scroll_indicator_pockets_cb_idx, 2, 2);
    }
}

static void bag_close_wait_fadescreen_and_continue(u8 self) {
    if (fading_control.active || big_callback_is_active(bag_win0_animation))
        return;
    u8 pocket_idx = bag_get_current_pocket();
    list_menu_remove(BAG2_STATE->list_menu_cb_idx, fmem.bag_cursor_position + POCKET_TO_BAG_POCKETS_IDX(pocket_idx), fmem.bag_cursor_items_above + POCKET_TO_BAG_POCKETS_IDX(pocket_idx));
    bag_delete_scroll_indicators_pockets();
    bag_delete_scroll_indicators_items();
    if (BAG2_STATE->internal_continuation)
        callback1_set(BAG2_STATE->internal_continuation);
    else
        callback1_set(fmem.bag_continuation);
    bag_free();
    big_callback_delete(self);
}

void bag_close(u8 cb_idx, u16 item_result, bool set_bag_closed) {
    item_activated = item_result;
    if (set_bag_closed) {
        clearflag(FLAG_BAG_OPEN);
        u8 win0_cb_idx = big_callback_new(bag_win0_animation, 0);
        s16 *params = (s16*)big_callbacks[win0_cb_idx].params;
        params[0] = -16;
        params[1] = 16;
    }
    bag_fade_out_and_continuation(cb_idx);
}

void bag_fade_out_and_continuation(u8 self) {
    big_callbacks[self].function = bag_close_wait_fadescreen_and_continue;
    fadescreen(0xFFFFFFFF, (u8)-2, 0, 16, 0);
}

void bag_open(u8 context, u8 open_which, void (*continuation)()) {
    // Todo reset state
    DEBUG("Open bag in context %d and pocket %d with continuation 0x%x\n", context, open_which, continuation);
    fmem.bag2_state = malloc_and_clear(sizeof(bag2_state_t));
    if (!fmem.bag2_state) {
        callback1_set(continuation);
        return;
    } else {
        BAG2_STATE->initialization_state = 0;
        if (continuation)
            fmem.bag_continuation = continuation;
        if (context != BAG_CONTEXT_LAST)
            fmem.bag_context = context;
        BAG2_STATE->scroll_indicator_pockets_cb_idx = 0xFF;
        BAG2_STATE->scroll_indicator_items_cb_idx = 0xFF;
        if (open_which != BAG_OPEN_LAST) {
            if (open_which < ARRAY_COUNT(bag_open_pocket_to_pocket)) {
                u8 pocket = bag_open_pocket_to_pocket[open_which];
                for (cmem.bag_pocket = 0; cmem.bag_pocket < ARRAY_COUNT(bag_pocket_order); cmem.bag_pocket++) {
                    if (bag_pocket_order[cmem.bag_pocket] == pocket)
                        break;
                }
                if (cmem.bag_pocket >= ARRAY_COUNT(bag_pocket_order))
                    ERROR("Did not find an index in bag_pocket_order to match the target pocket %d\n", pocket);
            } else {
                ERROR("Can not associate pocket with open_which %d\n", open_which);
            }
        }
        BAG2_STATE->pocket_switching_disabled = bag_pocket_switching_disabled_by_context[fmem.bag_context];
        bag_initialize_compute_item_counts();
        bag_initialize_list_cursor_positions();
        callback1_set(bag_cb_initialize);
    }
}

void bag2_return_to_last() {
    bag_open(BAG_CONTEXT_LAST, BAG_OPEN_LAST, NULL);
}

void bag_set_pocket_pointers() {
    memset(bag_pockets, 0, sizeof(bag_pockets));
    bag_pockets[POCKET_ITEMS - 1].items = save1->bag_pocket_items;
    bag_pockets[POCKET_ITEMS - 1].capacity = MAX_NUM_BAG_ITEMS;
    bag_pockets[POCKET_KEY_ITEMS - 1].items = save1->bag_pocket_key_items;
    bag_pockets[POCKET_KEY_ITEMS - 1].capacity = MAX_NUM_BAG_KEY_ITEMS;
    bag_pockets[POCKET_POKEBALLS - 1].items = save1->bag_pocket_pokeballs;
    bag_pockets[POCKET_POKEBALLS - 1].capacity = MAX_NUM_BAG_POKEBALLS;
    bag_pockets[POCKET_TM_HM - 1].items = save1->bag_pocket_tm_hms;
    bag_pockets[POCKET_TM_HM - 1].capacity = MAX_NUM_BAG_TM_HMS;
    bag_pockets[POCKET_BERRIES - 1].items = save1->bag_pocket_berries;
    bag_pockets[POCKET_BERRIES - 1].capacity = MAX_NUM_BAG_BERRIES;
    bag_pockets[POCKET_BAIT - 1].items = save1->bag_pocket_bait;
    bag_pockets[POCKET_BAIT - 1].capacity = MAX_NUM_BAG_BAIT;
    bag_pockets[POCKET_MEDICINE - 1].items = cmem.bag_pocket_medicine;
    bag_pockets[POCKET_MEDICINE - 1].capacity = MAX_NUM_BAG_MEDICINE;
}

void bag_clear() {
    for (int i = 0; i < NUM_POCKETS - 1; i++)
        bag_clear_slots(bag_pockets[i].items, bag_pockets[i].capacity);
}

/** Test the code **/

static void bag_wait_for_fadescreen_and_initialize(u8 self) {
    if (!fading_control.active) {
        bag_open(BAG_CONTEXT_OVERWORLD, BAG_OPEN_LAST, map_reload);
        big_callback_delete(self);
    }
}

void test_bag2() {
    fadescreen(0xFFFFFFFF, (u8)-2, 0, 16, 0);
    big_callback_new(bag_wait_for_fadescreen_and_initialize, 0);
}


void empty_pocket_berries() {
    bag_clear_slots(bag_pockets[POCKET_TO_BAG_POCKETS_IDX(POCKET_BERRIES)].items, bag_pockets[POCKET_BERRIES - 1].capacity);
}

u16 bag_get_current_slot_in_current_pocket() {
    u8 pocket = bag_get_current_pocket();
    return (u16)(fmem.bag_cursor_position[POCKET_TO_BAG_POCKETS_IDX(pocket)] + fmem.bag_cursor_items_above[POCKET_TO_BAG_POCKETS_IDX(pocket)]);
}

void bag_fix_pockets() {
    bool fixed_point;
    do {
        fixed_point = false;
        for (int i = 1; i < NUM_POCKETS; i++) {
            bag_pocket_t *p = bag_pockets + POCKET_TO_BAG_POCKETS_IDX(i);
            for (int j = 0; j < p->capacity; j++) {
                if (p->items[j].item_idx != ITEM_NONE) {
                    item_slot_set_quantity(&p->items[j].quantity, MIN(999, item_slot_get_quantity(&p->items[j].quantity)));
                    if (item_get_pocket(p->items[j].item_idx) != i) {
                        item_add(p->items[j].item_idx, item_slot_get_quantity(&p->items[j].quantity));
                        fixed_point = true;
                        p->items[j].item_idx = ITEM_NONE;
                        item_slot_set_quantity(&p->items[j].quantity, 0);
                    }
                }
            }
            bag_pocket_compact(p->items, p->capacity);
        }
    } while (fixed_point);


}