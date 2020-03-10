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

void battle_intro_draw_pokemon_or_trainer_sprite_draw_second_trainer() {
    if ((battle_flags & BATTLE_TWO_TRAINERS) && active_battler == BATTLE_POSITION_OPPONENT_RIGHT) {
        battle_controller_emit_draw_trainer_picture(0);
        battler_mark_for_controller_execution(active_battler);
    }
    // TODO: Ally battles
}

void battle_intro_try_second_trainer_ball_throw() {
    if (battle_flags & (BATTLE_MULTI | BATTLE_TWO_TRAINERS) && 
            battler_get_position(active_battler) == BATTLE_POSITION_OPPONENT_RIGHT) {
        dprintf("Add second ball throw \n");
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

// Wrapper that clears the selected switching targets for battlers (so that they are not forced to switch into what was previously chosen)
void battle_action_turn_finished_wrapper() {
    battle_state->battler_to_switch_into[battler_attacking_order[battle_action_current_turn]] = 6;
    battle_action_turn_finished();
}