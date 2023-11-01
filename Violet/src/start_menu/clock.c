#include "types.h"
#include "rtc.h"
#include "oam.h"
#include "save.h"
#include "callbacks.h"
#include "overworld/start_menu.h"
#include "color.h"
#include "fading.h"
#include "debug.h"
#include "text.h"
#include "overworld/map_control.h"
#include "save.h"
#include "superstate.h"
#include "language.h"
#include "gp_menu.h"
#include "pokepad/pokedex/scanner.h"

static const tboxdata start_menu_clock_tboxdata = {
    .bg_id = 0, .x = 1, .y = 1, .w = 6, .h = 4, .pal = 14, .start_tile = 8 
};

static const u8 start_menu_clock_text[] = LANGDEP(
    PSTRING("Uhrzeit"), PSTRING("Time")
);

static const u8 start_menu_clock_colon[] = PSTRING(":");

static const u16 clock_digit_x_positions[4] = {2, 11, 27, 37};

static void start_menu_clock_update() {
    tbox_print_string_parametrized(start_menu_state.safari_tbox_idx, 2, start_menu_clock_text, 0, 0, 0, NULL);
    rtc_timestamp time;
    time_read(&time);
    int digits[4] = {time.hour / 10, time.hour % 10, time.minute / 10, time.minute % 10};
    for (int i = 0; i < 4; i++) {
        //DEBUG("Digits[%d] = %d, offset: %x\n", i, digits[i], gfx_start_menu_7_segmentTiles + GRAPHIC_SIZE_4BPP(16, 16) * digits[i]);
        tbox_blit(start_menu_state.safari_tbox_idx, gfx_start_menu_7_segmentTiles, 0, (u16)(16 * digits[i]), 16, 160, clock_digit_x_positions[i], 16, 10, 16);
    }
    tbox_print_string_parametrized(start_menu_state.safari_tbox_idx, 2, start_menu_clock_colon, 21, 18, 0, NULL);
}

void start_menu_print_clock() {
    if (fading_is_active()) return;
    start_menu_state.safari_tbox_idx = tbox_new(&start_menu_clock_tboxdata);
    tbox_tilemap_draw(start_menu_state.safari_tbox_idx);
    tbox_print_std_frame(start_menu_state.safari_tbox_idx, false);
    start_menu_clock_update();
};

#if USE_7SEG_CLOCK
#else
static void start_menu_clock_callback(u8 self) {
    if (++big_callbacks[self].params[0] == 60) {
        big_callbacks[self].params[0] = 0;
        start_menu_clock_update();
    }
}
#endif // USE_7SEG_CLOCK

bool start_menu_initilize() {
    switch (start_menu_state.initialization_state) {
        case START_MENU_STEUP_STATE_BUILD:
            start_menu_build();
            break;
        case START_MENU_SETUP_STATE_LOAD_GFX: {
            tbox_load_message_gfx_and_pal();
            u8 box_idx = start_menu_tbox_initialize(start_menu_state.number_items);
            tbox_print_std_frame(box_idx, false);
            break;
        }
        case START_MENU_SETUP_STATE_PRINT_SAFARI_OR_CLOCK:
            if (safari_is_active()) {
                start_menu_print_safari_balls();
            } else if (true) {
                start_menu_print_clock();
            }
            break;
        case START_MENU_SETUP_SCANNER:
            start_menu_print_scanner();
            break;
        case START_MENU_SETUP_STATE_PRINT_ITEMS:
            if (!start_menu_draw_items(&(start_menu_state.number_items_printed), 2)) {
                return false;
            }
            break;
        case START_MENU_SETUP_STATE_SETUP_LIST: {
            u8 box_idx = start_menu_get_tbox_idx();
            start_menu_state.cursor = gp_menu_initialize_with_unmuted_a_press(box_idx, 2, 0, 0, 15, 
                start_menu_state.number_items, start_menu_state.cursor);
            if (!sub_080bf8d8() && !is_bank_x0_and_map_x40()) {
                start_menu_print_item_description(start_menu_item_descriptions[start_menu_state.items[start_menu_state.cursor]]);
            }
            tbox_copy_to_vram(box_idx, 1);
            if (!safari_is_active() && !mapheader_virtual.flash_type)
                big_callback_new(start_menu_clock_callback, 50);
            return true;
        }
    }
    start_menu_state.initialization_state++;
    return false;
}

void start_menu_clear_additional_box() {
    if (!safari_is_active()) {
        u8 idx = big_callback_get_id(start_menu_clock_callback);
        if (idx != 0xFF) big_callback_delete(idx);
        tbox_flush_all(start_menu_state.safari_tbox_idx, 0);
        tbox_copy_to_vram(start_menu_state.safari_tbox_idx, 2);
        tbox_free(start_menu_state.safari_tbox_idx);
    } else if (safari_is_active()) {
        tbox_flush_all(start_menu_state.safari_tbox_idx, 0);
        tbox_copy_to_vram(start_menu_state.safari_tbox_idx, 2);
        tbox_free(start_menu_state.safari_tbox_idx);
    }
}

bool start_menu_save_initialize_and_clear_additional_box() {
    if (!safari_is_active() && !mapheader_virtual.flash_type) {
        u8 idx = big_callback_get_id(start_menu_clock_callback);
        if (idx != 0xFF) big_callback_delete(idx);
    }
    return start_menu_save_initialize();
}