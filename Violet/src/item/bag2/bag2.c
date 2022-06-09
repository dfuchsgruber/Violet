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

static u8 bag_pocket_order[] = {
    POCKET_ITEMS, POCKET_MEDICINE, POCKET_POKEBALLS, POCKET_TM_HM, POCKET_BERRIES, POCKET_KEY_ITEMS, POCKET_BAIT,
};

u8 bag_get_current_pocket() {
    return bag_pocket_order[cmem.bag_pocket];
}

void bag_delete_scroll_indicators_items() {
    scroll_indicator_delete(BAG2_STATE->scroll_indicator_items_cb_idx);
}

void bag_delete_scroll_indicators_pockets() {
    scroll_indicator_delete(BAG2_STATE->scroll_indicator_pockets_cb_idx);
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
    list_menu_get_scroll_and_row(BAG2_STATE->list_menu_cb_idx, fmem.bag_cursor_position + pocket - 1, fmem.bag_cursor_items_above + pocket - 1);
    switch (input) {
        case LIST_MENU_B_PRESSED: {
        exit_bag:
            play_sound(5);
            bag_close(self, ITEM_NONE, true);
            break;
        }
        case LIST_MENU_NOTHING_CHOSEN:
            return;
        default: {
            if (input == BAG2_STATE->pocket_size[pocket]) {
                goto exit_bag;
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
    if (self->flags & OAM_FLAG_GFX_ROTSCALE_ANIM_END) {
        oam_rotscale_anim_init(self, 0);
        self->callback = oam_null_callback;
    }
}

void bag_shake_oam() {
    oam_object *o = oams + BAG2_STATE->oam_idx_bag;
    if (o->flags & OAM_FLAG_GFX_ROTSCALE_ANIM_END) {
        oam_rotscale_anim_init(o, 1);
        o->callback = bag_oam_callback_bag_shaking;
    }
}

static u8 str_close_bag[] = LANGDEP(PSTRING("Beutel schließen"), PSTRING("Close bag"));

static tbox_font_colormap font_colormap_description = {.background = 0, .body = 1, .edge = 2};

void bag_print_item_description(u16 slot) {
    u8 pocket = bag_get_current_pocket();
    u8 *description;
    if (slot == BAG2_STATE->pocket_size[pocket])
        description = str_close_bag;
    else
        description = item_get_description(item_get_idx_by_pocket_position(pocket, slot));
    tbox_flush_set(BAG_TBOX_DESCRIPTION, 0x00);
    tbox_print_string(BAG_TBOX_DESCRIPTION, 2, 0, 3, 0, 0, &font_colormap_description, 0, description);
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
    BAG2_STATE->scroll_indicator_pockets_cb_idx = scroll_indicator_new(&scroll_indicator_template_pockets,
        &cmem.bag_pocket);
    scroll_indicator_set_oam_priority(BAG2_STATE->scroll_indicator_pockets_cb_idx, 2, 2);
}

static void bag_close_wait_fadescreen_and_continue(u8 self) {
    if (fading_control.active || big_callback_is_active(bag_win0_animation))
        return;
    u8 pocket_idx = bag_get_current_pocket();
    list_menu_remove(BAG2_STATE->list_menu_cb_idx, fmem.bag_cursor_position + pocket_idx - 1, fmem.bag_cursor_items_above + pocket_idx - 1);
    bag_delete_scroll_indicators_pockets();
    bag_delete_scroll_indicators_items();
    if (BAG2_STATE->internal_continuation)
        callback1_set(BAG2_STATE->internal_continuation);
    else
        callback1_set(BAG2_STATE->continuation);
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
    big_callbacks[cb_idx].function = bag_close_wait_fadescreen_and_continue;
    fadescreen(0xFFFFFFFF, (u8)-2, 0, 16, 0);
}

void bag_open(u8 context, u8 open_which, void (*continuation)()) {
    // Todo reset state
    fmem.bag2_state = malloc_and_clear(sizeof(bag2_state_t));
    if (!fmem.bag2_state) {
        callback1_set(continuation);
        return;
    } else {
        BAG2_STATE->initialization_state = 0;
        BAG2_STATE->context = context;
        BAG2_STATE->open_which = open_which;
        BAG2_STATE->continuation = continuation;
        if (open_which != BAG_OPEN_LAST) {
            for (cmem.bag_pocket = 0; cmem.bag_pocket <= ARRAY_COUNT(bag_pocket_order); cmem.bag_pocket++) {
                if (bag_pocket_order[cmem.bag_pocket] == open_which)
                    break;
            }
        }
        bag_initialize_compute_item_counts();
        callback1_set(bag_cb_initialize);
    }
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