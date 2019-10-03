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

static graphic start_menu_clock_7_segment_graphic = {
    .sprite = gfx_start_menu_7_segmentTiles, .tag = START_MENU_GFX_7_SEGMENT_TAG,
    .size = 32 * 320 / 2
};

static sprite start_menu_clock_7_segment_sprite = {
    .attr0 = ATTR0_SHAPE_SQUARE, .attr1 = ATTR1_SIZE_16_16, .attr2 = ATTR2_PRIO(0)
};

static gfx_frame start_menu_clock_7_segment_frames[] = {
    {.data = 0 * 4, .duration = 0}, {.data = GFX_ANIM_END},
    {.data = 1 * 4, .duration = 0}, {.data = GFX_ANIM_END},
    {.data = 2 * 4, .duration = 0}, {.data = GFX_ANIM_END},
    {.data = 3 * 4, .duration = 0}, {.data = GFX_ANIM_END},
    {.data = 4 * 4, .duration = 0}, {.data = GFX_ANIM_END},
    {.data = 5 * 4, .duration = 0}, {.data = GFX_ANIM_END},
    {.data = 6 * 4, .duration = 0}, {.data = GFX_ANIM_END},
    {.data = 7 * 4, .duration = 0}, {.data = GFX_ANIM_END},
    {.data = 8 * 4, .duration = 0}, {.data = GFX_ANIM_END},
    {.data = 9 * 4, .duration = 0}, {.data = GFX_ANIM_END},
};

static gfx_frame *start_menu_clock_7_segment_gfx_anim_table[] = {
    start_menu_clock_7_segment_frames + 0 * 2,
    start_menu_clock_7_segment_frames + 1 * 2,
    start_menu_clock_7_segment_frames + 2 * 2,
    start_menu_clock_7_segment_frames + 3 * 2,
    start_menu_clock_7_segment_frames + 4 * 2,
    start_menu_clock_7_segment_frames + 5 * 2,
    start_menu_clock_7_segment_frames + 6 * 2,
    start_menu_clock_7_segment_frames + 7 * 2,
    start_menu_clock_7_segment_frames + 8 * 2,
    start_menu_clock_7_segment_frames + 9 * 2,
};

void start_menu_clock_oam_callback(oam_object *self) {
    if (self->private[0]-- == 0) {
        self->private[0] = 60; // Request the rtc time every 60 frames (~1 sec)
        rtc_timestamp time;
        time_read(&time);
        int digit = 8;
        switch (self->private[1]) {
            case START_MENU_CLOCK_HOURS_10:
                digit = time.hour / 10;
                break;
            case START_MENU_CLOCK_HOURS_1:
                digit = time.hour % 10;
                break;
            case START_MENU_CLOCK_MINUTES_10:
                digit = time.minute / 10;
                break;
            case START_MENU_CLOCK_MINUTES_1:
                digit = time.minute % 10;
                break;
        }
        self->anim_number = (u8)digit;
        oam_gfx_anim_init(self, 0);
    }
};

static oam_template start_menu_clock_7_segment_oam_template = {
    .tiles_tag = START_MENU_GFX_7_SEGMENT_TAG, .pal_tag = START_MENU_GFX_7_SEGMENT_TAG,
    .oam = &start_menu_clock_7_segment_sprite, .animation = start_menu_clock_7_segment_gfx_anim_table,
    .rotscale = oam_rotscale_anim_table_null, .callback = start_menu_clock_oam_callback
};

static u8 start_menu_clock_digit_types[] = {
    START_MENU_CLOCK_HOURS_10, START_MENU_CLOCK_HOURS_1, START_MENU_CLOCK_MINUTES_10, START_MENU_CLOCK_MINUTES_1
};

static tboxdata start_menu_clock_tboxdata = {
    .bg_id = 0, .x = 1, .y = 1, .w = 6, .h = 4, .pal = 15, .start_tile = 8 
};

static u8 start_menu_clock_text[] = LANGDEP(
    PSTRING("Uhrzeit"), PSTRING("Time")
);

static u8 start_menu_clock_colon[] = PSTRING(":");

void start_menu_print_clock() {
    if (fading_is_active()) return;
    oam_load_graphic(&start_menu_clock_7_segment_graphic);
    u8 pal_idx = oam_allocate_palette(START_MENU_GFX_7_SEGMENT_TAG);
    pal_decompress(gfx_start_menu_7_segmentPal, (u16)(256 + 16 * pal_idx), 16);
    for (int i = 0; i < 4; i++) {
        fmem.start_menu_clock_oam_idxs[i] = oam_new_forward_search(&start_menu_clock_7_segment_oam_template, 
            (s16)(16 + 11 * i + 5 * (i >= 2)), 32, 0);
        oams[fmem.start_menu_clock_oam_idxs[i]].private[1] = start_menu_clock_digit_types[i];
        oams[fmem.start_menu_clock_oam_idxs[i]].flags |= OAM_FLAG_INVISIBLE;
    }
    start_menu_state.safari_tbox_idx = tbox_new(&start_menu_clock_tboxdata);
    tbox_tilemap_draw(start_menu_state.safari_tbox_idx);
    tbox_print_std_frame(start_menu_state.safari_tbox_idx, false);
    tbox_print_string_parametrized(start_menu_state.safari_tbox_idx, 2, start_menu_clock_text, 0, 0, 255, NULL);
    tbox_print_string_parametrized(start_menu_state.safari_tbox_idx, 2, start_menu_clock_colon, 21, 18, 255, NULL);
    tbox_copy_to_vram(start_menu_state.safari_tbox_idx, 2);
};

bool start_menu_initilize() {
    switch (start_menu_state.initialization_state) {
        case 1:
            start_menu_build();
            break;
        case 2: {
            tbox_load_message_gfx_and_pal();
            u8 box_idx = start_menu_tbox_initialize(start_menu_state.number_items);
            tbox_print_std_frame(box_idx, false);
            break;
        }
        case 3:
            if (safari_is_active()) {
                start_menu_print_safari_balls();
            } else {
                start_menu_print_clock();
            }
            break;
        case 4:
            if (!start_menu_draw_items(&(start_menu_state.number_items_printed), 2)) {
                return false;
            }
            break;
        case 5: {
            u8 box_idx = start_menu_get_tbox_idx();
            start_menu_state.cursor = sub_0810f888(box_idx, 2, 0, 0, 15, 
                start_menu_state.number_items, start_menu_state.cursor);
            if (!sub_080bf8d8() && !is_bank_x0_and_map_x40()) {
                start_menu_print_item_description(start_menu_item_descriptions[start_menu_state.items[start_menu_state.cursor]]);
            }
            tbox_copy_to_vram(box_idx, 1);
            if (!safari_is_active()) {
                for (int i = 0; i < 4; i++) {
                    oams[fmem.start_menu_clock_oam_idxs[i]].flags &= (u16)(~OAM_FLAG_INVISIBLE);
                }
            }
            return true;
        }
    }
    start_menu_state.initialization_state++;
    return false;
}

void start_menu_clear_additional_box() {
    if (!safari_is_active()) {
        for (int i = 0; i < 4; i++) {
            oam_free(oams + fmem.start_menu_clock_oam_idxs[i]);
        }
    }
    tbox_flush_all(start_menu_state.safari_tbox_idx, 0);
    tbox_copy_to_vram(start_menu_state.safari_tbox_idx, 2);
    tbox_free_2(start_menu_state.safari_tbox_idx);
}

void start_menu_call_save_and_clear_additional_box() {
    if (!safari_is_active()) {
        for (int i = 0; i < 4; i++) {
            oam_free(oams + fmem.start_menu_clock_oam_idxs[i]);
        }
    }
    start_menu_call_save();
}