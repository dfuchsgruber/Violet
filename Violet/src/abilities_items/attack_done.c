#include "types.h"
#include "attack.h"
#include "debug.h"
#include "save.h"
#include "data_structures.h"
#include "battle/battler.h"
#include "battle/attack.h"
#include "battle/state.h"
#include "battle/battlescript.h"
#include "constants/items.h"
#include "constants/abilities.h"
#include "constants/attack_results.h"
#include "constants/attacks.h"
#include "constants/attack_flags.h"
#include "math.h"
#include "abilities.h"
#include "battle/battle_string.h"
#include "constants/battle/battle_handicaps.h"
#include "constants/pokemon_types.h"
#include "constants/pokemon_stat_names.h"
#include "item/item.h"
#include "constants/item_hold_effects.h"

static u16 curator_relevant_attacks[] = {
    ATTACK_GENESUNG, ATTACK_TAGEDIEB, ATTACK_SYNTHESE, ATTACK_MONDSCHEIN, ATTACK_ERHOLUNG, ATTACK_WUNSCHTRAUM,
    ATTACK_WEICHEI, ATTACK_AROMAKUR, ATTACK_VITALGLOCKE, ATTACK_MILCHGETRAENK
};

bool battle_abilities_attack_done_attacker_new() {
    battler *attacker = battlers + attacking_battler;
    battler *defender = battlers + defending_battler;
    defending_battler_ability = attacker->ability;
    if (attacker->ability == LERNFAEHIG && attacker->current_hp &&
            (attack_result & ATTACK_MISSED) && attacker->stat_changes[6] < 12) {
        attacker->stat_changes[STAT_ACCURACY]++;
        battle_scripting.animation_arguments[0] = 0x18;
        battle_scripting.animation_arguments[1] = 0;
        battle_scripting.battler_idx = attacking_battler; 
        battle_scripting.animation_user = attacking_battler;
        battle_scripting.animation_targets = attacking_battler;
        effect_battler = attacking_battler;
        battlescript_callstack_push_next_command();
        bsc_offset = bsc_lernfaehig;
        return true;
    } else if (attacker->ability == HOCHMUT && !(attack_result & (ATTACK_MISSED |
            ATTACK_NO_EFFECT | ATTACK_FAILED)) && 
            attacks[active_attack].base_power &&
            !battler_statuses[attacking_battler].hurt_in_confusion && DAMAGE_CAUSED
            && !defender->current_hp && attacker->stat_changes[1] < 12){
        attacker->stat_changes[STAT_ATTACK]++; // attack boost
        battle_scripting.animation_arguments[0] = 0xF;
        battle_scripting.animation_arguments[1] = 0;
        battle_scripting.battler_idx = attacking_battler;
        battle_scripting.animation_user = attacking_battler; 
        battle_scripting.animation_targets = attacking_battler;
        effect_battler = attacking_battler;
        battlescript_callstack_push_next_command();
        bsc_offset = bsc_hochmut;
        return true;
    }else if (attacker->ability == LEBENSRAEUBER && !(attack_result & (
            ATTACK_MISSED | ATTACK_NO_EFFECT | ATTACK_FAILED)) && 
            attacks[active_attack].base_power && attacker->current_hp <
            attacker->max_hp &&
            !battler_statuses[attacking_battler].hurt_in_confusion && DAMAGE_CAUSED){
        battle_scripting.battler_idx = attacking_battler;
        battle_scripting.animation_user = attacking_battler;
        battle_scripting.animation_targets = attacking_battler;
        effect_battler = attacking_battler;
        int hp_to_heal = damage_caused >> 2;
        if(hp_to_heal <= 0) hp_to_heal = 1;
        damage_to_apply = -hp_to_heal;
        bsc_offset = bsc_lebensraeuber;
        battlescript_callstack_push_next_command(); 
        return true;
    }else if (attacker->ability == CURATOR && !(attack_result & (
            ATTACK_MISSED | ATTACK_NO_EFFECT | ATTACK_FAILED)) && 
            attacker->current_hp < attacker->max_hp && !battler_statuses[attacking_battler].hurt_in_confusion){
        for (size_t i = 0; i < ARRAY_COUNT(curator_relevant_attacks); i++) {
            if (active_attack == curator_relevant_attacks[i]) {
                int hp_to_heal = attacker->max_hp / 8;
                if (hp_to_heal <= 0) hp_to_heal = 1;
                damage_to_apply = -hp_to_heal;
    	        battle_scripting.battler_idx = attacking_battler;
                battle_scripting.animation_user = attacking_battler;
                battle_scripting.animation_targets = attacking_battler;
                effect_battler = attacking_battler;
                battlescript_callstack_push_next_command();
                bsc_offset = bsc_curator;
                return true;
            }
        }
    } else if (attacker->ability == EXTRADORN && !(attack_result & (
            ATTACK_MISSED | ATTACK_NO_EFFECT | ATTACK_FAILED)) &&
            defender->current_hp && 
            (attacks[active_attack].flags & MAKES_CONTACT) &&
            !battler_statuses[attacking_battler].hurt_in_confusion && DAMAGE_CAUSED){
        battle_scripting.battler_idx = defending_battler;
        battle_scripting.animation_user = defending_battler;
        battle_scripting.animation_targets = defending_battler;
        effect_battler = defending_battler;
        damage_to_apply = MAX(1, damage_caused / 5);
        battlescript_callstack_push_next_command();
        bsc_offset = bsc_extradorn;
        return true;
    }
    return false;
}

bool battle_abilities_attack_done_defender_new() {
    battler *attacker = battlers + attacking_battler;
    battler *defender = battlers + defending_battler;
    defending_battler_ability = defender->ability;
    if(defender->ability == FLUFFIG && !(attack_result & (ATTACK_MISSED | ATTACK_NO_EFFECT | ATTACK_FAILED)) &&
            (attacks[active_attack].flags & MAKES_CONTACT) && !battler_statuses[attacking_battler].hurt_in_confusion && 
            DAMAGE_CAUSED) {
    	if (attacker->stat_changes[3] > 0) {
    		// Trigger fluffy
    		attacker->stat_changes[3] = (u8) MAX(0, attacker->stat_changes[3] - 2);
    	    battle_scripting.animation_arguments[0] = 0x18;
    	    battle_scripting.animation_arguments[1] = 0;
    	    battle_scripting.battler_idx = attacking_battler;
            battle_scripting.animation_user = attacking_battler;
            battle_scripting.animation_targets = attacking_battler;
            effect_battler = attacking_battler;
            battlescript_callstack_push_next_command();
            bsc_offset = bsc_fluffy;
            return true;
    	}
    }
    return false;
}

bool battle_items_attack_done_new() {
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

bool battle_handicap_attack_done() {
    battler *attacker = battlers + attacking_battler;
    // Apply handicap rules, step by step, the current state is fmem.gp_value
    if (BATTLE_STATE2->switch_in_handicap_effects_cnt == BATTLE_HANDICAP_ARENA_ENCOURAGEMENT && (fmem.battle_handicaps & int_bitmasks[BATTLE_HANDICAP_ARENA_ENCOURAGEMENT]) &&
            !(attack_result & (ATTACK_MISSED | ATTACK_NO_EFFECT | ATTACK_FAILED)) && 
            attacks[active_attack].base_power &&
            !battler_statuses[attacking_battler].hurt_in_confusion && DAMAGE_CAUSED
            && attacker->stat_changes[1] < 12 && 
            (attacker->type1 == TYPE_KAMPF || attacker->type2 == TYPE_KAMPF) &&
            attacks[active_attack].type == TYPE_KAMPF) {
            attacker->stat_changes[1]++; // attack boost
            battle_scripting.battler_idx = attacking_battler;
            battle_scripting.animation_user = attacking_battler;
            battle_scripting.animation_targets = attacking_battler;
            effect_battler = attacking_battler;
            battlescript_callstack_push_next_command();
            bsc_offset = bsc_hochmut;
            return true;
    }
    return false;
}

void bsc_cmd_x49_attack_done_new() {
    if (battle_scripting.attack_done_state <= 17) {
        bsc_cmd_x49_attack_done();
    }
    switch (battle_scripting.attack_done_state) {
        case 0 ... 17: return; // The original function has not terminated 
        case 18: { // We enter this case when the original function whould have terminated
            //dprintf("Initialize new attack done effects.\n");
            BATTLE_STATE2->attack_done_substate = 0;
            BATTLE_STATE2->switch_in_handicap_effects_cnt = 0;
            battle_scripting.attack_done_state++;
            break;
        }
        case 19: {
            // Yeah, this executes all new attack_done effects after all the other, but who cares tbh
            bool effect = false;
            while (!effect) {
                //dprintf("Executing substate %d\n", BATTLE_STATE2->attack_done_substate);
                switch(BATTLE_STATE2->attack_done_substate) {
                    case 0: {
                        if (battle_abilities_attack_done_attacker_new()) {
                            effect = true;
                        }
                        BATTLE_STATE2->attack_done_substate++;
                        break;
                    }
                    case 1: {
                        if (battle_abilities_attack_done_defender_new()) {
                            effect = true;
                        }
                        BATTLE_STATE2->attack_done_substate++;
                        break;
                    }
                    case 2: {
                        if (battle_items_attack_done_new()) {
                            effect = true;
                        }
                        BATTLE_STATE2->attack_done_substate++;
                        break;
                    }
                    case 3: {
                    }
                    case 4: {
                        if (BATTLE_STATE2->switch_in_handicap_effects_cnt < 32) {
                            if (battle_handicap_attack_done())
                                effect = true;
                            BATTLE_STATE2->switch_in_handicap_effects_cnt++; // Next step -> Next Check next handycap
                        } else {
                            BATTLE_STATE2->attack_done_substate++;
                        }
                        break;
                    }
                    default: { // Termination
                        bsc_offset += 3;
                        return;
                    }
                }
            }
        }
    }
}