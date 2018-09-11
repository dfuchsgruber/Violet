#include "types.h"
#include "constants/items.h"
#include "battle/battler.h"
#include "battle/attack.h"
#include "battle/weather.h"
#include "battle/battlescript.h"
#include "constants/abilities.h"
#include "constants/battle_weathers.h"
#include "debug.h"
#include "abilities.h"

extern u8 bsc_recoil[];
extern u8 bsc_heal[];
extern u8 bsc_tollwut[];
extern u8 bsc_tollwut_attack_boost[];
extern u8 bsc_lucid[];

void turn_end_apply_recoil_dmg(battler *target){
    int dmg = target->max_hp / 8;
    if (dmg <= 0) dmg = 1;
    damage_to_apply = dmg;
    battlescript_init_and_interrupt_battle(bsc_recoil);
}

bool turn_end(u8 ability, battler *target){
    int weather_negating_ability_present = ability_execute(0x13, 0,
            WOLKE_SIEBEN, 0, 0) || ability_execute(0x13, 0, KLIMASCHUTZ, 0,
            0);
    dprintf("Turn end abilties triggered, ability %d, wnegpres %d\n", ability,
            weather_negating_ability_present);
    if(ability == SOLARKRAFT && (battle_weather & BATTLE_WEATHER_SUN) &&
            !weather_negating_ability_present){
        dprintf("Solarkraft triggered\n");
        turn_end_apply_recoil_dmg(target);
        return true;
    }else if(ability == REGENMUT && (battle_weather & BATTLE_WEATHER_RAIN) &&
            !weather_negating_ability_present){
        turn_end_apply_recoil_dmg(target);
        return true;  
    }else if(ability == SANDHERZ && (battle_weather & BATTLE_WEATHER_SANDSTORM)
            && !weather_negating_ability_present){
        turn_end_apply_recoil_dmg(target);
        return true;
    }else if(ability == KAELTEWAHN && (battle_weather & BATTLE_WEATHER_HAIL)
            && !weather_negating_ability_present){
        turn_end_apply_recoil_dmg(target);
        return true;
    }else if(ability == PHOTOGENESE && (battle_weather & BATTLE_WEATHER_SUN) &&
            !weather_negating_ability_present &&
            target->current_hp < target->max_hp ){
        int dmg = target->max_hp / 8;
        if (dmg <= 0) dmg = 1;
        damage_to_apply = -dmg;
        battlescript_init_and_interrupt_battle(bsc_heal);
        return true;
    }else if(ability == TOLLWUT && (target->stat_changes[1] < 7 ||
            target->stat_changes[2] > 0 || target->stat_changes[5] > 0)){
        battlescript_init_and_interrupt_battle(bsc_tollwut);
        return true;
    }else if(ability == LUZID && (target->status1 & STATUS1_SLEEPING) &&
            target->stat_changes[4] < 12){
        battlescript_init_and_interrupt_battle(bsc_lucid);
        return true;
    }
    return false;
}

void turn_end_tollwut_attack_boost(){
    dprintf("Tollwut attack check for battler %d, stat change %d\n", 
            attacking_battler, battlers[attacking_battler].stat_changes[1]);
    if(battlers[attacking_battler].stat_changes[1] < 8){
        battlescript_callstack_push_next_command();
        bsc_offset = bsc_tollwut_attack_boost;
    }
}
