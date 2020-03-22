#include "types.h"
#include "battle/state.h"
#include "battle/controller.h"
#include "battle/battler.h"
#include "battle/communication.h"
#include "constants/battle/battle_handicaps.h"
#include "vars.h"
#include "abilities.h"
#include "constants/pokemon_types.h"
#include "battle/battlescript.h"
#include "debug.h"

extern u8 battlescript_handicap_extreme_heat[];
extern u8 battlescript_handicap_floating_rocks[];

static u8 *battlescripts_handicap[32] = {
    [BATTLE_HANDICAP_FLOATING_ROCKS] = battlescript_handicap_floating_rocks,
    [BATTLE_HANDICAP_EXTREME_HEAT] = battlescript_handicap_extreme_heat,
};

void battle_introduce_handicap() {
    if (battler_marked_for_controller_execution)
        return;
    if (battle_flags & BATTLE_WITH_HANDICAP) {
        while (BATTLE_STATE2->handicap_introduced < 32) {
            bool script_initialized = false;
            if (fmem.battle_handicaps & int_bitmasks[BATTLE_STATE2->handicap_introduced]) {
                if (battlescripts_handicap[BATTLE_STATE2->handicap_introduced]) {
                    battlescript_init_and_interrupt_battle(battlescripts_handicap[BATTLE_STATE2->handicap_introduced]);
                }
                script_initialized = true;
            }
            BATTLE_STATE2->handicap_introduced++;
            if (script_initialized)
                return;
        }
    }
    // Directly execute switch-in effects for handicaps
    while(BATTLE_STATE2->switch_in_handicap_effects_cnt < battler_cnt) {
        bool script_initialized = false;
        if (battle_handicap_switch_in_effects(BATTLE_STATE2->switch_in_handicap_effects_cnt))
            script_initialized = true;
        BATTLE_STATE2->switch_in_handicap_effects_cnt++;
        if (script_initialized)
            return;
    }

    battle_main_callback = battle_events_before_first_turn;
}

void battle_handicap_set() {
    fmem.battle_handicaps |= int_bitmasks[*var_access(0x8004)];
}

extern u8 battlescript_handicap_extreme_heat_apply[];

bool battle_handicap_switch_in_effects(u8 battler_idx) {
    for (int i = 0; i < 32; i++) {
        if (fmem.battle_handicaps & int_bitmasks[i]) { // Activate the i-th battle handicap for this battler
            switch (i) {
                case BATTLE_HANDICAP_EXTREME_HEAT: {
                    if (battlers[battler_idx].max_hp > 0 && !(battlers[battler_idx].status1 & STATUS1_ANY) &&
                        battlers[battler_idx].ability != AQUAHUELLE && battlers[battler_idx].type1 != TYPE_FEUER && 
                        battlers[battler_idx].type2 != TYPE_FEUER && !battle_side_statuses[battler_idx].status_safeguard) { 
                        // Battler can be affected by extreme heat
                        dprintf("Execute extreme heat for battler %d\n", battler_idx);
                        attacking_battler = battler_idx; // Set those for synchronize I suppose...
                        defending_battler = battler_idx; 
                        battle_scripting.battler_idx = battler_idx;
                        battle_communication[BATTLE_COMMUNICATION_MOVE_EFFECT_BYTE] = 0x43;
    	                battlescript_init_and_interrupt_battle(battlescript_handicap_extreme_heat_apply);
                        return true;
                    }
                    break;
                }
            }
        }
    }
    return false;
}