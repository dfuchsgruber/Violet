#include "types.h"
#include "overworld/script.h"
#include "bg.h"
#include "callbacks.h"
#include "pokemon/sprites.h"
#include "oam.h"
#include "text.h"
#include "transparency.h"
#include "color.h"

bool overworld_script_show_pokemon_picture (u16 species, u8 x, u8 y) {
    if (big_callback_is_active(overworld_script_callback_show_pokemon_picture))
        return false;
    u8 oam_idx = pokemon_oam_new(species, (s16)(8 * x + 40), (s16)(8 * y + 40));
    u8 cb_idx = big_callback_new(overworld_script_callback_show_pokemon_picture, 80);
    u8 tbox_idx = tbox_new_by_box(x, y, 8, 8);
    big_callbacks[cb_idx].params[5] = tbox_idx;
    big_callbacks[cb_idx].params[0] = 0;
    big_callbacks[cb_idx].params[1] = species;
    big_callbacks[cb_idx].params[2] = oam_idx;
    oams[oam_idx].callback = oam_null_callback;
    oams[oam_idx].final_oam.attr0 = (u16)(oams[oam_idx].final_oam.attr0 & (~(3 << 10))); // priority 0
    tbox_init_border_standard_style(tbox_idx, true);
    if (transparency_is_on()) {
        transparency_on();
        pal_copy(tbox_palette_transparent, 14 * 16, 16 * sizeof(color_t)); // Override border palette
    }
    bg_virtual_sync_reqeust_push(0);
    return true;
}