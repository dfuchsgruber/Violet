#include "types.h"
#include "abilities.h"
#include "battle.h"
#include "basestats.h"
#include "romfuncs.h"
#include "debug.h"

extern u8 bsc_hagelalarm[];

bool abilities_battle_enter(u8 ability, u8 index) {
    dprintf("Battle enter for ability %d, index %d\n", ability, index);
    if(ability == HAGELALARM && !(*battle_weather & BATTLE_WEATHER_HAIL)){
        *battle_weather = BATTLE_WEATHER_HAIL;
        dprintf("Hail triggered\n");
        bsc_init_by_interrupting_battle_func(bsc_hagelalarm);
        stat_change[0x17] = index;
        return true;
    }
    return false;
    
}

