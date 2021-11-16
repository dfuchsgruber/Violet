#include "types.h"
#include "pokemon/virtual.h"
#include "field_move.h"
#include "overworld/pokemon_party_menu.h"
#include "constants/pokemon_attributes.h"
#include "battle/state.h"
#include "debug.h"
#include "agbmemory.h"
#include "item/animation.h"
#include "item/tm_hm.h"
#include "attack.h"
#include "callbacks.h"

void pokemon_party_menu_options_build(pokemon *base, u8 index) {
    pokemon_party_menu_options_state_t *options_state = pokemon_party_menu_state.options_state;
    options_state->number_options = 0;
    pokemon_party_menu_opt_add(options_state->options, &options_state->number_options, 0); //Adding summary
    //adding field moves
    int i;
    for (i = 0; i < 4; i++) {
        u16 attack = (u16) pokemon_get_attribute(&base[index], ATTRIBUTE_ATTACK1 + i, NULL);
        int j;
        for (j = 0; field_moves[j] != 0xFFFF; j++) {
            if (attack == field_moves[j]) {
                pokemon_party_menu_opt_add(options_state->options, &options_state->number_options, (u8) (j + 0x12));
            }
        }
    }
    //adding switch
    if (pokemon_get_attribute(&base[1], ATTRIBUTE_SPECIES, NULL)) {
        //at least two pokemon are present
        pokemon_party_menu_opt_add(options_state->options, &options_state->number_options, 1); //Adding switch
    }
    //Adding back button and items
    pokemon_party_menu_opt_add(options_state->options, &options_state->number_options, 3);
    //Adding ev menu
    if (!pokemon_get_attribute(&base[index], ATTRIBUTE_IS_EGG, NULL) && options_state->number_options < 7) {
        pokemon_party_menu_opt_add(options_state->options, &options_state->number_options, 6);
    }
    pokemon_party_menu_opt_add(options_state->options, &options_state->number_options, 2);
}

u8 pokemon_party_menu_layout_by_battle_type() {
    if (!battle_is_double()) return PARTY_LAYOUT_SINGLE;
    else if(battle_is_multi_double() || battle_is_tag()) return PARTY_LAYOUT_MULTI;
    else return PARTY_LAYOUT_DOUBLE;
}

bool pokemon_party_menu_can_switch_into_index(u8 index) {
    // DEBUG("Can switch into %d?\n", index);
    if(!battle_is_multi_double() && !battle_is_tag()) return true;
    else return index != 1 && index != 4 && index != 5;
}

void pokemon_party_menu_load_partner_party(pokemon *p) {
    for (int i = 0; i < 3; i++) {
        pokemon_party_menu_partner_party[i].species = (u16) pokemon_get_attribute(p + i, ATTRIBUTE_SPECIES, 0);
        pokemon_party_menu_partner_party[i].item = (u16) pokemon_get_attribute(p + i, ATTRIBUTE_ITEM, 0);
        pokemon_get_attribute(p + i, ATTRIBUTE_NICKNAME, pokemon_party_menu_partner_party[i].nickname); // We don't need to remove
        pokemon_party_menu_partner_party[i].level = (u8) pokemon_get_attribute(p + i, ATTRIBUTE_LEVEL, 0);
        pokemon_party_menu_partner_party[i].hp = (u16) pokemon_get_attribute(p + i, ATTRIBUTE_CURRENT_HP, 0);
        pokemon_party_menu_partner_party[i].max_hp = (u16) pokemon_get_attribute(p + i, ATTRIBUTE_TOTAL_HP, 0);
        pokemon_party_menu_partner_party[i].status = (u16) pokemon_get_attribute(p + i, ATTRIBUTE_STATUS, 0);
        pid_t pid = {.value = (u32)pokemon_get_attribute(p + i, ATTRIBUTE_PID, 0)};
        pokemon_party_menu_partner_party[i].pid = pid;
        pokemon_party_menu_partner_party[i].gender = pokemon_get_gender(&p[i].box);
        pokemon_party_menu_partner_party[i].language = (u8) pokemon_get_attribute(p + i, ATTRIBUTE_LANGUAGE, 0);
        // Pad Name string (we simply ignore japanese names)
        u8 j;
        for (j = 0; pokemon_party_menu_partner_party[i].nickname[j] != 0xFF; j++) ;
        while(j < 6) {
            pokemon_party_menu_partner_party[i].nickname[j++] = 0;
        }
        pokemon_party_menu_partner_party[i].nickname[j] = 0xFF;
    }
    memcpy(&battle_state->field_184, pokemon_party_menu_partner_party, 3 * sizeof(pokemon_party_menu_partner_pokemon_t));
}

void sub_08124f4c(void) {
    if (item_animation_is_disabled()) {
        pokemon *p = player_pokemon + pokemon_party_menu_state.slot_idx;
        u8 slot = pokemon_get_move_slot_to_replace();
        pokemon_clear_pp_ups(p, slot);
        pokemon_set_move(p, item_idx_to_attack(item_activated), slot);
        pokemon_add_friendship(p, 4);
        if (item_activated < ITEM_VM01)
            tm_set_used(ITEM_IDX_TO_TM_IDX(item_activated));
        callback1_set(pokemon_party_menu_state.callback);
    } else {
        pokemon_party_menu_init(pokemon_party_menu_state.menu_type, KEEP_PARTY_LAYOUT, pokemon_party_menu_state.action, 
            pokemon_party_menu_state.slot_idx, PARTY_MSG_NONE, pokemon_party_menu_continuation_apply_item_effect, pokemon_party_menu_state.callback);
    }
}

extern u8 str_pokemon_learned_move[];

void pokemon_party_menu_big_callback_learned_move(u8 self) {
    pokemon *p = player_pokemon + pokemon_party_menu_state.slot_idx;
    s16 *move = &pokemon_party_menu_state.data1;
    u16 item = item_activated;
    
    if (move[1] == 0) {
        pokemon_add_friendship(p, 4);
        if (item < ITEM_VM01)
            tm_set_used(ITEM_IDX_TO_TM_IDX(item));
    }
    pokemon_load_name_as_string(p, buffer0);
    strcpy(buffer1, attack_names[move[0]]);
    string_decrypt(strbuf, str_pokemon_learned_move);
    pokemon_party_menu_init_text_rendering(strbuf, true);
    bg_virtual_sync_reqeust_push(2);
    big_callbacks[self].function = pokemon_party_menu_play_fanfare_after_text_finished;
}