/*
 * hidden_power.c
 *
 *  Created on: Feb 17, 2019
 *      Author: dominik
 */
#include "types.h"
#include "battle/state.h"
#include "battle/battler.h"
#include "battle/battlescript.h"
#include "pokemon/virtual.h"
#include "attack.h"

void bsc_cmd_xC1_hiddenpowercalc() {
	battle_dynamic_base_power = hidden_power_get_base_power(battlers[attacking_battler].pid);
	battle_state->dynamic_move_type = hidden_power_get_type(battlers[attacking_battler].pid);
	battle_state->dynamic_move_type |= 0xC0;
	bsc_offset++;
}

u8 hidden_power_get_type(pid_t pid) {
	return (u8)(pid.fields.hidden_power_type % 18);
}

u8 hidden_power_get_base_power(pid_t pid) {
	return (u8)(30 + (40 * (pid.fields.hidden_power_strength & 7)) / 8);
}
