#include "types.h"
#include "item/bag2.h"
#include "language.h"

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
    return bag_context_hints[BAG2_STATE->context];
}

static tbox_font_colormap font_colormap_pocket_hint = {.background = 0, .body = 2, .edge = 1}; 

void bag_print_hint(u8 *hint) {
    if (hint) {
        tbox_flush_set(BAG_TBOX_HINT, 0x11);
        tbox_tilemap_draw(BAG_TBOX_HINT);
        tbox_print_string(BAG_TBOX_HINT, 0, 2, 0, 0, 0, &font_colormap_pocket_hint, 0, hint);
    } else {
        tbox_flush_set(BAG_TBOX_HINT, 0x00);
        tbox_flush_map(BAG_TBOX_HINT);
    }
}