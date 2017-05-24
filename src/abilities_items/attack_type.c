#include "types.h"
#include "item.h"
#include "basestats.h"
#include "battle.h"
#include "abilities.h"
#include "romfuncs.h"
#include "debug.h"
#include "attack.h"


void damage_apply_multiplier(int multiplier){
    *damage_to_apply *= multiplier;
    *damage_to_apply /= 1000;
}

u8 attack_type_by_ability(u16 attack){
    battler *attacker = &battlers[*attacking_battler];
    if(attacks[attack].type == TYPE_NORMAL){
        switch(attacker->ability){
            case ZENITHAUT:
                damage_apply_multiplier(1300);
                return TYPE_FLYING;
            case KAEMPFERHERZ:
                damage_apply_multiplier(1300);
                return TYPE_FIGHTING;
            case DONNERAURA:
                damage_apply_multiplier(1300);
                return TYPE_ELECTRIC;
            case FROSTSCHICHT:
                damage_apply_multiplier(1300);
                return TYPE_ICE;
        }
    }
    return attacks[attack].type;
}