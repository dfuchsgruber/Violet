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
#include "debug.h"

extern u8 bsc_intimidate[];
extern u8 bsc_intimidate_end3[];
extern u8 bsc_gegenwind[];
extern u8 bsc_gegenwind_end3[];
extern u8 bsc_giftnebel[];
extern u8 bsc_giftnebel_end3[];

bool battle_abilities_intimidate2() {
    for (u8 i = 0; i < battler_cnt; i++) {
        if (battler_statuses3[i] & STATUS3_INTIMIDATE_POKES) {
            dprintf("Battler %d intimidates2 with ability %d\n", i, battlers[i].ability);
            if (battlers[i].ability == BEDROHER) {
                defending_battler_ability = battlers[i].ability;
                battler_statuses3[i] &= (u32)(~STATUS3_INTIMIDATE_POKES);
                battlescript_callstack_push_next_command();
                bsc_offset = bsc_intimidate;
                battle_state->intimidate_battler_idx = i;
                return true;
            } else if (battlers[i].ability == GEGENWIND) {
                defending_battler_ability = battlers[i].ability;
                battler_statuses3[i] &= (u32)(~STATUS3_INTIMIDATE_POKES);
                battlescript_callstack_push_next_command();
                bsc_offset = bsc_gegenwind;
                battle_state->intimidate_battler_idx = i;
                return true;
            } else if (battlers[i].ability == GIFTNEBEL) {
                defending_battler_ability = battlers[i].ability;
                battler_statuses3[i] &= (u32)(~STATUS3_INTIMIDATE_POKES);
                battlescript_callstack_push_next_command();
                bsc_offset = bsc_giftnebel;
                battle_state->intimidate_battler_idx = i;
                return true;
            }
        }
    }
    return false;
}

bool battle_abilities_intimidate1() {
    for (u8 i = 0; i < battler_cnt; i++) {
        if (battler_statuses3[i] & STATUS3_INTIMIDATE_POKES) {
            dprintf("Battler %d intimidates1 with ability %d\n", i, battlers[i].ability);
            if (battlers[i].ability == BEDROHER) {
                defending_battler_ability = BEDROHER;
                battler_statuses3[i] &= (u32)(~STATUS3_INTIMIDATE_POKES);
                battlescript_init_and_interrupt_battle(bsc_intimidate_end3);
                battle_state->intimidate_battler_idx = i;
                return true;
            } else if (battlers[i].ability == GEGENWIND) {
                defending_battler_ability = GEGENWIND;
                battler_statuses3[i] &= (u32)(~STATUS3_INTIMIDATE_POKES);
                battlescript_init_and_interrupt_battle(bsc_gegenwind_end3);
                battle_state->intimidate_battler_idx = i;
                return true;
            } else if (battlers[i].ability == GIFTNEBEL) {
                defending_battler_ability = battlers[i].ability;
                battler_statuses3[i] &= (u32)(~STATUS3_INTIMIDATE_POKES);
                battlescript_init_and_interrupt_battle(bsc_giftnebel_end3);
                battle_state->intimidate_battler_idx = i;
                return true;
            }
        }
    }
    return false;
}

