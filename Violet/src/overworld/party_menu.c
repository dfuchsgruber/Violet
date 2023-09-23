#include "types.h"
#include "pokemon/virtual.h"
#include "field_move.h"
#include "overworld/script.h"
#include "overworld/pokemon_party_menu.h"
#include "constants/pokemon_attributes.h"
#include "battle/state.h"
#include "debug.h"
#include "agbmemory.h"
#include "item/item.h"
#include "item/animation.h"
#include "item/tm_hm.h"
#include "attack.h"
#include "callbacks.h"
#include "pokemon/evolution.h"
#include "item/item.h"
#include "fading.h"
#include "vars.h"
#include "pokemon/move_relearner.h"
#include "constants/move_tutor.h"

EWRAM bool (*pokemon_party_menu_choose_mon_generic_mon_is_eligible)(pokemon*) = NULL;

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
        pokemon_party_menu_partner_party[i].gender = box_pokemon_get_gender(&p[i].box);
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

extern const u8 str_pokemon_learned_move[];

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

static void pokemon_party_menu_evolution_continuation() {
    if (item_rare_candy_is_issued()) {
        // Return to the party menu and directly issue more executions of the candy 
        pokemon_party_menu_init(pokemon_party_menu_type.type, KEEP_PARTY_LAYOUT, PARTY_ACTION_CHOOSE_MON, pokemon_party_menu_current_index, PARTY_MSG_NONE,
            item_callback_do_rare_candy_if_issued, pokemon_party_menu_state.callback);

    } else {
        pokemon_party_menu_state.callback(); // Normal exit callback from the party menu
    }
}

void pokemon_party_menu_attempt_evolution(u8 self) {
    pokemon *p = player_pokemon + pokemon_party_menu_current_index;
    u16 target_species = pokemon_get_evolution(p, EVOLUTION_TRIGGER_LEVEL_UP, 0);
    if (target_species) {
        // TODO: Remaining candy levels afterwards
        pokemon_party_menu_free();
        evolution_continuation = pokemon_party_menu_evolution_continuation;
        pokemon_initialize_evolution(p, target_species, true, pokemon_party_menu_current_index);
        big_callback_delete(self);
    } else {
        big_callbacks[self].function = item_callback_do_rare_candy_if_issued; // Will close the party menu if no more level ups are issued
    }
}

static void pokemon_party_menu_skip_item_use_animation(u8 self) {
    DEBUG("Item callback after selected 0x%x\n", item_callback_after_pokemon_selected);
    item_callback_after_pokemon_selected(self, pokemon_party_menu_wait_for_text_and_close);
}

void pokemon_party_menu_do_item_use_animation(u8 self) {
    // We do not want this ***cking animation...
    big_callbacks[self].function = pokemon_party_menu_skip_item_use_animation;

}

static bool accessible_move_tutor_pokemon_is_eligible(pokemon *p) {
    u8 type = (u8)(*var_access(VAR_ACCESIBLE_MOVE_TUTOR_TYPE) - 1);
    u16 moves[25];
    int num_moves = pokemon_get_accesible_learnable_moves(p, moves, type);
    DEBUG("Slot 0x%x is eligible %d\n", p, num_moves > 0);
    return num_moves > 0;
}

void overworld_accessible_move_tutor_select_pokemon() {
    overworld_script_set_active();
    pokemon_party_menu_choose_mon_generic_mon_is_eligible = accessible_move_tutor_pokemon_is_eligible;
    u8 cb_idx = big_callback_new(pokemon_party_menu_initialize_and_select_pokemon_after_fadescreen, 10);
    big_callbacks[cb_idx].params[0] = PARTY_MENU_TYPE_CHOOSE_MON_WITH_GENERIC_RESTRICTIONS;
    // fadescreen(0xFFFFFFFF, 0, 0, 16, 0);
    fadescreen_all(FADE_TO_BLACK, 0);
}

bool pokemon_party_menu_display_party_pokemon_data_for_move_tutor_or_evolution_item(u8 slot) {
    pokemon *p = player_pokemon + slot;
    u16 item = item_activated;
    if (pokemon_party_menu_state.menu_type == PARTY_MENU_TYPE_CHOOSE_MON_WITH_GENERIC_RESTRICTIONS &&
        pokemon_party_menu_choose_mon_generic_mon_is_eligible) {
        if (pokemon_party_menu_choose_mon_generic_mon_is_eligible(p)) {
            pokemon_party_menu_render_box_display_description(slot, PARTY_MENU_BOX_DESCRIPTION_ABLE);
        } else { 
            pokemon_party_menu_render_box_display_description(slot, PARTY_MENU_BOX_DESCRIPTION_NOT_ABLE);
        }
        return true;
    }
    if (pokemon_party_menu_state.action == PARTY_ACTION_MOVE_TUTOR) {
        lastresult = false;
        if (*var_access(0x8005) >= NUM_MOVE_TUTORS)
            return false;
        pokemon_party_menu_render_box_display_learn_move_information(slot, 0, (u8)(*var_access(0x8005)));
    } else {
        if (pokemon_party_menu_state.action != PARTY_ACTION_USE_ITEM)
            return false;
        switch (item_is_tm_or_evolution_stone(item)) {
        default: {
            return false;
        }
        case ITEM_EVOLUTION_OR_TM_TM: // TM/HM
            pokemon_party_menu_render_box_display_learn_move_information(slot, item, 0);
            break;
        case ITEM_EVOLUTION_OR_TM_EVOLUTION: // Evolution stone
            if (!pokemon_get_attribute(p, ATTRIBUTE_IS_EGG, NULL) && 
                pokemon_get_evolution(p, EVOLUTION_TRIGGER_ITEM, item) != POKEMON_POKEMON_0)
                return false;
            pokemon_party_menu_render_box_display_description(slot, PARTY_MENU_BOX_DESCRIPTION_NO_USE);
            break;
        }
    }
    return true;
}