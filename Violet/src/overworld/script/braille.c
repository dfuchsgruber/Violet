#include "types.h"
#include "overworld/script.h"
#include "text.h"
#include "save.h"
#include "debug.h"

static tbox_font_colormap braille_font_color_map = {
    .background = 1, .body = 2, .edge = 3, .shadow = 3
};

bool overworld_script_command_braille(overworld_script_state_t *state) {

    u8 *str = (u8*)overworld_script_read_word(state);
    if (!str) {
        str = state->pointer_banks[0];
    }

    u8 width = (u8)(string_get_width(TBOX_FONT_BRAILLE, str, -1) / 8);
    u8 height = 4;
    for (int i = 0; str[i] != 0xFF; i++) {
        if (str[i] == 0xFE) {
            height = MIN((u8)(height + 3), 18);
        }
    }
    DEBUG("braille height %d\n", height);
    u8 x = (u8)((30 - width) / 2);
    u8 y = (u8)((20 - height) / 2);

    tboxdata box;
    tbox_data_new(&box, 0, x, y, width, height, 15, 1);
    fmem.tbox_idx_braille = tbox_new(&box);

    tbox_print_std_frame(fmem.tbox_idx_braille, false);
    tbox_flush_set(fmem.tbox_idx_braille, 0x11);
    tbox_tilemap_draw(fmem.tbox_idx_braille);

    tbox_print_string(fmem.tbox_idx_braille, TBOX_FONT_BRAILLE, 0, 8, 0, 8, &braille_font_color_map, 0, str);

    tbox_copy_to_vram(fmem.tbox_idx_braille, 3);
    return false;
}

bool overworld_script_command_close_braille(overworld_script_state_t *state) {
    (void) state;
    tbox_flush_all(fmem.tbox_idx_braille, 0);
    tbox_flush_map(fmem.tbox_idx_braille);
    tbox_sync(fmem.tbox_idx_braille, TBOX_SYNC_MAP_AND_SET);
    tbox_flush_map_and_frame(fmem.tbox_idx_braille);
    tbox_free(fmem.tbox_idx_braille);
    return false;
}