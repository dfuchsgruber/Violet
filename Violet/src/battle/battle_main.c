#include "types.h"
#include "battle/state.h"
#include "save.h"
#include "mega.h"
#include "agbmemory.h"
#include "battle/controller.h"
#include "debug.h"
#include "battle/bg.h"
#include "battle/battlescript.h"
#include "constants/items.h"
#include "constants/item_effect_types.h"
#include "item/item_effect.h"
#include "item/item.h"
#include "battle/communication.h"
#include "battle/battle_string.h"
#include "constants/pokemon_stat_names.h"
#include "pokemon/virtual.h"
#include "overworld/pokemon_party_menu.h"
#include "overworld/map_control.h"
#include "superstate.h"
#include "fading.h"
#include "trainer/trainer.h"
#include "constants/item_hold_effects.h"
#include "constants/abilities.h"
#include "constants/pokemon_types.h"
#include "abilities.h"
#include "constants/item_pockets.h"


void battle_intro_draw_pokemon_or_trainer_sprite_draw_second_trainer() {
    if ((battle_flags & BATTLE_TWO_TRAINERS) && battler_get_position(active_battler) == BATTLE_POSITION_OPPONENT_RIGHT) {
        battle_controller_emit_draw_trainer_picture(0);
        battler_mark_for_controller_execution(active_battler);
    }
    if ((battle_flags & BATTLE_ALLY) && battler_get_position(active_battler) == BATTLE_POSITION_PLAYER_RIGHT) {
        battle_controller_emit_draw_trainer_picture(0);
        battler_mark_for_controller_execution(active_battler);
    }
}

void battle_intro_try_second_trainer_ball_throw() {
    if (battle_flags & (BATTLE_MULTI | BATTLE_TWO_TRAINERS) && 
            battler_get_position(active_battler) == BATTLE_POSITION_OPPONENT_RIGHT) {
        dprintf("Add second ball throw \n");
        battle_controller_emit_intro_trainer_ball_throw(0);
        battler_mark_for_controller_execution(active_battler);
    }
}

void battle_intro_try_partner_ball_throw() {
    if ((battle_flags & (BATTLE_MULTI | BATTLE_ALLY)) && 
            battler_get_position(active_battler) == BATTLE_POSITION_PLAYER_RIGHT) {
        dprintf("Add partner ball throw \n");
        battle_controller_emit_intro_trainer_ball_throw(0);
        battler_mark_for_controller_execution(active_battler);
    }
}

void battle_action_use_item() {
    attacking_battler = defending_battler = battler_attacking_order[battle_action_current_turn];
    battle_bg0_x = 0;
    battle_bg0_y = 0;
    battler_remove_fury_cutter_destiny_bond_grudge(attacking_battler);
    bsc_last_used_item = UNALIGNED_16_GET(battle_general_buffers1[attacking_battler] + 1);
    dprintf("Used item is %d\n", bsc_last_used_item);
    if (bsc_last_used_item <= ITEM_PREMIERBALL) {
        bsc_offset = battlescripts_pokeball[bsc_last_used_item];
    } else if (bsc_last_used_item == ITEM_POKEPUPPE || bsc_last_used_item == ITEM_ENECO_RUTE) {
        bsc_offset = battlescripts_run_by_item[0];
    } else if (bsc_last_used_item == ITEM_POKEFLOETE) {
        bsc_offset = battlescripts_run_by_item[1];
    } else if (battler_get_owner(attacking_battler) == OWNER_PLAYER) {
        bsc_offset = battlescripts_use_item[0];
    } else { // AI used item, set-up proper battlescript
        item_effect_t *effect = item_effects[bsc_last_used_item - ITEM_TRANK];
        u8 first = 0, last = 0;
        pokemon *p = battler_load_party_range(attacking_battler, &first, &last) + battler_idx_to_party_idx(attacking_battler);
        if (bsc_last_used_item == ITEM_TOP_GENESUNG) {
            bsc_offset = battlescripts_use_item[1];
        } else {
            dprintf("Item has effect %d\n", item_get_effect_type(bsc_last_used_item));
            switch (item_get_effect_type(bsc_last_used_item)) {
                case ITEM_EFFECT_HEAL_HP:
                    bsc_offset = battlescripts_use_item[2];
                    break; 
                case ITEM_EFFECT_HEAL_BURN:
                case ITEM_EFFECT_HEAL_FREEZE:
                case ITEM_EFFECT_HEAL_POISON:
                case ITEM_EFFECT_HEAL_PARALYSIS:
                case ITEM_EFFECT_HEAL_SLEEP:
                case ITEM_EFFECT_HEAL_ALL_STATUS:
                    item_effect_execute_status_heals(p, bsc_last_used_item, attacking_battler, 4, 
                        battler_idx_to_party_idx(attacking_battler), item_get_hold_effect(bsc_last_used_item), effect, false, false);
                    bsc_offset = battlescripts_use_item[3];
                    break;
                case ITEM_EFFECT_HEAL_INFATUATION:
                case ITEM_EFFECT_HEAL_CONFUSION:
                    item_effect_execute_battle_effects(p, bsc_last_used_item, attacking_battler, 4, 
                        battler_idx_to_party_idx(attacking_battler), item_get_hold_effect(bsc_last_used_item), effect, false, false);
                    bsc_offset = battlescripts_use_item[3];
                    break;
                case ITEM_EFFECT_X_ITEM:
                    battle_scripting.battler_idx = attacking_battler;
                    item_effect_execute_battle_effects(p, bsc_last_used_item, attacking_battler, 4, 
                        battler_idx_to_party_idx(attacking_battler), item_get_hold_effect(bsc_last_used_item), effect, false, false);
                    battle_communication[BATTLE_COMMUNICATION_MULTISTRING_CHOOSER] = 4;
                    bsc_offset = battlescripts_use_item[4];
                    if (effect->increase_critical_ratio) {
                        battle_communication[BATTLE_COMMUNICATION_MULTISTRING_CHOOSER] = 5;
                    } else if (effect->creates_mist) {
                        battle_communication[BATTLE_COMMUNICATION_MULTISTRING_CHOOSER] = battle_flags & BATTLE_DOUBLE ? 2 : 0;
                        bsc_offset = battlescripts_use_item[5];
                    } else if (effect->x_attack) {
                        BSC_BUFFER_STAT(bsc_string_buffer0, STAT_ATTACK);
                        BSC_BUFFER_STRING(bsc_string_buffer1, 0xD2);
                    } else if (effect->x_defense) {
                        BSC_BUFFER_STAT(bsc_string_buffer0, STAT_DEFENSE);
                        BSC_BUFFER_STRING(bsc_string_buffer1, 0xD2);
                    } else if (effect->x_accuracy) {
                        BSC_BUFFER_STAT(bsc_string_buffer0, STAT_ACCURACY);
                        BSC_BUFFER_STRING(bsc_string_buffer1, 0xD2);
                    } else if (effect->x_speed) {
                        BSC_BUFFER_STAT(bsc_string_buffer0, STAT_SPEED);
                        BSC_BUFFER_STRING(bsc_string_buffer1, 0xD2);
                    } else if (effect->x_special_attack) {
                        BSC_BUFFER_STAT(bsc_string_buffer0, STAT_SPECIAL_ATTACK);
                        BSC_BUFFER_STRING(bsc_string_buffer1, 0xD2);
                    }
                    break;
            }
        }
    }
    battle_action = BATTLE_ACTION_EXECUTE_SCRIPT;
}

extern u8 battlescript_introduce_aggresive_battler[];

void battle_aggresive_battlers_introduce() {
    if (battle_flags & BATTLE_AGGRESSIVE_WILD) {
        while (BATTLE_STATE2->aggresive_battler_idx < battler_cnt) {
            active_battler = BATTLE_STATE2->aggresive_battler_idx;
            BATTLE_STATE2->aggresive_battler_idx++;
            if (battler_is_opponent(active_battler)) {
                attacking_battler = defending_battler = battle_scripting.battler_idx = active_battler;
                battlescript_init_and_interrupt_battle(battlescript_introduce_aggresive_battler);
                return;
            }
        }
    }
    battle_main_callback = battle_events_before_first_turn;
}

// Wrapper that clears the selected switching targets for battlers (so that they are not forced to switch into what was previously chosen)
void battle_action_turn_finished_wrapper() {
    battle_state->battler_to_switch_into[battler_attacking_order[battle_action_current_turn]] = 6;
    battle_action_turn_finished();
}

void battle_callback_partner_party_preview() {
    generic_callback1();
    switch (battle_communication[BATTLE_COMMUNICATION_MULTIUSE]) {
        case 0: {
            battle_state->saved_callback = super.saved_callback; // Backup for the saved callback...
            BATTLE_STATE2->saved_battle_flags = battle_flags;
            super.saved_callback = battle_callback_partner_party_preview; // Return to this callback once the preview is done
            pokemon_party_menu_load_partner_party(player_pokemon + 3);
            pokemon_party_menu_init(PARTY_MENU_TYPE_MULTI_SHOWCASE, PARTY_LAYOUT_MULTI_SHOWCASE, PARTY_ACTION_CHOOSE_MON, 0, 
                PARTY_MSG_NONE, pokemon_party_menu_partner_party_slide_in_initialize, super.saved_callback);
            battle_communication[BATTLE_COMMUNICATION_MULTIUSE]++;
            break;
        }
        case 1: {
            if (!fading_control.active) {
                battle_flags = BATTLE_STATE2->saved_battle_flags;
                super.saved_callback = battle_state->saved_callback;
                super.callback1 = battle_graphics_initialize;
                battle_communication[BATTLE_COMMUNICATION_MULTIUSE]++;
            }
            break;
        }
    }
}

void battle_initialize_graphics_or_preview() {
    if (battle_is_tag() && fmem.ally_trainer_party_preview) {
        battle_communication[BATTLE_COMMUNICATION_MULTIUSE] = 0;
        callback1_set(battle_callback_partner_party_preview);
    } else {
        battle_graphics_initialize();
    }
}

void battle_ally_save_and_setup_party() {
    for (int i = 0; i < 3; i++)
        cmem.ally_battle_selected_party_idxs[i] = player_party_selected_idxs[i];
    player_save_party();
    player_party_reduce_to_selection();
    ally_party_setup();
    player_pokemon_recount_pokemon();
}

bool battle_has_two_players() {
    return battle_is_tag() || battle_is_multi_double();
}

bool battle_has_two_opponents() {
    return (battle_flags & (BATTLE_TWO_TRAINERS | BATTLE_MULTI)) > 0;
}

bool battle_controller_double_battle_should_send_out_only_one_pokemon() {
    if (battle_has_two_opponents()) return true; // Each battler has their own controller, that only sends out one mon
    return false;
}

void battle_clear_temporary_custom_effects(bool clear_all){
    if(clear_all){
        int i;
        for(i = 0; i < battler_cnt; i++){
            BATTLE_STATE2->status_custom[i] = 0;
        }
    }
}

extern u8 battlescript_before_attack[];

void battle_before_attack_effects() {
    BATTLE_STATE2->status_custom[attacking_battler] = 0;
    battlescript_callstack_push_next_command();
    BATTLE_STATE2->before_attack_state = 0;
    bsc_offset = battlescript_before_attack; // This script executes all effects before the battle...
}

bool battle_end_turn_effects() {
    // During any end of turn effect, a battler controlled by the ai may faint
    // Therefore, we have to allow the ai to choose a new switch in target in any step
    for (int i = 0; i < 4; i++)
        battle_state->battler_to_switch_into[i] = 6;
    if (battle_end_turn_field_effects()) return true;
    if (battle_handicap_end_turn_effects()) return true;
    if (battle_end_turn_battler_effects()) return true;
    return false;
}

void battle_end_turn_handle_battle_continues_wrapper() {
    if (!battler_marked_for_controller_execution) {
        battle_end_turn_handle_battle_continues();
        BATTLE_STATE2->end_of_turn_handicap_effects_cnt = 0;
    }
}

u8 battle_is_running_impossible() {
    if (BATTLE_IS_WILD_DOUBLE && battler_get_position(active_battler) == BATTLE_POSITION_PLAYER_RIGHT
        &&battler_is_alive(battler_get_by_position(BATTLE_POSITION_PLAYER_LEFT))) { // The right mon can only run if it is "alone"
        // Reason: We don't want the left mon to pick an action and then run with the right mon
        battle_communication[BATTLE_COMMUNICATION_MULTISTRING_CHOOSER] = 0;
        return 1;
    }
    u8 hold_effect = item_get_hold_effect(battlers[active_battler].item);
    if (battlers[active_battler].item == ITEM_ENIGMABEERE)
        hold_effect = enigma_berries[active_battler].hold_effect;
    item_target_battler = active_battler;
    if (hold_effect == HOLD_EFFECT_CAN_ALWAYS_RUN || (battle_flags & BATTLE_LINK) ||
        battlers[active_battler].ability == ANGSTHASE)
        return 0;
    u8 side = battler_is_opponent(active_battler);
    for (u8 i = 0; i < battler_cnt; i++) {
        if (side != battler_is_opponent(i) && battlers[i].ability == WEGSPERRE) {
            battle_scripting.battler_idx = i;
            defending_battler_ability = battlers[i].ability;
            battle_communication[BATTLE_COMMUNICATION_MULTISTRING_CHOOSER] = 2;
            return 2;
        }
        if (side != battler_is_opponent(i) && battlers[i].ability == AUSWEGSLOS
        && battlers[active_battler].ability != SCHWEBE && battlers[active_battler].type1 != TYPE_FLUG
        && battlers[active_battler].type2 != TYPE_FLUG) {
            battle_scripting.battler_idx = i;
            defending_battler_ability = battlers[i].ability;
            battle_communication[BATTLE_COMMUNICATION_MULTISTRING_CHOOSER] = 2;
            return 2;
        }
    }
    u8 i = ability_execute(ABILITY_CONTEXT_CHECK_FIELD_EXCEPT_CURRENT, active_battler, MAGNETFALLE, 0, 0);
    if (i != 0 && (battlers[active_battler].type1 == TYPE_STAHL || battlers[active_battler].type2 == TYPE_STAHL)) {
        battle_scripting.battler_idx = --i;
        defending_battler_ability = battlers[i].ability;
        battle_communication[BATTLE_COMMUNICATION_MULTISTRING_CHOOSER] = 2;
        return 2;
    }
    if (battlers[active_battler].status2 & (STATUS2_ESCAPE_PREVENTATION | STATUS2_WRAPPED) || 
        (battler_statuses3[active_battler] & STATUS3_ROOTED)) {
        battle_communication[BATTLE_COMMUNICATION_MULTISTRING_CHOOSER] = 0;
        return 1;
    }
    if ((battle_flags & (BATTLE_AGGRESSIVE_WILD)) && !battler_is_opponent(active_battler)) {
        battle_communication[BATTLE_COMMUNICATION_MULTISTRING_CHOOSER] = 0;
        return 1;
    }
    return 0;
}

void battle_wild_pokemon_sprite_fade_palettes(oam_object *oam, bool back) {
    u8 battler_idx = (u8)oam->private[0];
    int affects = 1 << (battler_idx + 16);
    if (BATTLE_IS_WILD_DOUBLE) {
        affects |= 1 << (PARTNER(battler_idx) + 16);
    }
    color_t c = {.rgb = {.red = 8, .green = 8, .blue = 8}};
    dprintf("Fading with affects 0x%x, rgb 0x%x\n", affects, c.value);
    fadescreen((u32)affects, 0, 10, back ? 0 : 10, c.value);
}

void battle_wild_pokemon_oam_callback(oam_object *self) {
    self->callback = battle_wild_pokemon_oam_callback_move_to_right;
    oam_gfx_anim_start_if_not_current(self, 0);
    battle_wild_pokemon_sprite_fade_palettes(self, false);
}

bool battle_handle_turn_selection_actions_are_prevented() {
    if (BATTLE_IS_WILD_DOUBLE && battler_get_position(active_battler) == BATTLE_POSITION_PLAYER_RIGHT &&
        (battler_action_chosen[battler_get_by_position(BATTLE_POSITION_PLAYER_LEFT)] == BATTLE_ACTION_RUN || BATTLE_STATE2->throwing_pokeball)) {
        // In a wild double battle, the right mon may not move if the left mon is running or throwing a pokeball
        dprintf("Battler at position %d can't do any action.\n", battler_get_position(active_battler));
        dprintf("Marked for pokeball throw %d\n", BATTLE_STATE2->throwing_pokeball);
        if (BATTLE_STATE2->throwing_pokeball)
            BATTLE_STATE2->throwing_pokeball = false;
        battler_action_chosen[active_battler] = BATTLE_ACTION_NOTHING_FAINTED;
        battle_communication[active_battler] = 3;
        return true;
    }
    return false;
}

void battle_handle_selection_actions_item_selected() {
    u16 item = UNALIGNED_16_GET(&battle_general_buffers1[active_battler][1]);
    if (item != 0) {
        item_activated = item;
        if (item_get_pocket(item_activated) == POCKET_POKEBALLS) {
            BATTLE_STATE2->throwing_pokeball = true; // Mark that this battler is throwing a pokéball, i.e. the right battler musn't do any action
            dprintf("Battler at position %d marked for pokeball throw.\n", battler_get_position(active_battler));
        }
        battle_communication[active_battler]++;
    } else {
        battle_communication[active_battler] = 0; // Re-select an action
    }
}