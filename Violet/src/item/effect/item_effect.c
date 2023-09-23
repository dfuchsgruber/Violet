#include "types.h"
#include "constants/item_effect_types.h"
#include "item/custom.h"
#include "item/item.h"
#include "item/item_effect.h"
#include "pokemon/virtual.h"
#include "constants/pokemon_attributes.h"
#include "save.h"
#include "superstate.h"
#include "battle/battler.h"
#include "battle/state.h"
#include "overworld/pokemon_party_menu.h"
#include "constants/pokemon_stat_names.h"
#include "pokemon/basestat.h"
#include "battle/attack.h"
#include "battle/controller.h"
#include "constants/item_hold_effects.h"
#include "map/namespace.h"
#include "pokemon/evolution.h"
#include "debug.h"
#include "constants/item_effect_types.h"
#include "language.h"
#include "item/pokeball.h"

// TODO: this function is only used by the battle ai in order to check if to use an item
// when at some point refactoring the battle ai, we do not have to return this value
u8 _item_effect_get_hp_healed_offset(u16 item, u8 effect_byte, u8 effect_bit) {
    if (effect_byte != 4 || effect_bit != 4) {
        ERROR("Item effect argument offset other than hp requested: byte %d bit %d\n", effect_byte, effect_bit);
    }
    if (ITEM_HAS_TABLE_EFFECT(item) && item_effects[item - ITEM_TRANK]) {
        return 12; // This offset of the hp to be healed in an item effect -> this is hacky...
    }
    return 0;
}

bool item_effect_execute_battle_effects(pokemon *p, u16 item, u8 battler_idx, u8 move_idx, u8 party_idx, u8 hold_effect, 
    const item_effect_t *effect, bool calculate_heal_only, bool check_only) {
    (void) p; (void) calculate_heal_only; (void) move_idx; (void) party_idx; (void) hold_effect; (void) item;
    bool effect_applied = false;
    if (super.in_battle && battler_idx != 4) {
        battler *b = battlers + battler_idx;
        if (effect->heal_infatuation && b->status2 & STATUS2_INFATUATION) {
            if (!check_only) b->status2 &= (u32)(~STATUS2_INFATUATION);
            effect_applied = true;
        }
        if (effect->increase_critical_ratio && !(b->status2 & STATUS2_FOCUS_ENERGY)) {
            if (!check_only) b->status2 |= STATUS2_FOCUS_ENERGY;
            effect_applied = true;
        }
        if (effect->creates_mist && battle_side_timers[battler_is_opponent(battler_idx)].mist_turns == 0) {
            if (!check_only) battle_side_timers[battler_is_opponent(battler_idx)].mist_turns = 5;
            effect_applied = true;
        }
        if (effect->x_attack && b->stat_changes[STAT_ATTACK] < 12) {
            if (!check_only) b->stat_changes[STAT_ATTACK] = (u8)(MIN(12, b->stat_changes[STAT_ATTACK] + effect->x_attack));
            effect_applied = true;
        }
        if (effect->x_defense && b->stat_changes[STAT_DEFENSE] < 12) {
            if (!check_only) b->stat_changes[STAT_DEFENSE] = (u8)(MIN(12, b->stat_changes[STAT_DEFENSE] + effect->x_defense));
            effect_applied = true;
        }
        if (effect->x_speed && b->stat_changes[STAT_SPEED] < 12) {
            if (!check_only) b->stat_changes[STAT_SPEED] = (u8)(MIN(12, b->stat_changes[STAT_SPEED] + effect->x_speed));
            effect_applied = true;
        }
        if (effect->x_special_attack && b->stat_changes[STAT_SPECIAL_ATTACK] < 12) {
            if (!check_only) b->stat_changes[STAT_SPECIAL_ATTACK] = (u8)(MIN(12, b->stat_changes[STAT_SPECIAL_ATTACK] + effect->x_special_attack));
            effect_applied = true;
        }
        if (effect->x_accuracy && b->stat_changes[STAT_ACCURACY] < 12) {
            if (!check_only) b->stat_changes[STAT_ACCURACY] = (u8)(MIN(12, b->stat_changes[STAT_ACCURACY] + effect->x_accuracy));
            effect_applied = true;
        }
        if (effect->heal_confusion && (battlers[battler_idx].status2 & STATUS2_CONFUSED)) {
            if (!check_only) battlers[battler_idx].status2 &= (u32)(~STATUS2_CONFUSED);
            effect_applied = true;
        }
    }
    return effect_applied;
}

bool item_effect_execute_level_up(pokemon *p, u16 item, u8 battler_idx, u8 move_idx, u8 party_idx, u8 hold_effect, 
    const item_effect_t *effect, bool calculate_heal_only, bool check_only) {
    (void) battler_idx; (void) move_idx; (void) party_idx; (void) hold_effect; (void) calculate_heal_only; (void) item;
    DEBUG("Level up %d, %d %d\n", effect->increase_level, effect->level, pokemon_get_attribute(p, ATTRIBUTE_LEVEL, 0));
    if (effect->increase_level && pokemon_get_attribute(p, ATTRIBUTE_LEVEL, 0) < 100) {
        if (!check_only) {
            int level = MIN(100, pokemon_get_attribute(p, ATTRIBUTE_LEVEL, 0) + effect->level);
            DEBUG("Increase to level %d with amount of %d\n", level, effect->level);
            pokemon_set_attribute(p, ATTRIBUTE_EXP, 
                &pokemon_experience_tables[basestats[pokemon_get_attribute(p, ATTRIBUTE_SPECIES, 0)].level_up_type][level]);
            pokemon_calculate_stats(p);
        }
        return true;
    }
    return false;
}

bool item_effect_execute_status_heals(pokemon *p, u16 item, u8 battler_idx, u8 move_idx, u8 party_idx, u8 hold_effect, 
    const item_effect_t *effect, bool calculate_heal_only, bool check_only) {
    (void) hold_effect; (void) move_idx; (void) calculate_heal_only; (void) item;
    bool effect_applied = false;
    if (effect->heal_sleep && pokemon_has_status_condition(p, party_idx, STATUS1_SLEEPING)) {
        if (!check_only){
            pokemon_remove_status_condition(p, party_idx, STATUS1_SLEEPING, battler_idx);
            battlers[battler_idx].status2 &= (u32)(~STATUS2_NIGHTMARE);
        }
        effect_applied = true;
    }
    if (effect->heal_burn && pokemon_has_status_condition(p, party_idx, STATUS1_BURNED)) {
        if (!check_only) pokemon_remove_status_condition(p, party_idx, STATUS1_BURNED, battler_idx);
        effect_applied = true;
    }  
    if (effect->heal_freeze && pokemon_has_status_condition(p, party_idx, STATUS1_FROZEN)) {
        if (!check_only) pokemon_remove_status_condition(p, party_idx, STATUS1_FROZEN, battler_idx);
        effect_applied = true;
    }    
    if (effect->heal_paralysis && pokemon_has_status_condition(p, party_idx, STATUS1_PARALYZED)) {
        if (!check_only) pokemon_remove_status_condition(p, party_idx, STATUS1_PARALYZED, battler_idx);
        effect_applied = true;
    }      
    if (effect->heal_poison && pokemon_has_status_condition(p, party_idx, STATUS1_POISONED_ANY | STATUS1_BADLY_POISONED_TURNS)) {
        if (!check_only) pokemon_remove_status_condition(p, party_idx, STATUS1_POISONED_ANY | STATUS1_BADLY_POISONED_TURNS, battler_idx);
        effect_applied = true;
    }       
    return effect_applied;
}

bool item_effect_execute_ev_increase(pokemon *p, u16 item, u8 battler_idx, u8 move_idx, u8 party_idx, u8 hold_effect, 
    const item_effect_t *effect, bool calculate_heal_only, bool check_only) {
    (void) battler_idx; (void) move_idx; (void) party_idx; (void) hold_effect; (void) calculate_heal_only; (void) item;
    bool increase_evs[6] = {[STAT_HP] = effect->increase_ev_hp, [STAT_ATTACK] = effect->increase_ev_attack, 
                            [STAT_DEFENSE] = effect->increase_ev_defense, [STAT_SPEED] = effect->increase_ev_speed, 
                            [STAT_SPECIAL_ATTACK] = effect->increase_ev_special_attack, 
                            [STAT_SPECIAL_DEFENSE] = effect->increase_ev_special_defense};
    bool effect_applied = false;
    for (int i = 0; i < 6; i++) {
        if (increase_evs[i]) {
            switch (effect->evs[i]) {
                case EFFECT_RESET_EVS: {
                    if (pokemon_get_effective_ev(p, i) > 0) {
                        if (!check_only) {
                            pokemon_set_effective_ev(p, i, 0);
                        }
                        effect_applied = true;
                    }
                    break;
                }
                default:{
                    int potential_ev = pokemon_get_potential_ev(p, i);
                    if (potential_ev < 255) {
                        if (!check_only) {
                            potential_ev += effect->evs[i];
                            pokemon_set_potential_ev(p, i, (u8)(MIN(255, potential_ev)));
                        }
                        effect_applied = true;
                    }
                    break;
                }
            }
        }

        
    }
    return effect_applied;  
}

bool item_effect_execute_pp_increase(pokemon *p, u16 item, u8 battler_idx, u8 move_idx, u8 party_idx, u8 hold_effect, 
    const item_effect_t *effect, bool calculate_heal_only, bool check_only) {
    (void) party_idx; (void) hold_effect; (void) battler_idx; (void) calculate_heal_only; (void) item;
    if (effect->pp_up || effect->pp_max) {
        // Calculate the pp ups for this move
        u8 pp_ups = (u8)((pokemon_get_attribute(p, ATTRIBUTE_PP_BONUSES, 0) & pokemon_pp_up_set_masks[move_idx]) >> (2 * move_idx));
        u16 move = (u16)pokemon_get_attribute(p, ATTRIBUTE_ATTACK1 + move_idx, 0);
        int pp = attack_get_pp(move, (u8)pokemon_get_attribute(p, ATTRIBUTE_PP_BONUSES, 0), move_idx);
        if (pp_ups < 3 && pp > 4) {
            if (!check_only) {
                if (effect->pp_up) {
                    pp_ups = (u8)(pokemon_get_attribute(p, ATTRIBUTE_PP_BONUSES, 0) + pokemon_pp_up_add_masks[move_idx]);
                } else if (effect->pp_max) {
                    pp_ups = (u8)((pokemon_get_attribute(p, ATTRIBUTE_PP_BONUSES, 0) & pokemon_pp_up_clear_masks[move_idx]) 
                        + 3 * pokemon_pp_up_add_masks[move_idx]);
                }
                pokemon_set_attribute(p, ATTRIBUTE_PP_BONUSES, &pp_ups);
                int pp_increase = attack_get_pp(move, pp_ups, move_idx) - pp;
                int current_pp = pokemon_get_attribute(p, ATTRIBUTE_PP1 + move_idx, 0) + pp_increase;
                pokemon_set_attribute(p, ATTRIBUTE_PP1 + move_idx, &current_pp);
            }
            return true;
        }
    }
    return false;
}

bool item_effect_execute_hp_heal(pokemon *p, u16 item, u8 battler_idx, u8 move_idx, u8 party_idx, u8 hold_effect, 
    const item_effect_t *effect, bool calculate_heal_only, bool check_only) {
    (void) move_idx; (void) hold_effect; (void) item;
    bool effect_applied = false;
    if (effect->heal_hp) {
        int current_hp = pokemon_get_attribute(p, ATTRIBUTE_CURRENT_HP, 0);
        if (effect->revives) {
            if (current_hp == 0) {
                if (!check_only) {
                    if (super.in_battle) {
                        if (battler_idx != 4) {
                            // Battler to be revived is present on the field, reload its battler data
                            battlers_absent &= (u8)(~int_bitmasks[battler_idx]);
                            battler_load_from_player_party(battler_idx, player_party_get_reordered_idx(party_idx));
                        } else {
                            // Pokemon to be revived is not present on the field
                            battlers_absent &= (u8)(~int_bitmasks[active_battler ^ 2]);
                        }
                        if (!battler_is_opponent(active_battler) && battle_results.revives_cnt < 255)
                            battle_results.revives_cnt++;
                    }
                }
                effect_applied = true;
            } else {
                return false;
            }
        } else if (current_hp == 0) { // Can't heal a fainted pokémon without revive effect
            return false;
        }
        // Heal hp TODO
        int hp_difference = pokemon_get_attribute(p, ATTRIBUTE_TOTAL_HP, 0) - pokemon_get_attribute(p, ATTRIBUTE_CURRENT_HP, 0);
        int hp_to_heal;
        switch (effect->hp) {
            case ITEM_EFFECT_HEAL_HP_ALL:
                hp_to_heal = hp_difference;
                break;
            case ITEM_EFFECT_HEAL_HP_HALF:
                hp_to_heal = MAX(1, pokemon_get_attribute(p, ATTRIBUTE_TOTAL_HP, 0) / 2);
                break;
            case ITEM_EFFECT_HEAL_HP_QUARTER:
                hp_to_heal = MAX(1, pokemon_get_attribute(p, ATTRIBUTE_TOTAL_HP, 0) / 4);
                break;
            case ITEM_EFFECT_HEAL_HP_EIGHTH:
                hp_to_heal = MAX(1, pokemon_get_attribute(p, ATTRIBUTE_TOTAL_HP, 0) / 8);
                break;
            case ITEM_EFFECT_HEAL_HP_DYANMIC:
                hp_to_heal = battle_scripting.heal_item_amount;
                break;
            case ITEM_EFFECT_HEAL_HP_PERCENTAGE:
                hp_to_heal = MAX(1, pokemon_get_attribute(p, ATTRIBUTE_TOTAL_HP, 0) * effect->hp / 100);
                break;
            default:
                hp_to_heal = effect->hp;
                break;
        }
        DEBUG("Hp to heal %d\n", hp_to_heal);
        if (hp_difference > 0) {
            if (!check_only) {
                if (calculate_heal_only) {
                    damage_to_apply = -hp_to_heal;
                } else {
                    // Apply healing to mons hp directly
                    int hp = MIN(pokemon_get_attribute(p, ATTRIBUTE_TOTAL_HP, 0), pokemon_get_attribute(p, ATTRIBUTE_CURRENT_HP, 0) + hp_to_heal);
                    pokemon_set_attribute(p, ATTRIBUTE_CURRENT_HP, &hp);
                    if (super.in_battle && battler_idx != 4) {
                        battlers[battler_idx].current_hp = (u16)hp;
                        if (!effect->revives && !battler_is_opponent(battler_idx)) {
                            if (battle_results.healing_items_cnt < 255)
                                battle_results.healing_items_cnt++;
                            // Temporarily change the active battler for animation
                            u8 tmp = active_battler;
                            active_battler = battler_idx;
                            battle_controller_emit_get_pokemon_data(0, 0, 0);
                            battler_mark_for_controller_execution(battler_idx);
                            active_battler = tmp;
                        }
                    }
                }
            }
            effect_applied = true;
        }

    }
    return effect_applied;
}

bool item_effect_heal_pp(pokemon *p, u8 battler_idx, u8 move_idx, u8 amount, bool check_only) {
    u16 move = (u16) pokemon_get_attribute(p, ATTRIBUTE_ATTACK1 + move_idx, 0);
    int pp = pokemon_get_attribute(p, ATTRIBUTE_PP1 + move_idx, 0);
    int max_pp = attack_get_pp(move, (u8) pokemon_get_attribute(p, ATTRIBUTE_PP_BONUSES, 0), move_idx);
    if (pp < max_pp) {
        if (!check_only) {
            if (amount == ITEM_EFFECT_PP_ALL) {
                pp = max_pp;
            } else {
                pp = MIN(max_pp, pp + amount);
            }
            DEBUG("Increase pp of move %d to %d on mon %x\n", move_idx, pp, p);
            pokemon_set_attribute(p, ATTRIBUTE_PP1 + move_idx, &pp);
            if (super.in_battle && battler_idx != 4 && !(battlers[battler_idx].status2 & STATUS2_TRANSFORMED) &&
                !(battler_disable[battler_idx].mimicked_moves & int_bitmasks[move_idx])) {
                battlers[battler_idx].current_pp[move_idx] = (u8)pp;
            }
        }
        return true;
    }
    return false;
}

bool item_effect_execute_pp_heal(pokemon *p, u16 item, u8 battler_idx, u8 move_idx, u8 party_idx, u8 hold_effect, 
    const item_effect_t *effect, bool calculate_heal_only, bool check_only) {
    (void) party_idx; (void) calculate_heal_only; (void) hold_effect; (void) item;
    bool effect_applied = false;
    if (effect->heal_pp) {
        if (effect->heal_pp_one_move) {
            return item_effect_heal_pp(p, battler_idx, move_idx, effect->pp, check_only);
        } else {
            for (u8 i = 0; i < 4; i++) {
                if (item_effect_heal_pp(p, battler_idx, i, effect->pp, check_only))
                    effect_applied = true;    
            }
        }
    }
    return effect_applied; 
}

bool item_effect_increase_friendship(pokemon *p, u8 hold_effect, int amount, bool check_only) {
    int friendship = pokemon_get_attribute(p, ATTRIBUTE_HAPPINESS, 0);
    if (friendship >= 255) return false;
    if (!check_only) {
        if (hold_effect == HOLD_EFFECT_HAPPINESS_UP) {
            amount += amount / 2;
        }
        friendship += amount;
        if (pokemon_get_attribute(p, ATTRIBUTE_CATCH_INFO, 0) == BALL_LUXURY) 
            friendship++;
        if (pokemon_get_attribute(p, ATTRIBUTE_CATCH_LOCATION, 0) == map_get_current_namespace())
            friendship++;
        friendship = MIN(255, friendship);
        pokemon_set_attribute(p, ATTRIBUTE_HAPPINESS, &friendship);
    }
    return true;
}

bool item_effect_execute_friendship(pokemon *p, u16 item, u8 battler_idx, u8 move_idx, u8 party_idx, u8 hold_effect, 
    const item_effect_t *effect, bool calculate_heal_only, bool check_only) {
    (void) party_idx; (void) calculate_heal_only; (void) move_idx; (void) battler_idx; (void) item;
    int friendship = pokemon_get_attribute(p, ATTRIBUTE_HAPPINESS, 0);
    if (effect->increase_friendship_low && friendship < 100) {
        return item_effect_increase_friendship(p, hold_effect, effect->friendship_low, check_only);
    } else if (effect->increase_friendship_mid && friendship < 200) {
        return item_effect_increase_friendship(p, hold_effect, effect->friendship_mid, check_only);
    } else if (effect->increase_friendship_high) {
        return item_effect_increase_friendship(p, hold_effect, effect->friendship_high, check_only);
    }
    return false;
}

bool item_effect_execute_evolution(pokemon *p, u16 item, u8 battler_idx, u8 move_idx, u8 party_idx, u8 hold_effect, 
    const item_effect_t *effect, bool calculate_heal_only, bool check_only) {
    (void) party_idx; (void) calculate_heal_only; (void) move_idx; (void) battler_idx; (void) hold_effect; (void) effect;
    u16 target;
    if (check_only) {   
        target = pokemon_get_evolution(p, EVOLUTION_TRIGGER_ITEM, item);
    } else {
        target = pokemon_get_evolution(p, EVOLUTION_TRIGGER_ITEM_AND_REMOVE_HOLD_ITEM, item);
    }
    if (target) {
        if (!check_only) {
            pokemon_initialize_evolution(p, target, false, party_idx);
        }
        return true;
    }
    return false;
}

bool item_effect_execute_golden_apple(pokemon *p, u16 item, u8 battler_idx, u8 move_idx, u8 party_idx, u8 hold_effect, 
    const item_effect_t *effect, bool calculate_heal_only, bool check_only) {
    (void)p; (void)item; (void)move_idx; (void)party_idx; (void)hold_effect; (void) calculate_heal_only;
    if (effect->golden_apple && battler_idx < 4) {
        if (!check_only) 
            battle_state2->status_custom_persistent[battler_idx] |= CUSTOM_STATUS_PERSISTENT_GOLDEN_APPLE_PROTECTION;
        DEBUG("Golden Apple protection battler %d, status is %x\n", battler_idx, battle_state2->status_custom_persistent[battler_idx]);
        return true;
    }
    return false;
}
  

bool (*const item_effect_functions[NUMBER_ITEM_EFFECT_FUNCTIONS])(pokemon*, u16, u8, u8, u8, u8, const item_effect_t*, bool, bool) = {
    item_effect_execute_battle_effects,
    item_effect_execute_level_up,
    item_effect_execute_status_heals,
    item_effect_execute_ev_increase,
    item_effect_execute_pp_increase,
    item_effect_execute_hp_heal,
    item_effect_execute_pp_heal,
    item_effect_execute_friendship,
    item_effect_execute_evolution,
    item_effect_execute_golden_apple,
};


bool item_effect(pokemon *p, u16 item, u8 party_idx, u8 move_idx, bool calculate_heal_only, bool check_only) {
    DEBUG("Item effect by table with p : %x, item %x, party_idx %d, move_idx %d, calculate_heal_only %d, check_only %d\n",
        p, item, party_idx, move_idx, calculate_heal_only, check_only);
    u8 hold_effect = 0;
    u16 held_item = (u16)pokemon_get_attribute(p, ATTRIBUTE_ITEM, 0);
    if (item == ITEM_ENIGMABEERE) {
        hold_effect = item_get_hold_effect(held_item);
    }
    item_target_battler = battler_in_party_menu;

    // Find the battler idx that is targeted for inbattle items
    u8 battler_idx = 4;
    if (super.in_battle) {
        active_battler = battler_in_party_menu;
        DEBUG("Item effect for active battler %d\n", active_battler);
        for (u8 i = 0; i < battler_cnt; i++) {
            if (battler_is_opponent(i) == battler_is_opponent(active_battler) && party_idx == battler_idx_to_party_idx(i)) {
                battler_idx = i;
                break;
            }
        }
        DEBUG("Found battler %d with party slot %d\n", battler_idx, party_idx);
    } else {
        active_battler = 0;
    }
    if (!ITEM_HAS_TABLE_EFFECT(item))
        return true;
    const item_effect_t *effect = item_effects[item - ITEM_TRANK];
    if (!effect && item != ITEM_ENIGMABEERE)
        return true;
    bool effect_applied = false;
    if (item == ITEM_ENIGMABEERE) {
        if (super.in_battle) {
            effect = &enigma_berries[battler_idx].item_effect;
        } else {
            effect = (item_effect_t*)&save1->enigma_berry.item_effect;
        }
    }
    for (int i = 0; i < NUMBER_ITEM_EFFECT_FUNCTIONS; i++) {
        if (item_effect_functions[i](p, item, battler_idx, move_idx, party_idx, hold_effect, effect, calculate_heal_only, check_only))
            effect_applied = true;
    }
    return effect_applied;
}

bool _item_effect_unapplicable_fmem_hooked(pokemon *p, u16 item, u8 party_idx, u8 move_idx) {
    (void)p;
    return !item_effect((pokemon*)hook_tmp, item, party_idx, move_idx, false, true);
}

bool item_effect_apply(pokemon *p, u16 item, u8 party_idx, u8 move_idx, bool calculate_hp_heal_only) {
    (void)p;
    return !item_effect((pokemon*)hook_tmp, item, party_idx, move_idx, calculate_hp_heal_only, false);
}

u8 item_get_effect_type(u16 item) {
    if (!ITEM_HAS_TABLE_EFFECT(item)) return ITEM_EFFECT_NONE;
    const item_effect_t* effect;
    if (item == ITEM_ENIGMABEERE) {
        effect = (item_effect_t*)&save1->enigma_berry.item_effect;
    } else {
        effect = item_effects[item - ITEM_TRANK];
    }
    if (effect->x_attack || effect->x_accuracy || effect->x_defense || effect->x_special_attack 
        || effect->x_speed || effect->creates_mist || effect->increase_critical_ratio)
        return ITEM_EFFECT_X_ITEM;
    if (effect->sacred_ash) return ITEM_EFFECT_SACRED_ASH;
    if (effect->heal_burn && effect->heal_confusion && effect->heal_freeze && effect->heal_infatuation
        && effect->heal_paralysis && effect->heal_poison && effect->heal_sleep) return ITEM_EFFECT_HEAL_ALL_STATUS;
    if (effect->heal_burn) return ITEM_EFFECT_HEAL_BURN;
    if (effect->heal_confusion) return ITEM_EFFECT_HEAL_CONFUSION;
    if (effect->heal_freeze) return ITEM_EFFECT_HEAL_FREEZE;
    if (effect->heal_infatuation) return ITEM_EFFECT_HEAL_INFATUATION;
    if (effect->heal_paralysis) return ITEM_EFFECT_HEAL_PARALYSIS;
    if (effect->heal_poison) return ITEM_EFFECT_HEAL_POISON;
    if (effect->heal_sleep) return ITEM_EFFECT_HEAL_SLEEP;
    if (effect->heal_hp || effect->revives) return ITEM_EFFECT_HEAL_HP;
    if (effect->increase_ev_hp) return ITEM_EFFECT_EV_HP;
    if (effect->increase_ev_attack) return ITEM_EFFECT_EV_ATTACK;
    if (effect->increase_ev_defense) return ITEM_EFFECT_EV_DEFENSE;
    if (effect->increase_ev_speed) return ITEM_EFFECT_EV_SPEED;
    if (effect->increase_ev_special_attack) return ITEM_EFFECT_EV_SPECIAL_ATTACK;
    if (effect->increase_ev_special_defense) return ITEM_EFFECT_EV_SPECIAL_DEFENSE;
    if (effect->trigger_evolution) return ITEM_EFFECT_TRIGGER_EVOLUTION;
    if (effect->pp_max) return ITEM_EFFECT_PP_MAX;
    if (effect->pp_up) return ITEM_EFFECT_PP_UP;
    if (effect->heal_pp) return ITEM_EFFECT_HEAL_PP;
    if (effect->friendship_low || effect->friendship_mid || effect->friendship_high) return ITEM_EFFECT_FRIENDSHIP;
    return ITEM_EFFECT_NONE;
}