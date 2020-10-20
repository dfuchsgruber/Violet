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

extern u8 str_item_has_no_effect[];

void item_field_nature_stone(u8 self) {
    item_callback_after_pokemon_selected = item_nature_stone;
    item_select_target_pokemon(self);
}


u8 str_nature_stone_sucess[] = LANGDEP(
    PSTRING("BUFFER_1 hat jetzt\ndas Wesen BUFFER_2.PAUSE_UNTIL_PRESS"),
    PSTRING("BUFFER_1\'s nature has\nchanged to BUFFER_2.PAUSE_UNTIL_PRESS"));

void item_nature_stone(u8 self, void (*item_field_usage_on_poke_callback_failure)(u8)) {

    pid_t poke_pid = {(u32)pokemon_get_attribute(
        &player_pokemon[pokemon_party_menu_current_index], ATTRIBUTE_PID, 0)};
    u8 current_nature = poke_pid.fields.nature;
    u32 current_positive = current_nature / 5;
    u32 current_negative = current_nature % 5;


    bool possible = false;

    u32 new_positive = 0xFF;
    u32 new_negative = 0xFF;
    switch (item_activated) {
        case ITEM_ANGR_ORB_P:
            new_positive = 0;
            break;
        case ITEM_ANGR_ORB_N:
            new_negative = 0;
            break;
        case ITEM_VERT_ORB_P:
            new_positive = 1;
            break;
        case ITEM_VERT_ORB_N:
            new_negative = 1;
            break;
        case ITEM_INIT_ORB_P:
            new_positive = 2;
            break;
        case ITEM_INIT_ORB_N:
            new_negative = 2;
            break;
        case ITEM_SPA_ORB_P:
            new_positive = 3;
            break;
        case ITEM_SPA_ORB_N:
            new_negative = 3;
            break;
        case ITEM_SPV_ORB_P:
            new_positive = 4;
            break;
        case ITEM_SPV_ORB_N:
            new_negative = 4;
            break;
    }

    //Now we check if the item can be used
    if (new_positive != 0xFF && new_positive != current_positive) {
        possible = true;
        new_negative = current_negative;
    }
    if (new_negative != 0xFF && new_negative != current_negative) {
        possible = true;
        new_positive = current_positive;
    }
    if (possible) {
        play_sound(258);
        //Now we compute the new nature
        u32 new_nature = (u32) (new_positive * 5 + new_negative);
        poke_pid.fields.nature = new_nature & 0x1F;
        strcpy(buffer1, pokemon_nature_strings[new_nature]);
        pokemon_set_attribute(&player_pokemon[pokemon_party_menu_current_index],
        		ATTRIBUTE_PID, &poke_pid);
        pokemon_calculate_stats(&player_pokemon[pokemon_party_menu_current_index]);
        //Todo remove item and return to bag
        item_remove(item_activated, 1);
        pokemon_load_name_as_string(&player_pokemon[pokemon_party_menu_current_index], buffer0);
        string_decrypt(strbuf, str_nature_stone_sucess);
        pokemon_party_menu_init_text_rendering(strbuf, 1);
        bg_virtual_sync_reqeust_push(2);
        big_callbacks[self].function = item_field_usage_on_poke_callback_failure; //0x8125711;
    } else {
        play_sound(5);
        pokemon_party_menu_init_text_rendering(str_item_has_no_effect, 1); //String @"Es wird keine Wirkung haben"
        bg_virtual_sync_reqeust_push(2);
        big_callbacks[self].function = item_field_usage_on_poke_callback_failure;
    }
}

static u8 str_item_null_syrup_used[] = LANGDEP(
    PSTRING("Die verteilten Fleiß-Punkte von\nBUFFER_1 wurden zurückgesetzt.PAUSE_UNTIL_PRESS"),
    PSTRING("All distributed effort values of\nBUFFER_1 were reset.PAUSE_UNTIL_PRESS")
);

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
        play_sound(257);
        for (u8 stat = 0; stat < 6; stat++) {
            pokemon_set_effective_ev(p, stat, 0);
        }
        item_remove(item_activated, 1);
        pokemon_load_name_as_string(&player_pokemon[pokemon_party_menu_current_index], buffer0);
        string_decrypt(strbuf, str_item_null_syrup_used);
        pokemon_party_menu_init_text_rendering(strbuf, 1);
        bg_virtual_sync_reqeust_push(2);
        big_callbacks[self].function = item_field_usage_on_poke_callback_failure;
    }
} 

void item_field_null_syrup(u8 self) {
    item_callback_after_pokemon_selected = item_null_syrup;
    item_select_target_pokemon(self);
}