#include "types.h"
#include "overworld/script.h"
#include "bg.h"
#include "callbacks.h"
#include "pokemon/sprites.h"
#include "oam.h"
#include "text.h"
#include "transparency.h"
#include "color.h"

void money_draw(u32 money, u8 x, u8 y) {
    tboxdata boxdata;
    tbox_data_new(&boxdata, 0, (u8)(x + 1), (u8)(y + 1), 8, 3, 15, 8);
    tbox_idx_money = tbox_new(&boxdata);
    tbox_flush_set(tbox_idx_money, 0);
    tbox_tilemap_draw(tbox_idx_money);
    tbox_message_init_border(tbox_idx_money, 0x21D, 13 * 16);
    if (transparency_is_on()) {
        transparency_on();
        pal_copy(tbox_palette_transparent, 13 * 16, 16 * sizeof(color_t)); // Override border palette
    }
    tbox_print_money(tbox_idx_money, 0x21D, 13, money);
}