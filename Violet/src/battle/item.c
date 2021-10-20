#include "types.h"
#include "battle/state.h"
#include "battle/battler.h"
#include "battle/battle_string.h"
#include "constants/item_hold_effects.h"
#include "constants/attack_flags.h"
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
#include "battle/communication.h"
#include "constants/battle/battle_effects.h"

extern u8 bsc_life_orb[];
extern u8 bsc_sun_egg[];
extern u8 bsc_storm_egg[];
extern u8 bsc_desert_egg[];
extern u8 bsc_blizzard_egg[];
extern u8 bsc_energiequarz[];
extern u8 bsc_beulenhelm[];
extern u8 bsc_weakness_policy[];

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
    u8 hold_effect, hold_effect_param;
    battler_get_hold_item_effect_and_parameter(defending_battler, &hold_effect, &hold_effect_param);
    switch (hold_effect) {
        case HOLD_EFFECT_BEULENHELM: {
            if (battlers[attacking_battler].current_hp > 0 &&
                !(attack_result & ATTACK_NO_EFFECT_ANY) && attacks[active_attack].base_power &&
                !battler_statuses[attacking_battler].hurt_in_confusion && DAMAGE_CAUSED &&
                (attacks[active_attack].flags & MAKES_CONTACT)) {
                    damage_to_apply = MAX(1, battlers[attacking_battler].max_hp / hold_effect_param);
                    battlescript_callstack_push_next_command();
                    battle_scripting.battler_idx = attacking_battler;
                    battle_scripting.animation_user = attacking_battler;
                    battle_scripting.animation_targets = attacking_battler;
                    bsc_last_used_item = battlers[defending_battler].item;
                    battle_record_item_effect(defending_battler, hold_effect);
                    bsc_offset = bsc_beulenhelm;
                    return true;
                }
            break;
        }
        case HOLD_EFFECT_WEAKNESS_POLICY: {
            if (((attack_result & (ATTACK_SUPER_EFFECTIVE | ATTACK_NOT_EFFECTIVE)) == ATTACK_SUPER_EFFECTIVE) &&
                !(attack_result & ATTACK_NO_EFFECT_ANY) && attacks[active_attack].base_power &&
                !battler_statuses[attacking_battler].hurt_in_confusion && DAMAGE_CAUSED && battlers[defending_battler].current_hp > 0 && 
                (battlers[defending_battler].stat_changes[STAT_ATTACK - 1] < 12 || battlers[defending_battler].stat_changes[STAT_SPECIAL_ATTACK - 1] < 12)) {
                effect_battler = defending_battler;
                battle_scripting.battler_idx = defending_battler;
                bsc_last_used_item = battlers[defending_battler].item;
                battlescript_callstack_push_next_command();
                battle_record_item_effect(defending_battler, hold_effect);
                bsc_offset = bsc_weakness_policy;
                return true;
            }
        }
    }
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

u16 battle_item_adjust_accuracy(u16 accuracy) {
    u8 hold_effect, hold_effect_param;
    // defender
    if (battlers[defending_battler].item == ITEM_ENIGMABEERE) {
        hold_effect = enigma_berries[defending_battler].hold_effect;
        hold_effect_param = enigma_berries[defending_battler].hold_effect_parameter;
    } else {
        hold_effect = item_get_hold_effect(battlers[defending_battler].item);
        hold_effect_param = item_get_hold_effect_parameter(battlers[defending_battler].item);
    }
    if (hold_effect == HOLD_EFFECT_EVASION_UP) {
        accuracy = (u16)((accuracy * (100 - hold_effect_param)) / 100);
    }
    // attacker
    if (battlers[attacking_battler].item == ITEM_ENIGMABEERE) {
        hold_effect = enigma_berries[attacking_battler].hold_effect;
        hold_effect_param = enigma_berries[attacking_battler].hold_effect_parameter;
    } else {
        hold_effect = item_get_hold_effect(battlers[attacking_battler].item);
        hold_effect_param = item_get_hold_effect_parameter(battlers[attacking_battler].item);
    }
    if (hold_effect == HOLD_EFFECT_BOOST_ACCURACY) {
        accuracy = (u16)((accuracy * (100 + hold_effect_param)) / 100);
    }
    return accuracy;
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

extern u8 bsc_heal_hp_by_item_end2[];
extern u8 bsc_deal_damage_by_item_end2[];
extern u8 bsc_status_orb[];

int battle_item_effect_after_attack(u8 battler_idx, bool move_turn) {
    u8 hold_effect, hold_effect_param;
    if (battlers[battler_idx].item == ITEM_ENIGMABEERE) {
        hold_effect = enigma_berries[battler_idx].hold_effect;
        hold_effect_param = enigma_berries[battler_idx].hold_effect_parameter;
    } else {
        hold_effect = item_get_hold_effect(battlers[battler_idx].item);
        hold_effect_param = item_get_hold_effect_parameter(battlers[battler_idx].item);
    }
    switch (hold_effect) {
        case HOLD_EFFECT_RECOVERS_HP_AT_END_OF_TURN_FOR_TYPE: {
            if (battlers[battler_idx].current_hp > 0) {
                bool heals = battlers[battler_idx].type1 == hold_effect_param || battlers[battler_idx].type2 == hold_effect_param;
                if ((battlers[battler_idx].current_hp < battlers[battler_idx].max_hp || !heals) && !move_turn) {
                    bsc_last_used_item = battlers[battler_idx].item;
                    battle_record_item_effect(battler_idx, hold_effect);
                    if (heals) {
                        damage_to_apply = -MIN(MAX(1, battlers[battler_idx].max_hp / 16), battlers[battler_idx].max_hp - battlers[battler_idx].current_hp);
                        battlescript_init_and_push_current_callback(bsc_heal_hp_by_item_end2);
                    } else {
                        damage_to_apply  = MAX(1, battlers[battler_idx].max_hp / 8);
                        battlescript_init_and_push_current_callback(bsc_deal_damage_by_item_end2);
                    }
                    return 4; // effect hp changed
                }
            
            }
            break;
        }
        case HOLD_EFFECT_CAUSES_BURN: {
            if (battlers[battler_idx].current_hp > 0 && battlers[battler_idx].type1 != TYPE_FEUER && battlers[battler_idx].type2 != TYPE_FEUER &&
                battlers[battler_idx].ability != AQUAHUELLE && battlers[battler_idx].status1 == 0 && (rnd16() % 100) < hold_effect_param) {
                attacking_battler = battler_idx;
                battle_communication[BATTLE_COMMUNICATION_BATTLE_EFFECT] = 0x40 | BATTLE_EFFECT_FIRE;
                    battle_record_item_effect(battler_idx, hold_effect);
                battlescript_init_and_push_current_callback(bsc_status_orb);
                return 1; // status changed
            }
            break;
        }
        case HOLD_EFFECT_CAUSES_POISON: {
            if (battlers[battler_idx].current_hp > 0 && battlers[battler_idx].type1 != TYPE_GIFT && battlers[battler_idx].type2 != TYPE_GIFT &&
                battlers[battler_idx].type1 != TYPE_STAHL && battlers[battler_idx].type2 != TYPE_STAHL &&
                battlers[battler_idx].ability != IMMUNITAET && battlers[battler_idx].status1 == 0 && (rnd16() % 100) < hold_effect_param) {
                attacking_battler = battler_idx;
                battle_communication[BATTLE_COMMUNICATION_BATTLE_EFFECT] = 0x40 | BATTLE_EFFECT_BAD_POISON;
                    battle_record_item_effect(battler_idx, hold_effect);
                battlescript_init_and_push_current_callback(bsc_status_orb);
                return 1; // status changed
            }
            break;
        }
        case HOLD_EFFECT_CAUSES_SLEEP: {
            if (battlers[battler_idx].current_hp > 0 && battlers[battler_idx].ability != INSOMNIA &&
                battlers[battler_idx].ability != MUNTERKEIT && battlers[battler_idx].status1 == 0 && (rnd16() % 100) < hold_effect_param) {
                // Check if there is an uproar and if so, if the battler is affected by it
                bool is_uproar = false;
                for (active_battler = 0; active_battler < battler_cnt; active_battler++)
                    if (battlers[active_battler].status2 & STATUS2_UPROARED)
                        is_uproar = true;
                if (is_uproar && battlers[battler_idx].ability != LAERMSCHUTZ)
                    break;
                attacking_battler = battler_idx;
                battle_communication[BATTLE_COMMUNICATION_BATTLE_EFFECT] = 0x40 | BATTLE_EFFECT_SLEEP;
                    battle_record_item_effect(battler_idx, hold_effect);
                battlescript_init_and_push_current_callback(bsc_status_orb);
                return 1; // status changed
            }
            break;
        }
        case HOLD_EFFECT_CAUSES_PARALYSIS: {
            if (battlers[battler_idx].current_hp > 0 && battlers[battler_idx].ability != FLEXIBILITAET &&
                battlers[battler_idx].status1 == 0 && (rnd16() % 100) < hold_effect_param) {
                attacking_battler = battler_idx;
                battle_communication[BATTLE_COMMUNICATION_BATTLE_EFFECT] = 0x40 | BATTLE_EFFECT_PARALYSIS;
                    battle_record_item_effect(battler_idx, hold_effect);
                battlescript_init_and_push_current_callback(bsc_status_orb);
                return 1; // status changed
            }
            break;
        }
        case HOLD_EFFECT_CAUSES_FREEZE: {
            if (battlers[battler_idx].current_hp > 0 && battlers[battler_idx].ability != MAGMAPANZER &&
                battlers[battler_idx].type1 != TYPE_EIS && battlers[battler_idx].type2 != TYPE_EIS &&
                battlers[battler_idx].status1 == 0 && (rnd16() % 100) < hold_effect_param) {
                // Pokémon can't be frozen in the sun
                if(WEATHER_HAS_EFFECT && (battle_weather & BATTLE_WEATHER_SUN_ANY))
                    break;
                attacking_battler = battler_idx;
                battle_communication[BATTLE_COMMUNICATION_BATTLE_EFFECT] = 0x40 | BATTLE_EFFECT_ICE;
                    battle_record_item_effect(battler_idx, hold_effect);
                battlescript_init_and_push_current_callback(bsc_status_orb);
                return 1; // status changed
            }
            break;
        }
    }
    return 0; // no effect
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