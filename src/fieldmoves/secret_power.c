/*
 * secret_power.c
 *
 *  Created on: Aug 25, 2018
 *      Author: dominik
 */
#include "types.h"
#include "flags.h"
#include "constants/flags.h"
#include "field_move.h"
#include "overworld/pokemon_party_menu.h"
#include "vars.h"
#include "overworld/script.h"
#include "dungeon/dungeon2.h"

void field_move_secret_power_overworld() {
	*var_access(0x800D) = pokemon_party_menu_get_current_index();
	overworld_script_init(ow_script_dungeon_enter_field);
}

bool field_move_secret_power_init() {
	if (checkflag(PLAYER_CAN_ENTER_DUNGEONS)) {
		// Check if there is a dungeon to enter
		if (dungeon_get_location_idx_player_is_facing() != -1) {
			pokemon_party_menu_continuation = pokemon_party_menu_return_and_execute_field_move;
			field_move_overworld_continuation = field_move_secret_power_overworld;
			return true;
		}
	}
	return false;
}

