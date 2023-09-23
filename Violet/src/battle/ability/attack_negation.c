#include "types.h"
#include "abilities.h"
#include "battle/battler.h"
#include "battle/battlescript.h"
#include "battle/state.h"
#include "attack.h"
#include "debug.h"
#include "constants/abilities.h"
#include "constants/pokemon_types.h"
#include "prng.h"
#include "constants/battle/battle_handicaps.h"
#include "constants/battle/battle_statuses.h"

extern const u8 bsc_flinch_aura[];
extern const u8 bsc_flinch_raura[];
extern const u8 bsc_flinch_baura[];
extern const u8 bsc_flinch_gaura[];
extern const u8 battlescript_handicap_terrifying_atmosphere_apply[];

const u8 *attack_negating_abilities(u8 defender_ability, u16 used_attack){
    
    if(defender_ability == R_KAISERAURA || defender_ability == B_KAISERAURA
            || defender_ability == G_KAISERAURA){
        if(!(rnd16() & 3)){
            //1/4 chance of flinching due to emperors aura
            battle_scripting.battler_idx = attacking_battler;
            battle_scripting.animation_user = defending_battler;
            if(battlers[attacking_battler].status2 & 0x1000){
                bsc_status_flags |= 0x800;
            }
            return bsc_flinch_aura;
        }else if(defender_ability == R_KAISERAURA){
            if(attacks[used_attack].type == TYPE_WASSER){
                if(battlers[attacking_battler].status2 & 0x1000){
                    bsc_status_flags |= 0x800;
                }
                return bsc_flinch_raura;
            }
        }else if(defender_ability == B_KAISERAURA){
            if(attacks[used_attack].type == TYPE_FEUER){
                if(battlers[attacking_battler].status2 & 0x1000){
                    bsc_status_flags |= 0x800;
                }
                return bsc_flinch_baura;
            }
        }else if(defender_ability == G_KAISERAURA){
            if(attacks[used_attack].type == TYPE_WASSER ||
                    attacks[used_attack].type == TYPE_FEUER ||
                    attacks[used_attack].type == TYPE_PFLANZE){
                if(battlers[attacking_battler].status2 & 0x1000){
                    bsc_status_flags |= 0x800;
                }
                return bsc_flinch_gaura;
            }
        }
    }else if(defender_ability == LAERMSCHUTZ){
        //check if attack is blocked by lärmschutz
        u16 *learmschutz_blockated_moves = (u16*)0x08250028;
        int i;
        for(i = 0; learmschutz_blockated_moves[i] != 0xFFFF; i++){
            if(used_attack == learmschutz_blockated_moves[i]) break;
            
        }
        if(learmschutz_blockated_moves[i] != 0xFFFF){
            if(battlers[attacking_battler].status2 & 0x1000){
                bsc_status_flags |= 0x800;
            }
            return (u8*)0x081DD704;
        }
    }
    // Check for handicap here, it's a bit hacky, but w/e
    if ((battle_handicaps & int_bitmasks[BATTLE_HANDICAP_TERRIFYING_ATMOSPHERE]) && battlers[defending_battler].type1 != TYPE_GEIST && 
            battlers[defending_battler].type2 != TYPE_GEIST && (rnd16() % 3) == 0) {
        if(battlers[attacking_battler].status2 & 0x1000){
            bsc_status_flags |= 0x800;
        }
        battle_scripting.battler_idx = attacking_battler;
        battle_scripting.animation_user = defending_battler;
        return battlescript_handicap_terrifying_atmosphere_apply;
    }
    return NULL;
}
