
#include "types.h"
#include "battle/battler.h"
#include "battle/attack.h"
#include "abilities.h"
#include "debug.h"
#include "battle/battlescript.h"
#include "constants/abilities.h"

extern u8 bsc_robustheit[];

void trigger_sturdy(){
    if(*damage_to_apply && battlers[*defending_battler].current_hp ==
            battlers[*defending_battler].max_hp && *damage_to_apply >=
            battlers[*defending_battler].current_hp &&
            battlers[*defending_battler].ability == ROBUSTHEIT){
        *damage_to_apply = battlers[*defending_battler].current_hp - 1;
        *bsc_offset += 2;
        battlescript_callstack_push_next_command();
        *bsc_offset = bsc_robustheit;
        *bsc_offset -= 2;
    }
    
}

