#include "types.h"
#include "item/item.h"
#include "item/item_effect.h"
#include "pokemon/virtual.h"
#include "overworld/pokemon_party_menu.h"
#include "bg.h"
#include "callbacks.h"

extern const u8 ow_script_item_has_no_effect[];

static void item_evolution_stone(u8 self, void (*item_field_usage_on_poke_callback_failure)(u8)) {
    if (item_effect(player_pokemon + pokemon_party_menu_state.slot_idx, item_activated, pokemon_party_menu_state.slot_idx, 0, false, false)) {
        item_remove(item_activated, 1);
        evolution_continuation = pokemon_party_menu_state.callback;
    } else {
        pokemon_party_menu_use_return_callback = 0;
        pokemon_party_menu_init_text_rendering(str_item_has_no_effect, true);
        bg_virtual_sync_reqeust_push(2);
        big_callbacks[self].function = item_field_usage_on_poke_callback_failure;
    }
}

void item_field_function_evolution_stone(u8 self) {
    item_callback_after_pokemon_selected = item_evolution_stone;
    item_select_target_pokemon(self);
}

u8 item_is_tm_or_evolution_stone(u16 item_idx) {
    if (item_get_pocket(item_idx) == POCKET_TM_HM) {
        return ITEM_EVOLUTION_OR_TM_TM;
    } else if (item_get_field_function(item_idx) == item_field_function_evolution_stone) {
        return ITEM_EVOLUTION_OR_TM_EVOLUTION;
    } else {
        return ITEM_EVOLUTION_OR_TM_NONE;
    }
}