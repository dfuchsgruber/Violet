#include "types.h"
#include "battle/attack.h"
#include "battle/battler.h"
#include "battle/state.h"
#include "debug.h"

void pp_reduce(u8 amount){
    battler *b = battlers + attacking_battler;
    if(BATTLE_STATE2->status_custom[attacking_battler] & CUSTOM_STATUS_AP_SPARER){
        //remove the status to save pp
        DEBUG("No pp reduce because of AP sparer.\n");
        BATTLE_STATE2->status_custom[attacking_battler] &= (u32)(~CUSTOM_STATUS_AP_SPARER);
    }else{
        if(b->current_pp[active_attack_slot] >= amount){
            b->current_pp[active_attack_slot] = (u8)(
                    b->current_pp[active_attack_slot] - amount);
            
        }else{
            b->current_pp[active_attack_slot] = 0;
        }
    }
}
