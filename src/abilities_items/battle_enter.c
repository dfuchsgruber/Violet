#include "types.h"
#include "constants/abilities.h"
#include "constants/battle_weathers.h"
#include "battle/state.h"
#include "battle/weather.h"
#include "battle/battlescript.h"
#include "debug.h"
#include "abilities.h"


bool abilities_battle_enter(u8 ability, u8 index) {
    dprintf("Battle enter for ability %d, index %d\n", ability, index);
    if(ability == HAGELALARM && !(battle_weather & BATTLE_WEATHER_HAIL)){
        battle_weather = BATTLE_WEATHER_HAIL;
        dprintf("Hail triggered\n");
        battlescript_init_and_interrupt_battle(bsc_hagelalarm);
        battle_stat_change[0x17] = index;
        return true;
    } else if (ability == HACK) {
        battlescript_init_and_interrupt_battle(bsc_hack);
        return true;
    }
    return false;
    
}

