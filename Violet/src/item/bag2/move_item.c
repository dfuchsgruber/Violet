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

bool bag_can_items_be_moved() {
    return BAG2_STATE->context == BAG_CONTEXT_OVERWORLD;
}

static u8 str_where_should_item_be_moved[] = LANGDEP(PSTRING("Wohin\nverschieben?"), PSTRING("Move to\nwhere?"));

void bag_start_moving_item(u8 cb_idx, u16 position) {
    u8 pocket = bag_get_current_pocket();
    (void)pocket;(void)cb_idx;
    BAG2_STATE->is_moving_item = true;
    BAG2_STATE->moving_item_original_position = (u16)position;
    bag_print_hint(str_where_should_item_be_moved);
}
