#include "types.h"
#include "item/item.h"
#include "save.h"
#include "superstate.h"
#include "overworld/pokemon_party_menu.h"
#include "callbacks.h"
#include "music.h"
#include "item/item_effect.h"
#include "debug.h"

void item_callback_rare_candy(u8 self, void (*exit_continuation)(u8)) {
    u8 party_idx = pokemon_party_menu_current_index;
    bool no_effect = true;
    if (pokemon_get_attribute(player_pokemon + party_idx, ATTRIBUTE_LEVEL, NULL) < 100) {
        no_effect = !item_effect(player_pokemon + party_idx, item_activated, party_idx, 0, false, true);
    }
    play_sound(5);
    if (no_effect) {
        pokemon_party_menu_use_return_callback = false;
        pokemon_party_menu_init_text_rendering(str_item_has_no_effect, self);
        bg_virtual_sync_reqeust_push(2);
        big_callbacks[self].function = exit_continuation;
    } else {
        if (!fmem.rare_candy_item_removed) {
            item_remove(item_activated, 1);
            fmem.rare_candy_item_removed = true;
        }
        item_callback_after_pokemon_selected = item_callback_rare_candy_step;
        pokemon_party_menu_do_item_use_animation(self);
    }
}

bool item_rare_candy_is_issued() {
    if (item_activated == ITEM_SONDERBONBON || item_activated == ITEM_GOLDBONBON) {
        u8 party_idx = pokemon_party_menu_current_index;
        return fmem.rare_candy_levels_remaining > 0 && 
            pokemon_get_attribute(player_pokemon + party_idx, ATTRIBUTE_LEVEL, NULL) < 100 &&
            item_effect(player_pokemon + party_idx, item_activated, party_idx, 0, false, true);
    }
    return false;
}

void item_callback_do_rare_candy_if_issued(u8 self) {
    if (item_rare_candy_is_issued() && fmem.rare_candy_levels_remaining > 0) {
        fmem.rare_candy_levels_remaining--;
        item_callback_rare_candy(self, pokemon_party_menu_wait_for_text_and_close);
    } else {
        big_callbacks[self].function = pokemon_party_menu_wait_for_text_and_close;
    }
}

static void item_callback_do_rare_candy(u8 self) {
    // When giving N levels, at the first time we do not want to check if a level-up is
    // possible as we want the potential error message
    fmem.rare_candy_levels_remaining--;
    item_callback_rare_candy(self, pokemon_party_menu_wait_for_text_and_close);
}

static void item_callback_any_rare_candy(u8 self, void (*exit_continuation)(u8)) {
    (void)exit_continuation; // It is always `pokemon_party_menu_wait_for_text_and_close`
    big_callbacks[self].function = item_callback_do_rare_candy;
}

void item_gold_candy_field_effect(u8 self) {
    item_callback_after_pokemon_selected = item_callback_any_rare_candy;
    fmem.rare_candy_levels_remaining = 8;
    fmem.rare_candy_item_removed = false;
    item_field_fade_to_scene_and_execute_callback(self);
}

void item_rare_candy_field_effect(u8 self) {
    item_callback_after_pokemon_selected = item_callback_any_rare_candy;
    fmem.rare_candy_levels_remaining = 1;
    fmem.rare_candy_item_removed = false;
    item_field_fade_to_scene_and_execute_callback(self);
}
