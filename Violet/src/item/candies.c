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

bool item_effect_level_up_unapplicable(pokemon *target, u16 item) {
    (void)item;
    return pokemon_get_attribute(target, ATTRIBUTE_LEVEL, 0) >= 100;
}

bool item_effect_level_up_apply(pokemon *target, u16 item) {
    if (!item_effect_level_up_unapplicable(target, item)) {
        int level = MIN(100, pokemon_get_attribute(target, ATTRIBUTE_LEVEL, 0) + item_effects[item - ITEM_TRANK][10]);
        pokemon_set_attribute(target, ATTRIBUTE_EXP, 
            &pokemon_experience_tables[basestats[pokemon_get_attribute(target, ATTRIBUTE_SPECIES, 0)].level_up_type][level]);
        pokemon_calculate_stats(target);
        return false;
    }
    return true;
}

/**
void item_field_golden_candy(u8 self) {
    item_callback_after_pokemon_selected = item_golden_candy;
    item_select_target_pokemon(self);
}

void item_golden_candy(u8 self, void (*failure_continuation)(u8)) {
    pokemon *p = player_pokemon + pokemon_party_menu_current_index;
    int level = pokemon_get_attribute(p, ATTRIBUTE_LEVEL, 0) + GOLDEN_CANDY_LEVEL_INCREASE;
    int species = pokemon_get_attribute(p, ATTRIBUTE_SPECIES, 0);
    if (level <= 100) {
        pokemon_set_attribute(p, ATTRIBUTE_EXP, pokemon_experience_tables[basestats[species].level_up_type][level]);
        pokemon_calculate_stats(p);
        play_sound(114);
        item_remove(item_activated, 1);
    } else {

    }
    if (possible) {
        //Now we compute the new nature
        u32 new_nature = (u32) (new_positive * 5 + new_negative);
        poke_pid.fields.nature = new_nature & 0x1F;
        pokemon_set_attribute(&player_pokemon[pokemon_party_menu_current_index],
        		ATTRIBUTE_PID, &poke_pid);
        pokemon_calculate_stats(&player_pokemon[pokemon_party_menu_current_index]);
        //Todo remove item and return to bag
        pokemon_load_name_as_string(&player_pokemon[pokemon_party_menu_current_index], buffer0);
        string_decrypt(strbuf, str_nature_stone_sucess);
        pokemon_party_menu_init_text_rendering(strbuf, 1); //String @"Es wird keine Wirkung haben"
        bg_virtual_sync_reqeust_push(2);
        big_callbacks[self].function = item_field_usage_on_poke_callback_failure; //0x8125711;
    } else {
        play_sound(5);
        pokemon_party_menu_init_text_rendering((u8*) 0x08416824, 1); //String @"Es wird keine Wirkung haben"
        //pokemenu_init_textrenderer(str_nature_stone_sucess_ref, 1);
        bg_virtual_sync_reqeust_push(2);
        big_callbacks[self].function = item_field_usage_on_poke_callback_failure;
    }
}
**/