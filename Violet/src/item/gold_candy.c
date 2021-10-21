#include "callbacks.h"
#include "item/item.h"
#include "overworld/pokemon_party_menu.h"
#include "save.h"
#include "superstate.h"
#include "types.h"

/*
 * This is way too much work... leave it for later (or never) and say that level-increase N-at once is good enough (even if one misses moves and potential evolutions)
 *
static void big_callback_nullsub(u8 self) {
    (void)self;
}
*/

/*
void item_gold_candy_field_effect(u8 self) {
    fmem.gold_candy_active = 1;
    fmem.gold_candy_levels_remaining = 3;
    item_callback_after_pokemon_selected = item_callback_rare_candy;
    item_field_fade_to_scene_and_execute_callback(self);
}

void callback2_return_to_bag_if_no_gold_candy_issued() {
    if (fmem.gold_candy_active && fmem.gold_candy_levels_remaining > 1) {
        --fmem.gold_candy_levels_remaining;
        item_callback_after_pokemon_selected = item_callback_rare_candy;
        callback1_set((void(*)())(0x08124cdc | 1));
        return;

    }
    // No gold candy increase
    fmem.gold_candy_active = 0;
    fmem.gold_candy_levels_remaining = 0;
    party_menu_continuation_return_to_bag();
}
*/
