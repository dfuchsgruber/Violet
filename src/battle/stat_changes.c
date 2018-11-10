#include "types.h"
#include "debug.h"
#include "battle/battler.h"
#include "battle/weather.h"
#include "pokemon/evolution.h"
#include "constants/abilities.h"
#include "constants/battle_weathers.h"
#include "constants/items.h"
#include "constants/evolution_methods.h"
#include "abilities.h"

int attacker_modify_satk(int satk){
    int weather_negating_ability_present = ability_execute(0x13, 0,
            WOLKE_SIEBEN, 0, 0) || ability_execute(0x13, 0, KLIMASCHUTZ, 0,
            0);
    battler *attacker = &battlers[attacking_battler];
    switch(attacker->ability){
        case SOLARKRAFT:
            if((battle_weather & BATTLE_WEATHER_SUN) &&
                    !weather_negating_ability_present) return satk + (satk / 2);
            break;
        case REGENMUT:
            if((battle_weather & BATTLE_WEATHER_RAIN) &&
                    !weather_negating_ability_present) return satk + (satk / 2);
            break;
        case KAELTEWAHN:
            if((battle_weather & BATTLE_WEATHER_HAIL) &&
                    !weather_negating_ability_present) return satk + (satk / 2);
            break;
        case UNGEBROCHEN:
            if(attacker->current_hp <= attacker->max_hp / 2) 
                return satk + (satk / 3);
            break;
        case HITZEWAHN:
            if(attacker->status1 & STATUS1_BURNED)
                return satk +(satk / 2);
            break;
            
    }
    return satk;
}

int attacker_modify_atk(int atk){
    int weather_negating_ability_present = ability_execute(0x13, 0,
            WOLKE_SIEBEN, 0, 0) || ability_execute(0x13, 0, KLIMASCHUTZ, 0,
            0);
    battler *attacker = &battlers[attacking_battler];
    switch(attacker->ability){
        case SANDHERZ:
            if((battle_weather & BATTLE_WEATHER_SUN) &&
                    !weather_negating_ability_present) return atk + (atk / 2);
            break;
        case UNGEBROCHEN:
            if(attacker->current_hp <= attacker->max_hp / 2) 
                return atk + (atk / 3);
            break;
        case GIFTWAHN:
            if(attacker->status1 & (STATUS1_POISONED | STATUS1_BADLY_POISONED))
                return atk + (atk / 2);
            break;
    }
    return atk;
}

int defender_modify_def(int def){
    battler *defender = &battlers[defending_battler];
    switch(defender->item){
        case ITEM_EVOLITH:{
        	if(pokemon_can_evolve(defender->species))
                def *= 2;
        }
            
    }
    return def;
}

int defender_modify_sdef(int sdef){
    battler *defender = &battlers[defending_battler];
    switch(defender->item){
        case ITEM_EVOLITH:{
            if(pokemon_can_evolve(defender->species))
                sdef *= 2;
        }
            
    }
    return sdef;
}
