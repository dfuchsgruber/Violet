
#include "types.h"
#include "debug.h"
#include "attack.h"
#include "battle/battler.h"
#include "battle/state.h"
#include "constants/pokemon_types.h"
#include "constants/attack_categories.h"
#include "constants/abilities.h"
#include "constants/attacks.h"

s8 attack_priority_get(u16 attack, u8 user){
    s8 prio = attacks[attack].priority;
    switch(battlers[user].ability){
        case ORKANSCHW:
            if(attacks[attack].type == TYPE_FLUG) prio++;
            break;
        case DUNKLE_MAGIE:
            if(attacks[attack].type == TYPE_UNLICHT) prio++;
            break;
        case STROLCH:
            if(attacks[attack].category == CATEGORY_STATUS) prio++;
            break;
        case FRUEHZUENDER:
        	if (attack == ATTACK_FINALE || attack == ATTACK_EXPLOSION)  prio++;
        	break;
        case ZEITSPIEL:
            prio--;
    }
    return prio;
}
