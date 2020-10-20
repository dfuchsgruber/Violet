/*
 * side_effects.c
 *
 *  Created on: Feb 14, 2019
 *      Author: dominik
 */
#include "types.h"
#include "battle/battler.h"
#include "battle/state.h"
#include "battle/battlescript.h"
#include "battle/communication.h"
#include "constants/attack_results.h"
#include "constants/items.h"
#include "item/item.h"
#include "constants/item_hold_effects.h"
#include "battle/attack.h"
#include "debug.h"

void bsc_cmd_x92_setlightscreen() {
	int side = battler_get_position(attacking_battler) & 1;
	if (battle_side_statuses[side].lightscreen ) {
		attack_result |= ATTACK_MISSED;
		battle_communication[BATTLE_COMMUNICATION_MULTISTRING_CHOOSER] = 0;
	} else {
		battle_side_statuses[side].lightscreen = 1;
		u16 item = battlers[attacking_battler].item;
		u8 hold_effect = item_get_hold_effect(item);
		if (item == ITEM_ENIGMABEERE) {
			hold_effect = enigma_berries[attacking_battler].hold_effect;
		}
		if (hold_effect == HOLD_EFFECT_LIGHT_CLAY)
			battle_side_timers[side].lightscreen_turns = 8;
		else
			battle_side_timers[side].lightscreen_turns = 5;
		battle_side_timers[side].lightscreen_battler_idx = attacking_battler;
		if ((battle_flags & BATTLE_DOUBLE) && battlers_alive(ALIVE_ATTACKING_SIDE))
			battle_communication[BATTLE_COMMUNICATION_MULTISTRING_CHOOSER] = 4;
		else
			battle_communication[BATTLE_COMMUNICATION_MULTISTRING_CHOOSER] = 3;
	}
	bsc_offset++;
}

void bsc_cmd_x7E_setreflect() {
	int side = battler_get_position(attacking_battler) & 1;
	if (battle_side_statuses[side].reflect ) {
		attack_result |= ATTACK_MISSED;
		battle_communication[BATTLE_COMMUNICATION_MULTISTRING_CHOOSER] = 0;
	} else {
		battle_side_statuses[side].reflect = 1;
		u16 item = battlers[attacking_battler].item;
		u8 hold_effect = item_get_hold_effect(item);
		if (item == ITEM_ENIGMABEERE) {
			hold_effect = enigma_berries[attacking_battler].hold_effect;
		}
		if (hold_effect == HOLD_EFFECT_LIGHT_CLAY)
			battle_side_timers[side].reflect_turns = 8;
		else
			battle_side_timers[side].reflect_turns = 5;
		battle_side_timers[side].reflect_battler_idx = attacking_battler;
		if ((battle_flags & BATTLE_DOUBLE) && battlers_alive(ALIVE_ATTACKING_SIDE))
			battle_communication[BATTLE_COMMUNICATION_MULTISTRING_CHOOSER] = 4;
		else
			battle_communication[BATTLE_COMMUNICATION_MULTISTRING_CHOOSER] = 3;
	}
	bsc_offset++;
}

