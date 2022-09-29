#include "types.h"
#include "stdbool.h"
#include "constants/items.h"
#include "pokemon/virtual.h"
#include "pokemon/basestat.h"
#include "callbacks.h"
#include "item/custom.h"
#include "constants/pokemon_attributes.h"
#include "language.h"
#include "item/item.h"
#include "text.h"
#include "bg.h"
#include "overworld/pokemon_party_menu.h"
#include "music.h"
#include "data_structures.h"
#include "ev_menu.h"
#include "debug.h"

extern u8 str_item_has_no_effect[];

void item_field_nature_stone(u8 self) {
    item_callback_after_pokemon_selected = item_nature_stone;
    item_select_target_pokemon(self);
}

u32 item_nature_stone_modify_nature(u8 nature, u16 item_idx) {
    u32 positive = 255, negative = 255;
    switch (item_idx) {
        case ITEM_ANGR_ORB_P:
            positive = 0;
            break;
        case ITEM_ANGR_ORB_N:
            negative = 0;
            break;
        case ITEM_VERT_ORB_P:
            positive = 1;
            break;
        case ITEM_VERT_ORB_N:
            negative = 1;
            break;
        case ITEM_INIT_ORB_P:
            positive = 2;
            break;
        case ITEM_INIT_ORB_N:
            negative = 2;
            break;
        case ITEM_SPA_ORB_P:
            positive = 3;
            break;
        case ITEM_SPA_ORB_N:
            negative = 3;
            break;
        case ITEM_SPV_ORB_P:
            positive = 4;
            break;
        case ITEM_SPV_ORB_N:
            negative = 4;
            break;
    }
    if (positive == 255)
        positive = nature / 5;
    if (negative == 255)
        negative = nature % 5;
    return (u32)(positive * 5 + negative);
}


void item_nature_stone(u8 self, void (*item_field_usage_on_poke_callback_failure)(u8)) {

    pid_t poke_pid = {(u32)pokemon_get_attribute(
        &player_pokemon[pokemon_party_menu_current_index], ATTRIBUTE_PID, 0)};
    u8 current_nature = poke_pid.fields.nature;
    DEBUG("Current nature is %d, new nature is %d", current_nature, item_nature_stone_modify_nature(current_nature, item_activated));
    if (current_nature != item_nature_stone_modify_nature(current_nature, item_activated)) {
        pokemon_party_menu_state.callback = ev_menu_initialize_change_nature;
        item_remove(item_activated, 1);
        pokemon_party_menu_return_and_execute_callback(self);
    } else {
        play_sound(5);
        pokemon_party_menu_init_text_rendering(str_item_has_no_effect, 1); //String @"Es wird keine Wirkung haben"
        bg_virtual_sync_reqeust_push(2);
        big_callbacks[self].function = item_field_usage_on_poke_callback_failure;
    }
}

static void item_null_syrup(u8 self, void (*item_field_usage_on_poke_callback_failure)(u8)) {
    pokemon *p = &player_pokemon[pokemon_party_menu_current_index];
    bool usable = false;
    for (u8 stat = 0; stat < 6; stat++) {
        if (pokemon_get_effective_ev(p, stat) > 0)
            usable = true;
    }
    if (!usable) {
        play_sound(5);
        pokemon_party_menu_init_text_rendering(str_item_has_no_effect, 1); //String @"Es wird keine Wirkung haben"
        bg_virtual_sync_reqeust_push(2);
        big_callbacks[self].function = item_field_usage_on_poke_callback_failure;
    } else {
        item_remove(item_activated, 1);
        pokemon_party_menu_state.callback = ev_menu_initialize_clear_effective_ev;
        pokemon_party_menu_return_and_execute_callback(self);
    }
} 

void item_field_null_syrup(u8 self) {
    item_callback_after_pokemon_selected = item_null_syrup;
    item_select_target_pokemon(self);
}