/*
 * priority.c
 *
 *  Created on: Feb 22, 2019
 *      Author: dominik
 */
#include "attack.h"
#include "battle/attack.h"
#include "battle/battler.h"
#include "battle/state.h"
#include "battle/weather.h"
#include "constants/attack_categories.h"
#include "constants/attacks.h"
#include "constants/battle/battle_actions.h"
#include "constants/item_hold_effects.h"
#include "constants/items.h"
#include "constants/pokemon_stat_names.h"
#include "constants/pokemon_types.h"
#include "item/custom.h"
#include "item/item.h"
#include "prng.h"
#include "types.h"

int battler_get_effective_speed(u8 battler_idx) {
    u8 speed_multiplier = 1;
    if (WEATHER_HAS_EFFECT) {
        if ((battlers[battler_idx].ability == WASSERTEMPO && (battle_weather & BATTLE_WEATHER_HAIL_ANY)) ||
            (battlers[battler_idx].ability == CHLOROPHYLL &&
             (battle_weather & BATTLE_WEATHER_SUN_ANY))) {
            speed_multiplier = 2;
        }
    }
    int speed = STAT_CHANGE_APPLY_MULTIPLIER(
        battlers[battler_idx].stats[STAT_SPEED - 1] * speed_multiplier, STAT_SPEED);
    // Get item based effects
    u16 item_idx = battlers[battler_idx].item;
    u8 hold_effect = items[item_idx].holding_effect_id;
    u8 hold_effect_param = items[item_idx].holding_effect_param;
    if (item_idx == ITEM_ENIGMABEERE) {
        hold_effect = enigma_berries[battler_idx].hold_effect;
        hold_effect_param = enigma_berries[battler_idx].hold_effect_parameter;
    }
    if (hold_effect == HOLD_EFFECT_MACHO_BRACE)
        speed /= 2;
    if (battlers[battler_idx].status1 & STATUS1_PARALYZED)
        speed /= 4;
    if (hold_effect == HOLD_EFFECT_QUICK_CLAW &&
        battle_current_turn_seed < (0xFFFF * hold_effect_param / 100))
        speed = INT_MAX;
    if (hold_effect == HOLD_EFFECT_CHOICE_ITEM && hold_effect_param == CHOICE_ITEM_SCARF)
        speed += speed / 2;
    return speed;
}

s8 battle_attack_priority_get(u16 attack, u8 battler_idx) {
    s8 priority = attacks[attack].priority;
    switch (battlers[battler_idx].ability) {
        case ORKANSCHW:
            if (attacks[attack].type == TYPE_FLUG)
                priority++;
            break;
        case DUNKLE_MAGIE:
            if (attacks[attack].type == TYPE_UNLICHT)
                priority++;
            break;
        case STROLCH:
            if (attacks[attack].category == CATEGORY_STATUS)
                priority++;
            break;
        case FRUEHZUENDER:
            if (attack == ATTACK_FINALE || attack == ATTACK_EXPLOSION)
                priority++;
            break;
        case ZEITSPIEL:
            priority--;
            break;
    }
    return priority;
}

u8 priority_compare(u8 first_battler, u8 second_battler, bool ignore_moves) {
    int speed_first = battler_get_effective_speed(first_battler);
    int speed_second = battler_get_effective_speed(second_battler);

    u16 move_first = ATTACK_NONE;
    if (battler_action_chosen[first_battler] == BATTLE_ACTION_USE_MOVE && !ignore_moves) {
        if (battler_statuses[first_battler].out_of_moves)
            move_first = ATTACK_VERZWEIFLER;
        else {
            u8 slot = battle_state->chosen_move_slots[first_battler];
            move_first = battlers[first_battler].moves[slot];
        }
    }
    u16 move_second = ATTACK_NONE;
    if (battler_action_chosen[second_battler] == BATTLE_ACTION_USE_MOVE && !ignore_moves) {
        if (battler_statuses[second_battler].out_of_moves)
            move_second = ATTACK_VERZWEIFLER;
        else {
            u8 slot = battle_state->chosen_move_slots[second_battler];
            move_second = battlers[second_battler].moves[slot];
        }
    }
    // Get attack priorites
    s8 priority_first = battle_attack_priority_get(move_first, first_battler);
    s8 priority_second = battle_attack_priority_get(move_second, second_battler);

    if (priority_first != 0 || priority_second != 0) {
        if (priority_first == priority_second) {
            if (speed_first == speed_second && (rnd16() & 1)) { // Speed tie
                return 2;                                       // Won by battler ?
            } else if (speed_first < speed_second) {
                return 1; // battler_second is first
            } else {
                return 0; // battler_first is first
            }
        } else {
            // Battler with higher priority is first
            if (priority_first < priority_second) {
                return 1; // battler_second is first
            } else {
                return 0; // battler_first is first
            }
        }
    } else {
        // Prio 0 moves (both want to attack last, this results in a speed tie)
        if (speed_first == speed_second && (rnd16() & 1)) {
            return 2; // Won by battler ?
        } else if (speed_first < speed_second) {
            return 1; // battler_second is first
        } else {
            return 0; // battler_first is first
        }
    }
}
