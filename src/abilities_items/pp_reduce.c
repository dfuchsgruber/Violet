#include "types.h"
#include "battle.h"

void pp_reduce(u8 amount){
    battler *b = &battlers[*attacking_battler];
    if(b->custom_status & CUSTOM_STATUS_AP_SPARER){
        //remove the status to save pp
        b->custom_status &= !(CUSTOM_STATUS_AP_SPARER);
    }else{
        if(b->current_pp[*active_attack_slot] >= amount){
            b->current_pp[*active_attack_slot] = (u8)(
                    b->current_pp[*active_attack_slot] - amount);
            
        }else{
            b->current_pp[*active_attack_slot] = 0;
        }
    }
}
