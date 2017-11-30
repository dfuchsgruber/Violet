
#include "types.h"
#include "item.h"
#include "basestats.h"
#include "battle.h"
#include "abilities.h"
#include "romfuncs.h"
#include "debug.h"
#include "attack.h"
#include "item.h"
#include "evolution.h"

extern u8 bsc_robustheit[];

void trigger_sturdy(){
    if(*damage_to_apply && battlers[*defending_battler].current_hp ==
            battlers[*defending_battler].max_hp && *damage_to_apply >=
            battlers[*defending_battler].current_hp &&
            battlers[*defending_battler].ability == ROBUSTHEIT){
        *damage_to_apply = battlers[*defending_battler].current_hp - 1;
        *bsc_offset += 2;
        bsc_push_next_cmd();
        *bsc_offset = bsc_robustheit;
        *bsc_offset -= 2;
    }
    
}

