#include "types.h"
#include "debug.h"
#include "battle/battler.h"
#include "battle/weather.h"
#include "battle/state.h"
#include "pokemon/evolution.h"
#include "constants/abilities.h"
#include "constants/battle_weathers.h"
#include "constants/items.h"
#include "constants/evolution_methods.h"
#include "abilities.h"
#include "item/item.h"
#include "constants/item_hold_effects.h"
#include "item/custom.h"

int attacker_modify_satk(int satk){
	if (WEATHER_HAS_EFFECT) {
		switch(battlers[attacking_battler].ability){
			case SOLARKRAFT:
				if(battle_weather & BATTLE_WEATHER_SUN_ANY) satk += satk / 2;
				break;
			case REGENMUT:
				if(battle_weather & BATTLE_WEATHER_RAIN_ANY) satk += satk / 2;
				break;
			case KAELTEWAHN:
				if(battle_weather & BATTLE_WEATHER_HAIL_ANY) satk += satk / 2;
				break;
			case UNGEBROCHEN:
				if(battlers[attacking_battler].current_hp <=
						battlers[attacking_battler].max_hp / 2) satk += satk / 3;
				break;
			case HITZEWAHN:
				if(battlers[attacking_battler].status1 & STATUS1_BURNED) satk += satk / 2;
				break;
		}
	}
    u16 item = battlers[attacking_battler].item;
    u8 hold_effect = items[item].holding_effect_id;
    u8 hold_effect_param = items[item].holding_effect_param;
    if (item == ITEM_ENIGMABEERE) {
    	hold_effect = enigma_berries[attacking_battler].hold_effect;
    	hold_effect_param = enigma_berries[attacking_battler].hold_effect_parameter;
    }
    if (hold_effect == HOLD_EFFECT_CHOICE_ITEM && hold_effect_param == CHOICE_ITEM_SPECS)
    	satk += satk / 2;
    return satk;
}

int attacker_modify_atk(int atk){
	if (WEATHER_HAS_EFFECT) {
		switch(battlers[attacking_battler].ability){
			case SANDHERZ:
				if(battle_weather & BATTLE_WEATHER_SANDSTORM_ANY) atk += atk / 2;
				break;
			case UNGEBROCHEN:
				if(battlers[attacking_battler].current_hp <= battlers[attacking_battler].max_hp / 2)
					atk += atk / 3;
				break;
			case GIFTWAHN:
				if(battlers[attacking_battler].status1 & STATUS1_POISONED_ANY) atk += atk / 2;
				break;
		}
	}
    u16 item = battlers[attacking_battler].item;
    u8 hold_effect = items[item].holding_effect_id;
    u8 hold_effect_param = items[item].holding_effect_param;
    if (item == ITEM_ENIGMABEERE) {
    	hold_effect = enigma_berries[attacking_battler].hold_effect;
    	hold_effect_param = enigma_berries[attacking_battler].hold_effect_parameter;
    }
    if (hold_effect == HOLD_EFFECT_CHOICE_ITEM && hold_effect_param == CHOICE_ITEM_BAND)
    	atk += (atk / 2);
    return atk;
}

int defender_modify_def(int def){
    u16 item = battlers[defending_battler].item;
    u8 hold_effect = items[item].holding_effect_id;
    if (item == ITEM_ENIGMABEERE) {
    	hold_effect = enigma_berries[defending_battler].hold_effect;
    }
    if (hold_effect == HOLD_EFFECT_EVOLITE)
    	def += (def / 2);
    return def;
}

int defender_modify_sdef(int sdef){
    u16 item = battlers[defending_battler].item;
    u8 hold_effect = items[item].holding_effect_id;
    if (item == ITEM_ENIGMABEERE) {
    	hold_effect = enigma_berries[defending_battler].hold_effect;
    }
    if (hold_effect == HOLD_EFFECT_EVOLITE)
    	sdef += (sdef / 2);
    return sdef;
}
