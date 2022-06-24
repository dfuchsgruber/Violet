#include "types.h"
#include "constants/abilities.h"
#include "constants/battle/battle_weathers.h"
#include "battle/state.h"
#include "battle/weather.h"
#include "battle/battlescript.h"
#include "battle/battler.h"
#include "constants/pokemon_stat_names.h"
#include "debug.h"
#include "abilities.h"

extern u8 bsc_eschat[];
extern u8 bsc_hack[];
extern u8 bsc_harvest[];
extern u8 bsc_hagelalarm[];
extern u8 bsc_tollwut[];

bool abilities_battle_enter(u8 ability, u8 index) {
    DEBUG("Battle enter for ability %d, index %d\n", ability, index);
    if(ability == HAGELALARM && !(battle_weather & BATTLE_WEATHER_HAIL)){
        battle_weather = BATTLE_WEATHER_HAIL;
        DEBUG("Hail triggered\n");
        battlescript_init_and_interrupt_battle(bsc_hagelalarm);
    	bsc_global.battler_idx = index;
        return true;
    } else if (ability == HACK && !battler_damage_taken[index].intimdated_foe) {
        battler_damage_taken[index].intimdated_foe = 1; // Abuse that one a bit I suppose...
        battlescript_init_and_interrupt_battle(bsc_hack);
        return true;
    } else if (ability == ESCHAT && !battler_damage_taken[index].intimdated_foe) {
        battler_damage_taken[index].intimdated_foe = 1; // Abuse that one a bit I suppose...
    	bsc_global.battler_idx = index;
    	battlescript_init_and_interrupt_battle(bsc_eschat);
    	return true;
    } else if (ability == TOLLWUT && (battlers[index].stat_changes[STAT_ATTACK] < 7 ||
    		battlers[index].stat_changes[STAT_DEFENSE] > 0
			|| battlers[index].stat_changes[STAT_SPECIAL_DEFENSE] > 0) && !battler_damage_taken[index].intimdated_foe) {
        battler_damage_taken[index].intimdated_foe = 1; // Abuse that one a bit I suppose...
    	bsc_global.battler_idx = index;
		battlescript_init_and_interrupt_battle(bsc_tollwut);
		return true;
    } else if (ability == GEGENWIND && !battler_damage_taken[index].intimdated_foe) {
        battler_statuses3[index] |= STATUS3_INTIMIDATE_POKES;
        battler_damage_taken[index].intimdated_foe = 1;
        return true;
    } else if (ability == GIFTNEBEL && !battler_damage_taken[index].intimdated_foe) {
        battler_statuses3[index] |= STATUS3_INTIMIDATE_POKES;
        battler_damage_taken[index].intimdated_foe = 1;
        return true;
    } else if (ability == FINALGLOCKE && !battler_damage_taken[index].intimdated_foe) {
        battler_statuses3[index] |= STATUS3_INTIMIDATE_POKES;
        battler_damage_taken[index].intimdated_foe = 1;
    } else if (ability == GLUECKSPILZ) {
        BATTLE_STATE2->item_dropping_chance_increased_by_ability = true;
        return false;
    }
    return false;
    
}

