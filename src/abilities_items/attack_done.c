#include "types.h"
#include "romfuncs.h"
#include "abilities.h"
#include "basestats.h"
#include "item.h"
#include "attack.h"
#include "battle.h"
#include "basestats.h"
#include "debug.h"
#include "save.h"
#include "data_structures.h"

extern u8 bsc_life_orb[];
extern u8 bsc_lernfaehig[];
extern u8 bsc_hochmut[];
extern u8 bsc_lebensraeuber[];
extern u8 bsc_curator[];
extern u8 bsc_extradorn[];

void attack_done(u8 index){
    battler *attacker = &battlers[*attacking_battler];
    battler *defender = &battlers[*defending_battler];
    //First apply life-orb damage if damage caused
    if(attacker->item == ITEM_LEBEN_ORB && attacker->current_hp &&
            !(*attack_result & (ATTACK_FAILED | ATTACK_MISSED |
            ATTACK_NO_EFFECT)) && attacks[*active_attack].base_power &&
            !(battler_statuses[*attacking_battler].unkown[1] & 1)){
        //inflict life-orb damage
        bsc_push_next_cmd();
        *bsc_offset = bsc_life_orb;
        //dprintf("Life orb triggered for battler %d\n", *attacking_battler);
        
        
    }
    //now apply the abilities
    if(attacker->ability == LERNFAEHIG && attacker->current_hp &&
            *attack_result & ATTACK_MISSED && attacker->stat_changes[6] < 12){
        if(gp_stack_push(index)){
            attacker->stat_changes[6]++; //accuracy boost
            bsc_push_next_cmd();
            *bsc_offset = bsc_lernfaehig;
        }else{
            derrf("Lernfaehig not triggered for battler %d\n, gp stack held no \
                    space\n", *attacking_battler);
        }
        
    }else if(attacker->ability == HOCHMUT && !(*attack_result & (ATTACK_MISSED |
            ATTACK_NO_EFFECT | ATTACK_FAILED)) && 
            attacks[*active_attack].base_power &&
            !(battler_statuses[*attacking_battler].unkown[1] & 1)
            && defender->current_hp && attacker->stat_changes[1] < 12){
        if(gp_stack_push(index)){
            attacker->stat_changes[1]++; //accuracy boost
            bsc_push_next_cmd();
            *bsc_offset = bsc_hochmut;
        }else{
            derrf("Hochmut not triggered for battler %d\n, gp stack held no \
                    space\n", *attacking_battler);
        }
    }else if(attacker->ability == LEBENSRAEUBER && !(*attack_result & (
            ATTACK_MISSED | ATTACK_NO_EFFECT | ATTACK_FAILED)) && 
            attacks[*active_attack].base_power && attacker->current_hp <
            attacker->max_hp){
        bsc_push_next_cmd();
        *bsc_offset = bsc_lebensraeuber;
    }else if(attacker->ability == CURATOR && !(*attack_result & (
            ATTACK_MISSED | ATTACK_NO_EFFECT | ATTACK_FAILED)) && 
            attacker->current_hp < attacker->max_hp && (
            *active_attack == ATTACK_GENESUNG ||
            *active_attack == ATTACK_TAGEDIEB ||
            *active_attack == ATTACK_SYNTHESE ||
            *active_attack == ATTACK_MONDSCHEIN ||
            *active_attack == ATTACK_ERHOLUNG ||
            *active_attack == ATTACK_WUNSCHTRAUM ||
            *active_attack == ATTACK_WEICHEI ||
            *active_attack == ATTACK_AROMAKUR ||
            *active_attack == ATTACK_VITALGLOCKE ||
            *active_attack == ATTACK_MILCHGETRAENK
            
            )){
        bsc_push_next_cmd();
        *bsc_offset = bsc_curator;
        
    }else if(attacker->ability == EXTRADORN && !(*attack_result & (
            ATTACK_MISSED | ATTACK_NO_EFFECT | ATTACK_FAILED)) &&
            defender->current_hp && 
            attacks[*active_attack].flags & MAKES_CONTACT){
        bsc_push_next_cmd();
        *bsc_offset = bsc_extradorn;
        
        
    }
}

void attack_done_prepeare_life_orb(){
    battler *attacker = &battlers[*attacking_battler];
    int damage = attacker->max_hp / 10;
    if(damage <= 0) damage = 1;
    *damage_to_apply = damage;
}

void attack_done_prepeare_lernfaehig(){
    stat_change[0x10] = 0x14;
    stat_change[0x11] = 0;
    stat_change[0x17] = (u8)gp_stack_pop();
}

void attack_done_prepeare_hochmut(){
    stat_change[0x10] = 0xF;
    stat_change[0x11] = 0;
    stat_change[0x17] = (u8)gp_stack_pop();
}

void attack_done_prepeare_lebensraeuber(){
    int hp_to_heal = *damage_caused >> 2;
    if(hp_to_heal <= 0) hp_to_heal = 1;
    *damage_to_apply = -hp_to_heal;
}

void attack_done_prepeare_curator(){
    battler *attacker = &battlers[*attacking_battler];
    int hp_to_heal = attacker->max_hp / 16;
    if (hp_to_heal <= 0) hp_to_heal = 1;
    *damage_to_apply = -hp_to_heal;
}

void attack_done_prepeare_extradorn(){
    bsc_buffers[0] = 0xFD;
    bsc_buffers[1] = 3;
    bsc_buffers[3] = 0xFF;
    int damage = *damage_caused / 8;
    if(damage <= 0) damage = 1;
    *damage_to_apply = damage;
}
