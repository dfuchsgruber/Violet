#include "types.h"
#include "battle/state.h"
#include "battle/battler.h"
#include "constants/item_hold_effects.h"
#include "item/item.h"
#include "battle/attack.h"
#include "constants/attack_results.h"
#include "attack.h"
#include "constants/pokemon_types.h"
#include "debug.h"

extern u8 bsc_life_orb[];


u8 battle_items_switch_in_effects() { // Return 0 if no effect was used, 0xFF if an effect was used, but no bsc was triggered and a suitable effect type else
    u8 hold_effect = item_get_hold_effect(bsc_last_used_item);
    u8 hold_effect_parameter = item_get_hold_effect_parameter(bsc_last_used_item);
    dprintf("Item switch in effect, hold effect %d with parameter %d\n", hold_effect, hold_effect_parameter);
    switch(hold_effect) {
        case HOLD_EFFECT_FOUR_LEAF:
            BATTLE_STATE2->item_dropping_chance_increased_by_item = 1;
            return 0xFF;
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
            !(attack_result & (ATTACK_FAILED | ATTACK_MISSED |
            ATTACK_NO_EFFECT)) && attacks[active_attack].base_power &&
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
            !(attack_result & (ATTACK_FAILED | ATTACK_MISSED |
            ATTACK_NO_EFFECT)) && attacks[active_attack].base_power &&
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