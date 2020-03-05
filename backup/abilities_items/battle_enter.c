#include "types.h"
#include "constants/abilities.h"
#include "constants/battle_weathers.h"
#include "battle/state.h"
#include "battle/weather.h"
#include "battle/battlescript.h"
#include "battle/battler.h"
#include "constants/pokemon_stat_names.h"
#include "debug.h"
#include "abilities.h"


bool abilities_battle_enter(u8 ability, u8 index) {
    dprintf("Battle enter for ability %d, index %d\n", ability, index);
    if(ability == HAGELALARM && !(battle_weather & BATTLE_WEATHER_HAIL)){
        battle_weather = BATTLE_WEATHER_HAIL;
        dprintf("Hail triggered\n");
        battlescript_init_and_interrupt_battle(bsc_hagelalarm);
    	bsc_global.battler_idx = index;
        return true;
    } else if (ability == HACK) {
        battlescript_init_and_interrupt_battle(bsc_hack);
        return true;
    } else if (ability == ESCHAT) {
    	bsc_global.battler_idx = index;
    	battlescript_init_and_interrupt_battle(bsc_eschat);
    	return true;
    } else if (ability == TOLLWUT && (battlers[index].stat_changes[STAT_ATTACK] < 7 ||
    		battlers[index].stat_changes[STAT_DEFENSE] > 0
			|| battlers[index].stat_changes[STAT_SPECIAL_DEFENSE] > 0)) {
		battlescript_init_and_interrupt_battle(bsc_tollwut);
		return true;
    } else if (ability == GEGENWIND && !battler_damage_taken[index].intimdated_foe) {
        battler_statuses3[index] |= STATUS3_INTIMIDATE_POKES;
        battler_damage_taken[index].intimdated_foe = 1;
        return true;
    }
    return false;
    
}

