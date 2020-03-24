#include "types.h"
#include "battle/battler.h"
#include "battle/attack.h"
#include "battle/state.h"
#include "constants/abilities.h"
#include "constants/attacks.h"
#include "constants/attack_results.h"
#include "attack.h"
#include "debug.h"
#include "constants/items.h"
#include "battle/battlescript.h"

void apply_final_damage_modifiers(){
    battler *attacker = &battlers[attacking_battler];
    battler *defender = &battlers[defending_battler];
    switch(defender->ability){
        case FELSENKERN:
        case FILTER:
        case BARRIERE:{
            if(attack_result & ATTACK_SUPER_EFFECTIVE){
                damage_apply_multiplier(750);
            }
            break;
        }
            
    }
    dprintf("Attacker ability is %d\n", attacking_battler);
    switch(attacker->ability){
        case ANPASSUNG:{
            if(attacks[active_attack].type == attacker->type1 ||
                    attacks[active_attack].type == attacker->type2){
                damage_to_apply *= 4;
                damage_to_apply /= 3;
            }
            break;
        }
        case AUFWERTUNG:{
            if(attack_result & ATTACK_NOT_EFFECTIVE){
                damage_to_apply *= 2;
            }
            break;
        }
        case ALLROUNDER:{
            if(attacks[active_attack].type != attacker->type1 &&
                    attacks[active_attack].type != attacker->type2){
                dprintf("Allrounder activated for battler %d\n",
                        attacking_battler);
                damage_apply_multiplier(1200);
            }
            break;
        } case ACHTLOS : {
        	if (active_attack == ATTACK_BODYCHECK ||
        			active_attack == ATTACK_FLAMMENBLITZ ||
        			active_attack == ATTACK_RISIKOTACKLE ||
        			active_attack == ATTACK_SPRUNGKICK ||
        			active_attack == ATTACK_STURZFLUG ||
					active_attack == ATTACK_TURMKICK ||
					active_attack == ATTACK_UEBERROLLER ||
					active_attack == ATTACK_VOLTTACKLE) {
                damage_apply_multiplier(1200);
        	}
        	break;
        }
        case SUPERSCHUETZE: {
        	if (critical_hit_multiplier > 1) {
        		damage_apply_multiplier(1500);
        	}
        	break;
        }
    }
}


void apply_pre_damage_modifiers(){
    battler *attacker = &battlers[attacking_battler];
    battler *defender = &battlers[defending_battler];
    switch(attacker->ability){
        case TECHNIKER:
            if(attacks[active_attack].base_power <= 60)
                damage_apply_multiplier(1500);
            break;
    }
    switch(defender->ability){
        case MULTISCHUPPE:{
            if(defender->current_hp >= defender->max_hp)
                damage_apply_multiplier(500);
            break;
        }
    }
    switch(attacker->item){
        case ITEM_LEBEN_ORB:{
            damage_apply_multiplier(1300);
            break;
        }   
    }
    if (BATTLE_STATE2->status_custom[defending_battler] & CUSTOM_STATUS_FLOATING_ROCKS) {
        dprintf("Reduce damage caused to rock type battler %d.\n", defending_battler);
        BATTLE_STATE2->status_custom[defending_battler] &= (u32)(~CUSTOM_STATUS_FLOATING_ROCKS);
        damage_apply_multiplier(500);
    }
    battlescript_cmd_x06_apply_damage_modifiers();
    apply_final_damage_modifiers();
}

