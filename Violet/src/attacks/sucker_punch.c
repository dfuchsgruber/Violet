/*
 * sucker_punch.c
 *
 *  Created on: Feb 14, 2019
 *      Author: dominik
 */

#include "types.h"
#include "battle/battlescript.h"
#include "battle/battler.h"
#include "battle/state.h"
#include "battle/attack.h"
#include "constants/attack_categories.h"
#include "constants/attack_results.h"
#include "attack.h"
#include "debug.h"

void bsc_sucker_punch_cancel() {
	u8 target = battle_state->move_target[attacking_battler];
	u16 move = moves_used[target];
	// Check if the user acts first (use pre-defined order to consider possible speed ties)
	int rank_attacker = -1, rank_defender = -1;
	for (int i = 0; i < battler_cnt; i++) {
		if (battler_attacking_order[i] == attacking_battler) rank_attacker = i;
		else if (battler_attacking_order[i] == defending_battler) rank_defender = i;
	}
	// Fail if the foe agitates first or does not do a damage move
	if (!move || rank_attacker > rank_defender ||
			!(attacks[move].category == CATEGORY_SPECIAL ||
			attacks[move].category == CATEGORY_PHYSICAL)) {
		attack_result |= ATTACK_FAILED;
		bsc_offset = bsc_attack_failed_pp_reduce;
	}
}
