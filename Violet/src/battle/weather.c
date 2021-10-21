/*
 * weather.c
 *
 *  Created on: Feb 16, 2019
 *      Author: dominik
 */
#include "battle/weather.h"
#include "battle/attack.h"
#include "battle/battler.h"
#include "battle/battlescript.h"
#include "battle/communication.h"
#include "battle/state.h"
#include "constants/attack_results.h"
#include "constants/battle/battle_weathers.h"
#include "constants/item_hold_effects.h"
#include "constants/item_weather_rock_types.h"
#include "constants/items.h"
#include "debug.h"
#include "item/item.h"
#include "types.h"

void bsc_cmd_xBB_setsunny() {
    if ((battle_weather & BATTLE_WEATHER_SUN) || (battle_weather & BATTLE_WEATHER_SUN_DROUGHT)) {
        attack_result |= ATTACK_MISSED;
        battle_communication[BATTLE_COMMUNICATION_MULTISTRING_CHOOSER] = 2;
    } else {
        battle_weather = BATTLE_WEATHER_SUN;
        battle_communication[BATTLE_COMMUNICATION_MULTISTRING_CHOOSER] = 4;
        u16 item = battlers[attacking_battler].item;
        u8 hold_effect = item_get_hold_effect(item);
        u8 hold_effect_parameter = item_get_hold_effect_parameter(item);
        if (item == ITEM_ENIGMABEERE) {
            hold_effect = enigma_berries[attacking_battler].hold_effect;
            hold_effect_parameter = enigma_berries[attacking_battler].hold_effect_parameter;
        }
        if (hold_effect == HOLD_EFFECT_WEATHER_ROCK && hold_effect_parameter == WEATHER_ROCK_SUN)
            battler_timers.weather_turns = 8;
        else
            battler_timers.weather_turns = 5;
    }
    bsc_offset++;
}

void bsc_cmd_x7D_setrain() {
    if ((battle_weather & BATTLE_WEATHER_RAIN) || (battle_weather & BATTLE_WEATHER_RAIN_DRIZZLE)) {
        attack_result |= ATTACK_MISSED;
        battle_communication[BATTLE_COMMUNICATION_MULTISTRING_CHOOSER] = 2;
    } else {
        battle_weather = BATTLE_WEATHER_RAIN;
        battle_communication[BATTLE_COMMUNICATION_MULTISTRING_CHOOSER] = 0;
        u16 item = battlers[attacking_battler].item;
        u8 hold_effect = item_get_hold_effect(item);
        u8 hold_effect_parameter = item_get_hold_effect_parameter(item);
        if (item == ITEM_ENIGMABEERE) {
            hold_effect = enigma_berries[attacking_battler].hold_effect;
            hold_effect_parameter = enigma_berries[attacking_battler].hold_effect_parameter;
        }
        if (hold_effect == HOLD_EFFECT_WEATHER_ROCK && hold_effect_parameter == WEATHER_ROCK_RAIN)
            battler_timers.weather_turns = 8;
        else
            battler_timers.weather_turns = 5;
    }
    bsc_offset++;
}

void bsc_cmd_x95_setsandstorm() {
    if ((battle_weather & BATTLE_WEATHER_SANDSTORM) ||
        (battle_weather & BATTLE_WEATHER_SANDSTORM_ABILITY)) {
        attack_result |= ATTACK_MISSED;
        battle_communication[BATTLE_COMMUNICATION_MULTISTRING_CHOOSER] = 2;
    } else {
        battle_weather = BATTLE_WEATHER_SANDSTORM;
        battle_communication[BATTLE_COMMUNICATION_MULTISTRING_CHOOSER] = 3;
        u16 item = battlers[attacking_battler].item;
        u8 hold_effect = item_get_hold_effect(item);
        u8 hold_effect_parameter = item_get_hold_effect_parameter(item);
        if (item == ITEM_ENIGMABEERE) {
            hold_effect = enigma_berries[attacking_battler].hold_effect;
            hold_effect_parameter = enigma_berries[attacking_battler].hold_effect_parameter;
        }
        if (hold_effect == HOLD_EFFECT_WEATHER_ROCK &&
            hold_effect_parameter == WEATHER_ROCK_SANDSTORM)
            battler_timers.weather_turns = 8;
        else
            battler_timers.weather_turns = 5;
    }
    bsc_offset++;
}

void bsc_cmd_xC8_sethail() {
    if ((battle_weather & BATTLE_WEATHER_HAIL)) {
        attack_result |= ATTACK_MISSED;
        battle_communication[BATTLE_COMMUNICATION_MULTISTRING_CHOOSER] = 2;
    } else {
        battle_weather = BATTLE_WEATHER_HAIL;
        battle_communication[BATTLE_COMMUNICATION_MULTISTRING_CHOOSER] = 5;
        u16 item = battlers[attacking_battler].item;
        u8 hold_effect = item_get_hold_effect(item);
        u8 hold_effect_parameter = item_get_hold_effect_parameter(item);
        if (item == ITEM_ENIGMABEERE) {
            hold_effect = enigma_berries[attacking_battler].hold_effect;
            hold_effect_parameter = enigma_berries[attacking_battler].hold_effect_parameter;
        }
        if (hold_effect == HOLD_EFFECT_WEATHER_ROCK &&
            hold_effect_parameter == WEATHER_ROCK_HAIL)
            battler_timers.weather_turns = 8;
        else
            battler_timers.weather_turns = 5;
    }
    bsc_offset++;
}
