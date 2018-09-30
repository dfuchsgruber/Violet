/*
 * rock_climb.c
 *
 *  Created on: Sep 30, 2018
 *      Author: dominik
 */

#include "types.h"
#include "flags.h"
#include "constants/flags.h"
#include "field_move.h"
#include "overworld/pokemon_party_menu.h"
#include "vars.h"
#include "overworld/script.h"
#include "tile/coordinate.h"
#include "tile/block.h"
#include "constants/block_hm_usage.h"

bool rock_climb_block_is_climbable() {
	position_t player_pos, faced_pos;
	player_get_position(&player_pos);
	player_get_position_faced(&faced_pos);
	if (player_pos.height == faced_pos.height || faced_pos.height == 0) {
		// Check if the adjacent tile is climbable
		u32 hm_usage = block_get_field_by_pos(faced_pos.coordinates.x, faced_pos.coordinates.y,
				BDATA_HM_USAGE);
		return (hm_usage & HM_USAGE_ROCK_CLIMB) > 0;
	}
	return false;
}

bool field_move_rock_climb_init() {
	if (checkflag(FRBADGE_8) || true) {
		// Check if there is a dungeon to enter
		return true;
	}
	return false;
}
