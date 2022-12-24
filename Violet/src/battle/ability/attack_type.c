#include "types.h"
#include "battle/battler.h"
#include "battle/attack.h"
#include "attack.h"
#include "debug.h"
#include "constants/abilities.h"
#include "constants/pokemon_types.h"


void damage_apply_multiplier(int multiplier){
    damage_to_apply *= multiplier;
    damage_to_apply /= 1000;
}

u8 attack_type_by_ability(u16 attack){
    battler *attacker = &battlers[attacking_battler];
    if(attacks[attack].type == TYPE_NORMAL){
        switch(attacker->ability){
            case ZENITHAUT:
                damage_apply_multiplier(1300);
                return TYPE_FLUG;
            case KAEMPFERHERZ:
                damage_apply_multiplier(1300);
                return TYPE_KAMPF;
            case DONNERAURA:
                damage_apply_multiplier(1300);
                return TYPE_ELEKTRO;
            case FROSTSCHICHT:
                damage_apply_multiplier(1300);
                return TYPE_EIS;
        }
    }
    return attacks[attack].type;
}
