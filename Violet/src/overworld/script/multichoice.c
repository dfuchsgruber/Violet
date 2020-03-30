#include "types.h"
#include "overworld/script.h"
#include "transparency.h"
#include "debug.h"

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