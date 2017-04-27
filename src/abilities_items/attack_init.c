#include "types.h"
#include "abilities.h"
#include "battle.h"
#include "romfuncs.h"
#include "basestats.h"
#include "item.h"
#include "attack.h"
#include "debug.h"


extern u8 bsc_wandlungskunst[];

void attack_init_trigger_abilities(){
    battler *attacker = &battlers[*attacking_battler];
    switch(attacker->ability){
        case WANDLUNGSK:{
            dprintf("Lauched ability 'WANDLUNGSK'");
            u8 attack_type = attacks[*active_attack].type;
            if(attacker->type1 != attack_type || attacker->type2 != attack_type){
                attacker->type1 = attack_type;
                attacker->type2 = attack_type;
                bsc_buffers[0] = 0xFD;
                bsc_buffers[1] = 3;
                bsc_buffers[2] = attack_type;
                bsc_buffers[3] = 0xFF;
                bsc_push_next_cmd();
                *bsc_offset = bsc_wandlungskunst;
            }
                
            break;
        }
        case TAKTIKWECHS:{
            break;
        }
        case AP_SPARER:{
            if(random_change_seed() & 3){
                setflag(FLAG_AP_SPARER_TRIGGERED);
            }
            break;
        }
    }
}
