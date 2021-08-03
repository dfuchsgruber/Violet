#include "types.h"
#include "overworld/script.h"
#include "transparency.h"
#include "debug.h"
#include "callbacks.h"
#include "vars.h"
#include "list_menu.h"

static void yesnobox_new_at(u8 x, u8 y, u8 default_no) {
    tboxdata boxdata = {
        .bg_id = 0, .x = x, .y = y, .w = 6, .h = 4, .pal = 15, .start_tile = 0x125,
    };
    gp_list_menu_yes_no_new(&boxdata, 2, 0, 2, 0x214, 14, default_no);
}

bool yesnobox(u8 x, u8 y) {
    if (big_callback_is_active(yesnobox_handle_input))
        return false;
    lastresult = 0xFF;
    yesnobox_new_at(x, y, false);
    big_callback_new(yesnobox_handle_input, 80);
    return true;
}

bool script_cmd_x6E_yesnobox(overworld_script_state_t *state) {
    u8 x = *(state->script++);
    u8 y = *(state->script++);
    if (yesnobox(x, y)) {
        if (transparency_is_on()) {
            transparency_on();
            pal_copy(tbox_palette_transparent, 14 * 16, 16 * sizeof(color_t)); // Override border palette
        }
        overworld_script_halt();
        return true;
    }
    return false;
}

bool script_cmd_x6F_multichoice(overworld_script_state_t *state) {
    u8 x = *(state->script++);
    u8 y = *(state->script++);
    u8 idx = *(state->script++);
    u8 ignore_b = *(state->script++);
    if (multichoice(x, y, idx, ignore_b)) {
        if (transparency_is_on()) {
            transparency_on();
            pal_copy(tbox_palette_transparent, 14 * 16, 16 * sizeof(color_t)); // Override border palette
        }
        overworld_script_halt();
        return true;
    }
    return false;
}

bool script_cmd_x70_multichoice_with_default(overworld_script_state_t *state) {
    u8 x = *(state->script++);
    u8 y = *(state->script++);
    u8 idx = *(state->script++);
    u8 ignore_b = *(state->script++);
    u8 default_idx = *(state->script++);
    if (multichoice_with_default(x, y, idx, ignore_b, default_idx)) {
        if (transparency_is_on()) {
            transparency_on();
            pal_copy(tbox_palette_transparent, 14 * 16, 16 * sizeof(color_t)); // Override border palette
        }
        overworld_script_halt();
        return true;
    }
    return false;
}

bool script_cmd_x71_multichoice_grid(overworld_script_state_t *state) {
    u8 x = *(state->script++);
    u8 y = *(state->script++);
    u8 idx = *(state->script++);
    u8 num_columns = *(state->script++);
    u8 ignore_b = *(state->script++);
    if (multichoice_grid(x, y, idx, ignore_b, num_columns)) {
        if (transparency_is_on()) {
            transparency_on();
            pal_copy(tbox_palette_transparent, 14 * 16, 16 * sizeof(color_t)); // Override border palette
        }
        overworld_script_halt();
        return true;
    }
    return false;
}