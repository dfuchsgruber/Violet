#include "types.h"
#include "battle/state.h"
#include "battle/battler.h"
#include "battle/battle_string.h"
#include "constants/item_hold_effects.h"
#include "item/item.h"
#include "battle/attack.h"
#include "constants/attack_results.h"
#include "attack.h"
#include "constants/pokemon_types.h"
#include "debug.h"
#include "battle/controller.h"
#include "item/item_effect.h"
#include "constants/item_weather_rock_types.h"
#include "constants/battle/battle_weathers.h"
#include "constants/battle/battle_animations.h"
#include "battle/weather.h"
#include "prng.h"
#include "battle/ai.h"

extern u8 bsc_life_orb[];
extern u8 bsc_sun_egg[];
extern u8 bsc_storm_egg[];
extern u8 bsc_desert_egg[];
extern u8 bsc_blizzard_egg[];
extern u8 bsc_energiequarz[];

u8 battle_items_switch_in_effects(u8 battler_idx) { // Return 0 if no effect was used, 0xFF if an effect was used, but no bsc was triggered and a suitable effect type else
    u8 hold_effect = item_get_hold_effect(bsc_last_used_item);
    u8 hold_effect_parameter = item_get_hold_effect_parameter(bsc_last_used_item);
    dprintf("Item switch in effect, hold effect %d with parameter %d\n", hold_effect, hold_effect_parameter);
    switch(hold_effect) {
        case HOLD_EFFECT_FOUR_LEAF:
            BATTLE_STATE2->item_dropping_chance_increased_by_item = 1;
            return 0xFF;
        case HOLD_EFFECT_WEATHER_EGG: {
            if (hold_effect_parameter == WEATHER_ROCK_HAIL && !(battle_weather & BATTLE_WEATHER_HAIL)) {
                battle_weather = BATTLE_WEATHER_HAIL;
                battler_timers.weather_turns = 2;
                battle_scripting.battler_idx = battler_idx;
                bsc_last_used_item = battlers[battler_idx].item;
                active_battler = battler_idx;
                battlescript_init_and_interrupt_battle(bsc_blizzard_egg);
                return true;
            } else if (hold_effect_parameter == WEATHER_ROCK_SUN && !(battle_weather & BATTLE_WEATHER_SUN)) {
                battle_weather = BATTLE_WEATHER_SUN;
                battler_timers.weather_turns = 2;
                battle_scripting.battler_idx = battler_idx;
                bsc_last_used_item = battlers[battler_idx].item;
                active_battler = battler_idx;
                battlescript_init_and_interrupt_battle(bsc_sun_egg);
                return true;
            } else if (hold_effect_parameter == WEATHER_ROCK_RAIN && !(battle_weather & BATTLE_WEATHER_RAIN)) {
                battle_weather = BATTLE_WEATHER_RAIN;
                battler_timers.weather_turns = 2;
                battle_scripting.battler_idx = battler_idx;
                bsc_last_used_item = battlers[battler_idx].item;
                active_battler = battler_idx;
                battlescript_init_and_interrupt_battle(bsc_storm_egg);
                return true;
            } else if (hold_effect_parameter == WEATHER_ROCK_SANDSTORM && !(battle_weather & BATTLE_WEATHER_SANDSTORM)) {
                battle_weather = BATTLE_WEATHER_SANDSTORM;
                battler_timers.weather_turns = 2;
                battle_scripting.battler_idx = battler_idx;
                bsc_last_used_item = battlers[battler_idx].item;
                active_battler = battler_idx;
                battlescript_init_and_interrupt_battle(bsc_desert_egg);
                return true;
            }
            break;
        }
        case HOLD_EFFECT_ENERGY_QUARZ: {
            // Determine any stat that can be raised
            u8 stats[STAT_EVASION - STAT_ATTACK + 1] = {0};
            size_t num_stats = 0;
            for (u8 i = STAT_ATTACK; i <= STAT_EVASION; i++) {
                if (battlers[battler_idx].stat_changes[i] < 12) {
                    stats[num_stats++] = i;
                }
            }
            if (num_stats > 0) {
                u8 stat = stats[rnd16() % num_stats];
                dprintf("Randomly raise stat %d\n", stat);
                SET_STATCHANGE(stat, 1, false);
                battle_scripting.animation_arguments[0] = (u8)(0x21 + stat + 5);
                battle_scripting.animation_arguments[1] = 0;
                effect_battler = battler_idx;
                battle_scripting.battler_idx = battler_idx;
                BSC_BUFFER_STAT(bsc_string_buffer0, stat);
                battlescript_init_and_interrupt_battle(bsc_energiequarz);
                return true;
            }
            break;
        }
    }
    return 0;
}

bool battle_items_attack_done_new() {
    return false;
}

bool battle_items_life_orb() {
    battler *attacker = battlers + attacking_battler;
    bsc_last_used_item = attacker->item;
    switch(item_get_hold_effect(attacker->item)) {
        case HOLD_EFFECT_LIFE_ORB: {
            if (attacker->current_hp &&
            !(attack_result & ATTACK_NO_EFFECT_ANY) && attacks[active_attack].base_power &&
            !battler_statuses[attacking_battler].hurt_in_confusion && DAMAGE_CAUSED){
                damage_to_apply = MAX(1, attacker->max_hp / item_get_hold_effect_parameter(attacker->item));
                battle_scripting.battler_idx = attacking_battler;
                battle_scripting.animation_user = attacking_battler;
                battle_scripting.animation_targets = attacking_battler;
                battlescript_callstack_push_next_command();
                bsc_offset = bsc_life_orb;
                return true;
            }
            break;
        }
    }
    return false;
}

bool battle_items_attack_done_defender() {
    return false;
}

extern u8 bsc_gunpowder[];

bool battle_items_gunpowder() {
    switch (item_get_hold_effect(battlers[defending_battler].item)) {
        case HOLD_EFFECT_GUN_POWDER: {
            if (attacks[active_attack].type == TYPE_FEUER && battlers[defending_battler].current_hp > 0 &&
            !(attack_result & ATTACK_NO_EFFECT_ANY) && attacks[active_attack].base_power &&
            !battler_statuses[attacking_battler].hurt_in_confusion && DAMAGE_CAUSED) {
                damage_to_apply = battlers[defending_battler].current_hp;
                battle_scripting.battler_idx = defending_battler;
                battle_scripting.animation_user = defending_battler;
                battle_scripting.animation_targets = defending_battler;
                bsc_last_used_item = battlers[defending_battler].item;
                battlescript_callstack_push_next_command();
                bsc_offset = bsc_gunpowder;
                return true;
            }
            break;
        }
    }
    return false;
}

bool battle_item_before_attack_attacker() {
    active_battler = attacking_battler;
    switch (item_get_hold_effect(battlers[attacking_battler].item)) {
        case HOLD_EFFECT_GEM: {
            u8 move_type;
            GET_MOVE_TYPE(active_attack, move_type);
            if (move_type == item_get_hold_effect_parameter(battlers[attacking_battler].item) &&
                attacks[active_attack].base_power > 0) {
                BATTLE_STATE2->status_custom[attacking_battler] |= CUSTOM_STATUS_GEM_USED;
                dprintf("Triggered gem in custom status.\n");
            }
            break; // Didn't trigger a battle script, that is done by command 0x7 (i.e. the hook at its end) (this takes care of multi-turn moves)
        }
    }
    return false;
}

extern u8 battlescript_battle_item_hold_effect_restore_hp[];

bool battle_item_restore_hp(u8 battler_idx, u8 move_turn, int hold_effect_parameter) {
    if (battlers[battler_idx].current_hp <= battlers[battler_idx].max_hp / 2 && !move_turn) {
        switch (hold_effect_parameter) {
            case ITEM_EFFECT_HEAL_HP_ALL:
                hold_effect_parameter = battlers[battler_idx].max_hp;
                break;
            case ITEM_EFFECT_HEAL_HP_HALF:
                hold_effect_parameter = battlers[battler_idx].max_hp / 2;
                break;
            case ITEM_EFFECT_HEAL_HP_QUARTER:
                hold_effect_parameter = battlers[battler_idx].max_hp / 4;
                break;
            case ITEM_EFFECT_HEAL_HP_EIGHTH:
                hold_effect_parameter = battlers[battler_idx].max_hp / 8;
                break;
        }
        damage_to_apply = hold_effect_parameter;
        if (battlers[battler_idx].current_hp + damage_to_apply > battlers[battler_idx].max_hp) {
            damage_to_apply = battlers[battler_idx].max_hp - battlers[battler_idx].current_hp;
        }
        damage_to_apply *= -1;
        battlescript_init_and_push_current_callback(battlescript_battle_item_hold_effect_restore_hp);
        return true;
    }
    return false;
}


bool battle_item_before_attack_defender() {
    active_battler = defending_battler;
    switch (item_get_hold_effect(battlers[defending_battler].item)) {
        case HOLD_EFFECT_TYPE_BERRY: {
            u8 move_type;
            GET_MOVE_TYPE(active_attack, move_type);
            // printf("Checking berry for move type %d, defending item %d, param %d\n", move_type, battlers[defending_battler].item, item_get_hold_effect_parameter(battlers[defending_battler].item));
            // dprintf("Active attack %d, attack_result %d\n", active_attack, attack_result);
            u8 multiplier = 16;
            battle_ai_attack_apply_effectiveness_multiplier_with_abilities(move_type, battlers[defending_battler].ability,
                battlers[defending_battler].type1, battlers[defending_battler].type2, &multiplier);
            if (move_type == item_get_hold_effect_parameter(battlers[defending_battler].item) &&
                attacks[active_attack].base_power > 0 && multiplier > 16) {
                BATTLE_STATE2->status_custom[attacking_battler] |= CUSTOM_STATUS_ATTACK_WEAKENED_BY_BERRY;
                // dprintf("Defender %d protected by berry.\n", defending_battler);
            }
            break; // Didn't trigger a battle script, that is done by command 0x7 (i.e. the hook at its end) (this takes care of multi-turn moves)
        }
    }
    return false;
}