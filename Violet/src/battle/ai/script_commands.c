#include "types.h"
#include "battle/state.h"
#include "battle/battler.h"
#include "battle/ai.h"
#include "constants/battle/battle_statuses.h"
#include "pokemon/basestat.h"
#include "prng.h"
#include "debug.h"
#include "battle/ressources.h"
#include "vars.h"
#include "constants/difficulties.h"
#include "constants/item_hold_effects.h"
#include "constants/pokemon_types.h"
#include "item/item.h"

static u16 battle_ai_fleeing_prng() {
    return (u16)_prng_xorshift(&battle_state2->fleeing_rng);
}

void battle_ai_script_command_random_flee() {
    u8 battler_idx = battler_get_by_position(BATTLE_POSITION_OPPONENT_LEFT);
    battle_state2->fleeing_rng = battle_state2->fleeing_rng_seed;
    int base_rate = basestats[battlers[battler_idx].species].exp_yield;
    // Some aliments may make fleeing harder
    if (battlers[defending_battler].status1 & STATUS1_FROZEN)
        base_rate /= 10;
    else if (battlers[battler_idx].status1 & STATUS1_SLEEPING)
        base_rate /= 3;
    else if (battlers[battler_idx].status1 & STATUS1_PARALYZED)
        base_rate /= 2;
    base_rate = MAX(1, base_rate);

    // By random, if the pokemon has lost hp, it may increase its fleeing rate
    if ((battle_ai_fleeing_prng() % battlers[battler_idx].max_hp) > battlers[battler_idx].current_hp / (*var_access(DIFFICULTY) == DIFFICULTY_HARD ? 2 : 1))
        base_rate += base_rate / 2;

    DEBUG("Considering fleeing with a rate of %d\n", base_rate);

    if (battle_ai_fleeing_prng() % 512 < base_rate) {
        battle_ai_script = (u8*)UNALIGNED_32_GET(battle_ai_script + 1);
    } else {
        battle_ai_script += 5;
    }
}

void battle_ai_script_command_jump_if_item_bad_for_battler() {
    u8 item_battler_idx, type_battler_idx;
    if (battle_ai_script[1] == 1)
        item_battler_idx = attacking_battler;
    else
        item_battler_idx = defending_battler;
    if (battle_ai_script[2] == 1)
        type_battler_idx = attacking_battler;
    else
        type_battler_idx = defending_battler;
    u8 *script = (u8*)UNALIGNED_32_GET(battle_ai_script + 3);
    battle_ai_script += 7;
    if (battlers[item_battler_idx].item == 0)
        return;
    u8 hold_effect, hold_effect_param;
    if (battlers[item_battler_idx].item == ITEM_ENIGMABEERE) {
        hold_effect = enigma_berries[item_battler_idx].hold_effect;
        hold_effect_param = enigma_berries[item_battler_idx].hold_effect_parameter;
    } else {
        hold_effect = item_get_hold_effect(battlers[item_battler_idx].item);
        hold_effect_param = item_get_hold_effect_parameter(battlers[item_battler_idx].item);
    }
    switch (hold_effect) {
        case HOLD_EFFECT_LEFTOVERS: {
            if (hold_effect_param != 0xFF){
                if (hold_effect_param != battlers[type_battler_idx].type1 && hold_effect_param != battlers[type_battler_idx].type2) {
                    battle_ai_script = script;
                }
            }
            break;
        }
    }
    
}   