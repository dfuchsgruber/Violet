#include "types.h"
#include "battle/state.h"
#include "battle/ai.h"
#include "constants/battle/battle_statuses.h"
#include "pokemon/basestat.h"
#include "prng.h"
#include "debug.h"
#include "battle/ressources.h"

static u16 battle_ai_fleeing_prng() {
    return (u16)_prng_xorshift(&BATTLE_STATE2->fleeing_rng);
}

void battle_ai_script_command_random_flee() {
    u8 battler_idx = battler_get_by_position(BATTLE_POSITION_OPPONENT_LEFT);
    BATTLE_STATE2->fleeing_rng = BATTLE_STATE2->fleeing_rng_seed;
    int base_rate = basestats[battlers[battler_idx].species].exp_yield;
    // Some aliments may make fleeing harder
    if (battlers[defending_battler].status1 & STATUS1_FROZEN)
        base_rate /= 10;
    else if (battlers[battler_idx].status1 & STATUS1_SLEEPING)
        base_rate /= 3;
    else if (battlers[battler_idx].status1 & STATUS1_PARALYZED)
        base_rate /= 2;

    // By random, if the pokemon has lost hp, it may increase its fleeing rate
    if ((battle_ai_fleeing_prng() % battlers[battler_idx].max_hp) > battlers[battler_idx].current_hp)
        base_rate += base_rate / 2;

    dprintf("Considering fleeing with a rate of %d\n", base_rate);

    if (battle_ai_fleeing_prng() % 255 < base_rate) {
        battle_ai_script = (u8*)UNALIGNED_32_GET(battle_ai_script + 1);
    } else {
        battle_ai_script += 5;
    }
}