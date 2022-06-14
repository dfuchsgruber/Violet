#include "types.h"
#include "item/bag2.h"
#include "language.h"
#include "debug.h"

static u8 str_hint_give[] = LANGDEP(PSTRING("Welches Item\ngeben?"), PSTRING("Give which item\nto a Pokémon?"));
static u8 str_hint_deposit[] = LANGDEP(PSTRING("Welches Item\nablegen?"), PSTRING("Deposit which\nitem?"));
static u8 str_hint_recharge[] = LANGDEP(PSTRING("Welche Tm\naufladen?"), PSTRING("Recharge which\nTm?"));
static u8 str_hint_compost[] = LANGDEP(PSTRING("Welche Beere\nkompostieren?"), PSTRING("Compost which\nberry?"));
static u8 str_hint_sell[] = LANGDEP(PSTRING("Welches Item\nverkaufen?"), PSTRING("Sell which\nitem?"));
static u8 str_hint_plant_berry[] = LANGDEP(PSTRING("Welche Beere\npflanzen?"), PSTRING("Plant which\nberry?"));

static u8 *bag_context_hints[NUM_BAG_CONTEXTS] = {
    [BAG_CONTEXT_PARTY_GIVE] = str_hint_give,
    [BAG_CONTEXT_SELL] = str_hint_sell,
    [BAG_CONTEXT_DEPOSIT] = str_hint_deposit,
    [BAG_CONTEXT_BOX_GIVE] = str_hint_give,
    [BAG_CONTEXT_RECHARGE_TM_HM] = str_hint_recharge,
    [BAG_CONTEXT_COMPOST] = str_hint_compost,
    [BAG_CONTEXT_PLANT_BERRY] = str_hint_plant_berry,
};

u8 *bag_get_context_hint() {
    // DEBUG("Bag context is %d for hint 0x%x\n", fmem.bag_context, bag_context_hints[fmem.bag_context]);
    u8 pocket = bag_get_current_pocket();
    if (pocket == POCKET_TM_HM)
        return NULL;
    else
        return bag_context_hints[fmem.bag_context];
}

tbox_font_colormap bag_font_colormap_pocket_hint = {.background = 0, .body = 2, .edge = 1}; 

void bag_print_hint(u8 *hint) {
    if (bag_get_current_pocket() == POCKET_TM_HM) {
        tbox_fill_rectangle(BAG_TBOX_HINT, 0x11, 0, 0, 9 * 8 + 4, 10 * 8);
        tbox_sync(BAG_TBOX_HINT, TBOX_SYNC_SET);
        tbox_tilemap_draw(BAG_TBOX_HINT);
    } else if (hint) {
        tbox_flush_set(BAG_TBOX_HINT, 0x00);
        tbox_fill_rectangle(BAG_TBOX_HINT, 0x11, 0, 0, 9 * 8 + 4, 4 * 8);
        tbox_tilemap_draw(BAG_TBOX_HINT);
        tbox_print_string(BAG_TBOX_HINT, 0, 2, 0, 0, 0, &bag_font_colormap_pocket_hint, 0, hint);
    } else {
        tbox_flush_set(BAG_TBOX_HINT, 0x00);
        tbox_flush_map(BAG_TBOX_HINT);
    }
    bg_virtual_sync_reqeust_push(2);
}