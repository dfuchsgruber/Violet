#include "types.h"
#include "item/bag2.h"
#include "item/bag.h"
#include "item/tm_hm.h"
#include "item/item.h"
#include "constants/item_pockets.h"

void bag_print_string(u8 callback_idx, u8 font, u8 *str, void (*continuation)(u8)) {
    tbox_flush_set(BAG_TBOX_MESSAGE, 0x11);
    tbox_tilemap_draw(BAG_TBOX_MESSAGE);
    tbox_print_string_and_continue(callback_idx, BAG_TBOX_MESSAGE, BAG_START_TILE_BORDER_MESSAGE, BAG_PAL_IDX_BORDER_MESSAGE,
        font, tbox_get_set_speed(), str, continuation);
    bg_virtual_sync_reqeust_push(0);
}

bool item_can_be_tossed(u16 item_idx) {
    if(item_is_hm(item_idx) || item_is_tm(item_idx) || item_get_pocket(item_idx) == POCKET_KEY_ITEMS)
        return false;
    return true;
}