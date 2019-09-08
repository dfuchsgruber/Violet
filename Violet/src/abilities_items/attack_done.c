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

void attack_done(u8 index){
    battler *attacker = &battlers[attacking_battler];
    battler *defender = &battlers[defending_battler];
    //First apply life-orb damage if damage caused
    if(attacker->item == ITEM_LEBEN_ORB && attacker->current_hp &&
            !(attack_result & (ATTACK_FAILED | ATTACK_MISSED |
            ATTACK_NO_EFFECT)) && attacks[active_attack].base_power &&
            !battler_statuses[attacking_battler].hurt_in_confusion && DAMAGE_CAUSED){
        //inflict life-orb damage
        battlescript_callstack_push_next_command();
        bsc_offset = bsc_life_orb;
        //dprintf("Life orb triggered for battler %d\n", attacking_battler);
        
        
    }
    //now apply the abilities
    if(attacker->ability == LERNFAEHIG && attacker->current_hp &&
            (attack_result & ATTACK_MISSED) && attacker->stat_changes[6] < 12){
        if(gp_stack_push(index)){
            attacker->stat_changes[6]++; //accuracy boost
            battlescript_callstack_push_next_command();
            bsc_offset = bsc_lernfaehig;
        }else{
            derrf("Lernfaehig not triggered for battler %d\n, gp stack held no \
                    space\n", attacking_battler);
        }
        
    }else if(attacker->ability == HOCHMUT && !(attack_result & (ATTACK_MISSED |
            ATTACK_NO_EFFECT | ATTACK_FAILED)) && 
            attacks[active_attack].base_power &&
            !battler_statuses[attacking_battler].hurt_in_confusion && DAMAGE_CAUSED
            && defender->current_hp && attacker->stat_changes[1] < 12){
        if(gp_stack_push(index)){
            attacker->stat_changes[1]++; //accuracy boost
            battlescript_callstack_push_next_command();
            bsc_offset = bsc_hochmut;
        }else{
            derrf("Hochmut not triggered for battler %d\n, gp stack held no \
                    space\n", attacking_battler);
        }
    }else if(attacker->ability == LEBENSRAEUBER && !(attack_result & (
            ATTACK_MISSED | ATTACK_NO_EFFECT | ATTACK_FAILED)) && 
            attacks[active_attack].base_power && attacker->current_hp <
            attacker->max_hp &&
            !battler_statuses[attacking_battler].hurt_in_confusion && DAMAGE_CAUSED){
        battlescript_callstack_push_next_command();
        bsc_offset = bsc_lebensraeuber;
    }else if(attacker->ability == CURATOR && !(attack_result & (
            ATTACK_MISSED | ATTACK_NO_EFFECT | ATTACK_FAILED)) && 
            attacker->current_hp < attacker->max_hp && (
            active_attack == ATTACK_GENESUNG ||
            active_attack == ATTACK_TAGEDIEB ||
            active_attack == ATTACK_SYNTHESE ||
            active_attack == ATTACK_MONDSCHEIN ||
            active_attack == ATTACK_ERHOLUNG ||
            active_attack == ATTACK_WUNSCHTRAUM ||
            active_attack == ATTACK_WEICHEI ||
            active_attack == ATTACK_AROMAKUR ||
            active_attack == ATTACK_VITALGLOCKE ||
            active_attack == ATTACK_MILCHGETRAENK
            ) && !battler_statuses[attacking_battler].hurt_in_confusion){
        battlescript_callstack_push_next_command();
        bsc_offset = bsc_curator;
        
    }else if(attacker->ability == EXTRADORN && !(attack_result & (
            ATTACK_MISSED | ATTACK_NO_EFFECT | ATTACK_FAILED)) &&
            defender->current_hp && 
            (attacks[active_attack].flags & MAKES_CONTACT) &&
            !battler_statuses[attacking_battler].hurt_in_confusion && DAMAGE_CAUSED){
        battlescript_callstack_push_next_command();
        bsc_offset = bsc_extradorn;
    } else if(defender->ability == FLUFFIG && (attacks[active_attack].flags & MAKES_CONTACT)) {
    	if (attacker->stat_changes[3] > 0) {
    		// Trigger fluffy
    		attacker->stat_changes[3] = (u8) MAX(0, attacker->stat_changes[3] - 2);
    	    battle_scripting.animation_arguments[0] = 0x18;
    	    battle_scripting.animation_arguments[1] = 0;
    	    battle_scripting.battler_idx = attacking_battler;
            battlescript_callstack_push_next_command();
            bsc_offset = bsc_fluffy;
    	}
    }
}

void attack_done_prepeare_life_orb(){
    battler *attacker = &battlers[attacking_battler];
    int damage = attacker->max_hp / 10;
    if(damage <= 0) damage = 1;
    damage_to_apply = damage;
}

void attack_done_prepeare_lernfaehig(){
    battle_scripting.animation_arguments[0] = 0x14;
    battle_scripting.animation_arguments[1] = 0;
    battle_scripting.battler_idx = (u8)gp_stack_pop();
}

void attack_done_prepeare_hochmut(){
    battle_scripting.animation_arguments[0] = 0xF;
    battle_scripting.animation_arguments[1] = 0;
    battle_scripting.battler_idx = (u8)gp_stack_pop();
}

void attack_done_prepeare_lebensraeuber(){
    int hp_to_heal = damage_caused >> 2;
    if(hp_to_heal <= 0) hp_to_heal = 1;
    damage_to_apply = -hp_to_heal;
}

void attack_done_prepeare_curator(){
    battler *attacker = &battlers[attacking_battler];
    int hp_to_heal = attacker->max_hp / 16;
    if (hp_to_heal <= 0) hp_to_heal = 1;
    damage_to_apply = -hp_to_heal;
}

void attack_done_prepeare_extradorn(){
    bsc_buffers[0] = 0xFD;
    bsc_buffers[1] = 3;
    bsc_buffers[3] = 0xFF;
    int damage = damage_caused / 8;
    if(damage <= 0) damage = 1;
    damage_to_apply = damage;
}
