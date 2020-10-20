#include "types.h"
#include "attack.h"
#include "battle/state.h"
#include "battle/attack.h"
#include "battle/battlescript.h"
#include "battle/battler.h"
#include "save.h"
#include "debug.h"
#include "constants/attacks.h"
#include "constants/attack_flags.h"
#include "constants/attack_categories.h"
#include "constants/pokemon_types.h"
#include "battle/communication.h"

extern u8 bsc_kings_shield_drop[];

void bsc_command_setprotect_apply_kings_shield(){
    dprintf("Kings shield tried for battler %d\n", attacking_battler);
    if(attacks[active_attack].effect == 0xE3){
        dprintf("Kings shield triggered for battler %d\n", attacking_battler);
        BATTLE_STATE2->status_custom[attacking_battler] |= CUSTOM_STATUS_KINGS_SHIELD;
        battle_communication[BATTLE_COMMUNICATION_MULTISTRING_CHOOSER] = 2;
        battler_statuses[attacking_battler].protect = true;
    }
}

bool attack_is_protecting_move(u16 move){
    return move == ATTACK_SCHUTZSCHILD || move == ATTACK_SCANNER ||
            move == ATTACK_AUSDAUER || move == ATTACK_KOENIGSSCHILD;
}

bool protect_attack_succeeds(){
    dprintf("Trying to apply protect state\n");
    battler *attacker = &battlers[attacking_battler];
    if(BATTLE_STATE2->status_custom[defending_battler] & 
        CUSTOM_STATUS_KINGS_SHIELD){
        dprintf("Defender %d is behind kings shield\n", defending_battler);
        //king shield protect, check if the move hits
        if(!(attacks[active_attack].flags & AFFECTED_BY_PROTECT)) return true;
        dprintf("Category of attack is %d\n", attacks[active_attack].category);
        if(attacks[active_attack].category == CATEGORY_STATUS) return true;
        if(attack_needs_charging(active_attack) && !(attacker->status2 &
                STATUS2_ATTACK_CHARGED)) return true;
        if(attacks[active_attack].flags & MAKES_CONTACT)
            BATTLE_STATE2->status_custom[attacking_battler] |=
                CUSTOM_STATUS_KINGS_SHIELD_DROP;
        
    }else{
        //regular protect
        if(!(attacks[active_attack].flags & AFFECTED_BY_PROTECT)) return true;
        if(active_attack == ATTACK_FLUCH && attacker->type1 != TYPE_GEIST &&
                attacker->type2 != TYPE_GEIST) return true; //curse succeeds
        if(attack_needs_charging(active_attack)){
            //check if the user has done the charging round or is starting the
            //charge
            if(!(attacker->status2 & STATUS2_ATTACK_CHARGED)) return true;
        }
    }
    return false;
}

void bsc_push_kings_shield_drop(){
    battler *attacker = &battlers[attacking_battler];
    if((BATTLE_STATE2->status_custom[attacking_battler] & CUSTOM_STATUS_KINGS_SHIELD_DROP)
        && attacker->stat_changes[1] > 0){
        if(attacker->stat_changes[1] == 1) attacker->stat_changes[1] = 0;
        else attacker->stat_changes[1] = (u8)(attacker->stat_changes[1]  - 2);
        battlescript_callstack_push_next_command();
        bsc_offset = bsc_kings_shield_drop;
    }
}

void kings_shield_prepeare_drop(){
    battle_scripting.animation_arguments[0] = 0x16;
    battle_scripting.animation_arguments[1] = 0;
    battle_scripting.battler_idx = attacking_battler;
}
